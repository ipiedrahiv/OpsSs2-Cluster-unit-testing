// Generated by /home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 1000 --nesting 3 --seed 16 --watchdog 25 --enable-file .simplify/simplify-control.txt
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000010000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000011101111111111100000000000000000000000001111111011110000000000000000000
//00000000000000000001111001101111000000000000011111111111111000000000000010000000
//00000110111111111111111001110111111111111101111011110111000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000010111
//11011011110000000000001111011111110101101111111011111111111101111111110000000000
//00111111111111111111101110000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000001


#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nanos6.h>
#include <unistd.h>
#include <pthread.h>

int watchdog_done = 0;

void *watchdog_func(void *x)
{
	for(int j=0;j<25;j++) {
		sleep(1);
		if (watchdog_done) {
			return NULL;
		}
	}
	printf("Watchdog timer expired (25 seconds)\n");
}


void func224()
{
}
void func226()
{
}
void func227()
{
}
void func228()
{
}
void func229()
{
}
void func230()
{
}
void func231()
{
}
void func232()
{
}
void func233()
{
}
void func223()
{
    #pragma oss task  node(0) wait label("func224")
    func224();
    
    #pragma oss task  node(1) wait label("func226")
    func226();
    
    #pragma oss task  node(0) label("func227")
    func227();
    
    #pragma oss task  node(1) wait label("func228")
    func228();
    
    #pragma oss task  node(0) wait label("func229")
    func229();
    
    #pragma oss taskwait noflush
    
    #pragma oss task  node(1) wait label("func230")
    func230();
    
    #pragma oss task  node(1) wait label("func231")
    func231();
    
    #pragma oss task  node(1) label("func232")
    func232();
    
    #pragma oss task  if(0) label("func233")
    func233();
    
}
void func257()
{
}
void func258(int *a,int *b)
{
}
void func259(int *b)
{
}
void func260()
{
}
void func261(int *a)
{
}
void func263(int *a)
{
}
void func264(int *a,int *b)
{
}
void func265(int *b)
{
}
void func266(int *b)
{
}
void func256(int *a,int *b)
{
    #pragma oss task  node(2) wait label("func257")
    func257();
    
    #pragma oss taskwait
    
    #pragma oss task weakout(b[513;52]) weakin(a[446;1]) node(1) wait label("func258")
    func258(a,b);
    
    #pragma oss task weakout(b[405;147]) node(0) wait label("func259")
    func259(b);
    
    #pragma oss task  node(1) wait label("func260")
    func260();
    
    #pragma oss task in(a[446;1]) node(2) wait label("func261")
    func261(a);
    
    #pragma oss task in(a[446;1]) node(1) wait label("func263")
    func263(a);
    
    #pragma oss task in(b[565;9]) in(a[446;1]) node(1) label("func264")
    func264(a,b);
    
    #pragma oss task weakinout(b[565;9]) node(1) wait label("func265")
    func265(b);
    
    #pragma oss task weakinout(b[565;12]) node(1) wait label("func266")
    func266(b);
    
}
void func301()
{
}
void func302(int *a)
{
}
void func304(int *a)
{
}
void func305()
{
}
void func307(int *a)
{
}
void func308(int *a)
{
}
void func309(int *a)
{
}
void func310(int *a)
{
}
void func300(int *a)
{
    #pragma oss task  node(2) wait label("func301")
    func301();
    
    #pragma oss task in(a[446;1]) node(0) wait label("func302")
    func302(a);
    
    #pragma oss taskwait
    
    #pragma oss task weakin(a[446;1]) node(1) label("func304")
    func304(a);
    
    #pragma oss task  node(1) wait label("func305")
    func305();
    
    #pragma oss task weakin(a[446;1]) node(1) label("func307")
    func307(a);
    
    #pragma oss task in(a[446;1]) node(2) wait label("func308")
    func308(a);
    
    #pragma oss task weakin(a[446;1]) node(1) wait label("func309")
    func309(a);
    
    #pragma oss task in(a[446;1]) node(2) wait label("func310")
    func310(a);
    
}
void func323()
{
}
void func324(int *a)
{
}
void func325(int *a)
{
}
void func326(int *a)
{
}
void func327(int *a)
{
}
void func328()
{
}
void func329(int *a)
{
}
void func330(int *a)
{
}
void func331(int *a)
{
}
void func332(int *a)
{
}
void func322(int *a)
{
    #pragma oss taskwait on(a[446;1])
    
    #pragma oss task  node(1) wait label("func323")
    func323();
    
    #pragma oss task in(a[446;1]) node(1) wait label("func324")
    func324(a);
    
    #pragma oss task weakin(a[446;1]) node(1) wait label("func325")
    func325(a);
    
    #pragma oss task in(a[446;1]) node(0) wait label("func326")
    func326(a);
    
    #pragma oss task weakin(a[446;1]) node(0) wait label("func327")
    func327(a);
    
    #pragma oss task  node(0) label("func328")
    func328();
    
    #pragma oss task in(a[446;1]) if(0) label("func329")
    func329(a);
    
    #pragma oss task weakin(a[446;1]) node(0) label("func330")
    func330(a);
    
    #pragma oss task weakin(a[446;1]) node(1) label("func331")
    func331(a);
    
    #pragma oss task in(a[446;1]) node(0) wait label("func332")
    func332(a);
    
}
void func222(int *a,int *b)
{
    #pragma oss task  node(1) label("func223")
    func223();
    
    #pragma oss taskwait noflush
    
    #pragma oss taskwait noflush
    
    #pragma oss task out(b[405;176]) in(a[446;1]) node(2) wait label("func256")
    func256(a,b);
    
    #pragma oss task in(a[446;1]) node(1) wait label("func300")
    func300(a);
    
    #pragma oss task weakin(a[446;1]) node(1) wait label("func322")
    func322(a);
    
}
void func358(int *a)
{
}
void func359(int *a)
{
}
void func360(int *a)
{
}
void func361(int *a)
{
}
void func362(int *a)
{
}
void func363(int *a)
{
}
void func364(int *a)
{
}
void func365(int *a)
{
}
void func366(int *a)
{
}
void func356(int *a)
{
    #pragma oss taskwait noflush
    
    #pragma oss task weakin(a[470;9]) if(0) label("func358")
    func358(a);
    
    #pragma oss task weakout(a[810;1]) weakin(a[475;3]) node(0) wait label("func359")
    func359(a);
    
    #pragma oss task weakin(a[477;7]) in(a[460;4]) node(2) wait label("func360")
    func360(a);
    
    #pragma oss task weakin(a[460;2]) in(a[487;3]) in(a[470;5]) in(a[484;3]) node(2) label("func361")
    func361(a);
    
    #pragma oss task in(a[489;1]) out(a[805;5]) node(1) label("func362")
    func362(a);
    
    #pragma oss task in(a[460;11]) node(2) label("func363")
    func363(a);
    
    #pragma oss task in(a[471;11]) node(0) label("func364")
    func364(a);
    
    #pragma oss task in(a[465;10]) node(1) wait label("func365")
    func365(a);
    
    #pragma oss task in(a[472;12]) in(a[459;1]) node(0) wait label("func366")
    func366(a);
    
}
void func368(int *a)
{
}
void func369(int *a)
{
}
void func370(int *a)
{
}
void func373(int *a)
{
}
void func374(int *a)
{
}
void func375(int *a)
{
}
void func377(int *a)
{
}
void func367(int *a)
{
    #pragma oss taskwait
    
    #pragma oss task weakout(a[801;1]) out(a[468;1]) node(0) wait label("func368")
    func368(a);
    
    #pragma oss task weakinout(a[466;1]) out(a[800;10]) node(2) wait label("func369")
    func369(a);
    
    #pragma oss taskwait noflush
    
    #pragma oss task weakout(a[467;1]) node(1) wait label("func370")
    func370(a);
    
    #pragma oss task weakin(a[469;1]) weakout(a[808;1]) node(2) wait label("func373")
    func373(a);
    
    #pragma oss task in(a[469;1]) weakin(a[466;1]) node(2) wait label("func374")
    func374(a);
    
    #pragma oss task weakin(a[469;1]) node(2) wait label("func375")
    func375(a);
    
    #pragma oss task weakout(a[466;1]) node(2) wait label("func377")
    func377(a);
    
}
void func379()
{
}
void func380(int *a)
{
}
void func381(int *a)
{
}
void func382(int *a)
{
}
void func383(int *a)
{
}
void func384(int *a)
{
}
void func385(int *a)
{
}
void func386(int *a)
{
}
void func387(int *a)
{
}
void func378(int *a)
{
    #pragma oss taskwait on(a[791;4])
    
    #pragma oss taskwait noflush
    
    #pragma oss task  node(2) label("func379")
    func379();
    
    #pragma oss task in(a[820;1]) weakinout(a[788;1]) if(0) label("func380")
    func380(a);
    
    #pragma oss task out(a[786;8]) node(1) label("func381")
    func381(a);
    
    #pragma oss task weakinout(a[794;1]) node(2) label("func382")
    func382(a);
    
    #pragma oss task in(a[820;1]) out(a[786;2]) node(0) wait label("func383")
    func383(a);
    
    #pragma oss task in(a[820;1]) node(1) label("func384")
    func384(a);
    
    #pragma oss task weakin(a[820;1]) node(2) label("func385")
    func385(a);
    
    #pragma oss task weakin(a[820;1]) weakout(a[789;1]) node(1) wait label("func386")
    func386(a);
    
    #pragma oss task in(a[820;1]) weakin(a[794;1]) node(2) wait label("func387")
    func387(a);
    
}
void func390(int *a)
{
}
void func392(int *a)
{
}
void func393(int *a)
{
}
void func394(int *a)
{
}
void func395(int *a)
{
}
void func397(int *a)
{
}
void func398(int *a)
{
}
void func399(int *a)
{
}
void func389(int *a)
{
    #pragma oss taskwait
    
    #pragma oss task inout(a[504;1]) inout(a[523;6]) node(1) wait label("func390")
    func390(a);
    
    #pragma oss taskwait noflush
    
    #pragma oss task weakout(a[471;3]) weakout(a[528;1]) weakout(a[483;1]) node(0) wait label("func392")
    func392(a);
    
    #pragma oss task weakinout(a[474;1]) node(1) wait label("func393")
    func393(a);
    
    #pragma oss task weakinout(a[508;2]) out(a[481;2]) out(a[521;1]) node(1) wait label("func394")
    func394(a);
    
    #pragma oss task weakinout(a[477;4]) in(a[509;1]) weakout(a[493;16]) node(0) label("func395")
    func395(a);
    
    #pragma oss task weakinout(a[470;1]) in(a[475;4]) in(a[479;2]) node(1) label("func397")
    func397(a);
    
    #pragma oss task weakinout(a[478;1]) inout(a[519;2]) node(1) label("func398")
    func398(a);
    
    #pragma oss task weakinout(a[509;1]) in(a[470;1]) inout(a[518;1]) node(2) wait label("func399")
    func399(a);
    
}
void func333(int *a)
{
    #pragma oss taskwait
    
    #pragma oss taskwait noflush
    
    #pragma oss task weakin(a[458;32]) weakout(a[801;10]) node(1) label("func356")
    func356(a);
    
    #pragma oss task weakinout(a[466;4]) out(a[797;13]) if(0) label("func367")
    func367(a);
    
    #pragma oss task inout(a[786;11]) in(a[820;1]) node(1) wait label("func378")
    func378(a);
    
    #pragma oss task weakinout(a[518;11]) inout(a[469;15]) out(a[487;25]) node(2) label("func389")
    func389(a);
    
}
void func557()
{
}
void func558()
{
}
void func560()
{
}
void func561()
{
}
void func563()
{
}
void func564()
{
}
void func565()
{
}
void func566()
{
}
void func556()
{
    #pragma oss taskwait noflush
    
    #pragma oss taskwait
    
    #pragma oss task  if(0) label("func557")
    func557();
    
    #pragma oss task  node(1) wait label("func558")
    func558();
    
    #pragma oss task  node(2) label("func560")
    func560();
    
    #pragma oss task  node(2) wait label("func561")
    func561();
    
    #pragma oss task  node(0) label("func563")
    func563();
    
    #pragma oss task  if(0) label("func564")
    func564();
    
    #pragma oss task  node(1) wait label("func565")
    func565();
    
    #pragma oss task  node(2) label("func566")
    func566();
    
}
void func579()
{
}
void func580()
{
}
void func581()
{
}
void func583()
{
}
void func584(int *a)
{
}
void func585()
{
}
void func586()
{
}
void func587()
{
}
void func588(int *a)
{
}
void func578(int *a)
{
    #pragma oss task  node(2) label("func579")
    func579();
    
    #pragma oss task  if(0) label("func580")
    func580();
    
    #pragma oss task  node(2) wait label("func581")
    func581();
    
    #pragma oss task  node(2) wait label("func583")
    func583();
    
    #pragma oss task weakout(a[661;3]) node(2) wait label("func584")
    func584(a);
    
    #pragma oss task  node(2) wait label("func585")
    func585();
    
    #pragma oss task  node(2) wait label("func586")
    func586();
    
    #pragma oss task  node(0) wait label("func587")
    func587();
    
    #pragma oss task weakout(a[661;2]) node(2) wait label("func588")
    func588(a);
    
}
void func591()
{
}
void func593()
{
}
void func595()
{
}
void func596()
{
}
void func597()
{
}
void func598()
{
}
void func599()
{
}
void func589()
{
    #pragma oss task  node(0) wait label("func591")
    func591();
    
    #pragma oss taskwait
    
    #pragma oss task  node(2) label("func593")
    func593();
    
    #pragma oss task  node(0) label("func595")
    func595();
    
    #pragma oss task  node(0) label("func596")
    func596();
    
    #pragma oss task  node(2) label("func597")
    func597();
    
    #pragma oss task  node(2) label("func598")
    func598();
    
    #pragma oss task  if(0) label("func599")
    func599();
    
}
void func601()
{
}
void func602()
{
}
void func603()
{
}
void func604()
{
}
void func605()
{
}
void func606()
{
}
void func607()
{
}
void func608()
{
}
void func609()
{
}
void func610()
{
}
void func600()
{
    #pragma oss taskwait noflush
    
    #pragma oss task  node(0) label("func601")
    func601();
    
    #pragma oss task  node(1) label("func602")
    func602();
    
    #pragma oss task  if(0) label("func603")
    func603();
    
    #pragma oss task  node(0) label("func604")
    func604();
    
    #pragma oss task  node(1) wait label("func605")
    func605();
    
    #pragma oss task  node(1) label("func606")
    func606();
    
    #pragma oss task  node(2) wait label("func607")
    func607();
    
    #pragma oss task  if(0) label("func608")
    func608();
    
    #pragma oss task  node(0) wait label("func609")
    func609();
    
    #pragma oss task  node(0) wait label("func610")
    func610();
    
}
void func613()
{
}
void func614()
{
}
void func615()
{
}
void func616()
{
}
void func617()
{
}
void func618()
{
}
void func619()
{
}
void func620()
{
}
void func621()
{
}
void func611()
{
    #pragma oss taskwait
    
    #pragma oss task  if(0) label("func613")
    func613();
    
    #pragma oss task  node(2) wait label("func614")
    func614();
    
    #pragma oss task  node(2) label("func615")
    func615();
    
    #pragma oss task  node(1) wait label("func616")
    func616();
    
    #pragma oss task  if(0) label("func617")
    func617();
    
    #pragma oss task  node(0) wait label("func618")
    func618();
    
    #pragma oss task  node(1) wait label("func619")
    func619();
    
    #pragma oss task  if(0) label("func620")
    func620();
    
    #pragma oss task  node(1) wait label("func621")
    func621();
    
}
void func634()
{
}
void func635(int *a)
{
}
void func636(int *a)
{
}
void func637()
{
}
void func638(int *a)
{
}
void func639(int *a)
{
}
void func640(int *a)
{
}
void func641(int *a)
{
}
void func642(int *a)
{
}
void func643()
{
}
void func633(int *a)
{
    #pragma oss task  node(0) wait label("func634")
    func634();
    
    #pragma oss task weakin(a[645;1]) node(1) wait label("func635")
    func635(a);
    
    #pragma oss task weakin(a[645;1]) node(2) wait label("func636")
    func636(a);
    
    #pragma oss task  node(1) label("func637")
    func637();
    
    #pragma oss task in(a[645;1]) node(2) wait label("func638")
    func638(a);
    
    #pragma oss task in(a[645;1]) node(0) wait label("func639")
    func639(a);
    
    #pragma oss task weakin(a[645;1]) node(1) wait label("func640")
    func640(a);
    
    #pragma oss task weakin(a[645;1]) node(0) wait label("func641")
    func641(a);
    
    #pragma oss task weakin(a[645;1]) node(2) label("func642")
    func642(a);
    
    #pragma oss task  node(2) wait label("func643")
    func643();
    
}
void func645()
{
}
void func646(int *a)
{
}
void func647()
{
}
void func648(int *a)
{
}
void func649()
{
}
void func650()
{
}
void func651()
{
}
void func652(int *a)
{
}
void func653()
{
}
void func644(int *a)
{
    #pragma oss task  node(0) label("func645")
    func645();
    
    #pragma oss task weakout(a[627;1]) node(1) label("func646")
    func646(a);
    
    #pragma oss task  node(0) wait label("func647")
    func647();
    
    #pragma oss taskwait
    
    #pragma oss task out(a[626;1]) node(2) label("func648")
    func648(a);
    
    #pragma oss task  node(2) label("func649")
    func649();
    
    #pragma oss task  node(2) wait label("func650")
    func650();
    
    #pragma oss task  node(0) wait label("func651")
    func651();
    
    #pragma oss task weakout(a[626;1]) node(2) wait label("func652")
    func652(a);
    
    #pragma oss task  node(1) label("func653")
    func653();
    
}
void func555(int *a)
{
    #pragma oss task  if(0) label("func556")
    func556();
    
    #pragma oss task weakout(a[659;5]) if(0) label("func578")
    func578(a);
    
    #pragma oss task  node(2) wait label("func589")
    func589();
    
    #pragma oss task  node(1) label("func600")
    func600();
    
    #pragma oss task  node(0) label("func611")
    func611();
    
    #pragma oss task in(a[645;1]) node(1) wait label("func633")
    func633(a);
    
    #pragma oss task out(a[625;3]) node(1) wait label("func644")
    func644(a);
    
}
void func999(int *a)
{
}


