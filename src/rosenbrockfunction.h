#ifndef ROSENBROCKFUNCTION_H
#define ROSENBROCKFUNCTION_H

#include "testfunctions.h"
#include <math.h>

namespace optCompare {

    class RosenbrockCost
    {
    public:
        template <typename T>
        bool operator()(const T* const x1, const T* const x2, T* residuals)
        const
        {
            residuals[0] = pow(T(100)*(x2[0] - (x1[0]*x1[0])), 2) + pow((x1[0] - T(1)), 2);
            return true;
        }
    };


    class RosenbrockFunction : public TestFunction
    {
    public:
        RosenbrockFunction()
            : TestFunction("Rosenbrock"),
              m_numParams(2),
              m_x1(1.02),
              m_x2(1.5)
        {}
        virtual size_t numParams() {return m_numParams;}
        virtual void findOptimum();
    private:
        const size_t m_numParams;
        double m_x1;
        double m_x2;
    };
}

#endif // ROSENBROCKFUNCTION_H
