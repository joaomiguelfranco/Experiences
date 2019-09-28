#include <iostream>
#include <vector>


void quickSort(std::vector<int>& vec, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = vec[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (vec[i] < pivot)
                  i++;
            while (vec[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = vec[i];
                  vec[i] = vec[j];
                  vec[j] = tmp;
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

int main()
{
	std::vector<int> vec = {2,5,1,9,8,6,4,0};
//	std::iterator it = vec.iterator();
	quickSort(vec,0,vec.size()-1);
	
	for (auto i : vec)
	{
		std::cout << i << std::endl;
	}

}
