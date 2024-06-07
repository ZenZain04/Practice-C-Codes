#include <stdio.h>


void swapNum(int *num1, int *num2);
void printArray(int array[], int length);

int binarySearch(int array[], int key, int length);

int main(void) {
    int length, arrayVal, key, result;

    printf("Enter the number of elements :  ");
    scanf("%d", &length);
git init

    int array[length];

    for (int i = 0; i < length; ++i) {
        printf("Enter the value for index #%d : ", i + 1);
        scanf("%d", &arrayVal);

        array[i] = arrayVal;
    }

    printf("Original array:");
    printArray(array, length);

    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1])
                swapNum(&array[j], &array[j + 1]);
        }
    }

    printf("The sorted array:");
    printArray(array, length);

    printf("Enter the key to search : ");
    scanf("%d", &key);

    result = binarySearch(array, key, length);

    if(result == 0)
        printf("Specified key is not in the array!");
    else
        printf("The specified key was found at index #%d", result);

    return 0;
}

void swapNum(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printArray(int array[], int length) {
    printf("\n");
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int binarySearch(int array[], int key, int length) {

    int mid,low = 0;
    int high = length - 1;


    while (low <= high){
        mid = (low + high) / 2;

        if(array[mid] == key){
            return mid;
        } else if(array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
