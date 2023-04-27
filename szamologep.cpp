#include <iostream>

using namespace std;



void szamologep() {
    float a;
    cout << "adj meg egy szamot" << endl;
    cin >> a;
    char muvelet;
    cout << "adj meg egy muveletet (+,-,*,/)" << endl;
    cin >> muvelet;
    float b;
    cout << "adj meg egy masik szamot" << endl;
    cin >> b;

    try {
        if (muvelet == '+') {
            throw (a + b);
        }
    }
        catch(float eredmeny){
            cout<<"az eredmeny: "<<eredmeny<<endl;
        }

    try {
        if (muvelet == '-') {
            throw (a - b);
        }
    }
    catch(float eredmeny){
        cout<<"az eredmeny: "<<eredmeny<<endl;
    }

    try {
        if (muvelet == '*') {
            throw (a * b);
        }
    }
    catch(float eredmeny){
        cout<<"az eredmeny: "<<eredmeny<<endl;
    }

    try {
        if (muvelet == '/') {
            throw (a / b);
        }
    }
    catch(float eredmeny){
        cout<<"az eredmeny: "<<eredmeny<<endl;
    }



}

int main() {

    szamologep();


    return 0;
}
