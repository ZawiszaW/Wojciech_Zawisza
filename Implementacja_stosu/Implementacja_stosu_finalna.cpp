#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>


struct stack_element
{

	stack_element* next;
	stack_element* previous;
	int value;

};


class stack_List
{

private:
	stack_element* List;

public:
	stack_List();

	bool empty();

	stack_element* top();

	void Print();

	void pop_front();

	void push_front(int value);

	~stack_List();
};


int main(int argc, char* argv[])
{
	stack_List Object = {};
	Object.push_front(20);
	Object.push_front(21);
	Object.push_front(22);
	Object.push_front(23);
	Object.push_front(24);

	Object.Print();
	Object.pop_front();
	Object.Print();
	Object.pop_front();
	Object.Print();
	Object.pop_front();
	Object.Print();
	Object.pop_front();
	Object.Print();
	Object.pop_front();
	Object.Print();

	return EXIT_SUCCESS;
}


stack_List::stack_List()
{

}

bool stack_List::empty()
{
	return !List;
}

stack_element* stack_List::top()
{
	return List;
}

void stack_List::Print()
{
	if (List == NULL)
	{
		printf("List is empty");
	}
	else
	{
		stack_element* current = List;
		do
		{
			printf("%i", current->value);

			printf("\n");

			current = current->next;

		} while (current != NULL);

		printf("\n");

	}
}

void stack_List::pop_front()
{
	if (List != NULL)
	{
		if (List->next == NULL)
		{
			List = NULL;
		}
		else
		{
			stack_element* temp;
			temp = List->next;
			free(List);
			List = temp;
			List->previous = NULL;
		}
	}
}

void stack_List::push_front(int value)
{
	if (List == NULL)
	{
		List = (stack_element*)malloc(sizeof(stack_element));
		List->value = value;
		List->previous = NULL;
		List->next = NULL;
	}
	else
	{
		stack_element* current;
		current = (stack_element*)malloc(sizeof(stack_element));
		current->value = value;
		current->previous = NULL;
		current->next = List;
		List->previous = current;
		List = current;
	}
}


stack_List::~stack_List()
{
	while (List)
	{
		pop_front();
	}
}