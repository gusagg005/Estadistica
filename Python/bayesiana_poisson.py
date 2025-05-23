def bayesiana_poisson():
    print("\n=== Estadística Bayesiana: Poisson ===")
    try:
        suma_datos = int(input("Ingrese la suma total de eventos observados: "))
        n = int(input("Ingrese el número de observaciones: "))
        alpha_prior = float(input("Ingrese el α de la prior Gamma: "))
        beta_prior = float(input("Ingrese el β de la prior Gamma: "))

        alpha_post = alpha_prior + suma_datos
        beta_post = beta_prior + n

        print(f"\nDistribución posterior: Gamma({alpha_post}, {beta_post})")
        media = alpha_post / beta_post
        print(f"Media posterior: {media:.4f}")
    except Exception as e:
        print(f"Error: {e}")

bayesiana_poisson()