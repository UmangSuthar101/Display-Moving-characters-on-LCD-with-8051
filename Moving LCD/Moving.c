#include< reg51.h>
sbit rs=P3^5;   //Register select (RS)
sbit en=P3^6;   //Enable (EN) pin
sbit rw=P3^7;   //Read write (RW) pin
char text[]={"WELCOME LYMBEDGE ROBOTICS               "};

void delay(unsigned int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i< time;i++)
for(j=0;j<10;j++);
}

             //Function for sending values to the command register of LCD
void lcdcmd(unsigned char value)  
{
P2=value;
rs = 0;
    rw = 0;
    en = 1;
delay(50);
en=0;
delay(50);

}
             //Function for sending values to the data register of LCD
void display(unsigned char value)  
{
P2=value;
rs = 1;
rw = 0;
en = 1;
delay(500);
en=0;
delay(50);

}
             //function to initialize the registers and pins of LCD
             //always use with every lcd of hitachi
void lcdint(void)         
{
P2=0x00;    //Port 1 is used as output port             
P3=0x03;    //Port 3 higher bits from 2 to 7 are used as output and lower two bits are used to
            //activate UART 
     delay(5);
     display(0x30);
     delay(4500);
     display(0x30);
     delay(300);
     display(0x30);
     delay(650);
lcdcmd(0x38);
delay(50);
lcdcmd(0x0F);
delay(50);
lcdcmd(0x01);
delay(50);
lcdcmd(0x06);
delay(50);
lcdcmd(0x8F);
delay(50);
}

void main()
{
unsigned int i;

lcdint();
 i=0;
while(text[i]!='\0'){
 display(text[i]);
 delay(200);
 lcdcmd(0x18);
 delay(600);
 i++;
}
}