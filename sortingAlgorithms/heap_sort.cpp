#include <iostream>
#include <vector>
#include <algorithm>

void heap_create(std::vector<int> &arr, int size, int root) {
    int child_left = 2 * root+ 1;
    int child_right = child_left+1;
    
    int val_max = root;
    
    if (child_right<size && arr[child_right] > arr[val_max])
        val_max = child_right;
    
    if (child_left < size && arr[child_left] > arr[val_max])
        val_max = child_left;
        
    if (val_max != root) {
        std::swap(arr[root],arr[val_max]);

        heap_create(arr, size, val_max);
    }
}

std::vector<int> heap_sort(std::vector<int> &vec) {
    int size = vec.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heap_create(vec, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        std::swap(vec[0],vec[i]);
        heap_create(vec, i, 0);
    }
    return vec;
}

int main() {
    std::vector<int> arr = {12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
    std::vector<int> sorted=heap_sort(arr);
    for(int i=0;i<sorted.size();i++){
        std::cout<<sorted[i]<< " ";
    }
}