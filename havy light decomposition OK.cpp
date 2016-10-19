//Havy light decomposition 
/// cant- la cantidad de nodos
/// pos- la pos. donde aparece
/// nn- el nod en el cual aparece
/// pd- el link con el padre full superior
/// G-Dp
/// L-lazy
vector<int> G[MN], V[MN];
vector<bool> L[MN];
int cant[MN], pos[MN], nn[MN], pd[MN];
void Dfs( int nod, int pad ){
    int t = V[nod].size(), newn;
    if( t == 1 && nod != 1 ){
      pos[nod] = 0;
      nn[nod] = nod;
      cant[nod] = 1;
      pd[nod] = pad;
      return;
    }

    int mej = nod;
    for( int i = 0; i < t; i ++ ){
        newn = V[nod][i];
        if( newn == pad )
            continue;

        Dfs( newn, nod );
        if( cant[mej] < cant[nn[newn]] )
            mej = nn[newn];
    }

    pos[nod] = cant[mej];
    cant[mej] ++;
    nn[nod] = mej;
    pd[mej] = pad;
}
typedef pair<int, int> par;
typedef pair<int, par> tri;
typedef vector<tri> vt;
typedef vector<par> vp;
/// me da el recorrido desde a hasta b en vector<tri>
/// f posicion s.f in, s.f fin
vt rec( int a, int b ){
	vp A1, B1;
	A1.clear(), B1.clear();
	for( int i = a; i != -1; i = pd[nn[i]] )
        A1.push_back( par( nn[i], pos[i] ) );
	for( int i = b; i != -1; i = pd[nn[i]] )
        B1.push_back( par( nn[i], pos[i] ) );

	vt C1;
	C1.clear();
	reverse( A1.begin(), A1.end() );
	reverse( B1.begin(), B1.end() );
	int t = 0;
	while( t < (int)A1.size() && t < (int)B1.size() && A1[t] == B1[t] ) t ++;
	if( t >= (int)A1.size() || t >= (int)B1.size() || 
	( t < (int)B1.size() && t < (int)A1.size() && A1[t].first != B1[t].first ) )
		t --;
	if( (t <(int) A1.size() && t < (int)B1.size()) && A1[t].first == B1[t].first ){
      C1.push_back( tri( A1[t].first, par( min( A1[t].second, B1[t].second ), 
	                                  max( A1[t].second, B1[t].second ) ) ) );
      t ++;
	}
	for( int i = t; i <(int) A1.size(); i ++ )
		C1.push_back( tri( A1[i].first, par( A1[i].second, cant[A1[i].first] - 1 ) ) );
	for( int i = t; i < (int)B1.size(); i ++ )
		C1.push_back( tri( B1[i].first, par( B1[i].second, cant[B1[i].first] - 1 ) ) );
	return C1;
}
void havy_light( ){
	Dfs( 1, -1 ); // root
	for( int i = 1; i <= N; i ++ )/// rellenar con 4*cant
		if( cant[i] ){
			G[i] = vector<int> ( cant[i]*4, 0 );
			L[i] = vector<bool> ( cant[i]*4, false );
		}
}