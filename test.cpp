#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <type_traits>
#include <iostream>

using namespace std;

// Generics: C++ Template
template <typename T>
class Node
{
public:
	// attributes
	Node<T> *next;
	Node<T> *prev;
	T data;
public:
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
class LinkedList
{
	public:
		Node<T>* head;
		Node<T>* tail;
		int length;
	public:
		LinkedList()
		{
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		void setHead(Node<T>* head)
		{
			this -> head = head;
		}
		
		void setTail(Node<T>* tail)
		{
			this -> tail = tail;
		}
		
		Node<T>* getPosition(int index)
		{
			if(index < 0 || index > length)
			{
				return NULL;
			}
			else
			{
				Node<T>* newNode = head;
				for(int i=0; i<index; i++)
				{
					newNode = newNode -> getNext();
					return newNode;
				}
			}
		}
		
		int getSize()
		{
			return length;
		}
		
		void duyetList()
		{
			Node<T>* newNode = head;	
			while(newNode != NULL)
			{
				newNode -> print();
				newNode = newNode -> getNext();
			}
		}
		
		void addHead(T value)
		{
			Node<T>* newNode = new Node<T>(value,NULL,NULL);
			if(head == NULL)
			{
				head = tail = newNode;
				length++;
			}
			else
			{
				newNode -> setNext(head);
				setHead(newNode);
				length++;
			}
		}
		
		void addTail(T value)
		{
			Node<T> *newNode = new Node<T>(value,NULL,NULL);
			if(head == NULL)
			{
				head = tail = newNode;
				length++;
			}
			else
			{
				tail -> setNext(newNode);
				setTail(newNode);
				length++;
			}	
		}
		
		
		
		void delHead()
		{
			if(head == NULL)
			{
				printf("Nothing to delete");
			}
			else
			{
				head = head -> next;
			}
		}
		
		void delTail()
		{
			if(head == NULL || head -> next -> next == NULL)
			{
				return delHead();
			}
			else
			{
				Node<T>* p = head;
				while(p -> next -> next != NULL)
				{
					p = p -> next;
				}
				p -> next = p -> next -> next;
			}
		}
};	


template <typename T>
class Stack
{
public:
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

class Token
{
    protected:
        char *rawText;
		bool _isOperand;
    public: 
        Token(char *rawText)
        {
			this->rawText = new char[strlen(rawText) + 1];
			strcpy(this->rawText, rawText);
			// printf("%s\n", this->rawText);
        }
		Token(double value){
			char *rawText = "\0";
			sprintf(rawText, "%f", value);
			strcpy(this->rawText, rawText);
		}
		char* getRawText(){
			return rawText;
		}
		bool isOperand(){
			return _isOperand;
		}
};

class Operand : public Token
{
    public:
        Operand(char *rawText) : Token(rawText)
		{
			_isOperand = true;
		}
		Operand(double value) : Token(value)
		{
			_isOperand = true;
		}
		double getValue()
		{
			return atof(rawText);
		}
};


class Operator : public Token
{
    public:
        Operator(char *rawText) : Token(rawText){
			_isOperand = false;
		}
		int getPriority(){
			//printf("%s\n", rawText);
			if(strcmp(rawText,"+")==0)
			{
				return 1;
			}
			else if(strcmp(rawText, "-") == 0)
			{
				return 1;
			}
			else if(strcmp(rawText, "*") == 0)
			{
				return 2;
			}
			else if(strcmp(rawText, "/") == 0)
			{
				return 2;
			}
			else if(strcmp(rawText, "^") == 0)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		Operand* calc(Operand *left, Operand *right)
		{
			if(strcmp(rawText, "+") == 0)
			{
				return new Operand(left->getValue() + right->getValue());
			}
			else if(strcmp(rawText, "-") == 0)
			{
				return new Operand(left->getValue() - right->getValue());
			}
			else if(strcmp(rawText, "*") == 0)
			{
				return new Operand(left->getValue() * right->getValue());
			}
			else if(strcmp(rawText, "/") == 0)
			{
				return new Operand(left->getValue() / right->getValue());
			}
			else if(strcmp(rawText, "^") == 0)
			{
				return new Operand(pow(left->getValue(), right->getValue()));
			}
			else
			{
				return NULL;
			}
		}
		// Overloading
		Operand* calc(Operand *op){
			return NULL;
		}
};

template<typename Base, typename T>
inline bool instanceof(const T* ) {
    return std::is_base_of<Base, T>::value;
}


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
	LinkedList<Token*> *parsing(char *exp)
	{
		LinkedList<Token*> *list = new LinkedList<Token*>();
		char *_operand = new char[100];
		char *_operator = new char[1];
		int i = 0;
		while(i<strlen(exp))
		{
			if(isOperand(exp[i]))
			{
				for(int j=i;j<=strlen(exp);j++)
				{
					if(exp[j]=='+' || exp[j]=='-' || exp[j]=='*' || exp[j]=='/' || exp[j]=='(' || exp[j]==')' ||  j == strlen(exp) )
					{
						int size = j-i+(j==strlen(exp)?1:0);
						strncpy(_operand,(exp+i),size);
						_operand[size] = '\0';
						i=j-1;
						break;
					}
				}
				// printf("%s\n", _operand);
				list -> addTail(new Operand(_operand));
				_operand = new char[100];
			}
			else
			{
				strncpy(_operator,(exp+i),1);
				// printf("%s\n", _operator);
				_operator[1] = '\0';
				list -> addTail(new Operator(_operator));
				_operator = new char[2];
			}
			i++;
		}
		return list;
	}

