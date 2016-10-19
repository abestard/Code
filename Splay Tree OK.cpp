struct splay_tree{
    const int inf = 1e9;
	struct nodo {
		int size, cant[30];
		nodo *l, *r, *p;
		bool inv;
		int laz, let;
		nodo(nodo *f=0, nodo *i = 0, nodo *d = 0){
		    l = i, p = f, r = d, size = 1, let = 0, laz = -1, inv = false;
			for(int i=0; i<30; i++) cant[i]=0;
		}
	} *root;
    splay_tree(){ root = NULL; }
    inline void zig(nodo *x) {
		nodo *y = x->p, *z = y->p;
		y->l = x->r;
		if( x->r )
		 x->r->p = y;
		x->p = z;
		if( z )
		  if (z->l == y)z->l = x; else z->r = x;
		y->p = x, x->r = y;
		updata(y);
	}
	inline void zag(nodo *x) {
		nodo *y = x->p, *z = y->p;
		y->r = x->l;
		if( x->l )
		 x->l->p = y;
		x->p = z;
		if( z )
		  if (z->l == y)z->l = x; else z->r = x;
		y->p = x, x->l = y;
		updata(y);
	}
	inline void splay(nodo *x) {
		for (; x->p ;) {
			nodo *y = x->p, *z = y->p;
			if (!z) {
				if (y->l == x) zig(x); else zag(x);
			} else {
				if (z->l == y){
					if (y->l == x)	zig(y), zig(x);
					else zag(x), zig(x);
				}
				else if (y->r == x) zag(y), zag(x);
				else zig(x), zag(x);
			}
		}
		root = x, updata(root);
	}
	void find(int x) {
		if(!root)return;
		nodo *p = root;
		for( ; ; ) {
			lazy( p );
			int izq = (p->l)?p->l->size:0;
			if (x == izq + 1) break;
			if (x > izq + 1){
				x -= izq + 1;
				if ( p->r ) p = p->r; else break;
			}
			else
			  if ( p->l ) p = p->l; else break;
		}
		splay(p);
	}
	inline void insertpos( int a, int b ){
	  nodo *nn = new nodo( 0, 0, 0 );
      nn->let = b;
	  find( a );
	  if( !root ){ root = nn, updata(root); return; }
      nodo *p = root;
      root = root->r;
      if( root ) root->p = 0;
      p->r = nn, nn->p = p;
      find( -inf );
      nn->r = root;
      if( root )
       root->p = nn;
      root = p;
      updata(nn), updata(root);
      int ui = 0;
	}
	inline void insert(int a) {
		nodo *p = root, *f=0;
		while(p){ f=p; p = p->r; }
		p = new nodo(f, 0, 0);
		p->let = a;
		if( f )
		 f->r = p;
		splay(p);
	}
	inline splay_tree split(int x){
		if(!root)return splay_tree();
		splay_tree L = splay_tree();
		find(x);
		if( root->l )
		 root->l->p=0;
		L.root = root->l, root->l=0;
		updata(root);
		return L;
	}
	inline void join(splay_tree L){
	    if( !L.root ) return;

		if(!root) root = L.root;
		else{
			find(-inf);
			root->l = L.root, root->l->p = root;
			updata(root);
		}
		L.root = NULL;
	}
	void print(nodo *r){
		if(r == NULL)return;
		lazy(r);
		print(r->l);
		printf("%c ", r->let);
		print(r->r);
	}
	void erase(int x) {
		find(x);
		if(!root)return;

		if (!root->l) {
			nodo *tmp = root;
			root = root->r;
			if(root)
              root->p = 0;
			delete tmp;
		} else {
			nodo *t = root->r, *tmp = root;
			root = root->l;
			if(root)root->p = 0;
			find(x);
			if(root)root->r = t;
			if( t ) t->p = root;
			updata(root);
			delete tmp;
		}
	}
	void clear( nodo*x ){
	    if( x ) return;
     	clear( x->l );
     	clear( x->r );
     	delete x;
	}
	inline void updata(nodo *x) {
		x->size = ((x->l)?x->l->size:0) + ((x->r)?x->r->size:0) + 1;
		for(int i = 0; i < 30; i ++)
			x->cant[i] = ((x->l)?x->l->cant[i]:0) + ((x->r)?x->r->cant[i]:0) + (x->let == i );
	}
	inline void lazy(nodo *p){
		if(!p)return;
		if(p->inv){
			swap(p->r, p->l);
			if( p->r ) p->r->inv = !p->r->inv;
			if( p->l ) p->l->inv = !p->l->inv;
			p->inv=0;
		}
		if(p->laz!=-1){
			updlazy(p->l, p->laz);
			updlazy(p->r, p->laz);
			p->laz = -1;
		}
	}
	inline void updlazy(nodo *p, int laz){
	    if( !p ) return;
		p->laz = laz;
		for(int i=0; i<30; i++)
		  if(i==p->laz)	p->cant[i] = p->size;
		  else p->cant[i] = 0;
		p->let = laz;
	}
	void solve(char opt, int a, int b, int c = 0 ){
		splay_tree t1 = split( a );
		splay_tree t = split( b - a + 2 );

		if(opt=='S') t.updlazy(t.root, c);
        else if( opt == 'R' ) t.root->inv = ( !t.root->inv );
 		else printf("%d\n", t.root->cant[c]);

		join(t);
		join(t1);
	}
}ST;
