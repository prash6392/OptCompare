#include "rastringinfunction.h"
#include <ceres/ceres.h>

using namespace optCompare;

void RastringinFunction::findOptimum() {
  ceres::Problem rastringin_problem;
  ceres::CostFunction *cf =
      new ceres::AutoDiffCostFunction<RastringinCost, 1, 1>(
          new RastringinCost());
  if (cf == NULL) {
    throw std::runtime_error("Failure to create cost function");
  }
  rastringin_problem.AddResidualBlock(cf, NULL, &m_x);

  ceres::Solver::Options rastringin_options;
  rastringin_options.linear_solver_type = ceres::LinearSolverType::DENSE_QR;
  rastringin_options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary rastringin_summary;
  ceres::Solve(rastringin_options, &rastringin_problem, &rastringin_summary);

  std::cout << rastringin_summary.FullReport() << std::endl;
  std::cout << "Optimum value:\n"
            << "x1: " << m_x << std::endl;
}
