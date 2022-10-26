# embedding_python_in_cpp
an example project using pybind11 to embed python in a C++ executable. There are three basic parts:

1. a C++ driver executable ([`driver.cpp`](https://github.com/samuelpmish/embedding_python_in_cpp/blob/main/driver.cpp))
2. a small C++ library ([`src/mylib.cpp`](https://github.com/samuelpmish/embedding_python_in_cpp/blob/main/src/mylib.cpp)) that negociates between the driver executable and the python library
3. a small jax / python library ([`mypythonlib.py`](https://github.com/samuelpmish/embedding_python_in_cpp/blob/main/mypythonlib.py))

# requirements

this project uses [jax](https://github.com/google/jax), so install that first

# build instructions

clone the project recursively

```
git clone https://github.com/samuelpmish/embedding_python_in_cpp.git --recursive
```

configure and build with CMake

```
cd embedding_python_in_cpp
cmake . -Bbuild
cmake --build build
```

run the driver executable from the base directory (so that the python interpreter 
will find `import mypythonlib`

```
% build/driver
starting driver...
(c++) x: 1 2 3 
(python) computing dfdx elementwise ... 
(c++) f'(x): 1.38177 0.0770037 -2.82886 
```
