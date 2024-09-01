# otus-cpp-hw
OTUS homework repository 

## CI/CD:
- Last build: ![Last build](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg)
- HW01 github_actions: ![HW01 github_actions](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=feature/github_actions)

## Requirements
 - cmake 3.12
 - boost 1.74

## Prepare
### Linux
```shell script
# apt-get update && sudo apt-get install libboost-test-dev libboost-filesystem-dev libboost-program-options-dev -y
```

### Windows
Download boost [binaries](https://sourceforge.net/projects/boost/files/boost-binaries/) and setup env for boost for e.g.:
```shell script
BOOST_INCLUDEDIR    C:\thirdparty\boost_1_58_0\include
BOOST_LIBRARYDIR    C:\thirdparty\boost_1_58_0\libs
BOOST_ROOT          C:\thirdparty\boost_1_58_0\
```

## Build 
```shell script
$ mkdir build && cd build
$ cmake .. -DPATCH_VERSION=1 -DWITH_BOOST_TEST=ON
$ cmake --build .
```

## Homeworks

| HW | Topic | CLI target | Test target |
|----|-------|------------|-------------|
| 01 | version + hello world | `helloworld_cli` | `test_hw01_version` |

## Usage

### HW01 Usage helloworld_cli
`helloworld_cli` takes no arguments; it prints the version and a hello-world greeting.
```shell script
$ helloworld_cli
```
