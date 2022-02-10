#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
public:

    void Heapify(vector<int> &arr) {
        int n = arr.size();
        for (int i = n / 2; i >= 0; i--) {
            Adjust(arr, i, n);
        }
    }

    // heap size if from 0 to n-1
    void Adjust(vector<int> &arr, int i, int n) {
        int j = 2 * i;
        int value = arr[i];
        while (j < n) {
            if (j < n - 1 && arr[j] < arr[j + 1])
                j = j + 1;
            if (value >= arr[j])
                break;

            arr[j / 2] = arr[j];
            j = 2 * j;
        }
        arr[j / 2] = value;
    }

    void HeapSort(vector<int> &arr) {
        int n = arr.size();
        Heapify(arr);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            Adjust(arr, 0, i);
        }
    }
    
    void DeleteMax(vector<int> &arr) {
        int n = arr.size();
        arr[0] = arr[n-1];
        arr.resize(n-1);
        Heapify(arr);
    }
    
    void Insert(vector<int> &arr, int value) {
        int n = arr.size();
        arr.resize(n+1);
        arr[n] = value;
        
        int j = (n+1)/2;
        
        while(j>0 && arr[j]<value)
        {
            arr[2*j] = arr[j];
            j = j/2;
        }
        
        arr[j*2] = value;
    }

    void Print(vector<int> &arr) {
        for (int i:arr)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    // your code goes here
    vector<int> arr = {2, 3, 6, 5, 9, 8, 1, 4, 2, 3, 6, 5, 9, 8, 1, 4};
    vector<int> heapArr = arr;
    MaxHeap maxHeap;
    cout << "Original array:" << endl;
    maxHeap.Print(arr);

    cout << "Heapify array:" << endl;
    maxHeap.Heapify(arr);
    maxHeap.Heapify(heapArr);
    maxHeap.Print(arr);

    cout << "HeapSort array:" << endl;
    maxHeap.HeapSort(heapArr);
    maxHeap.Print(heapArr);
    
    cout << "Delete rootMax array:" << endl;
    maxHeap.DeleteMax(arr);
    maxHeap.Print(arr);
    
    cout << "Delete rootMax array:" << endl;
    maxHeap.DeleteMax(arr);
    maxHeap.Print(arr);
    
    cout << "Insert 12 array:" << endl;
    maxHeap.Insert(arr,12);
    maxHeap.Print(arr);
    

    return 0;
}
