#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=================================swap================================
void swap(int *a, int *b);
void swap(int *a, int *b) {
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
//=================================INSERTION-SORT================================

//pseudo code
//INSERTION-SORT(A)
//for j = 2 to A.length
//    key = A[j]
//    //insert A[j] into the sorted sequence A[1...j-1]
//    i = j-1
//    while i>0 and A[i]>key
//        A[i+1] = A[i]
//        i = i-1
//    A[i+1] = key

void insertion_sort(int A[], int n);

void insertion_sort(int A[], int n){
    int i,j;
    int key;
    for(j=1; j<n; j++){
        key = A[j];
        i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}

//=================================SELECTION-SORT================================

//pseudo code
//SELECTION-SORT(A)
//for j = 1 to A.length-1
//    min = A[j]
//    //insert A[j] into the sorted sequence A[1...j-1]
//    i = j+1
//    while i<A.length and A[i]<min
//        min = A[i]
//        i = i+1
//    swap(min, a[j])

void selection_sort(int A[], int n);

void selection_sort(int A[], int n){
    int i,j, iter;
    int tmp;
    for(j=0; j<n-1; j++){
        iter = j;
        i = j+1;
        while(i<n){
            if(A[i] < A[iter]) {
                iter = i;
            }
            i = i+1;
        }
        if(j != iter) {
 /*           tmp = A[j];
            A[j] = A[iter];
            A[iter] = tmp;*/
            swap(&A[iter], &A[j]);
        }
    }
}

int main(){
    int array[100];
    int n = sizeof(array)/sizeof(int);
    srand(time(NULL));
    printf("\nBefore sort:\n");
    for(int i=0; i<n; i++){
        array[i] = rand();
        printf("%d ", array[i]);
    }
    //insertion_sort(array, n);
    selection_sort(array, n);
    printf("\nAfter sort:\n");
   
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }

    for(int i=0;i<n-1;i++){
        if(array[i]>array[i+1]){
            printf("failed\n");
            return -1;
        }
    }
    return 0;
}
