#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void shift_element(int* arr, int i);
void printArray(int* arr);

void shift_element(int* arr,int i){

    while(i>=0){
        *(arr+i+1) = *(arr+i);
        i--;
    }
}

void insertion_sort(int* arr , int len){
    int j;
    for(int i=1;i<len;i++){
        int temp = *(arr+i);
        j = -1; 
        do{
            ++j;
        }
        while(temp>*(arr+j));
        shift_element(arr+j-1,i-j);
        *(arr+j)=temp;
        
    }
}
void printArray(int* arr){
    int i;
    for(i=0;i<SIZE;++i){
        if(i==SIZE-1){
            printf("%d",*(arr+i));
        }
        else
        {
             printf("%d,",*(arr+i));
        }
        
    }
    printf("\n");
}
int main(){
    int *array=NULL;
    array = (int*)malloc(sizeof(int)*SIZE);
    for(int i=0;i<SIZE;i++){
        int temp;
        scanf("%d",&temp);
        *(array+i) = temp;
    }
    insertion_sort(array,SIZE);
    printArray(array);

    

}