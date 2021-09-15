#include <iostream>
#include "Vector3D.h"

using namespace std;

int main() {
    Vector3D v = Vector3D(1.0, 2.0, 3.0);
    Vector3D v2 = 5.0*v;
    Vector3D v3 = v2*6.0;
    cout << v2.x << endl;
    cout << v3.y << endl;
}