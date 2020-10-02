struct command {
	int binCommand;	// The original command from memory (4 bytes)
	int opcode;
	int rs;
	int rt;
	int rd;
};


void load_Fib();

void load_Lights();

void memToArr();

void changeLed(int *IORegisters);

int excecute_command(struct command newComm, int *regs, int *IORegisters, int *pc);

void testImm(struct command newComm, int *pc);

void updateComm(struct command *newComm, int *pc);

void newCommFunc(struct command *newComm, int *pc);

void initComm(struct command *newComm, int *pc);

void displayOnScreen(int *lastSWState, char *strToLCD, int *count, int *firstMemSW, struct command newComm);

void scanArr(int *pc, int *regs, int *IORegisters);

void Timer5Setup();

void Timer4Setup();


