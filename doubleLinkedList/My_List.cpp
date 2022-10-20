#include "My_List.h"

ptrNODE find_place(ptrNODE begin, const Student& stud)
{
	ptrNODE p = begin;
	while (p && p->info.compare(stud) < 0)
		p = p->next;
	return p;
}

DLIST::DLIST(const char* file_name)
{	
	std::ifstream file(file_name);
	Student stud(file);
	first_node(stud);
	ptrNODE place;
	while (!file.eof())
	{
		Student stud(file);
		place = find_place(begin, stud);
		if (place)
			add_before(place, stud);
		else
			add_after(end, stud);
	}
	file.close();
}

void DLIST::first_node(const Student& stud)
{
	begin = new NODE(stud);
	end = begin;
}

bool DLIST::empty()
{
	return begin == nullptr;
}

void DLIST::add_after(ptrNODE ptr, const Student& stud)
{
	ptrNODE p = new NODE(stud, ptr->next, ptr);
	if (ptr == end)
		end = p;
	else
		ptr->next->prev = p;
	ptr->next = p;
}

void DLIST::add_before(ptrNODE ptr, const Student& stud)
{
	ptrNODE p = new NODE(stud, ptr, ptr->prev);
	if (ptr == begin)
		begin = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::print()
{
	ptrNODE ptr = begin;
	while (ptr)
	{
		ptr->info.print();
		ptr = ptr->next;
	}
}

Student& DLIST::Delete(ptrNODE& ptr)
{
	ptrNODE p = ptr;
	if (ptr == begin) // удаление из начала
	{
		begin = p->next;
		ptr = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
		if (ptr == end) //удаление из конца
		{
			end = p->prev;
			ptr = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else // удаление из середины
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	static Student stud;
	stud = p->info;
	delete p;
	return stud;
}

DLIST::~DLIST()
{
	while (!empty())
		Delete(begin);
}