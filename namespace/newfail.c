// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 1 --tasks 200 --nesting 3 --seed 6 --enable-file simplify-control.txt
//00000000000000000000000000000000000000000000000000001000000000000000000000000000
//00000000000000000000000000110000000000000100100101100110000000000000000000100000
//00000110100001000000000000000010000001000000000000000000000000000000000000000000
//00


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


void func43()
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func139(int *a)
{
    fill(&a[620], 0x64472284, 6);
}
void func137(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[629], 0xba37a072, 1);
    #pragma oss taskwait on(a[620;2])

    fill(&a[620], 0x896b3122, 2);
    #pragma oss task out(a[620;6]) if(0) label("func139")
    func139(a);

}
void func144()
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func164(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func158(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    #pragma oss task weakout(a[610;6]) node(0) label("func164")
    func164(a);

}
void func129(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    #pragma oss task out(a[620;17]) node(0) label("func137")
    func137(a);

    #pragma oss task  node(0) label("func144")
    func144();

    fill(&a[637], 0x1bd25d93, 9);
    #pragma oss task weakout(a[559;63]) node(0) label("func158")
    func158(a);

}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    fill(&b[0], 0xe535256f, 1000);

    #pragma oss task  node(0) label("func43")
    func43();

    #pragma oss task out(a[558;96]) node(0) label("func129")
    func129(a);

    #pragma oss taskwait

    check_hash(&b[205], 0x24ce48c0, 32, "check_372");

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 1 --tasks 200 --nesting 3 --seed 6 --enable-file simplify-control.txt]\n");

    return(0);
}

