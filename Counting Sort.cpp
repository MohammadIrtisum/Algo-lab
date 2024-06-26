#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
   
    int maxElement = *max_element(arr.begin(), arr.end());

    
    vector<int> count(maxElement + 1, 0);

    
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

   
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Given array is: \n";
    printArray(arr);

    countingSort(arr);

    cout << "\nSorted array is: \n";
    printArray(arr);

    return 0;
}
