#include<stdio.h>
#include<stdlib.h>

struct Array {
    int* A;
    int size;
    int length;
};

void swap(int*, int*);
int linearSearch(Array*, int);
int binarySearch(Array*, int, int, int);

Array create(int);
int getLength(Array*);
int getSize(Array*);
int getData(Array*, int);
void dummyArray(Array*);
void display(Array*);
void add(Array*, int);
void deleteData(Array*);
void insert(Array*, int,int);
void remove(Array*, int);
void replace(Array*, int, int);
int isEmpty(Array*);
int getFirst(Array*);
int getLast(Array*);
void sort(Array*, int);
int isAsc(Array*);
int isDes(Array*);
int find(Array*, int);
void reverse(Array*,int);
void leftShift(Array*);
void rightShift(Array*);
void leftRotation(Array*);
void rightRotation(Array*);
void clearAll(Array*);
int sumAll(Array*);
int max(Array*);
int min(Array*);
float average(Array*);



int main()
{
    int s=20;
    struct Array arr;
    printf("Array concept\n");
    arr = create(s);

    //dummyArray(&arr);
    //insert(&arr, 3, 18);
    //insert(&arr, 8, 1);
    //remove(&arr, 5);
    //replace(&arr, 2, 4);
    //display(&arr);
    //reverse(&arr,0);
    //sort(&arr, 1);
    //rightRotation(&arr);
    //printf("Find in position: %d\n", find(&arr, 9));
    //sort(&arr, 0);
    //printf("min %d\n",min(&arr));
    //printf("average %f\n",average(&arr));
    //display(&arr);
    //sort(&arr, 0);
    //swap(&arr.A[2], &arr.A[3]);
    //printf("%d\n", getData(&arr, 0));
    //display(&arr);
    //printf("length of array %d\n", getLength(&arr));
    return 0;
}

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//create an array by providing size of an array.
Array create(int s) {
    struct Array arr;
    arr.A = (int*)malloc(s * sizeof(int));
    arr.size = s;
    arr.length = 0;
    return arr;
}

//get lenght of an array.
int getLength(Array* arr) {
    return arr->length;
}

//get size of an array.
int getSize(Array* arr) {
    return arr->size;
}

//get data from an index.
int getData(Array* arr, int index) {
    if (!isEmpty(arr)) {
        if (index >= 0 && index < arr->length - 1) {
            return arr->A[index];
        }
        else {
            printf("Array IndexOutOfBound! ");
            return -1;
        }
    }
    else {
        printf("array is empty ");
        return -1;
    }
}

//creating array with dummy data of length 6.
void dummyArray(Array* arr) {
    for (int i = 0; i < 16; i++) {
        arr->A[i] = i + (i + 3);
        arr->length++;
    }
}

//displaying an array
void display(Array *arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

//add/append data in array
void add(Array *arr, int data) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = data;
        arr->length++;
    }
    else {
        printf("no space for new data!\n");
    }
}

//remove/delete data from last index.
void deleteData(Array* arr) {
    if (arr->length > 0) {
        arr->A[arr->length - 1] = 0;
        arr->length--;
    }
    else {
        printf("array is empty\n");
    }
}

//insert data in given index.
void insert(Array* arr, int index,int data) {
    if (index >= 0 && index < arr->size-1) {
        for (int i = arr->length; i >= index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = data;
        arr->length++;
    }
    else {
        printf("Array IndexOutOfBound!\n");
    }
}

//delete data in a given index.
void remove(Array* arr, int index) {
    if (index >= 0 && index < arr->length - 1) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    else if (index >= arr->length && index<arr->size) {
        printf("not necessary\n");
    }
    else {
        printf("Array IndexOutOfBound!\n");
    }
}

//replace data in a given index with new data.
void replace(Array* arr, int index, int data) {
    if (index >= 0 && index < arr->length - 1) {
        arr->A[index] = data;
    }
    else {
        printf("Array IndexOutOfBound!\n");
    }
}

int isEmpty(Array* arr) {
    if (arr->length > 0) {
        return 0;
    }
    else {
        return 1;
    }
}

//get first element in a given array
int getFirst(Array* arr) {
    if (!isEmpty(arr)) {
        return arr->A[0];
    }
    else {
        printf("empty array\n");
        return -1;
    }
}

//get last element in a given array.
int getLast(Array* arr) {
    if (!isEmpty(arr)) {
       return arr->A[arr->length - 1];
    }
    else {
        printf("empty array\n");
        return -1;
    }
}

//sort an array.(using bubble sort technique)
void sort(Array* arr, int isAsc) {
    if (isAsc) {
        //ascending order
        for (int i = 0; i < arr->length; i++) {
            for (int j = 0; j < arr->length - 1 - i; j++) {
                if (arr->A[j] > arr->A[j + 1]) {
                    swap(&(arr->A[j]), &(arr->A[j + 1]));
                }
            }
        }
    }
    else {
        //decending order
        for (int i = 0; i < arr->length; i++) {
            for (int j = 0; j < arr->length - 1 - i; j++) {
                if (arr->A[j] < arr->A[j + 1]) {
                    swap(&(arr->A[j]), &(arr->A[j + 1]));
                }
            }
        }

    }
}

int isAsc(Array* arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        if ((arr->A[i]) > (arr->A[i + 1])) {
            return 0;
        }
    }
    return 1;
}

