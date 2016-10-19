/// Modular Equations ax(n)=b(n)
//using: Extended GCD
int modular_equations( int a, int b, int n ){
 int s, t, x0;
 int d = extended_euclid( a, n, s, t );

 if( b % d == 0 ){
    int tmp = (b/d)*s;
    x0 = ((tmp%n)+n)%n; // x0 = s*b
    return x0; // x = x0+(n/d)*k, 0 < k < d
 }

 return -1;
}


