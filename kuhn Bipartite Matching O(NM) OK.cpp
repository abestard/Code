bool khun( int nodo ){
    if( mark[nodo] )
        return false;
    mark[nodo] = 1;
    int tam = V[nodo].size();
    for( int i = 0; i < tam; i++ ){
        int ady = V[nodo][i];
        if( ( match[ady] == -1 || khun(match[ady])) ){
            match[ady] = nodo;
            return true;
        }
    }
    return false;
}
void PreMatching() {
	for( int i = 1; i <= N; i++ ){
		for( int j = 0; j < (int)V[i].size(); j++ ){
			int ady  = V[i][j];
			if( match[ady] != -1 )
				continue;
			match[ady] = i;
			used[i] = true;
			break;
		}
	}
}
/// a -> N+b  N|W
int Bipartite_matchin( ){
  memset(match,-1,sizeof(int)*(N+W+1));
  PreMatching();
  int sol = 0;
  for( int i = 1; i <= N; i++ ){
     fill(mark,mark+N+1,false);
     if( used[i] ){
            sol++;
            continue;
     }
     if( khun(i) ) sol++;
  }
  return sol;
}