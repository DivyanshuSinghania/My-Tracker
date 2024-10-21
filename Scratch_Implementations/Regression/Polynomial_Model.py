import numpy as np

class PolynomialRegression:
    
    def __init__(self, lr=.001, n_power=2, n_iter=100):
        
        if not isinstance(lr, (int, float)):
            raise TypeError(f"Learning Rate must be a int or float type, but got {type(lr).__name__}")
        if not isinstance(n_power, int):
            raise TypeError(f"Power must be a int type, but got {type(n_power).__name__}")
        if not isinstance(n_iter, int):
            raise TypeError(f"Number of Iteration should be a int type, but got {type(n_iter).__name__}")
        
        self.bias = 0
        self.wieght = np.zeros(n_power)
        self.lr = lr
        self.n_iter = n_iter
        self.n_power = n_power
        
    def fit(self, X, y):
        try:
            n_sample = len(X)
        except:
            n_sample = X.shape[1]

        for _ in range(self.n_iter):
            X_poly = []
            for j in range(n_sample):
                X_poly.append([np.pow(X[j], i+1) for i in range(self.n_power)])
            
            X_poly = np.squeeze(X_poly)
            y_pred = np.dot(X_poly, self.wieght) + self.bias
            print(f"y_pred - y_test: {y_pred-y}")
            # print(f"y_test: {y}")
            
            dw = (-1/n_sample)*np.dot(X_poly.T, y_pred-y)
            db = (-1/n_sample)*np.sum(y_pred-y)
            
            self.wieght = self.wieght + self.lr*dw
            self.bias = self.bias + self.lr*db
    
    def predict(self, X_test):        
        try:
            n_sample = len(X_test)
        except:
            n_sample = X_test.shape[1]

        X_poly = []
        for j in range(n_sample):
            X_poly.append([np.pow(X_test[j], i+1) for i in range(self.n_power)])
            
        X_poly = np.squeeze(X_poly)
        y_pred = np.dot(X_poly, self.wieght) + self.bias
        return y_pred
