add_executable(ImplicitApp main.cpp)
target_link_libraries(ImplicitApp PRIVATE NumericalIntegration)
add_custom_command(TARGET ImplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:NumericalIntegration>"
    "$<TARGET_FILE_DIR:ImplicitApp>"
)
