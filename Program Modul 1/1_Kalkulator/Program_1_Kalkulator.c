#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

void cover();
void menu1();
float input(int b);
void operasi(int b, float x, float y);
void ulang();
float validasi();

int main (){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|              PROGRAM KALKULATOR              |\n");
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
    printf("|                PILIHAN MENU                  |\n");
    printf("================================================\n");
    printf("| [1] PENJUMLAHAN                              |\n");
    printf("| [2] PENGURANGAN                              |\n");
    printf("| [3] PERKALIAN                                |\n");
    printf("| [4] PEMBAGIAN                                |\n");
    printf("| [5] MODULUS                                  |\n");
    printf("================================================\n");
    printf("| MASUKKAN KODE MENU : ");
    while(a!=b || a<1 || a>5){
        a=validasi();
        b=(int)a;
        if(a!=b || a<1 || a>5){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");

    input(b);
}

float input(int b){
    float x=-1, y=-1;

    printf("================================================\n");
    if(b==1){
        printf("|              OPERASI PENJUMLAHAN             |\n");
    }else if(b==2){
        printf("|              OPERASI PENGURANGAN             |\n");
    }else if(b==3){
        printf("|               OPERASI PERKALIAN              |\n");
    }else if(b==4){
        printf("|               OPERASI PEMBAGIAN              |\n");
    }else if(b==5){
        printf("|                OPERASI MODULUS               |\n");
    }
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN BILANGAN PERTAMA : ");
    if(b==5){
        while(x<0){
        x=validasi();
            if(x<0){
                printf("================================================\n");
                printf("|                 INPUT ERROR                  |\n");
                printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
                printf("================================================\n");
                printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
            }
        }
    }else{
        x=validasi();
    }
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN BILANGAN KEDUA : ");
    if(b==5){
        while(y<0){
        y=validasi();
            if(y<0){
                printf("================================================\n");
                printf("|                 INPUT ERROR                  |\n");
                printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
                printf("================================================\n");
                printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
            }
        }
    }else{
        y=validasi();
    }
    printf("================================================\n\n");

    operasi(b, x, y);
}

void operasi(int b, float x, float y){
    float i, j, hasil;
    if(b==1){//PENJUMLAHAN
        hasil=x+y;
        printf("================================================\n");
        printf("| HASIL PENJUMLAHAN DARI %.2f DENGAN %.2f = %.2f", x, y, hasil);
        printf("\n================================================\n\n");
    }else if(b==2){//PENGURANGAN
        hasil=x-y;
        printf("================================================\n");
        printf("| HASIL PENGURANGAN DARI %.2f DENGAN %.2f = %.2f", x, y, hasil);
        printf("\n================================================\n\n");
    }else if(b==3){//PERKALIAN
        hasil=x*y;
        printf("================================================\n");
        printf("| HASIL PERKALIAN DARI %.2f DENGAN %.2f = %.2f", x, y, hasil);
        printf("\n================================================\n\n");
    }else if(b==4){//PEMBAGIAN
        hasil=x/y;
        printf("================================================\n");
        printf("| HASIL PEMBAGIAN DARI %.2f DENGAN %.2f = %.2f", x, y, hasil);
        printf("\n================================================\n\n");
    }else if(b==5){//MODULUS
        i=round(x);
        j=round(y);
        hasil=(int)i%(int)j;
        printf("================================================\n");
        printf("| HASIL MODULUS DARI %.2f DENGAN %.2f = %.0f", i, j, hasil);
        printf("\n================================================\n\n");
    }

    ulang();
}

float validasi(){

    char input[100];
    int a=0, i;
    int negatif=0;
    int salah=0;
    int koma=0;
    int belakang=0;
    int deret=0;
    int depan=0;
    float nolKoma=1;
    float hasil;

    scanf("%[^\n]", input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]=='-'){
            negatif++;
            if(a>0 || negatif==2){
                salah=1;
                input[a]='\0';
            }
            if(input[a+1]<'0' || input[a+1]>'9'){
                salah=1;
                input[a]='\0';
            }
            a++;
        }else if(input[a]=='.'){
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

    if(negatif==1){
        hasil=hasil-(hasil*2);
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

void ulang(){
    float a;
    int b;

    printf("\n\n\n================================================\n");
    printf("|  APAKAH ANDA INGIN MENCOBA PROGRAMNYA LAGI?  |\n");
    printf("================================================\n");
    printf("|         PILIHAN        |        KODE         |\n");
    printf("================================================\n");
    printf("|           YA           |          1          |\n");
    printf("|          TIDAK         |          2          |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN KODE : ");
    while(a!=b || a<1 || a>2){
        a=validasi();
        b=(int)a;
        if(a!=b || a<1 || a>2){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");


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


