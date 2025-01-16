# otus-cpp-hw
OTUS homework repository 

## CI/CD:
- Last build: ![Last build](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg)
- HW01 github_actions: ![HW01 github_actions](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=feature/github_actions)
- HW02 ip_filter: ![HW02 ip_filter](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/ip-filter)
- HW03 allocator: ![HW03 allocator](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/allocator)
- HW04 sfinae_doxygen: ![HW04 sfinae_doxygen](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/sfinae_doxygen)
- HW05 graphic_editor: ![HW05 graphic_editor](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/graphic-editor)
- HW06 n_matrix: ![HW06 n_matrix](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/matrix)
- HW07 terminal: ![HW07 terminal](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/terminal)
- HW08 boost: ![HW08 boost](https://github.com/neverhoodanx/otus-cpp-hw/actions/workflows/release.yml/badge.svg?branch=release/boost)

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
| 02 | IP address filtering, reads TSV on stdin | `ip_filter_cli` | `test_hw02_ip_filter` |
| 03 | custom allocator and container demo | `hw_allocator_cli` | `test_hw03_custom_allocator`, `test_hw03_custom_vector` |
| 04 | SFINAE `print_ip` demo | `hw_sfinae_cli` | `test_hw04_sfinae` |
| 05 | graphic editor demo | `hw_graphic_editor_cli` | `test_hw05_graphic_editor` |
| 06 | N-dimensional sparse matrix demo | `hw_n_matrix_cli` | `test_hw06_matrix` |
| 07 | bulk command terminal | `bulk` | `test_hw07_terminal` |
| 08 | duplicate file finder | `bayan` | `test_hw08_boost` |

## Usage

### HW01 Usage helloworld_cli
`helloworld_cli` takes no arguments; it prints the version and a hello-world greeting.
```shell script
$ helloworld_cli
```

### HW02 Usage ip_filter_cli
Control hash for test data **ip_filter.tsv** is:
```shell script
24e7a7b2270daee89c64d3ca5fb3da1a -
```

#### Linux
```shell script
$ cat ip_filter.tsv | ./ip_filter_cli | md5sum
```

#### Windows
On windows we must convert line endings from LFCF (windows style) to CF(unix stule). we can repalce 0x0d0x0a to 0x0a `(\r\n to \n)` 
```shell script
PS E:\study\otus\build\Debug> cat .\ip_filter.tsv |.\ip_filter_cli.exe > hash.md5
PS E:\study\otus\build\Debug> ((Get-Content hash.md5) -join "`n") + "`n" | Set-Content -NoNewline hash_unix.md5
PS E:\study\otus\build\Debug> certutil -hashfile .\hash_unix.md5 MD5
```

### HW03 Usage hw_allocator_cli
`hw_allocator_cli` takes no arguments; it prints a demonstration of the custom allocator and container.
```shell script
$ hw_allocator_cli
```

### HW04 Usage hw_sfinae_cli
`hw_sfinae_cli` takes no arguments; it prints a demonstration of the SFINAE `print_ip` overloads.
```shell script
$ hw_sfinae_cli
```

### HW05 Usage hw_graphic_editor_cli
`hw_graphic_editor_cli` takes no arguments; it prints a demonstration of the graphic editor.
```shell script
$ hw_graphic_editor_cli
```

### HW06 Usage hw_n_matrix_cli
`hw_n_matrix_cli` takes no arguments; it prints a demonstration of the N-dimensional sparse matrix.
```shell script
$ hw_n_matrix_cli
```

### HW07 Usage bulk
`bulk` reads commands from stdin and executes them in static blocks of `<block_size>` lines.
```shell script
$ bulk <block_size>
```

### HW08 Usage bayan
Usage example:
```shell script
$ bayan -d "~\test" -b 64
```
Allowed options:
```shell script
Allowed options:
  --help                          produce help message
  -d [ --directories ] arg        directories to scan
  -e [ --exclude ] arg            directories to exclude
  -m [ --mask ] arg               file name masks
  -s [ --min-size ] arg (=1)      minimum file size
  -b [ --block-size ] arg (=4096) block size for reading
  -l [ --level ] arg (=1)         scanning level (0 Current directory only or 1 Recursive scanning)
  -H [ --hash ] arg (=md5)        hash type (md5 or crc32)
```
Example output :
```
hash: 09865ADB932231FB4019B4D048696B01, dublicates: 
 - home/neverhooda/test/2.txt 
 - home/neverhooda/test/test/4.bin 
 - home/neverhooda/test/test/4.txt 
```
