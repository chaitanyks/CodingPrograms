#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    if(n==1){
	    cout<<0<<endl;
	    continue;
	        
	    }
	    else if(n==2)
	    {
	        cout<<1<<endl;
	        continue;
	    }
	    else if(n==3)
	    {
	        cout<<2<<endl;
	        continue;
	    }
	    
	    if(n%2==0)
	    {
	        cout<<2<<endl;
	    }
	    else
	    {
	        cout<<3<<endl;
	    }
	    
	}
	return 0;
}
