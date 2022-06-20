#include <stdio.h>

void merge_sort (int array[], int left, int right);

int arr1[] = {2,4,5,7,8,5,4,3,6,8,1};
int size_of_array = sizeof(arr1)/ sizeof(arr1[0]);

int main (void) {
  // int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  int i;

  printf("Before sort: ");
  for (i = 0; i < size_of_array; i++) { printf("%d ", arr1[i]); }
  printf("\n");

  merge_sort(arr1, 0, size_of_array - 1);

  printf("After sort: ");
  for (i = 0; i < size_of_array; i++) { printf("%d ", arr1[i]); }
  printf("\n");

  return 0;
}

void merge_sort (int array[], int left, int right){
  int i, j, k, mid;
  int work[size_of_array];  // 作業用配列
  if (left < right) {

    //left＝０ + right＝配列の最大値 は配列の真ん中
    mid = (left + right)/2;

    merge_sort(array, left, mid);  // 左を整列
    merge_sort(array, mid+1, right);  // 右を整列

    for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分をコピー

    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j]; // 右半分を逆順にしてコピー
    }

    i = left; j = right;

    for (k = left; k <= right; k++) {
      if (work[i] < work[j])
      {
        array[k] = work[i++];
      }

      else                   { array[k] = work[j--]; }
    }
  }
}

