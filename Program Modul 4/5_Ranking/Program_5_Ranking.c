#include <stdio.h>
#include <stdlib.h>

struct mahasiswa
{
    char nama[100];
    float nilai;
};

void cover();
void menu1();
void operasi(struct mahasiswa m[], int jumlah);

int main()
{
    cover();
    return 0;
}

void cover()
{
    printf("================================================\n");
    printf("|        PROGRAM FILE PERANKINGAN NILAI        |\n");
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

void menu1()
{
    struct mahasiswa m[100];
    int jumlah = 0, i;

    FILE *in = fopen("asistenin.txt", "r");
    if (!in)
    {
        printf("================================================\n");
        printf("|      FILE asistenin.txt TIDAK DITEMUKAN      |\n");
        printf("| SILAHKAN BUAT FILE TERSEBUT TERLEBIH DAHULU  |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("| TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI  |\n");
        printf("|        SEMOGA HARI ANDA MENYENANGKAN         |\n");
        printf("================================================\n");
        exit(0);
    }
    else
    {
        printf("================================================\n");
        printf("|         FILE asistenin.txt DITEMUKAN         |\n");
        printf("================================================\n\n");

        printf("================================================\n");
        printf("|    DATA YANG TERDAPAT DI FILE asistenin.txt  |\n");
        printf("================================================\n\n");
        while (!feof(in))
        {
            fscanf(in, "%[^\n]\n", &m[jumlah].nama);
            fscanf(in, "%f\n", &m[jumlah].nilai);
            fflush(stdin);
            jumlah++;
        }
        fclose(in);

        for (i = 0; i < jumlah; i++)
        {
            printf("%s\n%.2f\n", m[i].nama, m[i].nilai);
        }
        printf("\n\n");
        system("pause");
        system("cls");

        operasi(m, jumlah);
    }
}

void operasi(struct mahasiswa m[], int jumlah)
{
    struct mahasiswa temp;
    int i, j;

    for (i = 0; i < jumlah - 1; i++)
    {
        for (j = 0; j < jumlah - i - 1; j++)
        {
            if (m[j].nilai < m[j + 1].nilai)
            {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
    printf("================================================\n");
    printf("|          DATA YANG TELAH DIRANGKING          |\n");
    printf("|     DAN DISIMPAN PADA FILE asistenout.txt    |\n");
    printf("================================================\n\n");

    printf("Nilai Mata Kuliah Algoritma dan Pemrograman\n");
    for (i = 0; i < jumlah; i++)
    {
        printf("%d. %s %.2f\n", i + 1, m[i].nama, m[i].nilai);
    }

    FILE *out = fopen("asistenout.txt", "w");
    fprintf(out, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
    for (i = 0; i < jumlah; i++)
    {
        fprintf(out, "%d. %s %.2f\n", i + 1, m[i].nama, m[i].nilai);
    }
    fclose(out);

    printf("\n\n");
    system("pause");
    system("cls");

    printf("================================================\n");
    printf("| TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI  |\n");
    printf("|        SEMOGA HARI ANDA MENYENANGKAN         |\n");
    printf("================================================\n");
    exit(0);
}
