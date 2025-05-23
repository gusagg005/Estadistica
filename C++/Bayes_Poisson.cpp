#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Función de masa de probabilidad de Poisson
double poisson_pmf(int y, double lambda) {
    return pow(lambda, y) * exp(-lambda) / tgamma(y + 1);
}

int main() {
    int n;
    cout << "¿Cuantos valores posibles de lambda vas a ingresar?: ";
    cin >> n;

    vector<double> lambdas(n);
    vector<double> priors(n);
    double total_prior = 0;

    cout << "\n--- Ingreso de valores ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Lambda[" << i+1 << "]: ";
        cin >> lambdas[i];
    }

    cout << "\n--- Ingreso de probabilidades a priori ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Prior para lambda = " << lambdas[i] << ": ";
        cin >> priors[i];
        total_prior += priors[i];
    }

    // Verificación: normalizar si no suman 1
    if (abs(total_prior - 1.0) > 1e-6) {
        cout << "\n?? Las probabilidades a priori no suman 1. Se normalizaran automáticamente.\n";
        for (int i = 0; i < n; i++) {
            priors[i] /= total_prior;
        }
    }

    int y;
    cout << "\nIngrese el valor observado de Y: ";
    cin >> y;

    vector<double> likelihoods(n);
    vector<double> posterior_no_normalized(n);
    double suma_posterior = 0;

    // Calcular verosimilitud y posterior no normalizada
    for (int i = 0; i < n; i++) {
        double p_y_dado_lambda = poisson_pmf(y, lambdas[i]);
        likelihoods[i] = p_y_dado_lambda;
        posterior_no_normalized[i] = p_y_dado_lambda * priors[i];
        suma_posterior += posterior_no_normalized[i];
    }

    // Mostrar resultados
    cout << fixed << setprecision(5);
    cout << "\n=== Distribución Posterior para Y = " << y << " ===\n";
    cout << "?\tPrior\t\tVerosim.\tPosterior\n";
    for (int i = 0; i < n; i++) {
        double posterior_normalizada = posterior_no_normalized[i] / suma_posterior;
        cout << lambdas[i] << "\t" << priors[i] << "\t" << likelihoods[i] << "\t" << posterior_normalizada << endl;
    }

    return 0;
}
