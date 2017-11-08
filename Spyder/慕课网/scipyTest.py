# -*- coding: utf-8 -*-
"""
Created on Mon Aug 14 14:18:13 2017

@author: HanKin
"""

import numpy as np
from pylab import *

def main():
    #--Integral
    from scipy.integrate import quad,dblquad,nquad
    print(quad(lambda x:np.exp(-x),0,np.inf))
    print(dblquad(lambda t, x:np.exp(-x*t)/t**3,0,np.inf,lambda x:1, lambda x:np.inf))
    def f(x,y):
        return x*y
    def bound_y():
        return [0,0.5]
    def bound_x(y):
        return [0,1-2*y]
    print("NQUAD",nquad(f,[bound_x,bound_y]))

    #2--Optimizer
    from scipy.optimize import minimize
    def rosen(x):
        return sum(100.0*(x[1:]-x[:-1]**2.0)**2.0+(1-x[:-1])**2.0)
    x0=np.array([1,3,0.7,0.8,1.9,1.2])
    res=minimize(rosen,x0,method="nelder-mead",options={"xtol":1e-8,"disp":True})
    print("ROSE MINI:",res)     #求出函数全局的最小值，可看属性res.x
    
    def func(x):
        return (2*x[0]*x[1]+2*x[0]-x[0]**2-2*x[1]**2)
    def func_deriv(x):
        dfdx0 =(-2*x[0]+2*x[1]+2)
        dedx1 =(2*x[0]-4*x[1])
        return np.array([dedx0,dedx1])
#    cons = 
#    优化器，拉格朗日（条件极值），雅可比矩阵，求根（未知数值）
    from scipy.optimize import root
    def fun(x):
        return x+2*np.cos(x)
    sol=root(fun,0.1)
    print("ROOT:",sol.x,sol.fun)
    
    def fun_simple(x):
        return x+3
    sol=root(fun,0.5)
    print("ROOT:",sol.x,sol.fun)
    
    #3--Interpolation插值
    x=np.linspace(0,1,10)
    y=np.sin(2*np.pi*x)
#    You used interpld, i.e. INTERPLD.
#    You want interp1d, i.e. with the numeral 1, for one-dimensional.
    from scipy.interpolate import interp1d
    li=interp1d(x,y,kind='cubic')
    x_new=np.linspace(0,1,50)
    y_new=li(x_new)
    figure()
    plot(x,y,'r')   #红色
    plot(x_new,y_new,'k')   #黑色
    print(y_new)
    
    #4--Linear
    from scipy import linalg as lg
    arr = np.array([[1,2],[3,4]])
    print("Det:",lg.det(arr))
    print("Inv:",lg.inv(arr))
    b=np.array([6,14])
    print("Sol:",lg.solve(arr,b))
    print("Eig:",lg.eig(arr))
    print("LU:",lg.lu(arr))
    print("QR:",lg.qr(arr))
    print("SVD:",lg.svd(arr))
    print("Schur:",lg.schur(arr))

if __name__=='__main__': 
    main()
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    