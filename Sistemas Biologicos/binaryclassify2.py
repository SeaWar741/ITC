import sklearn as sk
from sklearn import svm
import pandas as pd

heart =pd.read_csv("lung_cancer_examples.csv")

y = heart.iloc[:,4]
X = heart.iloc[:,:4]

SVM = svm.LinearSVC()
SVM.fit(X, y)
SVM.predict(X.iloc[460:,:])
round(SVM.score(X,y), 4)