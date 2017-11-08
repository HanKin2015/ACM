import itertools
import numpy as np
import pandas as pd

if __name__=='__main__':
    arr = np.array([1,2,3,4])
    print(type(arr))
    
#    brr = np.array(['spades','hearts','diamonds','clubs'])
    brr = np.array([11,12,13,14])
    print(type(brr))
    
    arr = np.ravel(arr)
    brr = np.ravel(brr)
    
#    arr = pd.DataFrame(arr,columns=['arr'])
#    brr = pd.DataFrame(brr,columns=['brr'])
    
    
    new_a = [1, 2, 3]
    new_b = [4, 5, 6]
    new = pd.DataFrame({
            "arr": [1, 2, 3],
            "brr": [4, 5, 6]
            })
    
    print(arr.shape)
    print(brr.shape)

#    ret = arr.join(brr)
    new.to_csv("rett.csv",index=False)
