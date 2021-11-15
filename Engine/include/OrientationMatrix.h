#pragma once
#include<array>
#include<Common.h>

class OrientationMatrix
{
	//tab[]i[j] i = ligne j = colonne
public:
	OrientationMatrix();
	OrientationMatrix(float p1, float q1, float r1, float p2, float q2, float r2);
	~OrientationMatrix();
	const array<array<float, 3>, 3> GetMatrix();

private:
	array<array<float, 3>, 3> m_matrix;
};

