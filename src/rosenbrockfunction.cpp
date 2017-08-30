#include "rosenbrockfunction.h"
#include "ceres/ceres.h"

using namespace optCompare;

void RosenbrockFunction::findOptimum()
{
    ceres::Problem rosen_problem;
    ceres::CostFunction * cf = new ceres::AutoDiffCostFunction<RosenbrockCost, 1, 1, 1>(new RosenbrockCost());
    if (cf == NULL)
    {
        throw std::runtime_error("Failure to create cost function");
    }
    rosen_problem.AddResidualBlock(cf,
                                   NULL,
                                   &m_x1,
                                   &m_x2);

    ceres::Solver::Options rosen_options;
    rosen_options.linear_solver_type = ceres::LinearSolverType::DENSE_QR;
    rosen_options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary rosen_summary;
    ceres::Solve(rosen_options, &rosen_problem, &rosen_summary);

    std::cout << rosen_summary.FullReport() << std::endl;
    std::cout << "Optimum value:\n" << "x1: " << m_x1 << "\tx2: " << m_x2 << std::endl;
}

