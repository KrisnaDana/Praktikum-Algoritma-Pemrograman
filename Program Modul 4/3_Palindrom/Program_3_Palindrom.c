#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cover();
void menu1();
char validasi_kata();
void ulang();

int main(){
    cover();
    return 0;
}

void cover(){
    printf("================================================\n");
    printf("|         PROGRAM KAMUS KATA PALINDROM         |\n");
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
    char a;

    printf("================================================\n");
    printf("| MASUKKAN KATA [chipertext] : ");
    a=validasi_kata();
}

char validasi_kata(){
    int a=0, salah=0, jumlah=0, i, j, k=0, palindrom=0, f[100], sama=0;
    char g[100];
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
            jumlah++;
        }else{
            cadangan[a]='\0';
            i=1;
        }
    }
    for(i=0;i<100;i++){
        f[i]=0;
    }

    a=0;
    while(input[a]!='\0'){
        if(input[a]>='a' && input[a]<='z'){
            a++;
        }else{
            salah=1;
            input[a]='\0';
        }
    }

    for(i=0;i<jumlah;i++){
        if(i==0){
            k++;
            f[k-1]=1;
            g[k-1]=input[i];
            for(j=i+1;j<jumlah;j++){
                if(input[i]==input[j]){
                    f[k-1]++;
                }
            }
        }else{
            for(j=0;j<i;j++){
                if(input[i]==input[j]){
                    sama=1;
                }
            }
            if(sama==0){
                k++;
                f[k-1]=1;
                g[k-1]=input[i];
                for(j=i+1;j<jumlah;j++){
                    if(input[i]==input[j]){
                        f[k-1]++;
                    }
                }
            }else{
                sama=0;
            }
        }
    }

    for(i=0;i<jumlah;i++){
        cadangan[i]=input[jumlah-1-i];
    }

    if(strcmp(input, cadangan)==0){
        palindrom=1;
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");
        printf("| SILAHKAN MASUKKAN DATA YANG BARU : ");
        return validasi_kata();
    }else{
        system("cls");

        printf("================================================\n");
        printf("| %s(%d) : ", input, jumlah);
        for(i=0;i<k;i++){
            printf("%c=%d ", g[i], f[i]);
        }
        if(palindrom==0){
            printf(": Bukan Palindrom");
        }else if(palindrom==1){
            printf(": Palindrom");
        }
        printf("\n================================================\n");

        //OPERASI FILE
        FILE *out=fopen("kamuskata.txt","a");
            fprintf(out,"%s(%d) : ", input, jumlah);
            for(i=0;i<k;i++){
                fprintf(out,"%c=%d ", g[i], f[i]);
            }
            if(palindrom==0){
                fprintf(out,": Bukan Palindrom\n");
            }else if(palindrom==1){
                fprintf(out,": Palindrom\n");
            }
        fclose(out);

        printf("\n================================================\n");
        printf("|  DATA BERHASIL DITAMBAHKAN KE kamuskata.txt  |\n");
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
