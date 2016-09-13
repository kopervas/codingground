	/*Задача на наслідування і поліморфізм: Описати базовий клас "Рядок" 
		з віртуальними функціями і похідні від нього класи "Стек" і "Черга"
	Проблемні питання:
		1. Стек: 
			- як правильно видалити елемент зі стеку? Достатньо просто 
		зменшити лічильник?
			- як реалізувати перегляд для стеку?
			- чи можна сортувати у стеку?
		2. Чи правильно реалізовано чергу? */

#include <iostream>
using namespace std;

struct Element
{
   int data;
   Element * Next;
};

class List
{
   Element * Head;
   Element * Tail;
   int Count;
public:
	List(){Head=Tail=0; Count=0;};
	~List(){};

   virtual void v_Add(int data)
	{
		Element * temp = new Element;
		temp->data = data;
		temp->Next = Head;
		Head = temp;
		Count++;
   }
   virtual void v_Del()
   {
		Element * temp = Head;
		Head = Head->Next;
		delete temp;
		Count--;
   }
  virtual void v_Show()
   {
		Element * temp = Head;
		while(temp != 0)
		{
		cout << temp->data << " ";
		temp = temp->Next;
   }
   cout << "\n\n";
   }
   virtual void v_Sort()
   {
		Element *temp = new Element;
		temp = Head;
		bool c = 1;

		while(c)
		{
			int t;
			temp = Head;
			c = 0;
			for(int i = 0; i < Count-1; i++){
			if(temp->data > (temp->Next)->data)
			{
				t = temp->data;
				temp->data = (temp->Next)->data;
				(temp->Next)->data = t;
				c = 1;
			}
			temp = temp->Next;
		}
	}
   }
 };

class Stack: public List
{
    int d[20];
    enum { FULL = 20, EMPTY = -1};
    int top = 0;
public:
    List(){top=0;};
	~List(){};

  void v_Add(int data)
	{
		d = data;
		top++;
   }
   void v_Del() //як правильно видалити елемент зі стеку?
   {            //достатньо просто зменшити лічильник?
       d[top] = NULL;
        top--;
   }
   int Pop()
   {
       return d[top];
       top--;
   }

  void v_Show() //як реалізувати перегляд для стеку?
   {
       int c = top;
		while(c> EMPTY)
        {
            cout << d[c] << ' ';
            c--;
        }
   }

   void v_Sort() //чи можна сортувати дані у стеку?
   {
		bool c = 1;
		while(c)
		{
			for(int i = top; i > EMPTY; i--){
                int temp = d[i];
			if(temp > d[i-1]))
			{
				d[i] = d[i-1];
				d[i-1] = temp;
				c = 1;
                }
            }
        }
   }
}
};
class Queue: public List           //клас черги, похідний від списку
{
public:
    List(){Head=Tail=0; Count=0;};
	~List(){};

	void v_Del()                    //для черги перевизначаємо лише одну функцію
   {                                //оскільки видалення відбувається "з хвоста"
		Element * temp = Head;
        for(int i = 1; i < Count; i++)
        {
            temp=temp->Next;
        }
        if(Count!=0)
   {
        temp->Next=0;
        Count--;
   }
   }
};
int main()
{
	int n, z;
	List lst;
	cout << "Vvedit kilkist zapusiv" << endl;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Vvedit znachennia" << endl;
		cin >> z;
		lst.AddToHead(z);
	}
	lst.v_Show();
	lst.v_Sort();
	lst.v_Show();
	return 0;
}
