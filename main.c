//Meric Altikardes 200202088 
#include <stdio.h>
#include <stdlib.h>
struct ogrenci{
char ad[20];
char soyad[20];
int no;
int ders_kodu;
int puan;
};
void indexle(){
	

	FILE *filep=fopen("D:\\dense\\veri.bin","rb");
	if(filep==NULL){
		printf("dosyaya erisilemedi!");
		exit(1);
	}
	int satir;
	FILE *metin_sil=fopen("D:\\dense\\veri.txt","w");
	fclose(metin_sil);
	while(1){
	struct ogrenci cevir;
	size_t sayi=fread(&cevir,sizeof(struct ogrenci),1,filep);
	satir++;
	if(sayi<1){
		break;
}
FILE *metin_belgesi=fopen("D:\\dense\\veri.txt","a+");
fprintf(metin_belgesi,"%d %d\n",satir,cevir.no);
}
}
void listele_bin(){

	FILE *dosya=fopen("D:\\dense\\veri.bin","rb");
	if(dosya==NULL){
		printf("dosya okunamadi!");
		exit(1);
	}
	printf("\nlistele:\n");
	while(1){
		struct ogrenci oku;
		size_t sayi=fread(&oku,sizeof(struct ogrenci),1,dosya);
		if(sayi<1){
			;break;
		}
		printf("%s %s %d %d %d\n",oku.ad,oku.soyad,oku.no,oku.ders_kodu,oku.puan);
}fclose(dosya);
}
void satir_satir_oku_index() {
FILE * dosya;
char *buf=malloc(50*sizeof(struct ogrenci));
if ((dosya = fopen("D:\\dense\\veri.txt","r")) == NULL) {
printf("Dosya acilamadi!\n");
exit(1);
}
int satir_sayisi = 0;
// satir satir okuma islemi
while ( fgets(buf, 100, dosya) != NULL ) {
satir_sayisi++;
printf("%d. satir: \%s\n", satir_sayisi, buf);
}
fclose(dosya);

}
void kayitekle(struct ogrenci x){
	FILE *dosya=fopen("D:\\dense\\veri.bin","ab+");
if(dosya==NULL){
	printf("islem basarisiz!");
	exit(1);
}

fwrite(&x,sizeof(struct ogrenci),1,dosya);

FILE *at=fopen("D:\\dense\\veri.txt","a");
fprintf(at,"%d %d",x.ders_kodu,x.no);

fclose(dosya);
fclose(at);
}
void indeks_dosyasini_sil(){
int kontrol=remove("D:\\dense\\veri.txt");
if(kontrol==0){
	printf("Indeks Dosyasi Silindi!");
}
else{
	printf("Indeks Dosyasi Silinemedi!");
}
}
int kayitbul(){
	
	int kontrol;
	int i=0,last,first,mid,n;
	FILE *filep=fopen("D:\\dense\\veri.txt","r");
	if(filep==NULL){
		printf("Indeksleme Yapiniz.");
	}
	struct ogrenci ogr[100];
	while(kontrol!=EOF){
		fscanf(filep,"%d %d",&ogr[i].ders_kodu,&ogr[i].no);
		kontrol=fgetc(filep);
		i++;
	}
	FILE *dosya=fopen("D:\\dense\\veri.bin","rb");
	if(dosya==NULL){
		printf("dosya bulunamadi.");
	}
first=0;
last=i--;
mid=(last+first)/2;
struct ogrenci ogrenme;
printf("Aranan numarayi giriniz:");
scanf("%d",&n);
char *buf=malloc(sizeof(struct ogrenci));
while (first <= last) {
      if (ogr[mid].no < n)
         first = mid + 1;    
      else if (ogr[mid].no == n) {
       printf("%d numara bu indekstedir. %d.\n",n,ogr[mid].ders_kodu);
       fseek(dosya,((ogr[mid].ders_kodu)-1)*sizeof(struct ogrenci),SEEK_SET);
        fread(&ogrenme,(sizeof(struct ogrenci)-1),1,dosya);
        printf("%s %s %d %d %d",ogrenme.ad,ogrenme.soyad,ogrenme.no,ogrenme.ders_kodu,ogrenme.puan);
       break;  
         
      }
	        else
         last = mid - 1;
      mid = (first + last)/2;
   }
   if (first > last){
   
      printf("bulunamadi %d boyle bir deger yok.\n",n); 
	
	  }free(buf);
      while ( fgets(buf, 100, dosya) != NULL ) {;break;
}
      
    return 0;
}
void kayit_sil(){
	int no;
printf("Silinecek No yu giriniz:");
scanf("%d",&no);
	FILE *filep=fopen("D:\\dense\\veri.bin","rb");
	FILE *dosya=fopen("D:\\dense\\yenitempdosya.bin","wb");
	FILE *txt=fopen("D:\\dense\\yenitempmetin.txt","w");
	if(filep==NULL){
		printf("dosya okunamadi");
	}
		while(1){
		struct ogrenci oku;
		size_t sayi=fread(&oku,sizeof(struct ogrenci),1,filep);
		if(sayi<1){
			break;
		}
		

if(oku.no!=no){
fprintf(txt,"%d %d\n",oku.ders_kodu,oku.no);
fwrite(&oku,sizeof(struct ogrenci),1,dosya);continue;
}
}fclose(filep);
fclose(dosya);
fclose(txt);
}
void kayit_guncelle(){
int no;
	printf("Degistirilecek No Giriniz:");
	scanf("%d",&no);
	int yenipuan;
	FILE *filep=fopen("D:\\dense\\veri.bin","r+b");
	if(filep==NULL){
		printf("dosya okunamadi");
	}
		while(1){
		struct ogrenci oku;
		size_t sayi=fread(&oku,sizeof(struct ogrenci),1,filep);
		if(sayi<1){
			break;
		}
		else if(oku.no==no){
			printf("Guncellenecek Ogrenci:%s %s %d %d %d\n",oku.ad,oku.soyad,oku.no,oku.ders_kodu,oku.puan);
			printf("yeni puani giriniz:");
			scanf("%d",&yenipuan);
			oku.puan=yenipuan;
	       fseek(filep,-sizeof(struct ogrenci),SEEK_CUR);
	       fwrite(&oku,sizeof(struct ogrenci),1,filep);
	       fclose(filep);
	       break;
		}
    	    	
}
}
int main() {
		
	
	rename("D:\\dense\\yenitempdosya.bin","D:\\dense\\veri.bin");
     rename("D:\\dense\\yenitempmetin.txt","D:\\dense\\veri.txt");
printf("*****Dosyalama sistemine Hosgeldiniz*****\n\n");
printf("Index Dosyasini Olusturmak icin 1'i\n");
printf("Veri Dosyasina Yeni Bir Kayit Eklemek Icin 2'yi\n");
printf("Kayit Bulmak Icin 3'u\n");
printf("Kayit Silmek Icin 4'u\n");
printf("Kayit Guncellemek Icin 5'i\n");
printf("Veri Dosyasini Listelemek Icin 6'yi\n");
printf("Indeks Dosyasini Listelemek Icin 7'yi\n");
printf("Indeks Dosyasini Silmek icin 8'i Seciniz\n");
printf("Cikmak Icin 0' i Seciniz\n");
printf("----------------------------------------------------\n");
int secim; 

scanf("%d",&secim);

switch(secim){
	case 0: exit(0);break;
	
	case 1: indexle();break;
   
   
    case 2: {
    	struct ogrenci ekle;
        printf("bilgileri giriniz:");
        scanf("%s %s %d %d %d",ekle.ad,ekle.soyad,&ekle.no,&ekle.ders_kodu,&ekle.puan);
        kayitekle(ekle);
	   
	}break;
	
	case 3: kayitbul();break;
    
	
	case 4:{
	 kayit_sil();
		 

	
		 
		 remove("D:\\dense\\veri.bin");
		 remove("D:\\dense\\veri.txt");
		 	break;
		
	}

   case 5: kayit_guncelle();break;
	
	case 6: listele_bin();break;
    
	
	case 7:{
    struct ogrenci gecici;

	FILE *filep=fopen("D:\\dense\\veri.txt","r");
	int i=0,size,j;
	char kontrol; 
    struct ogrenci oku[60];
    
	
		while(kontrol!=EOF)
	{
	fscanf(filep,"%d %d",&oku[i].ders_kodu,&oku[i].no);
	kontrol=fgetc(filep); 
	  i++;
	} 
    fclose(filep);
	size=i-1;
	for(i=1;i<size;i++)
	for(j=0;j<size-i;j++)
	if(oku[j+1].no<oku[j].no)
	{
	gecici=oku[j];
	oku[j]=oku[j+1];
	oku[j+1]=gecici;
	}
	FILE *fp=fopen("D:\\dense\\veri.txt","w");
	for(i=0;i<size;i++)
	fprintf(fp,"%d %d\n",oku[i].ders_kodu,oku[i].no);
fclose(fp);
}satir_satir_oku_index();
break;
   case 8: indeks_dosyasini_sil();break;



default: {
	printf("yanlis secim");
	break;
}

	remove("D:\\dense\\yenitempdosya.bin");
   
  return 0;
}}
