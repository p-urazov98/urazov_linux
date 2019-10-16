#include "tetra.h"
#include "polyhedron.h"
#include <string>
#include <iostream>


tetra::tetra()
{
	vertex A0, B0, C0, D0;
	A0.load(0, 0, 5);
	B0.load(5, 0, 0);
	C0.load(0, 5, 0);
	D0.load(0, 0, 0);
	load_all_vertex(A0, B0, C0, D0);
}
tetra::~tetra()
{
}
void tetra::load_all_vertex(vertex A0, vertex B0, vertex C0, vertex D0)
{
	double vec1[3], vec2[3], vec3[3];

	if (A0.P[2] >= B0.P[2] && A0.P[2] >= C0.P[2] && A0.P[2] >= D0.P[2])
	{
		A = A0;

		if (B0.P[0] >= C0.P[0] && B0.P[0] >= D0.P[0])
		{
			B = B0;
			vec(B.P, A.P, vec1);
			vec(B.P, C0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = C0;
				D = D0;
			}
			else
			{
				C = D0;
				D = C0;
			}
		}
		if (C0.P[0] >= B0.P[0] && C0.P[0] >= D0.P[0])
		{
			B = C0;
			vec(B.P, A.P, vec1);
			vec(B.P, B0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = B0;
				D = D0;
			}
			else
			{
				C = D0;
				D = B0;
			}
		}
		if (D0.P[0] >= B0.P[0] && D0.P[0] >= C0.P[0])
		{
			B = D0;
			vec(B.P, A.P, vec1);
			vec(B.P, B0.P, vec2);
			vec(B.P, C0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = B0;
				D = C0;
			}
			else
			{
				C = C0;
				D = B0;
			}
		}
	}
	if (B0.P[2] >= A0.P[2] && B0.P[2] >= C0.P[2] && B0.P[2] >= D0.P[2])
	{
		A = B0;

		if (A0.P[0] >= C0.P[0] && A0.P[0] >= D0.P[0])
		{
			B = A0;
			vec(B.P, A.P, vec1);
			vec(B.P, C0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = C0;
				D = D0;
			}
			else
			{
				C = D0;
				D = C0;
			}
		}

		if (C0.P[0] >= A0.P[0] && C0.P[0] >= D0.P[0])
		{
			B = C0;
			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = D0;
			}
			else
			{
				C = D0;
				D = A0;
			}
		}
		if (D0.P[0] >= A0.P[0] && D0.P[0] >= C0.P[0])
		{
			B = D0;
			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, C0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = C0;
			}
			else
			{
				C = C0;
				D = A0;
			}
		}
	}
	if (C0.P[2] >= A0.P[2] && C0.P[2] >= B0.P[2] && C0.P[2] >= D0.P[2])
	{
		A = C0;

		if (A0.P[0] > B0.P[0] && A0.P[0] > D0.P[0])
		{
			B = A0;
			vec(B.P, A.P, vec1);
			vec(B.P, B0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = B0;
				D = D0;
			}
			else
			{
				C = D0;
				D = B0;
			}
		}

		if (B0.P[0] >= A0.P[0] && B0.P[0] >= D0.P[0])
		{
			B = B0;
			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, D0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = D0;
			}
			else
			{
				C = D0;
				D = A0;
			}
		}
		if (D0.P[0] >= A0.P[0] && D0.P[0] >= B0.P[0])
		{
			B = D0;
			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, B0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = B0;
			}
			else
			{
				C = B0;
				D = A0;
			}
		}
	}
	if (D0.P[2] >= A0.P[2] && D0.P[2] >= B0.P[2] && D0.P[2] >= C0.P[2])
	{
		A = D0;

		if (A0.P[0] > B0.P[0] && A0.P[0] > C0.P[0])
		{
			B = A0;
			vec(B.P, A.P, vec1);
			vec(B.P, B0.P, vec2);
			vec(B.P, C0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = B0;
				D = C0;
			}
			else
			{
				C = C0;
				D = B0;
			}
		}

		if (B0.P[0] >= A0.P[0] && B0.P[0] >= C0.P[0])
		{
			B = B0;

			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, C0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = C0;
			}
			else
			{
				C = C0;
				D = A0;
			}
		}
		if (C0.P[0] >= A0.P[0] && C0.P[0] >= B0.P[0])
		{
			B = C0;
			vec(B.P, A.P, vec1);
			vec(B.P, A0.P, vec2);
			vec(B.P, B0.P, vec3);

			if (mix_mult(vec1, vec2, vec3) > 0)
			{
				C = A0;
				D = B0;
			}
			else
			{
				C = B0;
				D = A0;
			}
		}
	}
	calc_all_vertex();
}
void tetra::calc_all_vertex()
{
	//Точка А - точка с наибольшей координатой z. Вершины B,C,D вокруг нее против часовой стрелки;
	
	//Обрабатываем T
	////////////////////
	//AB
	vec_norm(A.P, B.P, A.T1);
	//AC
	vec_norm(A.P, C.P, A.T2);
	//AD
	vec_norm(A.P, D.P, A.T3);
	////////////////////
	//BA
	vec_norm(B.P, A.P, B.T1);
	//BD
	vec_norm(B.P, D.P, B.T2);
	//BC
	vec_norm(B.P, C.P, B.T3);
	////////////////////
	//CA
	vec_norm(C.P, A.P, C.T1);
	//CB
	vec_norm(C.P, B.P, C.T2);
	//CD
	vec_norm(C.P, D.P, C.T3);
	////////////////////
	//DA
	vec_norm(D.P, A.P, D.T1);
	//DC
	vec_norm(D.P, C.P, D.T2);
	//DB
	vec_norm(D.P, B.P, D.T3);
	
	//справа плоскость - 1; слева плоскость - 2

	vec_mult_norm(A.T1, A.T3, A.B1_1);
	vec_mult_norm(A.T2, A.T1, A.B1_2);

	vec_mult_norm(A.T2, A.T1, A.B2_1);
	vec_mult_norm(A.T3, A.T2, A.B2_2);

	vec_mult_norm(A.T3, A.T2, A.B3_1);
	vec_mult_norm(A.T1, A.T3, A.B3_2);

	vec_mult_norm(B.T1, B.T3, B.B1_1);
	vec_mult_norm(B.T2, B.T1, B.B1_2);

	vec_mult_norm(B.T2, B.T1, B.B2_1);
	vec_mult_norm(B.T3, B.T2, B.B2_2);

	vec_mult_norm(B.T3, B.T2, B.B3_1);
	vec_mult_norm(B.T1, B.T3, B.B3_2);

	vec_mult_norm(C.T1, C.T3, C.B1_1);
	vec_mult_norm(C.T2, C.T1, C.B1_2);

	vec_mult_norm(C.T2, C.T1, C.B2_1);
	vec_mult_norm(C.T3, C.T2, C.B2_2);

	vec_mult_norm(C.T3, C.T2, C.B3_1);
	vec_mult_norm(C.T1, C.T3, C.B3_2);
	
	vec_mult_norm(D.T1, D.T3, D.B1_1);
	vec_mult_norm(D.T2, D.T1, D.B1_2);

	vec_mult_norm(D.T2, D.T1, D.B2_1);
	vec_mult_norm(D.T3, D.T2, D.B2_2);

	vec_mult_norm(D.T3, D.T2, D.B3_1);
	vec_mult_norm(D.T1, D.T3, D.B3_2);

	//Теперь обрабатываем N
	vec_mult_norm(A.B1_1, A.T1, A.N1_1);
	vec_mult_norm(A.T1, A.B1_2, A.N1_2);
	vec_mult_norm(A.B2_1, A.T2, A.N2_1);
	vec_mult_norm(A.T2, A.B2_2, A.N2_2);
	vec_mult_norm(A.B3_1, A.T3, A.N3_1);
	vec_mult_norm(A.T3, A.B3_2, A.N3_2);

	vec_mult_norm(B.B1_1, B.T1, B.N1_1);
	vec_mult_norm(B.T1, B.B1_2, B.N1_2);
	vec_mult_norm(B.B2_1, B.T2, B.N2_1);
	vec_mult_norm(B.T2, B.B2_2, B.N2_2);
	vec_mult_norm(B.B3_1, B.T3, B.N3_1);
	vec_mult_norm(B.T3, B.B3_2, B.N3_2);

	vec_mult_norm(C.B1_1, C.T1, C.N1_1);
	vec_mult_norm(C.T1, C.B1_2, C.N1_2);
	vec_mult_norm(C.B2_1, C.T2, C.N2_1);
	vec_mult_norm(C.T2, C.B2_2, C.N2_2);
	vec_mult_norm(C.B3_1, C.T3, C.N3_1);
	vec_mult_norm(C.T3, C.B3_2, C.N3_2);

	vec_mult_norm(D.B1_1, D.T1, D.N1_1);
	vec_mult_norm(D.T1, D.B1_2, D.N1_2);
	vec_mult_norm(D.B2_1, D.T2, D.N2_1);
	vec_mult_norm(D.T2, D.B2_2, D.N2_2);
	vec_mult_norm(D.B3_1, D.T3, D.N3_1);
	vec_mult_norm(D.T3, D.B3_2, D.N3_2);

	///ABC
	matrix[0][0] = A.B1_2[0];
	matrix[0][1] = A.B1_2[1];
	matrix[0][2] = A.B1_2[2];
	matrix[0][3] = -A.B1_2[0] * A.P[0] - A.B1_2[1] * A.P[1] - A.B1_2[2] * A.P[2];

	for (int i = 0; i < 4; i++)
	{
		ABC[i] = matrix[0][i];
	}

	///ACD
	matrix[1][0] = A.B2_2[0];
	matrix[1][1] = A.B2_2[1];
	matrix[1][2] = A.B2_2[2];
	matrix[1][3] = -A.B2_2[0] * A.P[0] - A.B2_2[1] * A.P[1] - A.B2_2[2] * A.P[2];

	for (int i = 0; i < 4; i++)
	{
		ACD[i] = matrix[1][i];
	}

	///ABD
	matrix[2][0] = A.B1_1[0];
	matrix[2][1] = A.B1_1[1];
	matrix[2][2] = A.B1_1[2];
	matrix[2][3] = -A.B1_1[0] * A.P[0] - A.B1_1[1] * A.P[1] - A.B1_1[2] * A.P[2];

	for (int i = 0; i < 4; i++)
	{
		ABD[i] = matrix[2][i];
	}

	///BCD
	matrix[3][0] = B.B2_2[0];
	matrix[3][1] = B.B2_2[1];
	matrix[3][2] = B.B2_2[2];
	matrix[3][3] = -B.B2_2[0] * B.P[0] - B.B2_2[1] * B.P[1] - B.B2_2[2] * B.P[2];

	for (int i = 0; i < 4; i++)
	{
		BCD[i] = matrix[3][i];
	}

}
double tetra::calc_dist(double X[3], double Y[3])
{
	return sqrt((X[0] - Y[0])*(X[0] - Y[0]) + (X[1] - Y[1])*(X[1] - Y[1]) + (X[2] - Y[2])*(X[2] - Y[2]));
}
void tetra::vec(double A[3], double B[3], double RES[3])
{
	RES[0] = (B[0] - A[0]);
	RES[1] = (B[1] - A[1]);
	RES[2] = (B[2] - A[2]);
}
void tetra::vec_norm(double A[3], double B[3], double RES[3])
{
	double dist = 0;
	dist = calc_dist(A, B);
	RES[0] = (B[0] - A[0]) / dist;
	RES[1] = (B[1] - A[1]) / dist;
	RES[2] = (B[2] - A[2]) / dist;
}
void tetra::vec_mult_norm(double A[3], double B[3], double RES[3])
{
	double norm = 0;
	RES[0] = A[1] * B[2] - B[1] * A[2];
	RES[1] = -(A[0] * B[2] - B[0] * A[2]);
	RES[2] = A[0] * B[1] - B[0] * A[1];
	norm = sqrt(RES[0] * RES[0] + RES[1] * RES[1] + RES[2] * RES[2]);

	//нормировка
	for (int i = 0; i < 3; i++)
	{
		RES[i] = RES[i] / norm;
	}
}
double tetra::mix_mult(double A[3], double B[3], double C[3])
{
	double t[3], res=0;

	t[0] = A[1] * B[2] - A[2] * B[1];
	t[1] = A[2] * B[0] - A[0] * B[2];
	t[2] = A[0] * B[1] - A[1] * B[0];
	res = C[0] * t[0] + C[1] * t[1] + C[2] * t[2];

	return res;
}
bool tetra::check_in_tetra(double TEST[3])
{
	bool res = true;
	double val = 0;

	for (int i = 0; i < 4; i++)
	{
		val = matrix[i][0] * TEST[0] + matrix[i][1] * TEST[1] + matrix[i][2] * TEST[2] + matrix[i][3];
		if (val < 0)
		{
			res = false;
			break;
		}
	}

	return res;
}
double tetra::volume_tetra()
{
	return A.vertex_volume() + B.vertex_volume() + C.vertex_volume() + D.vertex_volume();
}