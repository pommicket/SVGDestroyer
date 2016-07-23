#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "StringFunctions.h"


int main()
{

	srand(time(NULL));

	char* filename;
	char* buffer;
	long int length;
	FILE* fp;
	int svgPos;
	int startPos;
	int digit1;
	int digit2;
	char replace;
	char with;
	
	filename = malloc(1024);
	
	printf("File to destroy: ");
	fgets(filename, 1024, stdin);
	filename = strtok(filename, "\n");
	
	
	fp = fopen(filename, "rb");

	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		length = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		buffer = malloc(length);
		fread(buffer, 1, length, fp);
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "File not found: %s\n", filename);
		return 1;
	}
	
	svgPos = find(buffer, "<svg", 0);
	startPos = find(buffer, ">", svgPos);

	if (svgPos == -1 || startPos == -1)
	{
		fprintf(stderr, "Error: Is this an SVG file?\n");
		return 1;
	}
	
	digit1 = rand() % 10;
	do
	{
		digit2 = rand() % 10;
	}
	while(digit1 == digit2);
	
	replace = (char)(digit1+48);
	with = (char)(digit2+48);
	
	replaceChar(buffer, replace, with, startPos);
	
	FILE* output = fopen(filename, "w");
	fprintf(output, "%s", buffer);
	fclose(output);
	
	printf("Replaced %c with %c.\n", replace, with);
	
	return 0;

}