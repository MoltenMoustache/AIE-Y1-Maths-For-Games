#include "BitOperator.h"
#include <iostream>


BitOperator::BitOperator()
{
}


BitOperator::~BitOperator()
{
}

void BitOperator::decToBin(char* a_binaryString, int a_value)
{
	int i;

	// Add remainer to binary string (this is the binary value of a_value)
	for (i = 0; a_value > 0; i++)
	{
		// Get remainer of a_value / 2 and add it to binary string
		a_binaryString[i] = a_value % 2;
		// divide a_value by 2
		a_value = a_value /= 2;
	}

	// display binary string
	for (i = i--; i < i >= 0; i--)
	{
		std::cout << a_binaryString[i];
	}
	// new line
	std::cout << std::endl;
}

int BitOperator::binToDec(const char* a_binaryString)
{

}
