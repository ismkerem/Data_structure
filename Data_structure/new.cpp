#include <iostream>
using namespace std;
class dugum {
private:
	int data;
	dugum* sonraki;
public:
	dugum(int data) {
		this.data = data;
		sonraki = nullptr;
	}
	dugum() {}
	void basaEkle(int veri) {
		dugum* yeniDugum = new dugum;
		yeniDugum->data = veri;
		yeniDugum->sonraki = head;
		head = yeniDugum;
	}
	void sonaEkle(int veri) {
		dugum* yeniDugum = new dugum;
		yeniDugum->data = veri;
		yeniDugum->next = nullptr;

		if (head == nullptr) {
			head = yeniDugum;
		}
		else {
			dugum* temp = head;
			while (temp->sonraki != nullptr) {
				temp = temp->sonraki;
			}
			temp->sonraki = yeniDugum;
		}
	}
	void eleman_ekle(int aranan_veri, dugum* eklenmek_istenen) {

		dugum* temp = head;
		while (temp->sonraki != nullptr)
		{
			if (temp->data == aranan_veri) {
				break
			}
			temp->sonraki = temp;
		}
		dugum* temp2 = temp;
		temp->sonraki = eklenmek_istenen;
		eklenmek_istenen->sonraki = temp2->sonraki;
	}
	void eleman_sil(int data, dugum* sil) {
		dugum* temp = sil;
		while (temp->sonraki != nullptr)
		{
			if (temp->sonraki->data = data) {
				temp->sonraki = temp->sonraki->sonraki;
				break
			}
			else
			{
				temp->sonraki = temp;
			}
		}

	}
	void yazdir() {
		dugum* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->sonraki;
		}
		cout << endl;
	}




};

int main() {
	dugum liste;

	dugum.basaEkle(10);
	dugum.basaEkle(20);
	dugum.sonaEkle(30);

	return 0;

}