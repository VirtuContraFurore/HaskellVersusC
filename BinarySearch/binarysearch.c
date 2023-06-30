#include <stdio.h>
#include <stdlib.h>

int recursiveBinarySearch(int array[], int left, int right, int element){
    if (right >= left){
        int middle = left + (right - left)/2;
        if (array[middle] == element)
            return middle;
        else if (array[middle] > element)
            return recursiveBinarySearch(array, left, middle-1, element);
        else
            return recursiveBinarySearch(array, middle+1, right, element);
   }
   return -1;
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
    int data_to_find;

    char * line = NULL;  // init to NULL is VERY important, see $man getline
    size_t len;
    ssize_t read;

    if((read = getline(&line, &len, myFile)) != -1){
        int d = atoi(line);
        data_to_find = d;
    } else {
        printf("Error reading file");
        return;
    }

    while((read = getline(&line, &len, myFile)) != -1){
        if(len > 1){
            int d = atoi(line);
            data[data_idx++] = d;
        }
    }

    int ret = recursiveBinarySearch(data, 0, data_idx, data_to_find);

    if(ret == -1){
        printf("Not found \n");
    } else {
        printf("Just %d\n", ret);
    }

    free(data);
}
