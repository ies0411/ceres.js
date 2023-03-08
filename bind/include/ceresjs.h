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

// enum class Operation {
//   PLUS,
//   MINUS,
//   MULTIPLE,
//   INVERSE,
//   TRANSPOSE,
//   DOT,
//   NORM,
//   CROSS,
// };
// class Operator {
//  private:
//   std::map<std::string, int> map_;

//  public:
//   void initMap() {
//     map_["plus"] = static_cast<int>(Operation::PLUS);
//     map_["minus"] = static_cast<int>(Operation::MINUS);
//     map_["multiple"] = static_cast<int>(Operation::MULTIPLE);
//     map_["inverse"] = static_cast<int>(Operation::INVERSE);
//     map_["transpose"] = static_cast<int>(Operation::TRANSPOSE);
//     map_["dot"] = static_cast<int>(Operation::DOT);
//     map_["norm"] = static_cast<int>(Operation::NORM);
//     map_["cross"] = static_cast<int>(Operation::CROSS);
//   }

// void mappingValueToMatrix(int type, int rows, int cols, double *left_values, double *right_values, Eigen::MatrixXd &left_matrix, Eigen::MatrixXd &right_matrix) {
//   if (type == Operation::INVERSE || type == Operation::TRANSPOSE) {
//     for (int row = 0; row < rows; row++) {
//       for (int col = 0; col < cols; col++) {
//         left_matrix(row, col) = left_values[(row + 1) * (col)];
//       }
//     }
//     return;
//   }
//   if (type == Operation::MULTIPLE) {
//     for (int row = 0; row < rows; row++) {
//       for (int col = 0; col < cols; col++) {
//         left_matrix(row, col) = left_values[(row + 1) * (col)];
//         right_matrix(col, row) = right_values[(row + 1) * (col)];
//       }
//     }
//     return;
//   }
//   for (int row = 0; row < rows; row++) {
//     for (int col = 0; col < cols; col++) {
//       left_matrix(row, col) = left_values[(row + 1) * (col)];
//       right_matrix(row, col) = right_values[(row + 1) * (col)];
//     }
//   }
// }

// explicit Operator() = default;
// virtual ~Operator();
// }
// ;
class SigleNumericErrorTerm {
 private:
  std::vector<double> coff;

 public:
  template <typename T>
  bool operator()(const T *const x, T *residual) const {
    residual[0] = coff[5] - (coff[0] * ceres::pow(x[0], 5) + coff[1] * ceres::pow(x[0], 4) + coff[2] * ceres::pow(x[0], 3) + coff[3] * ceres::pow(x[0], 2) + coff[4] * ceres::pow(x[0], 1));
    // residual[0] = coff[5] - x[0];
    return true;
  }
  SigleNumericErrorTerm(const std::vector<double> &coff_obj) : coff(coff_obj){};
  virtual ~SigleNumericErrorTerm() {
  }
};

class SingleVarNumericDiff {
 private:
  /* data */
  std::vector<double> coff;
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

    // // Run the solver!
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << "\n";
  }

  // void getParam(uint8_t &&num_paragraph_obj, std::vector<double> &&obj_coff, double &&initial_value_obj) {
  //   coff = std::move(obj_coff);
  //   num_paragraph = std::move(num_paragraph_obj);
  //   initial_value = std::move(initial_value_obj);
  // }
  explicit SingleVarNumericDiff(uint8_t &&num_paragraph_obj, std::vector<double> &&obj_coff, double &&initial_value_obj) {
    coff = std::move(obj_coff);
    num_paragraph = std::move(num_paragraph_obj);
    initial_value = std::move(initial_value_obj);
  };
  virtual ~SingleVarNumericDiff(){};
};
// SingleVarNumericDiff::SingleVarNumericDiff() {
// }
// SingleVarNumericDiff::~SingleVarNumericDiff() {
// }

//그냥 application 별로 나눠서 해야할듯