#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int value;
	Node *next;
	Node(int v) : value(v), next(NULL) {}
};
class List {
public:
	List(const vector<int> & v);
	List(int *array, int array_size);
	int length()const;
	bool insert(int pos, int value);
	int find(int value);
	int remove(int value);
	bool split(int pos, List& new_list);
	void combine(List& append_list);
	void printAll();
	~List() { delete[] head; }
private:
	Node* head;
	int size = length();
};

List::List(const vector<int>&v) {                     //construct a list using a "vector";
	int v_size = v.size();
	head = new Node(v[0]);
	Node *ele = head;
	for (int i = 0; i < v_size - 1; ++i) {
		ele->next = new Node(v[i + 1]);
		ele = ele->next;
	}
	ele = new Node(NULL);
	delete ele;
}
List::List(int* array, int array_size) {                //construct a list using a "array";
	head = new Node(array[0]);                          //the first node of the list;
	Node *ele = head;
	for (int i = 1; i < array_size; ++i) {
		ele->next = new Node(array[i]);
		ele = ele->next;
	}
	ele = new Node(NULL);
	delete ele;
}
int List::length()const {                           //return the length of the list;
	int size_ele = 0;
	Node*ele = head;
	while (ele != NULL) {
		size_ele += 1;
		ele = ele->next;
	}
	delete ele;
	return size_ele;
}
bool List::insert(int pos, int value) {                    //insert a "value" in the position of "pos";
	size = length();
	if (pos > size || pos<0)
		return false;
	else {
		vector<int>v;
		Node*ele = head;
		for (int i = 0; i < size; ++i) {
			if (i != pos) {
				v.push_back(ele->value);
				ele = ele->next;
			}
			else {
				v.push_back(value);
				v.push_back(ele->value);
				ele = ele->next;
			}
		}
		delete ele;
		head = new Node(v[0]);
		Node*in_ele = head;
		for (int i = 0; i < v.size() - 1; ++i) {
			in_ele->next = new Node(v[i + 1]);
			in_ele = in_ele->next;
		}
		in_ele = new Node(NULL);
		delete in_ele;
		return true;
	}
}
int List::find(int value) {                              //judge the element "value" whether in list;
	size = length();
	Node*fele = head;
	for (int i = 0; i < size; ++i) {
		if (fele->value == value) {
			delete fele;
			return i;
		}
		else {
			fele = fele->next;
		}
	}
	delete fele;
	return -1;
}
int List::remove(int value) {                              //remove all the element which is the same as "value";
	size = length();
	Node*re_ele = head;
	int pos = 0;
	vector<int>v;
	for (int i = 0; i < size; ++i) {
		v.push_back(re_ele->value);
		re_ele = re_ele->next;
	}
	delete re_ele;
	vector<int>vv;
	for (int i : v) {
		if (i == value)
			pos += 1;
		else {
			vv.push_back(i);
		}
	}
	head = new Node(vv[0]);
	Node*ele = head;
	for (int i = 0; i < vv.size() - 1; ++i) {
		ele->next = new Node(vv[i + 1]);
		ele = ele->next;
	}
	ele = new Node(NULL);
	delete ele;
	return pos;
}
bool List::split(int pos, List&new_list) {                        //make the list splited in the positon of "pos" and the left part construct a new list;
	size = length();
	if (pos >= size || pos < 0)
		return false;
	else {
		vector<int>v;
		Node*sele = head;
		for (int i = 0; i < size; ++i) {
			v.push_back(sele->value);
			sele = sele->next;
		}
		delete sele;
		vector<int>v1;
		vector<int>v2;
		for (int i = 0; i < pos + 1; ++i) {
			v1.push_back(v[i]);
		}
		for (int i = pos + 1; i < size; ++i) {
			v2.push_back(v[i]);
		}
		new_list.head = new Node(v2[0]);
		Node*new_ele = new_list.head;
		for (int i = 0; i < v2.size() - 1; ++i) {
			new_ele->next = new Node(v2[i + 1]);
			new_ele = new_ele->next;
		}
		new_ele = new Node(NULL);
		delete new_ele;
		head = new Node(v1[0]);
		Node*re_ele = head;
		for (int i = 0; i < v1.size() - 1; ++i) {
			re_ele->next = new Node(v1[i + 1]);
			re_ele = re_ele->next;
		}
		re_ele = new Node(NULL);
		delete re_ele;
		return true;
	}
}
void List::combine(List&append_list) {                               //make list longer by add another "append_list" at the end of list;
	size = length();
	int size_append = append_list.length();
	vector<int>v;
	Node*com_ele = head;
	for (int i = 0; i < size; ++i) {
		v.push_back(com_ele->value);
		com_ele = com_ele->next;
	}
	delete com_ele;
	Node*aele = append_list.head;
	for (int i = 0; i < size_append; ++i) {
		v.push_back(aele->value);
		aele = aele->next;
	}
	delete aele;
	head = new Node(v[0]);
	Node *c_ele = head;
	for (int i = 0; i < v.size() - 1; ++i) {
		c_ele->next = new Node(v[i + 1]);
		c_ele = c_ele->next;
	}
	c_ele = new Node(NULL);
	delete c_ele;
}
void List::printAll() {                        //print all the elements of the list;
	size = length();
	Node*pele = head;
	int pos = 0;
	vector<int>v;
	for (int i = 0; i < size; ++i) {
		v.push_back(pele->value);
		pele = pele->next;
	}
	delete pele;
	for (int i : v)
		cout << i << " ";
	cout << endl;
}
