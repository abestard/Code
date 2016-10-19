void Edmon_Karp( ){
	int nod, newn, flow[10005], P[10005];
	bool band;
	for( ; ; ){
		fill( flow, flow + 2 + 2*N, 0 );
		fill( P, P + 2 + 2*N, -1 );
		P[0] = 0, flow[0] = 1, band = false;
		while( !Q.empty() ) Q.pop();
		Q.push( 0 );
		while( !band && !Q.empty() ){
			nod = Q.front();  Q.pop();
			for( int i = Index[nod]; i != -1; i = G[i].next ){
				newn = G[i].newn;
				if( P[newn] != -1 || !G[i].cap  )
					continue;
				flow[newn] = min( G[i].cap, flow[nod] );
				P[newn] = i, Q.push( newn );
				if( newn == fin ){
					band = true; 
					break;
				}
			}
		}
		if( !flow[fin] ) break;
		sol += flow[fin];
		for( int i = fin; i != 0; i = G[P[i]].nod ){
			G[P[i]].cap -= flow[fin];
			G[P[i]^1].cap += flow[fin];
		}
	}
}