add_executable(test02-custom-discover EXCLUDE_FROM_ALL test02-custom-discover.cpp)
target_link_libraries(test02-custom-discover PRIVATE Catch2::Catch2WithMain cci)
add_test(NAME "inspection/test02-custom-discover" COMMAND test02-custom-discover)
add_dependencies(check test02-custom-discover)
