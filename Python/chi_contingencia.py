from scipy.stats import chi2_contingency
import numpy as np

def chi_cuadrada_contingencia():
    print("\n=== Prueba Chi-cuadrada de contingencia ===")
    try:
        filas = int(input("Ingrese el número de filas de la tabla: "))
        columnas = int(input("Ingrese el número de columnas de la tabla: "))

        print("Ingrese los valores de la tabla (por fila, separados por comas):")
        tabla = []
        for i in range(filas):
            fila = input(f"Fila {i+1}: ")
            valores = [int(x.strip()) for x in fila.split(",")]
            if len(valores) != columnas:
                print("Error: La cantidad de valores no coincide con el número de columnas.")
                return
            tabla.append(valores)

        tabla_np = np.array(tabla)
        estadistico, p_valor, _, _ = chi2_contingency(tabla_np)

        print(f"\nEstadístico Chi-cuadrada: {estadistico}")
        print(f"Valor p: {p_valor}")
        if p_valor < 0.05:
            print("Conclusión: Hay una asociación significativa entre las variables.")
        else:
            print("Conclusión: No hay evidencia de asociación significativa entre las variables.")
    except Exception as e:
        print(f"Error: {e}")

chi_cuadrada_contingencia()