#include <bits/stdc++.h>
using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
       
        int pi = partition(arr, low, high);

       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Given array is: \n";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array is: \n";
    printArray(arr);

    return 0;
}