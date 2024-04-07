#include <iostream>
using namespace std;
class dugum {
public:
	int data;
	dugum* next;
	dugum* prev;

	dugum(int data, dugum* next = nullptr, dugum* prev = nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};
class cift_yonlu_liste {
private:
private:
	dugum* head;
	dugum* tail;
	public:
		cift_yonlu_liste() {
			head = nullptr;
			tail = nullptr;
		}

		cift_yonlu_liste(){}
		void basaEkle(int veri) {
			dugum* newnode = new dugum(data, nullptr, nullptr);
			if (head == nullptr) {
				head = tail = newnode; 
			}
			else {
				newnode->next = head; 
				head->prev = newnode; 
				head = newnode;
				
			}
			
		}
		void sonaEkle(int veri) {
			dugum* newnode = new dugum(veri, nullptr, nullptr);
			if (head == nullptr) {
				head = tail = newnode;
			}
			else {
				tail->next = newnode;
				newnode->prev = tail;
				tail = newnode;
			}
		}
		void eleman_ekle(int aranan_veri, dugum* eklenmek_istenen) {
			dugum* temp = head;
			while (temp->next != nullptr)
			{
				if (temp->data == aranan_veri) {
					break;
				}
				temp = temp->next;
			}
			dugum* temp2 = temp;
			temp->next = eklenmek_istenen;
			eklenmek_istenen->next = temp2->next;

			eklenmek_istenen->next = temp2->next;
			temp2->next->prev = eklenmek_istenen;
			eklenmek_istenen->prev = temp2;
			temp2->next = eklenmek_istenen;
		}
		void eleman_sil(int data) {
			dugum* temp2 = head;
			if (temp2->data == data) {
				head = head->next;
				if (head != nullptr) {
					head->prev = nullptr;
				}
				else {
					tail = nullptr;
				}
				delete temp2;
				return;
			}

			while (temp2->next != nullptr && temp2->next->data != data) {
				temp2 = temp2->next;
			}

			if (temp2->next == nullptr) {
				cout << "Veri bulunamadı!" << endl;
				return;
			}

			dugum* temp = temp2->next;
			temp2->next = temp->next;
			if (temp->next != nullptr) {
				temp->next->prev = temp2;
			}
			else {
				tail = temp2;
			}
			delete temp;
		}

		void onden_sil() {
			if (head == nullptr) {
				return;
			}
			else if (head == tail) {
				head = tail = nullptr;
			}
			else {
				dugum* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
		}
		void arkadan_sil() {
			if (head == nullptr) {
				return;
			}
			else if (head == tail) {
				head = tail = nullptr;
			}
			else {
				dugum* temp = tail;
				tail->next = nullptr;
				tail = tail->prev;

			}
			}
};

int main() {




	cift_yonlu_liste liste;
	liste.sonaEkle(5);
	liste.sonaEkle(10);
    liste.sonaEkle(105);
	
	return 0;
	
}