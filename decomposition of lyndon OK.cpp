/// decomposition of lyndon  s = w1w2w3..wk, w1 >= w2 >=...>= wk.
void lyndon( string s ){
    int n = (int)s.length(), i = 0;
    while( i < n ){
        int j = i+1, k = i;
        while( j < n && s[k] <= s[j] ){
            if( s[k] < s[j] ) k = i;
            else k ++;
            j ++;
        }
        while( i <= k ){
            cout << s.substr( i, j-k )<<endl; /// lyndon descomp
            i += j-k;
        }
    }
}
