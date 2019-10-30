import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime

# Read in your file as a pandas.DataFrame
# using 'any number of whitespace' as the seperator
df = pd.read_csv("./Cerro_prieto.csv",parse_dates=['Date'],index_col=0)
print(df)
print(df.head())

#df.resample('M').mean()
df = df.fillna(df.mean())
monthly=df.resample('M', how='mean')
#df.groupby(df.index.Date).mean()
print(monthly)