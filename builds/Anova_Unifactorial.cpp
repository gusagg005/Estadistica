#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void anova_unifactorial() {
    int grupos, n_por_grupo;

    cout << "Ingresa el numero de grupos: ";
    cin >> grupos;

    cout << "Ingresa el numero de observaciones por grupo: ";
    cin >> n_por_grupo;

    int total_obs = grupos * n_por_grupo;

    vector<vector<double>> datos(grupos, vector<double>(n_por_grupo));
    double suma_total = 0.0;
    vector<double> sumas_grupo(grupos, 0.0);

    cout << "\nIngresa los datos para cada grupo:\n";
    for (int i = 0; i < grupos; ++i) {
        cout << "Grupo " << (i + 1) << ":\n";
        for (int j = 0; j < n_por_grupo; ++j) {
            cout << "  Observacion " << (j + 1) << ": ";
            cin >> datos[i][j];
            suma_total += datos[i][j];
            sumas_grupo[i] += datos[i][j];
        }
    }

    double media_total = suma_total / total_obs;

    double sctr = 0.0;
    for (int i = 0; i < grupos; ++i) {
        sctr += pow(sumas_grupo[i], 2) / n_por_grupo;
    }
    sctr -= pow(suma_total, 2) / total_obs;

    double sct = 0.0;
    for (int i = 0; i < grupos; ++i) {
        for (int j = 0; j < n_por_grupo; ++j) {
            sct += pow(datos[i][j], 2);
        }
    }
    sct -= pow(suma_total, 2) / total_obs;

    double sce = sct - sctr;

    int gl_total = total_obs - 1;
    int gl_tratamiento = grupos - 1;
    int gl_error = total_obs - grupos;

    double cm_tratamiento = sctr / gl_tratamiento;
    double cm_error = sce / gl_error;

    double F = cm_tratamiento / cm_error;

    cout << fixed << setprecision(4);
    cout << "\n--- TABLA ANOVA ---\n";
    cout << left << setw(20) << "Fuente"
         << setw(15) << "SC"
         << setw(10) << "GL"
         << setw(15) << "CM"
         << "F\n";
    cout << string(60, '-') << '\n';

    cout << left << setw(20) << "Tratamientos"
         << setw(15) << sctr
         << setw(10) << gl_tratamiento
         << setw(15) << cm_tratamiento
         << F << '\n';

    cout << left << setw(20) << "Error"
         << setw(15) << sce
         << setw(10) << gl_error
         << setw(15) << cm_error << '\n';

    cout << left << setw(20) << "Total"
         << setw(15) << sct
         << setw(10) << gl_total << '\n';

    cout << "\nValor de F calculado: " << F << endl;

    double F_critico;
    cout << "Ingresa el valor critico F para gl1 = " << gl_tratamiento
         << " y gl2 = " << gl_error << " con el nivel de confianza deseado: ";
    cin >> F_critico;

    if (F > F_critico) {
        cout << "Como F calculado > F critico (" << F_critico << "), rechazamos H0.\n";
        cout << "Hay evidencia significativa de diferencias entre grupos.\n";
    } else {
        cout << "Como F calculado <= F critico (" << F_critico << "), no rechazamos H0.\n";
        cout << "No hay evidencia suficiente de diferencias entre grupos.\n";
    }
}
int main() {
    anova_unifactorial();
    return 0;
}
