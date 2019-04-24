#include<iostream>
using namespace std;
int main()
{
  int s[10], f[10], n, i;
  s[0] = f[0] = 0;
  cout << "Enter the number of activities: ";
  cin >> n;
  cout << "Enter the starting and ending time: ";
  for(i = 1; i <= n; i++) {
    cin >> s[i];
    cin >> f[i];
  }
  i = 0;

  cout << "The selected activities are: ";
  cout << i;
  for(int j = 2;j <= n; j++) {
    if(s[j] >= f[i]) {
      cout << j;
      i = j;
    }
  }
}
