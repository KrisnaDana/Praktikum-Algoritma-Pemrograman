#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kubus1{
    float sisi;
    float luas;
    float volume;
};

union kubus2{
    float sisi;
    float luas;
    float volume;
};

void cover();
void menu1();
void operasi();
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|      PROGRAM PERBANDINGAN ANTARA 2 KUBUS     |\n");
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
    struct kubus1 k1;
    union kubus2 k2;

    k1.sisi=-1;

    printf("================================================\n");
    printf("| MASUKKAN PANJANG SISI KUBUS [cm] : ");
    while(k1.sisi<0){
        k1.sisi=validasi();
        if(k1.sisi<0){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n");
    system("cls");

    k1.luas=(k1.sisi*k1.sisi)*6;
    k1.volume=k1.sisi*k1.sisi*k1.sisi;

    printf("================================================\n");
    printf("|             KUBUS DENGAN STRUCT              |\n");
    printf("================================================\n");
    printf("| SISI           : %.2f cm\n", k1.sisi);
    printf("| LUAS PERMUKAAN : %.2f cm2\n", k1.luas);
    printf("| VOLUME         : %.2f cm3\n", k1.volume);
    printf("================================================\n\n");

    printf("================================================\n");
    printf("|              KUBUS DENGAN UNION              |\n");
    printf("================================================\n");

    k2.sisi=k1.sisi;
    printf("| SISI           : %.2f cm\n", k1.sisi);

    k2.luas=(k2.sisi*k2.sisi)*6;
    printf("| LUAS PERMUKAAN : %.2f cm2\n", k1.luas);

    k2.volume=(k2.luas/6)*k2.sisi;
    printf("| VOLUME         : %.2f cm3\n", k1.volume);
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| UKURAN MEMORI PADA KUBUS STRUCT : %d Byte\n", sizeof(k1));
    printf("| UKURAN MEMORI PADA KUBUS UNION  : %d Byte\n", sizeof(k2));
    printf("================================================\n");

    ulang();
}

float validasi(){

    char input[100];
    int a, i;
    int negatif=0;
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

