#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int i = low - 1;
    int j = low;
    for(j; j < high; j++){
        if(arr[j] < arr[high]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}


void quicksort(int arr[], int low, int high){
    if(low >= high) return;
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
}

void print_arr(int arr[], int len, const char* str){
    printf("Array (%s) | len: %d | {", str, len);
    for(int i = 0; i < len; i++)
        printf("%d%s", arr[i], i == len - 1 ? "}" : ", ");
    printf("\n");
}


int main(int argc, char** argv){
    int arr[] = {7, 3, 9, 1, 8, 6, 4, 2, 0, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, len, "Unsorted");
    quicksort(arr, 0, len - 1);
    print_arr(arr, len, "Sorted");


    return 0;
}