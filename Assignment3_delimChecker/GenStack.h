#include <iostream>
#include <iomanip>

using namespace std;

template <class S>
class GenStack
{
private:
	/*pointer to our structure cointaining our sequence*/
	int _size;
	int _top;
	S *stackPtr;

public:
	GenStack(const int);
	~GenStack()
	{
		delete stackPtr;
	}
	S top()	;
	int  size();
	bool push(const S &);
	bool pop(S &);	
	bool empty();

};
template<typename S>
GenStack<S>::GenStack(int size)
{
	(size>0)? 
		this->_size = size : this->_size = 5 ;
	
	this->_top = -1;
	stackPtr = new S[this->_size];
}
template<typename S>
bool GenStack<S>::push(const S &push)
{

	if(this->_top < this->_size - 1)
	{
		stackPtr[++_top] = push;
		return true;
	}
	else
	{
		cout<<"NULL OPERATION PUSH!\n";
		return false;
	}
}
template<typename S>
bool GenStack<S>::pop(S &pop)
{
	if(_top > 0)
	{
		pop = stackPtr[_top--];
		return true;
	}
	else
	{
		cout<<"NULL OPERATION POP!\n ";
		return false;
	}

}
template<typename S>
S GenStack<S>::top()
{
	if(this->_top <= this->_size - 1 && !empty())
		return stackPtr[_top];
	else
	{
		cout<<"The top is empty!\n";
		return -1;
	}
}
template<typename S>
bool GenStack<S>::empty()
{
	if(_top < 0 )
		return true;
	else
		return false;
}
template<typename S>
int GenStack<S>::size()
{
	return this->_size;
}

