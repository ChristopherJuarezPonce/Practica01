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

//Declaracion de todas las funciones para el programa
void registrarPanel(PanelSolar &panel);


int main(){

    //Declaracion de maximo 10 paneles solares
    PanelSolar paneles[10];
    int n; // Variable para almacenar el numero de paneles

    /*Este do while sirve para validar que el numero de paneles ingresado
    sea entre 1 y 10, si no es asi se le pedira al usuario que ingrese un 
    numero valido*/
    do
    {
        std::cout << "Ingrese el numero de paneles (maximo 10): ";
        std::cin >> n;
        if(n < 1 || n > 10);
        {
            std::cout << "El numero de elementos es invalido. Debe ser entre el 1 y 10." << std::endl;
        }
    } while (n < 1 || n > 10 );

    // Parte 1: Registrar los paneles solares
    for (int i = 0; i < n; i++) // Este for sirve para recorrer el arreglo de paneles solares y registrar cada uno de ellos
    {
        std::cout << "Panel " << i + 1 << ":" << std::endl;
        registrarPanel(paneles[i]);
    }
    

    return 0;
}

//Registrar los paneles solares
void registrarPanel(PanelSolar &panel){
    std::cout << "Ingrese el codigo del elemento: ";
    std::cin >> panel.codigo;
    std::cout << "Ingrese la ubicacion del panel: ";
    std::cin >> panel.ubicacion;
    std::cout << "Ingrese la potencia teorica: ";
    std::cin >> panel.potenciaTeorica;
    std::cout << "Ingrese la lectura 1: ";
    std::cin >> panel.lecturas[0];
    std::cout << "Ingrese la lectura 2: ";
    std::cin >> panel.lecturas[1];
    std::cout << "Ingrese la lectura 3: ";
    std::cin >> panel.lecturas[2];
}