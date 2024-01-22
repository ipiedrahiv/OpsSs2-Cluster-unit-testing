// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 200 --nesting 2 --seed 14 --watchdog 3 --enable-file simplify-control.txt
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000001000001011001100000000000000000000000000000000000000000000000000000110100
//0000001100000000000000000000000000000000000000000000000000001000000


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>


void func79(int *b)
{
}
void func81(int *a,int *b)
{
}
void func82(int *b)
{
}
void func85(int *a,int *b)
{
}
void func86(int *a,int *b)
{
}
void func75(int *a,int *b)
{
    #pragma oss task weakin(b[193;71]) weakin(b[289;25]) node(0) label("func79")
    func79(b);
    
    #pragma oss task out(a[930;5]) weakin(b[240;79]) node(0) label("func81")
    func81(a,b);
    
    #pragma oss task in(b[239;22]) weakin(b[261;17]) node(0) label("func82")
    func82(b);
    
    #pragma oss task weakout(a[938;2]) in(b[215;110]) node(1) label("func85")
    func85(a,b);
    
    #pragma oss task weakout(a[931;6]) in(b[194;134]) node(2) label("func86")
    func86(a,b);
    
}
void func136()
{
}
void func145(int *b)
{
}
void func146()
{
}
void func135(int *a,int *b)
{
    #pragma oss taskwait on(b[192;1])
    
    #pragma oss task  node(0) label("func136")
    func136();
    
    #pragma oss task out(b[192;1]) node(1) label("func145")
    func145(b);
    
    #pragma oss task  node(2) label("func146")
    func146();
    
}
void func195(int *a,int *b)
{
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    #pragma oss task in(b[192;166]) weakout(a[930;10]) node(2) label("func75")
    func75(a,b);
    
    #pragma oss task weakout(a[787;170]) inout(b[192;1]) node(1) label("func135")
    func135(a,b);
    
    #pragma oss task weakin(b[252;15]) out(a[261;608]) node(2) label("func195")
    func195(a,b);
    
    #pragma oss taskwait
    

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 200 --nesting 2 --seed 14 --watchdog 3 --enable-file simplify-control.txt]\n");
	
    return(0);
}
	
