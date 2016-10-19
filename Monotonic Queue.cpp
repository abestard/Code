//Monotonic Queue
typedef long long i64;
struct monotonic_queue {
    deque< pair<int, i64> > D;
    void add( int p, i64 v ){
        while( !D.empty() && D.front().second <= v )
            D.pop_front();
        D.push_front({p, v});
    }
    void borrar( int x ){
        while( !D.empty() && D.back().first <= x )
            D.pop_back();
    }
    i64 maximo( ){ return D.back().second; }
};
