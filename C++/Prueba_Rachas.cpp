#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>

// Mapa de pares (n1,n2) a pares (R_min, R_max)
std::map<std::pair<int,int>, std::pair<int,int>> tabla_criticos = {
    {{5,5}, {2,10}},
    {{6,6}, {3,11}},
    {{7,7}, {3,14}},
    {{8,8}, {4,16}},
    {{9,9}, {4,18}},
    {{10,10}, {5,20}},
    {{11,11}, {7,17}},
    // Agrega más pares según necesites
};

char signo(double x, double mediana) {
    if (x > mediana) return '+';
    else if (x < mediana) return '-';
    else return '0';
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de datos: ";
    std::cin >> n;

    std::vector<double> datos(n);
    std::cout << "Ingrese los datos:\n";
    for (int i = 0; i < n; ++i) std::cin >> datos[i];

    std::vector<double> ordenados = datos;
    std::sort(ordenados.begin(), ordenados.end());
    double mediana = (n % 2 == 0) ? (ordenados[n/2-1] + ordenados[n/2])/2.0 : ordenados[n/2];

    std::vector<char> secuencia;
    for (double val : datos) {
        char s = signo(val, mediana);
        if (s != '0') secuencia.push_back(s);
    }

    int n1 = 0, n2 = 0;
    for (char s : secuencia) {
        if (s == '+') n1++;
        else if (s == '-') n2++;
    }

    int R = 1;
    for (size_t i = 1; i < secuencia.size(); ++i) {
        if (secuencia[i] != secuencia[i-1]) R++;
    }

    std::cout << "\nNumero de rachas: " << R << "\n";
    std::cout << "n1 (+): " << n1 << ", n2 (-): " << n2 << "\n";

    // Buscar tabla crítica
    auto it = tabla_criticos.find({n1,n2});
    if (it == tabla_criticos.end()) {
        std::cout << "No hay valores críticos para n1 = " << n1 << ", n2 = " << n2 << ".\n";
        std::cout << "Por favor use la aproximación normal con Z.\n";
    } else {
        int R_min = it->second.first;
        int R_max = it->second.second;
        std::cout << "Valor critico inferior: " << R_min << "\n";
        std::cout << "Valor critico superior: " << R_max << "\n";

        if (R < R_min || R > R_max) {
            std::cout << "Resultado: Se RECHAZA la hipotesis nula de aleatoriedad.\n";
        } else {
            std::cout << "Resultado: No se rechaza la hipotesis nula.\n";
        }
    }

    return 0;
}

