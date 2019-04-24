#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s[20],f[20];
	cout<<"Enter the total number of activities: ";
	cin>>n;
	cout<<"Enter the start time and finish time of "<<n<<" activities\n";
	s[0]=f[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>f[i];
	}
	int i, j;
	cout<<"Following activities are selected: ";
	i = 1;
	cout<<i;
	for (j = 2; j<=n; j++)
    	{
      		if (s[j] >= f[i])
      		{
          		cout<<j;
          		i = j;
      		}
    	}
	return 0;
}
