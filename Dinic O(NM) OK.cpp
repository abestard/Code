//Dinic(N*M)
int lv[2005], Id[2005];
bool Bfs( int limt ){
	while( !Q.empty() ) Q.pop();
	fill( lv, lv + 2001, 0);
	lv[0] = 1;
	Q.push( 0 );

	int nod, newn;
	while( !Q.empty() ) {
		nod = Q.front();
		Q.pop();
		for( int i = Index[nod]; i != -1; i = G[i].next ){
			newn = G[i].newn;
			if( lv[newn] != 0 || G[i].cap < limt )continue;
			lv[newn] = lv[nod] + 1;
			Q.push( newn );
			if( newn == fin ) return true;
		}
	}
	return false;
}
bool Dfs( int nod, int limt ){
	if( nod == fin ) return true;
	int newn;
	for( ; Id[nod] != -1; Id[nod] = G[Id[nod]].next ){
		newn = G[Id[nod]].newn;
		if( lv[nod] + 1 == lv[newn] && G[Id[nod]].cap >= limt && Dfs( newn, limt ) ){
			G[Id[nod]].cap -= limt;
			G[Id[nod]^1].cap += limt;
			return true;
		}
	}
	return false;
}
int Dinic( ){
	int flow = 0;
	for( int limt = 4; limt > 0;  ){
		if( !Bfs( limt ) ){
			limt >>= 1;
			continue;
		}

		for( int i = 0; i <= fin; i ++ )
			Id[i] = Index[i];

		while( limt > 0 && Dfs( 0, limt ) )
			flow += limt;
	}
	return flow;
}