/** CODE BY MANIRIZZAMAN AKASH **/

#include<stdio.h>
#define MAX 100


int main(){
    int i =0, j= 0, k = 0,
        element = 0,
        array[MAX],
        totalElements = MAX;

        printf("Enter an element [-1 for exit]  : ");
        scanf("%d", &element);

    while(element != -1){
        k = i - 1;
        while((element < array[k]) && k >= 0){
            array[k+1] = array[k];
            --k;
        }

        array[k + 1] = element;

        printf("After inserting value in the array :\n");

        for(j = 0;j <= i; j++){
            printf("%d\t", array[j]);
        }
        printf("\nEnter another element: ");
        scanf("%d", &element);
        ++i;

    }

    printf("\n---------------------------\nFinal sorted array is : ");
     for(j = 0;j <= i; j++){
            printf("%d\t", array[j]);
        }

        return 0;
}
