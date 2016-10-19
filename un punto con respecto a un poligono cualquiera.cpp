#include <bits/stdc++.h>

using namespace std;

int N1, T, M;
typedef complex<double> point;
point cord[1005];

 double cross (const point & a, const point & b) {
   return imag (conj (a) * b);
 }

 double dot (const point & a, const point & b) {
   return real (conj (a) * b);
 }

#define curr(P,i) P[i]
#define next(P,i) P[(i + 1)% N]
enum {OUT, ON, IN};
int contains ( point *polygon, int N, point p) {
   bool in = false;
   for (int i = 0; i <N; ++i) {
     point a = curr( polygon, i ) - p, b = next( polygon, i ) - p;
     if (imag(a)> imag(b)) swap(a, b);
     if (imag(a) <= 0 && 0 <imag(b))
       if (cross(a, b) <0) in =! in;
     if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
   }
   return in? IN: OUT;
}

int main()
{
 //freopen("a.in","r",stdin);

 cin.tie();
 ios_base::sync_with_stdio(false);

 cin >> T;

 point punt;
 while( T -- ){
    cin >> N1 >> M;

    int a, b;
    for(int i = 0; i < N1; i ++){
        cin >> a >> b;
        cord[i].imag( b );
        cord[i].real( a );
    }

    int sol = 0;
    for(int i = 1; i <= M; i ++)
    {
        cin >> a >> b;
        punt.imag( b );
        punt.real( a );

        a = contains( cord, N1, punt );

        if( a == 2 ) sol ++;
    }

    cout << sol <<'\n';
 }


        return 0;
}
