#include "sort.h"
/**
 * lomuto - partitions array
 * @array: array to partition
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: pivot index
 */
int lomuto(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j, temp;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if (i + 1 != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}

/**
 * q_sort - recursive quick sort
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 */
void q_sort(int *array, int low, int high, size_t size)
{
int pivot;
if (low < high)
{
pivot = lomuto(array, low, high, size);
q_sort(array, low, pivot - 1, size);
q_sort(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - sorts array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
q_sort(array, 0, size - 1, size);
}
