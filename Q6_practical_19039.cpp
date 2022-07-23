#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

struct process
{
	int temp;
	
	int pid;
	int arriving_time;
	int burst_time;
	
	int response_time;
	int waiting_time;
	int turnAround_time;
	
	
	int start_time;
	//int current_time;
	int complete_time;
};

class Algorithm
{
	float totalWaiting_time, totalTurnAround_time, totalResponse_time, avgTurnAround_time, avgWaiting_time, avgResponse_time;
	int size;
	process *PList;
	
	
	public:
		void input(int size);
		void fcfs(int size);
		void output(int size);
		void sort_arrivalTime(int size);
		//void swap(int&, int&);
		
};

void Algorithm::input(int size)
{
	PList = new process[size];
	
	//cout<<PList->pid;
	cout<<"enter the process ID's"<<endl;
	for (int i=1;i<=size;i++)
	{	
		cin>>PList[i].pid;
	}
	cout<<"enter arrival time"<<endl;
	
	for (int i=1;i<=size;i++)
	{
		cout<<"For process"<<i<<endl;
		cin>>PList[i].arriving_time;
	}
	
	cout<<"enter burst time"<<endl;
	for (int i=1;i<=size;i++)
	{
		cout<<"For process"<<i<<endl;
		cin>>PList[i].burst_time;
	}
}

void Algorithm::sort_arrivalTime(int size)
{
	
	
	
	
	
	
	
		process temp;
    	 for(int i=0;i<=size-1;i++)
	{
		int loc=i;
		for(int j=i+1;j<=size;j++)
		{
			if(PList[loc].arriving_time>PList[j].arriving_time)
			loc=j;
		}
		if(loc!=i)
		{
			temp=PList[i];
			PList[i]=PList[loc];
			PList[loc]=temp;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
}


		
	
void Algorithm::output(int size)
{
	
	cout<<"\n_________________________________________________________________________________________________________";
	cout<<"\n  pid \tArrival Time  \tBurst time  \tWaiting Time  \tTurnAround Time  \tResponse Time";
	cout<<"\n_________________________________________________________________________________________________________";
	for(int i=1;i<=size;i++)
	{
		cout<<"\n  P"<<PList[i].pid<<"  \t"<<PList[i].arriving_time<<"    \t \t"<<PList[i].burst_time<<"  \t\t\t"<<PList[i].waiting_time<<"    \t\t"<<PList[i].turnAround_time<<"          \t"<<PList[i].response_time;
	}
	//displaying the gantt chart
	cout<<endl<<endl;
	cout<<"\nGantt Chart for FCFS ALGO:- "<<endl;
	cout<<"\t\t";
	//displaying the start time and completition time for each process
    int	current_time=0;
    for(int i=1;i<=size;i++)
    {
    	if(current_time!=PList[i].start_time)
    	{
    		cout<<current_time<<"         ";
    		current_time+=1;
    		i--;
		}
		if(current_time==PList[i].start_time)
		{
				cout<<current_time<<"         ";
				current_time=PList[i].complete_time;
		}
	}
	cout<<"  "<<PList[size].complete_time;
	//displaying the upper bar
	current_time=0;
	cout<<endl<<"\t\t";
	for(int i=1;i<=size;i++)
	{
			if(current_time!=PList[i].start_time)
    	{
    		cout<<"___________";
    		current_time+=1;
    		i--;
		}
		if(current_time==PList[i].start_time)
		{
			     cout<<"_________";
				current_time=PList[i].complete_time;
		}
	}
	cout<<"___________";
	cout<<endl<<"\t\t";
	current_time=0;
	//displaying the process in gantt chart
	 for(int i=1;i<=size;i++)
    {
    	if(current_time!=PList[i].start_time)
    	{
    		cout<<"|_________";
    		current_time+=1;
    		i--;
		}
		if(current_time==PList[i].start_time)
		{
			 	cout<<"|___P"<<PList[i].pid<<"_____";
				current_time=PList[i].complete_time;
		}
	}
	cout<<"_|";
	//displaying the calculated result
	cout<<"\n\n\nTotal Waiting Time is:- "<<totalWaiting_time;
	cout<<"\n\nTotal Turn Around Time is:- "<<totalTurnAround_time;
	cout<<"\n\nTotal Response Time is:- "<<totalResponse_time;
	cout<<"\n\nAverage Waiting time is:- "<<avgTurnAround_time;
	cout<<"\n\nAverage Turn Around time is:- "<<avgTurnAround_time;
	cout<<"\n\nAverage Response time is:- "<<avgResponse_time;

	
	
	
		
		
}

void Algorithm::fcfs(int size)
{
	
	int current_time= 0;
	totalWaiting_time=0;
	totalTurnAround_time =0;
	totalResponse_time = 0;
    PList[1].waiting_time = 0; 

    //PList[1].temp = PList[1].arriving_time; 
    for (int i=1;i<=size;i++) {
    	if (PList[i].arriving_time==0)
    	{
    	current_time= PList[i].arriving_time;
		}
		if (current_time<PList[i].arriving_time)
		{
		current_time = PList[i].arriving_time;
		}
		
		PList[i].start_time  = current_time;
		PList[i].complete_time = current_time + PList[i].burst_time;
		PList[i].turnAround_time = PList[i].complete_time - PList[i].arriving_time;
		PList[i].waiting_time = PList[i].turnAround_time - PList[i].burst_time;
		PList[i].response_time = PList[i].turnAround_time - PList[i].burst_time;
		
		
		current_time = PList[i].complete_time;
		
		totalWaiting_time = totalWaiting_time+PList[i].waiting_time;
		totalTurnAround_time = totalTurnAround_time + PList[i].turnAround_time;
		totalResponse_time = totalResponse_time + PList[i].response_time;
		
		
		
		
	}
	avgTurnAround_time = totalTurnAround_time/size;
	avgWaiting_time = totalWaiting_time/size;
	avgResponse_time = totalResponse_time/size;
	
	
	

}



int main()
{	
	
	int size;
	cout<<"enter the no of processes"<<endl;
	cin>>size;
	
	Algorithm a;
	
	a.input(size);
	a.sort_arrivalTime(size);
	a.fcfs( size);
	a.output(size);
	getch();
	return 0;
}






/*
enter the no of processes
3
enter the process ID's
1
2
3
enter arrival time
For process1
4
For process2
2
For process3
6
enter burst time
For process1
8
For process2
5
For process3
9

_________________________________________________________________________________________________________
  pid   Arrival Time    Burst time      Waiting Time    TurnAround Time         Response Time
_________________________________________________________________________________________________________
  P2    2               5                       0               5               0
  P1    4               8                       3               11              3
  P3    6               9                       9               18              9


Gantt Chart for FCFS ALGO:-
                0         1         2         7         15           24
                ____________________________________________________________
                |_________|_________|___P2_____|___P1_____|___P3______|


Total Waiting Time is:- 12

Total Turn Around Time is:- 34

Total Response Time is:- 12

Average Waiting time is:- 11.3333

Average Turn Around time is:- 11.3333

Average Response time is:- 4

*/
