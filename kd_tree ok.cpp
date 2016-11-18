#include<bits/stdc++.h>

using namespace std;

int N, M;
	typedef pair<int, int> par;
	bool comp1( const par &s1, const par &s2 ){
		return s1.first < s2.first;
	}
	bool comp2( const par &s1, const par &s2 ){
		return s1.second < s2.second;
	}
	inline long long dist( par a, par b ){
		return 1ll*(a.first - b.first)*(a.first - b.first) + 1ll*(a.second - b.second)*(a.second - b.second);
	}
	par G[100005];
	long long sol;
	struct kd{
		kd *l, *r;
		par v;
		kd( ){ l = r = NULL; }
	}root;
	void build_Kd_tree( int lv, int in, int fin, kd *nod ){
		if( lv ) sort( G+in, G+fin+1, comp1 );
		else sort( G+in, G+fin+1, comp2 );
		int mit = (in+fin)>>1;
		nod->v = G[mit];
		if( in < mit ){
			nod->l = new kd();
			build_Kd_tree( lv^1, in, mit-1, nod->l );
		}
		if( mit < fin ){
			nod->r = new kd();
			build_Kd_tree( lv^1, mit+1, fin, nod->r );
		}
	}
	void query_kd_tree( int lv, kd *nod, par p ){
		sol = min( sol, dist( p, nod->v ) );
		long long tmp = (lv == 1)?  p.first - nod->v.first: 
		                            p.second - nod->v.second;
		if ( tmp < 0 ) {
			if ( nod->l ) 
				query_kd_tree ( lv^1, nod->l, p );
			if ( nod->r && tmp*tmp < sol )
				query_kd_tree ( lv^1, nod->r, p );
		} else {
			if ( nod->l && tmp*tmp < sol )
				query_kd_tree ( lv^1, nod->l, p );
			if ( nod->r ) 
			    query_kd_tree ( lv^1, nod->r, p );
		}
	}

int main(){
  #ifdef acm
  freopen("a.in", "r", stdin);
  #endif // acm


  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;

  for( int i = 1; i <= N; i ++ )
    cin >> G[i].first >> G[i].second;

  build_Kd_tree( 1, 1, N, &root );

  int a, b;

  for( int i = 1; i <= M; i ++ ){
    cin >> a >> b;

    sol=1ll<<50;
    query_kd_tree( 1, &root, par( a, b ) );
    cout << fixed << setprecision(2) << 1.0*sqrt(sol) << '\n';
  }


	return 0;
}
