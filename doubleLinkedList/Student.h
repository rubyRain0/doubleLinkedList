#pragma once
#include <iostream>
#include <string>
#include <fstream>

using TMarks = int[5];

struct Student
{
private:
	std::string FIO;
	int course, group;
	TMarks marks;
public:
	Student() {};
	Student(std::ifstream& file);
	void print();
	int compare(const Student& stud);
	int kind();
};