#include <iostream>
using namespace std;

void changeVariable(int);
void changePointer(int*);
int getLengthArray(int[64]);
int getLengthPointer(int*);
int* createStackArray();
int* createHeapArray(int);

//IGME 209 DSA1 PE8
//Samar Karnani

int main()
{
	//Part 1
	int variable = 69;
	cout << "Variable value: " << variable << endl;
	changeVariable(variable);
	cout << "Variable value: " << variable << endl;
	changePointer(&variable);
	cout << "Variable value: " << variable << endl;

	//when changevariable() is called the varible passed is of value type
	//Therefore a copy of the variable is made and passed in
	//Since it is a copy and not the original, any change made will not affect the original variable 

	//When changePointer() is called a reference to the variable is passed in
	//The code then finds the variable stored at the address and changes it 
	//Therefore the value of variable in main will change every time changePointer is called


	//Part 2
	int intArray[64] = { 1,2,3,4,5,6,7,8,9,-1};
	int* intArrayPtr = intArray;
	cout << "\n\nNumber of elements before the terminator in getLengthArray(): " << getLengthArray(intArrayPtr) << endl;
	cout << "Number of elements before the terminator in getLengthPointer(): " << getLengthPointer(intArray) << endl;


	//Part 3
	int* intStackPtr = createStackArray();
	for (int i = 0; i < 5; i++) {
		cout << intStackPtr[i] << ", ";
	}
	cout << endl;
	//This prints out a bunch of arbitrary numbers because the stack array only exists within the scope of the function in which it is initialised

	int heapArraySize = 5;
	int* intHeapPtr = createHeapArray(heapArraySize);
	for (int i = 0; i < heapArraySize; i++) {
		cout << intHeapPtr[i] << ", ";
	}
	cout << endl;

	delete[] intHeapPtr;
	intHeapPtr = nullptr;
}

void changeVariable(int variable) {
	variable++;
	cout << "Inside changeVariable() -- Variable's value is now: " << variable << endl;
}

void changePointer(int* variablePtr) {
	(*variablePtr)++;
	cout << "Inside changePointer() -- Variable's value is now: " << *variablePtr << endl;
}

int getLengthArray(int intArray[64]) {
	int length = 0;
	while (intArray[length] != -1) {
		length++;
	}
	return length;
}

int getLengthPointer(int* intArray) {
	int length = 0;
	while (*(intArray + length) != -1) {
		length++;
	}
	return length;
}

int* createStackArray() {
	int intArray[5] = { 0,1,2,3,4 };
	return intArray;
}

int* createHeapArray(int arrayLength) {
	int* intArray = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		intArray[i] = i;
	}
	return intArray;
}


