#include <iostream>
#include <ctime>
using namespace std;
class Stack {
	struct Element {
		Element* pNext;
		int data;
	};
	Element* pEnd;
	int Size;
	void Add(const int data) {
		Element* temp = pEnd;
		if (pEnd != nullptr) {
			while (temp->pNext != nullptr) {
				temp = temp->pNext;
			}
			temp->pNext = new Element;
			temp = temp->pNext;
			temp->pNext = nullptr;
			temp->data = data;
		}
		else {
			pEnd = new Element;
			pEnd->data = data;
			pEnd->pNext = nullptr;
		}
	}
public:
	Stack() {
		Size = 0;
		pEnd = nullptr;
	}
	int GetSize() {
		return Size;
	}
	Element* Begin() {
		return pEnd;
	}
	int PopBack() {
		if (Size) {
			if (pEnd->pNext != nullptr) {
				int result = pEnd->data;
				Element* next = pEnd;
				pEnd = pEnd->pNext;
				delete next;
				Size--;
				return result;
			}
			Size--;
		}
		return 0;
	}
	void PushBack(int data) {
		Element* node = new Element;
		node->data = data;
		node->pNext = pEnd;
		pEnd = node;
		Size++;
	}
	~Stack() {
		Clear();
	}
	void Clear() {
		while (Size)
			PopBack();
	}
	void Print() {
		cout << pEnd->data;
	}
	void PrintAll() {
		Element* temp = pEnd;
		if (pEnd != nullptr) {
			cout << pEnd->data << " ";
		}
		while (temp->pNext != nullptr) {
			temp = temp->pNext;
			cout << temp->data << " ";
		}
		cout << endl;
	}
	Element* Clon(const Stack& s) {
		Size = s.Size;
		Element* temp = s.pEnd;
		while (temp != nullptr) {
			Add(temp->data);
			temp = temp->pNext;
		}
		return temp;
	}
	const Stack& operator+(const Stack& st) {
		Stack* s = new Stack;
		s->Size = this->Size + st.Size;
		Element* temp = this->pEnd;
		while (temp != nullptr) {
			s->Add(temp->data);
			temp = temp->pNext;
		}
		temp = st.pEnd;
		while (temp != nullptr) {
			s->Add(temp->data);
			temp = temp->pNext;
		}
		return *s;
	}
	const Stack& operator*(const Stack& st) {
		Stack* s = new Stack;
		s->Size = 0;
		Element* temp = this->pEnd;
		Element* temp2 = st.pEnd;
		while (temp != nullptr) {
			for (int i = 0; i < st.Size; i++) {
				if (temp->data == temp2->data) {
					s->Add(temp->data);
					s->Size++;
				}
				temp2 = temp2->pNext;
			}
			temp = temp->pNext;
			temp2 = st.pEnd;
		}
		if (s->Size == 0) {
			cout << "Общих элементов не найдено" << endl;
		}
		else {
			s->PrintAll();
		}
		return *s;
	}
};
int main() {
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	Stack st, st2, st3;
	for (int i = 0; i < 5; i++) {
		st.PushBack(rand() % 10);
	}
	for (int i = 0; i < 5; i++) {
		st3.PushBack(rand() % 10);
	}
	st2.Clon(st);
	cout << "Начальный Stack, размером: " << st.GetSize() << " \n" << "st1: ";
	st.PrintAll();
	cout << endl;
	cout << "Клонированный Stack, размером: " << st2.GetSize() << " \n" << "st2: ";
	st2.PrintAll();
	cout << endl;
	cout << "Сложение st + st3: " << endl;
	Stack st4 = st + st3;
	cout << endl;
	cout << "st: ";
	st.PrintAll();
	cout << endl;
	cout << "st3: ";
	st3.PrintAll();
	cout << endl;
	cout << "st4: ";
	st4.PrintAll();
	cout << endl << "Общие элементы у st и st3: " <<endl;
	cout << "st5: ";
	Stack st5 = st * st3;

	
}