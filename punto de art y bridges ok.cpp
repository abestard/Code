//Bridges y Punto de Articulacion
void bridges_PtoArt ( int nod ){
    int newn;
    Td[nod] = low[nod] = ++ k;
    for( auto num : V[nod] ){
        newn = G[num].nextn( nod );
        if( G[num].band ) continue;
        G[num].band = true;
        if( Td[newn] ){
            low[nod] = min( low[nod], Td[newn] );
            continue;
        }
        bridges_PtoArt( newn );
        low[nod] = min( low[nod], low[newn] );

        if(Td[nod] < low[newn])
            puente.push(par( nod, newn ));

        if( (Td[nod] == 1 && Td[newn] > 2 ) ||
            ( Td[nod] != 1 && Td[nod] <= low[newn] ) )
            Punto_art[nod] = true;
    }
}
