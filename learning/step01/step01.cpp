#include <iostream>

using namespace std;

int main () {
  int N;
  cout << "This is a simple program in C++\n";
  cout << "Enter a small integer: ";
  cin >> N;
  cout << "\nThe squares and cubes of the first " << N << " numbers are:\n";
  for (int i=1; i<N+1; i++) {
    cout << "Number: " << i << ". Square: " << i*i << ". Cube: " << i*i*i << endl;
  }
  return 0;
}