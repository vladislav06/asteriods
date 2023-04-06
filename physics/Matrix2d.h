//
// Created by vm on 23.7.3.
//

#ifndef ASTEROIDS_MATRIX2D_H
#define ASTEROIDS_MATRIX2D_H


#include "Vec2d.h"

class Matrix2d {
private:

    /*
     * /[0][0] [0][1]\
     * \[1][0] [1][1]/
     */
    double matrix[2][2];

public:
    Matrix2d();

    explicit Matrix2d(double matr[2][2]);

    void setMatrix(double matr[2][2]);

    Vec2d operator*(Vec2d vec) const;

    Matrix2d operator*(Matrix2d mt) const;

};


#endif //ASTEROIDS_MATRIX2D_H
