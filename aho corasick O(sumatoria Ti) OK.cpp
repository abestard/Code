//Aho Corasick
const int alph = 26;
struct tree {
    int parent, slink;
    bool band;
    int hij[30];
    tree( int p ){
        parent = p, slink = 0, band = false;
        fill( hij, hij + 30, -1 );
    }
};
vector<tree> trie;
void addWord( string s1 ){
    int root = 0;
    for( int i = 0; i < (int)s1.length(); i ++ ){
        if( trie[root].hij[s1[i] - 'a'] == -1 ){
            trie[root].hij[s1[i] - 'a'] = trie.size();
            trie.push_back( tree( root ) );
        }
        root = trie[root].hij[s1[i] - 'a'];
    }
    trie[root].band = true;
}
queue<int> Q;
void buildSuffixLinks(  ){
     int nod, nextC;
     Q.push( 0 );
     Q.push( 0 );
  while( !Q.empty() ){
    nod = Q.front(), Q.pop();
    nextC = Q.front(), Q.pop();
    for( int i = 0; i <= alph; i ++ )
        if( trie[nod].hij[i] != -1 ){
            Q.push( trie[nod].hij[i] );
            Q.push( i );
        }
    if( nod == 0 || trie[0].hij[nextC] == nod )
        continue;
    int& link = trie[nod].slink;
    link = trie[trie[nod].parent].slink;
    while( link != 0 && trie[link].hij[nextC] == -1 )
        link = trie[link].slink;
    link = trie[link].hij[nextC];
    if( link == -1 )
        link ++;
    if( trie[link].band )
        trie[nod].band = true;
  }
}
int go( int nod, char c ){
    if( nod == 0 )
        return trie[0].hij[c - 'a'];
    if( trie[nod].hij[c - 'a'] != -1 )
        return trie[nod].hij[c - 'a'];
    int link = trie[nod].slink;
    while( link != 0 && trie[link].hij[c-'a'] == -1 )
        link = trie[link].slink;
    return trie[link].hij[c-'a'];
}
int automata[10005][30], N, M;
void Aho_Corasick( ){
    string tmp;
    cin >> N >> M;
    trie.clear();
    trie = vector<tree> ( 1, tree(0) );
    for( int i = 1; i <= M; i ++ ){
        cin>>tmp;
        addWord( tmp );
    }
    buildSuffixLinks( );
    for( int j = 0; j < (int)trie.size(); j ++ )
        for( int h = 'a'; h <= 'z'; h ++ )
            automata[j][h-'a'] = go( j, h );
}
