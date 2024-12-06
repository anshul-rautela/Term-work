#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void quicksort(char arr[][100]){
    
}


int main(){
    printf("Enter the no. of names");
    int n;
    char s[100];
    scanf("%d",&n);
    char arr[n][100];
    int j=0;
    while(j!=n){
        getchar();
        scanf("%[^\n]",s);
        for(int i=0;s[i]!='\0';i++){
            arr[j][i]=s[i];
        }
        j++;
    }
    quicksort(arr);
}