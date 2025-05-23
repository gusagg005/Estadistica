#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Función para calcular combinatoria y probabilidad binomial
double binomial_pmf(int k, int n, double p) {
    double comb = 1;
    for (int i = 1; i <= k; ++i)
        comb *= (n - i + 1) / static_cast<double>(i);
    return comb * pow(p, k) * pow(1 - p, n - k);
}

int main() {
    int n, y, num_p;
    std::cout << "=== INFERENCIA BAYESIANA BINOMIAL DISCRETA ===\n";

    std::cout << "Ingrese numero total de ensayos (n): ";
    std::cin >> n;

    std::cout << "Ingrese numero de exitos observados (y): ";
    std::cin >> y;

    std::cout << "Ingrese cantidad de valores posibles para p: ";
    std::cin >> num_p;

    std::vector<double> valores_p(num_p);
    std::vector<double> prior(num_p);
    std::vector<double> verosimilitud(num_p);
    std::vector<double> posterior(num_p);

    std::cout << "Ingrese los valores posibles de p:\n";
    for (int i = 0; i < num_p; ++i) {
        std::cout << "p[" << i + 1 << "]: ";
        std::cin >> valores_p[i];
    }

    std::cout << "Ingrese la probabilidad a priori para cada valor de p:\n";
    for (int i = 0; i < num_p; ++i) {
        std::cout << "P(p = " << valores_p[i] << "): ";
        std::cin >> prior[i];
    }

    double evidencia = 0;

    for (int i = 0; i < num_p; ++i) {
        verosimilitud[i] = binomial_pmf(y, n, valores_p[i]);
        evidencia += verosimilitud[i] * prior[i];
    }

    for (int i = 0; i < num_p; ++i) {
        posterior[i] = (verosimilitud[i] * prior[i]) / evidencia;
    }

    // Resultados
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n=== DISTRIBUCIÓN POSTERIOR ===\n";
    for (int i = 0; i < num_p; ++i) {
        std::cout << "P(p = " << valores_p[i] << " | Y = " << y << ") = " << posterior[i] << "\n";
    }

    return 0;
}

