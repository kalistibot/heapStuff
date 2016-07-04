//
//  main.cpp
//  heapify
//
//  Created by Aaron on 4/5/16.
//  Copyright © 2016 Aaron. All rights reserved.
//


#include <iostream>
#include <new>
using namespace std;


void max_heapify(int *A, int root, int n)
{
    int lchild, rchild, largest;
    lchild = left(root);
    rchild = right(root);
    if (lchild<n-1 && A[lchild]>A[root])
        largest = A[lchild];
    else
        largest = A[root];
    if (rchild<n-1 && A[rchild]>A[root])
        largest = A[rchild];
    if (largest != root)
    {
        swap(A[largest], A[root]);
        max_heapify(A, largest, n);
    }
}


void heapsort(int a[], int size){
    int sorted[size];
    int temp;
    for (int i = 0; i < size ; i++){
        max_heapify(a,i, size/2);
        sorted[i] =a[0];
        a[0]=a[size-1];
        
        size--;
        temp=size;
    }
}

void heapbuild(int *A, int n)
{
    for (int i=n/2; i>=0; i--)
    {
        max_heapify(A, i, n);
    }
}


int main()
{
 
    int arraySize = 0;
    int * heapPtr;
    char choice;
    cout << "Do you want to make a heap? y/n";
    cin >> choice;
    
    while (choice =='y'){
    
        cout <<"Enter the size of the array to be sorted: ";
        cin>> arraySize;
        cin.clear();
        heapPtr = new int [arraySize];
        cout <<"Now enter "<< arraySize << " integers: ";
        for( int i = 0; i<arraySize;i++){
            cin>> heapPtr[i];
            cin.clear();
        }
    
    
       /* for (int i = arraySize; i >= 0;i--){
            heapsort(heapPtr, arraySize);
        }
        */
        heapbuild(heapPtr,arraySize);
    
        for(int i=0; i<arraySize; i++) cout<<heapPtr[i]<<" ";
    
        cout<<endl;
    
        delete heapPtr;
     
        cout << "Heap again? y/n";
        cin >> choice;
    }
    return 0;
}

