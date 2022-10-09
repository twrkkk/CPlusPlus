#include <iostream>
#include <fstream>

using TInfo = int;

struct NODE
{
	TInfo info;
	NODE* next;
	NODE(TInfo info, NODE* next = nullptr) :info(info), next(next) {}
	~NODE()
	{
		next = nullptr; // 0
	}
};

using ptrNODE = NODE*;

struct LIST
{
private:
	ptrNODE head, tail;
	size_t size;
	void Addiing_by_pointer(ptrNODE& ptr, TInfo elem)
	{
		ptrNODE p = new NODE(elem, ptr);
		ptr = p;
		size++;
	}
	void Deleting_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		delete p;
		size--;
	}
public:
	LIST()
	{
		head = tail = nullptr;
		size = 0;
	}
	~LIST();
	ptrNODE get_head()
	{
		return head;
	}
	void set_head(ptrNODE ptr)
	{
		head = ptr;
	}
	TInfo get_first()
	{
		return head->info;
	}
	size_t get_size()
	{
		return size;
	}
	bool Empty();
	void Add_to_head(TInfo elem);
	void Add_to_tail(TInfo elem);
	void Add_after(ptrNODE ptr, TInfo elem);
	void Delete_from_head();
	void Delete_after(ptrNODE ptr);
	void Print();
	void Create_by_stack(std::ifstream& file);
	void Create_by_queue(std::ifstream& file);
	void Create_by_order(std::ifstream& file);
};

bool delete_all_even(LIST& list)
{
	bool result = false;
	while (!list.Empty() && list.get_first() % 2 == 0)
	{
		result = true;
		list.Delete_from_head();
	}
	if (!list.Empty())
	{
		ptrNODE ptr = list.get_head();
		while (ptr->next)
			if (ptr->next->info % 2 == 0)
			{
				list.Delete_after(ptr);
				result = true;
			}
			else
				ptr = ptr->next;
	}
	return result;
}

int main()
{
	LIST list;
	std::ifstream file("numbers.txt");
	if (!file)
		std::cerr << "File not found!\n";
	else
	{
		//list.Create_by_stack(file);
		//list.Create_by_queue(file);
		list.Create_by_order(file);
		list.Print();
		std::cout << list.get_size() << '\n';
		if (delete_all_even(list))
			list.Print();
		else
			std::cout << "No even elements\n";
		std::cout << list.get_size() << '\n';
	}
	std::cin.get();
	return 0;
}

LIST::~LIST()
{
	while (!Empty())
		Delete_from_head();
}

bool LIST::Empty()
{
	return head == nullptr;
}

void LIST::Add_to_head(TInfo elem)
{
	//ptrNODE p = new NODE(elem, head);
	//head = p;
	//size++;
	Addiing_by_pointer(head, elem);
	if (!tail)// if (!head->next)
		tail = head;
}

void LIST::Add_to_tail(TInfo elem)
{
	if (!head) // if (Empty())
		Add_to_head(elem);
	else
	{
		//ptrNODE p = new NODE(elem, tail->next);
		//tail->next = p;
		//size++;
		Addiing_by_pointer(tail->next, elem);
		tail = tail->next;
	}
}

void LIST::Add_after(ptrNODE ptr, TInfo elem)
{
	if (ptr)
	{
		//ptrNODE p = new NODE(elem, ptr->next);
		//ptr->next = p;
		//size++;
		Addiing_by_pointer(ptr->next, elem);
		if (ptr == tail)
			tail = tail->next;
	}
}

void LIST::Delete_from_head()
{
	if (head)
	{
		/*ptrNODE p = head;
		head = head->next;
		delete p;
		size--;*/
		Deleting_by_pointer(head);
		if (Empty()) // if (size==0) if(!head)
			tail = nullptr;
	}
}

void LIST::Delete_after(ptrNODE ptr)
{
	if (ptr && ptr->next)
	{
		if (ptr->next == tail)
			tail = ptr;
		Deleting_by_pointer(ptr->next);
		//ptrNODE p = ptr->next;
		//ptr->next = p->next; // ptr->next=ptr->next->next;
		//delete p;
		//size--;
	}
}



void LIST::Print()
{
	ptrNODE ptr = head;
	while (ptr)
	{
		std::cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	std::cout << '\n';
}

void LIST::Create_by_stack(std::ifstream& file)
{
	TInfo elem;
	while (file >> elem)
		Add_to_head(elem);
}

void LIST::Create_by_queue(std::ifstream& file)
{
	TInfo elem;
	while (file >> elem)
		Add_to_tail(elem);
}

void LIST::Create_by_order(std::ifstream& file)
{
	TInfo elem;
	auto find_place = [this](TInfo elem)->ptrNODE
	{
		ptrNODE result = head;
		while (result->next && result->next->info < elem)
			result = result->next;
		return result;
	};
	while (file >> elem)
	{
		if (Empty() || head->info >= elem)
			Add_to_head(elem);
		else
		{
			ptrNODE ptr = find_place(elem);
			Add_after(ptr, elem);
		}
	}
}
