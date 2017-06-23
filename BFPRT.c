#include <string.h>
#include <stdio.h>
#include <time.h>

int c,b,tmp;
#define swap(c,b) {tmp=c;c=b;b=tmp;}
#define N 15
void InsertSort(int array[], int left, int right);
int FindMid(int array[], int left, int right);
int FindPosition(int array[], int left, int right, int num);
int Partion(int array[], int left, int right, int privot);
int BFPRT(int array[], int left, int right, int k);
int array[N] = {1,3,5,7,9,2,4,6,8,10,11,13,15,12,14};
int main()
{
    int k = 4;
    for (int i = 0; i < N; i++)
        printf("%d ",array[i]);
    printf("\n");
    printf("第 %d 大值為： %d \n", k, BFPRT(array, 0, N-1, k));
    return 0;
}

void InsertSort(int array[], int left, int right)
{
    int j,k;
    for(int i = left ; i < right; i++) {
        if(array[i] > array[i+1]) {
            k = array[i+1];
            j = i+1;
            while(j > left && array[j - 1] > k) {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = k;
        }
    }
}

int FindMid(int array[], int left, int right)
{
    if(left == right)
        return array[right];
    int i = 0;
    int j = 0;
    for(i = left; i < right - 5; i += 5) {
        InsertSort(array, i, i + 4);
        j = i - left;
        swap(array[left + j / 5], array[i + 2]);
    }
    int num = right - i + 1;
    if(num > 0) {
        InsertSort(array, i, i + num - 1);
        j = i - left;
        swap(array[left + j / 5], array[i + num / 2]);
    }
    j /= 5;
    if(j == left) return array[left];
    return FindMid(array, left, left + j);
}

int FindPosition(int array[], int left, int right, int num)
{
    for(int i = left; i <= right; i++)
        if(array[i] == num)
            return i;
    return -1;
}

int Partion(int array[], int left, int right, int privot)
{
    swap(array[privot], array[left]);
    int i = left;
    int j = right;
    int pivot = array[left];
    while(i < j) {
        while(array[j] <= pivot && i < j)
            j--;
        array[i] = array[j];
        while(array[i] >= pivot && i < j)
            i++;
        array[j] = array[i];
    }
    array[i] = pivot;
    return i;
}

int BFPRT(int array[], int left, int right, int k)
{
    int mid = FindMid(array, left, right);
    int privot =  FindPosition(array, left, right, mid);
    int pos = Partion(array, left, right, privot);
    int num = pos - left + 1;
    if(num == k) return array[pos];
    if(num > k)  return BFPRT(array, left, pos - 1, k);
    return BFPRT(array, pos + 1, right, k - num);
}


