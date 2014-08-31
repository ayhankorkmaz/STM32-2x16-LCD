/*************************************************************
* Dosya   : LCD
* Ama�    : STM32F1xx kullanarak 2x16 LCD kullan�m�
* Yazar   : Ayhan Korkmaz - AyhanKorkmaz.Net
* �leti�im: info@ayhankorkmaz.net
* Test    : STM32VLDiscovery Kart� ve 2x16
*           LCD �st�nde test edilmi�tir.
**************************************************************/

#include "stm32f10x.h"
#include "lcd.h"
#include "stm32f10x_rcc.h" 

unsigned char gozlem=0,Veri[30];
const char Yazi[]={"AyhanKorkmaz.Net"},Yazi1[]={"     2*16 LCD    "};
char k=12,i,j;

/********************************************************
Fonksiyon :Main
Amac	  :Ana Fonksiyondur
Kullanim  : -
*********************************************************/
int main(void)
{
 uint8_t i,k,l=16;
 lcd_hazirla();  
 lcd_temizle();
 lcd_git_xy(1,1);
 lcd_yazi_yaz("AyhanKorkmaz.Net");

 lcd_git_xy(2,1);
 lcd_yazi_yaz("Gururla Sunar!");
 delay(0x000fffff);
 delay(0x00ffffff);
 lcd_temizle();
 for(i=1;i<=16;i++)
 {
   lcd_git_xy(1,i);
   lcd_karakter_yaz(Yazi[i-1]);
   delay(0x0005ffff);
 }
 for(k=0;k<2;k++)
 {
 lcd_temizle();
 delay(0x0005ffff);
 delay(0x0005ffff);
 lcd_git_xy(1,1);
 lcd_yazi_yaz("AyhanKorkmaz.Net");
 delay(0x000fffff);
 delay(0x000fffff);
 }
 for(i=16;i>0;i--)
  {  
  lcd_git_xy(2,i);
  lcd_karakter_yaz(Yazi1[l]);
  delay(0x000Affff);
  l--;
  
  }
 lcd_temizle();
 lcd_git_xy(1,1);
 lcd_yazi_yaz("�����");
 delay(0x000fffff);
 delay(0x000fffff);
  delay(0x000fffff);
 delay(0x000fffff);
 lcd_temizle();
 lcd_git_xy(1,1);
 lcd_yazi_yaz("T�rk�e yaz�");
 lcd_git_xy(2,1);
 lcd_yazi_yaz("Yazabiliriniz!");
  delay(0x000fffff);
 delay(0x000fffff);
  delay(0x000fffff);
 delay(0x000fffff);
   delay(0x000fffff);
 delay(0x000fffff);
  delay(0x000fffff);
 delay(0x000fffff);
 for(k=0;k<2;k++)
 {
 lcd_temizle();
 delay(0x0005ffff);
 delay(0x0005ffff);
 lcd_git_xy(1,1);
 lcd_yazi_yaz("AyhanKorkmaz.Net");
 delay(0x000fffff);
 delay(0x000fffff);
 }
  lcd_temizle();
 delay(0x0005ffff);
 delay(0x0005ffff);
 lcd_git_xy(1,1);
 lcd_yazi_yaz("AyhanKorkmaz.Net");
 lcd_git_xy(2,1);
 lcd_yazi_yaz("Takipte Kal�n");
  while (1) 
  {

  }
}
