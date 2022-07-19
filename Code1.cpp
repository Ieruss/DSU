struct Dsu {
	int n;
	vector<int> p, sm;
	
	Dsu(int _n) : n(_n){
		p.resize(n + 1, -1);
		sm.resize(n + 1, 1);
	}
	
	int get(int v) {
		return (p[v] < 0 ? v : p[v] = get(p[v]));
	}
	
	bool Unite(int x, int y) {
		if ((x = get(x)) == (y = get(y))) {
			return false;
		}
		
		if (sm[x] < sm[y]) {
			swap(x, y);
		}
		
		sm[x] += sm[y];
		p[y] = x;
		return true;
	}
};
