int pos, Index[10005];///index = -1
struct edges{
 int nod, newn, cap, cost, next;
 bool band;
 edges( int a = 0, int b = 0, int c = 0, int d = 0, int e = 0 ){
  nod = a, newn = b, cap = c, cost = d, next = e;
 }
 int nextn ( int a ){
  if( nod == a )
   return newn;
  return nod;
 }
}G[100005];

///nod, newn, cap, cost
void insertar( int a, int b, int c, int d = 0 ){
 G[pos] = edges( a, b, c, d, Index[a] );
 Index[a] = pos ++;
 G[pos] = edges( b, a, 0, -d, Index[b] );
 Index[b] = pos ++;
}