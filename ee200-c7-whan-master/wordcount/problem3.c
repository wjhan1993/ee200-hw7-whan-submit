/* problem3.c - Word counting */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
  // lines, words and bytes counts the number of newlines, words and bytes in a file
  int lines = 0;
  bool linePrint = false;
  int words = 0;
  bool wordsPrint = false;
  int bytes = 0;
  bool bytesPrint = false;
  
  char *fileName = NULL;
  int i;

  // check all the input arguments
  for (i = 1;i < argc; i++)
    {
      if (!strcmp(argv[i], "-l"))
	  linePrint = true;
      else
	if (!strcmp(argv[i], "-w"))
	    wordsPrint = true;
	else
	  if (!strcmp(argv[i], "-c"))
	      bytesPrint = true;
	  else
	      fileName = argv[i];
    }

  FILE * fp;
  
  // open the input file if it is specified
  if (fileName != NULL)
    {
       fp = fopen(fileName,"r");
       if (fp == NULL)
	 {
	    printf("File open error!\n");
	    return(1);
	 }
    }
  
    char line[1000];
    // read line by line from stdin or file 
    while (fgets(line, 1000,(fp == NULL)?stdin:fp) != NULL)
    {
        lines = lines + 1;
	int i = 0;

	// lastIsFilled is the broken pointer indicator of words
	int lastIsFilled = 0;
	
	while (line[i] != '\0')
	{
	    bytes = bytes + 1;
	    
	    if (line[i] == ' ')
	      {
		if (lastIsFilled == 1)
		  {
	             words = words + 1;
		     lastIsFilled = 0;
		  }
	      }
	    else
	      lastIsFilled = 1;
	    
	    i = i + 1;
	}
	
	// the line ends with a word
        if (lastIsFilled)
	  words = words + 1;
    }
    
    // print results
    if (!linePrint && !wordsPrint && !bytesPrint)
      printf("%d %d %d",lines, words, bytes);
     
    if (linePrint)
      printf("%d ",lines);
    if (wordsPrint)
      printf("%d ",words);
    if (bytesPrint)
      printf("%d ",bytes);

    // printf fileName if it is not NULL
    if (fileName != NULL)
      printf(" %s",fileName);
    
    printf("\n");
    return(0);   
}
