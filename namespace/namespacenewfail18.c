// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 90 --nesting 2 --seed 2 --watchdog 25 --enable-file .simplify/simplify-control.txt
//00000000000000000000000011000000010000000000000000000000000010001000000110101100
//000010010000000000000000000


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>


void func26(int *b)
{
}
void func20(int *b)
{
    #pragma oss task in(b[529;11]) node(0) label("func26")
    func26(b);
    
}
void func54(int *a,int *b)
{
}
void func59(int *b)
{
}
void func50(int *a,int *b)
{
    #pragma oss task in(b[889;30]) node(0) label("func54")
    func54(a,b);
    
    #pragma oss task weakout(b[131;211]) node(2) wait label("func59")
    func59(b);
    
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));
	printf("a: %p\n", a);
	printf("b: %p\n", b);

    // #pragma oss taskwait on(b[634;220])
    
    #pragma oss task weakinout(b[289;262]) node(0) wait label("func20")
    func20(b);
    
    #pragma oss task weakin(b[863;62]) out(a[5;924]) out(b[117;431]) node(2) label("func50")
    func50(a,b);
    
    #pragma oss taskwait
    

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 90 --nesting 2 --seed 2 --watchdog 25 --enable-file .simplify/simplify-control.txt]\n");
	
    return(0);
}
	
