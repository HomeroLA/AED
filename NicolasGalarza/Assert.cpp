#include <iostream>
#include <array>
#include <valarray>
#include <cassert>

using namespace std;

unsigned const MAX = 50;

struct Punto {
    double x, y;
};

struct Poligono {
    unsigned n = 0;
    array<Punto, MAX> vertices{};
};

void addVertice(Poligono &, unsigned, Punto);

Punto getVertice(const Poligono &, unsigned);

void setVertice(Poligono &, unsigned, Punto);

void removeVertice(Poligono &, unsigned);

unsigned getCantidadLados(const Poligono &);

double getPerimetro(const Poligono &);

double getDistanciaEntrePuntos(Punto, Punto);

//TESTS
void runTests();

void testAddVertice();

void testGetVertice();

void testSetVertice();

void testRemoveVertice();

void testGetCantidadLados();

void testGetPerimetro();

void testPoligonoConCincoPuntos();

int main() {
    runTests();
    cout << "Ejecucion exitosa" << endl;
}

void addVertice(Poligono &poligono, unsigned posicion, Punto punto) {
    for (unsigned i = MAX - 1; i > posicion; i--) {
        poligono.vertices.at(i) = poligono.vertices.at(i - 1);
    }
    poligono.vertices.at(posicion) = punto;
    poligono.n++;
}

Punto getVertice(const Poligono &poligono, unsigned posicion) {
    return poligono.vertices.at(posicion);
}

void setVertice(Poligono &poligono, unsigned posicion, Punto punto) {
    poligono.vertices.at(posicion) = punto;
}

void removeVertice(Poligono &poligono, unsigned posicion) {
    for (unsigned i = posicion; i < MAX - 1; i++) {
        poligono.vertices.at(i) = poligono.vertices.at(i + 1);
    }
    poligono.n--;
}

unsigned getCantidadLados(const Poligono &poligono) {
    return poligono.n;
}

double getPerimetro(const Poligono &poligono) {
    double perimetro = 0;
    unsigned ultimaPosicion = poligono.n - 1;
    array<Punto, MAX> vertices = poligono.vertices;

    for (unsigned i = 0; i < ultimaPosicion; i++) {
        perimetro += getDistanciaEntrePuntos(vertices.at(i + 1), vertices.at(i));
    }
    perimetro += getDistanciaEntrePuntos(vertices.at(0), vertices.at(ultimaPosicion));

    return perimetro;
}

double getDistanciaEntrePuntos(Punto extremo, Punto origen) {
    return sqrt(pow(extremo.x - origen.x, 2) + pow(extremo.y - origen.y, 2));
}

//TESTS
void runTests() {
    testAddVertice();
    testGetVertice();
    testSetVertice();
    testRemoveVertice();
    testGetCantidadLados();
    testGetPerimetro();
    testPoligonoConCincoPuntos();
}

void testAddVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    addVertice(poligono, 0, punto);
    assert(poligono.vertices.at(0).x == punto.x);
    assert(poligono.vertices.at(0).y == punto.y);
}

void testGetVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    addVertice(poligono, 0, punto);
    assert(getVertice(poligono, 0).x == punto.x);
    assert(getVertice(poligono, 0).y == punto.y);
}

void testSetVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    setVertice(poligono, 4, punto);
    assert(poligono.vertices.at(4).x == punto.x);
    assert(poligono.vertices.at(4).y == punto.y);
}

void testRemoveVertice() {
    Poligono poligono;
    Punto punto{3, 3};
    addVertice(poligono, 0, punto);
    removeVertice(poligono, 0);
    assert(poligono.vertices.at(0).x == 0);
    assert(poligono.vertices.at(0).y == 0);
}

void testGetCantidadLados() {
    Poligono poligono;
    Punto punto0{1, 1};
    Punto punto1{2, 2};
    Punto punto2{3, 3};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    assert(getCantidadLados(poligono) == 3);
}

void testGetPerimetro() {
    Poligono poligono;
    Punto punto0{0, 1};
    Punto punto1{0, 2};
    Punto punto2{1, 2};
    Punto punto3{1, 1};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    addVertice(poligono, 3, punto3);
    assert(getPerimetro(poligono) == 4);
}

void testPoligonoConCincoPuntos() {
    Poligono poligono;
    Punto punto0{1, 5};
    Punto punto1{4, 2};
    Punto punto2{0, -1};
    Punto punto3{-3, 3};
    Punto punto4{-2, 6};
    Punto punto5{3, 6};
    Punto punto6{-2, -2};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    addVertice(poligono, 3, punto3);
    addVertice(poligono, 4, punto4);
    addVertice(poligono, 5, punto5);
    removeVertice(poligono, 0);
    setVertice(poligono, 1, punto6);
    assert(getVertice(poligono, 1).x == -2);
    assert(getVertice(poligono, 1).y == -2);
    assert(getPerimetro(poligono) < 24.6);
    assert(getPerimetro(poligono) > 24.5);
    assert(getCantidadLados(poligono) == 5);
}

