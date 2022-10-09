#include "My_List.h"

void main()
{
	LIST list;
	std::ifstream file("data.txt");
	if (file)
	{
		//list.create_by_queue(file);
		list.create_by_order(file);
		list.print();
		std::cout << list.get_size() << "\n";
		list.del_after(list.get_head()->next->next);
		list.sorting();
		list.print();
		file.close();
	}
	std::cin.get();
}

