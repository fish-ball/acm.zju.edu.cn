# -*- coding: cp936 -*-
# 3784061	2014-09-30 21:20:21	Accepted	3782	Python	10	140	呆滞的慢板
# eval 不能用，讨厌死了

from sys import stdin

for T in range(int(stdin.readline())):
    
    a, op1, b, op2, c = stdin.readline().strip().split()

    a, b, c = map(int, (a, b, c))
    
    if op1 == '*':
        if op2 == '*':
            print(a * b * c)
        elif op2 == '/':
            print(a * b // c)
        elif op2 == '%':
            print(a * b % c)
        elif op2 == '+':
            print(a * b + c)
        elif op2 == '-':
            print(a * b - c)

    elif op1 == '/':
        if op2 == '*':
            print(a // b * c)            
        elif op2 == '/':
            print(a // b // c)        
        elif op2 == '%':
            print(a // b % c)        
        elif op2 == '+':
            print(a // b + c)        
        elif op2 == '-':
            print(a // b - c)
            
    elif op1 == '%':
        if op2 == '*':
            print(a % b * c)            
        elif op2 == '/':
            print(a % b // c)        
        elif op2 == '%':
            print(a % b % c)        
        elif op2 == '+':
            print(a % b + c)        
        elif op2 == '-':
            print(a % b - c)

    elif op1 == '+':
        if op2 == '*':
            print(a + b * c)            
        elif op2 == '/':
            print(a + b // c)        
        elif op2 == '%':
            print(a + b % c)        
        elif op2 == '+':
            print(a + b + c)        
        elif op2 == '-':
            print(a + b - c)

    elif op1 == '-':
        if op2 == '*':
            print(a - b * c)            
        elif op2 == '/':
            print(a - b // c)        
        elif op2 == '%':
            print(a - b % c)        
        elif op2 == '+':
            print(a - b + c)        
        elif op2 == '-':
            print(a - b - c)
    
