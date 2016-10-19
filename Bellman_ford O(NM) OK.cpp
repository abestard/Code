//Bellman Ford O(NM)
double Bellman_Ford(  ){
 double newc;
 int nod, newn;
 fill( dist + 1, dist + 1 + N, maxint );
 fill( parent + 1, parent + 1 + N, -1 );
 dist[In] = D, parent[In] = 1 << 30;
 for( int i = 1; i < N; i ++ )
  for( int j = 1; j <= M; j ++ ){
     nod = G[j].nod, newn = G[j].newn;
     newc = dist[nod] * G[j].cost;

     if( dist[newn] > newc ){
      dist[newn] = newc;
      parent[newn] = nod;
     }
    }
 if( parent[Fin] == -1 )
  return 0;
 for( int j = 1; j <= M; j ++ ){
     nod = G[j].nod, newn = G[j].newn;
     newc = dist[nod] * G[j].cost;

     if( dist[newn] > newc )
        return 0;//se encontro un ciclo negativo
    }
  return dist[Fin];
}