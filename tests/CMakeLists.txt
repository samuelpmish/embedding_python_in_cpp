file(GLOB_RECURSE cpp_tests ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(filename ${cpp_tests})

  # get the name of the file without extension or directory 
  get_filename_component(testname ${filename} NAME_WE)

  # use the remaining string to name the binary file		
  add_executable(${testname} ${filename})

  add_test(${testname} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${testname})		

  target_link_libraries(${testname} PUBLIC mylib)

endforeach(filename ${cpp_tests})
