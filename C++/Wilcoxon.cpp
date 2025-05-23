#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Diferencia {
    double valor;
    double abs_valor;
    int signo; // 1 positivo, -1 negativo
    double rango;
};

bool compararAbs(const Diferencia& a, const Diferencia& b) {
    return a.abs_valor < b.abs_valor;
}

void asignarRangos(std::vector<Diferencia>& difs) {
    std::sort(difs.begin(), difs.end(), compararAbs);
    int n = difs.size();
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && difs[j].abs_valor == difs[i].abs_valor) ++j;

        double rangoProm = (i + 1 + j) / 2.0;
        for (int k = i; k < j; ++k)
            difs[k].rango = rangoProm;

        i = j;
    }
}

int main() {
    int n;
    std::vector<double> x, y;
    std::vector<Diferencia> diferencias;

    std::cout << "Ingrese el número de pares de datos: ";
    std::cin >> n;
    x.resize(n);
    y.resize(n);

    std::cout << "Ingrese los valores de la primera muestra (X):\n";
    for (int i = 0; i < n; ++i) std::cin >> x[i];

    std::cout << "Ingrese los valores de la segunda muestra (Y):\n";
    for (int i = 0; i < n; ++i) std::cin >> y[i];

    for (int i = 0; i < n; ++i) {
        double d = x[i] - y[i];
        if (d != 0) {
            Diferencia temp;
            temp.valor = d;
            temp.abs_valor = std::fabs(d);
            temp.signo = (d > 0) ? 1 : -1;
            temp.rango = 0;
            diferencias.push_back(temp);
        }
    }

        if (diferencias.empty()) {
        std::cout << "Todos los pares son iguales. No hay diferencias para analizar.\n";
        return 0;
    }


    asignarRangos(diferencias);

    double W_pos = 0, W_neg = 0;
    for (size_t i = 0; i < diferencias.size(); ++i) {
        if (diferencias[i].signo > 0)
            W_pos += diferencias[i].rango;
        else
            W_neg += diferencias[i].rango;
    }

    double T = std::min(W_pos, W_neg);
    int n_efectivo = diferencias.size();

    double mu_T = n_efectivo * (n_efectivo + 1) / 4.0;
    double sigma_T = std::sqrt(n_efectivo * (n_efectivo + 1) * (2 * n_efectivo + 1) / 24.0);
    double Z = (T - mu_T) / sigma_T;

    std::cout << "\n--- Resultados ---\n";
    std::cout << "Suma de rangos positivos (T+): " << W_pos << "\n";
    std::cout << "Suma de rangos negativos (T-): " << W_neg << "\n";
    std::cout << "Estadístico T (mínimo de T+ y T-): " << T << "\n";
    std::cout << "Z = " << Z << "\n";

    const double Z_critico = 1.96;
    if (std::fabs(Z) > Z_critico) {
        std::cout << "Resultado: Se RECHAZA la hipotesis nula (hay diferencia significativa).\n";
    } else {
        std::cout << "Resultado: NO se rechaza la hipotesis nula (no hay diferencia significativa).\n";
    }

    return 0;
}

