import numpy as np
from DecisionTree_Model import DecisionTree

class RandomForst:
    # self, min_sample_split=2, max_depth=100, n_features=None
    def __init__(self,*,no_trees=10, min_sample_split=2, max_depth=100, n_features= None):
        self.no_trees = no_trees
        self.min_sample_split = min_sample_split
        self.max_depth = max_depth
        self.n_features = n_features
        self.reg = []
        
    def fit(self, X, y):
        for _ in range(self.no_trees):
            # Pick "K" random data points
            num_rows, num_cols = X.shape
            # Randomly pick 20% of row's indices                                    |-> unique elements
            random_indices = np.random.choice(num_rows, size=int(.2*num_rows), replace=False)
            X_sample = X[random_indices, :]
            # creating a list of regressors of DecisionTree
            temp = DecisionTree(self.min_sample_split, self.max_depth, self.n_features)
            temp.fit(X, y)
            self.reg.append(temp)
        
    def predict(self, X):
        predictions = []
        pred = []
        for i in range(self.no_trees):
            regressor = self.reg[i]
            # print(regressor)
            predictions.append(regressor.predict(X))
        
        for i in range(X.shape[0]):
            mean = 0
            for j in range(self.no_trees):
                mean += predictions[j][i]
            mean = mean / self.no_trees
            if mean>.5:
                pred.append(1)
            else:
                pred.append(0)
        # print(f"Predictions->{pred}")
        return pred

import numpy as np
from sklearn.model_selection import train_test_split
from sklearn import datasets
import matplotlib.pyplot as plt

r = RandomForst()
data = datasets.load_breast_cancer()
X, y = data.data, data.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=73)

r.fit(X_train, y_train)
predictions = r.predict(X_test)

def accuracy(y_test, predictions):
    return np.sum(y_test==predictions) / len(y_test)

accuracy = accuracy(y_test, predictions)
print(accuracy)