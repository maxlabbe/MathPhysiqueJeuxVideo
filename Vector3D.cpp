#include <math.h>

#include "Vector3D.h"

// Public methods

double Vector3D::norm() {
    return sqrt(this->squaredNorm());
}

double Vector3D::squaredNorm() {
    return x*x + y*y + z*z ;
}

// Vector3D Vector3D::normalize() {
//     double norm = this->norm();
// }

Vector3D operator*(const double &c, const Vector3D &v) {
    return Vector3D(c*v.x, c*v.y, c*v.z);
}
Vector3D operator*(const Vector3D &v, const double &c) {
    return Vector3D(c*v.x, c*v.y, c*v.z);
}
Vector3D operator/(const Vector3D &v, const double &c) {
    return Vector3D(v.x/c, v.y/c, v.z/c);
}

// Constructors

Vector3D::Vector3D() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}