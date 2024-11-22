otus_add_hw(
    NAME hw05_graphic_editor
    SOURCES
        src/hw05_graphic_editor/canvas.cpp
        src/hw05_graphic_editor/circle.cpp
        src/hw05_graphic_editor/controller.cpp
        src/hw05_graphic_editor/shape_manager.cpp
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/hw05_graphic_editor
    CLI_NAME hw_graphic_editor_cli
    CLI_SOURCE src/hw05_graphic_editor/main.cpp
    TESTS tests/test_hw05_graphic_editor.cpp
)
