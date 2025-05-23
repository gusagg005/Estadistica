#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void anova_bloques() {
    int tratamientos, bloques;

    cout << "Ingresa el numero de tratamientos: ";
    cin >> tratamientos;
    cout << "Ingresa el numero de bloques: ";
    cin >> bloques;

    vector<vector<double>> datos(tratamientos, vector<double>(bloques));
    vector<double> sumas_tratamientos(tratamientos, 0.0);
    vector<double> sumas_bloques(bloques, 0.0);
    double suma_total = 0.0;

    cout << "\nIngresa los datos (filas = tratamientos, columnas = bloques):\n";
    for (int i = 0; i < tratamientos; ++i) {
        for (int j = 0; j < bloques; ++j) {
            cout << "Dato [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> datos[i][j];
            sumas_tratamientos[i] += datos[i][j];
            sumas_bloques[j] += datos[i][j];
            suma_total += datos[i][j];
        }
    }

    int N = tratamientos * bloques;

    // Cálculo de sumas de cuadrados
    double SCT = 0.0; // Suma total de cuadrados
    for (int i = 0; i < tratamientos; ++i) {
        for (int j = 0; j < bloques; ++j) {
            SCT += pow(datos[i][j], 2);
        }
    }
    SCT -= pow(suma_total, 2) / N;

    double SCTratamientos = 0.0;
    for (int i = 0; i < tratamientos; ++i) {
        SCTratamientos += pow(sumas_tratamientos[i], 2) / bloques;
    }
    SCTratamientos -= pow(suma_total, 2) / N;

    double SCBloques = 0.0;
    for (int j = 0; j < bloques; ++j) {
        SCBloques += pow(sumas_bloques[j], 2) / tratamientos;
    }
    SCBloques -= pow(suma_total, 2) / N;

    double SCE = SCT - SCTratamientos - SCBloques; // Suma de cuadrados del error

    // Grados de libertad
    int gl_tratamientos = tratamientos - 1;
    int gl_bloques = bloques - 1;
    int gl_error = (tratamientos - 1) * (bloques - 1);
    int gl_total = N - 1;

    // Cuadrados medios
    double CMtratamientos = SCTratamientos / gl_tratamientos;
    double CMbloques = SCBloques / gl_bloques;
    double CMerror = SCE / gl_error;

    // Estadísticos F
    double Ftratamientos = CMtratamientos / CMerror;
    double Fbloques = CMbloques / CMerror;

    cout << fixed << setprecision(4);
    cout << "\n--- TABLA ANOVA ---\n";
    cout << left << setw(15) << "Fuente"
         << setw(15) << "SC"
         << setw(10) << "GL"
         << setw(15) << "CM"
         << "F\n";
    cout << string(60, '-') << '\n';

    cout << left << setw(15) << "Tratamientos"
         << setw(15) << SCTratamientos
         << setw(10) << gl_tratamientos
         << setw(15) << CMtratamientos
         << Ftratamientos << '\n';

    cout << left << setw(15) << "Bloques"
         << setw(15) << SCBloques
         << setw(10) << gl_bloques
         << setw(15) << CMbloques
         << Fbloques << '\n';

    cout << left << setw(15) << "Error"
         << setw(15) << SCE
         << setw(10) << gl_error
         << setw(15) << CMerror << '\n';

    cout << left << setw(15) << "Total"
         << setw(15) << SCT
         << setw(10) << gl_total << '\n';

    double Fcrit_tratamientos, Fcrit_bloques;
    cout << "\nIngresa el valor critico F para Tratamientos (gl1 = " << gl_tratamientos
         << ", gl2 = " << gl_error << "): ";
    cin >> Fcrit_tratamientos;
    cout << "Ingresa el valor critico F para Bloques (gl1 = " << gl_bloques
         << ", gl2 = " << gl_error << "): ";
    cin >> Fcrit_bloques;

    cout << "\nPrueba para Tratamientos:\n";
    if (Ftratamientos > Fcrit_tratamientos) {
        cout << "F calculado > F critico (" << Fcrit_tratamientos << "), rechazamos H0.\n";
        cout << "Existe diferencia significativa entre los tratamientos.\n";
    } else {
        cout << "F calculado <= F critico (" << Fcrit_tratamientos << "), no rechazamos H0.\n";
        cout << "No hay evidencia suficiente para diferencias entre tratamientos.\n";
    }

    cout << "\nPrueba para Bloques:\n";
    if (Fbloques > Fcrit_bloques) {
        cout << "F calculado > F critico (" << Fcrit_bloques << "), rechazamos H0.\n";
        cout << "Existe efecto significativo de los bloques.\n";
    } else {
        cout << "F calculado <= F critico (" << Fcrit_bloques << "), no rechazamos H0.\n";
        cout << "No hay evidencia suficiente para efecto de los bloques.\n";
    }
}

int main() {
    anova_bloques();
    return 0;
}
