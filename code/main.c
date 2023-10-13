#include "rh850.h"



void clk_init(){
	/* Prepare 16MHz MainOsz */                                                                 \
	MOSCC=0x06;             /* Set MainOSC gain (8MHz < MOSC frequency =< 16MHz) */             \
	MOSCST=0xFFFF;          /* Set MainOSC stabilization time to max (8,19 ms) */               \
												\
	PROTCMD0=0xa5;          /* Trigger Enable (protected write) */                              \
	MOSCE=0x01;                                                                                 \
	MOSCE=(~0x01);                                                                              \
	MOSCE=0x01;                                                                                 \
	while (MOSCS != 0x7);   /* Wait for stable MainOSC */                                       \
												\
	/* Prepare PLL*/                                                                            \
	PLLC=0x00000a27;        /*16 MHz MainOSC -> 80MHz PLL */                                    \
	PROTCMD1=0xa5;          /* enable PLL (protected write) */                                  \
	PLLE=0x01;                                                                                  \
	PLLE=(~0x01);                                                                               \
	PLLE=0x01;                                                                                  \
	while(PLLS!=0x07);     /*Wait for stable PLL */                                             \
												\
	/* CPU Clock devider = 1 */                                                                 \
	PROTCMD1=0xa5;                                                                              \
	CKSC_CPUCLKD_CTL=0x01;                                                                      \
	CKSC_CPUCLKD_CTL=(~0x01);                                                                   \
	CKSC_CPUCLKD_CTL=0x01;                                                                      \
	while(CKSC_CPUCLKD_ACT!=0x01);                                                              \
												\
	/* PLL -> CPU Clock */                                                                      \
	PROTCMD1=0xa5;                                                                              \
	CKSC_CPUCLKS_CTL=0x03;                                                                      \
	CKSC_CPUCLKS_CTL=(~0x03);                                                                   \
	CKSC_CPUCLKS_CTL=0x03;                                                                      \
	while(CKSC_CPUCLKS_ACT!=0x03);

}

/*
 * Initialises UART to 9600 8n1
 */
void uart_init(){

	RLN31LUOER = 0x0; // Disable RX & TX


	// Set pins P10_11 and P10_12 as RX and TX
	PM10 = (PM10 & 0xefff) | 0x800;
	PMC10 = PMC10 | 0x1800;
	PFC10 = PFC10 | 0x1800;
	PFCE10 = PFCE10 & 0xe7ff;
	PFCAE10 = PFCAE10 & 0xe7ff;


	
	// Set protection
	PROTCMD1 = 0xa5;
	CKSC_ILINS_CTL = 0x2;
	CKSC_ILINS_CTL = ~0x2;
	CKSC_ILINS_CTL = 0x2;

	while(PROTS1);
	while(CKSC_ILINS_ACT != CKSC_ILINS_CTL);


	// Set protection
	PROTCMD1 = 0xa5;
	CKSC_ILIND_CTL = 0x1;
	CKSC_ILIND_CTL = ~0x1;
	CKSC_ILIND_CTL = 0x1;

	while(PROTS1);
	while(CKSC_ILIND_ACT != CKSC_ILIND_CTL);


	RLN31LCUC &= 0xfe; // Set LIN Reset mode

	while((RLN31LMST & 1) != 0); // Wait for reset mode

	RLN31LMD |= 1; // Set UART mode

	RLN31LWBR = 0x50; // Set sampling
	RLN31LWBR = 0x50; // Set sampling

	RLN31LBRP01 = 0x115; // Set Baud rate prescaler 

	RLN31LMD &= 0xdf; // Enable noise filter

	RLN31LEDE = 0x00; // Disable error detection
	RLN31LBFC = 0x00; // Set 8n1

	RLN31LSC = 0x10; // Set inter-byte space
	RLN31LDFC = 0x01; // Transmit 1 byte


	RLN31LUOR1 = 0x8;


	RLN31LCUC = 0x1; // Set operating mode
	RLN31LUOER = 0x3; // Enable RX & TX
}



/** 
 ** 	Main function, called by _start in vectors.s
**/
void main(void){
	int i, _i;
	char *from, *to;
	clk_init();
	uart_init();

	while(1);

}
