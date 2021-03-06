#include "student.h"


Student::Student(std::string& studName)
{
	name = studName;
}

quadeq Student::parseQuadEq(const std::string& equality)
{
	std::stringstream stream(equality);
	quadeq eq_ty;
	stream >> eq_ty.a >> eq_ty.b >> eq_ty.c;
	return eq_ty;
}

void Student::getCoeffs(std::string& str)
{
	int charCounter = 0;
	while (str[charCounter] != '=')
	{
		if (str[charCounter] != '-' && str[charCounter] != '.' && !(str[charCounter] >= '0' && str[charCounter] <= '9'))
		{
			if (str[charCounter] == '^')
			{
				str[charCounter] = ' ';
				charCounter++;
			}
			str[charCounter] = ' ';
		}
		charCounter++;
	}
	str[charCounter] = ' ';
	str[charCounter + 1] = ' ';
}

void studBad::SolveAndSend(std::string equality, std::queue<report>& reportStack) {
	report repToSend;
	repToSend.equality = equality;
	repToSend.name = name;
	repToSend.solution = "x = 0";
	reportStack.push(repToSend);
}

void studGood::SolveAndSend(std::string equality, std::queue<report>& reportStack) {
	report repToSend;
	repToSend.equality = equality;
	repToSend.name = name;

	getCoeffs(equality);
	quadeq eq_ty = parseQuadEq(equality);

	double sol[2];
	sol[0] = (-eq_ty.b - sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;
	sol[1] = (-eq_ty.b + sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;

	std::ostringstream stringsolution;
	stringsolution << "x1 = " << sol[0] << " x2 = " << sol[1];
	repToSend.solution = stringsolution.str();

	reportStack.push(repToSend);
}

const int blessRNGstudent = 2;

void studMedium::SolveAndSend(std::string equality, std::queue<report>& reportStack) {
	if (rand() % blessRNGstudent) {
		studGood::SolveAndSend(equality, reportStack);
	}
	else {
		studBad::SolveAndSend(equality, reportStack);
	}
}