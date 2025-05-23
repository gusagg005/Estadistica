def bayesiana_normal_discreta():
    print("\n=== Estadística Bayesiana: Prior Normal Discreta ===")
    try:
        x = float(input("Ingrese el dato observado: "))
        media_prior = float(input("Ingrese la media de la prior: "))
        var_prior = float(input("Ingrese la varianza de la prior: "))
        var_lik = float(input("Ingrese la varianza del modelo (verosimilitud): "))

        # Cálculos de la distribución posterior
        var_post = 1 / (1/var_prior + 1/var_lik)
        media_post = var_post * (media_prior/var_prior + x/var_lik)

        print(f"\nMedia posterior: {media_post:.4f}")
        print(f"Varianza posterior: {var_post:.4f}")
    except Exception as e:
        print(f"Error: {e}")

bayesiana_normal_discreta()
