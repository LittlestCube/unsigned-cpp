class UnsignedShort
{
	public:
		short s;
		
		UnsignedShort(char param)
		{
			set(param);
		}
		
		UnsignedShort(short param)
		{
			set(param);
		}
		
		UnsignedShort(int param)
		{
			set(param);
		}
		
		UnsignedShort()
		{
			set(0);
		}
		
		
		
		int unsign(short param)
		{
			return param & 0xFFFF;
		}
		
		
		
		int get()
		{
			return unsign(s);
		}
		
		int getBit(int position)
		{
			return ((s & (0x1 << position)) >> position);
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
				s = (short) (s & ~((0x1 << position)));
			}
			
			else
			{
				s = (short) (s | (0x1 << position));
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
		
		
		
		void setByte(int position, int nbyte)
		{
			nbyte = nbyte & 0xFF;
			
			int actualPosition = position * 8;
			
			s = (short) ((nbyte << actualPosition) | (s & ~(0xFF << actualPosition)));
		}
		
		char subByte(int position)
		{
			int actualPosition = position * 8;
			
			return (char) ((s & (0xFF << (actualPosition))) >> actualPosition);
		}
		
		void craftShort(char byte1, char byte0)
		{
			setByte(1, byte1);
			setByte(0, byte0);
		}
		
		
		
		void left(int offset)
		{
			s <<= offset;
		}
		
		void right(int offset)
		{
			s >>= offset;
		}
		
		void comp()
		{
			s = (short) ~s;
		}
		
		
		
		// ------- char parameters --------
		void set(char param)
		{
			s = (short) param;
		}
		
		void add(char param)
		{
			s += param;
		}
		
		void sub(char param)
		{
			add(-param);
		}
		
		void _or(char param)
		{
			s |= param;
		}
		
		void _and(char param)
		{
			s &= param;
		}
		
		void _xor(char param)
		{
			s ^= param;
		}
		
		
		
		// ------ short parameters --------
		void set(short param)
		{
			s = param;
		}
		
		void add(short param)
		{
			s += param;
		}
		
		void sub(short param)
		{
			add(-param);
		}
		
		void _or(short param)
		{
			s |= param;
		}
		
		void _and(short param)
		{
			s &= param;
		}
		
		void _xor(short param)
		{
			s ^= param;
		}
		
		
		
		// -------- int parameters --------
		void set(int param)
		{
			s = (short) param;
		}
		void add(int param)
		{
			s += param;
		}
		
		void sub(int param)
		{
			add(-param);
		}
		
		void _or(int param)
		{
			s |= param;
		}
		
		void _and(int param)
		{
			s &= param;
		}
		
		void _xor(int param)
		{
			s ^= param;
		}
};