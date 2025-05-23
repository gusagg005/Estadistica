#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct ValorRango {
    double valor;
    int grupo;
    double rango;
};

bool compararValor(const ValorRango& a, const ValorRango& b) {
    return a.valor < b.valor;
}

void asignarRangos(std::vector<ValorRango>& datos) {
    std::sort(datos.begin(), datos.end(), compararValor);
    size_t i = 0;
    while (i < datos.size()) {
        size_t j = i + 1;
        while (j < datos.size() && datos[j].valor == datos[i].valor) ++j;

        double rangoPromedio = (i + 1 + j) / 2.0;
        for (size_t k = i; k < j; ++k)
            datos[k].rango = rangoPromedio;

        i = j;
    }
}

int main() {
    int k;
    std::cout << "Ingrese el numero de grupos: ";
    std::cin >> k;

    std::vector<ValorRango> todosLosDatos;
    std::vector<int> tamanos(k);
    for (int i = 0; i < k; ++i) {
        int n;
        std::cout << "Cantidad de datos del grupo " << (i + 1) << ": ";
        std::cin >> n;
        tamanos[i] = n;
        std::cout << "Ingrese los " << n << " valores del grupo " << (i + 1) << ":\n";
        for (int j = 0; j < n; ++j) {
            double val;
            std::cin >> val;
            todosLosDatos.push_back({val, i, 0});
        }
    }

    int N = todosLosDatos.size();
    asignarRangos(todosLosDatos);

    std::vector<double> sumaRangos(k, 0.0);
    for (const auto& dato : todosLosDatos) {
        sumaRangos[dato.grupo] += dato.rango;
    }

    double H = 0.0;
    for (int i = 0; i < k; ++i) {
        H += (std::pow(sumaRangos[i], 2)) / tamanos[i];
    }
    H = (12.0 / (N * (N + 1))) * H - 3 * (N + 1);

    int gl = k - 1;
    double chi_critico = 5.991; // para k=3, a=0.05; puedes ajustarlo según gl

    std::cout << "\n--- Resultados ---\n";
    std::cout << "Estadistico H de Kruskal-Wallis: " << H << "\n";
    std::cout << "Grados de libertad: " << gl << "\n";
    std::cout << "Valor critico de chi-cuadrado (a=0.05): " << chi_critico << "\n";

    if (H > chi_critico) {
        std::cout << "Resultado: Se RECHAZA la hipotesis nula (al menos un grupo difiere).\n";
    } else {
        std::cout << "Resultado: NO se rechaza la hipotesis nula (no hay diferencia significativa).\n";
    }

    return 0;
}

