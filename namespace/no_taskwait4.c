#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>

int main(void)
{
	#pragma oss task label("func0")
	{
		int b[10];

		#pragma oss task out(b[0]) node(2) wait label("func1")
		{
			usleep(100);
			printf("done\n");
		}

		// #pragma oss taskwait
	}

	#pragma oss taskwait
	
    return(0);
}
	
