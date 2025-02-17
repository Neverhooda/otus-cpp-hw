/**
 *  @file decorator_async.cpp
 *  OTUS homework module
 *  #10 Decorator for async
 *  (c) 2025
 */

#include "decorator_async.hpp"

namespace otus_cpp::nw_async {
decorator_async::decorator_async(size_t bulk_size) : bulk_size_(bulk_size) {
	external_blocks_ = otus_cpp::async::connect(bulk_size_);
}

decorator_async::~decorator_async() {
	otus_cpp::async::disconnect(external_blocks_);
}

void decorator_async::send_internal_data(otus_cpp::async::Context ctx,
                                         const std::string &data) {
	std::lock_guard<std::mutex> lock(mutex_);
	otus_cpp::async::receive(ctx, data.data(), data.size());
}

void decorator_async::send_external_data(const std::string &data) {
	std::lock_guard<std::mutex> lock(mutex_);
	otus_cpp::async::receive(external_blocks_, data.data(), data.size());
}

otus_cpp::async::Context decorator_async::connect() {
	std::lock_guard<std::mutex> lock(mutex_);
	++counter_;
	auto ctx = otus_cpp::async::connect(bulk_size_);
	ctxs_.emplace(ctx);
	return ctx;
}

void decorator_async::disconnect(otus_cpp::async::Context ctx) {
	std::lock_guard<std::mutex> lock(mutex_);
	if (ctxs_.erase(ctx) == 0) {
		return;
	}
	--counter_;
	otus_cpp::async::disconnect(ctx);
	if (counter_ == 0) {
		otus_cpp::async::disconnect(external_blocks_);
		external_blocks_ = otus_cpp::async::connect(bulk_size_);
	}
}

void decorator_async::flush() {
	std::lock_guard<std::mutex> lock(mutex_);
	for (auto ctx : ctxs_) {
		otus_cpp::async::disconnect(ctx);
	}
	ctxs_.clear();
	counter_ = 0;
	otus_cpp::async::disconnect(external_blocks_);
	external_blocks_ = otus_cpp::async::connect(bulk_size_);
}

} // namespace otus_cpp::nw_async