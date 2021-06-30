#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    NOTE: THIS IS STILL INCOMPLETE AND WRONG
*/


// This approach is wrong, because if I want to pick (n-2)th element, I have to pick (n-1)st element too (like a subarray)
// I cannot distinctively choose from either left or right
// If I choose 3rd element, I have to pick 1st, 2nd and 3rd
int solve_f(vector<int> A, int B) {
    
   int left = 0, right = A.size()-1, sum = 0;
   int count = 0;
   cout << A.size() << endl;
   while(left<=right || B <= A.size() -1 )
   {

        if(count == B)
            return sum;
    
       if(A[left] >= A[right])
       {
           sum+=A[left];
           left+=1;
       }
       else if(A[right] > A[left])
       {
           sum+=A[right];
           right-=1;
       }

       count+=1;
   }

   return sum;
}


int solve(vector<int> A, int B)
{
    // If B > A.size()/2, then we are always gonna access some elements

    int m_l = 0, m_r = 0, count = 0, sum = 0;

    if(B > A.size()/2)
    {   
        m_l = A.size() - B;
        m_r = B;

        while(m_l<=m_r || B <= A.size() -1 )
        {

            if(count == B)
                return sum;

            if(A[m_l] >= A[m_r])
            {
                sum+=A[m_l];
                m_l+=1;
            }
            else if(A[m_r] > A[m_l])
            {
                sum+=A[m_r];
                m_r-=1;
            }

            count+=1;
        }
    }


}

int main ()
{
    cout << solve({-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35}, 48) << endl;
}