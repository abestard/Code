// Randomized Factorization Algorithm by Pollard Rho O(sqrt(s(n))) expected
// where s(n) is the smallest prime divisor of n
// use in conjuntion with miller_rabin test for primality
//using: Rabin-Miller(), mulmod()
#define func(x)(mulmod(x, x+B, n)+ A )
ll pollard_rho(ll n) {
  if( n == 1 ) return 1;
  if( miller_rabin( n ) )
     return n;
  ll d = n;
  while( d == n ){
    ll A = 1 + rand()%(n-1), B = 1 + rand()%(n-1);
    ll x = 2, y = 2;
    d = -1;
    while( d == 1 || d == -1 ){
        x = func(x), y = func(func(y));
        d = __gcd( x-y, n );
    }
  }
  return abs(d);
}
