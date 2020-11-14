#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, k, ans, mod=1e9+7;
int pw(int a, int b)
{
  int ret=1;
  while(b)
  {
    if(b&1) ret*=a;
    a*=a;
    b>>=1;
  }
  return ret;
}

vector<int> p;
const int sz=101010;
int sp[sz], e[sz], phi[sz], mu[sz], tau[sz], sigma[sz];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int i, j, temp=0;
  phi[1]=mu[1]=tau[1]=sigma[1]=1;
  for(i=2;i<sz;i++)
  {
    if(!sp[i])
    {
      p.push_back(i);
      e[i]=1;
      phi[i]=i-1;
      mu[i]=-1;
      tau[i]=2;
      sigma[i]=i+1;
    }
    for(auto j:p)
    {
      if(i*j>=sz) break;
      sp[i*j]=j;
      if(i%j==0)
      {
        e[i*j]=e[i]+1;
        phi[i*j]=phi[i]*j;
        mu[i*j]=0;
        tau[i*j]=tau[i]/e[i*j]*(e[i*j]+1);
        sigma[i*j]=sigma[i]*(j-1)/(pw(j, e[i*j])-1)*(pw(j, e[i*j]+1)-1)/(j-1);
        break;
      }
      e[i*j]=1;
      phi[i*j]=phi[i]*phi[j];
      mu[i*j]=mu[i]*mu[j];
      tau[i*j]=tau[i]*tau[j];
      sigma[i*j]=sigma[i]*sigma[j];
    }
  }
  for(i=2;i<sz;i++)
    cout<<i<<' '<<e[i]<<' '<<phi[i]<<' '<<mu[i]<<' '<<tau[i]<<' '<<sigma[i]<<'\n';
}