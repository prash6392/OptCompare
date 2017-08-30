function [ problem, opt_handle ] = createOptimizationProblem(optalg, func_handle, np)
%createOptimizationProblem creates an optimization problem of the given
%type.

if (strcmp(optalg, 'GA'))
    problem.fitnessfcn = func_handle;
    problem.nvars = np;
    problem.Aineq = [];
    problem.Bineq = [];
    problem.Aeq = [];
    problem.Beq = [];
    % problem.lb = -100;
    % problem.ub = 100;
    problem.nonlcon = [];
    problem.rngstate = [];
    problem.intcon = [];
    problem.solver = 'ga';
    options = gaoptimset();
    % options.InitialPopulationMatrix = {[-50; 50]};
    options.FunctionTolerance = 1e-8;
    options.Display = 'diagnose';
    options.MaxGenerations = 1000;
    options.PopulationSize = 100;
    problem.options = options;
    opt_handle = @ga;
elseif(strcmp(optalg, 'SA'))
    problem.objective = func_handle;
    problem.x0 = ones(np);
    % problem.lb = -100;
    % problem.ub = 100;
    problem.solver = 'simulannealbnd';
    options = saoptimset();
    options.MaxFunctionEvaluations = 1000;
    options.Display = 'diagnose';
    problem.options = options;
    opt_handle = @simulannealbnd;
else
    error('Unsupported optimization algorithm');
end

end

