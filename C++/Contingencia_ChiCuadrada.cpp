#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Función para calcular el estadístico chi-cuadrada
double calcularChiCuadrada(const vector<vector<int>>& observados, const vector<vector<double>>& esperados, int filas, int columnas) {
    double chi2 = 0.0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            chi2 += pow(observados[i][j] - esperados[i][j], 2) / esperados[i][j];
        }
    }
    return chi2;
}

int main() {
    int filas, columnas;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    // Crear matrices
    vector<vector<int>> observados(filas, vector<int>(columnas));
    vector<vector<double>> esperados(filas, vector<double>(columnas));
    vector<int> totalFilas(filas, 0);
    vector<int> totalColumnas(columnas, 0);
    int totalGeneral = 0;

    // Ingreso de datos observados
    cout << "Ingrese los datos observados:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Valor en fila " << i + 1 << ", columna " << j + 1 << ": ";
            cin >> observados[i][j];
            totalFilas[i] += observados[i][j];
            totalColumnas[j] += observados[i][j];
            totalGeneral += observados[i][j];
        }
    }

    // Cálculo de frecuencias esperadas
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            esperados[i][j] = static_cast<double>(totalFilas[i] * totalColumnas[j]) / totalGeneral;
        }
    }

    // Cálculo del estadístico chi-cuadrada
    double chi2 = calcularChiCuadrada(observados, esperados, filas, columnas);

    // Mostrar resultados
    cout << "\nFrecuencias esperadas:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << esperados[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nEstadistico Chi-cuadrada: " << chi2 << endl;

    // Grados de libertad
    int gl = (filas - 1) * (columnas - 1);
    cout << "Grados de libertad: " << gl << endl;

    return 0;
}
