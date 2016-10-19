///----FFT-O(n*log(n))-----
const int MOD = 167772161;
// so the algorithm works until n = 2 ^17 = 131072
const int g = 3; // primitive root
//const int MOD = 1073872897 = 2  ^ 30 + 2 ^ 17 + 1, g = 7
// another good choice is MOD = 167772161 = 2 ^27 + 2 ^ 25 + 1, g = 3
// a bigger choice would be MOD = 3221225473 = 2 ^ 31 + 2 ^ 30 + 1, g = 5
// but it requires unsigned long long for multiplications
typedef long long i64;
// n must be a power of two
// sign = 1, scale = 1 for DFT
// sign = -1, scale = (1 / n) (MOD) or (MOD-(MOD-1)/n) for inverse
//using: powmod()
void ifft(int n, i64 a[],int sign, i64 scale) {
	int k;
	for (k = 0; (1 << k) < n; k++);
	for (int i = 0; i < n; i++) {
		int q = 0;
		for (int j = 0; j < k; j++) {
			q <<= 1;
			if (i & 1 << j)	q++;
		}
		if (i < q) swap(a[i], a[q]);
	}
	i64 x = powmod(g, (MOD - 1) / n, MOD);
	for (int q = 2; q <= n; q <<= 1) {
		int q2 = q / 2;
		i64 wn = powmod(x, n + sign * n / q, MOD);
		i64 w = 1;
		for (int i = 0; i < q2; i++) {
			for (int j = i; j < n; j += q) {
				int v = w * a[j + q2] % MOD;
				a[j + q2] = (a[j] - v + MOD) % MOD;
				a[j] = (a[j] + v) % MOD;
			}
			w = i64(w) * wn % MOD;
		}
	}
	for (int i = 0; i < n; i++) a[i] = a[i] * scale % MOD;
}
