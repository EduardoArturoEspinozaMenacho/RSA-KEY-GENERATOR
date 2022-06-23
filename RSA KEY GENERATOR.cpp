#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int modulo(int a, int b) {
  int q = a / b;
  int r;
  if (a < 0) {
    q = q - 1;
  }
  return r = a - (q * b);
}
int expmod(int a, int x, int n) {
  int t;
  if (x == 0) {
    return 1;
  } else if (modulo(x, 2) == 0) {
    t = expmod(a, x / 2, n);
    return modulo(pow(t, 2), n);
  } else {
    t = expmod(a, x - 1, n);
    a = modulo(a, n);
    return modulo((t * a), n);
  }
}
bool ES_COMPUESTO(int a, int n, int t, int u) {
  int x_0 = expmod(a, u, n);
  int x_1;
  if (x_0 == 1 || x_0 == n - 1) {
    return false;
  }
  for (int i = 1; i < t; i++) {
    x_1 = expmod(x_0, 2, n);
    if (x_1 == n - 1) {
      return false;
    }
    x_0 = x_1;
  }
  return true;
}
bool MILLER_RABIN(int n, int s) {
  int t = 0;
  int u = n - 1;
  while (modulo(u, 2) == 0) {
    u = u / 2;
    t = t + 1;
  }
  for (int j = 1; j < s; j++) {
    int a = 2 + rand() % (n - 3);
    if (ES_COMPUESTO(a, n, t, u) == false) {

      return true;
    }
  }
  return false;
}
int RANDOMBITS(int b) {
  int z = pow(2, b) - 1;
  int n = rand() % z;
  return n;
}

int RANDOMGEN_PRIMOS(int b) {
  int s = 8;
  int n = RANDOMBITS(b);
  while (MILLER_RABIN(n, s) == false) {
    n = n + 2;
  }
  return n;
}
int Confirmacion(int n) {
  while (MILLER_RABIN(n, 16) == false) {
    n = n + 1;
  }
  return n;
}
int euclides(int a, int b){
int q;
int r=1;
int eu;
while(r!=0){
  q=a/b;
  r=modulo(a,b);
  a=b;
  eu=b;
  b=r;
  cout<<q<<" "<<r<<endl;
}
  return eu;
  } 
int ext_euclides(int a, int b) {
  int r = 1;
  int q;
  int x0 = 1, y0 = 0;
  int x1 = 0, y1 = 1;
  int auxx, auxy;
  int auxa = a, auxb = b;
  while (r != 0) {
    auxx = x1;
    auxy = y1;
    q = auxa / auxb;
    r = modulo(auxa,auxb);
    x1 = x0 - (q * x1);
    y1 = y0 - (q * y1);
    x0 = auxx;
    y0 = auxy;
    auxa = auxb;
    auxb = r;
  }
return x0;}

int PHI(int n) {
  int r = 0;
  for (int i = 1; i < n; i++) {
    int d =euclides(i, n);
    if (d == 1) {
      r = r + 1;
    }
  }
  return r;
}
int RSA_KEY_GENERATOR(int k) {
  int k_2 = k / 2;
  int p = RANDOMGEN_PRIMOS(k_2);
  int q = RANDOMGEN_PRIMOS(k_2);
  if (MILLER_RABIN(q, k_2) == false) {
    p = Confirmacion(p);
  }
  if (MILLER_RABIN(q, k_2) == false) {
    q = Confirmacion(q);
  }
  int n = p * q;
  cout << n << endl;
  int phn = PHI(n);
  int e = 2 + rand() % (n - 3);
  while (ext_euclides(e, phn) != 1) {
    int e = 2 + rand() % (n - 3);
  }
  cout << e << endl;
  double d =ext_euclides(e, phn);
  cout<<d;
  return 0;
}
int main() {
  srand(time(NULL));
  cout << RSA_KEY_GENERATOR(16);
}
