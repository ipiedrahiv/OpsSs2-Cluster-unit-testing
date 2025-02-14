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

#include <stdio.h>
#include "util.h"

int main()
{
	fail_if(nanos6_in_cluster_mode() != 0,
	        "This shouldn't be in cluster mode\n");

	fail_if(nanos6_is_master_node() != 1,
	        "Expected to be a master\n");

	fail_if(nanos6_get_cluster_node_id() != 0,
	        "This should be node 0 always\n");

	fail_if(nanos6_get_num_cluster_nodes() != 1,
	        "This should be 1 always with no communicator\n");

	return 0;
}

