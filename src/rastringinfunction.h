#ifndef RASTRINGINFUNCTION_H
#define RASTRINGINFUNCTION_H

#include "testfunctions.h"
#include <math.h>

namespace optCompare {

    const double PI = 3.14;

    class RastringinCost
    {
    public:
        template<typename T>
        bool operator()(const T* const x, T*residuals) const
        {
            residuals[0] = T(m_A) + pow(x[0], 2) - (T(m_A)*cos((T)2*(T)PI*x[0]));
            return true;
        }
    private:
        const double m_A=1;
    };


    class RastringinFunction : public TestFunction
    {
    public:
        RastringinFunction()
            : TestFunction("Rastringen"),
              m_numparams(1),
              m_x(100)
        {}
        virtual size_t numParams() {return m_numparams;}
        virtual void findOptimum();
    private:
        size_t m_numparams;
        double m_x;
    };

}


#endif // RASTRINGINFUNCTION_H
