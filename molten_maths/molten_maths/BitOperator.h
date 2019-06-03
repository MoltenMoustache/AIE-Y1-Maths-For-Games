#pragma once
class BitOperator
{
public:
	BitOperator();
	~BitOperator();

	int binToDec(const char* a_binaryString);
	void decToBin(char* a_binaryString, int a_value);
	void setBit(char& a_bitfield, char a_bit, char a_value);
	void checkBit(char& a_bitfield, char a_bit);
};

