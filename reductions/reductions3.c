#include "util.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "nanos6.h"


int main(int argc, char **argv)
{
    int a;
	a = 1;
	printf("&a = %p\n", &a);

	#pragma oss task reduction(+:a) node(1) label("task0")
	{
		printf("Start task0 on %d: a = %d [%p]\n", nanos6_get_cluster_node_id(), a, &a);
		usleep(10000);
		a++;
		printf("Done task0 on %d: a = %d [%p]\n", nanos6_get_cluster_node_id(), a, &a);
    }

	#pragma oss task reduction(+:a) node(0) label("task1")
	{
		printf("Start task1 on %d: a = %d [%p]\n", nanos6_get_cluster_node_id(), a, &a);
		sleep(1);
		a++;
		printf("Done task1 on %d: a = %d [%p]\n", nanos6_get_cluster_node_id(), a, &a);
    }

	printf("Before taskwait\n");
	#pragma oss taskwait
	printf("After taskwait: a = %d\n", a);
	sleep(3);
	assert_that(a == 3);
	printf("Done!\n");

    return 0;
}
