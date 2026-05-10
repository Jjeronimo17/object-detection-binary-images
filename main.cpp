#include <iostream>
#include <iostream>
#include <string>
#include "FunctionBFS.cpp"
using namespace std;
int main() {
        FunctionBFS detector;
        string nombreArchivo;

        cout << "===== DETECCION DE OBJETOS EN IMAGENES =====" << endl;
        cout << "Ingrese el nombre del archivo (ej: imagen.txt): ";
        cin >> nombreArchivo;


        if (!detector.cargarDesdeArchivo(nombreArchivo)) {
            cout << "No se pudo continuar. Saliendo..." << endl;
            return 1;
        }


        detector.imprimirMatriz();

    int objetos = detector.contadorObjetos();
    cout << "Numero de objetos: " << objetos << endl;
    if (detector.tieneBorde() == true) {
        cout << "La imagen SI tiene marco" << endl;
    } else {
        cout << "La imagen NO tiene marco" << endl;
    }

    cout << "\nPresione Enter para salir..." << endl;
    cin.ignore();
    cin.get();
    return 0;

};

