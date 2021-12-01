#pragma once

template <class Placeholder>
class SmartPointer
{
public:
	SmartPointer(Placeholder* _ptr = NULL) {
		ptr = _ptr;
	};

	~SmartPointer() {
		delete ptr;
		ptr = nullptr;
	};

	Placeholder& operator *(){
		return *ptr;
	};

	Placeholder* operator ->(){
		return ptr;
	};

private:
	Placeholder* ptr;
};

