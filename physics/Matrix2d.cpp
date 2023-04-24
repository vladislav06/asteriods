//
// Created by vm on 23.7.3.
//

#include "Matrix2d.h"
#include <cmath>

Vec2d Matrix2d::operator*(Vec2d vec) const {
    return Vec2d(this->matrix[0][0] * vec.x + this->matrix[0][1] * vec.y,
                 this->matrix[1][0] * vec.x + this->matrix[1][1] * vec.y
    );

}

Matrix2d Matrix2d::operator*(Matrix2d mt) const {
    double rez[2][2] = {
            {
                    this->matrix[0][0] * mt.matrix[0][0] + this->matrix[0][1] * mt.matrix[1][0],
                    this->matrix[0][0] * mt.matrix[0][1] + this->matrix[0][1] * mt.matrix[1][1]},
            {
                    this->matrix[1][0] * mt.matrix[0][0] + this->matrix[1][1] * mt.matrix[1][0],
                    this->matrix[1][0] * mt.matrix[0][1] + this->matrix[1][1] * mt.matrix[1][1]
            }
    };
    return Matrix2d(rez);
}

Matrix2d::Matrix2d() {
    this->matrix[0][0] = 0;
    this->matrix[0][1] = 0;
    this->matrix[1][0] = 0;
    this->matrix[1][1] = 0;
}

Matrix2d::Matrix2d(double matr[2][2]) {
    this->matrix[0][0] = matr[0][0];
    this->matrix[0][1] = matr[0][1];
    this->matrix[1][0] = matr[1][0];
    this->matrix[1][1] = matr[1][1];
}

void Matrix2d::setMatrix(double matr[2][2]) {
    this->matrix[0][0] = matr[0][0];
    this->matrix[0][1] = matr[0][1];
    this->matrix[1][0] = matr[1][0];
    this->matrix[1][1] = matr[1][1];
}

Matrix2d::Matrix2d(double deg) {
    //calculate new rotational matrix
    this->matrix[0][0] = std::cos(deg);
    this->matrix[0][1] = -std::sin(deg);
    this->matrix[1][0] = std::sin(deg);
    this->matrix[1][1] = std::cos(deg);

}
