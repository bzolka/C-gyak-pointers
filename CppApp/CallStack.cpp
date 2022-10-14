#include<stdio.h>

int Osszead(int a, int b)
{
	return a + b;
}


int OsszeadTombElemek(int* szamok, int hossz)
{
	int eredmeny = 0;
	for (int i = 0; i < hossz; i++)
		eredmeny = Osszead(eredmeny, szamok[i]);
	return eredmeny;
}


void DemoCallStack()
{
	int nums[3] = { 2, 3, 6 };
	int osszeg = OsszeadTombElemek(nums, 3);
	printf("Eredmeny: %d", osszeg);
}