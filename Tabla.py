import random
import math
s = 40
def euclides(a, b): 
    if b == 0 :
        return a
    else:
      return euclides(b, a % b)
def euclides_extendido(a, b):
    if a == 0 :
        return b, 0, 1
    mcd,x1,y1 = euclides_extendido(b % a, a)
    x = y1 - (b//a) * x1
    y = x1
    return mcd,x,y
def modulo(a,b): 
    r=a%b
    if r < 0:
        r=r+ b;
    return r

def inversa(a,b):
    m, a, y = euclides_extendido(a, b)
    if m == 1:
      a = modulo(a, b)
    return a

def exp_modular(a, x, n):
  c = a % n
  r = 1
  while(x > 0):
    if x % 2 != 0:
      r = (r * c) % n
    c = (c * c) % n
    x = x//2
  return r

def compuesto(a, n, t, u):
  x = exp_modular(a,u,n)
  if x == 1 or x == n - 1:
    return False
  for i in range(t):
    x = exp_modular(x,2,n)
    if x == n-1:
      return False
  return True

def Miller_Rabin(n,s):
  t = 0
  u = n - 1
  while (u % 2 == 0):
    u = u / 2
    t = t + 1
  for j in range(1, s):
    a = random.randint(2, n-1)
    if compuesto(a, n, t, u):
      return False
  return True

def gen_bits(b):
    n = random.randint(0, (2**b) - 1)
    m = (2**(b-1)) + 1
    n = n | m
    return n

def generar_primo(b):
    n = gen_bits(b)
    while Miller_Rabin(n, s) is False:
        n = n + 2
    return n

def RSA(K):
  bool = True
  while bool:
    p = generar_primo(K)
    q = generar_primo(K)
    if p != q:
      bool = False
  n = p * q
  euler_p = p - 1
  euler_q = q - 1
  euler = euler_p * euler_q
  bool = True
  while bool:
    e = random.randint(3, n - 1)
    if (euclides(e, euler) == 1):
      bool = False
  d = inversa(e,euler)
  print("n es : ")
  print(n)
  print("e es : ")
  print(e)
  print("d es : ")
  print(d)
  return(n, e, d)

def cifrado(m, e, n):
  cifrado = exp_modular(m, e, n)
  print("Cifrado: ", cifrado)
  return cifrado
    
def decifrado(c, d, n):
  decifrado = exp_modular(c, d, n)
  print("Descifrado: ", decifrado)
  return decifrado

bit = int(input("Tamaño de bits: "))
bit//2
c = int(input("Clave para cifrar: "))
n, e, d = RSA(bit)
decifrado(cifrado(c, e, n), d, n)
print()
print("Tabla de 64 bits")
ene, E, de = RSA(64)
for i in range(1, 11):
    print(i)
    m = random.randint(2, n - 1)
    print("m: ", m)
    decifrado(cifrado(m, E, ene), de, ene)

