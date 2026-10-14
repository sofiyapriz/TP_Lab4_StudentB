add_library(NumericalDiff STATIC src/NumericalDiff.cpp)
target_include_directories(NumericalDiff PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(NumericalDiff PUBLIC cxx_std_20)
