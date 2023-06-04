/*
Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell
data structure with modularity of programming language.
*/
#include <iostream>
using namespace std;

// Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int array_size;
    cout << "Enter the number of elements you want to enter: ";
    cin >> array_size;

    int arr[array_size]; // Declare the array with the specified size

    for (int i = 0; i < array_size; i++)
    {
        cin >> arr[i];
    }

    int n = array_size; // Use the array_size variable instead of sizeof

    cout << "Original array: ";
    printArray(arr, n);

    // Heap Sort
    heapSort(arr, n);
    cout << "Array after Heap Sort: ";
    printArray(arr, n);

    return 0;
}
