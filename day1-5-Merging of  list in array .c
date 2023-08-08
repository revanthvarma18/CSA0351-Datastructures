#include<stdio.h>
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
int i = 0, j = 0, k = 0;

while (i< n1 && j < n2)
{
if (arr1[i] < arr2[j])
arr3[k++] = arr1[i++];
else
arr3[k++] = arr2[j++];
}

while (i < n1)
arr3[k++] = arr1[i++];

while (j < n2)
arr3[k++] = arr2[j++];
}

int main()
{

int n1;
printf("Enter the number of elements of First Array");
scanf("%d", &n1);

printf("Enter the elements of First Array ");
int arr1[n1];
for(int i=0; i< n1; i++)
scanf("%d", &arr1[i]);

printf("Enter the number of elements of Second Array ");
int n2;
scanf("%d", &n2);

printf("Enter of elements of Second Array ");
int arr2[n2];
for(int i=0; i< n2; i++)
scanf("%d", &arr2[i]);

int arr3[n1+n2];
merge(arr1, arr2, n1, n2, arr3);

printf("\nArray after merging\n");
for (int i=0; i < n1+n2; i++)
printf("%d ", arr3[i]);

return 0;
}
