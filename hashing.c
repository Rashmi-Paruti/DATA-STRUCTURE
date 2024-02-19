/*Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F. Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are Integers. Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder method), and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int create(int);
void linear_prob(int[], int, int);
void display (int[]);
void main()
{
int a[MAX],num,key,i;
int ans=1;
 printf(" collision handling by linear probing : \n");
for (i=0;i<MAX;i++)
 {
 a[i] = -1;
 }
do
 {
 printf("\n Enter the data");
 scanf("%4d", &num);
 key=create(num);
 linear_prob(a,key,num);
 printf("\n Do you like to continue ? (1/0) ");
 scanf("%d",&ans);
 }while(ans);
 display(a);
}
int create(int num)
{
int key;
 key=num%100;
return key;
}
void linear_prob(int a[MAX], int key, int num)
{
int flag, i, count=0;
 flag=0;
if(a[key]== -1) 
{
 a[key] = num;
 }
else
 {
 printf("\n Collision Detected...!!!\n");
 i=0;
 while(i<MAX)
 {
 if (a[i]!=-1)
 count++;
 i++;
 }
 printf("Collision avoided successfully using LINEAR PROBING\n");
 if(count == MAX)
 {
 printf("\n Hash table is full");
 display(a);
 exit(1);
 }
 for(i=key+1; i<MAX; i++)
 if(a[i] == -1)
 {
 a[i] = num;
 flag =1;
 break;
 }
 //for(i=0;i<key;i++)
 i=0;
 while((i<key) && (flag==0))
 {
 if(a[i] == -1)
 {
 a[i] = num;
 flag=1;
 break;
 }
 i++;
 }
 }
}
void display(int a[MAX])
{
int i,choice;
 printf("1.Display ALL\n 2.Filtered Display\n");
 scanf("%d",&choice);
if(choice==1)
 {
 printf("\n the hash table is\n");
 for(i=0; i<MAX; i++)
 printf("\n %d %d ", i, a[i]);
 }
else
 {
 printf("\n the hash table is\n");
 for(i=0; i<MAX; i++)
 if(a[i]!=-1)
 {
 printf("\n %d %d ", i, a[i]);
 continue;
 }
 }
}