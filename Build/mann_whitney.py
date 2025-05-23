from scipy.stats import mannwhitneyu

def prueba_mann_whitney():
    print("\n=== Prueba de Mann-Whitney U ===")
    print("Compara dos grupos independientes sin asumir normalidad.\n")

    try:
        grupo1 = input("Ingrese los valores del grupo 1 separados por comas: ")
        grupo2 = input("Ingrese los valores del grupo 2 separados por comas: ")

        grupo1 = [float(x.strip()) for x in grupo1.split(",") if x.strip()]
        grupo2 = [float(x.strip()) for x in grupo2.split(",") if x.strip()]

        if not grupo1 or not grupo2:
            print("Debe ingresar al menos un valor en cada grupo.")
            return

        estadistico, p_valor = mannwhitneyu(grupo1, grupo2, alternative='two-sided')

        print(f"\nEstadístico U: {estadistico}")
        print(f"Valor p: {p_valor:.4f}")

        if p_valor < 0.05:
            print("Conclusión: Hay evidencia significativa para rechazar la hipótesis nula (los grupos son diferentes).")
        else:
            print("Conclusión: No hay evidencia suficiente para rechazar la hipótesis nula (los grupos no son diferentes).")

    except Exception as e:
        print(f"\nError en la entrada o en el cálculo: {e}")

prueba_mann_whitney()
