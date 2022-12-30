#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PHI 3.14

void cover();
float validasi();
void ulang();
void menu1();
void menu2(int b);
void operasi(int b, int c);
void segitiga_sembarang(int c);
void belah_ketupat(int c);
void jajar_genjang(int c);
void trapesium(int c);
void lingkaran(int c);

int main(){
    cover();
}

void cover(){
    printf("================================================\n");
    printf("|          PROGRAM MENGHITUNG KELILING         |\n");
    printf("|             DAN LUAS BANGUN DATAR            |\n");
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
    printf("| [1] SEGITIGA SEMBARANG                       |\n");
    printf("| [2] BELAH KETUPAT                            |\n");
    printf("| [3] JAJAR GENJANG                            |\n");
    printf("| [4] TRAPESIUM                                |\n");
    printf("| [5] LINGKARAN                                |\n");
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
    printf("| [1] KELILING                                 |\n");
    printf("| [2] LUAS                                     |\n");
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

    if(b==1){
        segitiga_sembarang(c);
    }else if(b==2){
        belah_ketupat(c);
    }else if(b==3){
        jajar_genjang(c);
    }else if(b==4){
        trapesium(c);
    }else if(b==5){
        lingkaran(c);
    }
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
    system("exit");
}

void segitiga_sembarang(int c){
    float sisi1, sisi2, sisi3, keliling, luas, s;

    if(c==1){
        printf("================================================\n");
        printf("|          KELILING SEGITIGA SEMBARANG         |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI PERTAMA SEGITIGA SEMBARANG [cm]: ");
        sisi1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KEDUA SEGITIGA SEMBARANG [cm]: ");
        sisi2=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KETIGA SEGITIGA SEMBARANG [cm]: ");
        sisi3=validasi();
        printf("================================================\n\n");

        keliling=sisi1+sisi2+sisi3;

        system("cls");
        printf("================================================\n");
        printf("| KELILING SEGITIGA SEMBARANG : %.2f cm\n", keliling);
        printf("================================================");
        ulang();
    }else if(c==2){
        printf("================================================\n");
        printf("|            LUAS SEGITIGA SEMBARANG           |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI PERTAMA SEGITIGA SEMBARANG [cm]: ");
        sisi1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KEDUA SEGITIGA SEMBARANG [cm]: ");
        sisi2=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI KETIGA SEGITIGA SEMBARANG [cm]: ");
        sisi3=validasi();
        printf("================================================\n\n");

        s=(sisi1+sisi2+sisi3)/2;
        luas=sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));

        system("cls");
        printf("================================================\n");
        printf("| LUAS SEGITIGA SEMBARANG : %.2f cm2\n", luas);
        printf("================================================");
        ulang();
    }
}

void belah_ketupat(int c){
    float sisi, keliling, diagonal1, diagonal2, luas;

    if(c==1){
        printf("================================================\n");
        printf("|            KELILING BELAH KETUPAT            |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI BELAH KETUPAT [cm]: ");
        sisi=validasi();
        printf("================================================\n\n");

        keliling=sisi*4;

        system("cls");
        printf("================================================\n");
        printf("| KELILING BELAH KETUPAT : %.2f cm\n", keliling);
        printf("================================================");
        ulang();
    }else if(c==2){
        printf("================================================\n");
        printf("|               LUAS BELAH KETUPAT             |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN DIAGONAL PERTAMA BELAH KETUPAT [cm]: ");
        diagonal1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN DIAGONAL KEDUA BELAH KETUPAT [cm]: ");
        diagonal2=validasi();
        printf("================================================\n\n");

        luas=diagonal1*diagonal2/2;

        system("cls");
        printf("================================================\n");
        printf("| LUAS BELAH KETUPAT : %.2f cm2\n", luas);
        printf("================================================");
        ulang();
    }
}

void jajar_genjang(int c){
    float alas, miring, keliling, tinggi, luas;

    if(c==1){
        printf("================================================\n");
        printf("|            KELILING JAJAR GENJANG            |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ALAS JAJAR GENJANG [cm]: ");
        alas=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI MIRING JAJAR GENJANG [cm]: ");
        miring=validasi();
        printf("================================================\n\n");

        keliling=(alas+miring)*2;

        system("cls");
        printf("================================================\n");
        printf("| KELILING JAJAR GENJANG : %.2f cm\n", keliling);
        printf("================================================");

        ulang();
    }else if(c==2){
        printf("================================================\n");
        printf("|               LUAS JAJAR GENJANG             |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ALAS JAJAR GENJANG [cm]: ");
        alas=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI JAJAR GENJANG [cm]: ");
        tinggi=validasi();
        printf("================================================\n\n");

        luas=alas*tinggi;

        system("cls");
        printf("================================================\n");
        printf("| LUAS JAJAR GENJANG : %.2f cm2\n", luas);
        printf("================================================");

        ulang();
    }
}

void trapesium(int c){
    float alas, atap, tm1, tm2, keliling, tinggi, luas;

    if(c==1){
        printf("================================================\n");
        printf("|              KELILING TRAPESIUM              |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ALAS TRAPESIUM [cm]: ");
        alas=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ATAP TRAPESIUM [cm]: ");
        atap=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI TEGAK/MIRING TRAPESIUM [cm]: ");
        tm1=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN SISI TEGAK/MIRING TRAPESIUM [cm]: ");
        tm2=validasi();
        printf("================================================\n\n");

        keliling=alas+atap+tm1+tm2;

        system("cls");
        printf("================================================\n");
        printf("| KELILING TRAPESIUM : %.2f cm\n", keliling);
        printf("================================================");

        ulang();
    }else if(c==2){
        printf("================================================\n");
        printf("|                LUAS TRAPESIUM                |\n");
        printf("================================================\n\n");


        printf("================================================\n");
        printf("| MASUKKAN ALAS TRAPESIUM [cm]: ");
        alas=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN ATAP TRAPESIUM [cm]: ");
        atap=validasi();
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN TINGGI TRAPESIUM [cm]: ");
        tinggi=validasi();
        printf("================================================\n\n");

        luas=(alas+atap)*tinggi/2;

        system("cls");
        printf("================================================\n");
        printf("| LUAS TRAPESIUM : %.2f cm2\n", luas);
        printf("================================================");

        ulang();
    }
}

void lingkaran(int c){
    float jari, keliling, luas;

    if(c==1){
        printf("================================================\n");
        printf("|              KELILING LINGKARAN              |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI LINGKARAN [cm]: ");
        jari=validasi();
        printf("================================================\n\n");

        keliling=jari*2*PHI;

        system("cls");
        printf("================================================\n");
        printf("| KELILING LINGKARAN : %.2f cm\n", keliling);
        printf("================================================");

        ulang();
    }else if(c==2){
        printf("================================================\n");
        printf("|                LUAS LINGKARAN                |\n");
        printf("================================================\n\n");


        printf("================================================\n");
        printf("| MASUKKAN JARI-JARI LINGKARAN [cm]: ");
        jari=validasi();
        printf("================================================\n\n");

        luas=jari*jari*PHI;

        system("cls");
        printf("================================================\n");
        printf("| LUAS LINGKARAN : %.2f cm2\n", luas);
        printf("================================================");

        ulang();
    }
}
