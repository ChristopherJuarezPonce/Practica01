#include <iostream>
#include <string>

/*Un grupo de ingenieros necesita auditar el consumo eléctrico de varios paneles
solares en una planta fotovoltaica. El sistema trabajará con un máximo de 10 paneles.*/

// Crear la estructura para el panel solar
struct PanelSolar
{
    int codigo;
    std::string ubicacion;
    float potenciaTeorica;       // Potencia maxima ideal de watts
    float lecturas[3];           // Tres mediciones de potencia real
    float eficiencia;            // Porcentaje de rendimiento real vs teorico
    std::string estadoOperativo; // Clasificacion segun eficiencia "Deficiente", "Aceptable", "Optimo" y "Anomalia"
};

// Declaracion de todas las funciones para el programa
void registrarPanel(PanelSolar &panel);
float calcularEficiencia(PanelSolar *panel);
void determinarEstado(PanelSolar &panel);
PanelSolar *obtenerPanelCritico(PanelSolar paneles[], int cantidad);
void aplicarMantenimiento(PanelSolar &panel, float porcentajeMejora);
void generarInformeGlobal(PanelSolar paneles[], int cantidad);

int main()
{

    // Declaracion de maximo 10 paneles solares
    PanelSolar paneles[10];
    int n; // Variable para almacenar el numero de paneles

    /*Este do while sirve para validar que el numero de paneles ingresado
    sea entre 1 y 10, si no es asi se le pedira al usuario que ingrese un
    numero valido*/
    do
    {
        std::cout << "Ingrese el numero de paneles (maximo 10): ";
        std::cin >> n;
        if (n < 1 || n > 10)
        {
            std::cout << "El numero de elementos es invalido. Debe ser entre el 1 y 10." << std::endl;
        }
    } while (n < 1 || n > 10);

    // Parte 1: Registrar los paneles solares
    for (int i = 0; i < n; i++) // Este for sirve para recorrer el arreglo de paneles solares y registrar cada uno de ellos
    {
        std::cout << "Panel " << i + 1 << ":" << std::endl;
        registrarPanel(paneles[i]);
    }

    // parte 2: Calcular la eficiencia de cada panel solar
    // parte 3: Determinar el estado operativo de cada panel solar
    for (int i = 0; i < n; i++)
    {
        calcularEficiencia(&paneles[i]);
        determinarEstado(paneles[i]);
    }

    // Parte 4: Obtener el panel solar con la eficiencia mas baja
    PanelSolar *panelCritico = obtenerPanelCritico(paneles, n);
    std::cout << "\nEl panel solar con la eficiencia mas baja es: " << std::endl;
    std::cout << "Codigo: " << panelCritico->codigo << std::endl;
    std::cout << "Ubicacion: " << panelCritico->ubicacion << std::endl;
    std::cout << "Potencia teorica: " << panelCritico->potenciaTeorica << std::endl;
    std::cout << "Lecturas: [" << panelCritico->lecturas[0] << ", " << panelCritico->lecturas[1] << ", " << panelCritico->lecturas[2] << "]" << std::endl;
    std::cout << "Eficiencia: " << panelCritico->eficiencia << "%" << std::endl;
    std::cout << "Estado operativo: " << panelCritico->estadoOperativo << std::endl;

    // Parte 5: Aplicar mantenimiento al panel solar con la eficiencia mas baja
    float porcentajeMejora;
    std::cout << "\n----------------------------------------------------------------------" << std::endl;
    std::cout << "Ingrese el porcentaje de mejora para el mantenimiento del panel solar (%): ";
    std::cin >> porcentajeMejora;
    // Aplicar el mantenimiento al panel solar con la eficiencia más baja
    aplicarMantenimiento(*panelCritico, porcentajeMejora);
    std::cout << "\n----------------------------------------------------------------------" << std::endl;
    std::cout << "Despues del mantenimiento, el panel solar con la eficiencia mas baja es: " << std::endl;
    std::cout << "Codigo: " << panelCritico->codigo << std::endl;
    std::cout << "Ubicacion: " << panelCritico->ubicacion << std::endl;
    std::cout << "Nuevas lecturas: [" << panelCritico->lecturas[0] << ", " << panelCritico->lecturas[1] << ", " << panelCritico->lecturas[2] << "]" << std::endl;
    std::cout << "Nuevas eficiencia: " << panelCritico->eficiencia << "%" << std::endl;
    std::cout << "Estado operativo: " << panelCritico->estadoOperativo << std::endl;

    // Parte 6: Generar un informe global de todos los paneles solares
    generarInformeGlobal(paneles, n);
    return 0;
}

