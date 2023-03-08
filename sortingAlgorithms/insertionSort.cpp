#include <vector>
#include <iostream>

void insertion_sort(std::vector<int>& list)
{
    for(unsigned int  i = 1; i <list.size(); i++)
    {
      int new_var = list[i];
      int j= i-1;

      while(j >= 0 && list[j] > new_var)
      {
         list[j+1] = list[j];
         j--;
      }
      list[j+1] = new_var;
    }
}
int main(){
    std::vector<int> arr = {690, 640, 382, 2, -9,1, 39};
   insertion_sort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
