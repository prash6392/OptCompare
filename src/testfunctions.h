#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

#include <memory>
#include <string>

namespace optCompare {


    class TestFunction
    {
    public:
        TestFunction(const std::string & name)
            : m_name(name)
        {}
        virtual size_t numParams() = 0;
        virtual void findOptimum() = 0;
    private:
        const std::string & m_name;
    };

}


#endif // TESTFUNCTIONS_H
