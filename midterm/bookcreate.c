#include <stdio.h>
#include "book.h"
int main(int argc,char* argv[])
{
	struct student rec;
	FILE *fp;
	if(argc != 2){
		fprintf(stderr,"How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   fp = fopen(argv[1], "w");
   printf("%-9s %-7s %-4s %-4s %-2s %-5s", "bookID", "Name", "bookwrite","year","count","y/n"); 
   while (scanf("%d %s %d %d %d %s", &rec.id, rec.name, &rec.write, $rec.year $rec.count %rec.y/n)==6)
	   fprintf(fp, "%d %s %d %d %d %s ", rec.id, rec.name, rec.write, rec.year, re.count,rec.y/n);
   fclose(fp);
   return 0;
} 
