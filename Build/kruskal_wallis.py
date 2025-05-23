from scipy.stats import kruskal

def prueba_kruskal_wallis():
    print("\n=== Prueba de Kruskal-Wallis ===")
    print("Compara tres o más grupos independientes sin asumir normalidad.\n")

    try:
        n = int(input("¿Cuántos grupos desea comparar? (mínimo 3): "))
        if n < 3:
            print("Se necesitan al menos 3 grupos.")
            return

        grupos = []
        for i in range(n):
            datos = input(f"Ingrese los valores del grupo {i+1} separados por comas: ")
            grupo = [float(x.strip()) for x in datos.split(",")]
            grupos.append(grupo)

        estadistico, p_valor = kruskal(*grupos)

        print(f"\nEstadístico H: {estadistico}")
        print(f"Valor p: {p_valor}")

        if p_valor < 0.05:
            print("Conclusión: Hay diferencias significativas entre al menos dos grupos.")
        else:
            print("Conclusión: No hay diferencias significativas entre los grupos.")
    
    except Exception as e:
        print(f"\nError: {e}")

prueba_kruskal_wallis()