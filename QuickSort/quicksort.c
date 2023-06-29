#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    FILE *myFile;
    myFile = fopen("input.txt", "r");

    int * data = (int *) malloc(10000000*sizeof(int));
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

    quickSort(data, 0, data_idx);

    // Print stuffy stuff
    printf("[");
    for(int i = 0; i < data_idx; i++)
        printf("%d,", data[i]);
    printf("]\n");

    free(data);
}
