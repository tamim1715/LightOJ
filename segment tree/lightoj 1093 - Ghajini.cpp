

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


int char_to_int(char c){int x=c-48; return x;}
char int_to_char(int x){int c=x+48; return c;}


void fast() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

map<int, int>mp;
vector<int>v;
map<int, vector<int> >G;
map<int, int>visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

#define mx 100001
int t[mx];
int treemax[mx * 3];
int treemin[mx*3];
void builtmax(int node, int l, int r)
{
    if(l==r)
    {
        treemax[node]=t[l];
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    builtmax(left, l, mid);
    builtmax(right, mid+1, r);
    treemax[node]=max(treemax[left], treemax[right]);
}
void builtmin(int node, int l, int r)
{
    if(l==r)
    {
        treemin[node]=t[r];
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    builtmin(left, l, mid);
    builtmin(right, mid+1, r);
    treemin[node]=min(treemin[left], treemin[right]);
}
int  querymax(int node, int l, int r, int i, int j)
{
    if(i>r||j<l) return INT_MIN;
    if(l>=i&&r<=j)
    {

        return treemax[node];
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    int p=querymax(left, l, mid,i,j);
    int q=querymax(right, mid+1, r,i,j);
    return max(p,q);

}

int  querymin(int node, int l, int r, int i, int j)
{
    if(i>r||j<l) return INT_MAX;
    if(l>=i&&r<=j)
    {

        return treemin[node];
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    int p=querymin(left, l, mid,i,j);
    int q=querymin(right, mid+1, r,i,j);
    return min(p,q);

}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=1;
    scanf("%d", &tst);
    while(tst--)
    {
        memset(t, 0, sizeof(t));
        memset(treemin, 0, sizeof(treemin));
        memset(treemax, 0, sizeof(treemax));
        int n,d;
        scanf("%d%d", &n, &d);
        for(int i=1; i<=n; i++) cin>>t[i];
        builtmin(1,1,n);
        builtmax(1,1,n);
        /*cout<<endl;
        for(int i=1; i<13; i++) cout<<treemax[i]<<" ";
        cout<<endl;
        for(int i=1; i<13; i++) cout<<treemin[i]<<" ";
        cout<<endl;*/
        int ans=0;
        for(int i=1; i<=n-d+1; i++)
        {
            int p=querymin(1,1,n, i, i+d-1);
            int q=querymax(1,1,n, i, i+d-1);
            //cout<<i<<" "<<i+d-1<<" "<<p<<" "<<q<<endl;
            if(p!=INT_MAX&&q!=INT_MIN)ans=max(ans, q-p);
        }
        printf("Case %d: %d\n",cas++, ans);


    }


    return 0;
}

