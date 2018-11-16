#include "stdafx.h"
#include "MyLinkedList.h"

class Node 
{
private:
	MusicClip data;
	Node* next;
public:
	//Constructor
	Node(MusicClip m) {
		data = m;
		next = nullptr;
	}
	~Node() {
		delete next;
	}
};

MyLinkedList::MyLinkedList()
{
}


MyLinkedList::~MyLinkedList()
{
}
