#include <stdio.h>
#include <stdlib.h>
#define GAJIPERJAM 10625

struct harian{
    int jam;
    int perjam;
    int gaji;
};
struct lembur{
    int jam;
    int perjam;
    int gaji;
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
    printf("|        PROGRAM MENGHITUNG GAJI HARIAN        |\n");
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
    printf("| MASUKKAN JUMLAH JAM KERJA : ");
    while(a!=b || a<1 || a>24){
        a=validasi();
        b=(int)a;
        if(a!=b || a<1 || a>24){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");
    operasi(b);

}

void operasi(int b){
    struct harian h;
    struct lembur l;
    int total;

    h.perjam=GAJIPERJAM;
    l.perjam=GAJIPERJAM*8;
    h.jam=b;
    if(h.jam>8){
        l.jam=h.jam-8;
        h.jam=8;
        l.gaji=l.jam*l.perjam;
    }
    h.gaji=h.jam*h.perjam;
    if(b>8){
        total=h.gaji+l.gaji;
    }

    printf("================================================\n");
    printf("|                 GAJI HARIAN                  |\n");
    printf("================================================\n");

    printf("\n================================================\n");
    printf("| GAJI PER JAM : Rp%d\n", h.perjam);
    printf("| JAM KERJA    : %d JAM\n", h.jam);
    printf("| GAJI         : Rp%d\n", h.gaji);
    printf("================================================\n");

    if(b>8){
        printf("\n================================================\n");
        printf("| GAJI PER JAM : Rp%d\n", l.perjam);
        printf("| JAM KERJA    : %d JAM\n", l.jam);
        printf("| GAJI LEMBUR  : Rp%d\n", l.gaji);
        printf("================================================\n");

        printf("\n================================================\n");
        printf("| GAJI TOTAL HARIAN : Rp%d", total);
        printf("\n================================================\n");
    }
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
