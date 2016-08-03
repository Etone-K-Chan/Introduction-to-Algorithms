#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//LINEAR-SEARCH

int linear_search(int array[], int n, int v);

int linear_search(int A[], int n, int v){
	for(int i=0; i<n; i++) {
        if(v == A[i]) {
            return i;
        }
    }
    return -1;
}

int main(){
    int array[100];
    int n = sizeof(array)/sizeof(int);
    srand(time(NULL));
    for(int i=0; i<n; i++){
        array[i] = rand();
    }
    int ret = linear_search(array, n, 17);

    printf("%d\n", ret);


    return 0;
}
