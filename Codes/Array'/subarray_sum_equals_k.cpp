#include <iostream>
#include <map>
#include <vector>

int getCount(std::vector<int> v, int k)
{
    int count = 0;
    int sum_till_now = 0;
    std::map<int, int> pre_sum;

    for(int i = 0; i<v.size(); i++)
    {
        sum_till_now+=v[i];

        if(sum_till_now == k)
            count+=1;
        
        if(pre_sum.find(sum_till_now - k) != pre_sum.end())
        {
            count+=pre_sum[sum_till_now - k];
        }

        pre_sum[sum_till_now] = pre_sum[sum_till_now] + 1; 
    }

    return count;
}