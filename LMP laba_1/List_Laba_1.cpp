#include "My_List.h"

using std::cin;
using std::cout;

//size_t get_first_digit(int number)
//{
//	size_t result = 0;
//	while (number)
//	{
//		result = number % 10;
//		number /= 10;
//	}
//	return result;
//}

bool task(LIST& list)
{
	auto get_first_digit = [](int number)
	{
		size_t result = 0;
		while (number)
		{
			result = number % 10;
			number /= 10;
		}
		return result;
	};

	//bool result = false;
	//ptrNODE beg = list.get_head()->next, p = beg;// , end = nullptr;
	//size_t digit_1 = get_first_digit(beg->info), digit_2 = -1;
	//while (digit_1 != digit_2 && !result)
	//{
	//	while (p->next && !result)
	//	{
	//		p = p->next;
	//		digit_2 = get_first_digit(p->info);
	//		if (digit_1 == digit_2)
	//		{
	//			//end = p;
	//			result = true;
	//		}
	//	}
	//	if (!result)
	//	{
	//		beg = beg->next;
	//		p = beg->next;
	//		//end = p;
	//		digit_1 = get_first_digit(beg->info);
	//		digit_2 = get_first_digit(p->info);
	//	}
	//	
	//}

	bool result = false;
	ptrNODE beg = list.get_head(), p = beg->next;// , end = nullptr;
	size_t digit_1 = get_first_digit(beg->next->info), digit_2 = -1;
	while (digit_1 != digit_2 && !result)
	{
		while (p->next && !result)
		{
			digit_2 = get_first_digit(p->next->info);
			if (digit_1 == digit_2)
			{
				//end = p;
				result = true;
			}
			else
				p = p->next;

		}
		if (!result)
		{
			beg = beg->next;
			p = beg->next;
			//end = p;
			digit_1 = get_first_digit(beg->next->info);
			digit_2 = get_first_digit(p->next->info);
		}

	}

	cout << beg->info << ' ' << p->info<<'\n';

	auto switch_pointers =
		[&](ptrNODE q, ptrNODE p)
	{
		/*ptrNODE tmp = p->next;
		p->next = tmp->next;
		tmp->next = q->next;
		q->next = tmp;
		p = q;*/
		/*ptrNODE tail = list.get_tail();
		if (p != tail)
		{
			ptrNODE tmp = beg->next;
			beg->next = p->next;
			p->next = tail->next;
			tail->next = tmp;
			list.set_tail(p);
		}*/
		/*ptrNODE tmp = q->next;
		q->next = p->next;
		p->next = tmp;*/
		/*ptrNODE tmp1 = q->next;
		ptrNODE tmp2 = p->next;
		q->next = p->next;
		p->next = tmp;*/
		ptrNODE tmp = p->next;
		p->next = q->next;
		q->next->next = tmp;
	};

	switch_pointers(beg, p);
	
	return result;
}

void main()
{
	LIST list;
	std::ifstream file("data.txt");
	if (file)
	{
		list.create_by_queue(file);
		list.print();
		cout << '\n';
		/*std::cout << list.get_size() << "\n";
		list.del_after(list.get_head()->next->next);*/
		//list.sorting();
		//list.print();

		task(list);
		list.print();


		file.close();
	}
	std::cin.get();
}

