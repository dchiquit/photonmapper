/*
 * Vector.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#include<ostream>
#include<cmath>

#include "geometry/Vector3D.h"

namespace graphics {
    Vector3D::Vector3D() : Vector3D(0,0,0) {
    }
    Vector3D::Vector3D(const Vector3D &start, const Vector3D &end) :
    x(end.x - start.x), y(end.y - start.y), z(end.z - start.z) {
    }

    Vector3D::Vector3D(const double x, const double y, const double z) :
    x(x), y(y), z(z) {
    }

    Vector3D::Vector3D(const Vector3D &vector) :
    x(vector.x), y(vector.y), z(vector.z) {
    }

    Vector3D::~Vector3D() {
    }

    Vector3D Vector3D::normalized() {
        auto length = magnitude();
        return
        {
            x / length, y / length, z / length
        };
    }

    double Vector3D::magnitude() {
        if (_magnitude == 0) {
            _magnitude = sqrt(x * x + y * y + z * z);
        }
        return _magnitude;
    }

    Vector3D Vector3D::cross(const Vector3D& v) const {

        auto cx = y * v.z - z * v.y;
        auto cy = z * v.x - x * v.z;
        auto cz = x * v.y - y * v.x;

        return
        {
            cx, cy, cz
        };
    }

    double Vector3D::dot(const Vector3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3D Vector3D::operator+(const Vector3D &rhs) const {
        return
        {
            x + rhs.x, y + rhs.y, z + rhs.z
        };
    }

    Vector3D Vector3D::operator-(const Vector3D &rhs) const {
        return
        {
            x - rhs.x, y - rhs.y, z - rhs.z
        };
    }

    Vector3D Vector3D::operator-() const {
        return
        {
            -x, -y, -z
        };
    }

    Vector3D Vector3D::operator/(const double rhs) const {
        return
        {
            x / rhs, y / rhs, z / rhs
        };
    }

    Vector3D Vector3D::operator*(const double rhs) const {
        return
        {
            x * rhs, y * rhs, z * rhs
        };
    }

    double Vector3D::operator*(const Vector3D& v) const {
        return dot(v);
    }

    Vector3D Vector3D::operator+(const double rhs) const {
        return
        {
            x + rhs, y + rhs, z + rhs
        };
    }

    Vector3D Vector3D::operator-(const double rhs) const {
        return
        {
            x - rhs, y - rhs, z - rhs
        };
    }

    Vector3D operator*(const double lhs, const Vector3D& rhs) {
        return rhs * lhs;
    }

    bool Vector3D::operator==(const Vector3D &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    bool Vector3D::operator!=(const Vector3D &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    std::ostream& operator<<(std::ostream &outs, const Vector3D &vector) {
        return outs << "<" << vector.x << ", " << vector.y << ", " << vector.z
                << ">";
    }

} /* namespace graphics */