int main(void)
{
	int *a = nanos6_dmalloc(1000 * sizeof(int), nanos6_equpart_distribution, 0, NULL);
	int *b = nanos6_lmalloc(1000 * sizeof(int));


	pthread_t watchdog;
	if (pthread_create(&watchdog, NULL, watchdog_func, NULL)) {
		return 1;
	}

    #pragma oss taskwait on(a[387;522])
    
    #pragma oss task out(b[99;533]) weakin(a[446;1]) node(1) label("func222")
    func222(a,b);
    
    #pragma oss task weakinout(a[785;47]) inout(a[446;86]) node(0) label("func333")
    func333(a);
    
    #pragma oss task out(a[382;283]) weakout(a[665;197]) node(2) wait label("func555")
    func555(a);
    
    #pragma oss task in(a[862;1]) weakout(a[91;16]) if(0) label("func999")
    func999(a);
    
    #pragma oss taskwait
    

   nanos6_dfree(a, 1000 * sizeof(int));
   nanos6_lfree(b, 1000 * sizeof(int));
     watchdog_done = 1;
    pthread_join(watchdog, NULL);

    printf("Test passed [/home/bsc28/bsc28600/work/20201023-experimental/ompss-2-testgen/ompss-2-testgen --nodes 3 --tasks 1000 --nesting 3 --seed 16 --watchdog 25 --enable-file .simplify/simplify-control.txt]\n");
	
    return(0);
}
	