// Registrar los paneles solares
void registrarPanel(PanelSolar &panel)
{
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

// Calcular la eficiencia de cada panel solar
float calcularEficiencia(PanelSolar *panel)
{
    // Calcular el promedio de las lecturas
    float promedioLecturas = (panel->lecturas[0] + panel->lecturas[1] + panel->lecturas[2]) / 3.0f;
    // Calcular la eficiencia del panel solar
    panel->eficiencia = (promedioLecturas / panel->potenciaTeorica) * 100.0;
    return panel->eficiencia; // Retornar la eficiencia calculada
}

// Determinar el estado operativo del panel solar
void determinarEstado(PanelSolar &panel)
{
    if (panel.eficiencia >= 0.0f && panel.eficiencia <= 50.0f)
    {
        panel.estadoOperativo = "DEFICIENTE";
    }
    else if (panel.eficiencia > 50.0f && panel.eficiencia <= 75.0f)
    {
        panel.estadoOperativo = "ACEPTABLE";
    }
    else if (panel.eficiencia > 75.0f && panel.eficiencia <= 100.0f)
    {
        panel.estadoOperativo = "OPTIMO";
    }
    else if (panel.eficiencia > 100.0f)
    {
        panel.estadoOperativo = "ANOMALIA";
    }
}

// Obtener el panel solar con la eficiencia mas baja
PanelSolar *obtenerPanelCritico(PanelSolar paneles[], int cantidad)
{
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

// Aplicar mantenimiento a un panel solar para mejorar su eficiencia
void aplicarMantenimiento(PanelSolar &panel, float porcentajeMejora)
{
    for (int i = 0; i < 3; i++)
    {
        // Formula para mejorar la lectura del panel solar en un porcentaje dado
        panel.lecturas[i] = panel.lecturas[i] * (1.0f + porcentajeMejora / 100.0f);
    }
    // Recalcular la eficiencia después del mantenimiento
    calcularEficiencia(&panel);
    determinarEstado(panel);
}

// Generar un informe global de todos los paneles solares
void generarInformeGlobal(PanelSolar paneles[], int cantidad)
{
    // Contadores para cada estado operativo
    int contadorDeficiente = 0;
    int contadorAceptable = 0;
    int contadorOptimo = 0;
    int contadorAnomalia = 0;

    // Suma de eficiencias para calcular el promedio
    float sumaEficiencias = 0.0f;
    std::cout << "\n----------------------------------------------------------------------" << std::endl;
    std::cout << "Informe Global de Paneles Solares" << std::endl;

    // Recorrer todos los paneles solares para contar los estados y sumar eficiencias
    for (int i = 0; i < cantidad; i++)
    {
        // Calcular el promedio de lecturas
        float promedioLecturas = (paneles[i].lecturas[0] + paneles[i].lecturas[1] + paneles[i].lecturas[2]) / 3.0f;
        std::cout << "Panel [" << i + 1 << "]" << std::endl;
        std::cout << "Codigo: " << paneles[i].codigo << std::endl;
        std::cout << "Ubicacion: " << paneles[i].ubicacion << std::endl;
        std::cout << "Lectura promedio: " << promedioLecturas << " W" << std::endl;
        std::cout << "Eficiencia: " << paneles[i].eficiencia << "%" << std::endl;
        std::cout << "Estado operativo: " << paneles[i].estadoOperativo << std::endl;
        std::cout << "----------------------------------------------------------------------" << std::endl;

        // Contar los estados operativos
        if (paneles[i].estadoOperativo == "DEFICIENTE")
        {
            contadorDeficiente++;
        }
        else if (paneles[i].estadoOperativo == "ACEPTABLE")
        {
            contadorAceptable++;
        }
        else if (paneles[i].estadoOperativo == "OPTIMO")
        {
            contadorOptimo++;
        }
        else if (paneles[i].estadoOperativo == "ANOMALIA")
        {
            contadorAnomalia++;
        }

        // Sumar la eficiencia del panel actual al total de eficiencias
        sumaEficiencias += paneles[i].eficiencia;
    }

    // Calculo final de la media de eficiencia de todos los paneles solares (FUERA DEL FOR)
    float eficienciaGlobalPromedio = sumaEficiencias / cantidad;

    // Mostrar el resumen del informe global (FUERA DEL FOR)
    std::cout << "\n----------------------------------------------------------------------" << std::endl;
    std::cout << "Resumen del Informe Global" << std::endl;
    std::cout << "Cantidad de paneles DEFICIENTE: " << contadorDeficiente << std::endl;
    std::cout << "Cantidad de paneles ACEPTABLE: " << contadorAceptable << std::endl;
    std::cout << "Cantidad de paneles OPTIMO: " << contadorOptimo << std::endl;
    std::cout << "Cantidad de paneles ANOMALIA: " << contadorAnomalia << std::endl;
    std::cout << "Eficiencia global promedio: " << eficienciaGlobalPromedio << "%" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
}
