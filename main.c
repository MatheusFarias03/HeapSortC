/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Matheus Farias de Oliveira Matsumoto
 *
 * Created on May 24, 2022, 6:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printArray(int* myArray, int arraySize){
    for (int i = 1; i < arraySize; i++) {
        printf("%i ", myArray[i]);
    }
}


void swap(int* myArray, int i, int j){
    myArray[i] = myArray[j] - myArray[i];
    myArray[j] = myArray[j] - myArray[i];
    myArray[i] = myArray[j] + myArray[i];
}


void ascend(int* myArray, int child, int parent){
    
    while (parent >= 0) {
            if (myArray[child] > myArray[parent]) {
                swap(myArray, child, parent);
            }
            child = parent;
            parent = (int)(floor((child+1)/2)-1);
    }
}


void descend(int* myArray, int finalPos, int i) {
    
    int largest = i;
    int childLeft = 2 * largest + 1;
    int childRight = 2 * largest + 2;
    
    if (childLeft < finalPos && myArray[childLeft] > myArray[largest])
        largest = childLeft;
    if (childRight < finalPos && myArray[childRight] > myArray[largest])
        largest = childRight;
    
    if (largest != i) {
      swap(myArray, i, largest);
      descend(myArray, finalPos, largest);
    }
}


void heapSort(int* myArray, int arraySize) {
    
    for (int i = 1; i < arraySize; i++) {
        
        int child = i;
        int parent = (int)(floor((i+1)/2)-1);
        
        ascend(myArray, child, parent);
    }

    for (int finalPos = arraySize-1; finalPos >= 0; finalPos--) {
        
        swap(myArray, finalPos, 0);
        descend(myArray, finalPos, 0);    
    }
}


int main(int argc, char** argv) {
    
    // User input
    int arraySize;
    printf("Type the size of the array : ");
    scanf("%d", &arraySize);
    arraySize++;

    // Variable sized array
    int* myArray = malloc(sizeof(int) * arraySize);
    
    // Random number allocation
    srand(time(0));
    for (int i = 0; i < arraySize; i++) {
        if (i == 0)
            myArray[i] = 0;
        else
            myArray[i] = rand() % 100;
    }
    
    printf("Unordered array : ");
    printArray(myArray, arraySize);
    
    printf("\nHeapSort : ");
    heapSort(myArray, arraySize);
    printArray(myArray, arraySize);
    
    // Free array from memory
    free(myArray);
    
    return (EXIT_SUCCESS);
}

