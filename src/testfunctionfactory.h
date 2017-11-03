#ifndef TESTFUNCTIONFACTORY_H
#define TESTFUNCTIONFACTORY_H

#include "quadraticfunction.h"
#include "rastringinfunction.h"
#include "rosenbrockfunction.h"
#include "testfunctions.h"
#include <exception>
#include <memory>

namespace optCompare {

class TestFunctionFactory {
public:
  static std::unique_ptr<TestFunction> createFunction(const std::string &name) {
    if (name == "Rosenbrock") {
      return std::unique_ptr<TestFunction>(new RosenbrockFunction());
    } else if (name == "Quadratic") {
      return std::unique_ptr<TestFunction>(new QuadraticFunction());
    } else if (name == "Rastringin") {
      return std::unique_ptr<TestFunction>(new RastringinFunction());
    } else {
      throw std::runtime_error("Unknown test function.");
    }
  }
};
}

#endif // TESTFUNCTIONFACTORY_H
