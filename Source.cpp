#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

class QuadraticEquationSolver {
public:
	QuadraticEquationSolver();

private:

	double A;
	double B;
	double C;

	double Discriminant;

	double x1;
	double x2;
	double Re;
	double Im;

	void SetCoefficients();
	void SetACoefficient(double); 
	void SetBCoefficient(double);
	void SetCCoefficient(double);
	void ShowEquation();
	void GetDiscriminant();
	void SolveTwoRoots();
	void SolveOneRoot();
	void SolveComplexRoots();
	void ShowRealRoots();
	void ShowComplexRoots();

};

void QuadraticEquationSolver::SetCoefficients()
{
	cout << "Enter coefficients of a standart form of Quadratic equation: Ax^2 + Bx + C = 0" << endl;
	cin >> A >> B >> C;

	SetACoefficient(A);
	SetBCoefficient(B);
	SetCCoefficient(C);

	cout <<"\n";
}

void QuadraticEquationSolver::SetACoefficient(double input)
{
	A = input;
}

void QuadraticEquationSolver::SetBCoefficient(double input)
{
	B = input;
}

void QuadraticEquationSolver::SetCCoefficient(double input)
{
	C = input;
}

void QuadraticEquationSolver::ShowEquation()
{
	std::cout <<"Solving equation " << A << "x^2 + " << B << "x + " << C << " = 0" << std::endl;
	cout << "\n";
}

void QuadraticEquationSolver::GetDiscriminant()
{
	Discriminant = B * B - 4 * A * C;
}

void QuadraticEquationSolver::SolveTwoRoots()
{
	x1 = (-B + sqrt(Discriminant)) / 2 * A;
	x2 = (-B - sqrt(Discriminant)) / 2 * A;
}

void QuadraticEquationSolver::SolveOneRoot()
{
	x1 = (-B) / 2*A;
	x2 = x1;
}

void QuadraticEquationSolver::SolveComplexRoots()
{
	Re = -B / 2 * A;
	Im = (sqrt(-Discriminant)) / 2 * A;
}

void QuadraticEquationSolver::ShowRealRoots()
{
	std::cout << "Roots of quadratic equation\n" << std::endl;
	std::cout << "x1 = " << x1 << std::endl;
	std::cout << "x2 = " << x2 << std::endl;
}

void QuadraticEquationSolver::ShowComplexRoots()
{
	std::cout << "Complex roots of quadratic equation\n" << std::endl;
	std::cout << "x1 = " << Re << " + " << "i*" << Im << std::endl;
	std::cout << "x2 = " << Re << " - " << "i*" << Im << std::endl;
	std::cout << "where i is imaginary unit" << std::endl;
}

QuadraticEquationSolver::QuadraticEquationSolver()
{
	SetCoefficients();
	ShowEquation();
	GetDiscriminant();

	if (Discriminant < 0)
	{
		SolveComplexRoots();
		ShowComplexRoots();
	}
	else if (Discriminant > 0)
	{
		SolveTwoRoots();
		ShowRealRoots();
	}
	else
	{
		SolveOneRoot();
		ShowRealRoots();
	}
}

int main(void)
{
	QuadraticEquationSolver EQUATION;
	return 0;
}

