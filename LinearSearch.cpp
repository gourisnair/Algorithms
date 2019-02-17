#include<iostream>
using namespace std;

int Search(int key, int a[10]) {
  for(int i = 0; i < 10; i++) {
    if(a[i] == key) {
      return 1;
    }
  }
}

int main()
{
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key;
  cin >> key;
  if(Search(key, a) == 1) {
    cout << "Key found\n";
  } else {
    cout << "Key not found\n";
  }

}
