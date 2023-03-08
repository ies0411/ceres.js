// #pragma once
#include <emscripten.h>
#include <emscripten/bind.h>

// #include <Eigen/Core>
// #include <Eigen/Dense>
// #include <cstdarg>
#include <ceres/ceres.h>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <map>
#include <vector>

class SigleNumericErrorTerm {
 private:
  std::vector<double> coff;

 public:
  template <typename T>
  bool operator()(const T *const x, T *residual) const {
    residual[0] = coff[5] - (coff[0] * ceres::pow(x[0], 5) + coff[1] * ceres::pow(x[0], 4) + coff[2] * ceres::pow(x[0], 3) + coff[3] * ceres::pow(x[0], 2) + coff[4] * ceres::pow(x[0], 1));
    return true;
  }
  SigleNumericErrorTerm(const std::vector<double> &coff_obj) : coff(coff_obj){};
  virtual ~SigleNumericErrorTerm() {
  }
};

class SingleVarNumericDiff {
 private:
  /* data */
  std::vector<double> coff(5, 0);
  uint8_t num_paragraph;
  double initial_value;

 public:
  void solveNumeric() {
    // Build the problem.
    ceres::Problem problem;

    // Set up the only cost function (also known as residual). This uses
    // auto-differentiation to obtain the derivative (jacobian).
    //가변인자
    ceres::CostFunction *cost_function =
        new ceres::AutoDiffCostFunction<SigleNumericErrorTerm, 1, 5>(new SigleNumericErrorTerm(coff));
    problem.AddResidualBlock(cost_function, nullptr, &initial_value);

    // Run the solver!
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << "\n";
  }

  explicit SingleVarNumericDiff(uint8_t &&num_paragraph_obj, std::vector<double> &&obj_coff, double &&initial_value_obj) {
    
    coff = std::move(obj_coff);
    num_paragraph = std::move(num_paragraph_obj);
    initial_value = std::move(initial_value_obj);
  };
  virtual ~SingleVarNumericDiff(){};
};
