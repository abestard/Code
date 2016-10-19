//Suffix Array (N*logN)
#define MN 200005
int N, in[305], prox[MN], sa[MN], k, cant[MN], pos[MN], lcp[MN], may, s1;
char A[MN];
bool b1[MN], b2[MN];
void LCP(  ){
	for( int p = 0, i = 0; i < N; i ++ )
		if( pos[i] != N - 1 ){
			for( int j = sa[pos[i]+1]; i + p <= N && 
			  j + p <= N && A[i+p] == A[j+p]; p ++ );
				lcp[pos[i]] = p;
			if( p ) p --;
		}
}
inline void upper( int x ){
	int p = pos[x];
	pos[x] = p + cant[p];
	cant[p] ++;
	b2[pos[x]] = true;
}
void Suffix_Array( ){
	fill( in, in + 300, -1 );
	for( int i = 0; i < N; i ++ )
		prox[i] = in[(int)A[i]], in[(int)A[i]] = i;
	for( int i = 'a'; i <= 'z'; i ++ )
		for( int j = in[i]; j != -1; j = prox[j] ){
			sa[k] = j;
			if( j == in[i] ) b1[k] = true;
			k ++;
		}
	int p;
	for( int H = 1; H < N; H *= 2 ){
		fill( b2, b2 + N + 1, false );
		for( int i = 0; i < N; i = k ){
			for( k = i+1; k < N && !b1[k]; k ++ );
				cant[i] = 0;
			for( int j = i; j < k; j ++ )
				pos[sa[j]] = i;
		}
		upper( N - H );
		for( int i = 0; i < N; i = k ){
			for( k = i+1; k < N && !b1[k]; k ++ );
			for( int j = i; j < k; j ++ )
				if( sa[j] - H >= 0 )
					upper( sa[j] - H );
			for( int j = i; j < k; j ++ )
				if( sa[j] - H >= 0 && b2[pos[sa[j] - H]] ){
					for( p = pos[sa[j] - H] + 1; p < N && !b1[p] && b2[p]; p ++ )
						b2[p] = false;
				}
		}
		for( int i = 0; i < N; i ++ ){
			sa[pos[i]] = i;
			b1[i] = ( b1[i] || b2[i] );
		}
	}
	LCP(  );
}