#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "teacher.h"
#include "resulttable.h"
#include "manylists.h"

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
	Students childrens;
	Tasks quadEqs;

	Report reports;
	MarVanna.ExamProcess(childrens.students, quadEqs.taskList, reports.reportStack);


	ResultTable table;
	MarVanna.checkWorks(reports.reportStack, table.reportExam);

	table.PrintResults();

	return 0;
}