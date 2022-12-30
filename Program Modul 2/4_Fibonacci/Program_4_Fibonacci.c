#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
void input(int b);
void rekursif(int n, int i, int pass, int bil1, int bil2, int awal);
void iteratif(int n);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("| PROGRAM MENAMPILKAN DERET BILANGAN FIBONACCI |\n");
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
    printf("|  METODE MENAMPILKAN DERET BILANGAN FIBONACCI |\n");
    printf("================================================\n");
    printf("| [1] METODE REKURSIF                          |\n");
    printf("| [2] METODE ITERATIF                          |\n");
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
    printf("================================================\n");
    system("cls");

    input(b);
}

void input(int b){
    float m;
    int n;
    int i=2, pass, bil1=0, bil2=1, awal=0; //UNTUK METODE REKURSIF

    if(b==1){
        printf("================================================\n");
        printf("|               METODE REKURSIF                |\n");
        printf("================================================\n\n");
    }else if(b==2){
        printf("================================================\n");
        printf("|               METODE ITERATIF                |\n");
        printf("================================================\n\n");
    }

    printf("================================================\n");
    printf("| MASUKKAN n DERET BILANGAN FIBONACCI : ");
    while(m!=n || m<1){
        m=validasi();
        n=(int)m;
        if(m!=n || m<1){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n");
    system("cls");

    if(b==1){
        printf("================================================\n");
        printf("|               METODE REKURSIF                |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("|         %d DERET BILANGAN FIBONACCI          |\n", n);
        printf("================================================\n\n");

        rekursif(n, i, pass, bil1, bil2, awal);
    }else if(b==2){
        iteratif(n);
    }
}

void rekursif(int n, int i, int pass, int bil1, int bil2, int awal){
    if(n==1){
        printf("%d", bil1);
    }else if(n>=i && awal==0){
        printf("%d, %d", bil1, bil2);
    }
    if(n>2 && i<n){
        pass=bil1+bil2;
        bil1=bil2;
        bil2=pass;
        awal=1;
        i++;

        printf(", %d", pass);

        rekursif(n, i, pass, bil1, bil2, awal);
    }
    ulang();
}

void iteratif(int n){
    int i, pass, bil1=0, bil2=1;

    printf("================================================\n");
    printf("|               METODE ITERATIF                |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("|         %d DERET BILANGAN FIBONACCI          |\n", n);
    printf("================================================\n\n");

    for(i=0;i<n;i++){
        if(i==0){
            pass=bil1;
        }else if(i==1){
            pass=bil2;
        }else{
            pass=bil1+bil2;
            bil1=bil2;
            bil2=pass;
        }
        if(i+1==n){
            printf("%d", pass);
        }else{
            printf("%d, ", pass);
        }
    }
    ulang();
}

float validasi(){

    char input[100];
    int a=0;
    int salah=0;
    int depan=0;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]>='0' && input[a]<='9'){
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

