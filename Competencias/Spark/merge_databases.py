import pandas as pd
import numpy as np
import glob
from tabula import read_pdf
import camelot

all_data = pd.DataFrame()
for f in glob.glob('./Databases/*.xlsx'):
   df = pd.read_excel(f)
   all_data = all_data.append(df, ignore_index=False)

print(all_data)

df = read_pdf("19069.pdf")

print(df)

""" tables = camelot.read_pdf('19069.pdf')
tables.export('19069.csv',f='csv',compress=True)
print(tables[0].parsing_report) """

writer = pd.ExcelWriter('mycollected_data.xlsx', engine='xlsxwriter')
all_data.to_excel(writer, sheet_name='Sheet1')
writer.save()