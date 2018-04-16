/**
 * Leonardo Pereda
 * April 16, 2018
 * Cache Lab Part A 
 */
#include <stdio.h>
#include <unistd.h>
#include "cachelab.h"
#include <stdlib.h>
#include <getopt.h>

void usage();
void readFile(FILE *pfile);

int main(int argc, char **argv)
{
	FILE *pfile;
    int option, h, v, s, E, b, t;
	int debug = 0;
    while((option = getopt(argc, argv, "hvs:E:b:t:")) != -1)
    {
        switch(option)
        {
            case 'h':
              usage();
			  h = 1;
              break;
            case 'v':
              printf("verbose flag ON\n");
              v = 1;
              break;
            case 's':
              s = atoi(optarg);
              break;
            case 'E':
              E = atoi(optarg);
              break;
            case 'b':
              b = atoi(optarg);
              break;
            case 't':
              pfile = fopen(optarg, "r");
			  t = 1;
              break;
            default:
              printf("Invalid argument.\n");
			  usage();
        }
    }
	printf("About to go in to readFile function...\n");
	readFile(pfile);
	if(debug == 1)
	{
		printf("h is %d\n", h);
		printf("v is %d\n", v);
		printf("s is %d\n", s);
		printf("E is %d\n", E);
		printf("b is %d\n", b);
		printf("t is %d\n", t);
	}
	return 0;
}

void readFile(FILE *pfile)
{
	printf("In the readFile function\n");
	if(pfile == NULL)
	{
		perror("Error in opening file\n");
		
	}
	int c = fgetc(pfile);
	while(c != EOF)
	{
		printf("%c", c);
		c = fgetc(pfile);
	}
	fclose(pfile);
}

void usage()
{
    printf("Specific Error [to be displayed here]\n");
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options\n");
    printf("-h          Print this help message.\n");
    printf("-v          Optional verbose flag.\n");
    printf("-s <num>    Number of set index bits.\n");
    printf("-E <num>    Number of lines per set.\n");
    printf("-b <num>    Number of block offset bits.\n");
    printf("-t <file>   Trace file.\n");
}

