

#define ust 2//segment display pini
#define sau 3//segment display pini
#define saa 4//segment display pini
#define alt 5//segment display pini
#define soa 6//segment display pini
#define sou 7//segment display pini
#define ort 8//segment display pini
#define nok 9//segment display pini
int role=A0;
int s=100;
int buton=13;
int butondurum;
//int mesafe=50;//algılama mesafesi
int trig1=11;//birinci mesafe sensörünün trig pini belirtildi
int trig2=9;//ikinci mesafe sensörünün trig pini belirtildi
int echo1=12;//birinci mesafe sensörünün echo pini belirtildi
int echo2=10;//ikinci mesafe sensörünün echo pini belirtildi
int sayac=0;//kişi sayacı
boolean gir,cik;// 1 ve 0 değerini alan değişken
long uzaklik,uzaklik2;//uzaklık değerinin atanacağı değişken
long sure,sure2;//mesafe sensörünün  kullancağı süre değişkeni
void setup() {
  pinMode(13,INPUT);//buton giriş pini
  
  pinMode(2,OUTPUT);//segment display
  pinMode(3,OUTPUT);//segment display
  pinMode(3,OUTPUT);//segment display
  pinMode(4,OUTPUT);//segment display
  pinMode(5,OUTPUT);//segment display
  pinMode(6,OUTPUT);//segment display
  pinMode(7,OUTPUT);//segment display
  pinMode(8,OUTPUT);//segment display
  pinMode(role,OUTPUT);//role çıkış olarak ayarlandı
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
  pinMode(trig1,OUTPUT);//birinci mesafe sensörünün trig pini çıkış olarak ayarlandı
  pinMode(trig2,OUTPUT);//ikinci mesafe sensörünün trig pini çıkış olarak ayarlandı
  pinMode(echo1,INPUT);//birinci mesafe sensörünün echo pini giriş olarak ayarlandı
  pinMode(echo2,INPUT);//ikinci mesafe sensörünün echo pini giriş olarak ayarlandı
  Serial.begin(9600);
}
void loop() {
  
  sens1();
  sens2();

  Serial.print("uzaklik1=");
  Serial.print(uzaklik);
  Serial.print("-----=");
  Serial.print("uzaklik2=");
  Serial.print(uzaklik2);
  Serial.print("-----=");
  Serial.print("sayac=");
  Serial.println(sayac);
  delay(500);
 
  if(uzaklik<50){
  IN();
  }
  if(uzaklik2<50){
  OUT();
  }
  if((sayac<0)||(sayac>9)){
    son();
    digitalWrite(ust,HIGH);
    delay(s);
    son();
    digitalWrite(sau,HIGH);
    delay(s);
    son();
    digitalWrite(saa,HIGH);
    delay(s);
    son();
    digitalWrite(alt,HIGH);
    delay(s);
    son();
    digitalWrite(soa,HIGH);
    delay(s);
    son();
    digitalWrite(sou,HIGH);
    //delay(s);
    
  }
  butondurum=digitalRead(buton);
  if(butondurum==HIGH){
    sayac=0;
  }
if(sayac==1){
  bir();
}
if(sayac==2){
  iki();
}
if(sayac==3){
  uc();
}
if(sayac==4){
  dort();
}
if(sayac==5){
  bes();
}
if(sayac==6){
  alti();
}
if(sayac==7){
  yedi();
}
if(sayac==8){
  sekiz();
}
if(sayac==9){
  dokuz();
}
if(sayac==0){
  sifir();
}
if(sayac>0){
  digitalWrite(role,HIGH);
}
else{
  digitalWrite(role,LOW);
}
}
void son(){
  digitalWrite(ust, LOW);
  digitalWrite(sau, LOW);
  digitalWrite(saa, LOW);
  digitalWrite(alt, LOW);
  digitalWrite(soa, LOW);
  digitalWrite(sou, LOW);
  digitalWrite(ort, LOW);
  //sure();
  }
void sifir(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, HIGH);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, LOW);
//  sure();
}
void bir(){
  digitalWrite(ust, LOW);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, LOW);
  digitalWrite(soa, LOW);
  digitalWrite(sou, LOW);
  digitalWrite(ort, LOW);
//  sure();
}
void iki(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, LOW);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, HIGH);
  digitalWrite(sou, LOW);
  digitalWrite(ort, HIGH);
  //sure();
}
void uc(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, LOW);
  digitalWrite(sou, LOW);
  digitalWrite(ort, HIGH);
  //sure();
}
void dort(){
  digitalWrite(ust, LOW);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, LOW);
  digitalWrite(soa, LOW);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, HIGH);
  //sure();
}
void bes(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, LOW);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, LOW);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, HIGH);
  //sure();
}
void alti(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, LOW);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, HIGH);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, HIGH);
  //sure();
}
void yedi(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, LOW);
  digitalWrite(soa, LOW);
  digitalWrite(sou, LOW);
  digitalWrite(ort, LOW);
  //sure();
}
void sekiz(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, HIGH);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, HIGH);
  //sure();
}
void dokuz(){
  digitalWrite(ust, HIGH);
  digitalWrite(sau, HIGH);
  digitalWrite(saa, HIGH);
  digitalWrite(alt, HIGH);
  digitalWrite(soa, LOW);
  digitalWrite(sou, HIGH);
  digitalWrite(ort, HIGH);
  //sure();
}
void sens1(){
  digitalWrite(trig1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig1,LOW);
  sure=pulseIn(echo1,HIGH);
  uzaklik=(sure/2) / 29.1;
}
void sens2(){
  digitalWrite(trig2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig2,LOW);
  sure2=pulseIn(echo2,HIGH);
  uzaklik2=(sure2/2) / 29.1;
}
void IN(){
  sayac++;
  uzaklik=52;
  delay(1000);
}
void OUT(){
  sayac--;
  uzaklik2=52;
  delay(1000);
}
