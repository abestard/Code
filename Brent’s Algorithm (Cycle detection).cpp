//O(u+l) Fµ(x0) = Fµ+l(x0)
par cycle_detaction( ){
	int p = 1, l = 1, t = x0, h = f(x0), u;
	while (t != h){
		if (p == l) t = h, p*= 2, l = 0;
		h = f(h), ++l;
	}
	u = 0, t = h = x0;
	for (i = l; i != 0; --i) h = f(h);
	while (t != h) t = f(t), h = f(h), ++u;
	return par( u, l );
}
