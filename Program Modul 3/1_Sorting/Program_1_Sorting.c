#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cover();
void menu1();
void menu2(int b);
void random(int b, int d);
void insertion(int d, int array[]);
void bubble(int d, int array[]);
int quick(int array[], int bawah, int atas);
int quick_pisah(int array[], int bawah, int atas);
int sequential(int f, int d, int array[]);
int binary(int array[], int bawah, int atas, int f);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|     PROGRAM PENGURUTAN DAN PENCARIAN DATA    |\n");
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
    printf("| [1] INSERTION SORT                           |\n");
    printf("| [2] BUBBLE SORT                              |\n");
    printf("| [3] QUICK SORT                               |\n");
    printf("| [4] SEQUENTIAL SEARCH                        |\n");
    printf("| [5] BINARY SEARCH                            |\n");
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
        insertion(d, array);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| INSERTION SORT DENGAN %d DATA\n", d);
        printf("================================================\n");

    }else if(b==2){
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENGURUTAN DATA SEDANG DILAKUKAN   |\n");
        printf("================================================\n");

        start=clock();
        bubble(d, array);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| BUBBLE SORT DENGAN %d DATA\n", d);
        printf("================================================\n");
    }else if(b==3){
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENGURUTAN DATA SEDANG DILAKUKAN   |\n");
        printf("================================================\n");

        start=clock();
        quick(array, 0, d-1);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| QUICK SORT DENGAN %d DATA\n", d);
        printf("================================================\n");
    }else if(b==4){
        printf("================================================\n");
        printf("| SEQUENTIAL SEARCH DENGAN %d DATA\n", d);
        printf("================================================\n");
        printf("| MASUKKAN DATA YANG INGIN DICARI [1 - %d] : ", d);
        while(e!=f){
            e=validasi();
            f=(int)e;
            if(e!=f){
                printf("================================================\n");
                printf("|                 INPUT ERROR                  |\n");
                printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
                printf("================================================\n");
                printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
            }
        }
        system("cls");
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENCARIAN DATA SEDANG DILAKUKAN    |\n");
        printf("================================================\n");

        start=clock();
        g=sequential(f, d, array);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| SEQUENTIAL SEARCH DENGAN %d DATA\n", d);
        printf("================================================\n");
        printf("| DATA YANG INGIN DICARI ADALAH %d\n", f);
        printf("================================================\n\n");

        printf("================================================\n");
        printf("|               DATA DITEMUKAN                 |\n");
        printf("================================================\n");

    }else if(b==5){
        printf("================================================\n");
        printf("| BINARY SEARCH DENGAN %d DATA\n", d);
        printf("================================================\n");
        printf("| MASUKKAN DATA YANG INGIN DICARI [1 - %d] : ", d);
        while(e!=f){
            e=validasi();
            f=(int)e;
            if(e!=f){
                printf("================================================\n");
                printf("|                 INPUT ERROR                  |\n");
                printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
                printf("================================================\n");
                printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
            }
        }
        printf("================================================\n");
        printf("|             MOHON TUNGGU SEBENTAR            |\n");
        printf("|    PROSES PENCARIAN DATA SEDANG DILAKUKAN    |\n");
        printf("================================================\n");

        quick(array, 0, d-1);
        start=clock();
        g=binary(array, 0, d-1, f);
        end=clock();

        system("cls");
        printf("================================================\n");
        printf("| BINARY SEARCH DENGAN %d DATA\n", d);
        printf("================================================\n");
        printf("| DATA YANG INGIN DICARI ADALAH %d\n", f);
        printf("================================================\n");

        printf("================================================\n");
        printf("|               DATA DITEMUKAN                 |\n");
        printf("================================================\n");

    }
    waktu=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n================================================\n");
    printf("| LAMA WAKTU : %.10lf DETIK\n", waktu);
    printf("================================================\n");
    ulang();

}

void insertion(int d, int array[]){
    int i, j, kunci;
    for (i=1;i<d;i++){
        kunci = array[i];
        j=i-1;
        while(j>=0 && array[j]>kunci){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=kunci;
    }
}

void bubble(int d, int array[]){
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

int quick(int array[], int bawah, int atas){
    int pi;
    if(bawah<atas){
        pi=quick_pisah(array, bawah, atas);
        quick(array, bawah, pi-1);
        quick(array, pi+1, atas);
    }
}

int quick_pisah(int array[], int bawah, int atas){
    int n, x , y, pivot, wadah;

    pivot=array[atas];
    x=(bawah-1);
    for(y=bawah;y<=atas-1;y++){
        if(array[y]<=pivot){
            x++;
            wadah=array[x];
            array[x]=array[y];
            array[y]=wadah;
        }
    }
    wadah=array[x+1];
    array[x+1]=array[atas];
    array[atas]=wadah;

    return (x+1);
}

int sequential(int f, int d, int array[]){
    int i;
    int temu=0;

    for(i=0;i<d;i++){
        if(array[i]==f){
            temu=1;
            return i;
        }
    }
    system("cls");
    printf("================================================\n");
    printf("| SEQUENTIAL SEARCH DENGAN %d DATA\n", d);
    printf("================================================\n");
    printf("| DATA YANG INGIN DICARI ADALAH %d\n", f);
    printf("================================================\n\n");
    if(temu==0){
        printf("================================================\n");
        printf("|            DATA TIDAK DITEMUKAN              |\n");
        printf("================================================\n");

        ulang();
    }
}

int binary(int array[], int bawah, int atas, int f){
    int tengah;
    int temu=0;
    while(bawah<=atas){
        tengah=bawah+(atas-bawah)/2;
        if(array[tengah]==f){
            temu=1;
            return tengah;
        }else if(array[tengah]<f){
            bawah=tengah+1;
        }else{
            atas=tengah-1;
        }
    }
    system("cls");
    if(temu==0){
        printf("================================================\n");
        printf("|            DATA TIDAK DITEMUKAN              |\n");
        printf("================================================\n");

        ulang();
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

