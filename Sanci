#include <iostream>
#include <string>

class Matrix{
    protected:
    int s;
    int o;
    char* mezo;

    public:
        Matrix(int s, int o){
            this -> s = s;
            this -> o = o;
            this -> mezo = new char[s*o];
            for(int i=0; i<s*o; i++){
                this -> mezo[i] = '.';
            }
        }

        char & mivanott(int sor, int oszlop){
            return this -> mezo[(sor-1)*o+oszlop-1];
        }

        int sorokszama(){
            return this -> s;
        }

        int oszlopokszama(){
            return this -> o;
        }
};

std::ostream & operator<<(std::ostream & bal, Matrix jobb){
    for(int i = 1; i<=jobb.sorokszama(); i++){
        for(int j = 1; j<=jobb.oszlopokszama(); j++){
            bal << jobb.mivanott(i,j) << ' ';
        }
        bal << std::endl;
    }
    return bal;
}

#define ALMAK 5
#define RAGOK 3
#define KIMARAD 2

int main(){
    srand(time(NULL));
    Matrix matrix1(6, 5);
    matrix1.mivanott(1,1) = 'P';
    int alma = 0;

    while(alma < ALMAK){
        int sor = rand() % matrix1.sorokszama() + 1;
        int oszlop = rand() % matrix1.oszlopokszama() + 1;
        if(matrix1.mivanott(sor,oszlop)=='.'){
            matrix1.mivanott(sor, oszlop) = 'A';
            alma++;
        }
    }
    int rago = 0;

    while(rago < RAGOK){
        int sor = rand() % matrix1.sorokszama() + 1;
        int oszlop = rand() % matrix1.oszlopokszama() + 1;
        if(matrix1.mivanott(sor,oszlop)=='.'){
            matrix1.mivanott(sor, oszlop) = 'R';
            rago++;
        }
    }

    std::cout << matrix1 << std::endl;

    int lepes = 0;
    int sor = 1;
    int oszlop = 1;
    int merre = 1;
    while(alma>0){

        if(matrix1.mivanott(sor, oszlop)=='A'){
            alma--;
        }
        else if(matrix1.mivanott(sor, oszlop)=='R'){
            lepes = lepes + KIMARAD;
        }
        if((merre==1 && oszlop==matrix1.oszlopokszama()) || (merre==-1 && oszlop==1)){
            merre *= -1;
            sor++;
        }
        else{
            oszlop += merre;
        }
        lepes++;
        
        
    }

    std::cout<<"megtett lepesek szama: "<<lepes<<std::endl;
    return 0;
}
