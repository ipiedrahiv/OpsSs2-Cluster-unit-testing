// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 75 --nesting 4 --seed 16 --watchdog 45 --taskfor --enable-file .simplify/simplify-control.txt
//10000000000000000000000010101011000000000000101000000000000000011110000000000000
//000000000010000000000000000001000000101000100


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>

void func17()
{
}
void func15()
{
    #pragma oss task  if(0) label("func17")
    func17();
    
    #pragma oss taskwait noflush
    
}
void func14()
{
    #pragma oss taskwait
    
    #pragma oss task  node(2) wait label("func15")
    func15();
    
}
void func28()
{
}
void func27(int *b)
{
    #pragma oss task  if(0) label("func28")
    func28();
    
}
void func0(int *b)
{
    #pragma oss task  if(0) label("func14")
    func14();
    
    #pragma oss task weakout(b[551;23]) if(0) label("func27")
    func27(b);
    
}
void func72(int *b)
{
}
void func67(int *a,int *b)
{
    #pragma oss taskwait noflush
    
    #pragma oss task in(b[180;44]) node(2) label("func72")
    func72(b);
    
}
void func40(int *a,int *b)
{
    #pragma oss taskwait noflush
    
    #pragma oss taskwait on(b[296;3])
    
    #pragma oss task for in(b[204;19]) chunksize(1) label("taskfor1")
       for(int i=0; i<19; i++) {
    }
    #pragma oss task out(a[550;84]) out(b[289;10]) in(b[178;58]) node(0) label("func67")
    func67(a,b);
    
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    #pragma oss task weakout(b[627;301]) out(b[418;173]) if(0) label("func0")
    func0(b);
    
    #pragma oss task out(a[530;128]) weakout(a[658;15]) out(b[135;171]) node(2) wait label("func40")
    func40(a,b);
    
    #pragma oss taskwait
    

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 75 --nesting 4 --seed 16 --watchdog 45 --taskfor --enable-file .simplify/simplify-control.txt]\n");
	
    return(0);
}
	
