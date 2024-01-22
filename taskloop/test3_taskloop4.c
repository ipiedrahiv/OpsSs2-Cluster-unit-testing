/*
 * Copyright (C) 2022  Paul Carpenter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>

#define MIN(a,b) ((a)>(b)?(b):(a))

const int N = 120;

int main(void)
{
    int *array = nanos6_lmalloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		#pragma oss task out(array[i]) node(i%3) label("init")
		{
			array[i] = 20;
		}
	}

	// Taskloop distributed over all nodes with a delay
	int nodes = nanos6_get_num_cluster_nodes();
	int itersPerNode = (N+nodes-1)/nodes;
	#pragma oss taskloop inout(array[i]) grainsize(1) label("taskloop")
	for (int i = 0; i < N; ++i) {
		if (i*2 > N) {
			sleep(1);
		}
		// printf("A %d on %d\n", i, nanos6_get_cluster_node_id());
		array[i] += 100;
		assert_that(nanos6_get_cluster_node_id() == (i/itersPerNode)); // assume blocked scheduling
	}

	#pragma oss taskwait

	for (int i = 0; i < N; ++i) {
		printf("array[%d] = %d\n", i, array[i]);
		assert_that(array[i] == 120);
	}

	printf("Test passed\n");
}

	
