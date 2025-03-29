#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 定义点的结构体
struct Point {
    int x, y;
};

// 计算点P到直线AB的距离
double distanceToLine(const Point& A, const Point& B, const Point& P) {
    return abs((B.x - A.x) * (A.y - P.y) - (A.x - P.x) * (B.y - A.y)) /
        sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

// 计算叉积，判断点C在向量AB的右侧、左侧或共线
int crossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

// 判断点C是否在向量AB的右侧
bool isRightOf(const Point& A, const Point& B, const Point& C) {
    return crossProduct(A, B, C) < 0;
}

// 快速凸包算法的部分实现
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
        else if (isRightOf(c, a, point)) {
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

    // 寻找极端点a和b
    sort(S.begin(), S.end(), [](const Point& p1, const Point& p2) {
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
        });

    Point a = S[0];
    Point b = S[S.size() - 1];

    vector<Point> A, B;

    // 筛选出右侧的点集A和B
    for (const auto& point : S) {
        if (isRightOf(b, a, point)) {
            A.push_back(point);
        }
        else if (isRightOf(a, b, point)) {
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

    // 调用凸包算法
    vector<Point> result = quick_hull(points);

    sort(points.begin(),points.end(),cmp);
    // 输出凸包顶点
    // cout << "Convex Hull Points:\n";
    for (const auto& point : result) {
        cout  << point.x <<' ' << point.y << endl;
    }

    return 0;
}
