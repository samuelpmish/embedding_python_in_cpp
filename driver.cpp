#include <iostream>

#include "mylib.hpp"

int main() {
  initialize();

  std::cout << "starting driver..." << std::endl;

  std::vector<double> input = {1.0, 2.0, 3.0};
  std::vector<double> output = compute_response(input);


  cleanup();
}
