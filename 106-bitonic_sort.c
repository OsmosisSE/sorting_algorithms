#include "sort.h"
#include <stdio.h>

void swap_ints(int *a, int *b);

void bit_merge(int *array, size_t size, size_t start, size_t seq, char flow);

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

void bitonic_sort(int *array, size_t size);

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * btonic_merge - Merge a bitonic sequence.
 * @array: Array of integers.
 * @size: The size of the array.
 * @start: Starting index of the sequence.
 * @seq: The size of the sequence.
 * @flow: The direction to sort in.
 */
void btonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
			    (flow == 'D' && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		btonic_merge(array, size, start, jump, flow);
		btonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Create a bitonic sequence.
 * @array: Array of integers.
 * @size: The size of the array.
 * @start: Starting index of a block.
 * @seq: The size of a block.
 * @flow: Direction to sort the block.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;

if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, (flow == 'U') ? "UP" : "DOWN");
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 'U');
		bitonic_seq(array, size, start + cut, cut, 'D');
		btonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, (flow == 'U') ? "UP" : "DOWN");
		print_array(array + start, seq);
}
}

/**
 * bitonic_sort - Sort an array of integers using Bitonic Sort.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 'U');
}
