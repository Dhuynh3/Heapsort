#include <iostream>
#include <vector>





class Heapsort {
public:

	std::vector<int> HArray;


	void InsertElement(int val);
	void Heapify(int node_index);
};


void Heapsort::InsertElement(int val) {
	this->HArray.push_back(val);
}

void Heapsort::Heapify(int node_index) {

}


int main() {

	Heapsort* heap = new Heapsort();

	heap->InsertElement(49);
	heap->InsertElement(62);
	heap->InsertElement(88);
	heap->InsertElement(73);
	heap->InsertElement(20);
	heap->InsertElement(94);
	heap->InsertElement(68);
	// 49,62,88,73,20,94,68


	// Begin by heapifying the array into a max heap




	return 0;
}