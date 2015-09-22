namespace Pokerom
{
	namespace GBEmulator
	{
		/*
		This code is designed to emulate a slight variation on the Zilog Z80 chip

		It is an 8-bit chip, with a 16-bit address buffer (it can address 65,536 bytes of memory)
		Program, RAM and cold storage are accessed through the normal address buffer.
		An instruction is anything between 1 and 3 bytes
		*/

		struct Clocks
		{
			/*
			m = A clock (current instruction time)
			t = A clock (current total instruction time)
			*/
			unsigned short m, t;
			/*
			pm = Previous instruction time?
			pt = ?
			*/
			unsigned short pm, pt;
		};

		struct Registers
		{
			/*
			Various registers contained on the CPU chip
			a = 8-bit accumulator
			f = flag bits
			b/c = 16-bit data/address bus (or 2 8-bit registers)
			d/e =    "     "     "     "    " "   "       "
			h/l = 16-bit accumulator/address bus (or 2 8-bit registers)
			*/
			unsigned char a, b, c, d, e, h, l, f;
			/*16-bit registers
			pc = Program Counter
			sp = Stack pointer
			*/
			unsigned short pc, sp;
		};

		struct CPU
		{
			Clocks clock;
			Registers reg;
		};
	}
}
