#define MAXN 4000000
int tree[MAXN][26], fail[MAXN];
int termina[MAXN], size = 1;
void addWord( string pal ){
    int p = 0, c;
    for(char c : pal){
        if( !tree[p][c-'a'] )
            tree[p][c-'a'] = size++;
        p = tree[p][c-'a'];
    }
    ///termina[p].push_back( pal_id );
    termina[p] = pal.size();
}
void buildersuffix(){
    queue<int> Q;
    for(int i = 0; i < 26; i++)
        if( tree[0][i] ) Q.push(tree[0][i]);
    while( !Q.empty() ){
        int u, v = Q.front(); Q.pop();
        ///for(int i = 0; i < termina[fail[v]].size(); i ++)
        ///    termina[v].push_back( termina[fail[v]][i] );
        termina[v] = max( termina[v], termina[fail[v]] );
        for( int i = 0; i < 26; i++ )
            if(u = tree[v][i]){
                fail[u] = tree[fail[v]][i];
                Q.push( u );
            }
            else
                tree[v][i] = tree[fail[v]][i];
    }
}
