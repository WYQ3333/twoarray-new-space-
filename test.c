#include<stdio.h>
#include<Windows.h>
#include<string.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int tmp = nums1Size + nums2Size;
	double array[20] = { 0 };
	int i = 0;
	int j = 0;
	int index = 0;
	while (i<nums1Size&&j<nums2Size)
	{
		if (nums1[i] <= nums2[i])
		{
			array[index++] = nums1[i++];
		}
		else
		{
			array[index++] = nums2[j++];
		}
	}
	while (i<nums1Size)
	{
		array[index++] = nums1[i++];
	}
	while (j<nums2Size)
	{
		array[index++] = nums2[j++];
	}
	if (tmp % 2 == 0)
	{
		int k = tmp / 2;
		return (array[k] + array[k - 1]) / 2.0;
	}
	else
	{
		int k = tmp/2;
		return array[k];
	}
}

int main()
{
	int nums1[] = { 1, 3 };
	int nums2[] = { 2, 4 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	double tmp = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	printf("中位数为 :%lf ",tmp);
	system("pause");
	return 0;
}