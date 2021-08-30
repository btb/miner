/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.  
COPYRIGHT 1993-1998 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/
//This include is just to allow compiling. It doesn't mean it will work. Values in here are only dummy values


//I just put in whatever felt good, consider this file nonesense.
typedef struct  {
	int status;
	int count;
	
} PORT;

#define COM1	0
#define COM2	1
#define COM3	2
#define COM4	3

#define IRQ2	2
#define IRQ3	3
#define IRQ4	4
#define IRQ7	7
#define IRQ15	15

#define ASSUCCESS	1
#define ASBUFREMPTY	0	
#define TRIGGER_04	4

#define ON	1
#define OFF 0


extern PORT *PortOpenGreenleafFast(int port, int baud, char parity, int databits, int stopbits);
extern void SetDtr(PORT *port, int state);
extern void SetRts(PORT *port, int state);
extern void UseRtsCts(PORT *port, int state);
extern void WriteChar(PORT *port, char ch);
extern void ClearRXBuffer(PORT *port);
extern void ReadBufferTimed(PORT *port, char *buf, int a, int b);
extern int  Change8259Priority(int a);
extern int  FastSetPortHardware(short port, int IRQ, int baseaddr);
extern int  FastGetPortHardware(short port, int *IRQ, int *baseaddr);
extern void FastSet16550TriggerLevel(int a);
extern void FastSet16550UseTXFifos(int a);
extern void FastSavePortParameters(short port);
extern int  PortClose(PORT *port);
extern void FastRestorePortParameters(int num);
extern int  GetCd(PORT *port);
extern int  ReadCharTimed(PORT *port, int blah);
extern int  ReadChar(PORT *port);
extern void ClearLineStatus(PORT *port);
extern int  HMInputLine(PORT *port, int a, char *buf, int b);
extern void HMWaitForOK(int a, int b);
extern      HMSendString(PORT *port, char *msg);
extern void HMReset(PORT *port);
extern void HMDial(PORT *port, char *pPhoneNum);
extern void HMSendStringNoWait(PORT *port, char *pbuf,int a);
extern void HMAnswer(PORT *port);
extern void ClearTXBuffer(PORT *port);
extern void WriteBuffer(PORT *port, char *pbuff, int len);

