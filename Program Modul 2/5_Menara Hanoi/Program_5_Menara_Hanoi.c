#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int cakram;

int main(){
   Intro();
   pilihan();

}


void Intro(){
    printf("||===========================================||\n");
    printf("||                Kelompok 17                ||\n");
    printf("||====||=======================||============||\n");
    printf("|| No ||     Nama Anggota      ||    NIM     ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 01 || Ni Luh Gede Gita      || 2005551028 ||\n");
    printf("||    || Putri Prita Sari      ||            ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 02 || I Putu Ngurah         || 2005551084 ||\n");
    printf("||    || Krisna Dana           ||            ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 03 || Gede Ade Rangga       || 2005551142 ||\n");
    printf("||    || Arianta               ||            ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 04 || Gede Raditya          || 2005551062 ||\n");
    printf("||    || Arya Wiguna           ||            ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 05 || Raja Tigor            || 2005551149 ||\n");
    printf("||    || Wirawan Simanjuntak   ||            ||\n");
    printf("||====||=======================||============||\n");
    printf("|| 06 || Herry Daniel          || 2005551052 ||\n");
    printf("||    || Prasetia Liukae       ||            ||\n");
    printf("||====||=======================||============||\n\n");
    system("pause");
}

float validasi1(){
    char Input_User[100];
    int a = 0;
    int behind = 0;
    int depan_koma = 0;
    int belakang_koma = 0;
    int kondisi = 0;
    int point = 0;
    int False = 0;
    int Min = 0;
    float Result;

    scanf(" %[^\n]", &Input_User);
    fflush(stdin);

    while(Input_User[a] != '\0'){
        if(Input_User[0] == '.'){
            False = 1;
            Input_User[0] = '\0';
        }else if(Input_User[a] == ' '){
            False = 1;
            Input_User[a] = '\0';
        }else if(Input_User[a]>='0' && Input_User[a]<='9' || Input_User[a] == '.' || Input_User[0] == '-'){
            if(Input_User[a] == '.'){
                point = point + 1;
                if(point > 1 || Input_User[a+1] == '\0'){
                    False = 1;
                    Input_User[a] = '\0';
                }
                kondisi = 1;
            }
            if(Input_User[0] == '-'){
                Min = 1;
            }
            if(Input_User[a]>='0' && Input_User[a]<='9'){
                if(kondisi == 1){
                    belakang_koma = (belakang_koma * 10) + (Input_User[a] - 48);
                    behind = behind + 1;
                }else{
                    depan_koma = (depan_koma * 10) + (Input_User[a] - 48);
                }
            }
        a++;
        }else{
            False = 1;
            Input_User[a] = '\0';
        }

    }
    if(point == 1){
        Result = (float) depan_koma + (belakang_koma / (pow(10, behind)));
    }else{
        Result = depan_koma;
    }
    if(Min == 1){
        Result = Result - (Result * 2);
    }
    if(False == 1){
        printf("\n");
        printf("||====================||\n");
        printf("||  Input Anda salah  ||\n");
        printf("||====================||\n");
        printf("\nInput angka dengan benar : ");
        return validasi1();
    }else{
        return Result;
    }
}

void try_again(){
        int choice;
        printf("||======================||\n");
        printf("||    Ingin mencoba     ||\n");
        printf("||   Prorgamnya lagi ?  ||\n");
        printf("||==========||==========||\n");
        printf("||    Y(1)  ||    N(0)  ||\n");
        printf("||==========||==========||\n");
        printf("|| Pilihan anda : ");
        choice = validasi1();

        if(choice == 1){
            menara_hanoi();
        }else if(choice == 0){
            system("cls");
            printf("||=========================||\n");
            printf("||    Terima kasih telah   ||\n");
            printf("|| Menggunakan program ini ||\n");
            printf("||=========================||\n");
            system("pause");
            system("exit");
        }else
        try_again();
}


void pilihan(){

    int pil;
    system("cls");
    printf("||==================================||\n");
    printf("||      Tentukkan pilihan metode    ||\n");
    printf("||            perulangan            ||\n");
    printf("||====||=============||=============||\n");
    printf("|| No ||   Pilihan   ||    Kode     ||\n");
    printf("||====||=============||=============||\n");
    printf("|| 01 || Rekursif    ||      1      ||\n");
    printf("||====||=============||=============||\n");
    printf("|| 02 || Iteratif    ||      2      ||\n");
    printf("||====||=============||=============||\n");



    printf("\nMasukkan kode dengan benar : ");
    pil = validasi1();
    system("cls");
    menara_hanoi();

    if(pil == 1){
       system("cls");
       printf("||================================||\n");
       printf("||       Langkah - langkah        ||\n");
       printf("||      Perpindahan  Cakram       ||\n");
       printf("||================================||\n\n");
       hanoiTw_rekursif(cakram,'1','2','3');
    }else if(pil == 2){
       system("cls");
        printf("||================================||\n");
        printf("||       Langkah - langkah        ||\n");
        printf("||      Perpindahan  Cakram       ||\n");
        printf("||================================||\n\n");
        hanoiTw_iteratif(cakram);
    }else{
        printf("\n||===============================||\n");
        printf("|| Kode yang anda masukkan salah ||\n");
        printf("||  harap masukkan kode dengan   ||\n");
        printf("||             benar             ||\n");
        printf("||===============================||\n");
        system("pause");
        pilihan();
    }

    try_again();
 }



void menara_hanoi(){
    system("cls");
    printf("||================================||\n");
    printf("||       Program Menara Hanoi     ||\n");
    printf("||================================||\n");
    printf("|| Masukkan jumlah cakram : ");
    cakram = validasi1();
    printf("||================================||\n");


}


void hanoiTw_rekursif(int cakram,char a, char b, char c){


    if(cakram == 1){
        printf("||================================||\n");
        printf("|| Pindahkanlah cakram paling     ||\n");
        printf("|| tertinggi dari Tiang %c menuju  ||\n",a);
        printf("|| Tiang %c                        ||\n",c);
        printf("||================================||\n\n");
    }else{
        hanoiTw_rekursif(cakram-1,a,c,b);
        hanoiTw_rekursif(1,a,b,c);
        hanoiTw_rekursif(cakram-1,b,a,c);
    }
}

void hanoiTw_iteratif(int cakram){

   for (int x=1; x < (1 << cakram); x++){
        printf("||================================||\n");
        printf("|| Pindahkanlah cakram paling     ||\n");
        printf("|| tertinggi dari Tiang %d menuju  ||\n",((x&(x-1))%3)+1);
        printf("|| Tiang %d                        ||\n",(((x|(x-1))+1)%3) + 1);
        printf("||================================||\n\n");

   }

}



