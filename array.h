#ifndef ARRAY_H
#define ARRAY_H
class Array
{
	protected:
		int *arr;
		int size;
		int capacity;
	public:
		Array();
		Array(int capacity);
		Array(const Array &op);
		~Array();
		int getCapacity(void);
		void printArray(void);
		int getSize(void);
		void pushBack(int n);
		void popBack();
		int& sert(int m);
};		


#endif
