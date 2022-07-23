//implementing SJF premeeetive scheduling algorithm
#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

struct Process
{
    int pid;
	int arrivaltime;
	int bursttime;
	int turnaroundtime;
	int waitime;
	int restime;
	int start_time;
	int completion_time;	
	int remainbursttime;	
};

class schedulingalgo
{
	int start,stop,temp;
   float totwait_time,totres_time,totta_time;
   Process *plist;
   int size;
   public:
   void input();
   void sort_arr();
   void sort_remainburst(int,int);
   void sjrf();
   void output();	
};
//taking input for the processes
void schedulingalgo::input()
{
	int k;
	cout<<"\nEnter the number of processes you want to assign to CPU:- ";
	cin>>size;
	plist=new Process[size];
	cout<<"\nEnter the process_id for 1st process and the system will allocate other ids sequentially:- ";
	cin>>k;
	for(int i=1;i<=size;i++)
	{
	 plist[i].pid=k++;
	}
	cout<<"\nEnter the arrival time for each process:- "<<endl;
	for(int i=1;i<=size;i++)
	{
		cout<<"\nProcess "<<i<<" arrivaltime:- ";
		cin>>plist[i].arrivaltime;
	}
	cout<<"\nEnter the burst time for each process:- "<<endl;
	for(int i=1;i<=size;i++)
	{
		cout<<"\nProcess "<<i<<" bursttime:- ";
		cin>>plist[i].bursttime;
	}
	for(int i=1;i<=size;i++)
	{
	plist[i].remainbursttime=plist[i].bursttime;
	}
	sort_arr();
}
//sort according to arrival time of processes
void schedulingalgo::sort_arr()
{
	Process temp;
    	 for(int i=0;i<=size-1;i++)
	{
		int loc=i;
		for(int j=i+1;j<=size;j++)
		{
			if(plist[loc].arrivaltime>plist[j].arrivaltime)
			loc=j;
		}
		if(loc!=i)
		{
			temp=plist[i];
			plist[i]=plist[loc];
			plist[loc]=temp;
		}
	}
}
 
void schedulingalgo::sort_remainburst(int n,int m)
{
	Process temp;
    	 for(int i=n;i<=m-1;i++)
	{
		int loc=i;
		for(int j=i+1;j<=m;j++)
		{
			if(plist[loc].remainbursttime>plist[j].remainbursttime)
			loc=j;
		}
		if(loc!=i)
		{
			temp=plist[i];
			plist[i]=plist[loc];
			plist[loc]=temp;
		}
	}
	
}
void schedulingalgo::sjrf()
{
	int i=1,j;
	input();
	sort_arr();
	int current_time=0;
	while(i<=size)
	{	
	    if(plist[i].arrivaltime>current_time)
	    current_time=plist[i].arrivaltime;
		 for(j=i;j<=size;j++)
		 {
		 	if(plist[j].arrivaltime>current_time)
		 	break;
		 }
			sort_remainburst(i,j-1);
			if(plist[i].bursttime==plist[i].remainbursttime)
			{
			plist[i].start_time=current_time;
			plist[i].restime=current_time;
		    }
		    
			plist[i].remainbursttime--;
			current_time++;
     if(plist[i].remainbursttime==0)
     {
     plist[i].completion_time=current_time;
     plist[i].turnaroundtime=plist[i].completion_time-plist[i].arrivaltime;
     plist[i].waitime=plist[i].turnaroundtime-plist[i].bursttime;
     i++;
	 }
    }
	 	
	//calculating total turn around,waiting and response time
	for(int i=1;i<=size;i++)
	{
	totta_time+=plist[i].turnaroundtime;
	totwait_time+=plist[i].waitime;
	totres_time+=plist[i].restime;
    }
	 output();
	}
