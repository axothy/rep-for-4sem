#pragma once
#include "student.h"
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <iterator>


class Teacher
{
	quadeq parseQuadEq(const std::string& equality);
	void getCoeffs(std::string& str);
public:
	void ExamProcess(std::vector<Student*>& students, std::list<std::string>& taskList, std::queue<report>& reportStack);
	void checkWorks(std::queue<report>& reportStack, std::map <std::string, int>& reportExam);
};
