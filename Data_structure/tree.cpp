#include <iostream>
using namespace std;

class dugum {
public:
	int data;
	dugum* sol;
	dugum* sag;
public:
	dugum(int data, dugum* sol = nullptr, dugum* sag = nullptr) {
		this->data = data;
		this->sol = sol;
		this->sag = sag;
	}
};

class tree {
private:
	dugum* root;
	public:
		tree() {
		root = nullptr;
	}
		void ekle(int veri) {
		dugum* newnode = new dugum(veri, nullptr, nullptr);
		if (root == nullptr) {
			root = newnode;
		}
		else {
			dugum* temp = root;
			while (temp != nullptr) {
				if (veri < temp->data) {
					if (temp->sol == nullptr) {
						temp->sol = newnode;
						break;
					}
					else {
						temp = temp->sol;
					}
				}
				else {
					if (temp->sag == nullptr) {
						temp->sag = newnode;
						break;
					}
					else {
						temp = temp->sag;
					}
				}
			}
		}
	}	
		bool isEmpty()
		{
			return root == nullptr;
		}
		dugum* en_buyuk_deger() {
			dugum * temp= root;
			while (temp->sag != nullptr)
			{
				temp=temp->sag;
			}
			return temp;
	 }
		dugum* en_kucuk_deger(dugum * temp) {
			dugum* temp = root;
			while (temp->sol != nullptr)
			{
				temp = temp->sol;
			}
			return temp;
		}
		bool arama(int aranan) {
			dugum* temp = root;
			while (temp != nullptr)
			{
				if (aranan == temp->data) {
					return true;
				}
				else if (aranan < temp->data) {
					temp = temp->sol;
				}
				else {
					temp = temp->sag;
				}
			}
			return false;
		}
		void ekle(int veri) {
		dugum* newnode = new dugum(veri, nullptr, nullptr);
			if (root == nullptr) {
				root = newnode;
			}
			else {
				dugum* temp = root;
				while (temp != nullptr) {
					if (veri < temp->data) {
						if (temp->sol == nullptr) {
							temp->sol = newnode;
							break;
						}
						else {
							temp = temp->sol;
						}
					}
					else {
						if (temp->sag == nullptr) {
							temp->sag = newnode;
							break;
						}
						else {
							temp = temp->sag;
						}
					}
				}
			}
		}
		dugum* sil(dugum* te_root,int veri) {
			if (root == nullptr) {
				cout << "ağac bos!";
			 }
			else if (veri < root->data)
			{
				root->sol = sil(root->sol, veri);
			}
			else if (veri > root->data)
			{
				root->sag = sil(root->sag, veri);
			}
			else
			{
				if (root->sol == nullptr && root->sag == nullptr)
				{
					delete root;
					
				}
				else if (root->sol == nullptr)
				{
					dugum* temp = root;
					root = root->sag;
					delete temp;
					
				}
				else if (root->sag == nullptr)
				{
					dugum* temp = root;
					root = root->sol;
					delete temp;
					
				}
				else {

					dugum* temp = en_kucuk_deger(root->sol);
					root->data = temp->data;
					root->sol = sil(root->sol, temp->data);
				}
				
			}



			return root;
		}
		void preorder(dugum* temp) {
			if (temp != nullptr) {
				cout << temp->data << " ";
				preorder(temp->sol);
				preorder(temp->sag);
			}
		}
		void inorder(dugum* temp) {
			if (temp != nullptr) {
				inorder(temp->sol);
				cout << temp->data << " ";
				inorder(temp->sag);
			}
		}
		void postorder(dugum* temp) {
			if (temp != nullptr) {
				postorder(temp->sol);
				postorder(temp->sag);
				cout << temp->data << " ";
			}
		}

};