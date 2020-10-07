#include <stdio.h>
#include <stdlib.h>


void swap (int n[3][3], int i, int j, int si, int sj){

    int arr[3][3];
    int aux;
    int x, y;

    for(x=0; x<3; ++x){
        for(y=0; y<3; ++y){
            arr[x][y]=n[x][y];
       }
    }

    aux = arr[i][j];
    arr[i][j]=arr[i+(si)][j+(sj)];
    arr[i+(si)][j+(sj)]=aux;

    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    free(*arr);
}


int main()
{
    int num[3][3];
    int i=0, j=0, vi, vj;


    printf("Digite 0 para indicar o espaço vazio\n");

    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j){
            scanf("%d", &num[i][j]);
            if(num[i][j]==0){
                vi=i;
                vj=j;
            }
        }
    }


    if(vi+1<=2){
        swap(num, vi, vj, 1, 0);
    }
    if(vj+1<=2){
        swap(num, vi, vj, 0, 1);
    }
    if(vi-1>=0){
        swap(num, vi, vj, -1, 0);
    }
    if(vj-1>=0){
        swap(num, vi, vj, 0, -1);
    }

    return 0;
}
