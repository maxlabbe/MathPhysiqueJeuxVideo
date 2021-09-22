#include <iostream>
#include "Vector3D.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

int main() {
    Vector3D v1 = Vector3D(1, 2, 3);
    Vector3D v2 = Vector3D(4, 5, 6);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v1.norm() << endl;
    cout << v1.squaredNorm() << endl;
    cout << v1.normalize() << endl;
    cout << 5 * v1 << endl;
    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << v1.elementWiseProduct(v2) << endl;
    cout << v1 * v2 << endl;
    cout << v1.crossProduct(v2) << endl;
    system("pause");
    return 0;
}