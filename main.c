#include<ioCC2530.h>
void delay(void)
{
 unsigned int i;
  unsigned char j;
  for(i=0;i<1500;i++)
  {
    for(j=0;j<200;j++)
    {
      asm("nop");
            asm("nop");
                  asm("nop");
    }
  }
}
void main( void )
{
  /* 配置P0_0 P2_0为通用IO口功能 */
    P0SEL &= ~(0x1 << 0);
    P2SEL &= ~(0x1 << 0);
    P0DIR |= 0x01;  // 设置P1.0为输出方式，复位后为普通I/O输入口
  P2DIR |= 0x01;  // 设置P2.0为输出方式，复位后为普通I/O输入口
  
  while(1)
  {
     P0_0 = 0;  // 设置P0.0输出低电平，那么就能点亮D2发光二极管
     P2_0 = 0;  // 设置P2.0输出低电平，那么就能点亮D3发光二极管
     
     delay();   // 延时子程序，延时大概400ms
     
     P0_0 = 1;  // 设置P0.0输出高电平，那么就能熄灭D2发光二极管
     P2_0 = 1;  // 设置P2.0输出高电平，那么就能熄灭D3发光二极管
     
     delay();    
  }
} // end of main()
