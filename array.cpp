#include "array.h"
#include <string.h>
#include <iostream>
using namespace std;
/*int *arr;
 int size;
 int capacity;*/

Array::Array()
{
	capacity=5;
	size=0;
	arr=new int[capacity];
	memset(arr,0,sizeof(int)*capacity);
}

Array::Array(int capacity)
{
	this->capacity=capacity;
	size=0;
	arr=new int[capacity];
	memset(arr,0,sizeof(int)*capacity);
}

Array::Array(const Array& op)
{
	capacity=op.capacity;
	size=op.size;
	arr=new int[capacity];
	memcpy(arr,op.arr,sizeof(int)*capacity);
}

Array::~Array()
{
	if(arr != NULL)
	{ 
	  delete [] arr;
	  arr=NULL;
	}
}

int Array::getSize(void)
{
	return(size);
}

int Array::getCapacity(void)
{
	return(capacity);
}

void Array::pushBack(int n)
{
	if(size==capacity)
	{
		int *ptr=new int[2*capacity];
		memset(ptr,0,sizeof(int)*2*capacity);
		memcpy(ptr,arr,sizeof(int)*size);
		delete [] arr;
		arr=ptr;
		capacity=2*capacity;
	}
	else
	    arr[size]=n;
	    size++;
}

void Array::popBack()
{
	if(size==0)
	cout<<"容器为空"<<endl;
	else
	size--; 
}

int& Array::sert(int m)
{
	if(size>m||m>capacity)
	{
	cout<<"访问位置无效"<<endl;
	exit(-1);
	}
	return(arr[m]);
}

void Array::printArray(void)
{
	while(size==0)
	{
		cout<<arr<<" ";
		arr++;
	}
	cout<<endl;
}




