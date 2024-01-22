// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 2 --tasks 70 --nesting 5 --seed 4 --taskwaitnoflush

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>



void func38(int *b)
{
}
void func39(int *b)
{
}
void func40(int *b)
{
}
void func37(int *b)
{
    #pragma oss task inout(b[392;1]) node(0)
    func38(b);
    
    #pragma oss taskwait noflush
    
    #pragma oss task weakin(b[392;1]) node(0)
    func39(b);
    
    #pragma oss taskwait
    
    #pragma oss task weakinout(b[392;1]) node(0)
    func40(b);
    
}
void func41(int *b)
{
    #pragma oss taskwait noflush
    
    #pragma oss taskwait noflush
    
}
void func43(int *b)
{
}
void func44(int *b)
{
}
void func45(int *b)
{
}
void func42(int *b)
{
    #pragma oss taskwait noflush
    
    #pragma oss taskwait on(b[391;1])
    
    #pragma oss task inout(b[391;1]) node(1)
    func43(b);
    
    #pragma oss task weakin(b[391;1]) if(0)
    func44(b);
    
    #pragma oss task weakin(b[391;1]) node(1)
    func45(b);
    
}
void func36(int *b)
{
    #pragma oss taskwait on(b[392;1])
    
    #pragma oss taskwait noflush
    
    #pragma oss task inout(b[392;1]) node(1)
    func37(b);
    
    #pragma oss task weakout(b[392;1]) node(1)
    func41(b);
    
    #pragma oss task weakout(b[391;1]) node(1)
    func42(b);
    
}
void func48(int *b)
{
}
void func49(int *b)
{
}
void func50(int *b)
{
}
void func47(int *b)
{
    #pragma oss task weakout(b[385;2]) inout(b[382;1]) weakin(b[390;1]) node(0)
    func48(b);
    
    #pragma oss taskwait
    
    #pragma oss taskwait on(b[390;1])
    
    #pragma oss task inout(b[382;1]) weakout(b[386;1]) out(b[390;1]) if(0)
    func49(b);
    
    #pragma oss task in(b[382;1]) node(0)
    func50(b);
    
}
void func52(int *b)
{
}
void func53(int *b)
{
}
void func54(int *b)
{
}
void func51(int *b)
{
    #pragma oss taskwait noflush
    
    #pragma oss taskwait
    
    #pragma oss task weakin(b[382;1]) in(b[384;1]) node(0)
    func52(b);
    
    #pragma oss task weakin(b[384;1]) weakinout(b[382;1]) node(0)
    func53(b);
    
    #pragma oss task weakout(b[382;1]) weakin(b[384;1]) node(1)
    func54(b);
    
}
void func56(int *b)
{
}
void func57(int *b)
{
}
void func58(int *b)
{
}
void func55(int *b)
{
    #pragma oss task in(b[383;1]) inout(b[389;1]) node(0)
    func56(b);
    
    #pragma oss taskwait on(b[383;1])
    
    #pragma oss taskwait
    
    #pragma oss task weakinout(b[389;1]) node(0)
    func57(b);
    
    #pragma oss task weakout(b[389;1]) weakin(b[383;1]) node(0)
    func58(b);
    
}
void func46(int *b)
{
    #pragma oss taskwait
    
    #pragma oss taskwait noflush
    
    #pragma oss task inout(b[390;1]) inout(b[385;2]) inout(b[382;1]) node(0)
    func47(b);
    
    #pragma oss task weakinout(b[382;1]) inout(b[384;1]) node(0)
    func51(b);
    
    #pragma oss task weakin(b[383;1]) inout(b[389;1]) node(0)
    func55(b);
    
}

void func35(int *b)
{
    #pragma oss task weakout(b[390;3]) node(1)
    func36(b);

	printf("hello\n");
    
    #pragma oss task out(b[385;10]) out(b[380;5]) node(1)
    func46(b);
    
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    #pragma oss task weakout(b[795;40]) weakout(b[375;22]) node(0)
    func35(b);
    
    #pragma oss taskwait

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 2 --tasks 70 --nesting 5 --seed 4 --taskwaitnoflush]\n");
	
    return(0);
}
	
