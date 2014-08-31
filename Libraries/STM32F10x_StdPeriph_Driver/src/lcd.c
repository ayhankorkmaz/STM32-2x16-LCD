/******************************************************************
*Dosya			:lcd.c
*Yazar			:Ayhan KORKMAZ - AyhanKorkmaz.Net
*�leti�im  	        :info@ayhankorkmaz.net
*Versiyon		:V1.0
*******************************************************************/

#include <stm32f10x.h>
#include "lcd.h"
 unsigned char sayac,s,adres=64;

/*****************************************************************************
Kullanim  : Eklemek istedi�iniz �zel karakterleri ekleyebiliriniz
            Bunun i�in LCD karakter olu�turma programlar�n� kulanabilirsiniz
******************************************************************************/
 unsigned char karakter_[8][8]=
{
  /* TR Karakterler */
{ 0,14,16,16,17,14, 4, 0},//�	 
{ 0, 0,12, 4, 4, 4,14, 0},//I
{10, 0,14,17,17,17,14, 0},//�
{ 0,15,16,14, 1,30, 4, 0},//$
{10, 0,17,17,17,17,14, 0},//�
/* �zel isaretler */
{2, 6,14,30,14, 6,  2, 0},//<	 
{ 0, 4, 4, 4, 4, 4, 4, 0},//|	 
{ 0, 16, 8, 4, 2, 1, 0,0} //\//	 
};
/********************************************************
Fonksiyon : delay
Amac	  : Gecikme Fonksiyonudur.
Kullanim  : delay(0x0000FFFF);
*********************************************************/
 void delay(unsigned long delay)
{
 while(delay--);
}
/********************************************************
Fonksiyon : lcd_komut
Amac	  : LCD �al��mas� i�in gerekli komutlar� verir
Kullanim  : lcd_komut(temizle);
*********************************************************/
void lcd_komut(char komut)
{
	GPIOC->BRR =  0x00000001; 			//RS=0
	GPIOC->ODR |= 0x00000002;			//E=1
	GPIOC->ODR |= (komut & 0x000000F0);	        //Y�ksek de�erlikli 4 bit g�nderiliyor
	lcd_gecikme();
	GPIOC->BRR = 0x00000002;			//E=0
	GPIOC->BRR = 0x000000F0;			//g�nderilen y�ksek de�erlikli 4 bit porttan temizleniyor.
 
	lcd_gecikme();
	GPIOC->ODR |= 0x00000002;			//E=1
	GPIOC->ODR |= ((komut & 0x0000000F)<<4);	//�lk 4 bit lcd ye g�nderiliyor.
	lcd_gecikme();
	GPIOC->BRR = 0x00000002;			//E=0
	GPIOC->BRR = 0x000000FF; 			//G�nderilen d���k de�erlikli 4 bit porttan temizleniyor.
}
/********************************************************
Fonksiyon : lcd_karakter_yaz
Amac	  : LCD Ekrana bir karakter basar
Kullanim  : lcd_karakter_yaz('A');
*********************************************************/
void lcd_karakter_yaz(char veri)
{
switch (veri) {
case '�' : veri=0x00; break; 
case '�' : veri=0x01; break;
case '�' : veri=0x02; break;
case '�' : veri=0x03; break;
case '�' : veri=0x04; break;

case '�' : veri=0x00; break;
case '�' : veri=0x01; break;
case '�' : veri=0x02; break;
case '�' : veri=0x03; break;
case '�' : veri=0x04; break;

default : break;
}
  
	GPIOC->ODR |= 0x00000001;			//RS=1
	GPIOC->ODR |= 0x00000002;			//E=1
	GPIOC->ODR |= (veri & 0x000000F0);	        //verinin y�ksek de�erlikli 4 biti g�nderiliyor.
	lcd_gecikme();
	GPIOC->BRR = 0x00000002;			//E=0
	GPIOC->BRR = 0x000000F0;			//G�nderilen 4 bit porttan temizleniyor.
 
	lcd_gecikme();
	GPIOC->ODR |= 0x00000002;			//E=1
	GPIOC->ODR |= ((veri & 0x0000000F)<<4);		//�lk 4 bit g�nderiliyor.
	lcd_gecikme();
	GPIOC->BRR = 0x00000002;			//E=0;
	GPIOC->BRR = 0x000000FF;			//G�nderilen ilk 4bit porttan temizleniyor.
        lcd_gecikme();
}
/********************************************************
Fonksiyon : lcd_yazi_yaz
Amac	  : LCD Ekrana yazi yazar
Kullanim  : lcd_yazi_yaz("AyhanKorkmaz.Net");
*********************************************************/
void lcd_yazi_yaz(char *veri)
{
	
	while(*veri)
	{
		lcd_gecikme();
		lcd_karakter_yaz(*veri++);
		
	}
          delay(0x0000FFFF);
}
/**************************************************************
Fonksiyon : lcd_git_xy
Amac	  : LCD ekran�n hangi b�lmesine yaz�laca��n� ayarlar�z
Kullanim  : lcd_git_xy(2,1); 2. sat�r 1. S�tun
***************************************************************/
void lcd_git_xy(unsigned char satir,unsigned char sutun)
{
	if(satir==1)
	{
		lcd_komut(0x00000080 + (sutun-1)); 					//1.sat�r 1.s�tun i�in cgram adresi 0x80 dir
	}
	else if(satir==2)
	{
		lcd_komut(0x000000C0 +(sutun-1));					//2.sat�r 1.s�tun i�in chram adresi 0x80+0x40=0xC0 d�r
	}
}
/********************************************************
Fonksiyon : lcd_hazirla
Amac	  : LCD �al��mas� i�in gerekli ilk ayarlar
Kullanim  : lcd_hazirla();
*********************************************************/
void lcd_hazirla(void)
{       
  
        delay(0x0000FFFF);
        delay(0x0000FFFF);
        GPIO_InitTypeDef GPIO_InitStructure;     
        delay(0x0000FFFF);

        RCC_DeInit();
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
        
	lcd_komut(zorunlu);
          delay(0x0000FFFF);
	lcd_komut(ikisatir4bit5x8);
          delay(0x0000FFFF);
	lcd_komut(imlecsagakay);
          delay(0x0000FFFF);
	lcd_komut(dayansonig);
          delay(0x0000FFFF);
	lcd_komut(dayansonyok);
          delay(0x0000FFFF);
	lcd_komut(temizle);
          delay(0x0000FFFF);
	lcd_gecikme();
        
 lcd_temizle();

        for(sayac=0;sayac<=7;sayac++){  // T�rk�e karakterler tanitiliyor
	lcd_komut(adres);
	for(s=0;s<=7;s++){
		lcd_karakter_yaz(karakter_[sayac][s]);
					 }				  
		adres=adres+8;	 
				 }
        lcd_temizle();
         delay(0x0000FFFF);
         
}
/********************************************************
Fonksiyon : lcd_temizle
Amac	  : LCD ekran tamamen silinir
Kullanim  : lcd_temizle();
*********************************************************/
void lcd_temizle(void)
{
	lcd_komut(temizle);
	lcd_gecikme();
}
/********************************************************
Fonksiyon : lcd_gecikme
Amac	  : LCD �al��mas� i�in gerekli gecikmedir
Kullanim  : lcd_gecikme();
*********************************************************/
void lcd_gecikme(void)
{
	unsigned long delay=0x00000872;		
	while(delay--);
}