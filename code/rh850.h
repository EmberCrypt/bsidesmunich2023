#ifndef __RH850_H__
#define __RH850_H__


#define ICRLIN31	(*(volatile unsigned short *) 0xFFFFA0E0)
#define ICRLIN31UR0	(*(volatile unsigned short *) 0xFFFFA0E2)
#define ICRLIN31UR1	(*(volatile unsigned short *) 0xFFFFA0E4)
#define ICRLIN31UR2	(*(volatile unsigned short *) 0xFFFFA0E6)

#define PM10		(*(volatile unsigned short *) 0xFFC10328)
#define PMC10		(*(volatile unsigned short *) 0xFFC10428)
#define PFC10		(*(volatile unsigned short *) 0xFFC10528)
#define PFCE10		(*(volatile unsigned short *) 0xFFC10628)
#define PFCAE10		(*(volatile unsigned short *) 0xFFC10A28)


#define MOSCE              (*(volatile unsigned long  *)0xFFF81100)
#define MOSCS              (*(volatile unsigned long  *)0xFFF81104)
#define MOSCC              (*(volatile unsigned long  *)0xFFF81108)
#define MOSCST             (*(volatile unsigned long  *)0xFFF8110C)
#define PLLE               (*(volatile unsigned long  *)0xFFF89000)
#define PLLS               (*(volatile unsigned long  *)0xFFF89004)
#define PLLC               (*(volatile unsigned long  *)0xFFF89008)

#define CKSC_CPUCLKS_CTL   (*(volatile unsigned long  *)0xFFF8A000)
#define CKSC_CPUCLKS_ACT   (*(volatile unsigned long  *)0xFFF8A008)
#define CKSC_CPUCLKD_CTL   (*(volatile unsigned long  *)0xFFF8A100)
#define CKSC_CPUCLKD_ACT   (*(volatile unsigned long  *)0xFFF8A108)

#define PROTCMD0           (*(volatile unsigned long  *)0xFFF80000)

#define PROTCMD1           (*(volatile unsigned long  *)0xFFF88000)
#define PROTS1             (*(volatile unsigned long  *)0xFFF88004)

#define CKSC_ILINS_CTL     (*(volatile unsigned long  *) 0xFFF8A400)
#define CKSC_ILINS_ACT     (*(volatile unsigned long  *) 0xFFF8A408)
#define CKSC_ILIND_CTL     (*(volatile unsigned long  *) 0xFFF8A800)
#define CKSC_ILIND_ACT     (*(volatile unsigned long  *) 0xFFF8A808)


#define RLN31LWBR	(*(volatile unsigned char *) 0xFFCF0041) // LIN Wake-Up Baud Rate Select Register
#define RLN31LBRP01	(*(volatile unsigned short *) 0xFFCF0042)
#define RLN31LMD	(*(volatile unsigned char *) 0xFFCF0048) // LIN Mode Register
#define RLN31LBFC	(*(volatile unsigned char *) 0xFFCF0049)
#define RLN31LSC	(*(volatile unsigned char *) 0xFFCF004a) // LIN Space Configuration register
#define RLN31LEDE	(*(volatile unsigned char *) 0xFFCF004d)
#define RLN31LCUC	(*(volatile unsigned char *) 0xFFCF004e)

#define RLN31LTRC	(*(volatile unsigned char *) 0xFFCF0050) // LIN Transmission Control Register
#define RLN31LMST	(*(volatile unsigned char *) 0xFFCF0051) // LIN Mode Status Register
#define RLN31LST	(*(volatile unsigned char *) 0xFFCF0052) // LIN Status Register
#define RLN31LDFC	(*(volatile unsigned char *) 0xFFCF0054)

#define RLN31LUOER	(*(volatile unsigned char *) 0xFFCF0060) // UART Enable register
#define RLN31LUOR1	(*(volatile unsigned char *) 0xFFCF0061) // UART Option register 1

#define RLN31LUTDR	(*(volatile unsigned char *) 0xFFCF0064) // UART Transmission Data Register



#define FLMDCNT		(*(volatile unsigned long  *)0xFFA00000)
#define FLMDPCMD	(*(volatile unsigned long  *)0xFFA00004)

#define WDTA0WDTE	(*(volatile unsigned char *) 0xffed0000)


#endif
