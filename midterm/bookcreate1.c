#include <stdio.h>
#include <stdlib.h>
#include "book.h"
int main(int argc, char* argv[])  
{ 
   struct book rec;
   FILE *fp;

   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n",argv[0]);
      exit(1); 
   }

   fp = fopen(argv[1], "wb");
   printf("%-9s %-7s %-4s %-5s %-4s %-4s\n", "StudentID", "Name", "bookwrite","year","count","yn"); 
   while (scanf("%d %s %s %d %d %s", &rec.id, rec.name, rec.write, &rec.year, &rec.count, rec.yn) == 6) 
      fwrite(&rec, sizeof(rec), 1, fp);

   fclose(fp);
   exit(0);
} 

