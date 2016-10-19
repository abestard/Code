//LIS-LDS
void write ( int ID ){
    if( !ID ) return;
    write ( Last[ID] );
    printf ("%d ", List[ID]);
}
void LIS_LDS( ){
    for ( int i = 1; i <= N; i ++ ){
        if ( Sol[m] <= List[i] ){
            Sol[++ m] = List[i];
            Id[m] = i;
            Last[i] = Id[m - 1];
        }
        else{
            up = upper_bound ( Sol + 1, Sol + m + 1, List[i] ) - Sol;
            Sol[up] = List[i];
            Id[up] = i;
            Last[i] = Id[up - 1];
        }
    }
    printf ("%d\n", m);
    write ( Id[m] );
}
