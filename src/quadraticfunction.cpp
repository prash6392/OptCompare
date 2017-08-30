#include "quadraticfunction.h"
#include <ceres/ceres.h>

using namespace optCompare;

void QuadraticFunction::findOptimum()
{
    ceres::Problem quad_problem;
    ceres::CostFunction * cf = new ceres::AutoDiffCostFunction<QuadraticCost, 1, 1>(new QuadraticCost());
    if (cf == NULL)
    {
        throw std::runtime_error("Failure to create cost function");
    }
    quad_problem.AddResidualBlock(cf,
                                   NULL,
                                   &m_x);

    ceres::Solver::Options quad_options;
    quad_options.linear_solver_type = ceres::LinearSolverType::DENSE_QR;
    quad_options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary quad_summary;
    ceres::Solve(quad_options, &quad_problem, &quad_summary);

    std::cout << quad_summary.FullReport() << std::endl;
    std::cout << "Optimum value:\n" << "x1: " << m_x << std::endl;
}

