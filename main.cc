#include <iostream>
#include <string>

/*Un grupo de ingenieros necesita auditar el consumo eléctrico de varios paneles 
solares en una planta fotovoltaica. El sistema trabajará con un máximo de 10 paneles.*/

// Crear la estructura para el panel solar
struct PanelSolar {
    int codigo;
    std::string ubicacion;
    float potenciaTeorica; //Potencia maxima ideal de watts
    float lecturas [3]; //Tres mediciones de potencia real
    float eficiencia; //Porcentaje de rendimiento real vs teorico
    std::string estadoOperativo; //Clasificacion segun eficiencia "Deficiente", "Aceptable", "Optimo" y "Anomalia"
};


int main(){
    return 0;
}