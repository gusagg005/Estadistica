from scipy.stats import beta

def intervalos_verosimiles():
    print("\n=== Intervalos Verosímiles (Credibilidad) ===")
    try:
        alpha = float(input("Parámetro α de la distribución posterior Beta: "))
        beta_param = float(input("Parámetro β de la distribución posterior Beta: "))
        
        if alpha <= 0 or beta_param <= 0:
            print("Los parámetros α y β deben ser mayores que 0.")
            return

        nivel = float(input("Nivel de credibilidad (por ejemplo 95): ")) / 100

        lower = beta.ppf((1 - nivel) / 2, alpha, beta_param)
        upper = beta.ppf(1 - (1 - nivel) / 2, alpha, beta_param)

        print(f"\nDado Beta({alpha}, {beta_param}), el intervalo creíble del {nivel*100:.0f}% es: [{lower:.4f}, {upper:.4f}]")
    except Exception as e:
        print(f"Error: {e}")

intervalos_verosimiles()
