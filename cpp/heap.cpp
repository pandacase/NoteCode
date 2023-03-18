//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void swap(int* arr, int i, int j);


class Heap{
private:
    int* a;
    int capacity = 100;
    int size;

public:
    Heap(int arr[], int n){
        size = n;
        a = new int[n+1];
        for(int i = 1; i <= n; ++i){
            a[i] = arr[i-1];
        }
        build_heap();
    }

    void build_heap(){
        for(int i = size/2; i > 0; --i){
            heapify(i);
        }
    }

    void sort_heap(){
        int temp = size;
        while( size > 0 ){
            swap(a, 1, size);
            --size;
            heapify(1);
        }
        size = temp;
    }

    void heapify(int i){ //from root!
        while(1){
            int maxpos = i;
            if( 2*i <= size && a[i] < a[2*i] ) maxpos = 2*i;
            if( 2*i+1 <= size && a[maxpos] < a[2*i+1] ) maxpos = 2*i+1;
            if( i == maxpos ) break;
            swap(a, i, maxpos);
            i = maxpos;
        }
    }

    void push(int data){
        if(size >= capacity) return;
        ++size;
        a[size] = data;
        for(int i = size; i/2 > 0 && a[i/2] < a[i]; i = i/2)    swap(a, i, i/2);
    }

    void pop(){
        if(size == 0) return;
        a[1] = a[size];
        --size;
        heapify(1);
    }

    void print(){
        for(int i = 1; i <= size; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }

};

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}




int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    Heap heap(a, 10);
    heap.print();
    system("pause");
    return 0;
}