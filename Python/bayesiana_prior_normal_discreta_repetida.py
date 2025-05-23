def bayesiana_prior_normal_discreta_repetida():
    print("\n=== Bayesiana: Prior Normal Discreta (varios datos) ===")
    try:
        datos = input("Ingrese los datos observados separados por comas: ")
        datos = [float(x.strip()) for x in datos.split(",")]

        media_prior = float(input("Ingrese la media de la prior: "))
        var_prior = float(input("Ingrese la varianza de la prior: "))
        var_lik = float(input("Ingrese la varianza de la verosimilitud: "))

        n = len(datos)
        media_muestra = sum(datos) / n

        var_post = 1 / (1/var_prior + n/var_lik)
        media_post = var_post * (media_prior/var_prior + n * media_muestra/var_lik)

        print(f"\nMedia posterior: {media_post:.4f}")
        print(f"Varianza posterior: {var_post:.4f}")
    except Exception as e:
        print(f"Error: {e}")

bayesiana_prior_normal_discreta_repetida()