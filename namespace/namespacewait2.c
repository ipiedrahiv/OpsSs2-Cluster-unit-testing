#include "util.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "nanos6.h"


int main(int argc, char **argv)
{
    int *a = nanos6_lmalloc(30*sizeof(int));
	a[0] = 1;
	a[10] = 1;

	#pragma oss task weakinout(a[0;20]) node(1) label("weak1") wait
	{
		#pragma oss task inout(a[0;10]) node(1) label("strong1a")
		{
			printf("\n\nStart task 1A on %d\n\n", nanos6_get_cluster_node_id());
			assert_that(a[0] == 1);
			sleep(1);
			printf("\n\nEnd task 1A on %d\n\n", nanos6_get_cluster_node_id());
		}
		#pragma oss task inout(a[10;10]) node(1) label("strong1b")
		{
			printf("\n\nStart task 1B on %d\n\n", nanos6_get_cluster_node_id());
			assert_that(a[10] == 1);
			sleep(2);
			printf("\n\nEnd task 1B on %d\n\n", nanos6_get_cluster_node_id());
		}
	}

	#pragma oss task weakinout(a[0;20]) node(1) label("weak2")
	{
		#pragma oss task inout(a[0;10]) node(1) label("strong2a")
		{
			printf("\n\nStart task 2A on %d\n\n", nanos6_get_cluster_node_id());
			assert_that(a[0] == 1);
			a[0] = 2;
			sleep(2);
			printf("\n\nDone task 2A on %d\n", nanos6_get_cluster_node_id());
		}
		#pragma oss task inout(a[10;10]) node(1) label("strong2b")
		{
			printf("\n\nStart task 2B on %d\n\n", nanos6_get_cluster_node_id());
			assert_that(a[10] == 1);
			a[10] = 2;
			sleep(1);
			printf("\n\nDone task 2B on %d\n", nanos6_get_cluster_node_id());
		}
	}

	#pragma oss taskwait
	assert_that(a[0] == 2);
	assert_that(a[10] == 2);
	printf("Finished main!\n");

    return 0;
}
