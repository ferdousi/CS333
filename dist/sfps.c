#include "types.h"
#include "user.h"
#include "ps.h"

#define MAX_PROC 7
int 
main(int argc, char *argv[])
{
    int processes;
    int i;
    struct uproc prc[MAX_PROC];

    processes = getprocs(MAX_PROC, prc);
//    printf(1,"%d\n", processes);  
    
	if(processes == -1){
	    printf(2, "getprocs failed\n");
	    exit();
	}

       printf(1, "\nPID PPID UID GID STATE SIZE NAME");	

       for(i=0; i<processes;i++){ 
	    printf(1,"\n%d  %d  %d  %d  %s  %d  %s\n ", prc[i].pid, prc[i].ppid, prc[i].uid, prc[i].gid, prc[i].state, prc[i].size, prc[i].name);

       }
    exit();

}
