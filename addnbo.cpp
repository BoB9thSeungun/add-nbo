#include "addnbo.hpp"
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <exception>
#include <iostream>
#include <netinet/in.h>

bool AddNbo(char *fileName1, char *fileName2)
{
	try
	{
		FILE *file1 = fopen(fileName1, "r");
		FILE *file2 = fopen(fileName2, "r");

		char buf[4];

		memset(buf, 0x00, 4);
		fread(buf, 1, 4, file1);

		uint32_t *p = reinterpret_cast<uint32_t*>(buf);
		uint32_t n1 = ntohl(*p);
	
		memset(buf, 0x00, 4);	
		fread(buf, 1, 4, file2);

		p = reinterpret_cast<uint32_t*>(buf);
		uint32_t n2 = ntohl(*p);

		uint32_t result = n1 + n2;

		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, result, result);

		fclose(file2);
		fclose(file1);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
