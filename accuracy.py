import random
import pandas as pd

def crossValidation(df):
    # accuracy = random.randint(0, 100)
    for i in range (len(df)):
        obj_to_classify = df.iloc[i][1:]
        label_obj_to_classify = df.iloc[i][0]
    #     # print(obj_to_classify)
    #     # print (label_obj_to_classify)



        print('Looping over i, at the', i+1, 'location')
        print('\tThe', i+1, 'th objectis in class', label_obj_to_classify)

    #return accuracy
