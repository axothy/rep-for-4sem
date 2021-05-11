#pragma once
#include "student.h"
#include "teacher.h"
#include "resulttable.h"
#include "manylists.h"
#include <map>
#include <string>
#include <iostream>
#include <iterator>

class ResultTable {
public:
	std::map <std::string, int> reportExam;

	void PrintResults();
};