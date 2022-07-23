//memory allocation strategy
#include<iostream>
#include<conio.h>
using namespace std;

struct Process
{
	int pid;
	int mem_req;
	int part_num;
};

struct Memory
{
	int part_size;
	int remain_size;
};

class memoryallocation
{
	Process *plist;
	Memory *mlist;
	int k;
	public:
  int numofprocess,numofpartition;
  void input();	
  void FirstFit();
  void BestFit();
  void WorstFit();
  void Output();
};
//taking the input from the user
void memoryallocation::input()
{
	cout<<"\nEnter the number of processes:- ";
	cin>>numofprocess;
	plist=new Process[numofprocess];
	cout<<"\nEnter the process_id for 1st process and the system will allocate other ids sequentially:- ";
	cin>>k;
	for(int i=0;i<numofprocess;i++)
	{
		plist[i].pid=k++;
	}
	cout<<"\n\nEnter the memory required for each process:- ";
	for(int i=0;i<numofprocess;i++)
	{
		cout<<"\nEnter the memory required for process "<<i+1<<":- ";
		cin>>plist[i].mem_req;
	}
	cout<<"\n\nEnter the number of memory partitions available:- ";
	cin>>numofpartition;
	mlist=new Memory[numofpartition];
	cout<<"\nEnter the partition size:- ";
	for(int i=0;i<numofpartition;i++)
	cin>>mlist[i].part_size;
}
//First Fit Strategy
void memoryallocation::FirstFit()
{
	int n;
	input();
	for(int i=0;i<numofpartition;i++)
	{
		mlist[i].remain_size=mlist[i].part_size;
	}
	for(int i=0;i<numofprocess;i++)
	{
		plist[i].part_num=-1;
		for(int j=0;j<numofpartition;j++)
		{
			if(mlist[j].remain_size>=plist[i].mem_req)
			{
			plist[i].part_num=j+1;
			mlist[j].remain_size-=plist[i].mem_req;
	 		break;
		    }
		}
	}
}
//Best Fit Strategy
void memoryallocation::BestFit()
{
	int n;
	input();
	for(int i=0;i<numofpartition;i++)
	{
		mlist[i].remain_size=mlist[i].part_size;
	}
	for(int i=0;i<numofprocess;i++)
	{
		plist[i].part_num=-1;
		int minindex=-1;
		for(int j=0;j<numofpartition;j++)
		{
			if(mlist[j].remain_size>=plist[i].mem_req)
			{
			 if(minindex==-1)
			 minindex=j;
			 else if(mlist[j].remain_size<mlist[minindex].remain_size)
			 minindex=j;
		    }
		}
		if(minindex!=-1)
		{
			mlist[minindex].remain_size-=plist[minindex].mem_req;
			plist[i].part_num=minindex+1;
		}
	}
}
//worst fit allocation
void memoryallocation::WorstFit()
{
	int n;
	input();
	for(int i=0;i<numofpartition;i++)
	{
		mlist[i].remain_size=mlist[i].part_size;
	}
	for(int i=0;i<numofprocess;i++)
	{
		plist[i].part_num=-1;
		int minindex=-1;
		for(int j=0;j<numofpartition;j++)
		{
			if(mlist[j].remain_size>=plist[i].mem_req)
			{
			 if(minindex==-1)
			 minindex=j;
			 else if(mlist[j].remain_size>mlist[minindex].remain_size)
			 minindex=j;
		    }
		}
		if(minindex!=-1)
		{
			mlist[minindex].remain_size-=plist[minindex].mem_req;
			plist[i].part_num=minindex+1;
		}
		mlist[n].remain_size-=plist[i].mem_req;
	}
}
//displaying the result
void memoryallocation::Output()
{
	cout<<"\n\n Process Id\t\t Memory Allocated";
	for(int i=0;i<numofprocess;i++)
	{
		cout<<"\n P"<<plist[i].pid<<"\t\t\t"<<plist[i].part_num;
	}
}
int main()
{
	memoryallocation m;
	int ch;
	char ans;
	do
	{
	cout<<"\nEnter your strategy:- \n1.First Fit\n2.Best Fit\n3.Worst Fit";
	cout<<"\nEnter your choice:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				m.FirstFit();
				m.Output();
				break;
			}
		case 2:
			{
				m.BestFit();
				m.Output();
				break;
			}
		case 3:
			{
				m.WorstFit();
				m.Output();
				break;
			}
		default:
			cout<<"\n\nWrong Choice.Reenter your choice:- ";
	}
	cout<<"\n\nDo you want more opeartion to perform:- ";
	cin>>ans;
    }while(ans=='y');
    getch();
    return 0;
}
/*
OUTPUT
case 1
Enter your strategy:-
1.First Fit
2.Best Fit
3.Worst Fit
Enter your choice:- 1

Enter the number of processes:- 5

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1


Enter the memory required for each process:-
Enter the memory required for process 1:- 115

Enter the memory required for process 2:- 500

Enter the memory required for process 3:- 358

Enter the memory required for process 4:- 200

Enter the memory required for process 5:- 375


Enter the number of memory partitions available:- 6

Enter the partition size:- 300
600
350
200
750
125


 Process Id              Memory Allocated
 P1                     1
 P2                     2
 P3                     5
 P4                     3
 P5                     5

Do you want more opeartion to perform:- y

Enter your strategy:-
1.First Fit
2.Best Fit
3.Worst Fit
Enter your choice:- 2

Enter the number of processes:- 5

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1


Enter the memory required for each process:-
Enter the memory required for process 1:- 115

Enter the memory required for process 2:- 500

Enter the memory required for process 3:- 358

Enter the memory required for process 4:- 200

Enter the memory required for process 5:- 375


Enter the number of memory partitions available:- 6

Enter the partition size:- 300
600
350
200
750
125


 Process Id              Memory Allocated
 P1                     6
 P2                     2
 P3                     5
 P4                     4
 P5                     5

case 2

Do you want more opeartion to perform:- y
Enter your strategy:-
1.First Fit
2.Best Fit
3.Worst Fit
Enter your choice:- 1

Enter the number of processes:- 5

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1


Enter the memory required for each process:-
Enter the memory required for process 1:- 115

Enter the memory required for process 2:- 500

Enter the memory required for process 3:- 358

Enter the memory required for process 4:- 200

Enter the memory required for process 5:- 375


Enter the number of memory partitions available:- 1

Enter the partition size:- 1200


 Process Id              Memory Allocated
 P1                     1
 P2                     1
 P3                     1
 P4                     1
 P5                     -1

Do you want more opeartion to perform:- y
Enter your strategy:-
1.First Fit
2.Best Fit
3.Worst Fit
Enter your choice:- 3

Enter the number of processes:- 5

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1


Enter the memory required for each process:-
Enter the memory required for process 1:- 115

Enter the memory required for process 2:- 500

Enter the memory required for process 3:- 358

Enter the memory required for process 4:- 200

Enter the memory required for process 5:- 375


Enter the number of memory partitions available:- 1

Enter the partition size:- 1200


 Process Id              Memory Allocated
 P1                    1
 P2                     1
 P3                     1
 P4                     1
 P5                     1

Do you want more opeartion to perform:-
*/
