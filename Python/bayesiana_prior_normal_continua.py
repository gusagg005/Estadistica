def bayesiana_prior_normal_continua():
    print("\n=== Bayesiana: Prior Normal Continua ===")
    try:
        media_muestra = float(input("Media muestral: "))
        n = int(input("Tamaño de muestra: "))
        var_muestra = float(input("Varianza muestral: "))

        media_prior = float(input("Media de la prior: "))
        var_prior = float(input("Varianza de la prior: "))

        var_post = 1 / (n/var_muestra + 1/var_prior)
        media_post = var_post * (media_muestra * n / var_muestra + media_prior / var_prior)

        print(f"\nMedia posterior: {media_post:.4f}")
        print(f"Varianza posterior: {var_post:.4f}")
    except Exception as e:
        print(f"Error: {e}")

bayesiana_prior_normal_continua()