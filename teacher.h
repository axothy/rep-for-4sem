#pragma once
#include "student.h"
#include "teacher.h"
#include "resulttable.h"
#include "manylists.h"
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <iterator>


class Teacher
{
public:
	void ExamProcess(std::vector<Student*> students, std::list<std::string> taskList, std::queue<report>& reportStack);
	void checkWorks(std::queue<report> reportStack, std::map <std::string, int>& reportExam);
};
