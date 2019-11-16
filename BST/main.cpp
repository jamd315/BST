#include <iostream>
#include "main.h"


template<class T>
Node<T>::Node(T* keyParam, Node<T>* parentParam)
{
	key = keyParam;
	height = 0;
	left = nullptr;
	right = nullptr;
	parent = parentParam;
}


template<class T>
void Node<T>::insert(T* objRef)
{
	if (*objRef <= *key)  // Position to left
	{
		if (left == nullptr)
		{
			left = new Node<T> (objRef, this);
			incrementHeight();
		}
		else
		{
			left->insert(objRef);
		}
	}
	else  // Position to right
	{
		if (right == nullptr)
		{
			right = new Node<T> (objRef, this);
		}
		else
		{
			right->insert(objRef);
		}
	}
}


template<class T>
void Node<T>::incrementHeight()
{
	checkChildHeight();
	height++;
	if (parent != nullptr)
	{
		parent->incrementHeight();
	}
}


template<class T>
void Node<T>::checkChildHeight()
{
	return;
	if (left->height - right->height > 1 || right->height - left->height > 1)
	{
		std::cout << "Node(" << key << ") imbalanced" << std::endl;
	}
	else
	{
		std::cout << "Node(" << key << ") balanced" << std::endl;
	}
}


template<class T>
void Node<T>::disp(int indentLevel)
{
	for (int i = 0; i < indentLevel; i++)
	{
		std::cout << '\t';
	}
	std::cout << "0x" << this << " (" << *key << ", height=" << height << ")" << std::endl;
	if (left != nullptr)
	{
		std::cout << "Left:  ";  // Prefix the next disp
		left->disp(indentLevel + 1);
	}
	if (right != nullptr)
	{
		std::cout << "Right: ";  // Prefix the next disp
		right->disp(indentLevel + 1);
	}
}


int main()
{
	int someInt = 10;
	Node<int> n(&someInt);
	std::cout << "1st int is 10" << std::endl;
	int userInt;
	while (1)
	{
		std::cout << "Enter the next number to insert: ";
		std::cin >> userInt;
		if (userInt == 0)
		{
			break;
		}
		n.insert(new int(userInt));
		n.disp();
	}
	return 0;
}