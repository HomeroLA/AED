#include <iostream>
#include<cassert>

using namespace std;

int cantDias(int, int);

int diasFebrero(int);

bool esMesValido(int);

bool esAnioValido(int);

bool mensajeDatoInvalido();

int main() {
    int m, a;
    bool valid = false;

    cout << "Ingrese mes: " << endl;
    cin >> m;
    cout << "Ingrese anio: " << endl;
    cin >> a;

    esMesValido(m) && esAnioValido(a) ? valid = true : mensajeDatoInvalido();

    valid ? cout << "La cantidad de dias es: " : cout << "" << endl;
    valid ? cout << cantDias(m, a) : cout << "No es posible calcular la cantidad de dias con los valores ingresados.";

    assert(29 == cantDias(2, 2016));
    assert(30 == cantDias(4, 2021));
    assert(29 == cantDias(2, 1988));
    assert(31 == cantDias(12, 1950));
    assert(30 == cantDias(6, 2021));
    assert(28 == cantDias(2, 2003));
}

int cantDias(int m, int a) {
    return (m == 4) || (m == 6) || (m == 9) || (m == 11) ? 30 :
           (m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12) ? 31 :
           diasFebrero(a);
}

int diasFebrero(int anio) {
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0) ? 29 : 28;
}

bool esMesValido(int mes) {
    return mes > 0 && mes < 13;
}

bool esAnioValido(int anio) {
    return anio > 1582;
}

bool mensajeDatoInvalido() {
    cout << "Algun dato ingresado no es valido";
    return false;
}
