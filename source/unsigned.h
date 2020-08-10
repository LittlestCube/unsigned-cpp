namespace Unsigned
{
	class UnsignedByte
	{
		public:
			char b;
			
			UnsignedByte(char param);
			UnsignedByte(short param);
			UnsignedByte(int param);
			UnsignedByte();
			
			int unsign(char param);
			
			int get();
			int getBit(int position);
			
			int subBits(int from, int to);
			
			void setBit(int position, int value);
			
			void setBits(int from, int to, int* values);
			void setBits(int from, int to, int directValue);
			
			void left(int offset);
			void right(int offset);
			
			void comp();
			
			void set(UnsignedByte param);
			void add(UnsignedByte param);
			void sub(UnsignedByte param);
			void _or(UnsignedByte param);
			void _and(UnsignedByte param);
			void _xor(UnsignedByte param);
			
			void set(char param);
			void add(char param);
			void sub(char param);
			void _or(char param);
			void _and(char param);
			void _xor(char param);
			
			void set(short param);
			void add(short param);
			void sub(short param);
			void _or(short param);
			void _and(short param);
			void _xor(short param);
			
			void set(int param);
			void add(int param);
			void sub(int param);
			void _or(int param);
			void _and(int param);
			void _xor(int param);
	};
	
	class UnsignedShort
	{
		public:
			short s;
			
			UnsignedShort(char param);
			UnsignedShort(short param);
			UnsignedShort(int param);
			UnsignedShort();
			
			int unsign(short param);
			
			int get();
			int getBit(int position);
			
			int subBits(int from, int to);
			
			void setBit(int position, int value);
			
			void setBits(int from, int to, int* values);
			void setBits(int from, int to, int directValue);
			
			void setByte(int position, int nbyte);
			char subByte(int position);
			void craftShort(char nbyte1, char nbyte0);
			
			void left(int offset);
			void right(int offset);
			
			void comp();
			
			void set(UnsignedShort param);
			void add(UnsignedShort param);
			void sub(UnsignedShort param);
			void _or(UnsignedShort param);
			void _and(UnsignedShort param);
			void _xor(UnsignedShort param);
			
			void set(UnsignedByte param);
			void add(UnsignedByte param);
			void sub(UnsignedByte param);
			void _or(UnsignedByte param);
			void _and(UnsignedByte param);
			void _xor(UnsignedByte param);
			
			void set(char param);
			void add(char param);
			void sub(char param);
			void _or(char param);
			void _and(char param);
			void _xor(char param);
			
			void set(short param);
			void add(short param);
			void sub(short param);
			void _or(short param);
			void _and(short param);
			void _xor(short param);
			
			void set(int param);
			void add(int param);
			void sub(int param);
			void _or(int param);
			void _and(int param);
			void _xor(int param);
	};
}