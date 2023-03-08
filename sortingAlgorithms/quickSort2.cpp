#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>  quick_sort(std::vector<int> &vec,int var1, int var2){
    if(var1>=var2) 
    return vec;
    if(vec.size()<2){
        return vec;
    }
    if(vec.size()!=0){
        int left=var1;
        int right=var2;
        int pivot=vec[var1+(var2-var1)/2];
        while(left<=right){
            while(vec[left]<pivot)
            left++;
            while(vec[right]>pivot)
            right--;
            if(left<=right){
                std::swap(vec[left], vec[right]);
                left++;
                right--;
            }
        }
        if(var1<right)
        quick_sort(vec,var1,right);
        if(left<var2)
        quick_sort(vec,left,var2);
    }
    return vec;
}


int main()
{
    std::vector<int> v = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19 };
    quick_sort(v,0,v.size()-1);
    for(int i=0;i<v.size()-1;++i)
		std::cout<<v[i]<<" ";
	std::cout<<"\n\n";

    return 0;
}

