// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void swap(vector<int>& vec, int i, int j)
{
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

void look_for_a_swap(vector<int> &A, int index)
{
    std::cout << "Looking for a swap for:" << A[index-1] << std::endl;
    int pivot_index = index - 1;
    int pivot = A[pivot_index];
    
    for(; index < A.size() && pivot > A[index] ; index++)
    {
     // iterates until it finds a higher value or reaches the end of the array
    }
    
    // We swap with the previous when we find a higher value
    swap(A,pivot_index,index-1);   
}

    

bool solution(vector<int> &A) {
    int num_swaps = 0;
    
    for(int index = 1; index < A.size();)
    {
        if(A[index] >= A[index-1])
        {
          index++;
        }
        else
        {
            look_for_a_swap(A, index);
            num_swaps++;
            if(num_swaps > 1)
            {
                return false;
            }
        }
    }
    
    return true;
}