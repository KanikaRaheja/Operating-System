//program to implement thread library to find sum of an array
#include<iostream>
#include<conio.h>
#include<pthread.h>
#include<math.h>
#define num 4 
using namespace std;
int sum=0;
int numarray;
int *arr;
int sumthread[num]={0};

void *runner(void *i)
{
	int ul,cnt;
	int id=*(int*)i;
	cout<<"\n\tThread  running\n";
	cnt=ceil((float)numarray/num);
	ul=(id+1)*cnt;
	if(ul>numarray)
	ul=numarray;
	//computing the sum for each thread
	for(int j=id*cnt;j<ul;j++)
	{
		sumthread[id]+=arr[j];
	}
 
}
//taking input from the user
void input()
{
	cout<<"\nEnter the Number of elements in the array:- ";
	cin>>numarray;
	arr= new int[numarray];
	for(int i=0;i<numarray;i++)
	{
		cout<<"\n Enter the element "<<i+1<<" of the array:- ";
		cin>>arr[i];
	}
}

int main()
{
	input();
	pthread_t t[num];
	int tid[num];
	
	for(int i=0;i<num;i++)
	{
		tid[i]=i;
		pthread_create(&t[i],NULL,runner,&tid[i]);
	}
		for(int i=0;i<num;i++)
	{
	 
		pthread_join(t[i],NULL);
	}
	//computing the total sum
	for(int i=0;i<num;i++)
	{
	  cout<<"\n "<<sumthread[i];
	  sum+=sumthread[i];
	}
	cout<<"\n\n\tTotal Sum is:- "<<sum;
	getch();
	return 0;
}

/*
Enter the Number of elements in the array:- 8

 Enter the element 1 of the array:- 1

 Enter the element 2 of the array:- 2

 Enter the element 3 of the array:- 3

 Enter the element 4 of the array:- 4

 Enter the element 5 of the array:- 5

 Enter the element 6 of the array:- 6

 Enter the element 7 of the array:- 7

 Enter the element 8 of the array:- 8

        Thread  running

        Thread  running

        Thread  running

        Thread  running

 3
 7
 11
 15

        Total Sum is:- 36

*/
