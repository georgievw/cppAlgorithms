#include <iostream>
#include <algorithm>

using namespace std;

int* inputArray(int);
void printArray(int*, int);
float simpleMinDistance(int*, int, int);

int main()
{
   int n, l;
   cin >> n >> l;
   int* array = inputArray(n);
   sort(array, array+n);
   float result = simpleMinDistance(array, n, l);
   cout << result << endl;
   delete [] array;
   return 0;
}

float simpleMinDistance(int* array, int n, int l)
{
    float max_dist = array[0];
    if (l - array[n-1] > max_dist) 
    {
        max_dist = l - array[n-1];
    }
    for (int i = 1; i < n; i++)
    {
        if (array[i] - array[i-1] > 2*max_dist)
        {
            max_dist = float(array[i] - array[i-1]) / 2;
        }
    }
    return max_dist;
}

int* inputArray(int n)
{
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    return array;
}

void printArray(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}