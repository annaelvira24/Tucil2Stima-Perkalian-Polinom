/* TUGAS KECIL 2 IF2211-STRATEGI ALGORITMA */
/* SEMESTER 2 2019/2020 */
/* Anna Elvira Hartoyo */
/* 13518045 */

#include <chrono>
#include <iostream>
#include <stdio.h>
#include "array.h"
#include "PolinomBruteForce.h"
#include "PolinomDivideConquer.h"

int main(){
    
    typedef std::chrono::high_resolution_clock Clock;

    TabInt P1, P2, PHasilBruteForce, PHasilDivide;
    int derajat;
    int perkalian = 0;
    int penjumlahan = 0;

    printf("Masukkan derajat polinom ");
    scanf("%d", &derajat);
    MakeEmpty(&P1, derajat);
    RandomPolinom(&P1);

    MakeEmpty(&P2, derajat);
    RandomPolinom(&P2);
    
    printf("Polinom A(x) = ");
    printPolinom(P1);
    printf("Polinom B(x) = ");
    printPolinom(P2);

    auto start_time = Clock::now();
    PHasilBruteForce = multiplyBruteForce(P1, P2, &perkalian, &penjumlahan);
    auto end_time = Clock::now();

    printf("\n");
    printf("Hasil perkalian polinom A(x) dan B(x) dengan brute force = \n");
    printPolinom(PHasilBruteForce);

    printf("Jumlah operasi perkalian = %d\n", perkalian);
    printf("Jumlah operasi penjumlahan = %d\n", penjumlahan);
    std::cout << "Waktu eksekusi = " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " mirkoseconds" << std::endl;



    perkalian = 0;
    penjumlahan = 0;
    
    auto start_time2 = Clock::now();
    PHasilDivide = multiplyDivideConquer(P1, P2, &penjumlahan, &perkalian);
    auto end_time2 = Clock::now();  
    
    printf("\n");
    printf("Hasil perkalian polinom A(x) dan B(x) dengan divide and conquer = \n");
    printPolinom(PHasilDivide);

    printf("Jumlah operasi perkalian = %d\n", perkalian);
    printf("Jumlah operasi penjumlahan = %d\n", penjumlahan);
    std::cout << "Waktu eksekusi = " << std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2).count() << " mirkoseconds" << std::endl;

}