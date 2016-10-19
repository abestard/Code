//LCS (n^2)
int lcs ( ){
   for ( int i = 1; i <= t1; i ++ )
      for ( int j = 1; j <= t2; j ++ )
          if ( cad1[i] == cad2[j] )
             Dp[i][j] = Dp[i-1][j-1]+1, P[i][j] = 'D';
          else
             if ( Dp[i-1][j] > Dp[i][j-1] )
                Dp[i][j] = Dp[i-1][j], P[i][j] = 'I';
             else
               Dp[i][j] = Dp[i][j-1], P[i][j] = 'S';
    return Dp[t1][t2];
}


