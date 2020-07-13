#include "addnbo.hpp"
#include <cstdio>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		return 0;
	}

	if(!AddNbo(argv[1], argv[2]))
	{
		printf("Failed\n");
	}

	return 0;
}
