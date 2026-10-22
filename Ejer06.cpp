#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float nota;
};

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void agregarAlumno(Alumno *&alumnos, int &cantidad) {
    Alumno *nuevo = new Alumno[cantidad + 1];

    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = alumnos[i];
    }

    cout << "Nombre: ";
    getline(cin, nuevo[cantidad].nombre);
    cout << "Edad: ";
    cin >> nuevo[cantidad].edad;
    cout << "Nota: ";
    cin >> nuevo[cantidad].nota;
    limpiarEntrada();

    delete[] alumnos;
    alumnos = nuevo;
    cantidad++;

    cout << "\nAlumno agregado correctamente.\n";
}

void mostrarAlumnos(Alumno *alumnos, int cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << "\nLISTA DE ALUMNOS\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "\nAlumno " << i + 1 << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Edad: " << alumnos[i].edad << endl;
        cout << "Nota: " << alumnos[i].nota << endl;
    }
}

void buscarAlumno(Alumno *alumnos, int cantidad) {
    string nombreBuscado;
    bool encontrado = false;

    cout << "Ingrese nombre a buscar: ";
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].nombre == nombreBuscado) {
            cout << "\nAlumno encontrado:\n";
            cout << "Nombre: " << alumnos[i].nombre << endl;
            cout << "Edad: " << alumnos[i].edad << endl;
            cout << "Nota: " << alumnos[i].nota << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontro el alumno.\n";
    }
}

int main() {
    Alumno *alumnos = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Agregar alumno\n";
        cout << "2. Mostrar alumnos\n";
        cout << "3. Buscar alumno\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        limpiarEntrada();

        switch (opcion) {
            case 1:
                agregarAlumno(alumnos, cantidad);
                break;
            case 2:
                mostrarAlumnos(alumnos, cantidad);
                break;
            case 3:
                buscarAlumno(alumnos, cantidad);
                break;
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
                break;
        }

    } while (opcion != 4);

    delete[] alumnos;
    return 0;
}