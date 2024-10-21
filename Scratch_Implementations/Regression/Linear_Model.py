import numpy as np

class LinearRegression:
    
    def __init__(self, lr=.001, n_itr=1000, reg=None, lmda=[.001, .001]):
        if not isinstance(lr, (int, float)):
            raise TypeError(f"Learning Rate must be a int or float type, but got {type(lr).__name__}")
        if not isinstance(n_itr, (int, float)):
            raise TypeError(f"Number of Iterations must be a int ype, but got {type(n_itr).__name__}")
        if reg is not None and not isinstance(reg, str):
            raise TypeError(f"Regulaizer must be a str or left alone, but got {type(lr).__name__}")
        if not isinstance(lmda, list):
            raise TypeError(f"Lambda (the regularization strength) must be a list type, but got {type(lr).__name__}")
        if not all(isinstance(i, (int, float)) for i in lmda):
            raise ValueError(f"Both Lambda should be int or float, but got {type(lmda[0]).__name__} and {type(lmda[1]).__name__}")
        self.lr = lr
        self.n_itr = n_itr
        self.wieghts = None
        self.bias = None
        self.reg = reg
        self.lmda_l = lmda[0]
        self.lmda_r = lmda[1]
        if self.reg == 'lasso':
            print(f"Lambda lasso Chosen = {self.lmda_l}")
        elif self.reg == 'ridge':
            print(f"Lambda ridge Chosen = {self.lmda_r}")
        elif self.reg == 'elastic_net':
            print(f"Lambda Ridge Chosen = {self.lmda_r}")
            print(f"Lambda Lasso Chosen = {self.lmda_l}")
            

        
    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.wieghts = np.zeros(n_features)
        self.bias = 0
        
        if self.reg == None:
            for _ in range(self.n_itr):
                # print(X.shape)
                # print(self.wieghts.shape)
                y_pred = np.dot(X, self.wieghts) + self.bias
                # print(y_pred.shape)
                
                dw = (-1/n_samples) * np.dot(X.T, (y_pred-y))
                db = (-1/n_samples) * np.sum(y_pred-y)
                # print(dw)
                # print(db)
                
                self.wieghts = self.wieghts + self.lr * dw
                self.bias = self.bias + self.lr * db
                # print(self.wieghts.shape)
                # print(self.bias.shape)

        elif self.reg == 'ridge':
            for _ in range(self.n_itr):
                y_pred = np.dot(X, self.wieghts) + self.bias
                
                reg_term = self.lmda_r * self.wieghts
                dw = (-1/n_samples) * np.dot(X.T, (y_pred-y)) + reg_term
                db = (-1/n_samples) * np.sum(y_pred-y)
                
                self.wieghts = self.wieghts + self.lr * dw
                self.bias = self.bias + self.lr * db
                

        elif self.reg == 'lasso':
            for _ in range(self.n_itr):
                y_pred = np.dot(X, self.wieghts) + self.bias
                reg_term = 0
                for i in self.wieghts:
                    if i>0: 
                        reg_term += self.lmda_l
                    elif i<0:
                        reg_term -= self.lmda_l

                dw = (-1/n_samples) * np.dot(X.T, (y_pred-y)) + reg_term
                db = (-1/n_samples) * np.sum(y_pred-y)

                self.wieghts = self.wieghts + self.lr * dw
                self.bias = self.bias + self.lr * db

        elif self.reg == 'elastic_net':
            for _ in range(self.n_itr):
                y_pred = np.dot(X, self.wieghts) + self.bias
                reg_term = self.lmda_r * self.wieghts
                for i in self.wieghts:
                    if i>0: 
                        reg_term = reg_term + self.lmda_l
                    elif i<0:
                        reg_term = reg_term - self.lmda_l

                dw = (-1/n_samples) * np.dot(X.T, (y_pred-y)) + reg_term
                db = (-1/n_samples) * np.sum(y_pred-y)
                
                self.wieghts = self.wieghts + self.lr * dw
                self.bias = self.bias + self.lr * db


    def predict(self, X):
        y_pred = np.dot(X, self.wieghts) + self.bias
        return y_pred
        