int isDes(Array* arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        if (arr->A[i] < arr->A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

//find/searh a key in given array
int find(Array* arr, int key) {
    if (isAsc(arr)) {
        //perform binary search.
        printf("using binary search algorithm\n");
       return binarySearch(arr, 0, arr->length - 1, key);
    }
    else {
        //perform linear search.
        printf("using linear search algorithm\n");
        return linearSearch(arr, key);
    }
}

//linear search (cond.. any type of arry sorted or unsorted)
int linearSearch(Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            printf("Successful search ");
            return i;
        }
    }
    printf("Unsuccessful search ");
    return -1;
}

//binary search (cond.. must be sorted)
int binarySearch(Array* arr,int l,int h,int key) {
    int m = (l + h) / 2;
    if (l <= h) {
        if (arr->A[m] == key) {
            printf("Successful search ");
            return m;
        }
        else if (arr->A[m] > key) {
            h = m - 1;
            return binarySearch(arr, l, h, key);
        }
        else {
            l = m + 1;
            return binarySearch(arr, l, h, key);
        }
    }
    else {
        printf("Unsuccessful search ");
        return -1;
    }
}

//reverse an array.
void reverse(Array* arr,int smart) {
    if (smart) {
        printf("reversing array using smart technique\n");
        for (int i = 0,j = arr->length - 1; i < arr->length / 2; i++, j--) {
            swap(&(arr->A[i]), &(arr->A[j]));
        }
    }
    else {
        printf("reversing array using normal technique\n");
        struct Array tempArr;
        tempArr = create(arr->size);

        for (int i = 0, j = arr->length-1; i < arr->length; i++, j--) {
            tempArr.A[i] = arr->A[j];
        }
        for (int i = 0; i < arr->length; i++) {
            arr->A[i] = tempArr.A[i];
        }

        free(tempArr.A);
        tempArr.A = NULL;
    }
}

//left shift an array by one index.
void leftShift(Array* arr) {
    for (int i = 0; i < arr->length-1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = -1;
}

//right shift an array by one index.
void rightShift(Array* arr) {
    for (int i = arr->length-1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = -1;
    
}

//left rotation an array by unit index.
void leftRotation(Array* arr) {
    int temp;
    temp = arr->A[0];
    for (int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

//right rotation an array by unit index.
void rightRotation(Array* arr) {
    int temp = arr->A[arr->length - 1];
    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = temp;
}

//delete all element in an array.
void clearAll(Array* arr) {
    arr->length = 0;
}

//sum of all data
int sumAll(Array* arr) {
    int s = 0;
    for (int i = 0; i < arr->length; i++) {
        s += arr->A[i];
    }
    return s;
}

//find max element in given array
int max(Array* arr) {
    int m,temp;
    m = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (m < arr->A[i]) {
            m = arr->A[i];
        }
    }
    return m;
}

//find min element in a given array.
int min(Array* arr) {
    int m, temp;
    m = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (m > arr->A[i]) {
            m = arr->A[i];
        }
    }
    return m;
}

//find average value in a given array.
float average(Array* arr) {
    if (!isEmpty(arr)) {
        float s = 0;
        for (int i = 0; i < arr->length; i++) {
            s += arr->A[i];
        }
        return s / arr->length;
    }
    else {
        printf("empty array\n");
    }
}

