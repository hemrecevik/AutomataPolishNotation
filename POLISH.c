#include <stdio.h>
#include <string.h>
#define YBoyut 9

typedef struct Yigin
{
	int indis;
	int eleman[YBoyut];
}Yiginlar;

Yiginlar Yeni_yigin;
int YiginDoluMu(){
	if(Yeni_yigin.indis>=YBoyut-1)return -1;
	else return 1;
}
void Yigina_Ekle(int ekle)
{
	if(YiginDoluMu()==-1)printf("Yigin Dolu Eklenemez..\n");
	else
	{
		Yeni_yigin.indis++;
		Yeni_yigin.eleman[Yeni_yigin.indis]=ekle;
	}
}
int YiginBosMu()
{
	if(Yeni_yigin.indis==-1)return -1;
	else return 1;
}
int Yigindan_Cikar()
{
	int cikan;
	if(YiginBosMu()==-1)printf("Yigin Bos Cikarma Yapilamaz..\n");
	else
	{
		cikan=Yeni_yigin.eleman[Yeni_yigin.indis];
		Yeni_yigin.indis--;
		return cikan;
	}
	
}
int Hesapla(int sayi1,char islem,int sayi2){
	int donen;
	switch(islem)
	{
		case '+':donen=sayi1+sayi2;break;
		case '-':donen=sayi1-sayi2;break;
		case '/':donen=sayi1/sayi2;break;
		case '*':donen=sayi1*sayi2;break;
		default:
			printf("HATA\n");break;	
	}
	return donen;
	
}
int PolishNotasyonu(char ifade[],int ifadeboyutu){
	int index=ifadeboyutu-1;
	int sonuc,operand1,operand2,operator1,deger,degisken;
	while(index>=0){
		if(ifade[index]==' ')index--;
		if(ifade[index]!='+'&&ifade[index]!='-'&&ifade[index]!='*'&&ifade[index]!='/')
			{	
				degisken=ifade[index]-'0';
				Yigina_Ekle(degisken);
			}
		else
		{
			operand1=Yigindan_Cikar();
			operand2=Yigindan_Cikar();
			operator1=ifade[index];
			deger=Hesapla(operand1,operator1,operand2);
			Yigina_Ekle(deger);
		}
		index=index-1;
	}
	sonuc=Yigindan_Cikar();
	return sonuc;
}
main(){
	char dizi[30];
	int sonuc;
	Yeni_yigin.indis=-1;
	printf(" Ifadeyi giriniz = \n");
	gets(dizi);
	
	sonuc=PolishNotasyonu(dizi,strlen(dizi));
	printf("\n\n %s  Isleminin sonucu= %d ",dizi,sonuc);

}
