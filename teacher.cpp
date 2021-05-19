#include "teacher.h"

void Teacher::ExamProcess(std::vector<Student*>& students, std::list<std::string>& taskList, std::queue<report>& reportStack)
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

void Teacher::getCoeffs(std::string& str)
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


quadeq Teacher::parseQuadEq(const std::string& equality)
{
	std::stringstream stream(equality);
	quadeq eq_ty;
	stream >> eq_ty.a >> eq_ty.b >> eq_ty.c;
	return eq_ty;
}

void Teacher::checkWorks(std::queue<report>& reportStack, std::map <std::string, int>& reportExam)
{
	while (!reportStack.empty())
	{
		std::string equality = reportStack.front().equality;
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

