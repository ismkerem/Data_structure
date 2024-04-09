#include <iostream>
using namespace std;
class dugum {
public:
	int data;
	dugum* next;
	public:
		dugum(int data, dugum* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};


class stack {
private:
	dugum* ust;
	int size;
	public:
		stack() {
		ust = nullptr;
		size = 0;
	}

     bool isEmpty() {
		return ust == nullptr;
	}
	 void push(int val)
	 {
      dugum* temp = new dugum(val);
		 if (isEmpty())
		 {
			 ust = temp;
	     }
		 else
		 {
			 ust->next =temp ;
			 ust = temp;
			 size++;
		   
	   }
	 }
	 void pop() {
		 if (isEmpty()) {
			 cout<<"stack bos"<<endl;
		 }
		 else {
			 dugum* temp = ust;
			 ust = ust->next;
			 delete(temp);
			 size++;
		 }
	 }
	 void display()
	 {
		 if (!isEmpty())
		 {
			 dugum* temp = ust;
			 while (temp != NULL)
			 {
				 cout << temp->data << endl;
				 temp = temp->next;
			 }
		 }
		 else
		 {
			 cout << "Stack bos";
		 }
	 }


};
int main() {

		stack s;
		s.push(10);
		s.push(20);
		s.push(30);
			
	s.display();


	return 0;
}