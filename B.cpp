#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef long long ll;
using namespace std;
ll expmod(int a, int x, ll n) {
  ll t;
  if (x == 0) {
    return 1;
  } else if (x%2==0) {
    t = expmod(a, x / 2, n);
    ll t_2=pow(t, 2);
    return t_2%n;
  } else {
    t = expmod(a, x - 1, n);
    a =a%n;
    return (t * a)%n;
  }
}
bool ES_COMPUESTO(ll a, ll n, ll t, ll u) {
  ll x_0 = expmod(a, u, n);
  ll x_1;
  if (x_0 == 1 || x_0 == n - 1) {
    return false;
  }
  for (ll i = 1; i < t; i++) {
    x_1 = expmod(x_0, 2, n);
    if (x_1 == n - 1) {
      return false;
    }
    x_0 = x_1;
  }
  return true;
}
bool MILLER_RABIN(int n, int s) {
  ll t = 0;
  ll u = n - 1;
  while (u%2 == 0) {
    u = u / 2;
    t = t + 1;
  }
  for (int j = 1; j < s; j++) {
    ll a = 2 + rand() % (n - 3);
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
  ll n = RANDOMBITS(b);
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
ll euclides(int a, int b){
ll q;
ll r=1;
ll eu;
while(r!=0){
  q=a/b;
  r=a%b;
  a=b;
  eu=b;
  b=r;
  cout<<q<<" "<<r<<endl;
}
  return eu;
  } 
ll ext_euclides(ll a, ll b) {
  ll r = 1;
  ll q;
  ll x0 = 1, y0 = 0;
  ll x1 = 0, y1 = 1;
  ll auxx, auxy;
  ll auxa = a, auxb = b;
  while (r != 0) {
    auxx = x1;
    auxy = y1;
    q = auxa / auxb;
    r = auxa%auxb;
    x1 = x0 - (q * x1);
    y1 = y0 - (q * y1);
    x0 = auxx;
    y0 = auxy;
    auxa = auxb;
    auxb = r;
  }
return x0;}
ll RSA_KEY_GENERATOR(ll k) {
  ll k_2 = k / 2;
  ll p = RANDOMGEN_PRIMOS(k_2);
  ll q = RANDOMGEN_PRIMOS(k_2);
  if (MILLER_RABIN(q, k_2) == false) {
    p = Confirmacion(p);
  }
  if (MILLER_RABIN(q, k_2) == false) {
    q = Confirmacion(q);
  }
  ll n = p * q;
  cout << n << endl;
  ll phn =(p-1)*(q-1);
  ll e = 2 + rand() % (n - 3);
  while (ext_euclides(e, phn) != 1) {
     e = 2 + rand() % (n - 3);
  }
  cout << e << endl;
  ll d =ext_euclides(e, phn);
  cout<<d;
  return 0;
}
int main() {
  srand(time(NULL));
  cout << RSA_KEY_GENERATOR(64);
}
