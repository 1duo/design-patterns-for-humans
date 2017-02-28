#include <iostream>
#include <vector>

class SortStrategy {
  public:
	virtual void sort(std::vector<int>& data) = 0;
};

class BubbleSortStrategy: public SortStrategy {
  public:
	void sort(std::vector<int>& data) {
		std::cout << "Sorting using bubble sort" << std::endl;
	}
};

class QuickSortStrategy: public SortStrategy {
  public:
	void sort(std::vector<int>& data) {
		std::cout << "Sorting using quick sort" << std::endl;
	}
};

class Sorter {
  protected:
	SortStrategy* sorter = nullptr;

  public:
	Sorter(SortStrategy* sorter) {
		this->sorter = sorter;
	}

	void sort(std::vector<int>& data) {
		return this->sorter->sort(data);
	}
};

int main() {
	std::vector<int> data1 = {1, 5, 4, 3, 2, 8};
	auto sorter1 = new Sorter(new BubbleSortStrategy());
	sorter1->sort(data1);
	std::vector<int> data2 = {1, 5, 4, 3, 2, 8};
	auto sorter2 = new Sorter(new QuickSortStrategy());
	sorter2->sort(data2);
	// =========================
	// Sorting using bubble sort
	// Sorting using quick sort
	// =========================
	return 0;
}
