#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int t;
float p,i;
float persen_bunga;
float validasi2();
float validasi3();

int main(){
   intro();
   kalkulasi_angsuran();
}


void intro(){

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
    char input_user[100];
    int a = 0;
    int behind = 0;
    int depan_koma = 0;
    int belakang_koma = 0;
    int kondisi = 0;
    int point = 0;
    int salah = 0;
    int min = 0;
    float result;

    scanf(" %[^\n]", &input_user);
    fflush(stdin);

    while(input_user[a] != '\0'){
        if(input_user[0] == '.'){
            salah = 1;
            input_user[0] = '\0';
        }else if(input_user[a] == ' '){
            salah = 1;
            input_user[a] = '\0';
        }else if(input_user[a]>='0' && input_user[a]<='9' || input_user[a] == '.' || input_user[0] == '-'){
            if(input_user[a] == '.'){
                point = point + 1;
                if(point > 1 || input_user[a+1] == '\0'){
                    salah = 1;
                    input_user[a] = '\0';
                }
                kondisi = 1;
            }
            if(input_user[0] == '-'){
                min = 1;
            }
            if(input_user[a]>='0' && input_user[a]<='9'){
                if(kondisi == 1){
                    belakang_koma = (belakang_koma * 10) + (input_user[a] - 48);
                    behind = behind + 1;
                }else{
                    depan_koma = (depan_koma * 10) + (input_user[a] - 48);
                }
            }
        a++;
        }else{
            salah = 1;
            input_user[a] = '\0';
        }

    }
    if(point == 1){
        result = (float) depan_koma + (belakang_koma / (pow(10, behind)));
    }else{
        result = depan_koma;
    }
    if(min == 1){
        result = result - (result * 2);
    }
    if(salah == 1){
        printf("||====================||\n");
        printf("||  Input Anda salah  ||\n");
        printf("||====================||\n");
        printf("\nInput angka dengan benar : ");
        return validasi1();
    }else{
        return result;
    }
}

void try_again(){

        int choice;
        printf("||======================||\n");
        printf("||    Ingin mencoba     ||\n");
        printf("||  Prorgamnya lagi ?   ||\n");
        printf("||==========||==========||\n");
        printf("||    Y(1)  ||    N(0)  ||\n");
        printf("||==========||==========||\n");
        printf("|| Pilihan anda : ");
        choice = validasi1();

        printf("%d",choice);
        if(choice == 1){
            kalkulasi_angsuran();
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

void kalkulasi_angsuran(){
    system("cls");
    printf("||========================================||\n");
    printf("||            Program Perhitungan         ||\n");
    printf("||                 Angsuran               ||\n");
    printf("||========================================||\n");
    printf("|| Masukkan pokok pinjaman (dalam Rp)     ||\n");
    printf("|| Pokok pinjaman : ");
    p = validasi1();
    printf("|| Masukkan besar bunga(persen/tahun)     ||\n");
    printf("|| Besar Bunga    : ");
    i = validasi1();
    validasi2();
    printf("|| Masukkan lama pinjaman (dalam bulan)   ||\n");
    printf("|| Lama Pinjamaan : ");
    t = validasi1();
    validasi3();
    printf("||========================================||\n");
    invoice();
    try_again();
}

float validasi2(){


        if(i > 100){
            printf("\n");
            printf("||============================||\n");
            printf("||  Rentang persentase bunga  ||\n");
            printf("||  yang anda masukkan salah, ||\n");
            printf("||  mohon memasukkan rentang  ||\n");
            printf("||    dari 0 - 100 persen     ||\n");
            printf("||============================||\n");
            printf("\n|| Masukkan besar bunga(persen/tahun)      : ");
            scanf("%f",&i);

            return validasi2();
        }
        else{
            return i;
        }
    }

float validasi3(){
     if(t > 12 || t < 1){

            printf("\n");
            printf("||============================||\n");
            printf("||   Rentang lama peminjaman  ||\n");
            printf("||  yang anda masukkan salah, ||\n");
            printf("||  mohon memasukkan rentang  ||\n");
            printf("||      dari 1 - 12 bulan     ||\n");
            printf("||============================||\n");
            printf("\n|| Masukkan lama pinjaman( dalam bulan)    : ");
            scanf("%d",&t);

            return validasi3();
        }
        else{
            return t;
        }
    }



void invoice(){
    float angs_bunga;
    float angs_pokok = p/t;
    float total_angs;
    float total_bunga;
    float total_pokok;
    float total_bayar;



  printf("\n||==============||==============||======================||==================||\n");
    printf("||    Bulan     ||    Bunga     ||    Angsuran Pokok    ||      Total       ||\n");
    printf("||==============||==============||======================||==================||\n");
    for(int month = 1; month <= t; month++){
        angs_bunga = (p - ((month - 1)*angs_pokok))*((i/12)/100);
        total_angs = angs_bunga + angs_pokok;
     printf("||\t%d\t||Rp.%10.2f ||Rp.%12.2f       ||Rp.%11.2f    ||\n",month,angs_bunga,angs_pokok, total_angs);
        total_bunga += angs_bunga;
        total_pokok += angs_pokok;
        total_bayar += total_angs;
    }

     printf("||==============||==============||======================||==================||\n");
     printf("||    Total     ||Rp.%10.2f ||Rp.%14.2f     ||Rp.%14.2f ||\n", total_bunga, total_pokok, total_bayar);
     printf("||==============||==============||======================||==================||\n");
     printf("\n");
     try_again();
     system("pause");


}

