#include "config.h"

void add(int *rd, int *rs, int *rt);

void sub(int *rd, int *rs, int *rt);

void andCom(int *rd, int *rs, int *rt);

void orCom (int *rd, int *rs, int *rt);

void sll(int *rd, int *rs, int *rt);

void sra(int *rd, int *rs, int *rt);

void newOp(int *rd, int *rs, int *rt);

void beq(int *rd, int *rs, int *rt, int *pc);

void bgt(int *rd, int *rs, int *rt, int *pc);

void ble(int *rd, int *rs, int *rt, int *pc);

void bne(int *rd, int *rs, int *rt, int *pc);

void jal(int *rd, int *pc, int *r15);


void lw(int *memPtr, int *regDes);


void sw(int *memPtr, int *regDes);

void lhi(int *regDes, int *regSrc);
