
#include "ceresjs.h"
// SingleVarNumericDiff abc;
// std::unique_ptr<SingleVarNumericDiff> ceresjs = std::make_unique<SingleVarNumericDiff>();

extern "C" {
int EMSCRIPTEN_KEEPALIVE singleVarNumericWASM(const int num_paragraph_obj, double* obj_coff, double initial_value_obj) {
  std::vector<double> coff_vector;
  for (int i = 0; i < num_paragraph_obj; i++) {
    coff_vector.push_back(obj_coff[i]);
  }
  SingleVarNumericDiff siglevar_numeric(std::move(num_paragraph_obj), std::move(coff_vector), std::move(initial_value_obj));
  siglevar_numeric.solveNumeric();
  return 1;
}

int main(int argc, const char** argv) {
  return 0;
}