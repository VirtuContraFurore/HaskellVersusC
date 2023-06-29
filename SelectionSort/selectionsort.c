#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    FILE *myFile;
    myFile = fopen("input.txt", "r");

    int * data = (int *) malloc(100000000*sizeof(int));
    if( data == NULL ){
        printf("Malloc failure");
        exit(-1);
    }

    int data_idx = 0;

    char * line;
    size_t len;
    ssize_t read;

    while((read = getline(&line, &len, myFile)) != -1){
        int d = atoi(line);
        data[data_idx++] = d;
    }

    selectionSort(data, data_idx);

    // Print stuffy stuff
    printf("[");
    for(int i = 0; i < data_idx; i++)
        printf("%d,", data[i]);
    printf("]\n");

    free(data);
}
