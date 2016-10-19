//Inverso Modular mcd(n,m)==1
//using: Extended GCD
int inverso_mod(int n ,int m){
    int s, t, d;
	d = extended_euclid( n, m, s, t );
	return ((s % m)+m)% m;
}
