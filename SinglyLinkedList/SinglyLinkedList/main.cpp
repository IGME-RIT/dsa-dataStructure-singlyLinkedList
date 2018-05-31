/*
 *C++ program to implement singly link list
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Node declaration
struct node
{
	int info;
	struct node* next;
}*start;

//Class declaration
class single_llist
{
public:
	node * create_node(int);
	void insert_begin();
	void insert_pos();
	void insert_last();
	void delete_pos();
	void sort();
	void search();
	void update();
	void reverse();
	void display();
	single_llist()
	{
		start = NULL;
	}
};

void main()
{
	int choice, nodes, element, position, i;
	single_llist s1;
	start = NULL;

	while (1)
	{
		cout << endl << "--------------------------------" << endl;
		cout << endl << "Operations on singly linked list" << endl;
		cout << endl << "--------------------------------" << endl;
		cout << "1. Insert node at beginning" << endl;
		cout << "2. Insert node at last" << endl;
		cout << "3. Insert node at position" << endl;
		cout << "4. Sort linked list" << endl;
		cout << "5. Delete a particular node" << endl;
		cout << "6. Update node value" << endl;
		cout << "7. Search element" << endl;
		cout << "8. Display linked list" << endl;
		cout << "9. Reverse linked list" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter your choice : ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Inserting node at beginning: " << endl;
			s1.insert_begin();
			cout << endl;
			break;

		case 2:
			cout << "Inserting node at last: " << endl;
			s1.insert_last();
			cout << endl;
			break;

		case 3:
			cout << "Inserting node at given position: " << endl;
			s1.insert_pos();
			cout << endl;
			break;

		case 4:
			cout << "Sort linked list: " << endl;
			s1.sort();
			cout << endl;
			break;

		case 5:
			cout << "Delete a particular node: " << endl;
			s1.delete_pos();
			cout << endl;
			break;

		case 6:
			cout << "Update node value: " << endl;
			s1.update();
			cout << endl;
			break;

		case 7:
			cout << "Search element in link list: " << endl;
			s1.search();
			cout << endl;
			break;

		case 8:
			cout << "Display elements of linked list: " << endl;
			s1.display();
			cout << endl;
			break;

		case 9:
			cout << "Reverse elements of linked list: " << endl;
			s1.reverse();
			cout << endl;
			break;

		case 10:
			cout << "Exiting......" << endl;
			exit(1);
			break;

		default:
			cout << "Wrong choice!" << endl;
		}
	}
}

//Creating a node
node* single_llist::create_node(int value)
{
	struct node *temp, *s;
	temp = new (struct node);

	if (temp != NULL)
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
	else
	{
		cout << "Memory not allocated" << endl;
		return 0;
	}
}

//Inserting node at the beginning of the list
void single_llist::insert_begin()
{
	int value;
	cout << "Enter value to be inserted: ";
	cin >> value;
	struct node *temp, *p;
	
	temp = create_node(value);

	if (start == NULL)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}

	cout << "Element inserted at the beginning" << endl;
}

//Inserting node at the end of the list
void single_llist::insert_last()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node *temp, *s;
	
	temp = create_node(value);
	s = start;

	while (s->next != NULL)
	{
		s = s->next;
	}

	temp->next = NULL;
	s->next = temp;

	cout << "Node inserted at last" << endl;
}

//Inserting a node at given position
void single_llist::insert_pos()
{
	int value, pos, counter = 0;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node *temp, *s, *ptr;

	ptr = NULL;

	temp = create_node(value);

	cout << "Enter the position at which the node is to be inserted: ";
	cin >> pos;

	int i;
	s = start;

	while (s != NULL)
	{
		s = s->next;
		counter++;
	}

	if (pos == 1)
	{
		if (start == NULL)
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter)
	{
		s = start;
		for (i = 1; i < pos; i++)
		{
			ptr = s;
			s = s->next;
		}

		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout << "Position provided is out of range!" << endl;
	}
}

//Sorting the linked list
void single_llist::sort()
{
	struct node *ptr, *s;
	int value;

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	ptr = start;

	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)
		{
			if (ptr->info > s->info)
			{
				value = ptr->info;
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr = ptr->next;
	}
}

//Deleting a node at given position
void single_llist::delete_pos()
{
	int pos, i, counter = 0;

	if (start == NULL);
	{
		cout << "The list is empty" << endl;
		return;
	}

	cout << "Enter the position of the value to be deleted: ";
	cin >> pos;
	struct node *s, *ptr;

	s = start;

	if (pos == 1)
	{
		s = s->next;
	}
	else
	{
		while (s != NULL)
		{
			s = s->next;
			counter++;
		}
		if (pos > 0 && pos <= counter)
		{
			s = start;
			for (i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}

			ptr->next = s->next;
		}
		else
		{
			cout << "Position out of range!" << endl;
		}

		free(s);
		cout << "Element deleted!" << endl;
	}
}

//Update a given node
void single_llist::update()
{
	int value, pos, i;

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	cout << "Enter the position of the node to be updated: ";
	cin >> pos;
	cout << "Enter the new value: ";
	cin >> value;
	struct node *s, *ptr;

	s = start;

	if (pos == 1)
	{
		start->info = value;
	}
	else
	{
		for (i = 0; i < pos - 1; i++)
		{
			if (s == NULL)
			{
				cout << "There are less than " << pos << " elements";
				return;
			}
			s = s->next;
		}

		s->info = value;
	}

	cout << "Node updated" << endl;
}

//Search for an element in the list
void single_llist::search()
{
	int value, pos = 0;
	bool found = false;

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	cout << "Enter the value to be searched: ";
	cin >> value;
	struct node* s;

	s = start;

	while (s != NULL)
	{
		pos++;

		if (s->info == value)
		{
			found = true;
			cout << "Element " << value << " is found at position " << pos << endl;
		}

		s = s->next;
	}

	if (!found)
	{
		cout << "Element with value: " << value << " not found in the list" << endl;
	}
}

//Reversing a linked list
void single_llist::reverse()
{
	struct node *ptr1, *ptr2, *ptr3;

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	if (start->next == NULL)
	{
		return;
	}

	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;

	ptr1->next = NULL;
	ptr2->next = ptr1;

	while (ptr3 != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}

	start = ptr2;
}

//Display the linked list
void single_llist::display()
{
	struct node* temp;

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	temp = start;
	cout << "Elements of list are: " << endl;

	while (temp != NULL)
	{
		cout << temp->info << "->";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}