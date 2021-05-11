#include "manylists.h"

Students::Students() {
	Student* studentCreation;

	for (int studCounter = 0; studCounter < studentsGroup::name.size(); studCounter++)
	{
		studentCreation = new Student(studentsGroup::name[studCounter]);
		students.push_back(studentCreation);
	}
}



Tasks::Tasks() {
	for (int taskCounter = 0; taskCounter < tasklist::equality.size(); taskCounter++)
	{
		taskList.push_back(tasklist::equality[taskCounter]);
	}
}
