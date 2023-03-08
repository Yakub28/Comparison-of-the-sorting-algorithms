#include <iostream>
#include <vector>
#include <algorithm>

int setting(std::vector<int> &vec, int var1, int var2){
	
	int pivot = vec[var1+(var2-var1)/2];
	int new_var = var1;
	for(int i=var1;i<var2;++i){
		if(vec[i]<vec[pivot]){
			std::swap(vec[i],vec[new_var]);
			++new_var;
		}
	}
	std::swap(vec[new_var],vec[pivot]);
	return new_var;
}


void hybrid_quick_sort(std::vector<int> &vec, int var1, int var2)
{
  while (var1 < var2)
    {
    if (var2-var1 + 1 < 75)
      {
    for(int j = 1; j < vec.size(); j++)
    {
      int key = vec[j];
      int i = j-1;

      while(i >= 0 && vec[i] > key)
      {
         vec[i+1] = vec[i];
         i--;
      }
      vec[i+1] = key;
    }
      break;
      }
    else
        {
        int pivot = setting(vec,var1,var2);
      if (pivot-var1<var2-pivot)
        {
        hybrid_quick_sort(vec,var1, pivot - 1);
        var1 = pivot + 1;
      }
      else
        {
        hybrid_quick_sort(vec, pivot + 1, var2);
        var2 = pivot-1;
        }
     }
   }
}

int main()
{
    std::vector<int> vec={7,8,4,4,99,87,2,1,5,7,0,1};
    hybrid_quick_sort(vec,0,vec.size()-1);
     for(unsigned i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
