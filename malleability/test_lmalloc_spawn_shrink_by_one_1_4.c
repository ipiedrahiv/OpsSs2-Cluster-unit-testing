/*
 * Copyright (C) 2022  Jimmy Aguilar Mena
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

#include <stdlib.h>
#include "util.h"

int main()
{
	int actual_nodes = 1;

	int *arr = nanos6_lmalloc(sizeof(int));
	int expected = 123;
	arr[0] = expected;

	srand(3);

	int N = 30;
	for (int i=0; i<N; i++) {
		int nodes = (rand() % 4) + 1;
		printf("%d. Will update to %d nodes\n", i, nodes);

		if (nodes < actual_nodes) {
			// Migrate data by hand to one of the remaining nodes
			int target_node = rand() % nodes;
			#pragma oss task node(target_node) inout(arr[0])
			{
				printf("Migration: got %d expected %d\n", arr[0], expected);
				fail_if(arr[0] != expected, "Incorrect value on migration");
			}
		}

		// Resize
		while (nodes > actual_nodes) {
			nanos6_cluster_resize(1);
			actual_nodes++;
		}
		while (nodes < actual_nodes) {
			nanos6_cluster_resize(-1);
			actual_nodes--;
		}

		fail_if(nanos6_get_cluster_node_id() != 0,
		        "Main on wrong cluster node.");
		fail_if(nanos6_get_num_cluster_nodes() != nodes,
		        "Wrong number of cluster nodes.");

		for(int node=0; node < nodes; node++) {
			#pragma oss task node(node) inout(arr[0])
			{
				fail_if(nanos6_get_cluster_node_id() != node,
						"Task on wrong cluster node.");
				fail_if(arr[0] != expected,
						"Incorrect data value passed to task");
				arr[0] += 100;
				printf("node %d increases to %d, and is ", node, arr[0]);
				system("hostname");
			}
			expected += 100;
		}
	}

	#pragma oss taskwait
	nanos6_lfree(arr, sizeof(int));

	return 0;
}
