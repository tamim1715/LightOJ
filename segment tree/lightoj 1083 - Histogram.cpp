
/* SHAHADATH HOSSAIN TAMIM
   BANGLADESH UNIVERSITY OF BUSINESS AND TECHNOLOGY
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define pb push_back
#define pob pop_back

#define gcd __gcd
#define lcm(a,b) (a*b)/__gcd(a,b)

#define L length()


#define all(a) a.begin(), a.end()
#define CLR(a)  memset(a,0,sizeof(a))


#define F  first
#define S  second

#define f(a,b) for(int i=a; i<b; i++)
#define fl(a,b) for(long long i=a; i<b; i++)

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

#define INF 1e9
#define INFL 1e18
#define mod 1000000007

#define pi 3.14159265358979323846

#define pii pair<int, int>

int char_to_int(char c){int x=c-48; return x;}
char int_to_char(int x){int c=x+48; return c;}


void fast() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

map<int, int>mp;
vector<int>v;
//pair<int, int>pii;
map<int, vector<int> >G;
map<int, int>visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int t[100009];
pii tree[300009];

void built(int node, int l , int r)
{
    if(l==r)
    {
        tree[node]={t[l], l};
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    built(left, l , mid);
    built(right, mid+1, r);
    tree[node]=min(tree[left], tree[right]);

}
pii query(int node, int l, int r,int i, int j )
{
    if(i>r||j<l) return {INF, INF};
    if(l>=i&&r<=j)
    {
        return tree[node];
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    pii p=query(left, l, mid,i ,j);
    pii q=query(right, mid+1, r, i, j);
    return min(p,q);
}

ll ans(int l, int r,int n)
{
    if(r<l) return 0LL;
    pii m= query(1,1,n,l ,r);
    ll a=(m.F)*(r-l+1);
    ll b=max(ans(l, m.S-1,n), ans(m.S+1, r,n));
    return max(a,b);
}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    cin>>tst;
    while(tst--)
    {
        memset(t, 0,sizeof(t));
        memset(tree, 0, sizeof(tree));
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) cin>>t[i];

        built(1,1,n);
        cout<<"Case "<<++cas<<": ";
        cout<<ans(1,n,n)<<endl;

    }


    return 0;
}

