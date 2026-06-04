#include <iostream>
#include <vector>

// Usamos el espacio de nombres estándar para evitar escribir std:: en cada línea
using namespace std;

// Función para determinar si un número es primo
// Devuelve true si es primo, de lo contrario devuelve false
bool esPrimo(int numero) {
    // Los números menores o iguales a 1 no son primos
    if (numero <= 1) return false;

    // Evaluamos si el número tiene algún divisor desde 2 hasta la raíz cuadrada del número.
    // Optimización: si i * i > numero, no es necesario seguir buscando.
    for (int i = 2; i * i <= numero; i++) {
        // Si el residuo es cero, significa que encontramos un divisor, por lo tanto no es primo
        if (numero % i == 0) {
            return false;
        }
    }
    // Si no se encontró ningún divisor, el número es primo
    return true;
}

int main() {
    int N;

    // Segmento: Interacción con el usuario
    // Solicitamos al usuario la cantidad de números primos que desea generar
    cout << "Ingrese la cantidad de números primos que desea generar (N): ";
    cin >> N;

    // Validación básica para asegurarse de que el usuario ingrese un entero positivo
    if (N <= 0) {
        cout << "Por favor, ingrese un número entero positivo mayor que cero." << endl;
        return 1; // Terminamos el programa con un código de error
    }

    // Segmento: Inicialización del contenedor (Array dinámico)
    // Usamos un vector de tipo entero para almacenar los N números primos de forma dinámica
    vector<int> primos;

    // Variables de control para el ciclo de búsqueda
    int candidato = 2; // Empezamos a evaluar desde el primer número primo, que es el 2

    // Segmento: Generación de números primos
    // El ciclo continuará ejecutándose hasta que hayamos encontrado exactamente N números primos
    while (primos.size() < N) {
        // Llamamos a la función esPrimo para verificar el número candidato actual
        if (esPrimo(candidato)) {
            // Si es primo, lo agregamos al final de nuestro arreglo (vector)
            primos.push_back(candidato);
        }
        // Incrementamos el candidato para evaluar el siguiente número en la próxima iteración
        candidato++;
    }

    // Segmento: Despliegue de resultados
    // Imprimimos la lista de los números primos almacenados en el arreglo
    cout << "\nLos primeros " << N << " números primos son:" << endl;
    for (int i = 0; i < primos.size(); i++) {
        cout << primos[i] << " ";
    }
    cout << endl; // Salto de línea final

    return 0; // Indicamos que el programa finalizó correctamente
}