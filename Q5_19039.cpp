#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(int argc,char *argv[])
{
      int fd1,fd2;
      char buffer[100];
     if(argc!=3)
{
       cout<<"\nWrong Number of arguments";
}
   else
{
     fd1=open(argv[1],O_RDONLY);
     fd2=open(argv[2],O_CREAT |O_WRONLY) ;
     if(fd1<0)
{
      cout<<"\nSource File not opened successfully";
       exit(0);
} 
   if(fd2<0)
{
      cout<<"\nTarget File not opened successfully";
       exit(0);
} 
    int n;
    while(n=read(fd1,buffer,sizeof(buffer))!=0)
{
     int x=write(fd2,buffer,n);
     if(x<0)
{
      cout<<"\nError in writing in target file.";
}

}
      close(fd1);
      close(fd2);
}
return 0;
}
