// Generated by ./nasty.py --nodes 2 --tasks 70 --nesting 2 --seed 142

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


void func1(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[912], 0x45a37659, 10, "check_9");
}
void func2(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[962], 0x346f4d44, 12, "check_10");
}
void func3(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[933], 0x25fecf16, 3, "check_11");
}
void func4(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[919], 0x7cb02e48, 15, "check_12");
}
void func5(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func6(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[907], 0xeb4674f2, 11);
}
void func7(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func8(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[913], 0x61126a72, 11, "check_17");
}
void func0(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x27094700, 33, "check_4");
    #pragma oss taskwait

    check_hash(&b[910], 0x27094700, 33, "check_5");
    #pragma oss task in(b[912;10]) weakin(b[922;16]) weakout(b[982;4]) node(0) label("func1")
    func1(b);

    #pragma oss task weakin(b[939;4]) weakin(b[956;4]) in(b[962;12]) node(1) label("func2")
    func2(b);

    #pragma oss task weakin(b[923;1]) weakin(b[954;1]) in(b[933;3]) node(1) label("func3")
    func3(b);

    #pragma oss task weakin(b[945;12]) in(b[919;15]) node(0) label("func4")
    func4(b);

    #pragma oss taskwait

    check_hash(&b[910], 0x27094700, 33, "check_13");
    #pragma oss task weakin(b[921;1]) weakin(b[922;13]) weakin(b[937;1]) node(0) label("func5")
    func5(b);

    #pragma oss task weakin(b[946;20]) weakin(b[942;1]) out(a[907;11]) node(1) label("func6")
    func6(a,b);

    #pragma oss task weakin(b[971;4]) weakout(a[899;6]) weakin(b[927;5]) weakout(b[978;10]) node(1) label("func7")
    func7(a,b);

    #pragma oss task weakin(b[936;7]) in(b[913;11]) node(0) label("func8")
    func8(b);

}
void func10(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func11(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x4f169a60, 57, "check_19");
}
void func12(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[933], 0x18fc2dc6, 31, "check_20");
}
void func13(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[957], 0x7a54548d, 6, "check_21");
}
void func14(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[736], 0x76802d13, 32);
}
void func15(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func16(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[546], 0x85fdf686, 115);
}
void func17(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[515], 0xb3c6d128, 99);
}
void func9(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x2c45aa40, 65, "check_18");
    #pragma oss task weakin(b[923;26]) weakout(a[761;23]) weakin(b[952;20]) node(1) label("func10")
    func10(a,b);

    #pragma oss task in(b[910;57]) node(1) label("func11")
    func11(b);

    #pragma oss task in(b[933;31]) node(1) label("func12")
    func12(b);

    #pragma oss task in(b[957;6]) node(0) label("func13")
    func13(b);

    #pragma oss task weakin(b[946;21]) weakin(b[967;2]) out(a[736;32]) node(1) label("func14")
    func14(a,b);

    #pragma oss task weakin(b[944;12]) weakin(b[956;1]) node(1) label("func15")
    func15(b);

    #pragma oss task weakin(b[945;10]) out(a[546;115]) node(1) label("func16")
    func16(a,b);

    #pragma oss task weakout(a[642;51]) out(a[515;99]) node(0) label("func17")
    func17(a);

}
void func19(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[572], 0x48d33b81, 96);
}
void func20(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[928], 0x1ec45708, 12, "check_25");
    fill(&b[945], 0x98e1c300, 17);
}
void func21(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[608], 0xd0cccabd, 92);
}
void func22(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[937], 0x73f88242, 3, "check_26");
}
void func23(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[920], 0x101c1686, 17, "check_27");
}
void func24(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func25(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x51e14f08, 29, "check_28");
    fill(&b[947], 0xfd61f206, 6);
}
void func26(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[934], 0x2da473f1, 3, "check_29");
}
void func18(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x5f20bb45, 30, "check_24");
    #pragma oss task out(a[572;96]) weakout(b[967;2]) weakout(b[945;1]) node(0) label("func19")
    func19(a,b);

    #pragma oss task in(b[928;12]) out(b[945;17]) node(1) label("func20")
    func20(b);

    #pragma oss task weakin(b[932;1]) weakin(b[920;9]) out(a[608;92]) node(0) label("func21")
    func21(a,b);

    #pragma oss task in(b[937;3]) node(0) label("func22")
    func22(b);

    #pragma oss task weakout(b[944;1]) in(b[920;17]) weakin(b[939;1]) node(1) label("func23")
    func23(b);

    #pragma oss task weakin(b[932;1]) weakout(b[954;14]) weakout(a[470;3]) node(0) label("func24")
    func24(a,b);

    #pragma oss task out(b[947;6]) in(b[910;29]) node(1) label("func25")
    func25(b);

    #pragma oss task in(b[934;3]) weakout(b[954;14]) node(1) label("func26")
    func26(b);

}
void func28(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func29(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func30(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func31(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[349], 0x164b63c6, 5);
    fill(&a[496], 0x263b903b, 199);
}
void func32(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[765], 0xc331331b, 100);
}
void func33(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func34(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[629], 0x1e57ebf6, 13);
}
void func35(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[694], 0x67e88ce9, 56);
}
void func27(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    #pragma oss task weakout(b[348;2]) weakout(b[218;129]) node(0) label("func28")
    func28(b);

    #pragma oss taskwait

    #pragma oss task weakout(b[425;186]) node(0) label("func29")
    func29(b);

    #pragma oss task weakout(b[345;11]) node(1) label("func30")
    func30(b);

    #pragma oss taskwait

    #pragma oss task out(b[349;5]) out(a[496;199]) node(0) label("func31")
    func31(a,b);

    #pragma oss task weakout(b[497;271]) out(a[765;100]) node(1) label("func32")
    func32(a,b);

    #pragma oss task weakout(a[421;242]) weakout(a[663;15]) weakout(b[238;86]) node(1) label("func33")
    func33(a,b);

    #pragma oss task out(a[629;13]) node(0) label("func34")
    func34(a);

    #pragma oss task out(b[694;56]) node(0) label("func35")
    func35(b);

}
void func37(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&b[931], 0x158ca2ee, 2);
}
void func38(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func39(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[936], 0x04e4416a, 1);
}
void func40(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[694], 0x63e2192d, 119);
}
void func41(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func42(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[935], 0x76afb111, 1);
}
void func43(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[814], 0x28db721c, 42);
    fill(&b[915], 0xfd28ebbd, 20);
}
void func44(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func36(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    #pragma oss task out(b[931;2]) node(1) label("func37")
    func37(b);

    #pragma oss task weakout(b[636;85]) node(0) label("func38")
    func38(b);

    #pragma oss task out(b[936;1]) weakout(b[923;1]) node(0) label("func39")
    func39(b);

    #pragma oss task weakout(b[924;3]) out(b[694;119]) node(0) label("func40")
    func40(b);

    #pragma oss task weakout(b[921;18]) node(1) label("func41")
    func41(b);

    #pragma oss taskwait

    #pragma oss task out(b[935;1]) weakout(b[936;3]) node(0) label("func42")
    func42(b);

    #pragma oss taskwait

    #pragma oss task out(b[814;42]) out(b[915;20]) node(0) label("func43")
    func43(b);

    #pragma oss task weakout(b[720;105]) weakout(b[917;15]) node(0) label("func44")
    func44(b);

}
void func46(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x6235a5c0, 1, "check_41");
}
void func47(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x6235a5c0, 1, "check_42");
    fill(&a[712], 0x49ef4bab, 67);
}
void func48(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x6235a5c0, 1, "check_43");
}
void func49(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x6235a5c0, 1, "check_46");
}
void func50(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[798], 0xaae91865, 9);
}
void func51(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[680], 0xb8ffea66, 126);
}
void func52(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x6235a5c0, 1, "check_48");
}
void func53(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x6235a5c0, 1, "check_49");
}
void func45(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    check_hash(&b[910], 0x6235a5c0, 1, "check_40");
    #pragma oss task in(b[910;1]) node(0) label("func46")
    func46(b);

    #pragma oss task in(b[910;1]) weakout(a[538;18]) out(a[712;67]) node(1) label("func47")
    func47(a,b);

    #pragma oss task in(b[910;1]) node(1) label("func48")
    func48(b);

    #pragma oss taskwait

    check_hash(&b[910], 0x6235a5c0, 1, "check_44");
    #pragma oss task weakout(a[841;23]) in(b[910;1]) weakout(a[437;76]) node(0) label("func49")
    func49(a,b);

    #pragma oss task out(a[798;9]) weakin(b[910;1]) node(1) label("func50")
    func50(a,b);

    #pragma oss task out(a[680;126]) node(1) label("func51")
    func51(a);

    fill(&a[908], 0x30d0fa0b, 30);
    #pragma oss task in(b[910;1]) node(0) label("func52")
    func52(b);

    #pragma oss task in(b[910;1]) node(1) label("func53")
    func53(b);

}
void func55(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func56(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&b[910], 0xdbec5ce0, 1);
}
void func57(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[910], 0x07dd80e8, 1);
}
void func58(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&a[895], 0xbca2fd7a, 77);
}
void func59(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[722], 0xfb517003, 11);
}
void func60(int *a)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func61(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&a[913], 0x1478b98d, 39);
}
void func62(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func54(int *a,int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    check_hash(&b[910], 0x6235a5c0, 1, "check_50");
    #pragma oss task weakout(a[805;152]) weakout(b[910;1]) node(0) label("func55")
    func55(a,b);

    #pragma oss taskwait

    #pragma oss task out(b[910;1]) node(1) label("func56")
    func56(b);

    #pragma oss task out(b[910;1]) weakout(a[814;106]) node(0) label("func57")
    func57(a,b);

    #pragma oss taskwait

    #pragma oss task weakout(a[870;25]) out(a[895;77]) node(0) label("func58")
    func58(a);

    #pragma oss task out(a[722;11]) weakout(a[733;161]) node(1) label("func59")
    func59(a);

    #pragma oss task weakout(a[946;4]) node(1) label("func60")
    func60(a);

    fill(&b[910], 0xd068cab2, 1);
    #pragma oss task weakin(b[910;1]) out(a[913;39]) node(1) label("func61")
    func61(a,b);

    #pragma oss task weakin(b[910;1]) node(0) label("func62")
    func62(b);

}
void func64(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&b[910], 0xdf2247db, 1);
}
void func65(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
}
void func66(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
}
void func67(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&b[935], 0x97519a77, 22);
}
void func68(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 0);
    fill(&b[910], 0x0a5b899c, 1);
}
void func69(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    fill(&b[833], 0x196a9f0e, 18);
}
void func63(int *b)
{
   assert_that( nanos6_get_cluster_node_id() == 1);
    #pragma oss task out(b[910;1]) node(1) label("func64")
    func64(b);

    #pragma oss task weakout(b[910;1]) node(1) label("func65")
    func65(b);

    #pragma oss task weakout(b[864;2]) node(0) label("func66")
    func66(b);

    #pragma oss task out(b[935;22]) node(1) label("func67")
    func67(b);

    #pragma oss task out(b[910;1]) weakout(b[913;29]) node(0) label("func68")
    func68(b);

    #pragma oss task out(b[833;18]) node(1) label("func69")
    func69(b);

}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    fill(&b[0], 0xb8298509, 1000);

    #pragma oss taskwait

    check_hash(&b[910], 0x6abd333c, 76, "check_3");
    #pragma oss task in(b[910;33]) weakout(a[861;67]) weakin(b[943;32]) weakout(b[975;14]) node(0) label("func0")
    func0(a,b);

    #pragma oss task in(b[910;65]) weakout(a[139;583]) weakout(a[722;64]) node(0) label("func9")
    func9(a,b);

    #pragma oss taskwait

    check_hash(&b[910], 0x2c45aa40, 65, "check_23");
    #pragma oss task weakout(a[453;279]) in(b[910;30]) weakout(b[940;29]) node(1) label("func18")
    func18(a,b);

    #pragma oss task weakout(b[212;144]) out(b[359;445]) weakout(a[328;560]) node(1) label("func27")
    func27(a,b);

    #pragma oss task weakout(b[911;28]) weakout(b[502;383]) node(1) label("func36")
    func36(b);

    #pragma oss task in(b[910;1]) out(a[429;512]) node(0) label("func45")
    func45(a,b);

    #pragma oss task inout(b[910;1]) out(a[687;291]) node(1) label("func54")
    func54(a,b);

    #pragma oss task out(b[825;42]) weakinout(b[910;1]) out(b[911;59]) node(1) label("func63")
    func63(b);

    #pragma oss taskwait

    check_hash(&b[970], 0x5131823c, 5, "check_57");

	nanos6_dfree(a, 1000 * sizeof(int));
	nanos6_lfree(b, 1000 * sizeof(int));


    printf("Test passed [./nasty.py --nodes 2 --tasks 70 --nesting 2 --seed 142]\n");

    return(0);
}

