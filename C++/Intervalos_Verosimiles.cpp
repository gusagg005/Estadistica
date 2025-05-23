#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Función para calcular la Z para el intervalo de confianza
double z_value(double confianza) {
    if (confianza == 0.90) return 1.645;
    if (confianza == 0.95) return 1.96;
    if (confianza == 0.99) return 2.576;
    return 1.96; // default
}

int main() {
    double sigma, x_barra, mu0, min_apriori, max_apriori;
    int n;
    double confianza;

    cout << "=== INFERENCIA BAYESIANA PARA MEDIA NORMAL ===\n";

    // Ingreso de datos generales
    cout << "Ingrese la desviacion estandar conocida (sigma): ";
    cin >> sigma;

    cout << "Ingrese el tamaño de la muestra: ";
    cin >> n;

    cout << "Ingrese la media de la muestra (x¯): ";
    cin >> x_barra;

    cout << "Nivel de confianza (por ejemplo 0.90, 0.95): ";
    cin >> confianza;

    // Ingreso de datos para la priori informativa
    cout << "\n--- DATOS DE LA PRIORI INFORMATIVA  ---\n";
    cout << "Ingrese la media de la distribucion a priori: ";
    cin >> mu0;

    cout << "Ingrese el valor minimo posible: ";
    cin >> min_apriori;

    cout << "Ingrese el valor maximo posible:  ";
    cin >> max_apriori;

    // Cálculo de varianza a priori usando el rango
    double rango = max_apriori - min_apriori;
    double sigma0 = rango / 6.0; // regla empírica ±3s
    double var0 = sigma0 * sigma0;

    // Posterior para la priori informativa
    double var_post_A = 1.0 / (1.0 / var0 + n / (sigma * sigma));
    double mu_post_A = var_post_A * (mu0 / var0 + n * x_barra / (sigma * sigma));

    // Posterior para la a priori plana
    double var_post_B = (sigma * sigma) / n;
    double mu_post_B = x_barra;

    // Intervalos verosímiles
    double z = z_value(confianza);
    double IC_A_low = mu_post_A - z * sqrt(var_post_A);
    double IC_A_high = mu_post_A + z * sqrt(var_post_A);

    double IC_B_low = mu_post_B - z * sqrt(var_post_B);
    double IC_B_high = mu_post_B + z * sqrt(var_post_B);

    // Resultados
    cout << fixed << setprecision(4);
    cout << "\n=== RESULTADOS ===\n";

    cout << "\n---  (priori informativa) ---\n";
    cout << "Media posterior: " << mu_post_A << endl;
    cout << "Varianza posterior: " << var_post_A << endl;
    cout << confianza * 100 << "% Intervalo verosimil: [" << IC_A_low << ", " << IC_A_high << "]\n";

    cout << "\n--- (priori plana) ---\n";
    cout << "Media posterior: " << mu_post_B << endl;
    cout << "Varianza posterior: " << var_post_B << endl;
    cout << confianza * 100 << "% Intervalo verosimil: [" << IC_B_low << ", " << IC_B_high << "]\n";

    return 0;
}
