#include "unsigned.h"

namespace Unsigned
{
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



	inline int UnsignedShort::unsign(short param)
	{
		return param & 0xFFFF;
	}



	inline int UnsignedShort::get()
	{
		return unsign(s);
	}

	inline int UnsignedShort::getBit(int position)
	{
		return ((s & (0x1 << position)) >> position);
	}

	inline int UnsignedShort::subBits(int from, int to)
	{
		int bits = 0;
		
		for (int i = from; i <= to; i++)
		{
			bits |= getBit(i) << (i - from);
		}
		
		return bits;
	}

	inline void UnsignedShort::setBit(int position, int value)
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

	inline void UnsignedShort::setBits(int from, int to, int *values)
	{
		for (int i = 0; i <= to - from; i++)
		{
			setBit(from + i, values[i]);
		}
	}



	inline void UnsignedShort::setBits(int from, int to, int directValue)
	{
		for (int i = from; i <= to; i++)
		{
			setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)));
		}
	}



	inline void UnsignedShort::setByte(int position, int nbyte)
	{
		nbyte = nbyte & 0xFF;
		
		int actualPosition = position * 8;
		
		s = (short) ((nbyte << actualPosition) | (s & ~(0xFF << actualPosition)));
	}

	inline char UnsignedShort::subByte(int position)
	{
		int actualPosition = position * 8;
		
		return (char) ((s & (0xFF << (actualPosition))) >> actualPosition);
	}

	inline void UnsignedShort::craftShort(char byte1, char byte0)
	{
		setByte(1, byte1);
		setByte(0, byte0);
	}



	inline void UnsignedShort::left(int offset)
	{
		s <<= offset;
	}

	inline void UnsignedShort::right(int offset)
	{
		s >>= offset;
	}

	inline void UnsignedShort::comp()
	{
		s = (short) ~s;
	}



	// -------- UnsignedShort parameters --------
	inline void UnsignedShort::set(UnsignedShort param)
	{
		s = param.s;
	}

	inline void UnsignedShort::add(UnsignedShort param)
	{
		s += param.s;
	}

	inline void UnsignedShort::sub(UnsignedShort param)
	{
		add(-param.s);
	}

	inline void UnsignedShort::_or(UnsignedShort param)
	{
		s |= param.s;
	}

	inline void UnsignedShort::_and(UnsignedShort param)
	{
		s &= param.s;
	}

	inline void UnsignedShort::_xor(UnsignedShort param)
	{
		s ^= param.s;
	}



	// ------- char parameters --------
	inline void UnsignedShort::set(char param)
	{
		s = (short) param;
	}

	inline void UnsignedShort::add(char param)
	{
		s += param;
	}

	inline void UnsignedShort::sub(char param)
	{
		add(-param);
	}

	inline void UnsignedShort::_or(char param)
	{
		s |= param;
	}

	inline void UnsignedShort::_and(char param)
	{
		s &= param;
	}

	inline void UnsignedShort::_xor(char param)
	{
		s ^= param;
	}



	// ------ short parameters --------
	inline void UnsignedShort::set(short param)
	{
		s = param;
	}

	inline void UnsignedShort::add(short param)
	{
		s += param;
	}

	inline void UnsignedShort::sub(short param)
	{
		add(-param);
	}

	inline void UnsignedShort::_or(short param)
	{
		s |= param;
	}

	inline void UnsignedShort::_and(short param)
	{
		s &= param;
	}

	inline void UnsignedShort::_xor(short param)
	{
		s ^= param;
	}



	// -------- int parameters --------
	inline void UnsignedShort::set(int param)
	{
		s = (short) param;
	}

	inline void UnsignedShort::add(int param)
	{
		s += param;
	}

	inline void UnsignedShort::sub(int param)
	{
		add(-param);
	}

	inline void UnsignedShort::_or(int param)
	{
		s |= param;
	}

	inline void UnsignedShort::_and(int param)
	{
		s &= param;
	}

	inline void UnsignedShort::_xor(int param)
	{
		s ^= param;
	}
}