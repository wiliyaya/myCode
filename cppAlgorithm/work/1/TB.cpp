#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point p;
    int prev;
    int next;
};

bool areCollinear(const vector<Point>& points) {
    if (points.size() <= 2) return true;
    int dx = points[1].x - points[0].x;
    int dy = points[1].y - points[0].y;
    for (size_t i = 2; i < points.size(); ++i) {
        int cross = dx * (points[i].y - points[0].y) - dy * (points[i].x - points[0].x);
        if (cross != 0) return false;
    }
    return true;
}

vector<Point> getCollinearEndpoints(const vector<Point>& points) {
    vector<Point> sorted = points;
    sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    return {sorted.front(), sorted.back()};
}

vector<Point> findThreeNonCollinearPoints(const vector<Point>& points) {
    int n = points.size();
    Point p0 = points[0], p1 = points[1];
    int dx = p1.x - p0.x, dy = p1.y - p0.y;
    for (int i = 2; i < n; ++i) {
        Point p2 = points[i];
        int cross = dx * (p2.y - p0.y) - dy * (p2.x - p0.x);
        if (cross != 0) return {p0, p1, p2};
    }
    return {};
}

Point computeX(const vector<Point>& threePoints) {
    int sum_x = 0, sum_y = 0;
    for (const auto& p : threePoints) {
        sum_x += p.x;
        sum_y += p.y;
    }
    return {sum_x / 3, sum_y / 3};
}

Point X;

bool compare(const Point& a, const Point& b) {
    int dx1 = a.x - X.x, dy1 = a.y - X.y;
    int dx2 = b.x - X.x, dy2 = b.y - X.y;
    int cross = dx1 * dy2 - dx2 * dy1;
    if (cross) return cross > 0;
    return (dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2);
}

int main() {
    int n; cin >> n;
    vector<Point> points(n);
    for (int i=0; i<n; ++i) cin >> points[i].x >> points[i].y;

    if (n == 1) {
        cout << points[0].x << " " << points[0].y << endl;
        return 0;
    }
    if (n == 2) {
        if (points[0].x != points[1].x || points[0].y != points[1].y) {
            vector<Point> temp = points;
            sort(temp.begin(), temp.end(), [](Point a, Point b) {
                return a.x < b.x || (a.x == b.x && a.y < b.y);
            });
            cout << temp[0].x << " " << temp[0].y << endl;
            cout << temp[1].x << " " << temp[1].y << endl;
        } else {
            cout << points[0].x << " " << points[0].y << endl;
        }
        return 0;
    }

    if (areCollinear(points)) {
        vector<Point> ends = getCollinearEndpoints(points);
        ends.erase(unique(ends.begin(), ends.end()), ends.end());
        sort(ends.begin(), ends.end(), [](Point a, Point b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
        for (auto& p : ends) cout << p.x << " " << p.y << endl;
        return 0;
    }

    vector<Point> three = findThreeNonCollinearPoints(points);
    X = computeX(three);
    sort(points.begin(), points.end(), compare);

    vector<Node> nodes(n);
    for (int i=0; i<n; ++i) {
        nodes[i].p = points[i];
        nodes[i].prev = (i-1 + n) % n;
        nodes[i].next = (i+1) % n;
    }

    int p = 0;
    for (int i=1; i<n; ++i) {
        if (points[i].y < points[p].y || (points[i].y == points[p].y && points[i].x > points[p].x))
            p = i;
    }

    int x = p, rx = nodes[x].next;
    bool changed;
    do {
        changed = false;
        while (true) {
            if (rx == p) break;
            int rrx = nodes[rx].next;
            Point a = nodes[x].p, b = nodes[rx].p, c = nodes[rrx].p;
            int cross = (b.x - a.x)*(c.y - b.y) - (b.y - a.y)*(c.x - b.x);
            if (cross <= 0) {
                int prev_rx = nodes[rx].prev, next_rx = nodes[rx].next;
                nodes[prev_rx].next = next_rx;
                nodes[next_rx].prev = prev_rx;
                if (x == prev_rx) {
                    rx = next_rx;
                } else {
                    rx = x;
                    x = nodes[rx].prev;
                }
                changed = true;
            } else {
                x = rx;
                rx = rrx;
            }
        }
        x = p;
        rx = nodes[x].next;
    } while (changed);

    vector<Point> hull;
    int current = p;
    do {
        hull.push_back(nodes[current].p);
        current = nodes[current].next;
    } while (current != p);

    sort(hull.begin(), hull.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    hull.erase(unique(hull.begin(), hull.end()), hull.end());

    for (auto& pt : hull) cout << pt.x << " " << pt.y << endl;

    return 0;
}