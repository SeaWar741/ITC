import pandas as pd

df = pd.read_csv("Niveles_de_agua_Conjunto_Modified.csv",parse_dates=['Fecha'],index_col=0)
df[df.columns] = df[df.columns].apply(pd.to_numeric, errors='coerce')
#df.resample('M').mean()
print("Replacing nan")
df.fillna(df.mean(), inplace=True)
print(df)
df.to_csv("Niveles_de_agua_Conjunto_Modified_mean.csv")
