#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <cstdio>

using namespace std;

int insertion_sort(int array[], int left, int right) {
    int assignments = 0;
    for(int i=left+1; i <= right; i++) {
        int val = array[i];
        int j=i;
        while((j > left) && (array[j-1] > val)) {
            array[j] = array[j-1];
            assignments++;
            j--;
        }
        array[j] = val;
        assignments++;
    }
    return assignments;
}

pair<int, int> partition(int array[], int left, int right) {
    int assignments = 0;
    int pivotValue = array[right];
    int storeIndex = left;
    for(int i=left; i < right; i++) {
        if(array[i] < pivotValue) {
            int temp = array[i];
            array[i] = array[storeIndex];
            array[storeIndex] = temp;
            assignments += 2;
            storeIndex++;
        }
    }
    int temp = array[right];
    array[right] = array[storeIndex];
    array[storeIndex] = temp;
    assignments += 2;
    return make_pair<int, int>(storeIndex, assignments);
}

int quicksort(int array[], int left, int right, int insertion_limit) {
    int assignments = 0;
    if(right - left + 1 <= insertion_limit) {
        assignments = insertion_sort(array, left, right);
    } else {
        if(left < right) {
            pair<int, int> partition_pair = partition(array, left, right);
            assignments += partition_pair.second;
            assignments += quicksort(array, left, partition_pair.first - 1, insertion_limit);
            assignments += quicksort(array, partition_pair.first + 1, right, insertion_limit);
        }
    }
    return assignments;
}

int main() {
    int n;
    cin >> n;
    int * A = new int[n];
    int * B = new int[n];
    int * C = new int[n];
    for(int i=0; i < n; i++) {
        cin >> A[i];
        B[i] = C[i] = A[i];
    }
    int left = 0;
    int right = n-1;
    int min = INT_MAX;
    int size = 0;
    for(int i=0; i <= n; i++) {
        memcpy(C, A, sizeof(int)*n);
        int hs = quicksort(C, left, right, i);
        if(hs < min) {
            min = hs;
            size = i;
        }
    }
    cout << size << endl << min << endl;
    for(int i=0; i < n; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
