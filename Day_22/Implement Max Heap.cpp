#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
private:
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    vector<int> heap;
    void insert(int val) {
        heap.push_back(val);
        int child = heap.size() - 1;

        while(child > 0) {
            int parent = (child - 1) / 2; 
            if(heap[parent] < heap[child]) {
                swap(heap[parent], heap[child]);
                child = parent;
            } else {
                break;
            }
        }
    }

    int deleteMax() {

        if(heap.empty())
            return -1;

        int maxElement = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        int index = 0;

        while(true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if(left < heap.size() &&
            heap[left] > heap[largest]) {
                largest = left;
            }

            if(right < heap.size() &&
            heap[right] > heap[largest]) {
                largest = right;
            }

            if(largest == index)
                break;

            swap(heap[index], heap[largest]);

            index = largest;
        }

        return maxElement;
    }

    void buildHeap(vector<int> &arr) {
        int n = arr.size();
        for(int i = (n / 2) - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
};

int main() {

    MaxHeap h;

    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(60);
    cout << "Insertion of elements : ";
    for(int x : h.heap)
        cout << x << " ";
    
    cout << endl;
    cout << "Extract Max : ";
    h.deleteMax();
    for(int x : h.heap)
        cout << x << " ";

    cout << endl;
    vector<int> arr = {10, 5, 20, 2, 4};

    cout << "Build heap : ";
    
    h.buildHeap(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}