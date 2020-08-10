#include "unsigned.h"

UnsignedShort::UnsignedShort(char param)
{
	set(param);
}

UnsignedShort::UnsignedShort(short param)
{
	set(param);
}

UnsignedShort::UnsignedShort(int param)
{
	set(param);
}

UnsignedShort::UnsignedShort()
{
	set(0);
}



int UnsignedShort::unsign(short param)
{
	return param & 0xFFFF;
}



int UnsignedShort::get()
{
	return unsign(s);
}

int UnsignedShort::getBit(int position)
{
	return ((s & (0x1 << position)) >> position);
}

int UnsignedShort::subBits(int from, int to)
{
	int bits = 0;
	
	for (int i = from; i <= to; i++)
	{
		bits |= getBit(i) << (i - from);
	}
	
	return bits;
}

void UnsignedShort::setBit(int position, int value)
{
	value %= 2;
	
	if (value == 0)
	{
		s = (short) (s & ~((0x1 << position)));
	}
	
	else
	{
		s = (short) (s | (0x1 << position));
	}
}

void UnsignedShort::setBits(int from, int to, int *values)
{
	for (int i = 0; i <= to - from; i++)
	{
		setBit(from + i, values[i]);
	}
}



void UnsignedShort::setBits(int from, int to, int directValue)
{
	for (int i = from; i <= to; i++)
	{
		setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)));
	}
}



void UnsignedShort::setByte(int position, int nbyte)
{
	nbyte = nbyte & 0xFF;
	
	int actualPosition = position * 8;
	
	s = (short) ((nbyte << actualPosition) | (s & ~(0xFF << actualPosition)));
}

char UnsignedShort::subByte(int position)
{
	int actualPosition = position * 8;
	
	return (char) ((s & (0xFF << (actualPosition))) >> actualPosition);
}

void UnsignedShort::craftShort(char byte1, char byte0)
{
	setByte(1, byte1);
	setByte(0, byte0);
}



void UnsignedShort::left(int offset)
{
	s <<= offset;
}

void UnsignedShort::right(int offset)
{
	s >>= offset;
}

void UnsignedShort::comp()
{
	s = (short) ~s;
}



// -------- UnsignedShort parameters --------
void UnsignedShort::set(UnsignedShort param)
{
	s = param.s;
}

void UnsignedShort::add(UnsignedShort param)
{
	s += param.s;
}

void UnsignedShort::sub(UnsignedShort param)
{
	add(-param.s);
}

void UnsignedShort::_or(UnsignedShort param)
{
	s |= param.s;
}

void UnsignedShort::_and(UnsignedShort param)
{
	s &= param.s;
}

void UnsignedShort::_xor(UnsignedShort param)
{
	s ^= param.s;
}



// ------- char parameters --------
void UnsignedShort::set(char param)
{
	s = (short) param;
}

void UnsignedShort::add(char param)
{
	s += param;
}

void UnsignedShort::sub(char param)
{
	add(-param);
}

void UnsignedShort::_or(char param)
{
	s |= param;
}

void UnsignedShort::_and(char param)
{
	s &= param;
}

void UnsignedShort::_xor(char param)
{
	s ^= param;
}



// ------ short parameters --------
void UnsignedShort::set(short param)
{
	s = param;
}

void UnsignedShort::add(short param)
{
	s += param;
}

void UnsignedShort::sub(short param)
{
	add(-param);
}

void UnsignedShort::_or(short param)
{
	s |= param;
}

void UnsignedShort::_and(short param)
{
	s &= param;
}

void UnsignedShort::_xor(short param)
{
	s ^= param;
}



// -------- int parameters --------
void UnsignedShort::set(int param)
{
	s = (short) param;
}

void UnsignedShort::add(int param)
{
	s += param;
}

void UnsignedShort::sub(int param)
{
	add(-param);
}

void UnsignedShort::_or(int param)
{
	s |= param;
}

void UnsignedShort::_and(int param)
{
	s &= param;
}

void UnsignedShort::_xor(int param)
{
	s ^= param;
}