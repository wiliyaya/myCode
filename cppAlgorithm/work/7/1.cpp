#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> a;
ll p;
class Linetree{
public:
  vector<ll> sum;
  vector<ll> lazy_add;
  vector<ll> lazy_multiply; // 懒标记数组，用于乘法懒标记
  ll size;

  Linetree(ll n) : size(n) {
    sum.resize(4 * n, 0);
    lazy_add.resize(4 * n, 0);
    lazy_multiply.resize(4 * n, 1); // 初始化懒乘法标记为1
  }
  void build(ll l,ll r,ll i){
    if(l==r){
      sum[i]=a[l];
    }else {
      ll mid=(l+r)>>1;
      build(l,mid,i<<1);
      build(mid+1,r,i<<1|1);
      up(i);
    }
  }

  void Lazy_add_up(ll i,ll v,ll n){
    sum[i] =(sum[i]+ v * n%p)%p; // 更新当前节点的值
    lazy_add[i] =(lazy_add[i]+ v)%p; // 更新懒标记
  }

  void Lazy_multiply_up(ll i,ll v,ll n){
    sum[i] =sum[i]* v%p; // 更新当前节点的值
    lazy_multiply[i] =lazy_multiply[i]* v%p; // 更新懒标记
    lazy_add[i] =lazy_add[i] * v%p; // 如果有加法懒标记，也要乘以v
  }

  void down(ll i,ll ln,ll rn){
    if(lazy_multiply[i]!=1){
      Lazy_multiply_up(i<<1,lazy_multiply[i],ln);
      Lazy_multiply_up(i<<1|1,lazy_multiply[i],rn);
      lazy_multiply[i]=1; // 清除当前节点的懒标记
      // 这里的ln和rn是子节点的长度
    }
    if(lazy_add[i]!=0){
      Lazy_add_up(i<<1,lazy_add[i],ln);
      Lazy_add_up(i<<1|1,lazy_add[i],rn);
      lazy_add[i]=0; // 清除当前节点的懒标记
      // 这里的ln和rn是子节点的长度
    } 
  }

  void up(ll i){
    sum[i]=(sum[i<<1]+sum[i<<1|1])%p;
  }

  void add(ll t,ll g,ll l,ll r,ll c,ll i){
    if(t<=l && r<=g){
      Lazy_add_up(i,c,r-l+1);
    }else {
      ll mid=(l+r)>>1;
      down(i,mid-l+1,r-mid);
      if(t<=mid){//说明左边占一部分
        add(t,g,l,mid,c,i<<1);
      }
      if(g>mid){//说明右边占一部分
        add(t,g,mid+1,r,c,i<<1|1);
      }
      up(i);
    }
  }

  void multiply(ll t,ll g,ll l,ll r,ll c,ll i){
    if(t<=l && r<=g){
      Lazy_multiply_up(i,c,r-l+1);
  }else {
    ll mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);
    if(t<=mid){
      multiply(t,g,l,mid,c,i<<1);
    }
    if(g>mid){
      multiply(t,g,mid+1,r,c,i<<1|1);
    }
    up(i);
  }
 }

  ll query(ll t,ll g,ll l,ll r,ll i){
    if(t<=l && r<=g){
      return sum[i];
    }else {
      ll mid=(l+r)>>1;
      down(i,mid-l+1,r-mid);
      ll res=0;
      if(t<=mid){
        res+=query(t,g,l,mid,i<<1);
      }
      if(g>mid){
        res+=query(t,g,mid+1,r,i<<1|1);
      }
      return res;
    }
  }
};

int main(){
  ll n;
  cin >> n >> p;
  a.resize(n+1);
  for(ll i = 1; i <=n; i++){
    cin >> a[i];
  }
  ll M;
  cin >> M;

  Linetree tree(n);
  tree.build(1,n,1);

  while(M--){
    ll op;
    cin >> op;
    if(op==1){
      ll t,g;
      ll c;
      cin >> t >> g >> c;
      tree.multiply(t,g,1,n,c,1); // 乘法操作
    }
    else if(op==2){
      ll t,g;
      ll c;
      cin>> t >> g >> c;
      tree.add(t,g,1,n,c,1); // 加法操作
    }
    else if(op==3){
      ll t,g;
      cin>> t >> g;
      cout << tree.query(t,g,1,n,1)%p << endl; // 查询操作
    }
  }
  return 0;
}