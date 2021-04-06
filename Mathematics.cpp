#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>
#include <map>
#include <array>
#include <ctime>

enum StudentLevel {
	studBad, 
	studMedium, 
	studGood
};

struct report {
	std::string equation;
	std::string solution;
	std::string name;
};

struct quadeq {
	double a, b, c;
};

class Student
{
private:
	std::string name;
	StudentLevel identificator;

public:
	Student(std::string studName);

	void SolveAndSend(std::string equation, std::queue<report>& reportStack); //*
};

class Teacher
{
public:
	void ExamProcess(std::vector<Student*> students, std::list<std::string> taskList, std::queue<report>& reportStack);
	void checkWorks(std::queue<report> reportStack, std::map <std::string, int>& reportExam);
	void printResults(std::map <std::string, int> reportExam);
};

Student::Student(std::string studName)
{
	name = studName;
	identificator = static_cast<StudentLevel>(rand() % 3); //*
}

void getCoeffs(std::string& str)
{
	int charCounter = 0;
	while (str[charCounter] != '=')
	{
		if (str[charCounter] != '-' && str[charCounter] != '.' && !(str[charCounter] >= '0' && str[charCounter] <= '9')) //*
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

quadeq parseQuadEq(std::string equation) //*
{
	std::stringstream stream(equation);
	quadeq eq_ty;
	stream >> eq_ty.a >> eq_ty.b >> eq_ty.c;
	return eq_ty;
}

void Student::SolveAndSend(std::string equation, std::queue<report>& reportStack)
{
	report repToSend;
	repToSend.equation = equation;
	repToSend.name = name;
	if (identificator == studBad)
	{
		repToSend.solution = "x = 0";
	}
	else if (identificator == studMedium)
	{
		if (rand() % 2 == 0)
		{
			repToSend.solution = "x = 0";
		}
		else
		{
			getCoeffs(equation); // *
			quadeq eq_ty = parseQuadEq(equation); //*

			double sol[2];
			sol[0] = (-eq_ty.b - sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;
			sol[1] = (-eq_ty.b + sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;

			std::ostringstream stringsolution;
			stringsolution << "x1 = " << sol[0] << " x2 = " << sol[1];
			repToSend.solution = stringsolution.str(); //*
		}
	}
	else if (identificator == studGood)
	{
		getCoeffs(equation);
		quadeq eq_ty = parseQuadEq(equation);

		double sol[2];
		sol[0] = (-eq_ty.b - sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;
		sol[1] = (-eq_ty.b + sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;

		std::ostringstream stringsolution;
		stringsolution << "x1 = " << sol[0] << " x2 = " << sol[1];
		repToSend.solution = stringsolution.str();
	}
	reportStack.push(repToSend); //*
}

namespace studentsGroup
{
	std::array<std::string, 18> name = { //*
	"Nastya", "Misha", "Sasha",
	"Darya", "Mihail", "Anya",
	"Iskander", "Olya", "Katya",
	"Max", "Sergey", "Maria",
	"Vlada", "Anton", "Fedya",
	"Alexey", "Konstantin", "Nikolay"
	};
}

namespace tasklist
{
	std::array<std::string, 5> equation = {
		"-1*x^2-10.42*x-4.19=0",
		"-2*x^2-9.4*x-4.51=0",
		"-3*x^2-9.6*x-4.91=0",
		"-4.3*x^2-9.1*x-4.22=0",
		"-5*x^2-9*x-4.33=0"
	};
}

void fillStudents(std::vector<Student*>& students) {
	Student* studentCreation;

	for (int studCounter = 0; studCounter < studentsGroup::name.size(); studCounter++)
	{
		studentCreation = new Student(studentsGroup::name[studCounter]);
		students.push_back(studentCreation); //*
	}
}

void fillTasks(std::list<std::string>& taskList) {
	for (int taskCounter = 0; taskCounter < tasklist::equation.size(); taskCounter++)
	{
		taskList.push_back(tasklist::equation[taskCounter]); //*
	}
}

void Teacher::ExamProcess(std::vector<Student*> students, std::list<std::string> taskList, std::queue<report>& reportStack)
{
	for (std::list <std::string> ::iterator itTask = taskList.begin(); itTask != taskList.end(); itTask++)
	{
		int counter = 0;
		for (std::vector <Student*> ::iterator itStud = students.begin(); itStud < students.end(); itStud++)
		{
			students.at(counter)->SolveAndSend(*itTask, reportStack);
			counter++;
		}
	}
}

void Teacher::checkWorks(std::queue<report> reportStack, std::map <std::string, int>& reportExam)
{
	while (!reportStack.empty())
	{
		std::string equality = reportStack.front().equation;
		getCoeffs(equality);
		quadeq eq_ty = parseQuadEq(equality);

		double sol[2];
		sol[0] = (-eq_ty.b - sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;
		sol[1] = (-eq_ty.b + sqrt(eq_ty.b * eq_ty.b - 4.0 * eq_ty.a * eq_ty.c)) / 2.0;

		std::ostringstream stringsolution;
		stringsolution << "x1 = " << sol[0] << " x2 = " << sol[1];

		std::string solution = stringsolution.str();

		std::map <std::string, int> ::iterator it;
		it = reportExam.find(reportStack.front().name);

		if (it == reportExam.end())
		{
			reportExam.insert(std::make_pair(reportStack.front().name, 0));
			it = reportExam.find(reportStack.front().name);
			if (solution == reportStack.front().solution)
				it->second = it->second + 1;
		}
		else
			if (solution == reportStack.front().solution)
				it->second = it->second + 1;

		reportStack.pop();
	}
}

void Teacher::printResults(std::map <std::string, int> reportExam)
{
	std::map <std::string, int> ::iterator it = reportExam.begin();
	for (; it != reportExam.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

int main()
{
	time_t rawtime;
	tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);


	std::stringstream timestream;
	timestream << asctime(timeinfo);

	if (timestream.str() == asctime(timeinfo)) {
		std::cout << "Exam began on " << asctime(timeinfo) << std::endl;
	}
	else {
		std::cout << "It is not time yet for exam, enjoy it!";
		return 0;
	}

	Teacher MarVanna;

	std::vector<Student*> students;
	std::list<std::string> taskList;
	std::queue<report> reportStack;

	fillStudents(students);

	fillTasks(taskList);
	MarVanna.ExamProcess(students, taskList, reportStack);

	std::map <std::string, int> reportExam;
	MarVanna.checkWorks(reportStack, reportExam);

	MarVanna.printResults(reportExam);

	return 0;
}