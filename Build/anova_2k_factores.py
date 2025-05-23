import pandas as pd
import statsmodels.api as sm
from statsmodels.formula.api import ols

def anova_2k_factores():
    print("\n=== ANOVA para Diseño Factorial 2^k ===")
    try:
        print("Asuma que hay dos factores: A y B con 2 niveles cada uno (- y +).")
        print("Ingrese los valores de respuesta para cada combinación de A y B:")

        combinaciones = [("-", "-"), ("-", "+"), ("+", "-"), ("+", "+")]
        datos = []

        for a, b in combinaciones:
            valor = float(input(f"Valor para A={a}, B={b}: "))
            datos.append({"A": a, "B": b, "respuesta": valor})

        df = pd.DataFrame(datos)
        modelo = ols('respuesta ~ C(A)*C(B)', data=df).fit()
        anova = sm.stats.anova_lm(modelo, typ=2)

        print("\nResultado ANOVA:")
        print(anova)
    except Exception as e:
        print(f"Error: {e}")

anova_2k_factores()
