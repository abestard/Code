priority_queue<par, vector<par>, greater<par> >Qp;
par Max_Flow_Min_Cost( ){
	int FlowF = 0, CostF = 0, F[1005], parent[1005];
    int	nod, newn, newc, flow, dist[1005], cost;
	for( ; ; ){
		fill( F + 1, F + 1 + Fin, 0 );
		fill( dist + 1, dist + 1 + Fin, 1 << 30 );
		F[In] = 1 << 30, dist[In] = 0;
		while( !Qp.empty() ) Qp.pop();
		Qp.push( par( 0, In ) );
		while( !Qp.empty() ){
			nod = Qp.top().second, cost = Qp.top().first;
			Qp.pop();
			if( nod == Fin ) break;
			flow = F[nod];
			for( int i = Index[nod]; i != -1; i = G[i].next ){
				newn = G[i].newn;
				newc = cost + G[i].cost;
				if( G[i].cap > 0 && dist[newn] > newc ){
					dist[newn] = newc;
					F[newn] = min( flow, G[i].cap );
					parent[newn] = i;
					Qp.push( par( newc, newn ) );
				}
			}
		}
		if( F[Fin] <= 0 ) break;
		CostF += dist[Fin]*F[Fin];
		FlowF += F[Fin];
		nod = Fin;
		while( nod != In ){
			G[parent[nod]].cap -= F[Fin];
			G[parent[nod]^1].cap += F[Fin];
			nod = G[parent[nod]].nod;
		}
	}
	return par( CostF, FlowF );
}
