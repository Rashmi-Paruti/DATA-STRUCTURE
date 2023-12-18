/*
5
b. Solving Tower of Hanoi problem with n disks
*/

#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);

void main()
{
	int n;
	printf("Enter the number of disks\n");
	scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B');
	return;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if(n == 1)
	{
		printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
		return;
	}
	
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
	return;
}