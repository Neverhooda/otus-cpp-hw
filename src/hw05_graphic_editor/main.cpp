/**
 *  OTUS homework module
 *  #5 graphic editor
 *  (c) 2024
 */

#include "hw05_graphic_editor/canvas.hpp"
#include "hw05_graphic_editor/controller.hpp"
#include "hw05_graphic_editor/shape_manager.hpp"

#include <memory>

int main(int, char **) {
	using namespace otus_cpp;

	editor::controller ctrl(std::make_shared<editor::shape_manager>(),
	                        std::make_shared<editor::canvas>());

	ctrl.create_circle(1, 1, 1);
	ctrl.create_circle(2, 2, 2);
	ctrl.update_view();
	ctrl.save_document("untitled.svg");
	ctrl.delete_shape(0);
	ctrl.update_view();

	return 0;
}
