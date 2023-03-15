#include <iostream>
#include <cmath>

/*
 * 1. (paraméterátadás gyakorlás)Legyen egy struktúra egy személyre alapadatokkal,
 * majd egy függvény számítsa ki, hogy mennyi kalóriát kell bevinnie. Legyen egy függvény,
 * aminek a bemenete, hogy mennyi banánt fogyasztott, és ez alapján csökkenti a napi fennmaradó
 * kalóriaigényt. Egy függvény adja meg, hogy mennyi banánt kell megennie ma, hogy 0-ra jöjjön ki.
 */

const unsigned short int banankcal = 105;

struct szemely{
    float testtomeg;            // kg-ban megadva
    unsigned char testmagassag; // cm-ben megadva
    unsigned char eletkor;      // evekben megadva
    char nem;                   // no avagy ferfi
    float bevittkcal=0;

    szemely(float testtomeg, unsigned char testmagassag, unsigned char eletkor, char nem){
        this->testtomeg = testtomeg;
        this->testmagassag = testmagassag;
        this->eletkor = eletkor;
        this->nem = nem;
    }
};

void banantfogyaszt(unsigned short int db, szemely& ember){
    ember.bevittkcal += db*banankcal;
}


float kaloriaigeny(szemely adatok){

    return std::tolower(adatok.nem)=='f'?
    66.46+13.7*adatok.testtomeg+5*adatok.testmagassag-6.8*adatok.eletkor :
    655.1+9.6*adatok.testtomeg+1.8*adatok.testmagassag-4.7*adatok.eletkor;
}

unsigned int megbanan(szemely ember){
    return std::max(0.f,std::ceil((kaloriaigeny(ember)-ember.bevittkcal)/banankcal));
}


int main() {

    szemely en(55, 170, 19, 'n');
    std::cout << kaloriaigeny(en) << std::endl;
    std::cout << megbanan(en) << std::endl;
    banantfogyaszt(2, en);
    std::cout << megbanan(en) << std::endl;
    return 0;
}
