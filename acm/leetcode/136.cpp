#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#include <bitset>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	
       bitset<64> b;
       int res = 0;
       for (int i = 0; i < nums.size(); ++i)
       {
       		//b[nums[i]] = b[nums[i]] ^ 1;
       		res = res^nums[i];
       }/*
       cout << b << endl;
       for (int i = 0; i < 64; ++i)
       {
       		if(b[i]) res = i;
       }*/
       return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	int tmp[]={1,-6,5,4,1,2,4,2,3,3,5};
	std::vector<int> v(tmp,tmp+11);
	

	printf("%d\b", s.singleNumber(v));
	
	return 0;
}