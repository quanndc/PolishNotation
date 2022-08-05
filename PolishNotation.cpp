#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Generics: C++ Template
template <typename T>
class Node
{
public:
	// attributes
	Node<T> *next;
	Node<T> *prev;
	T data;
	// methods
	Node(T value, Node<T> *next, Node<T> *prev)
	{
		this->data = value;
		this->next = next;
		this->prev = prev;
	}

	void setData(T data)
	{
		this->data = data;
	}

	T getData()
	{
		return data;
	}

	void setNext(Node<T> *next)
	{
		this->next = next;
	}

	Node<T> *getNext()
	{
		return next;
	}

	void setPrev(Node<T> *prev)
	{
		this->prev = prev;
	}

	Node<T> *getPrev()
	{
		return prev;
	}

	void print(char *format)
	{
		printf(format, getData());
	}
};

template <typename T>
class Stack
{
private:
	// attributes
	Node<T> *head;
	Node<T> *tail;
	int length = 0;

public:
	// methods
	Stack()
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void setHead(Node<T> *head)
	{
		this->head = head;
	}

	Node<T> *getHead()
	{
		return head;
	}

	void setTail(Node<T> *tail)
	{
		this->tail = tail;
	}

	Node<T> *getTail()
	{
		return tail;
	}

	int getSize()
	{
		return length;
	}

	void duyetStack(char *format)
	{
		Node *newNode = head;
		while (newNode != NULL)
		{
			newNode->print(format);
			newNode = newNode->getNext();
		}
	}

	void push(T value)
	{
		Node<T> *newNode = new Node<T>(value, NULL, NULL);
		if (head == NULL)
		{
			head = tail = new Node<T>(value, NULL, NULL);
			length++;
		}
		else
		{
			newNode->setPrev(tail);
			tail->setNext(newNode);
			setTail(newNode);
			length++;
		}
	}

	T pop()
	{
		Node<T> *result = tail;
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			if (tail->getPrev() != NULL)
			{
				tail = tail->getPrev();
				tail->setNext(NULL);
			}
			else
			{
				head = tail = NULL;
			}
			length--;
		}
		return result->data;
	}

	T peek()
	{
		return tail->data;
	}
};

template <typename T>
class Queue
{
private:
	Node<T> *head;
	Node<T> *tail;
	int length;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void setHead(Node<T> *head)
	{
		this->head = head;
	}

	void setTail(Node<T> *tail)
	{
		this->tail = tail;
	}

	int getSize()
	{
		return length;
	}

	void duyetQueue(char *format)
	{
		Node<T> *newNode = head;
		while (newNode != NULL)
		{
			newNode->print(format);
			newNode = newNode->getNext();
		}
	}

	void enqueue(T value)
	{
		Node<T> *newNode = new Node<T>(value, NULL, NULL);
		if (head == NULL)
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			tail->setNext(newNode);
			setTail(newNode);
			length++;
		}
	}

	T dequeue()
	{
		Node<T> *result = head;
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			head = head->next;
			length--;
		}
		return result->getData();
	}

	T front()
	{
		return head->getData();
	}
};



class PolishNotation
{
private:
	Stack<int> *stack;
	Queue<int> *queue;
	bool isOperand(char ch)
	{
		return (ch >= '0' && ch <= '9');
	}
	int getPriority(char k)
	{
		switch (k)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		}
		return -1;
	}

public:
	Queue<int> *infixToPostfix(char *exp)
	{
		int i;
		Stack<int> *operators = new Stack<int>();
		// char *result = new char[strlen(exp)];
		Queue<int> *result = new Queue<int>();
		for (i = 0; i <= strlen(exp); i++)
		{
			if (isOperand(exp[i]))
			{
				result->enqueue(exp[i]);
			}
			else
			{
				if (operators->getSize() == 0 || getPriority(operators->peek()) <= getPriority(exp[i]))
				{
					operators->push(exp[i]);
				}

				else if (operators->getSize() == 0 || exp[i] == '(')
				{
					operators->push('(');
					continue;
				}

				else if (operators->getSize() == 0 || exp[i] == ')')
				{

					while (operators->peek() != '(')
					{
						result->enqueue(operators->pop());
					}
					if (operators->peek() == '(')
					{
						operators->pop();
					}
					continue;
				}

				else
				{
					while (operators->getSize() != 0 && getPriority(operators->peek()) >= getPriority(exp[i]))
					{
						result->enqueue(operators->pop());
					}
					operators->push(exp[i]);
				}
			}
		}
		return result;
	}

	double evaluatePostfix(char *exp)
	{
		Stack<double> *stackDouble = new Stack<double>();
		Queue<int> *postfix = infixToPostfix(exp);

		while (postfix->getSize() != 0)
		{
			if (isOperand(postfix->front()))
			{
				stackDouble->push(postfix->dequeue() - 48);
			}
			else
			{
				double val2 = stackDouble->pop();
				double val1 = stackDouble->pop();
				switch (postfix->dequeue())
				{
				case '+':
					stackDouble->push(val1 + val2);
					break;
				case '-':
					stackDouble->push(val1 - val2);
					break;
				case '*':
					stackDouble->push(val1 * val2);
					break;
				case '/':
					stackDouble->push(val1 / val2);
					break;
				}
			}
		}
		return stackDouble->pop();
		// return 0;
	}
};

int main()
{
	PolishNotation *polish = new PolishNotation();
	char exp[] = "9+2+35+3*6";
	Queue<int> *postfix = polish->infixToPostfix(exp);
	postfix->duyetQueue("%c ");
	printf("postfix evaluation: %.2lf", polish->evaluatePostfix(exp));
	return 0;

	// need format the value!!!
}
