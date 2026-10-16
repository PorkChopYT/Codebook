// 0-indexed

struct point {
    ll x, y;

    bool operator < (const point &b) const {
        if (x != b.x) return x < b.x;
        return y < b.y;
    }

    bool operator == (const point &b) const {
        return x == b.x && y == b.y;
    }
};

ll cross(point a, point b, point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

vector<point> convex_hull(vector<point> p){ // usage: random points in vector
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    if (n <= 2) return p;
    bool collinear = true;
    for (int i = 2; i < n; i++) {
        if (cross(p[0], p[1], p[i]) != 0) {
            collinear = false;
            break;
        }
    }
    if (collinear) return p;

    vector<point> lo, up;

    // Lower hull
    for (auto pt : p) {
        // change to cross <= 0 to exclude points on the same line
        while (lo.size() >= 2 && cross(lo[lo.size()-2], lo.back(), pt) < 0)
            lo.pop_back();
        lo.push_back(pt);
    }
    // Upper hull
    for (int i = n-1; i >= 0; i--) {
        // change to cross <= 0 to exclude points on the same line
        while (up.size() >= 2 && cross(up[up.size()-2], up.back(), p[i]) < 0)
            up.pop_back();
        up.push_back(p[i]);
    }
    lo.pop_back();
    up.pop_back();
    lo.insert(lo.end(), up.begin(), up.end());
    return lo;
}