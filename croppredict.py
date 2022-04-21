import numpy as np
import pandas as pd 
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier

df=pd.read_csv('Crop_recommendation.csv')

c=df.label.astype('category')
targets = dict(enumerate(c.cat.categories))
df['target']=c.cat.codes

y=df.target
X=df[['N','P','K','temperature','humidity','ph','rainfall']]

X_train, X_test, y_train, y_test = train_test_split(X, y,random_state=1)

model = DecisionTreeClassifier(random_state=42).fit(X_train, y_train)
model.score(X_test,y_test)

def predictcrop(arr):
    result = model.predict([arr])
    return (targets[result[0]])


""" crop = predictcrop([78, 42, 42,20.130175, 81.604873, 7.628473, 262.717340])
print(crop) """