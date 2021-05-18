#pragma once
#include <map>
#include <string>
#include <iostream>
#include <iterator>

class ResultTable {
public:
	std::map <std::string, int> reportExam;

	void PrintResults();
};