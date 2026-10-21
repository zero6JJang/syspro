#include <stdio.h> 
#include "book.h"
  
int main(int argc, char* argv[]) { 
   struct student rec;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   fp = fopen(argv[1], "r");
   printf("%-9s %-7s %-4s %-4s %-4s %-4s", "bookID", "Name", "bokwrite","year","count","y/n"); 
   while (fscanf(fp,"%d %s %s %d %d %s ", &rec.id, &rec.name, &rec.write, &year,&count,&y/n)==6) 
      printf("%10d %6s %6d %3d %3d %3d\n", rec.id, rec.name, rec.write,rec.year,rec.count,rec.y/n);
   fclose(fp);
   return 0;
} 

