#include "manylists.h"

const int studentLVLchance = 3;

Students::Students() {
	Student* studentCreation;

	for (int studCounter = 0; studCounter < studentsGroup::name.size(); studCounter++)
	{
		auto studentLevel = static_cast<StudentLevel>(rand() % studentLVLchance);

		if (studentLevel == studentBad) {
			studentCreation = new studBad(studentsGroup::name[studCounter]);
			students.push_back(studentCreation);
		}
		else if (studentLevel == studentMedium) {
			studentCreation = new studMedium(studentsGroup::name[studCounter]);
			students.push_back(studentCreation);
		}
		else {
			studentCreation = new studGood(studentsGroup::name[studCounter]);
			students.push_back(studentCreation);
		}
	}
}



Tasks::Tasks() {
	for (int taskCounter = 0; taskCounter < tasklist::equality.size(); taskCounter++)
	{
		taskList.push_back(tasklist::equality[taskCounter]);
	}
}
