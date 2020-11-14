int szdfs(int cur, int par) {
    sz[cur] = 1;
    for(int nxt : G[cur]) if(nxt != par && !del[nxt]) sz[cur] += szdfs(nxt, cur);
    return sz[cur];
}

int cdfs(int cur, int par, int cap) {
    for(int nxt : G[cur]) if(nxt != par && !del[nxt] && sz[nxt] > cap)
        return cdfs(nxt, cur, cap);
    return cur;
}

void decompose(int root, int par) {
    int cap = szdfs(root, par);
    int cen = cdfs(root, par, cap / 2);
    del[cen] = 1;
    p[cen] = par;
    for(int i : G[cen]) if(!del[i]) decompose(i, cen);
}