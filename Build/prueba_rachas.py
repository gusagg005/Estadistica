import numpy as np
from statsmodels.sandbox.stats.runs import runstest_1samp

def prueba_de_rachas():
    print("\n=== Prueba de Rachas ===")
    print("Evalúa la aleatoriedad de una secuencia de datos (por encima y debajo de la mediana).\n")

    try:
        datos = input("Ingrese la secuencia de datos numéricos separados por comas: ")
        datos = [float(x.strip()) for x in datos.split(",")]

        # Se aplica una prueba de rachas alrededor de la mediana
        resultado = runstest_1samp(datos, correction=True)

        z = resultado[0]
        p_valor = resultado[1]

        print(f"\nEstadístico Z: {z}")
        print(f"Valor p: {p_valor}")

        if p_valor < 0.05:
            print("Conclusión: La secuencia no parece aleatoria (se detectan patrones).")
        else:
            print("Conclusión: No hay evidencia para rechazar la aleatoriedad de la secuencia.")

    except Exception as e:
        print(f"\nError: {e}")

prueba_de_rachas()