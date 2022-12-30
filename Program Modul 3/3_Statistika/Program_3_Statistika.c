#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
void menu2(int b);
void keterangan(int b);
void operasi(int b, int d, float data[]);
void median(int d, float *data);
void modus(int d, float *data);
void mean(int d, float *data);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|    PROGRAM STATISTIKA MENGGUNAKAN POINTER    |\n");
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
    printf("| [1] MEDIAN                                   |\n");
    printf("| [2] MODUS                                    |\n");
    printf("| [3] MEAN                                     |\n");
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
    printf("================================================\n");

    system("cls");
    menu2(b);
}

void menu2(int b){
    float c, z, data[100];
    int d, i;

    keterangan(b);

    printf("\n================================================\n");
    printf("| MASUKKAN JUMLAH DATA : ");
    while(c!=d || c<1){
        c=validasi();
        d=(int)c;
        if(c!=d || c<1){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n");

    system("cls");
    keterangan(b);

    printf("\n");
    for(i=0;i<d;i++){
        printf("================================================\n");
        printf("| MASUKKAN NILAI DATA KE-%d : ", i+1);
        z=validasi();
        data[i]=z;
    }
    system("cls");
    operasi(b, d, data);
}

void operasi(int b, int d, float data[]){
    int i;

    keterangan(b);

    printf("\n================================================\n");
    printf("| DATA YANG TELAH DIMASUKKAN : ");
    for(i=0;i<d;i++){
        if(i+1==d){
            printf("%.2f\n", data[i]);
        }else{
            printf("%.2f, ", data[i]);
        }
    }
    printf("================================================\n");

    if(b==1){
        median(d, data);
    }else if(b==2){
        modus(d, data);
    }else if(b==3){
        mean(d, data);
    }
    ulang();
}

void median(int d, float *data){
    int i, j, posisi;
    float mid, temp;
    for(i=0;i<d;i++){
        for(j=i+1;j<d;j++){
            if(*(data+j) < *(data+i)){
                temp = *(data+i);
                *(data+i) = *(data+j);
                *(data+j) = temp;
            }
        }
    }
    printf("\n================================================\n");
    printf("| DATA YANG TELAH DIURUTKAN : ");
    for(i=0;i<d;i++){
        if(i+1==d){
            printf("%.2f\n", *(data+i));
        }else{
            printf("%.2f, ", *(data+i));
        }
    }
    printf("================================================\n");

    if(d%2==1){
        posisi=(d-1)/2;
        mid=*(data+posisi);
    }else if(d%2==0){
        posisi=d/2;
        mid=(*(data+posisi)+*(data+posisi-1))/2;
    }
    printf("\n================================================\n");
    printf("| MEDIAN DARI DATA TERSEBUT ADALAH : %.2f", mid);
    printf("\n================================================\n");
}

void modus(int d, float *data){
    int i, j, x=0, z=0;
    float modus[d], k, f[d], temp;

    for(i=0;i<d;i++){
        for(j=i+1;j<d;j++){
            if(*(data+j) < *(data+i)){
                temp = *(data+i);
                *(data+i) = *(data+j);
                *(data+j) = temp;
            }
        }
    }

    //menghitung berapa kali muncul tiap angka
    for(i=0;i<d;i++){
        f[i]=0;
        for(j=0;j<d;j++){
            if(*(data+j)==*(data+i)){
                f[i]++;
            }
        }
    }
    //menentukan nilai yang paling sering muncul
    for(i=0;i<d;i++){
        if(f[i]>k){
            k=f[i];
        }
    }
    //jika modus lebih dari satu
    for(i=0;i<d;i++){
        if(x==0){
            modus[x]=0;
        }else{
            modus[x]=modus[x-1];
        }
        if(f[i]==k){
            if(*(data+i)!=modus[x]){
                modus[x]=*(data+i);
                x++;
            }
        }
    }
    for(i=0;i<d;i++){
        if(f[d]==k){
            z++;
        }
        if(z==d){
            x=0;
        }
    }

    printf("\n================================================\n");
    printf("| MODUS DARI DATA TERSEBUT ADALAH : ");
    for(i=0;i<x;i++){
        if(i+x){
            printf(" %.2f", modus[i]);
        }else{
            printf(" %.2f", modus[i]);
        }
    }
    printf("\n================================================\n");
}

void mean(int d, float *data){
    int i;
    float jumlah=0, mean;
    for(i=0;i<d;i++){
        jumlah=jumlah+*(data+i);
    }
    mean=jumlah/d;

    printf("\n================================================\n");
    printf("| MEAN DARI DATA TERSEBUT ADALAH : %.2f", mean);
    printf("\n================================================\n");
}

void keterangan(int b){
    if(b==1){
        printf("================================================\n");
        printf("|                   MEDIAN                     |\n");
        printf("================================================\n");
    }else if(b==2){
        printf("================================================\n");
        printf("|                   MODUS                      |\n");
        printf("================================================\n");
    }else if(b==3){
        printf("================================================\n");
        printf("|                    MEAN                      |\n");
        printf("================================================\n");
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
