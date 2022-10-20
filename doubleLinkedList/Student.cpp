#include "Student.h"

Student::Student(std::ifstream& file)
{
	std::getline(file, FIO);
	file >> course >> group;
	for (size_t i = 0; i < 5; i++)
		file >> marks[i];
	file.ignore();
	std::string splitLine;
	std::getline(file, splitLine);
}

void Student::print()
{
	std::cout << FIO << '\n';
	std::cout << course << '\n' << group << '\n';
	for (size_t i = 0; i < 5; i++)
		std::cout << marks[i] << ' ';
	std::cout << '\n';
	std::cout << "--------------\n";
}

int Student::compare(const Student& stud)
{
	int result = 1;
	if (course < stud.course ||
		course == stud.course && group < stud.group ||
		course == stud.course && group == stud.group && FIO < stud.FIO)
		result = -1;
	else
		if (course == stud.course && group == stud.group && FIO == stud.FIO)
			result = 0;
	return result;
}
int Student::kind()
{
	int result = marks[0];
	for (size_t i = 1; i < 5; i++)
	{
		if (marks[i] < result)
			result = marks[i];
	}
	return result;
}