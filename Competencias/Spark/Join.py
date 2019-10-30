import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime
import glob

counter = 0

for filen in glob.glob("./"+'*.csv'):
    # Read in your file as a pandas.DataFrame
    # using 'any number of whitespace' as the seperator
    print(f"Iniciando {filen}")
    df = pd.read_csv(f"./{filen}",parse_dates=['Date'],index_col=0)
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
    filen= filen[:-4]
    nfile = f"{filen}_processed_data.csv"

    df.to_csv(nfile)

    print(f"Se completo el archivo {filen}| Counter: {counter}")