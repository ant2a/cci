add_executable(test01-basic EXCLUDE_FROM_ALL test01-basic.cpp)
target_link_libraries(test01-basic PRIVATE Catch2::Catch2WithMain cci)
add_test(NAME "inspection/test01-basic" COMMAND test01-basic)
add_dependencies(check test01-basic)
