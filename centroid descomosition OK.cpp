// Centroid descomposition
#define MAXN 100005
bool mark[MAXN];
int cant[MAXN], timer;
void Dfs( int nod, int pad ){
    cant[nod] = 1;
    for( auto i:V[nod] )
        if( i.first != pad && !mark[i.first] ){
            Dfs( i.first, nod );
            cant[nod] += cant[i.first];
        }
}
int centroid( int nod, int pad, int nn ){
    for( auto i:V[nod] )
        if( i.first != pad && !mark[i.first] && cant[i.first] > nn/2 )
            return centroid( i.first, nod, nn );
    return nod;
}
long long solve( int nod, int pad ){
    Dfs( nod, pad );
    int centr = centroid( nod, pad, cant[nod] );
    long long sol = 0;
    mark[centr] = true;
    timer ++;
    for( auto i : V[centr] )
        if( i.first != pad && !mark[i.first] ){
            sol += query( i.first, centr, i.second );
            updater( i.first, centr, i.second );
        }
    for( auto i : V[centr] )
        if( i.first != pad && !mark[i.first] )
            sol += solve( i.first, centr );
    return sol;
}
