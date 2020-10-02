#include "commands.h"

void add(int *rd, int *rs, int *rt)
{
	*rd = *rs + *rt;
}

void sub(int *rd, int *rs, int *rt)
{
	*rd = *rs - *rt;
}

void andCom(int *rd, int *rs, int *rt)
{
	*rd = (*rs) & (*rt);
}

void orCom (int *rd, int *rs, int *rt)
{
	*rd = (*rs) | (*rt);
}

void sll(int *rd, int *rs, int *rt)
{
	*rd = (*rs) << (*rt);
}

void sra(int *rd, int *rs, int *rt)
{
	*rd = (*rs) >> (*rt);
	*rd = (*rd) | (*rs & 0x80000000);
}

void newOp(int *rd, int *rs, int *rt)
{
    if (*rt == 0)
    {
        *rd = *rs;
    }
    else
    {
        *rs = *rd;
    }
}

void beq(int *rd, int *rs, int *rt, int *pc)
{
	if ((*rs == *rt))
	{
		*pc = ((*rd) & 0xFFFF) - 1;
	}
}

void bgt(int *rd, int *rs, int *rt, int *pc)
{
	if (*rs > *rt)
	{
		*pc = ((*rd) & 0xFFFF) - 1;
	}
}

void ble(int *rd, int *rs, int *rt, int *pc)
{
	if (*rs <= *rt)
	{
		*pc = ((*rd) & 0xFFFF) - 1;
	}
}

void bne(int *rd, int *rs, int *rt, int *pc)
{
	if (*rs != *rt)
	{
		*pc = ((*rd) & 0xFFFF) - 1;
	}
}

void jal(int *rd, int *pc, int *r15)
{
	*r15 = (*pc) + 1;
	*pc = ((*rd)&(0x7FF));
	*pc = (*pc) - 1;
}

void lw(int *memPtr, int *regDes)
{
	int isNeg;
	*regDes = *(memPtr);
	isNeg = (*memPtr) & 0x8000;
	if (isNeg == 0x8000)
		*regDes = (*regDes) | 0xFFFF0000;
}

void sw(int *memPtr, int *regDes)
{
	*(memPtr) = ((*regDes)&(0xFFFF));
}

void lhi(int *regDes, int *regSrc)
{
	*regDes = (*regDes)&(0xFFFF) + (((*regSrc)&(0xFFFF)) << 16);
}

