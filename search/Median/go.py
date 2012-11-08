#!/usr/bin/env python

N = int(raw_input())


a = []    
total = 0


def getMeida(total):
    index = total/2
    if total % 2 == 0:
        return (a[index] + a[index-1])/2
    else:
        return a[index]

for i in range(0, N):
    tmp = raw_input()
    act,item = [xx for xx in tmp.split(" ")]
    
    if act == 'a':
        
    elif act == 'r':


