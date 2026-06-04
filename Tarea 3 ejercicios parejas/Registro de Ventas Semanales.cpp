#include <iostream>
#include <string>

using namespace std;

int main() {
    // Segmento: Configuración de constantes y variables globales del problema
    const int DIAS_SEMANA = 7;
    // Arreglo de strings para mostrar los nombres de los días al usuario
    string dias[DIAS_SEMANA] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo" };
    // Arreglo de tipo double para almacenar las ventas de cada día
    double ventas[DIAS_SEMANA];

    // Segmento: Lectura de datos y llenado del arreglo
    cout << "--- Registro de Ventas Semanales ---" << endl;
    for (int i = 0; i < DIAS_SEMANA; i++) {
        cout << "Ingrese las ventas del día " << dias[i] << ": Q";
        cin >> ventas[i];

        // Validación básica por si se ingresa un valor negativo
        while (ventas[i] < 0) {
            cout << "Las ventas no pueden ser negativas. Intente de nuevo para el " << dias[i] << ": Q";
            cin >> ventas[i];
        }
    }

    // Segmento: Procesamiento de los datos (Cálculos)
    double totalVentas = 0;
    double maxVentas = ventas[0]; // Asumimos inicialmente que el primer día fue el mayor
    int indiceMax = 0;            // Guarda la posición del día con mayores ventas
    bool huboDiaSinVentas = false; // Bandera (flag) para rastrear si alguna venta es igual a 0

    for (int i = 0; i < DIAS_SEMANA; i++) {
        // 1. Acumular el total de las ventas de la semana
        totalVentas += ventas[i];

        // 2. Encontrar el día con la venta máxima
        if (ventas[i] > maxVentas) {
            maxVentas = ventas[i];
            indiceMax = i; // Guardamos el índice actual para saber qué día de la semana fue
        }

        // 3. Verificar si hubo algún día con ventas iguales a cero
        if (ventas[i] == 0) {
            huboDiaSinVentas = true;
        }
    }

    // Segmento: Despliegue de los resultados solicitados
    cout << "\n=======================================" << endl;
    cout << "         RESUMEN DE LA SEMANA          " << endl;
    cout << "=======================================" << endl;

    // 1. Mostrar el total general
    cout << "* El total de ventas de la semana fue de: Q" << totalVentas << endl;

    // 2. Mostrar el día con mayor recaudación usando el índice guardado
    cout << "* El día con mayores ventas fue el " << dias[indiceMax]
        << " con un monto de: Q" << maxVentas << endl;

    // 3. Mostrar el estado de los días sin ventas basándonos en la bandera lógica
    if (huboDiaSinVentas) {
        cout << "* Alerta: Sí hubo al menos un día sin ventas (Q0) en la semana." << endl;
    }
    else {
        cout << "* Nota: Todos los días registraron ventas mayores a cero." << endl;
    }

    return 0;
}