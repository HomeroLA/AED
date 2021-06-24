#include <iostream>
#include<cassert>

using namespace std;


int cantDias(int, int);
int diasFebrero(int);
bool esMesValido(int);
bool esAnioValido(int);
bool mensajeDatoInvalido();

int main() {
    int mes, anio;

    bool valid = false;

    cout << "Ingrese mes: " << endl;
    cin >> mes;
    cout << "Ingrese anio: " << endl;
    cin >> anio;

    esMesValido(mes) && esAnioValido(anio) ? valid = true : mensajeDatoInvalido(); 

    valid ? cout << "La cantidad de dias es: " << cantDias(mes, anio) : cout << "No es posible calcular la cantidad de dias con los valores ingresados.";
    
    assert(29 == cantDias(2, 2016));
    assert(30 == cantDias(4, 2021));
    assert(29 == cantDias(2, 1988));
    assert(31 == cantDias(12, 1950));
    assert(30 == cantDias(6, 2021));
    assert(28 == cantDias(2, 2003));
}

int cantDias(int mes, int anio) {
    return (mes == 2) ? diasFebrero(anio) : (mes == 4) || (mes == 6) || (mes == 9) || (mes == 11) ? 30 : 31;
}

int diasFebrero(int anio) {
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0) ? 29 : 28;
    //calculo de año bisiesto
}

bool esMesValido(int mes) {
    return mes > 0 && mes < 13;
}

bool esAnioValido(int anio) {
    return anio > 1582;
}

bool mensajeDatoInvalido() {
    cout << "Algun dato ingresado no es valido. ";
    return false;
}
