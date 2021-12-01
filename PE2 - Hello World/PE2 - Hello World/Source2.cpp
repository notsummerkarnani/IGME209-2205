#include <iostream>
using namespace std;

//IGME 209 PE2 Hello World
//Samar Karnani

int numSeconds;
double areaCircle;
char dataType[];

void AreaCalc(double radius);

int main()
{
	cout << "Hello World!\n\n";

	numSeconds = 60 * 60 * 24 * 31;
	printf("The answer for 5a is: %i \n\n", numSeconds);

	AreaCalc(6.2);

	int a = 9 / 5;
	cout << a << endl;
	cout << "The answer for 5c is truncate" << endl;
}

void AreaCalc(double radius) {
	areaCircle = 3.14159 * radius * radius;
	printf("The answer for 5b is: %f \n\n", areaCircle);
}