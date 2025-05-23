#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Función de verosimilitud conjunta para una media mu
double likelihood(const vector<double>& datos, double mu, double sigma) {
    double suma = 0;
    for (double x : datos) {
        suma += pow(x - mu, 2);
    }
    return exp(-suma / (2 * sigma * sigma));
}

int main() {
    int n_muestra;
    cout << "Ingrese el numero de datos observados: ";
    cin >> n_muestra;

    vector<double> datos(n_muestra);
    cout << "Ingrese los datos observados:\n";
    for (int i = 0; i < n_muestra; i++) {
        cin >> datos[i];
    }

    int n_priors;
    cout << "\nIngrese cuantos valores posibles de media (mu) desea usar en el prior: ";
    cin >> n_priors;

    vector<double> mus(n_priors);
    vector<double> priors(n_priors);
    double prior_uniforme = 1.0 / n_priors;

    cout << "Ingrese los valores posibles de mu:\n";
    for (int i = 0; i < n_priors; i++) {
        cin >> mus[i];
        priors[i] = prior_uniforme; // Prior uniforme
    }

    double sigma;
    cout << "\nIngrese la desviación estandar conocida: ";
    cin >> sigma;

    vector<double> posterior_no_normalized(n_priors);
    double suma_posterior = 0;

    // Calcular verosimilitud y posterior no normalizada
    for (int i = 0; i < n_priors; i++) {
        double like = likelihood(datos, mus[i], sigma);
        posterior_no_normalized[i] = like * priors[i];
        suma_posterior += posterior_no_normalized[i];
    }

    // Mostrar resultados
    cout << fixed << setprecision(6);
    cout << "\n=== Distribución Posterior ===\n";
    cout << "Mu\tPrior\tPosterior\n";
    for (int i = 0; i < n_priors; i++) {
        double posterior = posterior_no_normalized[i] / suma_posterior;
        cout << mus[i] << "\t" << priors[i] << "\t" << posterior << endl;
    }

    return 0;
}
