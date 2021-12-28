#include <iostream>
using namespace std;


long staircase(int n)
{
    
    long a[n+1];
     
    a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=4;
 
        // dp iteration starting from i =4
        for(int i=4 ;i<=n ;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
    
    return a[n];
    
}


int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}