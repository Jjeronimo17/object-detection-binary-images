//
// Created by USUARIO on 10/05/2026.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class FunctionBFS {

    int M;
    int N;
    vector<vector<int>> matriz;
    vector<vector<bool>> visitado;



public:

    FunctionBFS() {
        M = 0;
        N = 0;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool cargarDesdeArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "Error: no se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
            return false;
        }

        matriz.clear();
        string linea;


        while (getline(archivo, linea)) {
            vector<int> filaActual;

            for (char c : linea) {
                if (c == '0' || c == '1') {
                    filaActual.push_back(c - '0');
                }
            }


            if (!filaActual.empty()) {
                matriz.push_back(filaActual);
            }
        }

        archivo.close();


        M = matriz.size();
        N = (M > 0) ? matriz[0].size() : 0;


        if (M == 0 || N == 0) {
            cout << "Error: el archivo esta vacio o tiene formato invalido" << endl;
            return false;
        }


        visitado.assign(M, vector<bool>(N, false));

        cout << "Archivo cargado correctamente. Dimensiones: " << M << "x" << N << endl;
        return true;
    }

    void imprimirMatriz() {
        cout << "\nMatriz cargada:" << endl;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void BFS(int filaInicial, int colInicial) {
        queue<pair<int, int>> cola;
        cola.push({filaInicial, colInicial});
        visitado[filaInicial][colInicial] = true;

        while (!cola.empty()) {
            pair<int, int> actual = cola.front();
            cola.pop();
            int x = actual.first;
            int y = actual.second;

            for (int i = 0; i < 4; i++) {
                int nuevoX = x + dx[i];
                int nuevoY = y + dy[i];

                if (nuevoX >= 0 && nuevoX < M && nuevoY >= 0 && nuevoY < N) {
                    if (matriz[nuevoX][nuevoY] == 1 && !visitado[nuevoX][nuevoY]) {
                        visitado[nuevoX][nuevoY] = true;
                        cola.push({nuevoX, nuevoY});
                    }
                }
            }
        }
    }

    int contadorObjetos() {
        int contador = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matriz[i][j] == 1 && !visitado[i][j]) {
                    BFS(i, j);
                    contador++;
                }
            }
        }
        return contador;
    }

    bool bordeSuperior () {
        for (int i = 0; i < N; i++) {
            if (matriz[0][i] == 1) {
                return false;
            }
        }
        return true;
    }
    bool bordeLateralIzquierdo() {
        for (int i = 0; i < M; i++) {
            if (matriz[i][0] == 1) {
                return false;
            }
        }
        return true;
    }
    bool bordeLateralDerecho() {
        for (int i = 0; i < M; i++) {
            if (matriz[i][N - 1] == 1) {
                return false;
            }
        }
        return true;
    }
    bool bordeInferior () {
        for (int i = 0; i < N; i++) {
            if (matriz[M - 1][i] == 1) {
                return false;
            }
        }
        return true;
    }
    bool tieneBorde() {
        if (bordeSuperior() + bordeLateralIzquierdo() + bordeInferior() + bordeLateralDerecho() == 4) {
            return true;
        } else {
            return false;
        }
    }



};
