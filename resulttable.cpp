#include "resulttable.h"

void ResultTable::PrintResults() {
	std::map <std::string, int> ::iterator it = reportExam.begin();
	for (; it != reportExam.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}