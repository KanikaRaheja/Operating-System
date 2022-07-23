
//Write a program to implement SJF Scheduling algorithm
#include<iostream>
#include<conio.h>
using namespace std;
struct process
{
	int pid;
	int arv_time;//arrival time
	int burst_time;//burst time
	int wait_time;//waiting time
	int tat_time;//turn around time
	int res_time;//response time
	int start_time;//start time
	
	int comp_time;//completion time
};
class scheduling
{
	float total_tat, total_wt,total_rt ,total_bt;//total turnaround time, total wait time,total response time,total burst time
	int n;
	process *plist;
	public:
	 void input();
	 void sort_arvtime();
	 void sort_burst_time(int,int);
	 void sjf();
	 void display();
	
};
//Taking input for the processes
void scheduling::input()
{
		cout<<"Enter the number of processes:";
     	cin>>n;
     	
     plist= new process[n];
     for( int i=1;i<=n;i++)
     {
          cout<<"\nEnter the Process ID:";
          cout<<"P";
          cin>>plist[i].pid;
          cout<<"\nEnter the"<<" "<<"P"<<plist[i].pid<<" Arrival time:";
          cin>>plist[i].arv_time;
          cout<<"\nEnter the"<<" " <<"P"<<plist[i].pid<<" Burst time:";
          cin>>plist[i].burst_time;
          cout<<"______________________________________";
      }
  
}
//sorting processes according to arrival time
void scheduling::sort_arvtime()
{
	process temp;
	 for(int i=1;i<=n;i++)
	{
		int loc=i;
		for(int j=i+1;j<=n;j++)
		{
			if(plist[loc].arv_time>plist[j].arv_time)
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
//sorting processes according to burst time
void scheduling::sort_burst_time(int x,int y)
{
	process temp;
	 for(int i=x;i<=y-1;i++)
	{
		int loc=i;
		for(int j=i+1;j<=y;j++)
		{
			if(plist[loc].burst_time>plist[j].burst_time)
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
//SJF Algorithm
void scheduling::sjf()
{
	int i,j;
		int curr_time=0;
	for(i=1;i<=n;i++)
	{
		for( j=i;j<=n;j++)
	{
		if (plist[j].arv_time>curr_time)
		 break;
	}
		sort_burst_time(i,j-1); 
	


		if(curr_time<plist[i].arv_time)
		{
			curr_time=plist[i].arv_time;
		}
		plist[i].start_time=curr_time;
		plist[i].comp_time=curr_time+plist[i].burst_time;
		
		plist[i].tat_time=plist[i].comp_time-plist[i].arv_time;
		plist[i].wait_time=plist[i].tat_time-plist[i].burst_time;
		plist[i].res_time=plist[i].tat_time-plist[i].burst_time;
			curr_time=plist[i].comp_time;
	}
		for(int i=1;i<=n;i++)	
       {
       	total_tat+=plist[i].tat_time;//total turnaround time
		total_wt+=plist[i].wait_time;//total wait time
		total_rt+=plist[i].res_time;//total response time
	   }

}
//for displaying the output
void scheduling::display()
{
	//displaying the table
   	cout<<"\n____________________________________________________________________________________________________";
	cout<<"\n \tPID \tArrival Time  \tBurst time  \tWaiting Time  \tTurn Around Time \a Response Time";
	cout<<"\n____________________________________________________________________________________________________";
	
		for(int i=1;i<=n;i++)
	{
		
		cout<<"\n\tP"<<plist[i].pid<<"  \t"<<plist[i].arv_time<<"    \t \t"<<plist[i].burst_time<<"  \t\t"<<plist[i].wait_time<<"  \t\t"<<plist[i].tat_time<<"  \t\t\t"<<plist[i].res_time;
		cout<<"\n____________________________________________________________________________________________________";
	}

// SJF Gantt chart
	cout<<endl<<endl;
	cout<<"\nSJF GANTT CHART \n";
	cout<<"\t\t";
	// start time and completition time for each process
    int	curr_time=0;
    for(int i=1;i<=n;i++)
    {
    	if(curr_time!=plist[i].start_time)
    	{
    		cout<<curr_time<<"         ";
    		curr_time+=1;
    		i--;
		}
		if(curr_time==plist[i].start_time)
		{
				cout<<curr_time<<"         ";
				curr_time=plist[i].comp_time;
		}
	}
	cout<<"  "<<plist[n].comp_time;
	//displaying the upper bar
	curr_time=0;
	cout<<endl<<"\t\t";
	for(int i=1;i<=n;i++)
	{
			if(curr_time!=plist[i].start_time)
    	{
    		cout<<"___________";
    		curr_time+=1;
    		i--;
		}
		if(curr_time==plist[i].start_time)
		{
			     cout<<"_________";
				curr_time=plist[i].comp_time;
		}
	}
	cout<<"___________";
	cout<<endl<<"\t\t";
	curr_time=0;
	//displaying the process in gantt chart
	 for(int i=1;i<=n;i++)
    {
    	if(curr_time!=plist[i].start_time)
    	{
    		cout<<"|_________";
    		curr_time+=1;
    		i--;
		}
		if(curr_time==plist[i].start_time)
		{
			 	cout<<"|___P"<<plist[i].pid<<"_____";
				curr_time=plist[i].comp_time;
		}
	}
	cout<<"_|";
 

	

	//displaying the calculated result
	cout<<"\n\n\nTotal Waiting Time :"<<total_wt;
	cout<<"\t\tTotal Turn Around Time :"<<total_tat;
	cout<<"\n\nTotal Response Time: "<<total_rt;
	cout<<"\t\tAverage Waiting time:"<<total_wt/n;
	cout<<"\n\nAverage Turn Around time: "<<total_tat/n;
	cout<<"\t\tAverage Response time:"<<total_rt/n;	
	 
}
int main()
{
	

	scheduling ob;
	ob.input();
	ob.sort_arvtime();
	
	ob.sjf();
	ob.display();
	getch();
	return 0;
	
}

/*
Test case 1
Enter the number of processes:4

Enter the Process ID:P1

Enter the P1 Arrival time:0

Enter the P1 Burst time:6
______________________________________
Enter the Process ID:P2

Enter the P2 Arrival time:0

Enter the P2 Burst time:8
______________________________________
Enter the Process ID:P3

Enter the P3 Arrival time:0

Enter the P3 Burst time:7
______________________________________
Enter the Process ID:P4

Enter the P4 Arrival time:0

Enter the P4 Burst time:3
______________________________________
____________________________________________________________________________________________________
        PID     Arrival Time    Burst time      Waiting Time    Turn Around Time  Response Time
____________________________________________________________________________________________________
        P4      0               3               0               3                       0
____________________________________________________________________________________________________
        P1      0               6               3               9                       3
____________________________________________________________________________________________________
        P3      0               7               9               16                      9
____________________________________________________________________________________________________
        P2      0               8               16              24                      16
____________________________________________________________________________________________________


SJF GANTT CHART
                0         3         9         16           24
                _______________________________________________
                |___P4_____|___P1_____|___P3_____|___P2______|


Total Waiting Time :28          Total Turn Around Time :52

Total Response Time: 28         Average Waiting time:7

Average Turn Around time: 13            Average Response time:7
**************************************************************************************************
Test case 2

Enter the number of processes:6

Enter the Process ID:P1

Enter the P1 Arrival time:2

Enter the P1 Burst time:5
______________________________________
Enter the Process ID:P2

Enter the P2 Arrival time:4

Enter the P2 Burst time:2
______________________________________
Enter the Process ID:P3

Enter the P3 Arrival time:6

Enter the P3 Burst time:1
______________________________________
Enter the Process ID:P4

Enter the P4 Arrival time:12

Enter the P4 Burst time:5
______________________________________
Enter the Process ID:P5

Enter the P5 Arrival time:13

Enter the P5 Burst time:4
______________________________________
Enter the Process ID:P6

Enter the P6 Arrival time:0

Enter the P6 Burst time:6
______________________________________
____________________________________________________________________________________________________
        PID     Arrival Time    Burst time      Waiting Time    Turn Around Time  Response Time
____________________________________________________________________________________________________
        P6      0               6               0               6                       0
____________________________________________________________________________________________________
        P3      6               1               0               1                       0
____________________________________________________________________________________________________
        P2      4               2               3               5                       3
____________________________________________________________________________________________________
        P1      2               5               7               12                      7
____________________________________________________________________________________________________
        P5      13              4               1               5                       1
____________________________________________________________________________________________________
        P4      12              5               6               11                      6
____________________________________________________________________________________________________


SJF GANTT CHART
                0         6         7         9         14         18           23
                _________________________________________________________________
                |___P6_____|___P3_____|___P2_____|___P1_____|___P5_____|___P4______|


Total Waiting Time :17          Total Turn Around Time :40

Total Response Time: 17         Average Waiting time:2.83333

Average Turn Around time: 6.66667               Average Response time:2.83333

**********************************************************************************
TEST CASE 3
Enter the number of processes:6

Enter the Process ID:P1

Enter the P1 Arrival time:2

Enter the P1 Burst time:5
______________________________________
Enter the Process ID:P2

Enter the P2 Arrival time:4

Enter the P2 Burst time:2
______________________________________
Enter the Process ID:P3

Enter the P3 Arrival time:6

Enter the P3 Burst time:1
______________________________________
Enter the Process ID:P4

Enter the P4 Arrival time:12

Enter the P4 Burst time:5
______________________________________
Enter the Process ID:P5

Enter the P5 Arrival time:8

Enter the P5 Burst time:4
______________________________________
Enter the Process ID:P6

Enter the P6 Arrival time:0

Enter the P6 Burst time:6
______________________________________
____________________________________________________________________________________________________
        PID     Arrival Time    Burst time      Waiting Time    Turn Around Time  Response Time
____________________________________________________________________________________________________
        P6      0               6               0               6                       0
____________________________________________________________________________________________________
        P3      6               1               0               1                       0
____________________________________________________________________________________________________
        P2      4               2               3               5                       3
____________________________________________________________________________________________________
        P5      8               4               1               5                       1
____________________________________________________________________________________________________
        P1      2               5               11              16                      11
____________________________________________________________________________________________________
        P4      12              5               6               11                      6
____________________________________________________________________________________________________


SJF GANTT CHART
                0         6         7         9         13         18           23
                _________________________________________________________________
                |___P6_____|___P3_____|___P2_____|___P5_____|___P1_____|___P4______|


Total Waiting Time :21          Total Turn Around Time :44

Total Response Time: 21         Average Waiting time:3.5

Average Turn Around time: 7.33333               Average Response time:3.5

*/


