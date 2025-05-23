from scipy.stats import wilcoxon

def prueba_wilcoxon():
    print("\n=== Prueba de Wilcoxon ===")
    print("Compara dos muestras relacionadas (emparejadas), sin asumir normalidad.\n")

    try:
        grupo1 = input("Ingrese los valores del primer grupo (antes), separados por comas: ")
        grupo2 = input("Ingrese los valores del segundo grupo (después), separados por comas: ")

        # Convertir a listas de números
        grupo1 = [float(x.strip()) for x in grupo1.split(",")]
        grupo2 = [float(x.strip()) for x in grupo2.split(",")]

        if len(grupo1) != len(grupo2):
            print("\nError: Las dos muestras deben tener la misma longitud.")
            return

        # Ejecutar la prueba de Wilcoxon
        estadistico, p_valor = wilcoxon(grupo1, grupo2)

        # Mostrar resultados
        print(f"\nEstadístico W: {estadistico}")
        print(f"Valor p: {p_valor}")

        if p_valor < 0.05:
            print("Conclusión: Hay evidencia significativa para rechazar la hipótesis nula (hay diferencia entre los grupos).")
        else:
            print("Conclusión: No hay evidencia suficiente para rechazar la hipótesis nula (no hay diferencia entre los grupos).")

    except Exception as e:
        print(f"\nError en la entrada o en el cálculo: {e}")

prueba_wilcoxon()