#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"

using TInfo = Student;

struct NODE
{
	TInfo info; 
	NODE* next, *prev;
	NODE(TInfo info, NODE* next = nullptr, NODE* prev = nullptr) :info(info), next(next), prev(prev) {}
	~NODE() 
	{
		next = nullptr;
		prev = nullptr;
	}
};

using  ptrNODE = NODE*;

struct DLIST
{
private:
	ptrNODE begin, end;
public:
	DLIST()
	{
		begin = nullptr;
		end = nullptr;
	}
	DLIST(const char* file_name);
	void first_node(const Student& stud);
	bool empty();
	void add_before(ptrNODE ptr, const Student& stud);
	void add_after(ptrNODE ptr, const Student& stud);
	void print();
	Student& Delete(ptrNODE& ptr);
	ptrNODE get_begin()
	{
		return begin;
	}
	~DLIST();
};