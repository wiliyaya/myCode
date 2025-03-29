#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// 计算点P到直线AB的距离
double distanceToLine(const Point& A, const Point& B, const Point& P) {
    return abs((B.x - A.x) * (A.y - P.y) - (A.x - P.x) * (B.y - A.y)) /
        sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

// 修正后的叉积计算：向量AB × 向量AC
int crossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// 判断点C是否在向量AB的右侧（叉积为负）
bool isRightOf(const Point& A, const Point& B, const Point& C) {
    return crossProduct(A, B, C) < 0;
}

vector<Point> quick_half_hull(vector<Point>& S, const Point& a, const Point& b) {
    if (S.empty()) return {};

    double maxDist = -1;
    Point c;
    for (const auto& point : S) {
        double dist = distanceToLine(a, b, point);
        if (dist > maxDist) {
            maxDist = dist;
            c = point;
        }
    }

    vector<Point> A, B;

    // 筛选出右侧的点集A和B
    for (const auto& point : S) {
        if (isRightOf(b, c, point)) {
            A.push_back(point);
        }
        if (isRightOf(c, a, point)) {
            B.push_back(point);
        }
    }

    vector<Point> QA = quick_half_hull(A, a, c);
    vector<Point> QB = quick_half_hull(B, c, b);

    vector<Point> result;
    result.insert(result.end(), QA.begin(), QA.end());
    result.push_back(c);
    result.insert(result.end(), QB.begin(), QB.end());

    return result;
}

vector<Point> quick_hull(vector<Point>& S) {
    if (S.size() < 3) return S;

    sort(S.begin(), S.end(), [](const Point& p1, const Point& p2) {
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
        });

    Point a = S[0];
    Point b = S.back();

    vector<Point> A, B;

    // 修正筛选条件：A为ab右侧的点，B为ab左侧的点
    for (const auto& point : S) {
        if (isRightOf(a, b, point)) {
            A.push_back(point);
        } else if (isRightOf(b, a, point)) {
            B.push_back(point);
        }
    }

    vector<Point> QA = quick_half_hull(A, a, b);
    vector<Point> QB = quick_half_hull(B, b, a);

    vector<Point> result;
    result.push_back(a);
    result.insert(result.end(), QA.begin(), QA.end());
    result.push_back(b);
    result.insert(result.end(), QB.begin(), QB.end());

    // 去重
    auto last = unique(result.begin(), result.end(), [](const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
        });
    result.erase(last, result.end());

    return result;
}
bool cmp(Point& a,Point & b ){
  if(a.x==b.x){
    return a.y<b.y;
  }
  return a.x<b.x;
}

int main() {
  vector<Point> points;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    Point p;
    cin>>p.x>>p.y;
    points.push_back(p);
  }
    vector<Point> result = quick_hull(points);

    // cout << "Convex Hull Points:\n";
    sort(result.begin(),result.end(),cmp);
    for (const auto& point : result) {
        cout<< point.x << " " << point.y << "\n";
    }

    return 0;
}