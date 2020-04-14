/* TUGAS KECIL 2 IF2211-STRATEGI ALGORITMA */
/* SEMESTER 2 2019/2020 */
/* Anna Elvira Hartoyo */
/* 13518045 */

#ifndef PolinomDivideConquer_H
#define PolinomDivideConquer_H

#include "boolean.h"
#include <math.h>
#include "array.h"

TabInt plusPolinom(TabInt P1, TabInt P2, int *count)
/* Jika derajat kedua polinom P1 dan P2 tidak sama, dilakukan padding terlebih dahulu hingga derajat keduanya sama*/
/* Fungsi mengembalikan polinom hasil penjumlahan P1 dan P2 */
{
    TabInt PHasil;
    int i;

    //proses padding
    if(Neff(P1)>Neff(P2)){
        MakeEmpty(&PHasil, Neff(P1));
        for(i = Neff(P2)+1; i<=Neff(P1); i++){
            Elmt(P2,i) = 0;
        }
    }

    else if(Neff(P1)<Neff(P2)){
        MakeEmpty(&PHasil, Neff(P2));
        for(i = Neff(P1)+1; i<=Neff(P2); i++){
            Elmt(P1,i) = 0;
        }
    }

    else{
        MakeEmpty(&PHasil, Neff(P1));
    }

    //Penjumlaha kedua polinom dengan derajat sama
    for(i=0; i<=Neff(PHasil); i++){
        Elmt(PHasil, i) = Elmt(P1,i) + Elmt(P2,i);
        *count++;
    }

    return (PHasil);
}

TabInt MinPolinom(TabInt P1, TabInt P2, int *count)
/* Fungsi mengembalikan polinom hasil pengurangan P1 oleh P2 */
{
    TabInt PHasil;
    int i;

    MakeEmpty(&PHasil, Neff(P1));
    for(i=0; i<=Neff(PHasil); i++){
        Elmt(PHasil, i) = Elmt(P1,i) - Elmt(P2,i);
        *count++;
    }
    return (PHasil);
}

TabInt CopyTab(TabInt Tin, int fromIdx, int toIdx, int fromIdx2)
/* Menyalin isi Tin dari fromindex2 ke TabInt return dari index fromindex hingga toindex*/
{
    int i;
    int j = fromIdx2;
    TabInt TCopy;

    MakeEmpty(&TCopy, toIdx);
    for(i=fromIdx;i<=toIdx;i++)
    {
       Elmt(TCopy,i) = Elmt(Tin,j);
       j++;
    }

    return (TCopy);
}

TabInt CopyTab2(TabInt P1, int x)
/*Menyalin isi P1 ke TabInt return dengan Neff TabInt return sebesar x. Jika Neff P1 tidak sama dengan n,
sisa TabInt akan diisi dengan 0*/
{
    int i;
    TabInt TCopy;

    MakeEmpty(&TCopy, x);
    for(i=0;i<=Neff(P1);i++)
    {
       Elmt(TCopy,i) = Elmt(P1,i);
    }

    //mengisi sisa array dengan 0
    for(i = Neff(P1)+1; i<= x; i++){
        Elmt(TCopy, i) = 0;
    }

    return (TCopy);
}

void geser(TabInt *T, int x)
/* I.S. T terdefinisi, tidak kosong */
/* F.S. elemen pada T telah digeser ke kanan sajauh x indeks */
{
    for(int i = Neff(*T); i>=0; i--){
        Elmt(*T, i + x) = Elmt(*T,i);
        Elmt(*T,i) = 0;
    }
}

TabInt multiplyDivideConquer(TabInt P1, TabInt P2, int *penjumlahan, int *perkalian)
/* Fungsi mengembalikan nilai perkalian Polinom pada P1 dan P2 dengan algoritma divide and conquer,
fungsi juga menghitung banyaknya operasi penjumlahan dan perkalian yang terjadi selama
proes perkalian kedua polinom lalu menyimpannya pada variabel perkalian dan penjumlahan*/
{
    TabInt P1Temp1, P1Temp2, P2Temp1, P2Temp2;
    TabInt Y, U, Z;
    
    int n = Neff(P1);
    MakeEmpty(&Y, 2*n);
    MakeEmpty(&U, 2*n);
    MakeEmpty(&Z, 2*n);

    //base case (solve)
    if(n == 0){
        Elmt(U,0) = Elmt(P1, 0) * Elmt(P2,0);
        *perkalian += 1;
    }
    else if(n == 1){
        Elmt(U,0) = Elmt(P1, 0) * Elmt(P2,0);
        Elmt(Z,2) = Elmt(P1, 1) * Elmt(P2,1);
        Elmt(Y,1) = (Elmt(P1,0)+Elmt(P1,1)) * (Elmt(P2,0) + Elmt(P2,1))-Elmt(U,0)-Elmt(Z,2);
        *perkalian += 3;
        *penjumlahan += 4;
    }

    //rekurens
    else{
        int firstHalf = n/2;
        int secondHalf = n - firstHalf;
        
        //Membagi array Polinom pertama menjadi 2 bagian (divide)
        P1Temp1 = CopyTab(P1, 0, firstHalf-1, 0); //A0(x)
        P1Temp2 = CopyTab(P1, 0, secondHalf, firstHalf); //A1(x)
        
        //Membagi array Polinom kedua menjadi 2 bagian
        P2Temp1 = CopyTab(P2, 0, firstHalf-1, 0); //B0(x)
        P2Temp2 = CopyTab(P2, 0, secondHalf, firstHalf); //B1(x)
        
        //Proses operasi polinom yang sudah dibagi menjadi 2 bagian (conquer)
        U = CopyTab2(multiplyDivideConquer(P1Temp1, P2Temp1, penjumlahan, perkalian),Neff(U));
        Z = CopyTab2(multiplyDivideConquer(P1Temp2, P2Temp2, penjumlahan, perkalian), Neff(Z));
        Y = CopyTab2(multiplyDivideConquer(plusPolinom(P1Temp1, P1Temp2, penjumlahan), plusPolinom(P2Temp1, P2Temp2, penjumlahan), penjumlahan, perkalian), Neff(Y));
        Y = MinPolinom(Y, plusPolinom(U,Z, penjumlahan), penjumlahan);

        geser(&Z,firstHalf*2);
        geser(&Y,firstHalf);
    }

    //Tahap combine U, Y, dan Z
    return (plusPolinom(plusPolinom(U,Y, penjumlahan), Z, penjumlahan));
}


#endif
