import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime

# Read in your file as a pandas.DataFrame
# using 'any number of whitespace' as the seperator
df = pd.read_csv("./Cerro_prieto.csv")

print(df)
print(df.head())

#df.resample('M').mean()
df.groupby(df.index.Date).mean()
print(df)