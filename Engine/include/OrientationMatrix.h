#pragma once
#include<array>
#include<Common.h>
#include<MathTools/Matrix3.h>

class OrientationMatrix : public Matrix3
{
	//tab[]i[j] i = ligne j = colonne
public:
	OrientationMatrix();
	OrientationMatrix(float p1, float q1, float r1, float p2, float q2, float r2);
	~OrientationMatrix();
};

