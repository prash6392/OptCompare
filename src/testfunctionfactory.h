#ifndef TESTFUNCTIONFACTORY_H
#define TESTFUNCTIONFACTORY_H

#include <memory>
#include <exception>
#include "testfunctions.h"
#include "rosenbrockfunction.h"
#include "quadraticfunction.h"

namespace optCompare {

    class TestFunctionFactory
    {
    public:
        static std::unique_ptr<TestFunction> createFunction(const std::string & name)
        {
            if (name == "Rosenbrock")
            {
                return std::unique_ptr<TestFunction>(new RosenbrockFunction());
            }
            else if (name == "Quadratic")
            {
                return std::unique_ptr<TestFunction>(new QuadraticFunction());
            }
            else
            {
                throw std::runtime_error("Unknown test function.");
            }
        }
    };
}

#endif // TESTFUNCTIONFACTORY_H
