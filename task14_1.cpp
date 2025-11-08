#include<iostream>
#include<fstream>
using namespace std;
const char fname[] = "data.txt";

double calc(const char* fname) {
    ifstream fin(fname);

    double values;
    double sum = 0;
    
    while(fin >> values){
        sum += values;
    }

    fin.close();
    return sum;
}

int main(){
    cout << "Result = " << calc(fname) << endl;
    return 0;
}