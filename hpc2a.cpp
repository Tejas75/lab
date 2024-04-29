#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <chrono>

using namespace std;
void bubble(int *, int);
void swap(int &, int &);

void bubble(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int first = i % 2;

        #pragma omp parallel for shared(a, first)
        for (int j = first; j < n - 1; j += 2)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}



void obubble(int array[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
        }
    }
}


int main()
{
    int *a, n;
    cout << "\n Enter total number: ";
    cin >> n;
    a = new int[n];
    cout << " Enter number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    // parallel bubble sort
    auto start = std::chrono::high_resolution_clock::now();
    bubble(a, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " nanoseconds" <<std::endl;

   cout << " Sorted array: ";
    for (int i = 0; i < n; i++)  {
        cout << a[i] << " ";
    }

    cout<<endl;
    
    // sequential bubble sort
    auto start1 = std::chrono::high_resolution_clock::now();
    obubble(a, n);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<chrono::nanoseconds>(end1 - start1);
    std::cout << "Execution time: " << duration1.count() << " nanoseconds" << endl;


    cout << " Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
