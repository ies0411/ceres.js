// #pragma once
#include <emscripten.h>
#include <emscripten/bind.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <cstdarg>
#include <iostream>
#include <map>
// static map< string, int > m;
// void Init()
// {
// 　　m["Name"] = ENUM_NAME;
// 　　m["Age"] = ENUM_AGE;
// }

// void func()
// {
// 　　switch(m[sz])
// 　　{
// 　　　　case ENUM_NAME:
// 　　　　　　...
// 　　　　　　break;
// 　　　　case ENUM_AGE:
// 　　　　　　...
// 　　　　　　break;
// 　　}
// }
enum Operation {
    PLUS,
    MINUS,
    MULTIPLE,
    INVERSE,
    TRANSPOSE,

};
// std::map<std::string, cv::Mat>().swap(calib.images_);

static std::map<std::string, int> map_;

void mappingValueToMatrix(int type, int rows, int cols, double *left_values, double *right_values, Eigen::MatrixXd &left_matrix, Eigen::MatrixXd &right_matrix) {
    if (type == Operation::INVERSE || type == Operation::TRANSPOSE) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                left_matrix(row, col) = left_values[(row + 1) * (col)];
            }
        }
        return;
    }
    if (type == Operation::MULTIPLE) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                left_matrix(row, col) = left_values[(row + 1) * (col)];
                right_matrix(col, row) = right_values[(row + 1) * (col)];
            }
        }
        return;
    }
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            left_matrix(row, col) = left_values[(row + 1) * (col)];
            right_matrix(row, col) = right_values[(row + 1) * (col)];
        }
    }
}

extern "C" {
int EMSCRIPTEN_KEEPALIVE operationMatrix(char *operation_type, int rows, int cols, double *left_values, double *right_values, double *result) {
    std::string operation_type_cpp(operation_type);
    Eigen::MatrixXd left_matrix, right_matrix, result_matrix;  // TODO exception in js
    switch (map_[operation_type_cpp]) {
        case Operation::PLUS:
            mappingValueToMatrix(Operation::PLUS, rows, cols, left_values, right_values, left_matrix, right_matrix);
            result_matrix = left_matrix + right_matrix;
            break;

        case Operation::MULTIPLE:
            mappingValueToMatrix(Operation::MULTIPLE, rows, cols, left_values, right_values, left_matrix, right_matrix);

            result_matrix = left_matrix * right_matrix;
            break;

        case Operation::MINUS:
            mappingValueToMatrix(Operation::MINUS, rows, cols, left_values, right_values, left_matrix, right_matrix);

            result_matrix = left_matrix - right_matrix;
            break;
        case Operation::INVERSE:
            mappingValueToMatrix(Operation::INVERSE, rows, cols, left_values, right_values, left_matrix, right_matrix);

            result_matrix = left_matrix.inverse();
            // if (result_matrix == "NaNs") return -1;
            break;
        case Operation::TRANSPOSE:
            mappingValueToMatrix(Operation::TRANSPOSE, rows, cols, left_values, right_values, left_matrix, right_matrix);

            result_matrix = left_matrix.transpose();
            // if (result_matrix == "NaNs") return -1;
            break;

        default:
            std::cout << "nothing matched type" << std::endl;
            return -1;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result[(row + 1) * (col)] = result_matrix(row, col);
        }
    }
    return 1;
}
}