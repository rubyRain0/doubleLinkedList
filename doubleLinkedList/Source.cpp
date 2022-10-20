#include "My_List.h"
#include <Windows.h>

void task_1(DLIST& DL)
{
	ptrNODE ptr = DL.get_begin();
	while (ptr)
	{
		if (ptr->info.kind() == 2)
			DL.Delete(ptr);
		else
			ptr = ptr->next;
	}
}

int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream file("students.txt");
	if (file)
	{
		DLIST DL("students.txt");
		DL.print(); task_1(DL);
		std::cout << "List after task: \n\n";
		DL.print();
	}
	std::cin.get();
}