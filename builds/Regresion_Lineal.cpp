#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void regresion_lineal_simple() {
    int n;
    cout << "--- Regresión Lineal Simple ---\n";
    cout << "¿Cuántos pares de datos (x, y) vas a ingresar? ";
    cin >> n;

    if (n < 2) {
        cout << "Se necesitan al menos dos puntos para realizar regresión.\n";
        return;
    }

    vector<double> x(n), y(n), residuos(n);
    double suma_x = 0, suma_y = 0, suma_x2 = 0, suma_xy = 0;

    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "]: ";
        cin >> x[i];
        cout << "y[" << i + 1 << "]: ";
        cin >> y[i];

        suma_x += x[i];
        suma_y += y[i];
        suma_x2 += x[i] * x[i];
        suma_xy += x[i] * y[i];
    }

    double media_x = suma_x / n;
    double media_y = suma_y / n;

    double b1 = (suma_xy - n * media_x * media_y) / (suma_x2 - n * media_x * media_x);
    double b0 = media_y - b1 * media_x;

    double sct = 0, scr = 0, sce = 0;
    for (int i = 0; i < n; ++i) {
        double yi_est = b0 + b1 * x[i];
        residuos[i] = y[i] - yi_est;

        sct += pow(y[i] - media_y, 2);
        scr += pow(yi_est - media_y, 2);
        sce += pow(residuos[i], 2);
    }

    double r2 = scr / sct;
    double cmr = scr / 1;           // GL regresión = 1
    double cme = sce / (n - 2);     // GL error = n - 2
    double f = cmr / cme;
    double error_est = sqrt(cme);

    // Estadístico Durbin-Watson
    double dw_num = 0, dw_den = 0;
    for (int i = 1; i < n; ++i)
        dw_num += pow(residuos[i] - residuos[i - 1], 2);
    for (int i = 0; i < n; ++i)
        dw_den += pow(residuos[i], 2);
    double durbin_watson = dw_num / dw_den;

    cout << fixed << setprecision(4);
    cout << "\n--- Resultados ---\n";
    cout << "Modelo de regresion: y = " << b0 << " + " << b1 << "*x\n";
    cout << "Coeficiente de determinacion (R^2): " << r2 << '\n';
    cout << "SCT (total): " << sct << '\n';
    cout << "SCR (regresión): " << scr << '\n';
    cout << "SCE (error): " << sce << '\n';
    cout << "Error estandar de estimacion: " << error_est << '\n';
    cout << "Estadistico F: " << f << '\n';
    cout << "Estadistico Durbin-Watson: " << durbin_watson << '\n';

    // Comparación con valor F crítico (opcional)
    char comparar;
    cout << "\n¿Quieres comparar con un valor critico F? (s/n): ";
    cin >> comparar;
    if (comparar == 's' || comparar == 'S') {
        double f_crit;
        cout << "Ingresa el valor F critico (gl1 = 1, gl2 = " << (n - 2) << "): ";
        cin >> f_crit;
        if (f > f_crit)
            cout << "El modelo es significativo (se rechaza H0).\n";
        else
            cout << "El modelo NO es significativo (no se rechaza H0).\n";
    }
}

int main() {
    regresion_lineal_simple();
    return 0;
}

