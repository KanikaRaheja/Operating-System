/*2. Write a program to report behaviour of linux kernel including
a. Kernel version  //cat/proc/sys/kernel/osrelease
b. CPU type and model  //cat/proc/cpuinfo*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h> //system function for executing shell command
//https://www.man7.org/linux/man-pages/man2/uname.2.html
#include<sys/utsname.h> //get name and information about current kernel

using namespace std;

int main()
{
   int q;
   struct utsname s1;
   q=uname(&s1);
   if(q==0)
   {
      printf("\nSystem name:%s,system",s1.sysname);//operating system name
      printf("\nVersion:%s",s1.version);//operating system version
      printf("\nRelease:%s",s1.release);//operating system release
      printf("\nMachine:%s",s1.machine);//cpu type and model // i686:86->intel family
      system("cat/proc/cpuinfo|awk 'NR==3,NR==4(print)' ");//cpu model
   }
   else
   {
      printf("ERROR\n");
   }
   return 0;
}



