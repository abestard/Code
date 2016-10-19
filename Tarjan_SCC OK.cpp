//Tarjan SCC
void Tarjan_SCC( int nod ){
	int newn;
	vector<int>::iterator it;
	Td[nod] = low[nod] = ++ k;
	P.push( nod );

	for(it = V[nod].begin(); it != V[nod].end(); it ++){
		newn = *it;

		if( Td[newn] ){
			if( !mark[newn] )
				low[nod] = min( low[nod], Td[newn] );
			continue;
		}

		Tarjan_SCC( newn );
		low[nod] = min( low[nod], low[newn] );
	}

	if( low[nod] == Td[nod] ){
		sol ++;
		while( !mark[nod] )
		{
			printf("%d ", (int)P.top());
			mark[(int)P.top()] = true;
			P.pop();
		}
	}
}