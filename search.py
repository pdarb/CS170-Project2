import pandas as pd
from accuracy import crossValidation


# Iterates through search tree - Forward Selection
def featureSearch(df):

    current_set_of_features = []

    for i in range (df.shape[1]):
        print('On the', i+1, 'th level of the search tree')
        feature_to_add_at_level = []
        best_so_far = 0

        for k in range (df.shape[1]):
            if (k+1) not in current_set_of_features:
                print('\tConsider adding feature', k+1)
                accuracy = crossValidation(df)
                #print(accuracy)

                if accuracy > best_so_far:
                    best_so_far = accuracy
                    feature_to_add_at_level.append(k+1)
                    print("feature:", feature_to_add_at_level)
        
        current_set_of_features.append(feature_to_add_at_level[-1])
        #print(current_set_of_features)
        print("On level", i+1, "I added feature", feature_to_add_at_level[-1], "to current set")

    print('Current Features:', current_set_of_features)
    