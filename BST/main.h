#pragma once


template <class T>
class Node
{
public:
	T* key;
	unsigned short height;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	Node(T* keyParam, Node<T>* parentParam);
	Node(T* keyParam) : Node(keyParam, nullptr) {}
	void insert(T* obj);
	void incrementHeight();
	void checkChildHeight();
	void disp(int indentLevel);
	void disp() { disp(0); }  // Is there a better way to do this?  TODO
};