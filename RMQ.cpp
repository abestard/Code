//RMQ
void build_rmq( ){
    for(int i = 0; i < N; i ++) M[i][0] = i;
    for(int j = 1; ( 1 << j ) < N; j ++ )
        for(int i = 0; i+(1<<(j-1)) < N; i ++ )
            if( arr[ M[i][j-1] ] <= arr[ M[i+(1<<(j-1))][j-1] ])
                M[i][j] = M[i][j-1];
            else M[i][j] = M[i+(1<<(j-1))][j-1];
}
int query_rmq( int x, int y ){
    int lg = log2( y - x + 1 );
    if( arr[ M[x][lg] ] <= arr[M[y-(1<<lg)+1][lg] ])
        return M[x][lg];
    else return M[y-(1<<lg)+1][lg];
}
