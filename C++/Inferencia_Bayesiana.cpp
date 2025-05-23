#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

// Función para calcular la media
double calcularMedia(const vector<double>& datos) {
    double suma = accumulate(datos.begin(), datos.end(), 0.0);
    return suma / datos.size();
}

// CDF de la normal estándar (función error)
double cdfNormal(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

// P-valor para prueba de dos colas
double p_valor_dos_colas(double z) {
    return 2 * (1 - cdfNormal(fabs(z)));
}

// P-valor para prueba cola derecha
double p_valor_cola_derecha(double z) {
    return 1 - cdfNormal(z);
}

int main() {
    cout << fixed << setprecision(5);

    int n;
    cout << "Ingrese el tamaño de la muestra: ";
    cin >> n;

    vector<double> datos(n);
    cout << "Ingrese los valores de la muestra:\n";
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    double sigma;
    cout << "Ingrese la desviacion estandar conocida de la poblacion (sigma): ";
    cin >> sigma;

    double mu0_prior;
    cout << "Ingrese la media del prior (mu0): ";
    cin >> mu0_prior;

    double tau_prior;
    cout << "Ingrese la desviacion estandar del prior (tau): ";
    cin >> tau_prior;

    double media_muestral = calcularMedia(datos);
    double var_poblacion = sigma * sigma;
    double var_prior = tau_prior * tau_prior;

    // Parámetros posterior
    double var_posterior = 1.0 / (n / var_poblacion + 1.0 / var_prior);
    double media_posterior = var_posterior * ((n * media_muestral / var_poblacion) + (mu0_prior / var_prior));
    double sd_posterior = sqrt(var_posterior);

    cout << "\n--- Resultados ---\n";
    cout << "Media muestral: " << media_muestral << "\n";
    cout << "Media posterior: " << media_posterior << "\n";
    cout << "Varianza posterior: " << var_posterior << "\n";
    cout << "Intervalo de credibilidad del 95%: [" 
         << media_posterior - 1.96 * sd_posterior << ", " 
         << media_posterior + 1.96 * sd_posterior << "]\n";

    while (true) {
        cout << "\nSeleccione tipo de prueba de hipotesis:\n";
        cout << "1) Cola derecha (H0: mu <= mu_hipo)\n";
        cout << "2) Dos colas (H0: mu = mu_hipo)\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";
        int opcion;
        cin >> opcion;
        if (opcion == 0) break;

        double mu_hipo;
        cout << "Ingrese el valor de hipotesis para mu: ";
        cin >> mu_hipo;

        double z = (media_posterior - mu_hipo) / sd_posterior;

        if (opcion == 1) {
            // cola derecha
            double p_valor = p_valor_cola_derecha(z);
            cout << "Z para prueba: " << z << "\n";
            cout << "P-valor (cola derecha): " << p_valor << "\n";
            if (p_valor < 0.05)
                cout << "Se rechaza H0: mu <= " << mu_hipo << " al nivel 5%.\n";
            else
                cout << "No se rechaza H0: mu <= " << mu_hipo << " al nivel 5%.\n";
        }
        else if (opcion == 2) {
            // dos colas
            double p_valor = p_valor_dos_colas(z);
            cout << "Z para prueba: " << z << "\n";
            cout << "P-valor (dos colas): " << p_valor << "\n";
            if (p_valor < 0.05)
                cout << "Se rechaza H0: mu = " << mu_hipo << " al nivel 5%.\n";
            else
                cout << "No se rechaza H0: mu = " << mu_hipo << " al nivel 5%.\n";
        }
        else {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    cout << "Programa finalizado.\n";
    return 0;
}

