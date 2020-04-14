/* TUGAS KECIL 2 IF2211-STRATEGI ALGORITMA */
/* SEMESTER 2 2019/2020 */
/* Anna Elvira Hartoyo */
/* 13518045 */

#ifndef array_H
#define array_H

#include <time.h>
#include <math.h>
#include "boolean.h"
#include <stdio.h>


/* Definisi elemen dan koleksi objek */
typedef struct
{
  int *TI; /* memori tempat penyimpan elemen (container) */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} TabInt;


/* ********** SELEKTOR ********** */
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
extern void MakeEmpty(TabInt *T, int n)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan Neff = n dan kapasitas maksimum 2*n dan isi tabel (T[i]) = 0*/
{
    (TI(*T)) = new int[n*2];   //inisialisasi array
    MaxEl(*T) = n*2;
    Neff(*T) = n;

    for(int i = 0; i<= n; i++){ //mengisi array dengan 0 hinggan Neff
        Elmt(*T, i) = 0;
    }
}

/* ********** Prosedur/Fungsi untuk Perkalian Polinom ********** */
extern void RandomPolinom(TabInt *T)
/* I.S. T terdefinisi, tidak kosong*/
/* F.S. T terisi bilangan random hingga Neff*/
{
  srand(time(0) + rand());
    for (int i = 0; i<=Neff(*T); i++){
        int temp = pow(-1, rand());
        Elmt(*T,i) = temp * rand() % 50;
    }
}

extern void printPolinom(TabInt T)
/* I.S. T terdefinisi, tidak kosong*/
/* F.S. Nilai T[i] dan i tercetak ke layar dengan format T[i]x^i */
{
  printf("%d",Elmt(T,0));

    for (int i = 1; i<=Neff(T); i++){
        if (Elmt(T,i) >= 0){
            printf(" + %d", Elmt(T,i));
        }

        else{
            printf(" - %d", -1 * Elmt(T,i));
        }
        printf("x^%d", i);
    }
    printf("\n");
}

#endif