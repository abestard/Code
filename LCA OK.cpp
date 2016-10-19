/// LCA
void LCA( ){
	lv[1] = 1, Q.push( 1 );
	int logg, nod, newn, t;
	mark[1] = true;
	while( !Q.empty() ){
		nod = Q.front();
		Q.pop();
		t = V[nod].size();
		for(int i = 0; i < t; i ++){
			newn = V[nod][i];
			if( mark[newn] ) continue;
			Q.push( newn );
			lv[newn] = lv[nod] + 1;
			Dp[newn][0] = nod;
			logg = log2( lv[newn] );
			for(int j = 1; j <= logg; j ++)
				if( Dp[newn][j - 1] )
					Dp[newn][j] = Dp[Dp[newn][j - 1]][j - 1];
		}
	}
}
int ancestro( int a, int b ){
	if( lv[a] < lv[b] ) swap( a, b );
	int logg = log2( lv[a] );
	for( int i = logg; i >= 0; i -- )
		if(lv[a] - ( 1 << i) >= lv[b] && Dp[a][i])
			a = Dp[a][i];
	if( a == b ) return a;
	for(int i = logg; i >= 0; i --)
		if(Dp[a][i] != Dp[b][i] && Dp[a][i])
			a = Dp[a][i], b = Dp[b][i];
	return Dp[a][0];
}