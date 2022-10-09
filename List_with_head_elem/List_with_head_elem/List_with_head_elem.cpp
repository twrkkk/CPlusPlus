
#include "../../../../Downloads/List c++ with head elem/My_List.h"

ptrNODE move_head(ptrNODE head, int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		head = head->next;
	}
	return head;
}

bool is_the_same_lists(LIST list1, LIST list2)
{
	bool flag = false;
	list1.sorting();
	list2.sorting();
	if (list1.get_size() == list2.get_size())
	{
		int size = list1.get_size();
		int i = 0;
		ptrNODE head1 = list1.get_head();
		ptrNODE head2 = list2.get_head();
		while (!flag && i < size)
		{
			if (head1->next->info != head2->next->info)
				flag = true;
			head1 = head1->next;
			head2 = head2->next;
			++i;
		}
	}
	return !flag;
}

void main()
{
	LIST list;
	LIST list2;
	std::ifstream file("data.txt");
	if (file)
	{
		list.create_by_queue(file);
		list.print();
		file.clear();
		file.seekg(0);
		list2.create_by_stack(file);
		list2.print();
		/*std::cout << list.get_size() << "\n";
		list.del_after(list.get_head()->next->next);
		list.sorting();
		list.print();*/
		//list.print2(list.get_head()->next->next);
		file.close();

		ptrNODE head = list.get_head();
		ptrNODE new_head = move_head(head, list.get_size());
		std::cout << new_head->info + new_head->next->info << '\n';
		std::cout << is_the_same_lists(list, list2) << '\n';
	}
	std::cin.get();
}

