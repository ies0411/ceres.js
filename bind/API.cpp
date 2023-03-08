
#include "ceresjs.h"
// SingleVarNumericDiff abc;
// std::unique_ptr<SingleVarNumericDiff> ceresjs = std::make_unique<SingleVarNumericDiff>();

extern "C" {
int EMSCRIPTEN_KEEPALIVE singleVarNumericWASM(const int num_paragraph_obj, double* obj_coff, double initial_value_obj) {
  // explicit SingleVarNumericDiff(uint8_t &&num_paragraph_obj, std::vector<double> &&obj_coff, double &&initial_value_obj) {
  std::vector<double> coff_vector;
  for (int i = 0; i < num_paragraph_obj; i++) {
    coff_vector.push_back(obj_coff[i]);
  }
  SingleVarNumericDiff siglevar_numeric(std::move(num_paragraph_obj), std::move(coff_vector), std::move(initial_value_obj));
  siglevar_numeric.solveNumeric();
  // numeric.solve();
  return 1;
}

// int EMSCRIPTEN_KEEPALIVE operationMatrix(char *operation_type, int rows, int cols, double *left_values, double *right_values, double *result) {
//   initMap();
//   std::string operation_type_cpp(operation_type);
//   Eigen::MatrixXd left_matrix, right_matrix, result_matrix;  // TODO exception in js
//   switch (map_[operation_type_cpp]) {
//     case Operation::PLUS:
//       mappingValueToMatrix(Operation::PLUS, rows, cols, left_values, right_values, left_matrix, right_matrix);
//       result_matrix = left_matrix + right_matrix;
//       break;

//     case Operation::MULTIPLE:
//       mappingValueToMatrix(Operation::MULTIPLE, rows, cols, left_values, right_values, left_matrix, right_matrix);

//       result_matrix = left_matrix * right_matrix;
//       break;

//     case Operation::MINUS:
//       mappingValueToMatrix(Operation::MINUS, rows, cols, left_values, right_values, left_matrix, right_matrix);

//       result_matrix = left_matrix - right_matrix;
//       break;
//     case Operation::INVERSE:
//       mappingValueToMatrix(Operation::INVERSE, rows, cols, left_values, right_values, left_matrix, right_matrix);
//       // TODO: exception of inverse
//       result_matrix = left_matrix.inverse();
//       // if (result_matrix == "NaNs") return -1;
//       break;
//     case Operation::TRANSPOSE:
//       mappingValueToMatrix(Operation::TRANSPOSE, rows, cols, left_values, right_values, left_matrix, right_matrix);

//       result_matrix = left_matrix.transpose();
//       // if (result_matrix == "NaNs") return -1;
//       break;
//     case Operation::DOT:
//       result_matrix = left_matrix.dot(right_matrix);

//       break;
//     case Operation::NORM:
//       result_matrix = left_matrix.normalized();
//       break;
//     case Operation::CROSS:
//       result_matrix = left_matrix.cross(right_matrix);
//       break;

//     default:
//       std::cout << "nothing matched type" << std::endl;
//       return -1;
//   }

//   for (int row = 0; row < rows; row++) {
//     for (int col = 0; col < cols; col++) {
//       result[(row + 1) * (col)] = result_matrix(row, col);
//     }
//   }
//   return 1;
// }
}
int main(int argc, const char** argv) {
  return 0;
}