#pragma once
#include <queue>
#include <sstream>
#include <string>
#include <queue>
#include <iostream>

enum StudentLevel {
	studentBad, studentMedium, studentGood
};


struct quadeq {
	double a, b, c;
};


struct report {
	std::string equality;
	std::string solution;
	std::string name;
};

class Student
{
protected:
	quadeq parseQuadEq(const std::string& equality);
	void getCoeffs(std::string& str);

	std::string name;
	Student() {}
public:
	Student(std::string& studName);

	virtual void SolveAndSend(std::string equality, std::queue<report>& reportStack) = 0;
};


class studBad : virtual public Student {
protected:
	studBad() {}
	void SolveAndSend(std::string equality, std::queue<report>& reportStack);
public:
	studBad(std::string& studName) : Student(studName) {}


};

class studGood : virtual public Student {
protected:
	studGood() {}
	void SolveAndSend(std::string equality, std::queue<report>& reportStack);
public:
	studGood(std::string& studName) : Student(studName) {}


};

class studMedium : public studBad, public studGood {
	void SolveAndSend(std::string equality, std::queue<report>& reportStack);
public:
	studMedium(std::string& studName) : Student(studName) {}

};