//display the overall output
void schedulingalgo::output()
{
	int ar[100],b[100];
	int current_time;
	temp=-1;
	 sort_arr();
	int j;
	//displaying the table 
	cout<<"\n_________________________________________________________________________________________________________";
	cout<<"\n  pid \tArrival Time  \tBurst time  \tWaiting Time  \tTurnAround Time  \tResponse Time";
	cout<<"\n_________________________________________________________________________________________________________";
	for(int i=1;i<=size;i++)
	{
		cout<<"\n  P"<<plist[i].pid<<"  \t"<<plist[i].arrivaltime<<"    \t \t"<<plist[i].bursttime<<"  \t\t\t"<<plist[i].waitime<<"    \t\t"<<plist[i].turnaroundtime<<"          \t"<<plist[i].restime;
	}
	//displaying the gantt chart
	cout<<endl<<endl;
	cout<<"\nGantt Chart for SJF PREEMPTIVE ALGO:- "<<endl;
	cout<<"\t\t";
	//displaying the start time and completition time for each process
     current_time=0;
    	for(int i=1;i<=size;i++)
	{
	plist[i].remainbursttime=plist[i].bursttime;
	}
	int i=1;
    	while(i<=size)
	{	
		 for(j=i;j<=size;j++)
		 {
		 	if(plist[j].arrivaltime>current_time)
		 	break;
		 }
		 sort_remainburst(i,j-1);
		 if(plist[i].arrivaltime>current_time)
	    current_time=plist[i].arrivaltime;
		  	if(temp!=plist[i].pid)
			{
				cout<<current_time<<"         ";
					temp=plist[i].pid;
			}
			plist[i].remainbursttime--;
			current_time++;
     if(plist[i].remainbursttime==0)
     {
     i++;
     if(current_time<plist[i+1].arrivaltime)
     	 cout<<current_time<<"         ";
	 }
}
   cout<<plist[size].completion_time<<"         ";
  //displaying the upper bar 
  temp=-1;
  sort_arr(); 
  cout<<endl;
  cout<<"\t\t";
   current_time=0;
    	for(int i=1;i<=size;i++)
	{
	plist[i].remainbursttime=plist[i].bursttime;
	}
	 i=1;
    	while(i<=size)
	{	
		 for(j=i;j<=size;j++)
		 {
		 	if(plist[j].arrivaltime>current_time)
		 	break;
		 }
		 sort_remainburst(i,j-1);
		 if(plist[i].arrivaltime>current_time)
	    current_time=plist[i].arrivaltime;
		  	if(temp!=plist[i].pid)
			{
				cout<<"_________";
					temp=plist[i].pid;
			}
			plist[i].remainbursttime--;
			current_time++;
     if(plist[i].remainbursttime==0)
     {
     i++;
     if(current_time<plist[i+1].arrivaltime)
     	cout<<"_________";
	 }
}
     cout<<"____________";
     
//displaying the process id
     cout<<endl;
  cout<<"\t\t";
  sort_arr();
  temp=-1;
   current_time=0;
    	for(int i=1;i<=size;i++)
	{
	plist[i].remainbursttime=plist[i].bursttime;
	}
	 i=1;
    	while(i<=size)
	{	
		 for(j=i;j<=size;j++)
		 {
		 	if(plist[j].arrivaltime>current_time)
		 	break;
		 }
		 sort_remainburst(i,j-1);
		 if(plist[i].arrivaltime>current_time)
	    current_time=plist[i].arrivaltime;
		  	if(temp!=plist[i].pid)
			{
				cout<<"|___P"<<plist[i].pid<<"____";
					temp=plist[i].pid;
			}
			plist[i].remainbursttime--;
			current_time++;
     if(plist[i].remainbursttime==0)
     {
     i++;
     if(current_time<plist[i+1].arrivaltime)
     	cout<<"|_________";;
	 }
}
  cout<<"_____|";
	//displaying the calculated result
	cout<<"\n\n\nTotal Waiting Time is:- "<<totwait_time;
	cout<<"\n\nTotal Turn Around Time is:- "<<totta_time;
	cout<<"\n\nTotal Response Time is:- "<<totres_time;
	cout<<"\n\nAverage Waiting time is:- "<<totwait_time/size;
	cout<<"\n\nAverage Turn Around time is:- "<<totta_time/size;
	cout<<"\n\nAverage Response time is:- "<<totres_time/size;
}
int main()
{
	schedulingalgo s;
	s.sjrf();
	getch();
 
	return 0;
}

/*
OUTPUT

test case 1

Enter the number of processes you want to assign to CPU:- 4

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 0

Process 2 arrivaltime:- 1

Process 3 arrivaltime:- 2

Process 4 arrivaltime:- 3

Enter the burst time for each process:-

Process 1 bursttime:- 8

Process 2 bursttime:- 4

Process 3 bursttime:- 6

Process 4 bursttime:- 2

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P1    0               8                       12              20              0
  P2    1               4                       0               4               1
  P3    2               6                       5               11              7
  P4    3               2                       2               4               5


Gantt Chart for SJF PREEMPTIVE ALGO:-
                0         1         5         7         13         20
                _________________________________________________________
                |___P1____|___P2____|___P4____|___P3____|___P1_________|


Total Waiting Time is:- 19

Total Turn Around Time is:- 39

Total Response Time is:- 13

Average Waiting time is:- 4.75

Average Turn Around time is:- 9.75

Average Response time is:- 3.25

test case 2

Enter the number of processes you want to assign to CPU:- 5

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 1

Process 2 arrivaltime:- 5

Process 3 arrivaltime:- 6

Process 4 arrivaltime:- 9

Process 5 arrivaltime:- 4

Enter the burst time for each process:-

Process 1 bursttime:- 2

Process 2 bursttime:- 4

Process 3 bursttime:- 2

Process 4 bursttime:- 5

Process 5 bursttime:- 8

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P1    1               2                       0               2               1
  P5    4               8                       11              19              4
  P2    5               4                       2               6               5
  P3    6               2                       0               2               6
  P4    9               5                       2               7               11


Gantt Chart for SJF PREEMPTIVE ALGO:-
                1         3         4         5         6         8         11         16         23
                ____________________________________________________________________________________
                |___P1____|_________|___P5____|___P2____|___P3____|___P2____|___P4____|___P5_________|


Total Waiting Time is:- 15

Total Turn Around Time is:- 36

Total Response Time is:- 27

Average Waiting time is:- 3

Average Turn Around time is:- 7.2

Average Response time is:- 5.4


test case 3
Enter the number of processes you want to assign to CPU:- 4

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 0

Process 2 arrivaltime:- 0

Process 3 arrivaltime:- 0

Process 4 arrivaltime:- 0

Enter the burst time for each process:-

Process 1 bursttime:- 8

Process 2 bursttime:- 4

Process 3 bursttime:- 6

Process 4 bursttime:- 2

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P4    0               2                       0               2               0
  P2    0               4                       2               6               2
  P3    0               6                       6               12              6
  P1    0               8                       12              20              12


Gantt Chart for SJF PREEMPTIVE ALGO:-
                0         2         6         12         20
                ________________________________________________
                |___P4____|___P2____|___P3____|___P1_________|


Total Waiting Time is:- 20

Total Turn Around Time is:- 40

Total Response Time is:- 20

Average Waiting time is:- 5

Average Turn Around time is:- 10

Average Response time is:- 5

*/

