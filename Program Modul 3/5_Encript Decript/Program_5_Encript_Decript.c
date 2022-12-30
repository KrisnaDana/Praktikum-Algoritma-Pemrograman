#include <stdio.h>
#include <stdlib.h>

void cover();
void menu1();
void menu2(int b);
void input1(int b, int d);
char validasi_text(int b, int d);
void operasi(int b, int d, char array[]);
float validasi();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|          PROGRAM ENKRIPSI/DESKRIPSI          |\n");
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
    printf("| [1] ENKRIPSI                                 |\n");
    printf("| [2] DESKRIPSI                                |\n");
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

    if(b==1){
        printf("================================================\n");
        printf("|                   ENKRIPSI                   |\n");
        printf("================================================\n");
    }else if(b==2){
        printf("================================================\n");
        printf("|                  DESKRIPSI                   |\n");
        printf("================================================\n");
    }

    printf("\n================================================\n");
    printf("| MASUKKAN JUMLAH PERGESERAN : ");
    while(c!=d){
        c=validasi();
        d=(int)c;
        if(c!=d){
            printf("================================================\n");
            printf("|                 INPUT ERROR                  |\n");
            printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
            printf("================================================\n");
            printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        }
    }
    printf("================================================\n\n");
    system("cls");

    input1(b, d);
}

void input1(int b, int d){
    char e;

    if(b==1){
        printf("================================================\n");
        printf("|                   ENKRIPSI                   |\n");
        printf("================================================\n");

        printf("\n================================================\n");
        printf("| MASUKKAN DATA (plaintext): ");
    }else if(b==2){
        printf("================================================\n");
        printf("|                  DESKRIPSI                   |\n");
        printf("================================================\n");

        printf("\n================================================\n");
        printf("| MASUKKAN DATA (CHIPERTEXT): ");
    }
    e=validasi_text(b, d);
}

char validasi_text(int b, int d){
    int a=0, salah=0, depan=0, hasil=0, i;
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
            if(b==1){
                if(input[a]>='a' && input[a]<='z'){
                    a++;
                }else{
                    salah=1;
                    input[a]='\0';
                }
            }else if(b==2){
                if(input[a]>='A' && input[a]<='Z'){
                    a++;
                }else{
                    salah=1;
                    input[a]='\0';
                }
            }
        }
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN DATA YANG BARU : ");
        return validasi_text(b, d);
    }else{
        system("cls");
        if(b==1){
            printf("================================================\n");
            printf("|                   ENKRIPSI                   |\n");
            printf("================================================\n");

            printf("\n================================================\n");
            printf("| PERGESERAN %d HURUF KE KANAN DARI DATA : %s\n", d, cadangan);
            printf("================================================\n");
        }else if(b==2){
            printf("================================================\n");
            printf("|                  DESKRIPSI                   |\n");
            printf("================================================\n");

            printf("\n================================================\n");
            printf("| PERGESERAN %d HURUF KE KIRI DARI DATA : %s\n", d, cadangan);
            printf("================================================\n");
        }
        operasi(b, d, cadangan);
    }
}

void operasi(int b, int d, char array[]){
    int i, j;

    if(b==1){
        for(i=0;i<100 && array[i]!='\0';i++){
            if(array[i]==' '){

            }else{
                array[i]=array[i]-32+d;
                for(j=0;j<1;){
                    if(array[i]>90){
                        array[i]=array[i]-26;
                    }else{
                        j=1;
                    }
                }
            }
        }
    }else if(b==2){
        for(i=0;i<100 && array[i]!='\0';i++){
            if(array[i]==' '){

            }else{
                array[i]=array[i]+32-d;
                for(j=0;j<1;){
                    if(array[i]<97){
                        array[i]=array[i]+26;
                    }else{
                        j=1;
                    }
                }
            }
        }
    }
    if(b==1){
        printf("\n================================================\n");
        printf("| HASIL ENKRIPSI : %s\n", array);
        printf("================================================\n");
    }else if(b==2){
        printf("\n================================================\n");
        printf("| HASIL DESKRIPSI : %s\n", array);
        printf("================================================\n");
    }
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

