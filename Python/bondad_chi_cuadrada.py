from scipy.stats import chisquare

def bondad_chi_cuadrada():
    print("\n=== Prueba de bondad de ajuste Chi-cuadrada ===")
    try:
        observados = input("Ingrese los valores observados separados por comas: ")
        esperados = input("Ingrese los valores esperados separados por comas: ")

        obs = [float(x.strip()) for x in observados.split(",")]
        esp = [float(x.strip()) for x in esperados.split(",")]

        if len(obs) != len(esp):
            print("Error: La cantidad de observados y esperados debe ser igual.")
            return

        estadistico, p_valor = chisquare(obs, f_exp=esp)

        print(f"\nEstadístico Chi-cuadrada: {estadistico}")
        print(f"Valor p: {p_valor}")
        if p_valor < 0.05:
            print("Conclusión: Hay diferencia significativa entre los datos observados y esperados.")
        else:
            print("Conclusión: No hay diferencia significativa entre los datos observados y esperados.")
    except Exception as e:
        print(f"Error: {e}")

bondad_chi_cuadrada()
