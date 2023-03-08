#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> merge_sort(std::vector<int> vec)
{
    if (vec.size()<= 1) return vec;  
      
    int middle =floor(vec.size()/2);
    std::vector<int> left(vec.begin(),vec.begin()+middle);
    std::vector<int> right(vec.begin()+middle,vec.begin()+vec.size());
    
    left=merge_sort(left);
    right=merge_sort(right);
    
   
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;
    while (left_i < left.size() and right_i < right.size()) {
        if (left[left_i] < right[right_i]) {
            vec[buffer_i] = left[left_i];
            left_i += 1;
        } else {
            vec[buffer_i] = right[right_i];
            right_i += 1;
        }
        buffer_i += 1;
    }
    while (left_i < left.size()) { 
        vec[buffer_i] = left[left_i];
        left_i += 1;
        buffer_i += 1;
    }
    while (right_i < right.size()) { 
        vec[buffer_i] = right[right_i];
        right_i += 1;
        buffer_i += 1;
    }
    
    return vec;
        
}



int main()
{
    
    std::vector<int> arr = {2,7,1,4,-11,-5,0};
    std::vector<int> sorted = merge_sort(arr);
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}