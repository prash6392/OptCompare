#ifndef QUADRATICFUNCTION_H
#define QUADRATICFUNCTION_H

#include "testfunctions.h"

namespace optCompare {

class QuadraticCost {
public:
  template <typename T> bool operator()(const T *const x, T *residuals) const {
    residuals[0] = (T(10) - x[0]);
    return true;
  }
};

class QuadraticFunction : public TestFunction {
public:
  QuadraticFunction() : TestFunction("QuadraticFunction"), m_numParams(1) {}
  virtual size_t numParams() { return m_numParams; }
  virtual void findOptimum();

private:
  const size_t m_numParams;
  double m_x;
};
}

#endif // QUADRATICFUNCTION_H
