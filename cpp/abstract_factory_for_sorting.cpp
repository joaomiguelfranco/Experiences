// Disclaimer:
//  - I used sorting algorithms from the web
//  - I didn't implement my ones, since:
//        - The exercise is planned for 1h
//        - And I focused on the Abstract Factory and code readability
//  - In the sorting method decision:
//        - I took the liberty to use Enum Classes instead of the string, because:
//            - It is strong typed
//            - Doesn't give room for human errors (e.g. case-sensitivy)
//        - If string is really required, I'd create an adapter between the string and the Enum Class SortingMethod.
//  - The only tests are in main() and they are really simple
//  - In production code, I'd invest more in:
//      - UTs in the SortingAlgorithms
//      - UT for the factory with a mocked SortAlgo to check for expectations on which algo is called depending on the input for the factory.
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class SortAlgo
{
public:
  virtual ~SortAlgo() = default;
  virtual void sort(std::vector<int>&) = 0;
};


enum class SortingMethod
{
  BUBBLE,
  QUICK,
  HEAP
};

class BubbleSortAlgo : public SortAlgo
{
public:
  void sort(std::vector<int>& input_list) 
  {
    bubbleSort(input_list);
  }
    
private:
  // A function to implement bubblesort. I picked it from the web
  void bubbleSort(std::vector<int>& list)  
  {  
    for (int i = 0; i < list.size()-1; i++)
    {
      for (int j = 0; j < list.size()-i-1; j++)  
        if (list.at(j) > list.at(j+1))  
          std::swap(list.at(j), list.at(j+1));  
    }
  }  

};

class QuickSortAlgo : public SortAlgo
{
public:
  void sort(std::vector<int>& input_list) 
  {
    quickSort(input_list, 0, input_list.size());    
  }

private:
  void quickSort(std::vector<int>& vec, int left, int right)
  {
    int i = left, j = right;
    int pivot = vec[(left + right) / 2];

    /* partition */
    while (i <= j) {
      while (vec[i] < pivot)
        i++;
      while (vec[j] > pivot)
        j--;
      if (i <= j) {
        std::swap(vec[i],vec[j]);
        i++;
        j--;
      }
    };
  
    /* recursion */
    if (left < j)
      quickSort(vec, left, j);
    if (i < right)
      quickSort(vec, i, right);
  }
};

class HeapSortAlgo : public SortAlgo
{
public:
  void sort(std::vector<int>& input_list) 
  {
    heapSort(input_list);
  }
    
private:
  void heapify(std::vector<int>& array, int len, int i)
  {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && array[left] > array[largest])
      largest = left;

    if (right < len && array[right] > array[largest])
      largest = right;

    if (largest != i)
    {
      std::swap(array[i], array[largest]);

      heapify(array, len, largest);
    }
  }
  
  // To be honest, I picked an already existing sorting algo from the web. Didn't implement my own version.
  void heapSort(std::vector<int>& input)
  {
    for (int i = input.size() / 2 - 1; i >= 0; i--)
      heapify(input, input.size(), i);

    for (int i = input.size() - 1; i >= 0; i--)
    {
      std::swap(input[0], input[i]);
      heapify(input, i, 0);
    }
  }


};

void sortFactoryMethod(
    const SortingMethod& sortingMethod,
    std::vector<int>& input_list)
{
  std::unique_ptr<SortAlgo> abstractSortMethod;
  
  switch(sortingMethod)
  {
    case(SortingMethod::BUBBLE):
      abstractSortMethod = std::make_unique<BubbleSortAlgo>();
      break;
    case(SortingMethod::HEAP):
      abstractSortMethod = std::make_unique<HeapSortAlgo>();
      break;
    case(SortingMethod::QUICK):
      abstractSortMethod = std::make_unique<QuickSortAlgo>();
      break;
    default: throw ("Sorting algorithm not implemented");    
  }
  abstractSortMethod->sort(input_list);
}

void print_list(const std::vector<int>& list)
{
  for(const auto& i : list) std::cout << i << ' ';
  std::cout << std::endl;
}

int main()
{  
  std::vector<int> input_list = {4,5,1,643,23,123,542,5243};
    
  std::cout << "BUBBLE SORT" << std::endl;
  print_list(input_list);
  sortFactoryMethod(SortingMethod::BUBBLE, input_list);
  print_list(input_list);

  std::cout << "\nHEAP SORT" << std::endl;
  input_list = {213,5342,12,22,1,4,451,29};
  print_list(input_list);
  sortFactoryMethod(SortingMethod::HEAP, input_list);
  print_list(input_list);

  std::cout << "\nQUICK SORT" << std::endl;
  input_list = {123,12,21,5,2,1,9};
  print_list(input_list);
  sortFactoryMethod(SortingMethod::QUICK, input_list);
  print_list(input_list);
}
