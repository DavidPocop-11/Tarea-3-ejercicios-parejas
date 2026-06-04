#include <iostream>  // Incluye la librería estándar de entrada y salida (para usar std::cout y std::cin)
#include <vector>    // Incluye la librería de vectores para manejar arreglos dinámicos (que cambian de tamaño)
#include <limits>    // Incluye funciones para manejar los límites de los tipos de datos (usado al limpiar el buffer)

int main() {  // Define la función principal donde inicia la ejecución de todo programa en C++

    // Configura la consola para intentar reconocer caracteres locales (como tildes o la ñ)
    std::locale::global(std::locale(""));

    int n;  // Declara una variable entera para almacenar la cantidad total de estudiantes
    // Imprime en pantalla el encabezado del programa
    std::cout << "=== Sistema de Gestión de Calificaciones ===" << std::endl;
    // Imprime una instrucción solicitando al usuario que ingrese el número de alumnos
    std::cout << "Ingrese la cantidad de estudiantes: ";

    // Ciclo "while" que valida la entrada: se repite si el usuario ingresa texto en vez de un número, o si el número es menor o igual a cero
    while (!(std::cin >> n) || n <= 0) {
        // Advierte al usuario del error y solicita un número correcto
        std::cout << "Por favor, ingrese un número entero válido y mayor que 0: ";
        std::cin.clear();  // Limpia el estado de error del flujo de entrada de datos (std::cin)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descarta los caracteres incorrectos que quedaron atrapados en el buffer
    }  // Fin del ciclo de validación de N

    // Crea un vector (arreglo dinámico) de números decimales llamado "calificaciones" con un tamaño de "n" elementos
    std::vector<double> calificaciones(n);
    double suma = 0.0;     // Declara e inicializa una variable decimal para acumular la suma de todas las notas
    int aprobados = 0;     // Declara e inicializa un contador entero para los alumnos con nota igual o mayor a 60
    int reprobados = 0;    // Declara e inicializa un contador entero para los alumnos con nota menor a 60

    // Ciclo "for" que se repetirá desde 0 hasta N-1 para solicitar la nota de cada estudiante
    for (int i = 0; i < n; i++) {
        // Muestra en pantalla el mensaje pidiendo la nota del estudiante actual (i + 1 es para que se lea "estudiante 1", "estudiante 2", etc.)
        std::cout << "Ingrese la calificación del estudiante " << i + 1 << " (0-100): ";

        // Ciclo "while" que valida la nota: se repite si no es un número o si está fuera del rango de 0 a 100
        while (!(std::cin >> calificaciones[i]) || calificaciones[i] < 0 || calificaciones[i] > 100) {
            // Muestra un mensaje informando que el rango ingresado no es válido
            std::cout << "Nota inválida. Ingrese una calificación entre 0 y 100: ";
            std::cin.clear();  // Limpia el estado de error de la entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vacía el buffer de la consola
        }  // Fin de la validación de la nota individual

        suma += calificaciones[i];  // Suma de forma acumulativa la nota ingresada a la variable "suma"

        // Estructura condicional para evaluar el estatus del alumno
        if (calificaciones[i] >= 60.0) {  // Si la nota del estudiante es mayor o igual a 60...
            aprobados++;  // Incrementa en 1 el contador de estudiantes aprobados
        }
        else {  // De lo contrario (si la nota es menor a 60)...
            reprobados++;  // Incrementa en 1 el contador de estudiantes reprobados
        }  // Fin de la estructura condicional de conteo
    }  // Fin del ciclo "for" de lectura de datos

    // Inicializa la variable de la nota máxima tomando como referencia la primera calificación del vector (posición 0)
    double nota_maxima = calificaciones[0];
    // Inicializa la variable de la nota mínima tomando también como referencia la primera calificación del vector
    double nota_minima = calificaciones[0];

    // Ciclo "for" que recorre el vector desde la posición 1 en adelante para buscar los extremos
    for (int i = 1; i < n; i++) {
        if (calificaciones[i] > nota_maxima) {  // Si la nota actual es mayor que la nota máxima registrada hasta ahora...
            nota_maxima = calificaciones[i];    // Actualiza la variable "nota_maxima" con este nuevo valor más alto
        }  // Fin de la condición para el máximo

        if (calificaciones[i] < nota_minima) {  // Si la nota actual es menor que la nota mínima registrada hasta ahora...
            nota_minima = calificaciones[i];    // Actualiza la variable "nota_minima" con este nuevo valor más bajo
        }  // Fin de la condición para el mínimo
    }  // Fin del ciclo "for" de búsqueda de extremos

    // Calcula el promedio dividiendo el acumulado de la suma entre la cantidad total "n" de estudiantes
    double promedio = suma / n;

    // Bloque de salida: Imprime una línea estética de separación en la consola
    std::cout << "\n================ REPORTE ================" << std::endl;
    // Imprime la nota más alta encontrada en el grupo
    std::cout << "Calificación más alta: " << nota_maxima << std::endl;
    // Imprime la nota más baja encontrada en el grupo
    std::cout << "Calificación más baja: " << nota_minima << std::endl;
    // Imprime el resultado del promedio general calculado
    std::cout << "Promedio del grupo:    " << promedio << std::endl;
    // Imprime el total de alumnos que lograron aprobar
    std::cout << "Estudiantes aprobados: " << aprobados << std::endl;
    // Imprime el total de alumnos que no alcanzaron la nota mínima
    std::cout << "Estudiantes reprobados: " << reprobados << std::endl;
    // Imprime la línea de cierre del reporte en consola
    std::cout << "=========================================" << std::endl;

    return 0;  // Retorna cero al sistema operativo, indicando que el programa finalizó correctamente sin errores
}  // Cierre definitivo de la función principal main








