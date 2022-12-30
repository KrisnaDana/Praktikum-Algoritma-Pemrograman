#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa{
    char nama[100];
    char nim[100];
};

void cover();
void menu1();
char validasi_nama();
char validasi_nim(char input[]);
void operasi(char input[], char nim[]);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|    PROGRAM SISTEM INFORMASI DATA MAHASISWA   |\n");
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

    printf("================================================\n");
    printf("|                 INPUT DATA                   |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN NAMA MAHASISWA : ");
    validasi_nama();
}

char validasi_nama(){
    int a=0, salah=0, depan=0, hasil=0, i;
    float b;
    char input[100];
    char cadangan[100];

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }
    for(i=0;i<1;){
        if(input[a]!='\0'){
            cadangan[a]=input[a];
            a++;
        }else{
            cadangan[a]='\0';
            i=1;
        }
    }

    a=0;
    while(input[a]!='\0'){
        if(input[a]==32){
            if(input[0]==32){
                salah=1;
                input[a]='\0';
            }else if(input[a-1]==32 && input[a]==32){
                salah=1;
                input[a]='\0';
            }else if(input[a+1]=='\0' && input[a]==32){
                salah=1;
                input[a]='\0';
            }else{
                a++;
            }
        }else{
            if(input[a]>='a' && input[a]<='z' || input[a]>='A' && input[a]<='Z'){
                a++;
            }else{
                salah=1;
                input[a]='\0';
            }
        }
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN DATA YANG BARU : ");
        return validasi_nama();
    }else{
        printf("================================================\n");
        printf("| MASUKKAN NIM MAHASISWA : ");
        validasi_nim(input);
    }
}

char validasi_nim(char input[]){
    int a=0, salah=0, depan=0, hasil=0, i;
    float b;
    char nim[100];
    char cadangan[100];

    scanf("%[^\n]", &nim);
    fflush(stdin);

    if(nim[a]=='\0'){
        salah=1;
    }

    while(nim[a]!='\0'){
        if(nim[a]>='0' && nim[a]<='9'){
            a++;
        }else{
            salah=1;
            nim[a]='\0';
        }
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN DATA YANG BARU : ");
        return validasi_nim(input);
    }else{
        system("cls");
        operasi(input, nim);
    }
}

void operasi(char input[], char nim[]){
    struct mahasiswa m[100];
    int jumlah=0, i, sama=0;

    FILE *in=fopen("file.txt","a+");
        while(!feof(in)){
            fscanf(in,"%[^\n]\n", &m[jumlah].nama);
            fscanf(in,"%f\n\n", &m[jumlah].nim);
            fflush(stdin);
            jumlah++;
        }
        for(i=0;i<jumlah;i++){
            if(strcmp(m[i].nama, input)==0 || strcmp(m[i].nim, nim)==0){
                sama=1;
            }
        }
        if(sama==1){
            fclose(in);
            printf("================================================\n");
            printf("|       DATA SUDAH ADA DI FILE file.txt        |\n");
            printf("|   TIDAK DIPERBOLEHKAN PEN-DOUBLE-AN DATA     |\n");
            printf("================================================\n");

            ulang();
        }else if(sama==0){
            fprintf(in,"%s\n", input);
            fprintf(in,"%s\n\n", nim);
            fclose(in);

            printf("================================================\n");
            printf("|     DATA SUDAH DISIMPAN DI FILE file.txt     |\n");
            printf("================================================\n\n");

            printf("================================================\n");
            printf("| %s\n", input);
            printf("| %s\n", nim);
            printf("================================================\n");

            ulang();
        }
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
