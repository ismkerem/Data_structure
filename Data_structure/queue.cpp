#include <iostream>

using namespace std;

class dugum {
public:
	int data;
	dugum* next;
	
	dugum(int data, dugum* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

class queue {
private:
	dugum* on;
	dugum* arka;
	int sayac;
public:
	queue() {
		on = nullptr;
		arka = nullptr;
		sayac = 0;
	}
	
	
	void enqueue(int data) {
		dugum* newnode = new dugum(data, nullptr);
		if (bosmu())
		{
			arka = on = newnode;
			sayac++;
		}
		else
		{
			arka->next = newnode;
			arka = newnode;
			sayac++;
		}
}
void dequeue() {

	if (on == NULL)
	{
		cout << "Queue bombos" << endl;
	}
	else
	{
		dugum* temp_node = on;
		on = on->next;
       if (on == nullptr) {
			arka = nullptr;
		}

		delete temp_node;
	
	}
}
	void print() {
		dugum* temp = on;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}	
	bool bosmu()
	{
		return arka == NULL;
	}

};