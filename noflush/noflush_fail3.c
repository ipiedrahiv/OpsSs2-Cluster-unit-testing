// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 2 --tasks 55 --nesting 2 --seed 18 --enable-file simplify-control.txt

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>

void show(const int *a, int n)
{
	printf("Show %p size %d\n", a, n);
	for (int j=0; j<n; j++)
	{
		printf("0x%08x\n", a[j]);
	}
}

void check(const int *a, const int *ref, int n, const char *name, int ofs)
{
	// printf("Check %p size %d\n", a, n);
	for (int j=0; j<n; j++)
	{
		if (a[j] != ref[j])
		{
			const char *eq = (a[j] == ref[j]) ? "==" : "!=";
			printf("%s[%d]: 0x%08x %s 0x%08x\n", name, ofs+j, a[j], eq, ref[j]);
			assert_that(a[j] == ref[j]);
		}
	}
}

void copy(int *a, const int *ref, int n)
{
	memcpy(a, ref, n * sizeof(int));
}

void check_hash(const int *a, int hash, int n, const char *name)
{
	int val = 0;
	for (int j=0; j<n; j++)
	{
		val ^= a[j];
		val = ((val * 1103515245) + 12345) & 0x7fffffff;
	}
	if (val != hash)
		printf("Error in %s\n", name);
	assert_that(val == hash);
}

void fill(int *a, int val, int n)
{
	for (int j=0; j<n; j++)
	{
		a[j] = val;
		val = ((val * 1103515245) + 12345) & 0x7fffffff;
	}
}


void func0(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[813], 0x95fbea75, 1);
}
void func32(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[372], 0x4e0a233b, 141, "check_56");
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    fill(&b[0], 0x626cf56e, 1000);

    #pragma oss task weakinout(b[571;202]) out(a[785;186]) node(1) label("func0")
    func0(a,b);
    
    #pragma oss taskwait
	printf("done taskwait1\n");
    
    check_hash(&b[343], 0x31ecae19, 314, "check_18");
    check_hash(&b[658], 0x10a850e8, 27, "check_18");
    check_hash(&b[686], 0x006ebb40, 191, "check_18");
    #pragma oss task out(a[831;13]) weakinout(b[582;1]) weakout(b[583;324]) in(b[372;141]) node(1) label("func32")
    func32(a,b);
    
    fill(&b[35], 0x685598b0, 149);
    #pragma oss taskwait
    
    check_hash(&b[35], 0x4a2e5e6d, 149, "check_99");

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 2 --tasks 55 --nesting 2 --seed 18 --enable-file simplify-control.txt]\n");
	
    return(0);
}
	
