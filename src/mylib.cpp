#include "mylib.hpp"

#include <pybind11/embed.h>

#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

// this object exists to help manage the lifetime of the python interpreter
struct Simulation {
  Simulation() {
    mypythonlib = py::module_::import("mypythonlib");
  }

  std::vector < double > operator()(const std::vector< double > & inputs) {

    std::cout << "(c++) x: ";
    for (auto value : inputs) {
      std::cout << value << " ";
    }
    std::cout << std::endl;

    // pass the data through to the python interpreter, invoke "process_data" and cast the output back to a vector
    //
    // note: this is only one of many ways of executing python code with pybind11, for other ways to
    // run arbitrary code snippets or existing script files, see https://pybind11.readthedocs.io/en/stable/advanced/embedding.html
    std::vector< double > outputs = mypythonlib.attr("process_data")(&inputs).cast<std::vector<double>>();

    std::cout << "(c++) f'(x): ";
    for (auto value : outputs) {
      std::cout << value << " ";
    }
    std::cout << std::endl;

    return outputs;
  }

  // note: the interpreter is declared first, so that
  // it will be the last to be destroyed when the class
  // is deconstructed, see: tinyurl.com/2hjb6k27
  py::scoped_interpreter context;

  py::module_ mypythonlib;

};

Simulation * sim;

////////////////////////////////////////////////////

// the free functions exist only to forward information to the Simulation object
void initialize() { sim = new Simulation; }

std::vector< double > compute_response(std::vector< double > inputs) {
  return (*sim)(inputs);
}

void cleanup() { delete sim; }
