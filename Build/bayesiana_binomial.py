from scipy.stats import beta

def bayesiana_binomial():
    print("\n=== Estadística Bayesiana: Binomial ===")
    try:
        exitos = int(input("Ingrese el número de éxitos observados: "))
        fracasos = int(input("Ingrese el número de fracasos observados: "))
        alpha_prior = float(input("Ingrese el parámetro α de la prior Beta: "))
        beta_prior = float(input("Ingrese el parámetro β de la prior Beta: "))

        alpha_post = alpha_prior + exitos
        beta_post = beta_prior + fracasos

        print(f"\nDistribución posterior: Beta({alpha_post}, {beta_post})")

        media = alpha_post / (alpha_post + beta_post)
        print(f"Media posterior: {media:.4f}")
    except Exception as e:
        print(f"Error: {e}")

bayesiana_binomial()