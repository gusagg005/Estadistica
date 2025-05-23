from scipy.stats import f_oneway

def anova_unifactorial():
    print("\n=== ANOVA Unifactorial ===")
    try:
        grupos = []
        while True:
            datos = input("Ingrese los datos de un grupo separados por comas (o ENTER para terminar): ")
            if datos == "":
                break
            grupo = [float(x.strip()) for x in datos.split(",")]
            grupos.append(grupo)

        if len(grupos) < 2:
            print("Se requieren al menos dos grupos para ANOVA.")
            return

        # Mostrar información de los grupos
        print(f"\nNúmero de grupos: {len(grupos)}")
        total_datos = sum(len(g) for g in grupos)
        print(f"Total de observaciones: {total_datos}")

        for i, g in enumerate(grupos, start=1):
            print(f"Grupo {i} ({len(g)} datos) → Media: {sum(g)/len(g):.2f}")

        # Verificar si los grupos tienen diferentes tamaños
        tamaños = [len(g) for g in grupos]
        if len(set(tamaños)) != 1:
            print("Advertencia: Los grupos tienen tamaños diferentes.")

        # ANOVA
        stat, p = f_oneway(*grupos)
        print(f"\nEstadístico F: {stat:.4f}")
        print(f"Valor p: {p:.4f}")
        if p < 0.05:
            print("Conclusión: Hay diferencias significativas entre al menos un par de medias.")
        else:
            print("Conclusión: No hay diferencias significativas.")
    except Exception as e:
        print(f"Error: {e}")

# Ejecutar la función
anova_unifactorial()
