#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {

public :

    // Public methods

    double norm();
    double squaredNorm();
    // Vector3D normalize();

    friend Vector3D operator*(const double &, const Vector3D &);
    friend Vector3D operator*(const Vector3D &, const double &);
    friend Vector3D operator/(const Vector3D &, const double &);

    // Constructors

    Vector3D();
    Vector3D(double x, double y, double z);

    // Attributes

    double x;
    double y;
    double z;

};

#endif
