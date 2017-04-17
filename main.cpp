#include"my_list.h"

int main() {
	int arr[6] = { 1,2,3,4,5,6};
	List list(arr, 6);
	vector<int>v = { 1,2,3,4 };
	List list1(v);
	cout << list.length() << endl;
	list.combine(list1);
	cout << list.remove(1) << endl;
	cout << list.find(1) << endl;
	cout << list.insert(3, 10) << endl;
	cout << list.split(6, list1) << endl;
	list.printAll();
	cin.get();
	return 0;
}