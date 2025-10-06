#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  //elemen-element left
    int n2 = right - mid;    //elemen-elemen right


    vector<int> L(n1), R(n2); 


    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; //elemen-elemen left dimasukkan ke array
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; //elemen-elemen right dimasukkan ke array


    int i = 0;    
    int j = 0;      
    int k = left;

    //mengurutkan elemen dari kedua ruas yang sudah dibagi
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; 
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    } //apabila ada sisa di left maka akan masuk ke arr


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    } //apabila ada sisa di right maka akan masuk ke arr
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right)
        return; //jika banyak elemen 0 ataupun 1 maka akan kembali ke program main


    int mid = left + (right - left) / 2;


    mergeSort(arr, left, mid); //membagi elemen di mid pertama
    mergeSort(arr, mid + 1, right); //membagi elemen di mid kedua
   
    merge(arr, left,mid,right);
}

//fungsi unutuk menampilkan elemen-elemen data
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n); //mendeklarasikan array dinamis bertipe integer sebanyak n
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i]; //menginput elemen-elemen ke dalam array
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1); //proses sorting
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}