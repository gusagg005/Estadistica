#include <iostream>
#include <vector>
#include <numeric>  // para std::accumulate
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tama�o de la muestra: ";
    cin >> n;

    vector<double> muestra(n);
    cout << "Ingrese los valores de la muestra:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dato " << i + 1 << ": ";
        cin >> muestra[i];
    }

    double sigma; // desviaci�n est�ndar conocida
    cout << "Ingrese la desviaci�n estandar conocida del proceso (sigma): ";
    cin >> sigma;

    double mu_0, var_0; // media y varianza de la distribuci�n previa
    cout << "Ingrese la media de la distribucion previa: ";
    cin >> mu_0;
    cout << "Ingrese la varianza de la distribucion previa: ";
    cin >> var_0;

    // C�lculo de la media muestral
    double suma = accumulate(muestra.begin(), muestra.end(), 0.0);
    double x_barra = suma / n;

    // C�lculo de la varianza y media posterior
    double var_posterior = 1.0 / (1.0 / var_0 + n / (sigma * sigma));
    double mu_posterior = var_posterior * (mu_0 / var_0 + n * x_barra / (sigma * sigma));

    // Resultados
    cout << "\n--- RESULTADOS ---\n";
    cout << "Media de la muestra (x�): " << x_barra << endl;
    cout << "Media posterior: " << mu_posterior << endl;
    cout << "Varianza posterior: " << var_posterior << endl;

    return 0;
}
