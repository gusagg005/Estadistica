#include <iostream>
using namespace std;

// Declaraciones de funciones
void Mann_Whitney();
void Wilcoxon();
void Kruskal_Wallis();
void Prueba_Rachas();
void Bondad_ChiCuadrada();
void Kolmogorov_Smirnov();
void Contigencia_ChiCuadrada();
void Bayes_Binomial();
void Bayes_Poisson();
void Bayes_PriorDiscreta();
void Bayes_PriorContinua();
void Intervalos_Verosimiles();
void Inferencia_Bayesiana();
void Anova_Unifactorial();
void Anova_Bloques();
void Anova_2k_factores();
void Regresion_Lineal();

int main() {
    int opcion;
    char continuar;

    do {
        cout << "\n--- MENÚ DE MÉTODOS ---\n";
        cout << "1. Mann-Whitney\n";
        cout << "2. Wilcoxon\n";
        cout << "3. Kruskal-Wallis\n";
        cout << "4. Rachas\n";
        cout << "5. Bondad de Ajuste\n";
        cout << "6. Kolmogorov Smirnov\n";
        cout << "7. Chi Cuadrada Contingencia\n";
        cout << "8. Estadística Bayesiana Binomial\n";
        cout << "9. Estadística Bayesiana Poisson\n";
        cout << "10. Estadística Bayesiana Prior Normal Discreta\n";
        cout << "11. Estadística Bayesiana Prior Normal Continua\n";
        cout << "12. Intervalos Verosímiles\n";
        cout << "13. Prueba de Hipótesis - Inferencia Bayesiana\n";
        cout << "14. ANOVA Unifactorial\n";
        cout << "15. ANOVA por Bloques\n";
        cout << "16. ANOVA 2^k Factores\n";
        cout << "17. Regresión Lineal\n";
        cout << "Selecciona un método (1-17): ";
        cin >> opcion;

        switch (opcion) {
            case 1: Mann_Whitney(); break;
            case 2: Wilcoxon(); break;
            case 3: Kruskal_Wallis(); break;
            case 4: Prueba_Rachas(); break;
            case 5: Bondad_ChiCuadrada(); break;
            case 6: Kolmogorov_Smirnov(); break;
            case 7: Contigencia_ChiCuadrada(); break;
            case 8: Bayes_Binomial(); break;
            case 9: Bayes_Poisson(); break;
            case 10: Bayes_PriorDiscreta(); break;
            case 11: Bayes_PriorContinua(); break;
            case 12: Intervalos_Verosimiles(); break;
            case 13: Inferencia_Bayesiana(); break;
            case 14: Anova_Unifactorial(); break;
            case 15: Anova_Bloques(); break;
            case 16: Anova_2k_factores(); break;
            case 17: Regresion_Lineal(); break;
            default:
                cout << "Opción no válida.\n";
                break;
        }

        cout << "\n¿Deseas usar otro método? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Programa terminado.\n";
    return 0;
}
