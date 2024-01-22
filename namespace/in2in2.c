// Generated by /home/bsc28/bsc28600/work/20210906-impi/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 95 --nesting 4 --seed 19889 --watchdog 45 --enable-file .simplify/simplify-control.txt
//00110000000100000000000001000000000001010000100000000000000000000000000000000000
//00000000000000000000000000000000000000000000000


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>

int watchdog_done = 0;

void *watchdog_func(void *x)
{
	for(int j=0;j<14;j++) {
		sleep(1);
		if (watchdog_done) {
			return NULL;
		}
	}
	printf("Watchdog timer expired (14 seconds)\n");
	assert(0);
}

void func26(char *all,int *b)
{
}

int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));
	char *all = (char *)NULL;


	pthread_t watchdog;
	if (pthread_create(&watchdog, NULL, watchdog_func, NULL)) {
		return 1;
	}

    #pragma oss task weakinout(b[970;1]) node(2) label("P")
    {
		#pragma oss task in(b[970;1]) node(1) wait label("A")
		{ }
	}

    #pragma oss task weakin(b[970;1]) node(1) wait label("B")
    {}

    #pragma oss taskwait

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));
     watchdog_done = 1;
    pthread_join(watchdog, NULL);

    printf("Test passed [/home/bsc28/bsc28600/work/20210906-impi/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 95 --nesting 4 --seed 19889 --watchdog 45 --enable-file .simplify/simplify-control.txt]\n");

    return(0);
}

