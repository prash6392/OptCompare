#include "testfunctionfactory.h"
#include <exception>
#include <iostream>

using namespace optCompare;

int main(int argc, char **argv) {
  char *test_func_name = NULL;

  try {
    if (argc == 2) {
      test_func_name = argv[1];
    } else {
      throw std::runtime_error("Usage: OptCompare test_function_name\n");
    }

    if (test_func_name != NULL) {
      std::unique_ptr<TestFunction> tf =
          TestFunctionFactory::createFunction(std::string(test_func_name));
      tf->findOptimum();
    } else {
      throw std::runtime_error("Error parsing filename\n");
    }
  } catch (std::exception &e) {
    std::cerr << e.what();
    return -1;
  }

  return 0;
}
