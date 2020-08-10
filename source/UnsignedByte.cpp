#include "unsigned.h"

namespace Unsigned
{
	UnsignedByte::UnsignedByte(char param)
	{
		set(param);
	}

	UnsignedByte::UnsignedByte(short param)
	{
		set(param);
	}

	UnsignedByte::UnsignedByte(int param)
	{
		set(param);
	}

	UnsignedByte::UnsignedByte()
	{
		set(0);
	}



	inline int UnsignedByte::unsign(char param)
	{
		return param & 0xFF;
	}

	inline int UnsignedByte::get()
	{
		return unsign(b);
	}

	inline int UnsignedByte::getBit(int position)
	{
		return ((b & (0x1 << position)) >> position);
	}

	inline int UnsignedByte::subBits(int from, int to)
	{
		int bits = 0;
		
		for (int i = from; i <= to; i++)
		{
			bits |= getBit(i) << (i - from);
		}
		
		return bits;
	}

	inline void UnsignedByte::setBit(int position, int value)
	{
		value %= 2;
		
		if (value == 0)
		{
			b = (char) (b & ~((0x1 << position)));
		}
		
		else
		{
			b = (char) (b | (0x1 << position));
		}
	}

	inline void UnsignedByte::setBits(int from, int to, int* values)
	{
		for (int i = 0; i <= to - from; i++)
		{
			setBit(from + i, values[i]);
		}
	}



	inline void UnsignedByte::setBits(int from, int to, int directValue)
	{
		for (int i = from; i <= to; i++)
		{
			setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)));
		}
	}



	inline void UnsignedByte::left(int offset)
	{
		b <<= offset;
	}

	inline void UnsignedByte::right(int offset)
	{
		b >>= offset;
	}

	inline void UnsignedByte::comp()
	{
		b = (char) ~b;
	}



	// -------- UnsignedByte parameters --------
	inline void UnsignedByte::set(UnsignedByte param)
	{
		b = param.b;
	}

	inline void UnsignedByte::add(UnsignedByte param)
	{
		b += param.get();
	}

	inline void UnsignedByte::sub(UnsignedByte param)
	{
		add(-param.get());
	}

	inline void UnsignedByte::_or(UnsignedByte param)
	{
		b |= param.b;
	}

	inline void UnsignedByte::_and(UnsignedByte param)
	{
		b &= param.b;
	}

	inline void UnsignedByte::_xor(UnsignedByte param)
	{
		b ^= param.b;
	}



	// ------- char parameters --------
	inline void UnsignedByte::set(char param)
	{
		b = param;
	}

	inline void UnsignedByte::add(char param)
	{
		b += param;
	}

	inline void UnsignedByte::sub(char param)
	{
		add(-param);
	}

	inline void UnsignedByte::_or(char param)
	{
		b |= param;
	}

	inline void UnsignedByte::_and(char param)
	{
		b &= param;
	}

	inline void UnsignedByte::_xor(char param)
	{
		b ^= param;
	}



	// ------ short parameters --------
	inline void UnsignedByte::set(short param)
	{
		b = (char) param;
	}

	inline void UnsignedByte::add(short param)
	{
		b += param;
	}

	inline void UnsignedByte::sub(short param)
	{
		add(-param);
	}

	inline void UnsignedByte::_or(short param)
	{
		b |= param;
	}

	inline void UnsignedByte::_and(short param)
	{
		b &= param;
	}

	inline void UnsignedByte::_xor(short param)
	{
		b ^= param;
	}



	// -------- int parameters --------
	inline void UnsignedByte::set(int param)
	{
		b = (char) param;
	}

	inline void UnsignedByte::add(int param)
	{
		b += param;
	}

	inline void UnsignedByte::sub(int param)
	{
		add(-param);
	}

	inline void UnsignedByte::_or(int param)
	{
		b |= param;
	}

	inline void UnsignedByte::_and(int param)
	{
		b &= param;
	}

	inline void UnsignedByte::_xor(int param)
	{
		b ^= param;
	}
}