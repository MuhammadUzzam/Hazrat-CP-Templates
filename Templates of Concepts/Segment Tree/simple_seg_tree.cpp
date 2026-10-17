struct node {
    int sum;
    node() {
        sum = 0;
    }
};
node seg[4 * 200200];
int a[200200];
node merge(node left, node right) {
    node ans;
    ans.sum = (left.sum & right.sum);
    return ans;
}
void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind].sum = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * ind, low, mid);
    build(2 * ind + 1, mid + 1, high);
    seg[ind] = merge(seg[2 * ind], seg[2 * ind + 1]);
}
node query(int ind, int low, int high, int lq, int rq) {
    if (rq < low || high < lq) {
        node ans;
        ans.sum=LLONG_MAX;	// this is use when you want to find bitwise AND of intervals
        return ans;
    }
    if (lq <= low && high <= rq) {
        return seg[ind];
    }
    int mid = (low + high) >> 1;
    return merge(
        query(2 * ind, low, mid, lq, rq),
        query(2 * ind + 1, mid + 1, high, lq, rq)
    );
}