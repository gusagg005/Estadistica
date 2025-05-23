#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct RankedValue {
    double value;
    int group;
    double rank;
};

void asignarRangos(std::vector<RankedValue>& datos) {
    std::sort(datos.begin(), datos.end(), [](const RankedValue& a, const RankedValue& b) {
        return a.value < b.value;
    });

    int n = datos.size();
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && datos[j].value == datos[i].value) ++j;

        double promedioRango = (i + 1 + j) / 2.0;
        for (int k = i; k < j; ++k)
            datos[k].rank = promedioRango;

        i = j;
    }
}

double calcularU(const std::vector<RankedValue>& datos, int grupo) {
    double sumaRangos = 0;
    int n = 0;
    for (const auto& d : datos) {
        if (d.group == grupo) {
            sumaRangos += d.rank;
            ++n;
        }
    }
    return sumaRangos - (n * (n + 1)) / 2.0;
}

int main() {
    int n1, n2;
    std::vector<double> muestra1, muestra2;

    std::cout << "Ingrese la cantidad de elementos de la muestra 1: ";
    std::cin >> n1;
    muestra1.resize(n1);
    std::cout << "Ingrese los valores de la muestra 1:\n";
    for (int i = 0; i < n1; ++i) std::cin >> muestra1[i];

    std::cout << "Ingrese la cantidad de elementos de la muestra 2: ";
    std::cin >> n2;
    muestra2.resize(n2);
    std::cout << "Ingrese los valores de la muestra 2:\n";
    for (int i = 0; i < n2; ++i) std::cin >> muestra2[i];

    std::vector<RankedValue> datos;
    for (double v : muestra1) datos.push_back({v, 1, 0});
    for (double v : muestra2) datos.push_back({v, 2, 0});

    asignarRangos(datos);

    double U1 = calcularU(datos, 1);
    double U2 = calcularU(datos, 2);
    double U = std::min(U1, U2);

    double mu_U = n1 * n2 / 2.0;
    double sigma_U = std::sqrt(n1 * n2 * (n1 + n2 + 1) / 12.0);
    double Z = (U - mu_U) / sigma_U;

    std::cout << "\n--- Resultados ---\n";
    std::cout << "U1 = " << U1 << ", U2 = " << U2 << "\n";
    std::cout << "U = " << U << " (menor de los dos)\n";
    std::cout << "Media U = " << mu_U << ", Desv. estandar = " << sigma_U << "\n";
    std::cout << "Z = " << Z << "\n";

    const double Z_critico = 1.96;
    if (std::abs(Z) > Z_critico) {
        std::cout << "Resultado: Se RECHAZA la hipotesis nula (diferencia significativa).\n";
    } else {
        std::cout << "Resultado: NO se rechaza la hipotesis nula (no hay diferencia significativa).\n";
    }

    return 0;
}

