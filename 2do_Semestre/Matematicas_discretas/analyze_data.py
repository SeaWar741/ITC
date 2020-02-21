import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

df=pd.read_csv('Encuesta.csv')
print(df.head())
sns.set()
heatmap1_data = pd.pivot_table(df, values='Edad', 
                     index=['Forma'], 
                     columns='Bebida')

sns.heatmap(heatmap1_data, cmap="YlGnBu")

heatmap2_data = pd.pivot_table(df, values='Forma', 
                     index=['Bebida'], 
                     columns='Funcion')
plt.show()
sns.heatmap(heatmap2_data, cmap="RdBu")
plt.show()
heatmap3_data = pd.pivot_table(df, values='Material', 
                     index=['Bebida'], 
                     columns='Funcion')
sns.heatmap(heatmap3_data)
plt.show()
heatmap4_data = pd.pivot_table(df, values='Bebida', 
                     index=['Forma'], 
                     columns='Costo_D')
sns.heatmap(heatmap4_data)
plt.show()
heatmap5_data = pd.pivot_table(df, values='Bebida', 
                     index=['Forma'], 
                     columns='Costo_R')
sns.heatmap(heatmap5_data)
plt.show()