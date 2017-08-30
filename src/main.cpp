#include "testfunctionfactory.h"

using namespace optCompare;

int main(int argc, char ** argv)
{
    char * test_func_name = NULL;

    if (argc == 2)
    {
        test_func_name = argv[1];
    }
    else
    {
        throw std::runtime_error("Usage: OptCompare test_function_name");
        return -1;
    }

    if (test_func_name != NULL)
    {
        std::unique_ptr<TestFunction> tf = TestFunctionFactory::createFunction(std::string(test_func_name));
        tf->findOptimum();
    }
    else
    {
        throw std::runtime_error("Error parsing filename");
        return -1;
    }
    return 0;
}

