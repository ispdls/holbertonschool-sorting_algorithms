#include "sort.h"

/**
* swap_ints - Swap two integers in an array
* @a: first integer
* @b: second integer
*/
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme for quicksort
* @array: the array to partition
* @size: size of the array
* @low: lower index of the partition
* @high: higher index of the partition
* Return: index of the pivot
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];

	int i = low;

	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}


/**
* quicksort - Implements quicksort algorithm recursively
* @array: the array to sort
* @size: size of the array
* @low: lower index of the partition
* @high: higher index of the partition
*/
void quicksort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, pivot_index - 1);
		quicksort(array, size, pivot_index + 1, high);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: the array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
