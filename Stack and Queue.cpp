#include<iostream>

using namespace std;

/*
template <class T>
class Stack
{
private:

	T* data; 
	int top; 
	const int max_size; 

public:
	
	Stack(const int max_size = 5):max_size(max_size)
	{
		
		top = -1;
		data = new T[max_size];

	}
	
	~Stack()
	{
		delete[]data;
	}
	
	void push(const T newItem)
	{
		
		if (top == max_size-1)
		{
			cout << "Stack overflow" << endl;
		}

		else
		{
			data[++top] = newItem;
		}
	}

	void pop()
	{
		if (top == -1)
		{
			cout << "Stack is empty" << endl;
		}

		else
		{
			data[--top];
		}
	}

	void clear()
	{
		top == -1;
	}
	
	T getTop() const
	{
		if (top == -1)
		{
			cout << "Stack overflow" << endl;
		}

		else
		{
			return data[top];
		}
	}


	
	bool isEmpty() const
	{
		if (top == -1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}


	bool isFull() const
	{
		
		if (top ==max_size - 1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}


	void showStructure() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty " << endl;
		}
		else
		{
			for (int i = 0; i <= top; i++)
			{
				cout << data[i];
			}

			cout << "Top is:" << top << endl;
		}
	}

};

int main()
{
	Stack<int> integer_stack;
	Stack<float> float_stack;
	Stack<string> string_stack;
	

	integer_stack.push(5);
	integer_stack.push(6);
	integer_stack.showStructure();

	float_stack.push(-3.0);
	float_stack.push(-8.0);
	float_stack.showStructure();

	string_stack.pop();
	string_stack.pop();
	string_stack.showStructure();

	
	
	return 0;
}
*/


template <class T>
class Queue
{
private:
	
	T* data; 
	int front; 
	int rear; 
	const int max_size;

public:
	
	Queue(const int MAX_SIZE = 5) :max_size(max_size)
	{

		front = -1;
		rear = -1;
		data = new T[max_size];
	}
	
	~Queue()
	{
		delete[]data;
	}

	void enQueue(const T newItem)
	{
		if (isFull())
		{
			cout << "Queue is full" << endl;
		}

		else
		{
			if (front == -1)
			{
				front = 0;
			}
			rear = (rear + 1) % max_size;

			data[rear] = newItem;

			if (front == -1)
			{
				front = rear;
			}
		}
	}

	void deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			if (front == rear)
			{
				front = rear = - 1;
			}
		}
		
	}

	void clear()
	{
		front = -1;
		rear = -1;
	}
	
	T getFront() const
	{
		if (!isEmpty())
		{
			return data[front];
		}
		else
		{
			cout << "Queue is empty" << endl;
				return T();
		}
	}
	T getRear() const
	{
		if (!isEmpty())
		{
			return data[rear];
		}
		else
		{
			cout << "Queue is empty" << endl;
			return T();
		}
		
	}
	
	bool isEmpty() const
	{
		return size == 0;
	}

	bool isFull() const
	{
		return(rear + 1) % max_size == front;
	}
	
	void showStructure() const
	{
		if (isEmpty())
		{
			cout << "Queue empty" << endl;
        }
		else
		{
			int i = front;
			while (i != rear)
			{
				cout << data[i];
				i = (i + 1) % max_size;
			}
			cout << data[rear] << front << rear << endl;
		}
	}

};

int main()
{
	Queue<int> integer_stack;
	Queue<float> float_stack;
	Queue<string> string_stack;

	integer_stack.enQueue(5);
	integer_stack.enQueue(6);
	integer_stack.showStructure();

	float_stack.enQueue(-3.0);
	float_stack.enQueue(-8.0);
	float_stack.showStructure();

	string_stack.deQueue();
	string_stack.deQueue();
	string_stack.showStructure();

	return 0;
}