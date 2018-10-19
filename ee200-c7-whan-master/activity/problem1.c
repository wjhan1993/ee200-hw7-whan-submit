/* problem1.c - Activity log */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  // If the activity or duration are not specified,
  // print a Usage message
  if (!strcmp(argv[1],"") || !strcmp(argv[2],""))
  {
      printf("Usage: please input activity, duration!\n");
      return(1);
  }
  
  // get current epoch time (seconds since 00:00 January 1, 1970 UTC)
  int seconds = (int)time(NULL);
  
  // read activity, duration and notes from the input
  char* activity = argv[1];
  char* duration = argv[2];
  char* notes = argv[3];

  FILE* fp = fopen ("activity.tsv", "a");
  if (fp == NULL)
    {
        printf("file open error!\n");
	exit(1);
    }
  else
    fprintf(fp,"%d	%s	%s	%s\n", seconds, activity, duration, notes);

  fclose(fp);
  return(0);
}

