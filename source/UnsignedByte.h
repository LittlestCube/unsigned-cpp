class UnsignedByte
{
	public:
		signed char b;
		
		UnsignedByte(char param)
		{
			set(param);
		}
		
		UnsignedByte(short param)
		{
			set(param);
		}
		
		UnsignedByte(int param)
		{
			set(param);
		}
		
		UnsignedByte()
		{
			set(0);
		}
		
		
		
		int unsign(char param)
		{
			return param & 0xFF;
		}
		
		int get()
		{
			return unsign(b);
		}
		
		int getBit(int position)
		{
			return ((b & (0x1 << position)) >> position);
		}
		
		int subBits(int from, int to)
		{
			int bits = 0;
			
			for (int i = from; i <= to; i++)
			{
				bits |= getBit(i) << (i - from);
			}
			
			return bits;
		}
		
		void setBit(int position, int value)
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
		
		void setBits(int from, int to, int *values)
		{
			for (int i = 0; i <= to - from; i++)
			{
				setBit(from + i, values[i]);
			}
		}
		
		
		
		void setBits(int from, int to, int directValue)
		{
			for (int i = from; i <= to; i++)
			{
				setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)));
			}
		}
		
		
		
		void left(int offset)
		{
			b <<= offset;
		}
		
		void right(int offset)
		{
			b >>= offset;
		}
		
		void comp()
		{
			b = (char) ~b;
		}
		
		
		
		// ------- char parameters --------
		void set(char param)
		{
			b = param;
		}
		
		void add(char param)
		{
			b += param;
		}
		
		void sub(char param)
		{
			add(-param);
		}
		
		void _or(char param)
		{
			b |= param;
		}
		
		void _and(char param)
		{
			b &= param;
		}
		
		void _xor(char param)
		{
			b ^= param;
		}
		
		
		
		// ------ short parameters --------
		void set(short param)
		{
			b = (char) param;
		}
		
		void add(short param)
		{
			b += param;
		}
		
		void sub(short param)
		{
			add(-param);
		}
		
		void _or(short param)
		{
			b |= param;
		}
		
		void _and(short param)
		{
			b &= param;
		}
		
		void _xor(short param)
		{
			b ^= param;
		}
		
		
		
		// -------- int parameters --------
		void set(int param)
		{
			b = (char) param;
		}
		
		void add(int param)
		{
			b += param;
		}
		
		void sub(int param)
		{
			add(-param);
		}
		
		void _or(int param)
		{
			b |= param;
		}
		
		void _and(int param)
		{
			b &= param;
		}
		
		void _xor(int param)
		{
			b ^= param;
		}
};