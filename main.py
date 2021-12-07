import pandas as pd
import random 
from search import featureSearch
from accuracy import crossValidation

df = pd.read_csv('Small_data_60.txt', header=None, sep="\s+")
#print(df.columns)
#print(df)  'Small_data_60.txt'   'LARGE_data__94.txt'

#featureSearch(df)
crossValidation(df)


