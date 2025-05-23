#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int k;
    std::cout << "Ingrese el número de categorias: ";
    std::cin >> k;

    std::vector<double> observadas(k);
    std::vector<double> esperadas(k);

    std::cout << "Ingrese las frecuencias OBSERVADAS:\n";
    for (int i = 0; i < k; ++i) {
        std::cout << "O[" << i + 1 << "]: ";
        std::cin >> observadas[i];
    }

    std::cout << "Ingrese las frecuencias ESPERADAS:\n";
    for (int i = 0; i < k; ++i) {
        std::cout << "E[" << i + 1 << "]: ";
        std::cin >> esperadas[i];
    }

    double chi2 = 0.0;
    for (int i = 0; i < k; ++i) {
        if (esperadas[i] == 0) {
            std::cerr << "Error: E[" << i + 1 << "] no puede ser 0.\n";
            return 1;
        }
        double diff = observadas[i] - esperadas[i];
        chi2 += (diff * diff) / esperadas[i];
    }

    int grados_libertad = k - 1;

    std::cout << "\n--- Resultados ---\n";
    std::cout << "Estadistico chi-cuadrado: " << chi2 << "\n";
    std::cout << "Grados de libertad: " << grados_libertad << "\n";

    std::cout << "Compara el resultado con el valor critico en la tabla chi-cuadrada\n";
    std::cout << "por ejemplo para a = 0.05 y gl = " << grados_libertad << "\n";

    return 0;
}

