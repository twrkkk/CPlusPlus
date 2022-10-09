
#include <iostream>
#include "my_list.h"
#include <fstream>

struct Node
{
	Node* next_elem;
	int info;

	Node(int new_info, Node* ptr = nullptr) : info(new_info), next_elem(ptr) {};

};

class List
{
	Node* head, tail;
	size_t size;
	List()
	{
		head = new Node(0);
		tail = head;
		size = 0;
	}
	void add_by_pointer(Node& ptr, int info)
	{
		Node* new_node = new Node(info, ptr);
		ptr = new_node;
	}

	void del_by_pointer(Node& ptr)
	{
		Node* p = ptr;
		ptr = p->next_elem;
		delete p;
	}
	void add_to_head(int info)
	{
		add_by_pointer(head.next_elem, info);
		if (head == tail)
			tail = tail.next_elem;
		++size;
	}
	void create_by_stack(std::ifstream& file)
	{
		int elem;
		while (file >> elem)
			add_to_head(elem);
	}
	void print()
	{
		Node* node = head->next_elem;
		while (node)
		{
			std::cout << node->info << ' ' << '\n';
			node = node->next_elem;
		}
		std::cout << '\n';

	}
};

int main()
{
	List list;
	std::ifstream file("data.txt");
	if (file)
	{
		list.create_by_stack(file);
		list.print();
	}
}