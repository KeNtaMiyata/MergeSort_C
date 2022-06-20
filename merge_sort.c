#include <stdio.h>

void merge_sort(int array[],int left_index, int right_index);

int arr1[] = {2,4,5,7,8,5,4,3,6,8,1};
int size_of_array = sizeof(arr1)/ sizeof(arr1[0]);

int main(void)
{
    printf("%d\n",size_of_array );

    printf("Before sort: ");
    for (int i = 0; i < size_of_array; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    merge_sort(arr1, 0, size_of_array - 1);

    printf("After sort: ");
    for (int i = 0; i < size_of_array; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

}

void merge_sort(int array[],int left_index, int right_index)
{
    int length,mid;

    length = right_index - left_index + 1;

    int work[size_of_array];

    if (length == 1)
    {
        return;
    }

    mid = (right_index + left_index) / 2;

    //左整理
    merge_sort(array, left_index, mid);

    //右整理
    merge_sort(array, mid + 1, right_index);
    
    //copy left side
    for (int i = left_index; i < mid + 1; i++ )
    {
        work[i] = array[i];
    }

    //copy right side reversely
    for (int i = mid + 1; i < right_index + 1; i++)
    {
        work[i] = array[right_index - (i - (mid + 1))];
    }

    int i = left_index;
    int j = right_index;

    //sort
    for (int k = left_index; k <= right_index; k++)
    {
        if (work[i] > work[j])
        {
            array[k] = work[i];
            i++;
        }
        else
        {
            array[k] = work[j--];
        }
    }
}