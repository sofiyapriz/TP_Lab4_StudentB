add_executable(ExplicitApp main.cpp)
add_dependencies(ExplicitApp NumericalIntegration)
add_custom_command(TARGET ExplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:NumericalIntegration>"
    "$<TARGET_FILE_DIR:ExplicitApp>"
)
