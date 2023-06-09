//
// Created by vm on 23.7.3.
//

#ifndef ASTEROIDS_VEC2D_H
#define ASTEROIDS_VEC2D_H


class Vec2d {
public:
    double x = .0;
    double y = .0;

    Vec2d() {}

    Vec2d(double x, double y);

    /// Normalises vector that its length is 1
    Vec2d normalise();

    /// Calculates length of the vector
    double length();



    Vec2d operator+(Vec2d other) const;

    void operator+=(Vec2d other);

    Vec2d operator-(Vec2d other) const;

    void operator-=(Vec2d other);

    Vec2d operator-() const;


    Vec2d operator*(double a) const;
};


#endif //ASTEROIDS_VEC2D_H
