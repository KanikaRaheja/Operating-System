//implementing Round Robin scheduling algorithm
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
	int remaintime;	
};

class schedulingalgo
{
	int start,stop,temp,timequantum;
   float totwait_time,totres_time,totta_time;
   Process *plist;
   int size;
   public:
   void input();
   void sort_arr();
   void roundrobin();
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
	plist[i].remaintime=plist[i].bursttime;
	}
	cout<<"\n\nEnter the time quantum for the round robin scheduling:- ";
	cin>>timequantum;
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
void schedulingalgo::roundrobin()
{
	int j=1,i;
	input();
	int current_time=plist[0].arrivaltime;
	while(j<=size)
	{	
		 for(i=1;i<=size;i++)
		 {
		 	if(plist[i].arrivaltime>current_time && i==j) //new process has arrived
	        current_time=plist[i].arrivaltime;
	        else if(plist[i].arrivaltime>current_time && i!=j) //no new process is available
	        break;
		 	if(plist[i].remaintime==0)
		 	continue;
			if(plist[i].bursttime==plist[i].remaintime)
			{
			plist[i].start_time=current_time;
			plist[i].restime=current_time;
		    }
		    if(plist[i].remaintime>timequantum)
		    {
			plist[i].remaintime-=timequantum;
			current_time+=timequantum;
		    }
		    else if(plist[i].remaintime<=timequantum)
		    {
		    	current_time+=plist[i].remaintime;
		    	plist[i].remaintime=0;
		    	plist[i].completion_time=current_time;
                plist[i].turnaroundtime=plist[i].completion_time-plist[i].arrivaltime;
                plist[i].waitime=plist[i].turnaroundtime-plist[i].bursttime;
                j++;
		}
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
	int current_time;
	 sort_arr();
	//displaying the table 
	//cout<<"\n_________________________________________________________________________________________________________";
	cout<<"\n  pid \tArrival Time  \tBurst time  \tWaiting Time  \tTurnAround Time  \tResponse Time";
	//cout<<"\n_________________________________________________________________________________________________________";
	for(int i=1;i<=size;i++)
	{
		cout<<"\n  P"<<plist[i].pid<<"  \t"<<plist[i].arrivaltime<<"    \t \t"<<plist[i].bursttime<<"  \t\t\t"<<plist[i].waitime<<"    \t\t"<<plist[i].turnaroundtime<<"          \t"<<plist[i].restime;
	}
	for(int i=1;i<=size;i++)
	{
	plist[i].remaintime=plist[i].bursttime;
	}
	//displaying the gantt chart
	cout<<endl<<endl;
	cout<<"\nGantt Chart for Round Robin ALGO:- "<<endl;
	cout<<"\t\t";
	//displaying the start time and completition time for each process	 
    	int j=1,i;
    	 sort_arr();
	 current_time=plist[1].arrivaltime;
	 cout<<current_time<<"         ";
	while(j<=size)
	{	
		 for(i=1;i<=size;i++)
		 {
		 	if(plist[i].arrivaltime>current_time && i==j) //new process has arrived
			 {
			 	current_time=plist[i].arrivaltime;
			 	cout<<current_time<<"         ";
			 } 
	        else if(plist[i].arrivaltime>current_time && i!=j) //no new process is available
	        break;
		 	if(plist[i].remaintime==0)
		 	continue;
			if(plist[i].bursttime==plist[i].remaintime)
			{
			plist[i].start_time=current_time;
			plist[i].restime=current_time;
		    }
		    if(plist[i].remaintime>timequantum)
		    {
			plist[i].remaintime-=timequantum;
			current_time+=timequantum;
			cout<<current_time<<"        ";
		    }
		    else if(plist[i].remaintime<=timequantum)
		    {
		    	current_time+=plist[i].remaintime;
		    	cout<<current_time<<"         ";
		    	plist[i].remaintime=0;
		    	plist[i].completion_time=current_time;
                plist[i].turnaroundtime=plist[i].completion_time-plist[i].arrivaltime;
                plist[i].waitime=plist[i].turnaroundtime-plist[i].bursttime;
                j++;
		}
   }
} 
	cout<<endl;
	cout<<"\t\t";
//displayin the upper bar
	 j=1;
    	 sort_arr();
    	 	for(int i=1;i<=size;i++)
	{
	plist[i].remaintime=plist[i].bursttime;
	}
	 current_time=plist[1].arrivaltime;
	 //cout<<"_________";
	while(j<=size)
	{	
		 for(i=1;i<=size;i++)
		 {
		 	if(plist[i].arrivaltime>current_time && i==j) //new process has arrived
	        {
			current_time=plist[i].arrivaltime;
			//cout<<"_________";
		    }
	        else if(plist[i].arrivaltime>current_time && i!=j) //no new process is available
	        break;
		 	if(plist[i].remaintime==0)
		 	continue;
			if(plist[i].bursttime==plist[i].remaintime)
			{
			plist[i].start_time=current_time;
			plist[i].restime=current_time;
		    }
		    if(plist[i].remaintime>timequantum)
		    {
			plist[i].remaintime-=timequantum;
			current_time+=timequantum;
			//cout<<"_________";
		    }
		    else if(plist[i].remaintime<=timequantum)
		    {
		    	current_time+=plist[i].remaintime;
		    	//cout<<"_________";
		    	plist[i].remaintime=0;
		    	plist[i].completion_time=current_time;
                plist[i].turnaroundtime=plist[i].completion_time-plist[i].arrivaltime;
                plist[i].waitime=plist[i].turnaroundtime-plist[i].bursttime;
                j++;
		}
   }
}
	cout<<endl;
	cout<<"\t\t";
//displaying the pid of the processes
	 j=1;
    	 sort_arr();
    	 	for(int i=1;i<=size;i++)
	{
	plist[i].remaintime=plist[i].bursttime;
	}
	 current_time=plist[1].arrivaltime;
	while(j<=size)
	{	
		 for(i=1;i<=size;i++)
		 {
		 	if(plist[i].arrivaltime>current_time && i==j) //new process has arrived
	        {
			current_time=plist[i].arrivaltime;
			 //cout<<"|________";
		    }
	        else if(plist[i].arrivaltime>current_time && i!=j) //no new process is available
	        break;
		 	if(plist[i].remaintime==0)
		 	continue;
			if(plist[i].bursttime==plist[i].remaintime)
			{
			plist[i].start_time=current_time;
			plist[i].restime=current_time;
		    }
		    if(plist[i].remaintime>timequantum)
		    {
			plist[i].remaintime-=timequantum;
			current_time+=timequantum;
			  //cout<<"|___P"<<plist[i].pid<<"____";
			  
		    }
		    else if(plist[i].remaintime<=timequantum)
		    {
		    	current_time+=plist[i].remaintime;
		     cout<<"|___P"<<plist[i].pid<<"____";
		    	plist[i].remaintime=0;
		    	plist[i].completion_time=current_time;
                plist[i].turnaroundtime=plist[i].completion_time-plist[i].arrivaltime;
                plist[i].waitime=plist[i].turnaroundtime-plist[i].bursttime;
                j++;
		}
   }
}
   //cout<<"_|";
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
	s.roundrobin();
	getch();
	return 0;
}

/*
OUTPUT

test case 1
Enter the number of processes you want to assign to CPU:- 3

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 0

Process 2 arrivaltime:- 0

Process 3 arrivaltime:- 0

Enter the burst time for each process:-

Process 1 bursttime:- 24

Process 2 bursttime:- 3

Process 3 bursttime:- 3


Enter the time quantum for the round robin scheduling:- 4

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P1    0               24                      6               30              0
  P2    0               3                       4               7               4
  P3    0               3                       7               10              7


Gantt Chart for Round Robin ALGO:-
                0         4        7         10         14        18        22        26        30
                _________________________________________________________________________________
                |___P1____|___P2____|___P3____|___P1____|___P1____|___P1____|___P1____|___P1_____|


Total Waiting Time is:- 17

Total Turn Around Time is:- 47

Total Response Time is:- 11

Average Waiting time is:- 5.66667

Average Turn Around time is:- 15.6667

Average Response time is:- 3.66667

test case 2:

Enter the number of processes you want to assign to CPU:- 3

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 1

Process 2 arrivaltime:- 6

Process 3 arrivaltime:- 7

Enter the burst time for each process:-

Process 1 bursttime:- 24

Process 2 bursttime:- 3

Process 3 bursttime:- 3


Enter the time quantum for the round robin scheduling:- 4

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P1    1               24                      6               30              1
  P2    6               3                       3               6               9
  P3    7               3                       5               8               12


Gantt Chart for Round Robin ALGO:-
                1         5        9        12         15         19        23        27        31
                _________________________________________________________________________________
                |___P1____|___P1____|___P2____|___P3____|___P1____|___P1____|___P1____|___P1_____|


Total Waiting Time is:- 14

Total Turn Around Time is:- 44

Total Response Time is:- 22

Average Waiting time is:- 4.66667

Average Turn Around time is:- 14.6667

Average Response time is:- 7.33333
 
 test case 3:
 Enter the number of processes you want to assign to CPU:- 3

Enter the process_id for 1st process and the system will allocate other ids sequentially:- 1

Enter the arrival time for each process:-

Process 1 arrivaltime:- 1

Process 2 arrivaltime:- 15

Process 3 arrivaltime:- 16

Enter the burst time for each process:-

Process 1 bursttime:- 8

Process 2 bursttime:- 6

Process 3 bursttime:- 4


Enter the time quantum for the round robin scheduling:- 4

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P1    1               8                       0               8               1
  P2    15              6                       4               10              15
  P3    16              4                       3               7               19


Gantt Chart for Round Robin ALGO:-
                1         5        9         15         19        23         25
                _______________________________________________________________
                |___P1____|___P1____|________|___P2____|___P3____|___P2_____|


Total Waiting Time is:- 7

Total Turn Around Time is:- 25

Total Response Time is:- 35

Average Waiting time is:- 2.33333

Average Turn Around time is:- 8.33333

Average Response time is:- 11.6667



*/

