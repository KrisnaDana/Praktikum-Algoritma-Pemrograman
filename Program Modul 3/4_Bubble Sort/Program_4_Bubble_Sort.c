#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cover();
void menu1();
void menu2(int b);
void random(int b, int d);
void bubble_b(int d, int array[]);
void bubble_p(int d, int *arr);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|          PROGRAM METODE BUBBLE SORT          |\n");
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
    printf("| [1] BUBBLE SORT METODE BIASA                 |\n");
    printf("| [2] BUBBLE SORT METODE POINTER               |\n");
    printf("| [3] KELUAR                                   |\n");
    printf("================================================\n");
    printf("| MASUKKAN KODE MENU : ");
    while(a!=b || a<1 || a>3){
        a=validasi();
        b=(int)a;
        if(a!=b || a<1 || a>3){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");
    if(b==3){
        printf("================================================\n");
        printf("| TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI  |\n");
        printf("|        SEMOGA HARI ANDA MENYENANGKAN         |\n");
        printf("================================================\n");
        exit(0);
    }
    menu2(b);
}

void menu2(int b){
    float c;
    int d;

    printf("================================================\n");
    printf("|                PILIHAN MENU                  |\n");
    printf("================================================\n");
    printf("| [1] 1000 BILANGAN ACAK                       |\n");
    printf("| [2] 16000 BILANGAN ACAK                      |\n");
    printf("| [3] 64000 BILANGAN ACAK                      |\n");
    printf("| [4] KEMBALI                                  |\n");
    printf("================================================\n");
    printf("| MASUKKAN KODE MENU : ");
    while(c!=d || c<1 || c>5){
        c=validasi();
        d=(int)c;
        if(c!=d || c<1 || c>5){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");
    if(d==1){
        d=1000;
    }else if(d==2){
        d=16000;
    }else if(d==3){
        d=64000;
    }else if(d==4){
        menu1();
    }
    random(b, d);
}

void random(int b, int d){
    int array[d];
    int i, j, e, f, g, temp, acak;
    clock_t start, end;
    time_t t;
    double waktu;

    printf("================================================\n");
    printf("|             MOHON TUNGGU SEBENTAR            |\n");
    printf("|    PROSES PENGACAKAN DATA SEDANG DILAKUKAN   |\n");
    printf("================================================\n");

    for(i=0;i<d;i++){
        array[i]=i+1;
    }
    srand(time(NULL));
    for(i=0;i<d;i++){
        acak=rand()%d+1;
        temp=array[i];
        array[i]=array[acak];
        array[acak]=temp;
    }
    system("cls");

    if(b==1){
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENGURUTAN DATA SEDANG DILAKUKAN   |\n");
        printf("================================================\n");

        start=clock();
        bubble_b(d, array);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| BUBBLE SORT METODE BIASA DENGAN %d DATA\n", d);
        printf("================================================\n");

    }else if(b==2){
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENGURUTAN DATA SEDANG DILAKUKAN   |\n");
        printf("================================================\n");

        start=clock();
        bubble_p(d, array);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| BUBBLE SORT METODE POINTER DENGAN %d DATA\n", d);
        printf("================================================\n");
    }

    waktu=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n================================================\n");
    printf("| LAMA WAKTU : %.10lf DETIK\n", waktu);
    printf("================================================\n");
    ulang();
}

void bubble_b(int d, int array[]){
    int i, j, temp;
    for (i=0;i<d-1;i++){
        for(j=0;j<d-i-1;j++){
            if (array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

void bubble_p(int d, int *array){
    int i, j, temp;
    for(i=0;i<d;i++){
        for(j=i+1;j<d;j++){
            if(*(array+j) < *(array+i)){
                temp = *(array+i);
                *(array+i) = *(array+j);
                *(array+j) = temp;
            }
        }
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
    exit(0);
}
