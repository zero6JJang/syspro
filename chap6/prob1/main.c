#include <sys/types.h> 
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{ 
   int i;
   struct stat buf;
   for (i = 1; i < argc; i++) {
      printf("%s: ", argv[i]);
      if (lstat(argv[i], &buf) < 0) {
         perror("lstat()"); 
         continue;
      }
  if (S_ISREG(buf.st_mode)) 
         printf("%s \n", "regular file\n¼");
      if (S_ISDIR(buf.st_mode)) 
         printf("%s \n", "directory\n¬");
      if (S_ISCHR(buf.st_mode)) 
         printf("%s \n", "character device\n");
      if (S_ISBLK(buf.st_mode)) 
         printf("%s \n", "block device\n");
      if (S_ISFIFO(buf.st_mode)) 
         printf("%s \n", "fifo (named pipe)\n");
      if (S_ISLNK(buf.st_mode)) 
         printf("%s \n", "simbolic link\n");
      if (S_ISSOCK(buf.st_mode)) 
         printf("%s \n", "socket\n ");
   }
   exit(0);
}


