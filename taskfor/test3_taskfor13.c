// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 1000 --nesting 2 --seed 11 --watchdog 25 --taskfor --enable-file .simplify/simplify-control.txt
//11101111111111011111110111101011100011000111110000000000000000000000000000000000
//00000000011011100101101111001101111100100111110101110111111111101101010111111011
//00111100111110011010111111111000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000010110011111101011111101101101110011111011
//01100111101011111111001111101111011110111011111101101111001001111111100101011010
//11001100010111111101100000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000011011111111011111111101111110101111111011110000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000010000000000000000000000000000000000
//00000000100000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000100000000000000000000000000000000000000000000001000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//000000000000000000000000000000000000000000000000000000000000000000000000000


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>



void func1()
{
}
void func2()
{
}
void func4()
{
}
void func5()
{
}
void func6()
{
}
void func7()
{
}
void func9()
{
}
void func11()
{
}
void func13()
{
}
void func14()
{
}
void func16()
{
}
void func17()
{
}
void func18()
{
}
void func19()
{
}
void func21()
{
}
void func23()
{
}
void func24()
{
}
void func26()
{
}
void func30()
{
}
void func35()
{
}
void func39()
{
}
void func40()
{
}
void func41()
{
}
void func0()
{
    #pragma oss task  node(0) label("func1")
    func1();
    
    #pragma oss task  node(0) label("func2")
    func2();
    
    #pragma oss task  if(0) label("func4")
    func4();
    
    #pragma oss taskwait noflush
    
    #pragma oss taskwait noflush
    
    #pragma oss task  if(0) label("func5")
    func5();
    
    #pragma oss task  node(0) wait label("func6")
    func6();
    
    #pragma oss task  node(1) label("func7")
    func7();
    
    #pragma oss task  node(0) label("func9")
    func9();
    
    #pragma oss task  node(1) label("func11")
    func11();
    
    #pragma oss task  node(2) wait label("func13")
    func13();
    
    #pragma oss task  node(1) label("func14")
    func14();
    
    #pragma oss task  node(0) label("func16")
    func16();
    
    #pragma oss task  node(0) wait label("func17")
    func17();
    
    #pragma oss task  node(2) label("func18")
    func18();
    
    #pragma oss task  node(1) wait label("func19")
    func19();
    
    #pragma oss task  node(2) wait label("func21")
    func21();
    
    #pragma oss task  node(0) wait label("func23")
    func23();
    
    #pragma oss task  node(0) wait label("func24")
    func24();
    
    #pragma oss task  node(2) wait label("func26")
    func26();
    
    #pragma oss task  node(1) wait label("func30")
    func30();
    
    #pragma oss task  node(0) wait label("func35")
    func35();
    
    #pragma oss task  node(1) label("func39")
    func39();
    
    #pragma oss task  node(1) wait label("func40")
    func40();
    
    #pragma oss task  node(2) label("func41")
    func41();
    
}
void func85(int *b)
{
}
void func86(int *a)
{
}
void func89(int *a,int *b)
{
}
void func91(int *a)
{
}
void func92(int *a,int *b)
{
}
void func94(int *a,int *b)
{
}
void func95(int *b)
{
}
void func100(int *a)
{
}
void func101(int *a)
{
}
void func103(int *a)
{
}
void func105(int *a,int *b)
{
}
void func106(int *a)
{
}
void func107(int *a,int *b)
{
}
void func110(int *b)
{
}
void func113(int *a,int *b)
{
}
void func115(int *a)
{
}
void func116(int *b)
{
}
void func117(int *a)
{
}
void func119(int *a,int *b)
{
}
void func121(int *b)
{
}
void func126(int *a,int *b)
{
}
void func129(int *a,int *b)
{
}
void func130(int *a,int *b)
{
}
void func83(int *a,int *b)
{
    #pragma oss taskwait on(b[238;33])
    
    #pragma oss task in(b[232;20]) node(2) wait label("func85")
    func85(b);
    
    #pragma oss taskwait
    
    #pragma oss task in(a[573;1]) in(a[574;3]) node(0) wait label("func86")
    func86(a);
    
    #pragma oss task in(b[139;125]) out(a[406;35]) node(1) label("func89")
    func89(a,b);
    
    #pragma oss task in(a[578;2]) weakout(a[330;120]) node(0) label("func91")
    func91(a);
    
    #pragma oss task in(b[209;24]) weakin(a[575;4]) in(a[579;1]) weakout(a[335;109]) node(1) label("func92")
    func92(a,b);
    
    #pragma oss task weakin(a[574;6]) in(b[202;55]) node(0) wait label("func94")
    func94(a,b);
    
    #pragma oss task weakin(b[158;91]) node(0) wait label("func95")
    func95(b);
    
    #pragma oss task for in(a[574;1]) chunksize(43) label("taskfor96")
       for(int i=0; i<1; i++) {
    }
    #pragma oss task in(a[578;2]) weakin(a[575;3]) node(0) label("func100")
    func100(a);
    
    #pragma oss task in(a[572;8]) if(0) label("func101")
    func101(a);
    
    #pragma oss task out(a[170;276]) weakin(a[575;1]) node(1) label("func103")
    func103(a);
    
    #pragma oss task for in(b[217;48]) chunksize(30) label("taskfor104")
       for(int i=0; i<48; i++) {
    }
    #pragma oss task weakin(b[262;7]) in(a[578;2]) weakin(b[163;39]) node(2) wait label("func105")
    func105(a,b);
    
    #pragma oss task in(a[579;1]) out(a[455;6]) weakin(a[577;2]) node(2) wait label("func106")
    func106(a);
    
    #pragma oss task weakout(a[253;5]) out(a[258;185]) in(b[128;64]) node(2) label("func107")
    func107(a,b);
    
    #pragma oss task weakin(b[186;11]) in(b[197;19]) in(b[270;1]) node(0) label("func110")
    func110(b);
    
    #pragma oss task weakin(a[578;1]) weakin(b[143;79]) in(a[576;2]) node(2) label("func113")
    func113(a,b);
    
    #pragma oss task for in(b[239;34]) chunksize(26) label("taskfor114")
       for(int i=0; i<34; i++) {
    }
    #pragma oss task in(a[579;1]) out(a[319;1]) weakin(a[574;3]) node(1) wait label("func115")
    func115(a);
    
    #pragma oss task weakin(b[129;13]) weakin(b[224;8]) in(b[195;10]) if(0) label("func116")
    func116(b);
    
    #pragma oss task in(a[578;1]) node(1) label("func117")
    func117(a);
    
    #pragma oss task weakin(b[203;61]) weakin(a[572;7]) weakin(a[579;1]) node(0) label("func119")
    func119(a,b);
    
    #pragma oss task in(b[248;22]) node(1) label("func121")
    func121(b);
    
    #pragma oss task for in(a[572;6]) chunksize(1) label("taskfor123")
       for(int i=0; i<6; i++) {
    }
    #pragma oss task weakin(a[577;2]) weakin(b[235;8]) in(a[575;2]) in(a[579;1]) node(2) wait label("func126")
    func126(a,b);
    
    #pragma oss task for in(b[171;4]) chunksize(4) label("taskfor127")
       for(int i=0; i<4; i++) {
    }
    #pragma oss task for in(a[572;5]) chunksize(5) label("taskfor128")
       for(int i=0; i<5; i++) {
    }
    #pragma oss task in(b[170;64]) in(a[577;2]) node(1) wait label("func129")
    func129(a,b);
    
    #pragma oss task weakin(a[573;7]) weakin(b[181;15]) node(1) wait label("func130")
    func130(a,b);
    
}
void func137(int *b)
{
}
void func139(int *b)
{
}
void func141(int *b)
{
}
void func142(int *b)
{
}
void func143(int *b)
{
}
void func144(int *b)
{
}
void func146(int *b)
{
}
void func148(int *b)
{
}
void func149(int *b)
{
}
void func152(int *b)
{
}
void func153(int *b)
{
}
void func155(int *b)
{
}
void func159(int *b)
{
}
void func160(int *b)
{
}
void func161(int *b)
{
}
void func162(int *b)
{
}
void func166(int *b)
{
}
void func170(int *b)
{
}
void func171(int *b)
{
}
void func172(int *b)
{
}
void func175(int *b)
{
}
void func177(int *b)
{
}
void func132(int *b)
{
    #pragma oss taskwait on(b[479;117])
    
    #pragma oss task for in(b[131;7]) chunksize(4) label("taskfor133")
       for(int i=0; i<7; i++) {
    }
    #pragma oss taskwait
    
    #pragma oss task weakin(b[223;2]) weakin(b[264;1]) inout(b[976;5]) if(0) label("func137")
    func137(b);
    
    #pragma oss task weakout(b[981;1]) weakout(b[583;1]) weakinout(b[974;4]) node(2) wait label("func139")
    func139(b);
    
    #pragma oss task weakout(b[556;33]) inout(b[548;5]) node(2) label("func141")
    func141(b);
    
    #pragma oss task weakinout(b[536;12]) if(0) label("func142")
    func142(b);
    
    #pragma oss task weakin(b[254;5]) node(0) label("func143")
    func143(b);
    
    #pragma oss task inout(b[589;7]) weakout(b[545;4]) node(1) label("func144")
    func144(b);
    
    #pragma oss task for in(b[212;43]) chunksize(43) label("taskfor145")
       for(int i=0; i<43; i++) {
    }
    #pragma oss task weakin(b[543;2]) weakin(b[236;1]) in(b[237;17]) node(0) wait label("func146")
    func146(b);
    
    #pragma oss task weakout(b[541;25]) in(b[589;2]) weakout(b[484;36]) node(1) label("func148")
    func148(b);
    
    #pragma oss task weakinout(b[589;7]) weakout(b[966;14]) if(0) label("func149")
    func149(b);
    
    #pragma oss task weakin(b[133;138]) in(b[520;1]) node(1) label("func152")
    func152(b);
    
    #pragma oss task weakin(b[248;12]) weakin(b[205;25]) in(b[260;7]) node(1) wait label("func153")
    func153(b);
    
    #pragma oss task for in(b[175;34]) chunksize(23) label("taskfor154")
       for(int i=0; i<34; i++) {
    }
    #pragma oss task weakin(b[455;29]) weakout(b[979;1]) inout(b[536;5]) node(0) wait label("func155")
    func155(b);
    
    #pragma oss task in(b[146;76]) weakout(b[976;2]) node(1) label("func159")
    func159(b);
    
    #pragma oss task weakinout(b[451;33]) weakout(b[589;2]) in(b[217;52]) node(2) wait label("func160")
    func160(b);
    
    #pragma oss task weakinout(b[451;33]) in(b[208;44]) node(1) label("func161")
    func161(b);
    
    #pragma oss task in(b[520;21]) out(b[972;4]) out(b[541;1]) node(0) wait label("func162")
    func162(b);
    
    #pragma oss task for out(b[971;1]) chunksize(6) label("taskfor165")
       for(int i=0; i<1; i++) {
            b[971+i] = 0xb2bb5af6;
    }
    #pragma oss task in(b[520;2]) node(2) wait label("func166")
    func166(b);
    
    #pragma oss task for in(b[451;22]) chunksize(21) label("taskfor168")
       for(int i=0; i<22; i++) {
    }
    #pragma oss task weakout(b[551;14]) weakin(b[208;41]) weakout(b[973;6]) node(1) wait label("func170")
    func170(b);
    
    #pragma oss task weakin(b[199;66]) weakinout(b[451;33]) node(0) wait label("func171")
    func171(b);
    
    #pragma oss task in(b[971;1]) weakin(b[454;30]) node(1) label("func172")
    func172(b);
    
    #pragma oss task for in(b[265;2]) chunksize(57) label("taskfor173")
       for(int i=0; i<2; i++) {
    }
    #pragma oss task for inout(b[596;1]) chunksize(41) label("taskfor174")
       for(int i=0; i<1; i++) {
            b[596+i] ^= 0x37a63c63;
    }
    #pragma oss task weakout(b[979;1]) in(b[218;27]) weakin(b[245;4]) weakin(b[249;16]) node(1) wait label("func175")
    func175(b);
    
    #pragma oss task for in(b[971;1]) chunksize(98) label("taskfor176")
       for(int i=0; i<1; i++) {
    }
    #pragma oss task in(b[596;2]) weakinout(b[971;1]) node(0) wait label("func177")
    func177(b);
    
}
void func266(int *b)
{
}
void func267(int *b)
{
}
void func269()
{
}
void func270()
{
}
void func271()
{
}
void func273()
{
}
void func274(int *b)
{
}
void func276(int *b)
{
}
void func279(int *b)
{
}
void func280()
{
}
void func281(int *b)
{
}
void func282(int *b)
{
}
void func283(int *b)
{
}
void func285(int *b)
{
}
void func289(int *b)
{
}
void func291(int *b)
{
}
void func292()
{
}
void func296(int *b)
{
}
void func297()
{
}
void func299(int *b)
{
}
void func300(int *b)
{
}
void func302(int *b)
{
}
void func303(int *b)
{
}
void func305(int *b)
{
}
void func306(int *b)
{
}
void func265(int *b)
{
    #pragma oss task in(b[239;1]) node(1) label("func266")
    func266(b);
    
    #pragma oss task out(b[239;1]) node(0) label("func267")
    func267(b);
    
    #pragma oss task  node(1) label("func269")
    func269();
    
    #pragma oss task  node(2) label("func270")
    func270();
    
    #pragma oss task  node(0) label("func271")
    func271();
    
    #pragma oss task for out(b[239;1]) chunksize(98) label("taskfor272")
       for(int i=0; i<1; i++) {
            b[239+i] = 0x100a1089;
    }
    #pragma oss task  node(1) wait label("func273")
    func273();
    
    #pragma oss task out(b[239;1]) node(1) wait label("func274")
    func274(b);
    
    #pragma oss task out(b[237;1]) out(b[194;8]) node(0) label("func276")
    func276(b);
    
    #pragma oss task out(b[151;7]) node(2) label("func279")
    func279(b);
    
    #pragma oss task  node(0) wait label("func280")
    func280();
    
    #pragma oss task weakout(b[239;1]) node(0) label("func281")
    func281(b);
    
    #pragma oss task out(b[202;16]) node(0) label("func282")
    func282(b);
    
    #pragma oss task out(b[151;41]) node(0) label("func283")
    func283(b);
    
    #pragma oss task out(b[90;66]) node(2) label("func285")
    func285(b);
    
    #pragma oss task out(b[186;17]) node(0) wait label("func289")
    func289(b);
    
    #pragma oss task out(b[239;1]) node(1) label("func291")
    func291(b);
    
    #pragma oss task  if(0) label("func292")
    func292();
    
    #pragma oss task out(b[73;11]) if(0) label("func296")
    func296(b);
    
    #pragma oss task  node(2) wait label("func297")
    func297();
    
    #pragma oss task out(b[175;3]) node(1) wait label("func299")
    func299(b);
    
    #pragma oss task weakout(b[75;117]) node(1) wait label("func300")
    func300(b);
    
    #pragma oss task out(b[215;15]) if(0) label("func302")
    func302(b);
    
    #pragma oss task weakout(b[239;1]) node(0) wait label("func303")
    func303(b);
    
    #pragma oss task weakout(b[239;1]) node(2) wait label("func305")
    func305(b);
    
    #pragma oss task weakout(b[188;15]) node(1) label("func306")
    func306(b);
    
}
void func310()
{
}
void func311(int *b)
{
}
void func314()
{
}
void func317(int *b)
{
}
void func318()
{
}
void func321()
{
}
void func325()
{
}
void func326()
{
}
void func327(int *b)
{
}
void func328()
{
}
void func330()
{
}
void func336(int *b)
{
}
void func337(int *b)
{
}
void func338(int *b)
{
}
void func340()
{
}
void func341(int *b)
{
}
void func342(int *b)
{
}
void func344()
{
}
void func345(int *b)
{
}
void func347(int *b)
{
}
void func348(int *b)
{
}
void func355(int *b)
{
}
void func356(int *b)
{
}
void func357(int *b)
{
}
void func309(int *b)
{
    #pragma oss task  node(2) wait label("func310")
    func310();
    
    #pragma oss task weakout(b[353;8]) if(0) label("func311")
    func311(b);
    
    #pragma oss task  node(0) wait label("func314")
    func314();
    
    #pragma oss taskwait
    
    #pragma oss taskwait
    
    #pragma oss task weakout(b[363;10]) node(2) label("func317")
    func317(b);
    
    #pragma oss task  node(2) label("func318")
    func318();
    
    #pragma oss task  node(2) wait label("func321")
    func321();
    
    #pragma oss task  node(1) wait label("func325")
    func325();
    
    #pragma oss task  node(0) label("func326")
    func326();
    
    #pragma oss task weakout(b[320;59]) node(2) label("func327")
    func327(b);
    
    #pragma oss task  node(1) wait label("func328")
    func328();
    
    #pragma oss task  node(0) wait label("func330")
    func330();
    
    #pragma oss task for out(b[389;1]) chunksize(2) label("taskfor332")
       for(int i=0; i<1; i++) {
            b[389+i] = 0x59cad897;
    }
    #pragma oss task weakout(b[343;42]) in(b[389;1]) node(1) wait label("func336")
    func336(b);
    
    #pragma oss task weakout(b[293;34]) node(2) wait label("func337")
    func337(b);
    
    #pragma oss task out(b[288;6]) weakout(b[330;45]) weakinout(b[389;1]) node(1) wait label("func338")
    func338(b);
    
    #pragma oss task  node(2) wait label("func340")
    func340();
    
    #pragma oss task weakin(b[389;1]) node(2) wait label("func341")
    func341(b);
    
    #pragma oss task out(b[375;11]) node(0) wait label("func342")
    func342(b);
    
    #pragma oss task  node(1) wait label("func344")
    func344();
    
    #pragma oss task out(b[328;30]) weakout(b[358;18]) node(1) label("func345")
    func345(b);
    
    #pragma oss task inout(b[389;1]) node(0) wait label("func347")
    func347(b);
    
    #pragma oss task weakin(b[389;1]) node(0) label("func348")
    func348(b);
    
    #pragma oss task for out(b[288;77]) chunksize(53) label("taskfor349")
       for(int i=0; i<77; i++) {
            b[288+i] = 0x9bbdcda5;
    }
    #pragma oss task weakinout(b[300;8]) node(1) label("func355")
    func355(b);
    
    #pragma oss task inout(b[327;18]) node(1) label("func356")
    func356(b);
    
    #pragma oss task out(b[313;70]) node(2) wait label("func357")
    func357(b);
    
}
void func363()
{
}
void func364()
{
}
void func366(int *a,int *b)
{
}
void func368(int *a)
{
}
void func374(int *a,int *b)
{
}
void func376(int *b)
{
}
void func377(int *a,int *b)
{
}
void func379(int *a,int *b)
{
}
void func381(int *a)
{
}
void func382(int *a)
{
}
void func386()
{
}
void func390(int *a)
{
}
void func392(int *a,int *b)
{
}
void func393(int *a,int *b)
{
}
void func394(int *a)
{
}
void func395(int *b)
{
}
void func396(int *b)
{
}
void func397(int *a,int *b)
{
}
void func398(int *b)
{
}
void func400(int *a,int *b)
{
}
void func360(int *a,int *b)
{
    #pragma oss task  if(0) label("func363")
    func363();
    
    #pragma oss taskwait noflush
    
    #pragma oss task  node(1) label("func364")
    func364();
    
    #pragma oss task for out(b[380;1]) chunksize(89) label("taskfor365")
       for(int i=0; i<1; i++) {
            b[380+i] = 0x426fe46a;
    }
    #pragma oss task in(b[380;1]) weakout(a[850;77]) node(1) wait label("func366")
    func366(a,b);
    
    #pragma oss task inout(a[927;15]) node(0) label("func368")
    func368(a);
    
    #pragma oss task for inout(a[927;23]) chunksize(13) label("taskfor372")
       for(int i=0; i<23; i++) {
            a[927+i] ^= 0x9bf1f465;
    }
    #pragma oss task in(a[795;55]) in(b[344;22]) in(a[927;19]) node(2) wait label("func374")
    func374(a,b);
    
    #pragma oss task weakout(b[374;15]) out(b[316;17]) node(1) wait label("func376")
    func376(b);
    
    #pragma oss task weakin(b[338;28]) weakout(b[388;4]) weakout(a[796;34]) node(1) label("func377")
    func377(a,b);
    
    #pragma oss task inout(b[338;32]) weakinout(a[764;32]) node(1) label("func379")
    func379(a,b);
    
    #pragma oss task weakin(a[737;59]) node(1) wait label("func381")
    func381(a);
    
    #pragma oss task inout(a[737;59]) node(2) wait label("func382")
    func382(a);
    
    #pragma oss task for out(a[874;54]) chunksize(37) label("taskfor385")
       for(int i=0; i<54; i++) {
            a[874+i] = 0x65ca51ef;
    }
    #pragma oss task  node(0) label("func386")
    func386();
    
    #pragma oss task out(a[786;37]) node(0) wait label("func390")
    func390(a);
    
    #pragma oss task weakinout(a[874;73]) weakin(b[338;32]) node(2) label("func392")
    func392(a,b);
    
    #pragma oss task in(a[766;20]) weakin(b[338;19]) if(0) label("func393")
    func393(a,b);
    
    #pragma oss task in(a[737;48]) weakinout(a[874;9]) node(2) label("func394")
    func394(a);
    
    #pragma oss task weakinout(b[338;30]) node(2) wait label("func395")
    func395(b);
    
    #pragma oss task weakinout(b[338;17]) node(0) wait label("func396")
    func396(b);
    
    #pragma oss task in(a[737;49]) out(b[376;7]) weakinout(a[874;50]) node(0) wait label("func397")
    func397(a,b);
    
    #pragma oss task inout(b[338;23]) if(0) label("func398")
    func398(b);
    
    #pragma oss task weakin(b[338;24]) weakinout(a[767;19]) weakinout(b[362;7]) node(1) wait label("func400")
    func400(a,b);
    
    #pragma oss task for inout(b[338;32]) chunksize(11) label("taskfor401")
       for(int i=0; i<32; i++) {
            b[338+i] ^= 0x525f0448;
    }
}
void func493()
{
}
void func494()
{
}
void func495()
{
}
void func496()
{
}
void func497()
{
}
void func498()
{
}
void func502()
{
}
void func503()
{
}
void func504()
{
}
void func505()
{
}
void func506()
{
}
void func507()
{
}
void func508()
{
}
void func510()
{
}
void func512()
{
}
void func513()
{
}
void func514()
{
}
void func515()
{
}
void func517()
{
}
void func519()
{
}
void func520()
{
}
void func522()
{
}
void func524()
{
}
void func527()
{
}
void func528()
{
}
void func529()
{
}
void func530()
{
}
void func489()
{
    #pragma oss taskwait noflush
    
    #pragma oss task  node(0) label("func493")
    func493();
    
    #pragma oss task  node(2) label("func494")
    func494();
    
    #pragma oss task  node(1) label("func495")
    func495();
    
    #pragma oss task  node(2) wait label("func496")
    func496();
    
    #pragma oss task  node(0) wait label("func497")
    func497();
    
    #pragma oss task  if(0) label("func498")
    func498();
    
    #pragma oss task  node(2) label("func502")
    func502();
    
    #pragma oss task  if(0) label("func503")
    func503();
    
    #pragma oss task  node(1) label("func504")
    func504();
    
    #pragma oss task  node(1) wait label("func505")
    func505();
    
    #pragma oss task  node(2) wait label("func506")
    func506();
    
    #pragma oss task  node(2) label("func507")
    func507();
    
    #pragma oss task  node(2) wait label("func508")
    func508();
    
    #pragma oss task  node(1) wait label("func510")
    func510();
    
    #pragma oss task  if(0) label("func512")
    func512();
    
    #pragma oss task  node(1) wait label("func513")
    func513();
    
    #pragma oss task  node(1) wait label("func514")
    func514();
    
    #pragma oss task  node(1) wait label("func515")
    func515();
    
    #pragma oss task  node(1) label("func517")
    func517();
    
    #pragma oss task  node(1) wait label("func519")
    func519();
    
    #pragma oss task  node(0) wait label("func520")
    func520();
    
    #pragma oss task  node(0) wait label("func522")
    func522();
    
    //#pragma oss task  node(0) label("func524")
    //func524();
    //
    //#pragma oss task  node(2) wait label("func527")
    //func527();
    //
    //#pragma oss task  node(2) wait label("func528")
    //func528();
    //
    //#pragma oss task  node(2) wait label("func529")
    //func529();
    //
    //#pragma oss task  node(0) wait label("func530")
    //func530();
    
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));

    #pragma oss task  node(0) label("func0")
    func0();
    
    #pragma oss taskwait on(b[120;265])
    
    #pragma oss taskwait on(a[248;436])
    
    #pragma oss task in(b[120;153]) in(a[572;8]) weakout(a[145;317]) if(0) label("func83")
    func83(a,b);
    
    #pragma oss task for inout(a[572;8]) chunksize(6) label("taskfor131")
       for(int i=0; i<8; i++) {
            a[572+i] ^= 0x4ec84f41;
    }
    #pragma oss task out(b[966;16]) in(b[120;153]) out(b[445;154]) node(0) label("func132")
    func132(b);
    
    #pragma oss task for inout(b[120;153]) chunksize(74) label("taskfor178")
       for(int i=0; i<153; i++) {
            b[120+i] ^= 0xb31fb3de;
    }
    #pragma oss task weakout(b[51;188]) weakinout(b[239;1]) node(0) wait label("func265")
    func265(b);
    
    #pragma oss task weakout(b[269;121]) node(1) label("func309")
    func309(b);
    
    #pragma oss task out(b[290;105]) out(a[675;277]) node(1) wait label("func360")
    func360(a,b);
    
    #pragma oss task  node(1) label("func489")
    func489();
    
    #pragma oss taskwait
    
   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 1000 --nesting 2 --seed 11 --watchdog 25 --taskfor --enable-file .simplify/simplify-control.txt]\n");
	
    return(0);
}
	