	Queue<Token*> *infixToPostfix(char* exp)
	{
		int i;
		LinkedList<Token*> *list = parsing(exp);
		Stack<Operator*> *operators = new Stack<Operator*>();
		Queue<Token*> *result = new Queue<Token*>();
		Node<Token*>* ptr = list->head;
		while(ptr!=NULL)
		{
			if (ptr->getData()->isOperand())
			{
				result->enqueue(ptr->getData());
			}
			else
			{
				Operator *op = (Operator*)ptr->getData();
				if (operators->getSize() == 0 || operators->peek()->getPriority() <= op->getPriority())
				{
					operators->push(op);
				}

				else if (operators->getSize() == 0 || strcmp(op->getRawText(), "(") == 0)
				{
					operators->push(op);
				}

				else if (operators->getSize() == 0 || strcmp(op->getRawText(), ")") == 0)
				{
					while (strcmp(operators->peek()->getRawText(), "(")!=0)
					{
						result->enqueue(operators->pop());
					}
					if (strcmp(operators->peek()->getRawText(), "(")==0)
					{
						operators->pop();
					}
				}

				else
				{
					while (operators->getSize() != 0 && operators->peek()->getPriority() >= op->getPriority())
					{
						result->enqueue(operators->pop());
					}
					operators->push(op);
				}
			}
			ptr = ptr->getNext();
		}
		while(operators->getSize()!=0)
		{
			result->enqueue(operators->pop());
		}
		return result;
	}


	double evaluatePostfix(char *exp)
	{
		Stack<double> *stackDouble = new Stack<double>();
		Queue<Token*> *postfix = infixToPostfix(exp);

		while (postfix->getSize() != 0)
		{
			if (postfix->front()->getRawText() == 
			{
				stackDouble->push((char)postfix->dequeue()->getRawText());
			}
			else
			{
				double val2 = stackDouble->pop();
				double val1 = stackDouble->pop();
				switch ((char)postfix->dequeue()->getRawText())
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
	char* exp = "12+8";
	Queue<Token *> *postfix = polish->infixToPostfix(exp);
	while (postfix->getSize() != 0)
	{
		cout << postfix->dequeue()->getRawText();
	}
	printf("postfix evaluation: %.2lf", polish->evaluatePostfix(exp));
	return 0;

	// need format the value!!!
}
