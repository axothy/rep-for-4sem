#pragma once
#include "student.h"
#include <list>
#include <array>

namespace studentsGroup
{
	std::array<std::string, 18> name = {
	"Dima", "Misha", "Sasha",
	"Vanya", "Mihail", "Anya",
	"Rushan", "Olya", "Katya",
	"Alexander", "Artyom", "Raul",
	"Vlada", "Anton", "Fedya",
	"Alexey", "Lyoha", "Danil"
	};
}

namespace tasklist
{
	std::array<std::string, 5> equality = {
		"-1*x^2-10.42*x-4.19=0",
		"-2*x^2-9.4*x-4.51=0",
		"-3*x^2-9.6*x-4.91=0",
		"-4.3*x^2-9.1*x-4.22=0",
		"-5*x^2-9*x-4.33=0"
	};
}


class Students {
public:
	Students();
	std::vector<Student*> students;
};

class Tasks {
public:
	Tasks();
	std::list<std::string> taskList;
};

class Report {
public:
	std::queue<report> reportStack;
};