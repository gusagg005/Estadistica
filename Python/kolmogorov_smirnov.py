from scipy.stats import kstest

def prueba_kolmogorov_smirnov():
    print("\n=== Prueba de Kolmogorov-Smirnov (normal) ===")
    try:
        datos = input("Ingrese los datos separados por comas: ")
        data = [float(x.strip()) for x in datos.split(",")]

        estadistico, p_valor = kstest(data, 'norm')

        print(f"\nEstadístico KS: {estadistico}")
        print(f"Valor p: {p_valor}")
        if p_valor < 0.05:
            print("Conclusión: Los datos NO siguen una distribución normal.")
        else:
            print("Conclusión: No se rechaza que los datos provienen de una distribución normal.")
    except Exception as e:
        print(f"Error: {e}")

prueba_kolmogorov_smirnov()