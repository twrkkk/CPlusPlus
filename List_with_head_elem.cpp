
#include "../../../../Downloads/List c++ with head elem/My_List.h"
#include <functional>
//1
ptrNODE move_head(ptrNODE head, int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		if(head->next)
			head = head->next;
	}
	return head;
}
//4
bool is_the_same_lists(LIST list1, LIST list2)
{
	list1.sorting();
	list2.sorting();
	bool flag = false;
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
//2
bool is_true(ptrNODE head, std::function<bool(ptrNODE, ptrNODE)> cmp)
{;
	bool result = false;
	while (head->next && head->next->next && !result)
	{
		if (cmp(head->next, head->next->next))
		{
			head = head->next;
		}
		else
			result = true;
	}
	return !result;
}
//3
ptrNODE find_prev_elem(ptrNODE head, int elem)
{
	ptrNODE prev_pos = nullptr;
	ptrNODE curr_pos = head->next;
	bool flag = false;
	while (head->next && !flag)
	{
		if (head->next->info == elem)
		{
			prev_pos = curr_pos;
			curr_pos = head->next;
			flag = true;
		}
		head = head->next;
	}
	return prev_pos;
}
//3
void task_3(LIST& list, int e, int e1)
{
	bool flag = false;
	ptrNODE head = list.get_head();
	while (head->next)
	{
		if (head->next->info == e)
		{
			list.add_after(head, e1);
			head = head->next;
		}
		head = head->next;
	}
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
		std::ifstream file2("data2.txt");
		list2.create_by_stack(file2);
		list2.print();


		file.close();

		//1
		/*ptrNODE head = list.get_head();
		if (list.get_size() > 1)
		{
			ptrNODE new_head = move_head(head, list.get_size());
			std::cout << new_head->info + new_head->next->info << '\n';
		}
		else
			std::cout << "Not enough elements" << '\n';*/

		//4
		/*std::cout << is_the_same_lists(list, list2) << '\n';*/

		//2
		/*auto less = [](ptrNODE elem1, ptrNODE elem2) {return elem1->info < elem2->info; };
		std::cout << is_true(list.get_head(), less);*/

		//3
		/*ptrNODE pos = find_prev_elem(list.get_head(), 2);
		if (pos != nullptr)
		{
			list.add_after(pos, 5);
			list.print();
		}
		or

		task_3(list, 2, 5);
		list.print();*/


	}
	std::cin.get();
}

