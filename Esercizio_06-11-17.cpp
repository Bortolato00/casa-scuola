#include<iostream>
using namespace std;

const float PI=3.14159265358979f;

class Punto{
public:
    float x;
    float y;
public:
    Punto(float x, float y);
};

Punto::Punto(float x, float y):
    x(x), y(y){
    // x = x;
    // y = y;
}

class Cerchio{
public:
    float raggio;
    // float centro_x;
    // float centro_y; invece che avere questi due aggiungo un attributo Punto
    Punto centro;
public:
    Cerchio(float x, float y, float raggio);
    float area();
    float circonferenza();
    float volume();
};

float Cerchio::area(){
    return raggio*raggio*PI;
}

float Cerchio::circonferenza(){
    return 2*raggio*PI;
}

Cerchio::Cerchio(float x, float y, float raggio):
    centro(x, y), raggio(raggio){
    // centro = centro;
    // raggio = raggio;
}

class Cilindro : public Cerchio{
public:
    float altezza;
    Cilindro(float x, float y, float raggio, float altezza);
    float volume();
    float area();
};

Cilindro::Cilindro(float x, float y, float raggio, float altezza):
      Cerchio(x, y, raggio), altezza(altezza){
      // altezza=altezza; questo non si può fare ed è sostituito
      // da altezza(altezza) nella initializer list
}

float Cilindro::area(){
    return Cerchio::area()*2+Cerchio::circonferenza()*altezza;
}
float Cilindro::volume(){
    return Cerchio::area()*altezza;
}
int main(){
    Punto centro(2, 5);
    float raggio(7);
    float altezza(10);
    Cilindro cilindro = Cilindro(centro.x, centro.y, raggio, altezza);
    cout << "Volume del cilindro: ";
    cout << cilindro.volume;
    /* .... altri cout e cin.... */
}
