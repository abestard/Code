//Hashing
unsigned long long calc_hash( int ptr, int in, int f ){
	return Dp[f] - Dp[in-1]*pot33[f-in+1];
}
void buil_hash(  ){
	for( int i = 1; i <= ta; i ++ ) 
		Dp[i] = Dp[i-1]*33LL + ( A[i] - 'a' );
}