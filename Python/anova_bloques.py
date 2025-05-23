import pandas as pd
import statsmodels.api as sm
from statsmodels.formula.api import ols

def anova_bloques():
    print("\n=== ANOVA con Diseño en Bloques ===")
    try:
        tratamientos = input("Tratamientos (separados por comas): ").split(",")
        bloques = input("Bloques (separados por comas): ").split(",")
        
        datos = []
        for bloque in bloques:
            print(f"\nDatos para el bloque {bloque}:")
            for tratamiento in tratamientos:
                valor = float(input(f"{tratamiento}: "))
                datos.append({"bloque": bloque.strip(), "tratamiento": tratamiento.strip(), "valor": valor})

        df = pd.DataFrame(datos)
        modelo = ols('valor ~ C(tratamiento) + C(bloque)', data=df).fit()
        anova = sm.stats.anova_lm(modelo, typ=2)

        print("\nResultado ANOVA:")
        print(anova)
    except Exception as e:
        print(f"Error: {e}")


anova_bloques()