#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
float validasi();
float validasiBiner();
void kode1();
void kode2();
void ulang();

int main(){

    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|           PROGRAM KONVERSI BILANGAN          |\n");
    printf("|                  KELOMPOK 17                 |\n");
    printf("================================================\n");
    printf("| 2005551028 NI LUH GEDE GITA PUTRI PRITA SARI |\n");
    printf("| 2005551052 HERRY DANIEL PRASETIA LIUKAE      |\n");
    printf("| 2005551062 GEDE RADITYA ARYA WIGUNA          |\n");
    printf("| 2005551084 I PUTU NGURAH KRISNA DANA         |\n");
    printf("| 2005551142 GEDE ADE RANGGA ARINATA           |\n");
    printf("| 2005551149 RAJA TIGOR WIRAWAN SIMANJUNTAK    |\n");
    printf("================================================\n\n");

    system("pause");
    system("cls");

    menu1();
}

void menu1(){
    float a;
    int b;

    printf("================================================\n");
    printf("|                 PILIHAN MENU                 |\n");
    printf("================================================\n");
    printf("|          JENIS KONVERSI          |    KODE   |\n");
    printf("================================================\n");
    printf("| BILANGAN DESIMAL KE BINER        |     1     |\n");
    printf("| BILANGAN BINER KE DESIMAL        |     2     |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN KODE : ");
    a=validasi();
    b=(int)a;
    printf("================================================\n\n");

    while(a!=b || a<1 || a>2){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
        b=(int)a;
    }

    system("cls");
    if(a==1){
        kode1();
    }else if(a==2){
        kode2();
    }
}

float validasi(){

    char input[100];
    int a=0, i;
    int salah=0;
    int koma=0;
    int belakang=0;
    int deret=0;
    int depan=0;
    float nolKoma=1;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]=='.'){
            koma++;
            if(input[0]=='.' || input[a+1]=='\0' || koma>1 ){
                salah=1;
                input[a]='\0';
            }
            a++;
        }else if(input[a]>='0' && input[a]<='9'){
            if(koma==1){
                belakang=(belakang*10)+(input[a]-48);
                deret++;
                a++;
            }else{
                depan=(depan*10)+(input[a]-48);
                a++;
            }
        }else{
            salah=1;
            input[a]='\0';
        }
    }

    if(koma==1){
        for(i=0;i<deret;i++){
            nolKoma=nolKoma/10;
        }
        hasil=belakang*nolKoma+depan;

    }else{
        hasil=depan;
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");

        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        return validasi();
    }else{
        return hasil;
    }
}

float validasiBiner(){

    char input[100];
    int a=0, i;
    int salah=0;
    int depan=0;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(a>=8 && input[8]!='\0'){
            salah=1;
            input[a]='\0';
        }else if(input[a]=='0' || input[a]=='1'){
                depan=(depan*10)+(input[a]-48);
                a++;
        }else{
            salah=1;
            input[a]='\0';
        }
    }
        hasil=depan;

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");

        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        return validasiBiner();
    }else{
        return hasil;
    }
}

void kode1(){
    int i, b, biner[100];
    float a;

    printf("================================================\n");
    printf("|     KONVERSI BILANGAN DESIMAL KE BINER       |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN NILAI BILANGAN DESIMAL : ");
    a=validasi();
    b=(int)a;
    printf("================================================\n\n");

    while(a!=b || a<0){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
        b=(int)a;
    }

    system("cls");

    for(i=0;b>0;i++){
        biner[i]=b%2;
        b=b/2;
    }

    printf("================================================\n");
    printf("|     KONVERSI BILANGAN DESIMAL KE BINER       |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| HASIL KONVERSI BILANGAN %d KE BINER : ", (int)a);
    if(a==0){
        printf("0");
    }else{
        for(i=i-1;i>=0;i--){
            printf("%d", biner[i]);
        }
    }
    printf("\n================================================\n\n\n");

    ulang();
}

void kode2(){
    float a;
    int b, i, d, desimal=0, j=1, p=1;

    printf("================================================\n");
    printf("|     KONVERSI BILANGAN BINER KE DESIMAL       |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN NILAI BILANGAN BINER : ");
    a=validasiBiner();
    b=(int)a;
    printf("================================================\n\n");

    while(a!=b){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasiBiner();
        b=(int)a;
    }

    system("cls");

    for(i=b;i>0;i/=10){
        d=i%10;
        if(j==1){
            p*=1;
        }else{
            p*=2;
        }
        desimal=desimal+(d*p);
        j++;
    }

    printf("================================================\n");
    printf("|     KONVERSI BILANGAN BINER KE DESIMAL       |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| HASIL KONVERSI BILANGAN %d KE DESIMAL : %d", (int)a, desimal);
    printf("\n================================================\n\n\n");

    ulang();
}

void ulang(){
    float a;
    int b;

    printf("================================================\n");
    printf("|  APAKAH ANDA INGIN MENCOBA PROGRAMNYA LAGI?  |\n");
    printf("================================================\n");
    printf("|         PILIHAN        |        KODE         |\n");
    printf("================================================\n");
    printf("|           YA           |          1          |\n");
    printf("|          TIDAK         |          2          |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN KODE : ");
    a=validasi();
    b=(int)a;
    printf("================================================\n\n");

    while(a!=b || a<1 || a>2){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
        b=(int)a;
    }

    system("cls");

    if(a==1){
        menu1();
    }else if(a==2){
        printf("================================================\n");
        printf("| TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI  |\n");
        printf("|        SEMOGA HARI ANDA MENYENANGKAN         |\n");
        printf("================================================\n");
    }
    exit(0);
}



