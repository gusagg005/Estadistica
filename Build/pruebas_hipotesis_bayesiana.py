from scipy.stats import beta

def pruebas_hipotesis_bayesiana():
    print("\n=== Pruebas de Hipótesis Bayesiana ===")
    try:
        alpha_post = float(input("Ingrese α de la posterior Beta: "))
        beta_post = float(input("Ingrese β de la posterior Beta: "))
        umbral = float(input("Ingrese el valor umbral para comparar: "))

        prob = 1 - beta.cdf(umbral, alpha_post, beta_post)

        print(f"\nP(θ > {umbral}) = {prob:.4f}")
        if prob > 0.95:
            print("Se acepta la hipótesis alternativa (alta credibilidad).")
        else:
            print("No hay suficiente evidencia para aceptar la alternativa.")
    except Exception as e:
        print(f"Error: {e}")

pruebas_hipotesis_bayesiana()