#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[]){

   int min;
   int sec;
 
   struct rtcdate startTime;
   struct rtcdate endTime;
   
  

   if(date(&startTime)){
	printf(2, "date_failed");
	exit();
   }



   int pid = fork();

   if(pid > 0){
      wait();
   
	if(date(&endTime)){
	    printf(2, "date2_failed");
	    exit();
	}
    
    min = endTime.minute - startTime.minute;
    sec = endTime.second - startTime.second;

   if(sec < 0){
	sec = sec + 60;
	min = min-1;
   }

   printf(1, "%s %s %d %s %d %s\n", argv[1],"runs in", min, "minute(s)", sec, "seconds");

   exit();
   }
   else if(pid == 0){
       exec(argv[1], argv+1);
       printf(1, "Error: exec returned");
       
       exit();
   }
   else{

       printf(2,"fork error\n");
       exit();   
   }


  


exit();

}
