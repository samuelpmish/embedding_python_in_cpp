#pragma once

#include <vector>

// call once, before invoking compute_response
void initialize();

// call at the end of program to clean up memory
void cleanup(); 

std::vector < double > compute_response(std::vector < double > inputs);

