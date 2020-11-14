struct PST {
    struct NODE {
        int l, r, val;
        NODE(): l(0), r(0), val(0) {}
    };
    NODE T[MAXN * 30];

    int sz = 0;

    int make(int y, int l, int r, int n) {
        if(r < y || y < l) return n;
        int cur = ++sz;
        T[cur] = T[n];
        if(l != r) {
            int mid = l + r >> 1;
            T[cur].l = make(y, l, mid, T[n].l);
            T[cur].r = make(y, mid+1, r, T[n].r);
        }
        T[cur].val++;
        return cur;
    }

    int query(int x, int y, int l, int r, int nx, int ny) {
        if(r < x || y < l) return 0;
        if(x <= l && r <= y) return T[ny].val - T[nx].val;
        int mid = l + r >> 1;
        return query(x, y, l, mid, T[nx].l, T[ny].l) + 
            query(x, y, mid+1, r, T[nx].r, T[ny].r);
    }
} pst;