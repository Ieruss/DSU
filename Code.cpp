struct DSU{
	int n;
	vector<int> p, sm;
	DSU(int _n){
		n = _n;
		p.resize(n+2);
		sm.resize(n+2, 1);
		for(int i = 1; i <= n; ++i){
			p[i] = i;
		}
	}
	int get(int v){
		if(v == p[v]){
			return v;
		}
		return p[v] = get(p[v]);
	}
	bool Union(int x, int y){
		x = get(x), y = get(y);
		if(x == y){
			return false;
		}
		if(sm[x] < sm[y]){
			swap(x, y);
		}
		sm[x] += sm[y];
		p[y] = x;
		return true;
	}
}; 
