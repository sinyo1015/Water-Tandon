/* ---------- ALAT PENDETEKSI KETINGGIAN AIR ----------- */
/* ----------- www.nofgipiston.wordpress.com ----------- */

//Pemanggilan library LCD
#include<LiquidCrystal.h>

//Inialisasi pin lcd
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
//Inialisasi pin sensor air
const int pinAir = A0;
//Inialisasi pin buzzer
const int pinBuzzer = D1;
//Deklarasi variable data pembacaan sensor air
int data;

void setup()
{
 //Inialisasi jumlah baris dan kolom lcd
 lcd.begin(16, 2);
 //Inialisasi status I/O
 pinMode(pinAir, INPUT);
 pinMode(pinBuzzer, OUTPUT);
 //Menghapus tulisan lcd
 lcd.clear();
 //Menuliskan kata pada lcd
 lcd.setCursor(0, 0);
 lcd.print("Alat Pendeteksi");
 lcd.setCursor(0, 1);
 lcd.print("Ketinggian Air");
 delay(3000);
}

void loop()
{
 //Variabel data adalah hasil pembacaan pin sensor air
 data = analogRead(pinAir);

 //Range output sensor berkisar 0 sampai 1023
 //Air terdeteksi
 //Saat output sensor berniali >= 400
 if (data >= 400)
 {
 //Alarm dibunyikan
 digitalWrite(pinBuzzer, HIGH);
 delay(500);
 digitalWrite(pinBuzzer, LOW);
 delay(500);

 //Menulis pada lcd bahwa air telah penuh
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Air Sudah");
 lcd.setCursor(0, 1);
 lcd.print("Penuh ...");
 }

 //Jika air tidak terdeteksi atau nilai data di bawah 400
 else
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Air belum");
 lcd.setCursor(0, 1);
 lcd.print("Penuh ...");
 delay(300);
 }
}
