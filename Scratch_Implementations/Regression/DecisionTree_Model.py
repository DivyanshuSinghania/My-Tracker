import numpy as np
from collections import Counter

class Node:
    
    def __init__(self, feature=None, threshold=None, left=None, right=None, *,value=None):
    # ,*,value=None -> with this when passing the arg, we need to write the name of arg too, 
    # example Node(...,value = 4)
        self.feature = feature
        self.threshold = threshold
        self.left = left
        self.right = right
        self.value = value
    
    def isLeafNode(self):
        return self.value is not None
    
class DecisionTree:
    
    def __init__(self, min_sample_split=2, max_depth=100, n_features=None):
        self.min_sample_split = min_sample_split
        self.max_depth = max_depth
        self.n_features = n_features
        self.root = None
    
    def fit(self, X, y):
        self.n_features = X.shape[1] if not self.n_features else min(X.shape[1], self.n_feature)
        if(X.shape[1]<self.n_features):
            print("No. feature inputed is more than max No. feture, n_feature = max_features")
            
        # Creating tree, this will be the basis for prediction
        self.root = self._grow_tree(X, y)
        
    def _grow_tree(self, X, y, depth=0):
        # Recursive Function
        n_samples, n_feats = X.shape
        n_labels = len(np.unique(y))
        # Check the stopping criteria -> this will help reduce complexity in Random Forest too
        if(depth>=self.max_depth or n_labels==1 or n_samples<self.min_sample_split):
            leaf_value = self._most_common_label(y)
            return Node(value=leaf_value)
        
        # find best split from self.n_features in the remaining features on the basis of (threshold->labels)
        feat_idxs = np.random.choice(n_feats, self.n_features, replace=False)
        best_threshold, best_features = self._best_split(X,y,feat_idxs)
        
        # Create Children on basis of featurea and threshold/values provided
        left_idxs, right_idxs = self._split(X[:, best_features], best_threshold)
        left = self._grow_tree(X[left_idxs, :], y[left_idxs], depth+1)
        right = self._grow_tree(X[right_idxs, :], y[right_idxs], depth+1)
        # self, feature=None, threshold=None, left=None, right=None, *,value=None
        return Node(best_features, best_threshold, left, right)
        
    def _most_common_label(self, y):
        counter = Counter(y)
        value = counter.most_common(1)[0][0]
        return value
        
    def _best_split(self, X, y, feat_idxs):
        best_gain = -1
        split_threshold, split_idx = None, None
        
        # Goind thorugh every combination of feature and threshold/values in it
        for feat_idx in feat_idxs:
            X_col = X[:, feat_idx]
            thresholds = np.unique(X_col)
            for thr in thresholds:
                # Calculating Inofrmation gain for max gains
                gain = self._info_gain(y, X_col, thr)
                
                if(gain>best_gain):
                    best_gain = gain
                    split_idx = feat_idx
                    split_threshold = thr
        
        return split_threshold, split_idx
    
    def _split(self, X_col, thr):
        left_idx = np.argwhere(X_col<=thr).flatten()
        right_idx = np.argwhere(X_col>thr).flatten()
        return left_idx, right_idx
    
    def _info_gain(self, y, X_col, thr):
    # IG = E(parent) - [Weighted average].E(children)
        # Parent Entropy
        parent_entropy = self._entropy(y)
        
        # Create Child from indices from the X_col
        left_idxs, right_idxs = self._split(X_col, thr)
        
        # one side is empty then entropy is zero and hence IG too
        if len(left_idxs)==0 or len(right_idxs)==0:
            return 0
        
        # Calculate the WEIGHTED AVERAGE Entropy of Children
        n = len(y)
        n_l, n_r = len(left_idxs), len(right_idxs)
        e_l, e_r = self._entropy(y[left_idxs]), self._entropy(y[right_idxs])
        child_entropy = (n_l/n)*e_l + (n_r/n)*e_r
        
        # Calculate IG
        return parent_entropy - child_entropy
    
    
    def _entropy(self, y):
    # E = -sum(p*log(p)), p = #x/n->number of x by number of all values
        # [0,1,3,2,3,1] -> [1,2,1,2]->this tells the repitition of index, basically histogram
        hist = np.bincount(y)
        ps = hist / len(y)
        
        # Calculating Entropy, ignoring 0 as it means the element(index in hist) never existed in "y"
        return -np.sum(p*np.log(p) for p in ps if p > 0)
        
    def predict(self, X):
        return np.array([self._traverseTree(x, self.root) for x in X])
    
    def _traverseTree(self, x, root):
        if root.isLeafNode():
            return root.value
        
        if x[root.feature]<=root.threshold:
            return self._traverseTree(x, root.left)
        return self._traverseTree(x, root.right)
        