import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime

# Read in your file as a pandas.DataFrame
# using 'any number of whitespace' as the seperator
df = pd.read_csv("./Cerro_prieto.csv",parse_dates=['Date'],index_col=0)
print(df)

df[df.columns] = df[df.columns].apply(pd.to_numeric, errors='coerce')
#df.resample('M').mean()
print("Replacing nan")
df.fillna(df.mean(), inplace=True)
print(df)
monthly=df.resample('M', how='mean')
#df.groupby(df.index.Date).mean()
print(monthly)

df['T.Media'] = df.apply(lambda row: ((row.TMAX + row.TMIN)/2), axis = 1) 

df.to_csv(r'./Data_retreived.csv')