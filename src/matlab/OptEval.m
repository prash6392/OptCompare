function OptEval(algorithm, func_name)

    % Decide which function to optimize
    if (strcmp(func_name, 'Rosenbrock'))
        [problem, optalg] = createOptimizationProblem(algorithm, @RosenbrockFunction, 2);
    elseif(strcmp(func_name, 'Quadratic'))
        [problem, optalg] = createOptimizationProblem(algorithm, @QuadraticFunction, 1);
    elseif(strcmp(func_name, 'Rastringin') || strcmp(func_name, 'Eggholder'))
        [problem, optalg] = createOptimizationProblem(algorithm, @RastringinFunction, 1);
    else
        error('Unsupported function');
    end

    % Solve problem
    opt_params = optalg(problem);

    % Print result
    disp(opt_params);
end