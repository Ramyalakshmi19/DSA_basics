#include <iostream>
using namespace std;
int partition(int a[], int left, int right) {
  int pivot = a[right];  
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (a[j] <= pivot) {
      i++;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  int temp = a[i + 1];
  a[i + 1] = a[right];
  a[right] = temp;

  return i + 1;  
}
void quickSort(int a[], int left, int right) {
  if (left < right) {
    int pivotIndex = partition(a, left, right); 
    quickSort(a, left, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, right);
  }
}
int main() 
{
  int N;
  cout<<"Enter the number of elements:";
  cin>>N;
  int a[N]; 
  cout << "Enter " << N << " values:" << endl;
  for (int i = 0; i < N; i++)
   {
    cin >> a[i];
  }
  quickSort(a, 0, N - 1);
  cout << "Sorted array:" << endl;
  for (int i = 0; i < N; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}

