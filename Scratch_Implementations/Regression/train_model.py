import numpy as np
from sklearn.model_selection import train_test_split
from sklearn import datasets
import matplotlib.pyplot as plt
from Linear_Model import LinearRegression

def mse(y_test, predictions):
    return np.mean((y_test-predictions)**2)

X, y = datasets.make_regression(n_samples=100, n_features=4, noise=10, random_state=73)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=73)

print(X)
print(y)

reg = LinearRegression(lr=0.01, n_itr=100, reg='ridge') # 'ridge' -> Reduce overfitting,
                                                        # 'lasso' -> reduce overfittin andfeature selection,
                                                        # 'elastic_net' -> Search all three diff and benefits

reg.fit(X_train,y_train)
# print(f"before prediction: {X_test}")
predictions = reg.predict(X_test)
# print(f"after prediction: {predictions}")

mse = mse(y_test, predictions)
print(mse)

y_pred_line = reg.predict(X)
# cmap = plt.get_cmap('viridis')
fig = plt.figure(figsize=(8,6))

# Printing graph with only first variable
# print(X_train.shape)
# print(y_train.shape)
# print(X_test.shape)
# print(y_test.shape)
m1 = plt.scatter(X_train[:, 0], y_train, color='red', s=10)
m2 = plt.scatter(X_test[:, 0], y_test, color='blue', s=10)
plt.plot(X[:, 0], y_pred_line, color='green', linewidth=.5, label='Prediction')
plt.show()