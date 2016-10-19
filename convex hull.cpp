#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;

namespace std {
  bool operator < (const point& a, const point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

double cross(const point& a, const point& b) {
  return imag(conj(a)*b);
}

double dot(const point& a, const point& b) {
  return real(conj(a)*b);
}

int ccw(point a, point b, point c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

vector<point> convex_hull(vector<point> ps) {
  int n = ps.size(), k = 0;
  sort( ps.begin(), ps.end() );
  vector<point> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k);
  return ch;
}


int main()
{
    #ifdef acm
    freopen("a.in", "r", stdin);
    #endif // acm

    cin.tie();
    ios_base::sync_with_stdio(false);

    int T, N, tmp;
    double a, b;
    vector<point> V, S;

    cin >> T;

    cout << T << '\n';

    for( int h = 1; h <= T; h ++ ){
        cin >> N;
        V.clear();

        for( int i = 1; i <= N; i ++ ){
            cin >> a >> b;
            V.push_back( point( b, a ) );
        }

        S = convex_hull( V );
        tmp = S.size();
        cout << tmp << '\n';
        for( int i = tmp-1; i >= 0; i -- ){
          cout << S[i].imag() << ' ' <<S[i].real() << '\n';
        }

        if( h != T ){
            cin >> tmp;
            cout << tmp << '\n';
        }
    }

    return 0;
}
