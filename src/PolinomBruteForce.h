/* TUGAS KECIL 2 IF2211-STRATEGI ALGORITMA */
/* SEMESTER 2 2019/2020 */
/* Anna Elvira Hartoyo */
/* 13518045 */

#ifndef PolinomBruteForce_H
#define PolinomBruteForce_H

#include "boolean.h"
#include <math.h>
#include <time.h>
#include "array.h"

TabInt multiplyBruteForce(TabInt P1, TabInt P2, int *perkalian, int *penjumlahan)
/* Fungsi mengembalikan nilai perkalian Polinom pada T1 dan T2 dengan algoritma brute force,
fungsi juga menghitung banyaknya operasi penjumlahan dan perkalian yang terjadi selama
proes perkalian kedua polinom lalu menyimpannya pada variabel perkalian dan penjumlahan*/
{
    TabInt PHasil;
    int i, j;
    int countplus = 0;
    int countmultiply = 0;

    MakeEmpty(&PHasil, Neff(P1) + Neff(P2)); // inisialisasi array untuk hasil

    // proses perkalian P1 dan P2 secara brute force
    for (i=0; i <= Neff(P1); i++) { 
        for (j=0; j <= Neff(P2); j++){
            Elmt(PHasil,i+j) += Elmt(P1, i) * Elmt(P2,j);
            countmultiply++;
            countplus++;
        }
    } 

    *penjumlahan = countplus;
    *perkalian = countmultiply;
    return PHasil;
}

#endif
