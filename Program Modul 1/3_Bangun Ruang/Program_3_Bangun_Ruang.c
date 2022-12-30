#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PHI 3.14

void cover();
float validasi();
void ulang();
void menu1();
void menu2(int b);
void operasi(int b, int c);
float tabung(int c);
float bola(int c);
float limas(int c);
float prisma(int c);
float kerucut(int c);

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|          PROGRAM MENGHITUNG VOLUME           |\n");
    printf("|       DAN LUAS PERMUKAAN BANGUN RUANG        |\n");
    printf("|                 KELOMPOK 17                  |\n");
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

void menu1(){
    float a;
    int b;

    printf("================================================\n");
    printf("|                PILIHAN MENU                  |\n");
    printf("================================================\n");
    printf("| [1] TABUNG                                   |\n");
    printf("| [2] BOLA                                     |\n");
    printf("| [3] LIMAS SEGIEMPAT                          |\n");
    printf("| [4] PRISMA SEGITIGA                          |\n");
    printf("| [5] KERUCUT                                  |\n");
    printf("| [6] KELUAR                                   |\n");
    printf("================================================\n");
    printf("| MASUKKAN KODE MENU : ");
    while(a!=b || a<1 || a>6){
        a=validasi();
        b=(int)a;
        if(a!=b || a<1 || a>6){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");

    if(b==6){
        printf("================================================\n");
        printf("| TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI  |\n");
        printf("|        SEMOGA HARI ANDA MENYENANGKAN         |\n");
        printf("================================================\n");
        exit(0);
    }else{
         menu2(b);
    }
}

void menu2(int b){
    float a;
    int c;

    printf("================================================\n");
    printf("|                 PILIHAN MENU                 |\n");
    printf("================================================\n");
    printf("| [1] LUAS PERMUKAAN                           |\n");
    printf("| [2] VOLUME                                   |\n");
    printf("| [3] KEMBALI                                  |\n");
    printf("================================================\n");
    printf("| MASUKKAN KODE MENU : ");
    while(a!=c || a<1 || a>3){
        a=validasi();
        c=(int)a;
        if(a!=c || a<1 || a>3){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");

    if(c==3){
        menu1();
    }else{
        operasi(b, c);
    }
}

void operasi(int b, int c){
    float hasil;

    if(b==1){
        hasil=tabung(c);
        if(c==1){
            printf("================================================\n");
            printf("| LUAS PERMUKAAN TABUNG : %.2f cm2\n", hasil);
            printf("================================================");
        }else if(c==2){
            printf("================================================\n");
            printf("| VOLUME TABUNG : %.2f cm2\n", hasil);
            printf("================================================");
        }
    }else if(b==2){
        hasil=bola(c);
        if(c==1){
            printf("================================================\n");
            printf("| LUAS PERMUKAAN BOLA : %.2f cm2\n", hasil);
            printf("================================================");
        }else if(c==2){
            printf("================================================\n");
            printf("| VOLUME BOLA : %.2f cm3\n", hasil);
            printf("================================================");
        }
    }else if(b==3){
        hasil=limas(c);
        if(c==1){
            printf("================================================\n");
            printf("| LUAS PERMUKAAN LIMAS SEGIEMPAT : %.2f cm2\n", hasil);
            printf("================================================");
        }else if(c==2){
            printf("================================================\n");
            printf("| VOLUME LIMAS SEGIEMPAT : %.2f cm3\n", hasil);
            printf("================================================");
        }
    }else if(b==4){
        hasil=prisma(c);
        if(c==1){
            printf("================================================\n");
            printf("| LUAS PERMUKAAN PRISMA SEGITIGA : %.2f cm2\n", hasil);
            printf("================================================");
        }else if(c==2){
            printf("================================================\n");
            printf("| VOLUME PRISMA SEGITIGA : %.2f cm3\n", hasil);
            printf("================================================");
        }
    }else if(b==5){
        hasil=kerucut(c);
        if(c==1){
            printf("================================================\n");
            printf("| LUAS PERMUKAAN KERUCUT : %.2f cm2\n", hasil);
            printf("================================================");
        }else if(c==2){
            printf("================================================\n");
            printf("| VOLUME PRISMA KERUCUT : %.2f cm3\n", hasil);
            printf("================================================");
        }
    }
    ulang();
}

float tabung(int c){
    float r, t, luas, volume;

    if(c==1){
        printf("================================================\n");
        printf("|            LUAS PERMUKAAN TABUNG             |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI TABUNG [cm]: ");
        r=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI TABUNG [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        luas=(r*r*PHI*2)+(r*2*PHI*t);
        system("cls");
        return luas;
    }else if(c==2){
        printf("================================================\n");
        printf("|                 VOLUME TABUNG                |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI TABUNG [cm]: ");
        r=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI TABUNG [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        volume=r*r*PHI*t;

        system("cls");
        return volume;
    }
}

float bola(int c){
    float r, luas, volume;
    if(c==1){
        printf("================================================\n");
        printf("|             LUAS PERMUKAAN BOLA              |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI BOLA [cm]: ");
        r=validasi();
        printf("================================================\n\n");
        luas=r*r*PHI*4;

        system("cls");
        return luas;
    }else if(c==2){
        printf("================================================\n");
        printf("|                 VOLUME BOLA                  |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI BOLA [cm]: ");
        r=validasi();
        printf("================================================\n\n");
        volume=r*r*r*PHI*4/3;

        system("cls");
        return volume;
    }
}

float limas(int c){
    float s1, s2, t, t1, t2, luas, volume;
    if(c==1){
        printf("================================================\n");
        printf("|        LUAS PERMUKAAN LIMAS SEGIEMPAT        |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI PERTAMA ALAS LIMAS [cm]: ");
        s1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KEDUA ALAS LIMAS [cm]: ");
        s2=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI LIMAS [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        t1=sqrt((s1*s1/4)+(t*t));
        t2=sqrt((s2*s2/4)+(t*t));
        luas=(s1*t2)+(s2*t1)+(s1*s2);

        system("cls");
        return luas;

    }else if(c==2){
        printf("================================================\n");
        printf("|            VOLUME LIMAS SEGIEMPAT            |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI PERTAMA ALAS LIMAS [cm]: ");
        s1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KEDUA ALAS LIMAS [cm]: ");
        s2=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI LIMAS [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        volume=s1*s2*t/3;

        system("cls");
        return volume;
    }
}

float prisma(int c){
    float a, t1, t2, s1, s2, luas, volume;
    if(c==1){
        printf("================================================\n");
        printf("|        LUAS PERMUKAAN PRISMA SEGITIGA        |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ALAS SEGITIGA [cm]: ");
        a=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI SEGITIGA [cm]: ");
        t1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI PRISMA [cm]: ");
        t2=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI PERTAMA SEGITIGA [cm]: ");
        s1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KEDUA SEGITIGA [cm]: ");
        s2=validasi();
        printf("================================================\n\n");

        luas=(a*t1)+(s1*t2)+(s2*t2)+(a*t2);

        system("cls");
        return luas;
    }else if(c==2){
        printf("================================================\n");
        printf("|            VOLUME PRISMA SEGITIGA            |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ALAS SEGITIGA [cm]: ");
        a=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI SEGITIGA [cm]: ");
        t1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI PRISMA SEGITIGA [cm]: ");
        t2=validasi();
        printf("================================================\n\n");

        volume=a*t1*t2/2;
        system("cls");
        return volume;
    }
}

float kerucut(int c){
    float r, t, luas, volume, s;
    if(c==1){
        printf("================================================\n");
        printf("|            LUAS PERMUKAAN KERUCUT            |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI KERUCUT [cm]: ");
        r=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI KERUCUT [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        s=sqrt((r*r)+(t*t));
        luas=(r*r*PHI)+(r*PHI*s);

        system("cls");
        return luas;
    }else if(c==2){
        printf("================================================\n");
        printf("|                VOLUME KERUCUT                |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI KERUCUT [cm]: ");
        r=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI KERUCUT [cm]: ");
        t=validasi();
        printf("================================================\n\n");

        volume=r*r*PHI*t/3;

        system("cls");
        return volume;
    }
}
