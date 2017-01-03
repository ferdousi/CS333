#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


int 
main(int argc, char *argv[])
{
    int uid, gid, ppid;
    uid = getuid();
    printf(1, "Current UID is: %d\n", uid);
    printf(1, "Setting UID to 4\n");

    setuid(4);
    uid = getuid();
    printf(1, "Current UID is: %d\n", uid);

    gid = getgid();
    printf(1, "Current GID is: %d\n", gid);
    printf(1, "Setting GID to 100\n");

    setgid(100);
    gid = getgid();
    printf(1, "Current GID is: %d\n", gid);

    ppid = getppid();
    printf(1, "Current PPID is: %d\n", ppid);



    exit();
}
