/*
Madushan Rajendran
22/03/2024
This is program has different types of sorting
*/

#include <iostream>
using namespace std;

class SelectionSort{
public:
    void selectionSort(int a[],int n){
        int min;

        for (int i = 0;i<n;i++){
            min = i;
            for (int j=i+1;j<n;j++){
                if (a[j]<a[min])
                    min = j;
            }
            if (min !=i)
                swap(a[min],a[i]);
        }

        cout << "\nArray after Selection sorting;"<<endl;
        for (int i=0;i<n;i++){
            cout << a[i]<<" ";
        }
    }
};

class MergeSort{
public:
    void merge(int a[], int const left, int const mid,int const right)
    {
        int const a1 = mid - left + 1;
        int const a2 = right - mid;

        auto *leftArray = new int[a1],*rightArray = new int[a2];

        for (auto i = 0; i < a1; i++)
            leftArray[i] = a[left + i];
        for (auto j = 0; j < a2; j++)
            rightArray[j] = a[mid + 1 + j];

        auto ia1 = 0, ia2 = 0;
        int ima = left;

        while (ia1 < a1 && ia2 < a2) {
            if (leftArray[ia1] <= rightArray[ia2]) {
                a[ima] = leftArray[ia1];
                ia1++;
            }
            else {
                a[ima] = rightArray[ia2];
                ia2++;
            }
            ima++;
        }


        while (ia1 < a1) {
            a[ima] = leftArray[ia1];
            ia1++;
            ima++;
        }

        while (ia2 < a2) {
            a[ima] = rightArray[ia2];
            ia2++;
            ima++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

    void mergeSort(int a[], int const begin, int const end)
    {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }

    void printArray(int a[], int size)
    {
        cout << "\nArray after Merge sorting;"<<endl;
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
    }
};


class QuickSort{`
public:
 int partitionQuickSort(int a[],int start,int end){
    int pivot = a[start];

    int count = 0;
    for (int i = start+1;i<=end;i++){
        if (a[i]<=pivot)
            count++;
    }

    int pivotI = start+count;
    swap(a[pivotI],a[start]);

    int i = start,j=end;

    while (i<pivotI && j> pivotI){
        while (a[i]<= pivot){
            i++;
        }
        while (a[j]>pivot){
            j--;
        }

        if (i<pivotI&& j>pivotI){
            swap(a[i++],a[j--]);
        }
    }
    return pivotI;
}

 void quickSort(int a[],int start,int end){
    if (start>=end)
        return;
    int p = partitionQuickSort(a,start,end);
    quickSort(a,start,p-1);
    quickSort(a,p+1,end);

}

    void printArray(int a[], int size)
    {
        cout << "\nArray after Quick sorting;"<<endl;
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
    }

};

class HeapSort{
public:

    void shiftDown(int key, int a[], int root, int last) {
        int larger = 2 * root;
        while (larger <= last)
        {
            if ((larger +1 <= last) && (a[larger+1] > a[larger]))
                larger++;
            if (key >= a[larger])
                break;
            a[root] = a[larger];
            root = larger;
            larger = 2 * root;
        }
        a[root] = key;

    };

    void heapSort(int a[], int n)
    {
        for (int h = n/2; h >= 1; h--)
            shiftDown(a[h], a, h, n);
        for (int k = n; k > 1; k--)
        {
            int item = a[k];
            a[k] = a[1];
            shiftDown(item, a, 1, k-1);
        }
    };
    void printArray(int a[], int size)
    {
        cout << "\nArray after Heap sorting;"<<endl;
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
    }

};



int main() {
    cout << "--------------------------------" << endl;
    int a1[]={6,9,4,8,7};
    cout << "Array before sorting;"<<endl;
    int n = sizeof(a1) / sizeof(a1[0]);
    for (int i=0;i<n;i++){
        cout << a1[i]<<" ";
    }
    SelectionSort S;
    S.selectionSort(a1,n);

    cout << "\n--------------------------------" << endl;
    int a2[]={6,9,4,8,7};
    cout<< "Array before sorting;"<<endl;
    for (int i=0;i<n;i++){
        cout << a2[i]<<" ";
    }
    MergeSort M;
    M.mergeSort(a2,0,n-1);
    M.printArray(a2,n);

    cout << "\n--------------------------------" << endl;
    int a3[]={6,9,4,8,7};
    cout<< "Array before sorting;"<<endl;
    for (int i=0;i<n;i++){
        cout << a3[i]<<" ";
    }
    QuickSort Q;
    Q.quickSort(a3,0,n-1);
    Q.printArray(a3,n);

    cout << "\n--------------------------------" << endl;
    int a4[]={6,9,4,8,7};
    cout<< "Array before sorting;"<<endl;
    for (int i=0;i<n;i++){
        cout << a4[i]<<" ";
    }
    HeapSort H;
    H.heapSort(a4,n);
    H.printArray(a4,n);
    cout << "\n--------------------------------" << endl;
    return 0;
}
