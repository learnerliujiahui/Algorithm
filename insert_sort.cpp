#include <stdio.h>

int main(){
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i, j, key;
    for(j = 1; j <= 9; j++)
    {
        key = a[j];
        i  = j-1;
        while (i >= 0 && a[i] > key)
        {
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }

    for(i = 0; i <= 9; i++)
        printf("%d\t", a[i]);
    
    return 0;
}