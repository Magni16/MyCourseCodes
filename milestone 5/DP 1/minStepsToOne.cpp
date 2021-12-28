#include<iostream>
#include<cmath>
using namespace std;


int countMinStepsToOne(int n)
{
	// first of all use recursion simply
    // base case
    if(n<=1){
        return 0;
    }
    
    // small-calculation
    int y = INT_MAX;
    int z = INT_MAX;
    int x = countMinStepsToOne(n-1);
    
    if(n%2 ==0){
         y = countMinStepsToOne(n/2);
    }
    
    if(n%3 ==0){
         z = countMinStepsToOne(n/3);
    }
    int ans =  min(x,min(y,z))+1;
    return ans;
}


int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
