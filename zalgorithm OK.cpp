//Z-Algorithm
void Z_algorithm( ){
 int L = 0, R = 0, k;
 for (int i = 1; i < n; i++){
  if( i <= R && z[i-L] < R-i+1 )
   z[i] = z[i-L];
  else{
   L = i, R = max( R, i );
   while( R < n && s[R-L] == s[R] )
    R ++;
   z[i] = R - L;
   R --;
  }
 }
}