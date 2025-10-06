m1 = 5
m2 = 9
m3 = 12
n = int(input())
t1 = n//m3
t2 = (n - t1*m3)//m2
t3 = (n - t1*m3-t2*m2)//m1
if t1*m3+t2*m2+t3*m1 == n:
    print(f'{t1}*{m3}', ',', f'{t2}*{m2}', ',',f'{t3}*{m1}')
else:
    print('-42')




