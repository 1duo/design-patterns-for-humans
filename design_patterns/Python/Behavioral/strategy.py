class SortStrategy:

    def sort(self, data):
        raise NotImplementedError


class BubbleSortStrategy(SortStrategy):

    def sort(self, data):
        print('Sorting using bubble sort')
        return data


class QuickSortStrategy(SortStrategy):

    def sort(self, data):
        print('Sorting using quick sort')
        return data


class Sorter:

    def __init__(self, sorter):
        self.sorter = sorter

    def sort(self, data):
        return self.sorter.sort(data)


if __name__ == '__main__':

    data = [1, 5, 4, 3, 2, 8]
    sorter = Sorter(BubbleSortStrategy())
    sorter.sort(data)  # Sorting using bubble sort

    sorter = Sorter(QuickSortStrategy())
    sorter.sort(data)  # Sorting using quick sort
