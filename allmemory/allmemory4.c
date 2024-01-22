/*
 * Copyright (C) 2022  Paul Capenter
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

int main(int argc, char **argv)
{
  int nodes = nanos6_get_num_cluster_nodes();
  char *ALL_MEMORY = NULL;
  int N = 10;
  int A = 0;
  
	#pragma oss task out(A) weakinout(ALL_MEMORY[1;-2]) node(1) label("T1")
	{
		A = 1;
	}
  

  #pragma oss taskwait
  assert_that(A == 1);
  printf("Test passed\n");
  return 0;
}
