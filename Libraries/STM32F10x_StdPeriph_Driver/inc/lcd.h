/******************************************************************
*Dosya			:lcd.h
*Amaç			:2*16 LCD için gerekli tanımlamaları yapar
*Kullanım   	:Proje dosyasında ilgili yere eklenir.
*                lcd.c içinden çağırılır
*Yazar			:Ayhan KORKMAZ - AyhanKorkmaz.Net
*İletişim  	    :info@ayhankorkmaz.net
*Versiyon		:V1.0
*Pin bağlantısı :
*                  ----------------
*                  ||||||||||||||||
*                               
*PC.0  –> RS
*PC.1  –> E
*PC.4  –> DB4
*PC.5  –> DB5
*PC.6  –> DB6
*PC.7  –> DB7
*RW    ->Toprak
*******************************************************************/

#ifndef __LCD_H
#define __LCD_H

#define temizle 		0x01
#define zorunlu 		0x02
//------İMLEÇ AYARLARI------//
#define dkyansonyok		0x08   	//dk = disp kapalı
#define	dkyanson		0x09
#define dkyansonyokig	0x0A	//ig = imleç göster
#define dkyansonig		0x0B
#define dayansonyok		0x0C	//da = display açık
#define dayanson		0x0D
#define dayansonyokig 	0x0E
#define dayansonig		0x0F
#define solakay			0x10	//imleç sola kayar
#define sagakay			0x14	//imleç sağa kayar
#define dispsolakay		0x18	//display sola kayar
#define dispsagakay		0x1C	//display sağa kayar
 
//-------İletişim Ayarları------//
 
#define birsatir4bit5x8		0x3C	//LCD 1 satır,5x8 matris 4bit iletişim
#define birsatir4bit5x10	0x24
#define ikisatir4bit5x8		0x28
#define ikisatir4bit5x10	0x2C
#define birsatir8bit5x8		0x30
#define birsatir8bit5x10	0x34
#define ikisatir8bit5x8		0x38
#define ikisatir8bit5x10	0x20
 
//-------GİRİŞ AYARLARI--------//
 
#define imlecsolakay		0x04	//Her yazılan karakterden sonra imleç sola kayar
#define imlecdispsolakay	0x05	//Her yazılan karakterden sonra imleç ve display sola kayar
#define imlecsagakay		0x06	//Her yazılan karakterden sonra imleç saga kayar
#define imlecdispsagakay	0x07	//Her yazılan karakterden sonra imleç ve display sola kayar
extern void delay(unsigned long delay);
extern void lcd_komut(char komut);
extern void lcd_karakter_yaz(char veri);
extern void lcd_yazi_yaz(char *veri);
extern void lcd_git_xy(unsigned char satir,unsigned char sutun);
extern void lcd_hazirla(void);
extern void lcd_temizle(void);
extern void lcd_gecikme(void);
#endif