# include <stdio.h>
# include <math.h>

int main(){
    int MCS(int a[], int s, int t);
    int max_value;
    int array[6] = {6, -4, 7, -4, 0, 1};
    max_value = MCS(array, 0, 5);
    printf("max value is: %d", max_value);
    return 0;
}

int MCS(int a[], int s, int t)
{
    //int array[10] = a[10];
    int max(int a, int b, int c);
    int m, i, j, left_max, right_max, middle_sum, middle_sum_max;
    if (s == t) return 0;
    if (t == s + 1) return a[s];

    m = floor((s + t)/2);
    //printf("m is: %d", m);
    left_max = MCS(a, s, m);
    right_max = MCS(a, m, t);

    middle_sum = a[m-1] + a[m];
    middle_sum_max = middle_sum;
    
    for(i = m-2;i >= s;i--)
        {
        middle_sum += a[i];
        if (middle_sum > middle_sum_max) middle_sum_max = middle_sum;
        }

    for(j = m + 1;j <= t;j++)
        {
        middle_sum += a[i];
        if (middle_sum > middle_sum_max) middle_sum_max = middle_sum;
        }
    return max(left_max, right_max, middle_sum_max);
}

int max(int a, int b, int c)
{
    int max = a;
    if (b > a) max = b;
    if (c > max) max = c;
    return max;
}
