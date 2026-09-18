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
float calcularEficiencia(PanelSolar *panel);
void determinarEstado(PanelSolar *panel);
PanelSolar* obtenerPanelCritico(PanelSolar paneles[], int cantidad);


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

    //parte 2: Calcular la eficiencia de cada panel solar
    //parte 3: Determinar el estado operativo de cada panel solar
    for (int i = 0; i < n; i++)
    {
        calcularEficiencia(&paneles[i]);
        determinarEstado(&paneles[i]);
    }

    //Parte 4: Obtener el panel solar con la eficiencia mas baja
    PanelSolar *panelCritico = obtenerPanelCritico(paneles, n);
    std::cout << "\nEl panel solar con la eficiencia mas baja es: " << std::endl;
    std::cout << "Codigo: " << panelCritico->codigo << std::endl;
    std::cout << "Ubicacion: " << panelCritico->ubicacion << std::endl;
    std::cout << "Potencia teorica: " << panelCritico->potenciaTeorica << std::endl;
    std::cout << "Lecturas: [" << panelCritico->lecturas[0] << ", " << panelCritico->lecturas[1] << ", " << panelCritico->lecturas[2] << "]" << std::endl;
    std::cout << "Eficiencia: " << panelCritico->eficiencia << "%" << std::endl;
    std::cout << "Estado operativo: " << panelCritico->estadoOperativo << std::endl;
    

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

//Calcular la eficiencia de cada panel solar
float calcularEficiencia(PanelSolar *panel){
    //Calcular el promedio de las lecturas 
    float promedioLecturas = (panel->lecturas[0] + panel->lecturas[1] + panel->lecturas[2]) / 3.0f;
    //Calcular la eficiencia del panel solar
    panel->eficiencia = (promedioLecturas / panel->potenciaTeorica) * 100.0;
    return panel->eficiencia; //Retornar la eficiencia calculada
}

//Determinar el estado operativo del panel solar
void determinarEstado(PanelSolar *panel){
    if (panel->eficiencia >= 0.0f && panel->eficiencia <= 50.0f) {
        panel->estadoOperativo = "DEFICIENTE";
    } else if (panel->eficiencia > 50.0f && panel->eficiencia <= 75.0f) {
        panel->estadoOperativo = "ACEPTABLE";
    } else if (panel->eficiencia > 75.0f && panel->eficiencia <= 100.0f) {
        panel->estadoOperativo = "OPTIMO";
    } else if (panel->eficiencia > 100.0f) {
        panel->estadoOperativo = "ANOMALIA";
    }
}

//Obtener el panel solar con la eficiencia mas baja
PanelSolar* obtenerPanelCritico(PanelSolar paneles[], int cantidad){
    // Asumimos inicialmente que el primer elemento es el más crítico
    PanelSolar *critico = &paneles[0];
    for (int i = 1; i < cantidad; i++)
    {
        if (paneles[i].eficiencia < critico->eficiencia)
        {
            critico = &paneles[i]; // Apuntamos a la dirección del nuevo máximo
        }
    }

    return critico; 
}

