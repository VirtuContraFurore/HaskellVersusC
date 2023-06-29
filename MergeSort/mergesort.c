#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

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
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
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

    mergeSort(data, 0, data_idx-1);

    // Print stuffy stuff
    printf("[");
    for(int i = 0; i < data_idx; i++)
        printf("%d,", data[i]);
    printf("]\n");

    free(data);
}
