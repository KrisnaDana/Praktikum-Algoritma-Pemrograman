#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
void input1(int b);
void input2(int b, int x, int y);
float validasi();
void ulang();


int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|   PROGRAM OPERASI MATEMATIKA PADA MATRIKS    |\n");
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
    printf("| [1] PENJUMLAHAN                              |\n");
    printf("| [2] PERKALIAN                                |\n");
    printf("| [3] TRANSPOSE                                |\n");
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

    input1(b);
}

void input1(int b){
    float c, d;
    int x, y;
    if(b==1){
        printf("================================================\n");
        printf("|             PENJUMLAHAN MATRIKS              |\n");
        printf("================================================\n");
    }else if(b==2){
        printf("================================================\n");
        printf("|              PERKALIAN MATRIKS              |\n");
        printf("================================================\n");
    }else if(b==3){
        printf("================================================\n");
        printf("|              TRANSPOSE MATRIKS              |\n");
        printf("================================================\n");
    }

    printf("\n================================================\n");
    printf("| MASUKKAN PANJANG KOLOM (SUMBU X) MAKSIMAL 9 : ");
    while(c!=x || c<1 || c>9){
        c=validasi();
        x=(int)c;
        if(c!=x || c<1 || c>9){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n");
    printf("| MASUKKAN PANJANG BARIS (SUMBU Y) MAKSIMAL 9 : ");
    while(d!=y || d<1 || d>9){
        d=validasi();
        y=(int)d;
        if(d!=y || d<1 || d>9){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }

    system("cls");
    input2(b, x, y);
}

void input2(int b, int x, int y){
    float array[10][10], array1[10][10], array2[10][10];
    float g;
    int i, j;

    printf("================================================\n");
    printf("|         INPUT NILAI MATRIKS PERTAMA          |\n");
    printf("================================================\n\n");

    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            printf("================================================\n");
            printf("| MASUKKAN NILAI KOLOM/X KE-%d PADA BARIS/Y KE-%d : ", j+1, i+1);
            g=validasi();
            array1[i][j]=g;
        }
    }
    if(b==1 || b==2){
        system("cls");
        printf("================================================\n");
        printf("|          INPUT NILAI MATRIKS KEDUA           |\n");
        printf("================================================\n\n");
        for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                printf("================================================\n");
                printf("| MASUKKAN NILAI KOLOM/X KE-%d PADA BARIS/Y KE-%d : ", j+1, i+1);
                g=validasi();
                array2[i][j]=g;
            }
        }
    }
    system("cls");
//----------------------------------------------------------------------------------------------------------------------------------


    if(b==1){
        printf("================================================\n");
        printf("|             PENJUMLAHAN MATRIKS              |\n");
        printf("================================================\n");

        for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                array[i][j]=array1[i][j]+array2[i][j];
            }
        }
    }else if(b==2){
        printf("================================================\n");
        printf("|              PERKALIAN MATRIKS              |\n");
        printf("================================================\n");

        for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                array[i][j]=array1[i][j]*array2[i][j];
            }
        }
    }else if(b==3){
        printf("================================================\n");
        printf("|              TRANSPOSE MATRIKS              |\n");
        printf("================================================\n");

        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                array[i][j]=array1[j][i];
            }
        }
    }
    printf("\n================================================\n");
    if(b==1 || b==2){
        printf("| MATRIKS PERTAMA ");
    }else if(b==3){
        printf("| MATRIKS ");
    }
    printf("(%dx%d): \n", x, y);
    printf("================================================");
    for(i=0;i<y;i++){
        printf("\n|");
        for(j=0;j<x;j++){
            if(i+1==y && j+1==x){
                printf("%6.2f", array1[i][j]);
            }else{
                printf("%6.2f, ", array1[i][j]);
            }
        }
    }
    printf("\n================================================\n");
    if(b==1 || b==2){
        printf("\n================================================\n");
        printf("| MATRIKS KEDUA ");
        printf("(%dx%d): \n", x, y);
        printf("================================================");
        for(i=0;i<y;i++){
            printf("\n|");
            for(j=0;j<x;j++){
                if(i+1==y && j+1==x){
                    printf("%6.2f", array2[i][j]);
                }else{
                    printf("%6.2f, ", array2[i][j]);
                }
            }
        }
        printf("\n================================================\n");
    }
    printf("\n");

    if(b==1){
        printf("================================================\n");
        printf("| HASIL PENJUMLAHAN MATRIKS PERTAMA DAN KEDUA  |\n");
        printf("================================================");
    }else if(b==2){
        printf("================================================\n");
        printf("|  HASIL PERKALIAN MATRIKS PERTAMA DAN KEDUA   |\n");
        printf("================================================");
    }else if(b==3){
        printf("================================================\n");
        printf("|           HASIL TRANSPOSE MATRIKS            |\n");
        printf("================================================");
    }
    if(b==1 || b==2){
        for(i=0;i<y;i++){
            printf("\n|");
            for(j=0;j<x;j++){
                if(i+1==y && j+1==x){
                    printf("%6.2f", array[i][j]);
                }else{
                    printf("%6.2f, ", array[i][j]);
                }
            }
        }
    }else if(b==3){
        for(i=0;i<x;i++){
            printf("\n|");
            for(j=0;j<y;j++){
                if(i+1==x && j+1==y){
                    printf("%6.2f", array[i][j]);
                }else{
                    printf("%6.2f, ", array[i][j]);
                }
            }
        }
    }
    printf("\n================================================\n\n");
    ulang();
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
