//program to make use of fork() and exelp
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main()
{
     pid_t pid;
     pid=fork();
     if(pid<0)
{
      cout<<"\n Fork Failed";
}
     else if(pid==0)
{
        cout<<"\n   Child Process  "<<endl<<endl;
        execlp("ls","ls",NULL);
         
         
}
    else
{
       wait(NULL);
       cout<<"\n Parent Process "<<endl;
       cout<<"\nParent pid is:- "<<pid<<endl;
       cout<<"\nParentgetpid is:- "<<getpid()<<endl;
       cout<<"\nParentgetppid is:- "<<getppid()<<endl;
}
     return 0;
}
/*
OUTPUT
 Child Process  

a.out  execlp_19007.cpp  exelp_19007.cpp

 Parent Process 

Parent pid is:- 6231

Parentgetpid is:- 6230

Parentgetppid is:- 4223

*/
