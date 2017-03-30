//
//  main.cpp
//  SelectionSort using pass-by-reference
//
//  Created by Melinda Fernandes on 29/03/2017.
//  Copyright © 2017 Melinda Fernandes. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

void selectionSort(int * const, const int); // prototypes
void swap(int * const, int * const);

int main(){
    const int arraySize = 10;
    int a[arraySize] = {5,7,1,6,2,9,3,4,8,0};
    
    // print unsorted array
    cout << "The unsorted array: ";
    for(int i = 0; i < arraySize; i++)
        cout << a[i] << "  ";
    cout << endl;
    
    // call selectionSort on array
    selectionSort(a, arraySize);
    
    // print sorted array
    cout << "The sorted array: ";
    for(int i = 0; i < arraySize; i++)
        cout << a[i] << "  ";
    cout << endl;
    
    return 0;
} // end main

void selectionSort(int * const array, int const size){
    
    int smallest;
    
    for(int i = 0; i < size; i++){
        
        // set smallest index so far
        smallest = i;
        
        // search array for smallest
        for (int index = i+1; index < size; index++)
            if( array[index] < array[smallest])
                smallest = index;
        // once smallest in remaining array has been identified, swap with position array[i]
        swap(&array[i], &array[smallest]);
        
    } // end for
} // end function selectionSort

// information hiding between functions, so
// array elements are passed by reference (address of each array element is passed)
void swap(int *aPtr1, int *aPtr2){
    int placeholder = *aPtr1;
    *aPtr1 = *aPtr2;
    *aPtr2 = placeholder;
} // end function swap
