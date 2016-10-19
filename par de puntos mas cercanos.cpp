#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;

namespace std {
  bool operator < (const point& a, const point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

pair<point,point> closestPair(vector<point> p) {
  int n = p.size(), s = 0, t = 1, m = 2, S[n]; S[0] = 0, S[1] = 1;
  sort(p.begin(), p.end()); // "p < q" <=> "p.x < q.x"
  double d = norm(p[s]-p[t]);
  for (int i = 2; i < n; S[m++] = i++)
   for(int j = 0; j < m; j ++){
    if (norm(p[S[j]]-p[i])<d) d = norm(p[s = S[j]]-p[t = i]);
    if (real(p[S[j]]) < real(p[i]) - d) S[j--] = S[--m];
  }
  return make_pair( p[s], p[t] );
}



int main()
{
    #ifdef acm
    freopen("a.in", "r", stdin);
    #endif // acm

    cin.tie();
    ios_base::sync_with_stdio(false);

    int T;
    double a, b;
    vector<point> V;
    pair <point, point> S;

    while( scanf("%d", &T) && T ){
        V.clear();
        for( int i = 1; i <= T; i ++ ){
            scanf("%lf%lf", &a, &b);
            V.push_back( point( a, b ) );
        }

        S = closestPair(V);

        a = sqrt( norm(S.first-S.second) );

        if( a < 10000 )
           printf("%.4lf\n", a);
        else
           printf("INFINITY\n");
    }

    return 0;
}
