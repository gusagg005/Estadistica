#include <vector>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

void anova_2k_repeticiones() {
    int niveles_A, niveles_B, repeticiones;
    cout << "--- ANOVA de Dos Factores con Repeticiones ---\n";
    cout << "Numero de niveles del Factor A: ";
    cin >> niveles_A;
    cout << "Numero de niveles del Factor B: ";
    cin >> niveles_B;
    cout << "Numero de repeticiones por celda: ";
    cin >> repeticiones;

    // Estructura: datos[a][b][r]
    vector<vector<vector<double>>> datos(niveles_A, vector<vector<double>>(niveles_B, vector<double>(repeticiones)));

    double suma_total = 0.0;
    int total_datos = niveles_A * niveles_B * repeticiones;

    // Captura de datos
    for (int i = 0; i < niveles_A; ++i) {
        for (int j = 0; j < niveles_B; ++j) {
            cout << "Datos para A" << i + 1 << ", B" << j + 1 << ":\n";
            for (int r = 0; r < repeticiones; ++r) {
                cout << "  Repeticion " << r + 1 << ": ";
                cin >> datos[i][j][r];
                suma_total += datos[i][j][r];
            }
        }
    }

    double media_total = suma_total / total_datos;

    // SCT
    double sct = 0.0;
    for (int i = 0; i < niveles_A; ++i)
        for (int j = 0; j < niveles_B; ++j)
            for (int r = 0; r < repeticiones; ++r)
                sct += pow(datos[i][j][r] - media_total, 2);

    // Suma por factor A
    vector<double> sumas_A(niveles_A, 0.0);
    for (int i = 0; i < niveles_A; ++i)
        for (int j = 0; j < niveles_B; ++j)
            for (int r = 0; r < repeticiones; ++r)
                sumas_A[i] += datos[i][j][r];

    double sca = 0.0;
    for (int i = 0; i < niveles_A; ++i) {
        double media_a = sumas_A[i] / (niveles_B * repeticiones);
        sca += niveles_B * repeticiones * pow(media_a - media_total, 2);
    }

    // Suma por factor B
    vector<double> sumas_B(niveles_B, 0.0);
    for (int j = 0; j < niveles_B; ++j)
        for (int i = 0; i < niveles_A; ++i)
            for (int r = 0; r < repeticiones; ++r)
                sumas_B[j] += datos[i][j][r];

    double scb = 0.0;
    for (int j = 0; j < niveles_B; ++j) {
        double media_b = sumas_B[j] / (niveles_A * repeticiones);
        scb += niveles_A * repeticiones * pow(media_b - media_total, 2);
    }

    // Interacción AB
    double scab = 0.0;
    for (int i = 0; i < niveles_A; ++i) {
        for (int j = 0; j < niveles_B; ++j) {
            double suma_ij = 0.0;
            for (int r = 0; r < repeticiones; ++r)
                suma_ij += datos[i][j][r];
            double media_ij = suma_ij / repeticiones;
            double media_a = sumas_A[i] / (niveles_B * repeticiones);
            double media_b = sumas_B[j] / (niveles_A * repeticiones);
            scab += repeticiones * pow(media_ij - media_a - media_b + media_total, 2);
        }
    }

    // Error
    double sce = sct - sca - scb - scab;

    // Grados de libertad
    int gl_total = total_datos - 1;
    int gl_a = niveles_A - 1;
    int gl_b = niveles_B - 1;
    int gl_ab = gl_a * gl_b;
    int gl_e = gl_total - gl_a - gl_b - gl_ab;

    // Cuadrados medios
    double cm_a = sca / gl_a;
    double cm_b = scb / gl_b;
    double cm_ab = scab / gl_ab;
    double cm_e = sce / gl_e;

    // F
    double F_a = cm_a / cm_e;
    double F_b = cm_b / cm_e;
    double F_ab = cm_ab / cm_e;

    // Tabla ANOVA
    cout << fixed << setprecision(4);
    cout << "\n--- TABLA ANOVA ---\n";
    cout << left << setw(15) << "Fuente"
         << setw(12) << "SC"
         << setw(8) << "GL"
         << setw(12) << "CM"
         << "F\n";
    cout << string(50, '-') << '\n';

    cout << left << setw(15) << "Factor A"
         << setw(12) << sca
         << setw(8) << gl_a
         << setw(12) << cm_a
         << F_a << '\n';

    cout << left << setw(15) << "Factor B"
         << setw(12) << scb
         << setw(8) << gl_b
         << setw(12) << cm_b
         << F_b << '\n';

    cout << left << setw(15) << "Interaccion"
         << setw(12) << scab
         << setw(8) << gl_ab
         << setw(12) << cm_ab
         << F_ab << '\n';

    cout << left << setw(15) << "Error"
         << setw(12) << sce
         << setw(8) << gl_e
         << setw(12) << cm_e << '\n';

    cout << left << setw(15) << "Total"
         << setw(12) << sct
         << setw(8) << gl_total << '\n';

    // F críticos
    double Fcrit_a, Fcrit_b, Fcrit_ab;
    cout << "\nIngresa F critica para A (gl1 = " << gl_a << ", gl2 = " << gl_e << "): ";
    cin >> Fcrit_a;
    cout << "Ingresa F critica para B (gl1 = " << gl_b << ", gl2 = " << gl_e << "): ";
    cin >> Fcrit_b;
    cout << "Ingresa F critica para A×B (gl1 = " << gl_ab << ", gl2 = " << gl_e << "): ";
    cin >> Fcrit_ab;

    cout << "\nResultados:\n";
    cout << "Factor A: " << (F_a > Fcrit_a ? "Significativo" : "No significativo") << '\n';
    cout << "Factor B: " << (F_b > Fcrit_b ? "Significativo" : "No significativo") << '\n';
    cout << "Interaccion A×B: " << (F_ab > Fcrit_ab ? "Significativa" : "No significativa") << '\n';
}
int main()
{
	anova_2k_repeticiones();
	return 0;
}
