#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
void input();
float validasi();
float absensi();
float tugas();
float quiz();
float uts();
float uas();
void na(float hasil[]);
void ulang();

int main(){

    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|              PROGRAM NILAI AKHIR             |\n");
    printf("|                  MATA KULIAH                 |\n");
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
    printf("|               RUMUS NILAI ANGKA              |\n");
    printf("================================================\n");
    printf("|  NILAI ANGKA = (ABSENSI(MAKS.15) x 5%) +      |\n");
    printf("| (NILAI 3 TUGAS x 20%) + (NILAI QUIZ x 15%) +   |\n");
    printf("| (NILAI UTS x 30%) + (NILAI UAS x 30%)          |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("|             KETENTUAN NILAI HURUF            |\n");
    printf("================================================\n");
    printf("|    RENTANG NILAI ANGKA    |    NILAI HURUF   |\n");
    printf("================================================\n");
    printf("|       0 <= NA < 45        |         E        |\n");
    printf("|      45 <= NA < 50        |         D        |\n");
    printf("|      50 <= NA < 55        |         D+       |\n");
    printf("|      55 <= NA < 60        |         C        |\n");
    printf("|      60 <= NA < 65        |         C+       |\n");
    printf("|      65 <= NA < 75        |         B        |\n");
    printf("|      75 <= NA < 80        |         B+       |\n");
    printf("|      80 <= NA <= 100      |         A        |\n");
    printf("================================================\n\n");

    system("pause");
    system("cls");

    input();
}

void input(){
    float hasil[5];


    hasil[0]=absensi();

    hasil[1]=tugas();

    hasil[2]=quiz();

    hasil[3]=uts();

    hasil[4]=uas();

    na(hasil);
}

float validasi(){

    char input[100];
    int a=0, i;
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

float absensi(){
    float a, hasil;
    int b;

    printf("================================================\n");
    printf("|                 INPUT ABSENSI                |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN JUMLAH ABSENSI (MAKSIMAL 15) : ");
    while(a!=b || a<0 || a>15){
        a=validasi();
        b=(int)a;
        if(a!=b || a<0 || a>15){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    if(b==0){
        printf("================================================\n");
        printf("|                  NILAI AKHIR                 |\n");
        printf("================================================\n");
        printf("|                NILAI HURUF : E               |\n");
        printf("================================================\n\n\n");

        ulang();
    }else{
        hasil=a/15*5;
        system("cls");
        return hasil;
    }
}

float tugas(){
    float a[3], hasil;
    int i;

    printf("================================================\n");
    printf("|               INPUT NILAI TUGAS              |\n");
    printf("================================================\n");

    for(i=0;i<3;i++){
        printf("\n================================================\n");
        printf("| MASUKKAN NILAI TUGAS KE-%d : ", i+1);
        a[i]=validasi();
        printf("================================================\n\n");

        while(a[i]<0 || a[i]>100){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
            a[i]=validasi();
        }
    }
    hasil=(a[0]+a[1]+a[2])/3*2/10;

    system("cls");
    return hasil;
}

float quiz(){
    float a, hasil;

    printf("================================================\n");
    printf("|               INPUT NILAI QUIZ               |\n");
    printf("================================================\n");

    printf("\n================================================\n");
    printf("| MASUKKAN NILAI QUIZ : ");
    a=validasi();
    printf("================================================\n\n");

    while(a<0 || a>100){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
    }

    hasil=a*15/100;

    system("cls");
    return hasil;
}

float uts(){
    float a, hasil;

    printf("================================================\n");
    printf("|               INPUT NILAI UTS                |\n");
    printf("================================================\n");

    printf("\n================================================\n");
    printf("| MASUKKAN NILAI UTS : ");
    a=validasi();
    printf("================================================\n\n");

    while(a<0 || a>100){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
    }

    hasil=a*3/10;

    system("cls");
    return hasil;
}

float uas(){
    float a, hasil;

    printf("================================================\n");
    printf("|               INPUT NILAI UAS                |\n");
    printf("================================================\n");

    printf("\n================================================\n");
    printf("| MASUKKAN NILAI UAS : ");
    a=validasi();
    printf("================================================\n\n");

    while(a<0 || a>100){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
    }

    hasil=a*3/10;

    system("cls");
    return hasil;
}

void na(float hasil[]){
    float nilai;

    nilai=hasil[0]+hasil[1]+hasil[2]+hasil[3]+hasil[4];

    printf("================================================\n");
    printf("|                  NILAI AKHIR                 |\n");
    printf("================================================\n");
    printf("|       JENIS NILAI         |    NILAI ANGKA   |\n");
    printf("================================================\n");
    printf("| NILAI ABSENSI             |       %.2f       |\n", hasil[0]);
    printf("| NILAI TUGAS               |      %.2f       |\n", hasil[1]);
    printf("| NILAI QUIZ                |      %.2f       |\n", hasil[2]);
    printf("| NILAI UTS                 |      %.2f       |\n", hasil[3]);
    printf("| NILAI UAS                 |      %.2f       |\n", hasil[4]);
    printf("================================================\n");
    printf("| NILAI AKHIR               |     %.2f       |\n", nilai);
    printf("================================================\n");
    printf("| NILAI HURUF               |        ");
    if(nilai>0 && nilai<45){
        printf("E         |\n");
    }else if(nilai>=45 && nilai<50){
        printf("D         |\n");
    }else if(nilai>=50 && nilai<55){
        printf("D+        |\n");
    }else if(nilai>=55 && nilai<60){
        printf("C         |\n");
    }else if(nilai>=60 && nilai<65){
        printf("C+        |\n");
    }else if(nilai>=65 && nilai<75){
        printf("B         |\n");
    }else if(nilai>=75 && nilai<80){
        printf("B+        |\n");
    }else if(nilai>=80 && nilai<=100){
        printf("A         |\n");
    }
    printf("================================================\n");

    ulang();
}

void ulang(){
    float a;
    int b;

    printf("================================================\n");
    printf("|  APAKAH ANDA INGIN MENCOBA PROGRAMNYA LAGI?  |\n");
    printf("================================================\n");
    printf("|         PILIHAN        |        KODE         |\n");
    printf("================================================\n");
    printf("|           YA           |          1          |\n");
    printf("|          TIDAK         |          2          |\n");
    printf("================================================\n\n");

    printf("================================================\n");
    printf("| MASUKKAN KODE : ");
    a=validasi();
    b=(int)a;
    printf("================================================\n\n");

    while(a!=b || a<1 || a>2){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        a=validasi();
        b=(int)a;
    }

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


