import numpy as np
x= [1,2,3,4,5,6]
X_poly_f = []
for i in range(len(x)):
    X_poly = []
    for j in range(4):
        X_poly.append(np.pow(x[i], (j+1)))
    
    X_poly_f.append(X_poly)

print(X_poly_f)
