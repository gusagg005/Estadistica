def mostrar_menu():
    opciones = [
        "Mann-Whitney",
        "Wilcoxon",
        "Kruskal-Wallis",
        "Prueba de rachas",
        "Bondad de ajuste Chi cuadrada",
        "Kolmogorov-Smirnov",
        "Chi cuadrada de contingencia",
        "Estadística bayesiana binomial",
        "Estadística bayesiana Poisson",
        "Estadística bayesiana prior normal discreta",
        "Estadística bayesiana prior normal discreta (repetida)",
        "Estadística bayesiana prior normal continua",
        "Intervalos verosímiles",
        "Pruebas de hipótesis en inferencia bayesiana",
        "Análisis de varianza diseño unifactorial",
        "Análisis de varianza diseño en bloques",
        "Análisis de varianza diseño 2^k factores",
        "Modelo de regresión lineal"
    ]

    print("\n=== MENÚ DE MÉTODOS ESTADÍSTICOS ===")
    for i, opcion in enumerate(opciones, start=1):
        print(f"{i}. {opcion}")
    
    while True:
        entrada = input("\nSeleccione una opción por número (1-18): ")
        if entrada.isdigit():
            seleccion = int(entrada)
            if 1 <= seleccion <= len(opciones):
                print(f"\nSeleccionaste: {opciones[seleccion - 1]}")
                return seleccion
            else:
                print("Número fuera del rango. Intente de nuevo.")
        else:
            print("Entrada no válida. Solo se aceptan números. Intente de nuevo.")

def main():
    while True:
        seleccion = mostrar_menu()

        if seleccion == 1:
            from mann_whitney import prueba_mann_whitney
            prueba_mann_whitney()

        elif seleccion == 2:
            from wilcoxon import prueba_wilcoxon
            prueba_wilcoxon()

        elif seleccion == 3:
            from kruskal_wallis import prueba_kruskal_wallis
            prueba_kruskal_wallis()

        elif seleccion == 4:
            from prueba_rachas import prueba_de_rachas
            prueba_de_rachas()

        elif seleccion == 5:
            from bondad_chi_cuadrada import bondad_chi_cuadrada
            bondad_chi_cuadrada()
        
        elif seleccion == 6:
            from kolmogorov_smirnov import prueba_kolmogorov_smirnov
            prueba_kolmogorov_smirnov()
        
        elif seleccion == 7:
            from chi_contingencia import chi_cuadrada_contingencia
            chi_cuadrada_contingencia()

        elif seleccion == 8:
            from bayesiana_binomial import bayesiana_binomial
            bayesiana_binomial()
        
        elif seleccion == 9:
            from bayesiana_poisson import bayesiana_poisson
            bayesiana_poisson()

        elif seleccion == 10:
            from bayesiana_normal_discreta import bayesiana_normal_discreta
            bayesiana_normal_discreta()
        
        elif seleccion == 11:
            from bayesiana_prior_normal_discreta_repetida import bayesiana_prior_normal_discreta_repetida
            bayesiana_prior_normal_discreta_repetida()
        
        elif seleccion == 12:
            from bayesiana_prior_normal_continua import bayesiana_prior_normal_continua
            bayesiana_prior_normal_continua()
        
        elif seleccion == 13:
            from intervalos_verosimiles import intervalos_verosimiles
            intervalos_verosimiles()
        
        elif seleccion == 14:
            from pruebas_hipotesis_bayesiana import pruebas_hipotesis_bayesiana
            pruebas_hipotesis_bayesiana()
        
        elif seleccion == 15:
            from anova_unifactorial import anova_unifactorial
            anova_unifactorial()
        
        elif seleccion == 16:
            from anova_bloques import anova_bloques
            anova_bloques()
        
        elif seleccion == 17:
            from anova_2k_factores import anova_2k_factores
            anova_2k_factores()
        
        elif seleccion == 18:
            from regresion_lineal import regresion_lineal
            regresion_lineal()

        continuar = input("\n¿Deseas realizar otra prueba? (s/n): ").strip().lower()
        if continuar != 's':
            print("\nGracias por usar el sistema. ¡Hasta luego!")
            break

if __name__ == "__main__":
    main()