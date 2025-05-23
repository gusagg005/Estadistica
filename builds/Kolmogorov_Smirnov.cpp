#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double ks_critico(int n, double alpha = 0.05) {
    // Valor crítico de K-S para una muestra (aproximado)
    // Distribución uniforme como referencia
    if (alpha == 0.05)
        return 1.36 / std::sqrt(n);
    else if (alpha == 0.01)
        return 1.63 / std::sqrt(n);
    else {
        std::cerr << "Nivel de significancia no soportado.\n";
        return -1;
    }
}

int main() {
    int n;
    std::cout << "Ingrese el tamaño de la muestra: ";
    std::cin >> n;

    if (n < 1) {
        std::cerr << "Tamaño de muestra invalido.\n";
        return 1;
    }

    std::vector<double> datos(n);
    std::cout << "Ingrese los " << n << " datos (entre 0 y 1 si usa uniforme):\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> datos[i];
    }

    // Ordenamos la muestra
    std::sort(datos.begin(), datos.end());

    // Calcular el estadístico D
    double D = 0.0;
    for (int i = 0; i < n; ++i) {
        double F_emp = (i + 1) / static_cast<double>(n);
        double F_teo = datos[i];  // distribución uniforme [0,1]
        double diff1 = std::fabs(F_emp - F_teo);
        double diff2 = std::fabs(F_teo - i / static_cast<double>(n));
        D = std::max({D, diff1, diff2});
    }

    double D_critico = ks_critico(n);

    std::cout << "\n--- Resultados ---\n";
    std::cout << "Estadistico D: " << D << "\n";
    std::cout << "Valor critico (a = 0.05): " << D_critico << "\n";

    if (D > D_critico) {
        std::cout << "? Se RECHAZA la hipotesis nula (distribucion distinta).\n";
    } else {
        std::cout << "? No se rechaza la hipotesis nula (distribucion compatible).\n";
    }

    return 0;
}

