/* problem2.c - Activity summary */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
  // if the summary duration is not specified, print an error message
  if (argc != 2)
    {
        printf("Usage: please input the the summary time duration\n");
	return (1);
    }
  
  // get current time and read time duration for summary from the input
  char* timeDuration = argv[1];
  int currentTime = (int)time(NULL);
  int totalExerciseTime = 0;
  
  // startTime of the summary
  int startTime;
  switch (timeDuration[1])
    {
    case 'd':
      startTime = currentTime - atoi(timeDuration) * 24 * 60 * 60;
      break;
    case 'w':
      startTime = currentTime - atoi(timeDuration) * 7 * 24 * 60 * 60;
      break;
    case 'y':
      startTime = currentTime - atoi(timeDuration) * 365 * 7 * 24 * 60 * 60;
      break;
    default:
      printf("Wrong Duration input\n");
      return (1);
    }

  // read activity.tsv and calculate the total exercise time
  FILE * fp = fopen("activity.tsv","r");
  if (fp == NULL)
    {
        printf("File open error\n");
        return(1);
    }
  else
    {
      char line[255];
      int seconds,duration;
      char activity[100],note[100];
      
      // read activity.tsv line by line 
      while(fgets(line,255,fp) != NULL)
	{
           sscanf(line, "%d %s %d %s", &seconds, activity, &duration, note);
	   
         // if the activity time is after start time of summary,
	 // add the exercise time to the exerciseTime in total
	 if (seconds >= startTime)
	     totalExerciseTime = totalExerciseTime + duration;
        }
      printf("Total exercise: %d minutes\n",totalExerciseTime);
      return (0);
    }
}

