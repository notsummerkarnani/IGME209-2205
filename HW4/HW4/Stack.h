#pragma once
#include <iostream>

using namespace std;

template <class Placeholder>
class Stack
{
private:
	Placeholder* stack;
	int size;


public:
	Stack();
	//Copy Constructor for Stack
	Stack(const Stack &_otherStack);
	//Copy Assignment constructor
	Stack<Placeholder>& operator=(const Stack<Placeholder>& other);
	//Destructor for stack
	~Stack();

	//Adds an item to the top of the stack and resizes it if needed
	void Push(Placeholder _item);
	//Removes an item from the top of the stack
	Placeholder Pop();
	//Prints all the elements on the stack
	void Print();
	//gets the number of items on the stack
	int GetSize();
	//Checks if the stack is empty or not
	bool IsEmpty();
};

//Default constructor
template<class Placeholder>
inline Stack<Placeholder>::Stack(){
	stack = new Placeholder[4];
	size = 0;
	stack[3] = 0;
}

//Copy constructor
template<class Placeholder>
inline Stack<Placeholder>::Stack(const Stack &_otherStack) {
	size = _otherStack.size;
	stack = new Placeholder[size];
	for (int i = 0; i < size; i++) {
		stack[i] = _otherStack.stack[i];
	}
}

//copy assignment constructor
template<class Placeholder>
inline Stack<Placeholder>& Stack<Placeholder>::operator=(const Stack<Placeholder>& other){
	if (this == &other) {
		return *this;
	}

	if (stack != nullptr) {
		delete stack;
		stack = nullptr;
		size = 0;
	}

	size = other.size;
	stack = new Placeholder[size];
	for (int i = 0; i < size; i++) {
		stack[i] = other[i];
	}

	return *this;
}

//Destructor
template<class Placeholder>
inline Stack<Placeholder>::~Stack(){
	delete stack;
	stack = nullptr;
}

//Adds an item to the stack
template<class Placeholder>
inline void Stack<Placeholder>::Push(Placeholder _item){
	if (stack[size] == 0) {
		Placeholder* oldstack = stack;
		stack = new Placeholder[(size+1) * 2];	//creates new [] double the original size
		stack[((size + 1) * 2) - 1] = 0;
		for (int i = 0; i < size; i++) {
			stack[i] = oldstack[i];
		}
		delete oldstack;
	}
	stack[size] = _item;
	size++;
	
}

//Removes item from the top of the stack
template<class Placeholder>
inline Placeholder Stack<Placeholder>::Pop(){
	if (size > 0) {
		Placeholder item = stack[size - 1];
		stack[size - 1] = 0;
		size--;
		return item;
	}
	return 0;
}

//Prints all items on stack
template<class Placeholder>
inline void Stack<Placeholder>::Print(){
	for (int i = 0; i < size; i++) {
		cout << stack[size - i -1] << endl;
	}
}

//returns the number of elements in the stack
template<class Placeholder>
inline int Stack<Placeholder>::GetSize(){
	return size;
}

//Returns true if the stack is empty
template<class Placeholder>
inline bool Stack<Placeholder>::IsEmpty(){
	if (size == 0) {
		return true;
	}
	return false;
}
