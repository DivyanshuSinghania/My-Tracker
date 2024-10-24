import numpy as np

# Used dual Lagranges Transformed Formulae,
# Only linear was too easy
# And this was too difficult
# for now I took help of ChatGPT
# But I will RETURN

class SVR:
    def __init__(self, kernel='rbf', C=1.0, epsilon=0.1, gamma='scale'):
        self.kernel = kernel
        self.C = C
        self.epsilon = epsilon
        self.gamma = gamma
        self.alpha = None
        self.b = 0
        self.support_vectors = None
        self.support_vector_labels = None

    def fit(self, X, y):
        self.X_train = X
        self.y_train = y
        n_samples, n_features = X.shape
        
        # Initialize Lagrange multipliers
        self.alpha = np.zeros(n_samples)

        # Main SMO loop (simplified)
        for _ in range(1000):  # Max iterations
            alpha_changed = 0
            
            for i in range(n_samples):
                # Calculate the error for the i-th training sample
                error_i = self._calculate_error(i)

                # Check KKT conditions
                if (self.y_train[i] * error_i < -self.epsilon and self.alpha[i] < self.C) or \
                   (self.y_train[i] * error_i > self.epsilon and self.alpha[i] > 0):
                    
                    # Select a second random index
                    j = self._select_random_index(i, n_samples)
                    
                    # Calculate the error for the j-th training sample
                    error_j = self._calculate_error(j)

                    # Save old alphas
                    alpha_i_old = self.alpha[i]
                    alpha_j_old = self.alpha[j]

                    # Compute the bounds for alpha_j
                    if self.y_train[i] != self.y_train[j]:
                        L = max(0, alpha_j_old - alpha_i_old)
                        H = min(self.C, self.C + alpha_j_old - alpha_i_old)
                    else:
                        L = max(0, alpha_i_old + alpha_j_old - self.C)
                        H = min(self.C, alpha_i_old + alpha_j_old)

                    if L == H:
                        continue

                    # Compute the kernel and other necessary components
                    K_ij = self._kernel(X[i], X[j])
                    eta = 2 * K_ij - self._kernel(X[i], X[i]) - self._kernel(X[j], X[j])
                    
                    if eta >= 0:
                        continue
                    
                    # Update alpha_j
                    self.alpha[j] -= (self.y_train[j] * (error_i - error_j)) / eta
                    self.alpha[j] = np.clip(self.alpha[j], L, H)

                    # Check if alpha_j has changed significantly
                    if abs(self.alpha[j] - alpha_j_old) < 1e-5:
                        continue

                    # Update alpha_i
                    self.alpha[i] += self.y_train[i] * self.y_train[j] * (alpha_j_old - self.alpha[j])

                    # Update b
                    b1 = self.b - error_i - self.y_train[i] * (self.alpha[i] - alpha_i_old) * self._kernel(X[i], X[i]) - \
                         self.y_train[j] * (self.alpha[j] - alpha_j_old) * self._kernel(X[i], X[j])
                    b2 = self.b - error_j - self.y_train[i] * (self.alpha[i] - alpha_i_old) * self._kernel(X[i], X[j]) - \
                         self.y_train[j] * (self.alpha[j] - alpha_j_old) * self._kernel(X[j], X[j])
                    
                    if 0 < self.alpha[i] < self.C:
                        self.b = b1
                    elif 0 < self.alpha[j] < self.C:
                        self.b = b2
                    else:
                        self.b = (b1 + b2) / 2
                    
                    alpha_changed += 1
            
            if alpha_changed == 0:
                break
        
        # Save support vectors
        support_vector_indices = self.alpha > 0
        self.support_vectors = X[support_vector_indices]
        self.support_vector_labels = y[support_vector_indices]
        self.alpha = self.alpha[support_vector_indices]

    def predict(self, X):
        # Calculate the prediction
        prediction = np.zeros(X.shape[0])
        for i in range(len(X)):
            prediction[i] = np.sum(self.alpha * self.support_vector_labels * self._kernel(X[i], self.support_vectors)) + self.b
        return prediction

    def _kernel(self, x1, x2):
        if self.kernel == 'linear':
            return np.dot(x1, x2)
        elif self.kernel == 'rbf':
            if self.gamma == 'scale':
                self.gamma = 1.0 / x1.shape[1]
            return np.exp(-self.gamma * np.linalg.norm(x1 - x2) ** 2)
        # You can add other kernels (e.g., polynomial) here
        else:
            raise ValueError(f"Unsupported kernel: {self.kernel}")

    def _calculate_error(self, i):
        # Calculate the error for a given sample
        return self.predict(self.X_train[i].reshape(1, -1))[0] - self.y_train[i]

    def _select_random_index(self, i, n_samples):
        j = i
        while j == i:
            j = np.random.randint(0, n_samples)
        return j




# Generate synthetic data (same as before)
X = np.random.rand(100, 1) * 10
y = np.sin(X).ravel() + np.random.randn(100) * 0.1

# Create and train the SVR model
svr_model = SVR(kernel='rbf', C=1.0, epsilon=0.1)
svr_model.fit(X, y)

# Make predictions
X_new = np.linspace(0, 10, 100).reshape(-1, 1)
predictions = svr_model.predict(X_new)

# Plot the results
import matplotlib.pyplot as plt

plt.scatter(X, y, color='blue', label='Training Data')
plt.plot(X_new, predictions, color='red', label='SVR Predictions')
plt.title('SVR Model Predictions from Scratch')
plt.xlabel('X')
plt.ylabel('Predicted y')
plt.legend()
plt.show()