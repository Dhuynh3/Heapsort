#include <iostream>
#include <vector>

class Heapsort {
public:

	std::vector<int> HArray;

	void InsertElement(int val);
	void Heapify();
	void MaxHeapPercolateDown(int node_index, int array_size);
	void PrintHeap();
	void HeapSort_();
};

void Heapsort::InsertElement(int val) {
	this->HArray.push_back(val);
}

void Heapsort::Heapify() {
	
	// Largest internal node is at index floor(n/2)-1, where n is the total number of nodes
	for (int i = (this->HArray.size() / 2) - 1; i >= 0; i--) {
		this->MaxHeapPercolateDown(i, this->HArray.size());
	}
	
}

void Heapsort::MaxHeapPercolateDown(int node_index, int array_size) {

	int child_index_left = 2 * node_index + 1;
	int current_node_value = this->HArray[node_index];

	while (child_index_left < array_size) {

		int maxValue = current_node_value;
		int maxIndex = -1;
		
		// Looping through the child nodes
		for (int i = 0; i < 2 && i + child_index_left < array_size; i++) {
			if (this->HArray[i + child_index_left] > maxValue) {
				maxValue = this->HArray[i + child_index_left];
				maxIndex = i + child_index_left;
			}
		}
		
		if (maxValue == current_node_value) {
			return;
		}
		else {
			std::swap(this->HArray[node_index], this->HArray[maxIndex]);
			node_index = maxIndex;
			child_index_left = 2 * node_index + 1;
		}
		
	}

}

void Heapsort::PrintHeap() {
	for (int i = 0; i < this->HArray.size(); i++) {
		std::cout << this->HArray[i] << " ";
	}
	std::cout << std::endl;
}

void Heapsort::HeapSort_() {
	
	this->Heapify();

	for (int i = this->HArray.size() - 1; i > 0; i--) {
		
		// [0]th element is the largest element in the heap, swap this starting from the end index down.
		std::swap(this->HArray[0], this->HArray[i]);
		
		// Heapify the heap again, but this time only till the index i, since the last element is already sorted.
		this->MaxHeapPercolateDown(0, i);
	}

}

int main() {

	Heapsort* heap = new Heapsort();

	// 49,62,88,73,20,94,68
	heap->InsertElement(49);
	heap->InsertElement(62);
	heap->InsertElement(88);
	heap->InsertElement(73);
	heap->InsertElement(20);
	heap->InsertElement(94);
	heap->InsertElement(68);

	heap->PrintHeap();
	
	// Begin by heapifying the array into a max heap.
	// Do this by calling MaxHeapPercolate on every internal node in the array starting from the largest internal node index
	// Heapified array 94 73 88 62 20 49 68
	heap->HeapSort_();
	


	heap->PrintHeap();
	return 0;
}