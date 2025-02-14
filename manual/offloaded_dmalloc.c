/*
 * Copyright (C) 2020 Paul Carpenter
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


bool dmalloc()
{
	#pragma oss task node(1) label("task0")
	{
		int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
		printf("dmalloc'ed on node %d:  a = %p\n", nanos6_get_cluster_node_id(), a);
		nanos6_dfree(a, 1000 * sizeof(int));
	}

	#pragma oss taskwait
    return true;
}

int main(int argc, char *argv[])
{
	test_t test = FUNC_DEF(dmalloc);

	return run_test(&test);
}
