#pragma once
#include "student.h"
#include "teacher.h"
#include "resulttable.h"
#include "manylists.h"
#include <queue>
#include <sstream>
#include <string>
#include <queue>
#include <iostream>

enum StudentLevel {
	studBad, studMedium, studGood
};

struct report {
	std::string equality;
	std::string solution;
	std::string name;
};

class Student
{
private:
	std::string name;
	StudentLevel identificator;

public:
	Student(std::string studName);

	void SolveAndSend(std::string equality, std::queue<report>& reportStack);
};



struct quadeq {
	double a, b, c;
};
