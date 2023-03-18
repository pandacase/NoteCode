#include<bits/stdc++.h>
using namespace std;

int	ans = 0;
void calculation(int* arr, int size);
void merge(int* arr, int low, int mid, int high, int size);
void sort(int* arr, int low, int high, int size);


void calculation(int* arr, int size){
    sort(arr, 0, size-1, size);
}

void merge(int* arr, int low, int mid, int high, int size){
    int aux[size];
    for(int k = low; k <= high; ++k){
        aux[k] = arr[k];
    }
    for(int i = low; i <= mid; ++i){
    	for(int j = mid + 1; j <= high; ++j){
    		if(aux[i] > aux[j])	ans+=1;
		}
	}

}

void sort(int* arr, int low, int high, int size){
    if(low >= high) return;
    int mid = low + (high - low)/2;
    sort(arr, low, mid, size);
    sort(arr, mid + 1, high, size);
    merge(arr, low, mid, high, size);
}

int main(){
    int n;
    while(cin >> n){
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        ans = 0;
        calculation(arr, n);
        cout << ans << endl;
    }
}
