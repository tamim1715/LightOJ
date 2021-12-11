
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
#define mod 1e9+7

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

int t[5000001],tree[5000001],n,m,mn=INF;
int builttree(int node, int a, int b)
{
    if(a==b)
    {
        tree[node]=t[a];
        return t[a];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(a+b)/2;
    builttree(left, a, mid);
    builttree(right, mid+1, b);
    tree[node]=min(tree[left],tree[right]);
    //return tree[node];

}

int query(int node, int a, int b, int i, int j)
{
    //if(j<a||i>b) return INF;
    if(i>b||j<a) return INF;
    if(a>=i&&b<=j)
    {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(a+b)/2;
    int x=query(left, a, mid, i, j);
    int y=query(right, mid+1, b, i, j);
    return min(x,y);
}
int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &n, &m);
        //memset(t, 0, sizeof(t));
        f(1,n+1) scanf("%d", &t[i]);
        builttree(1,1,n);
        printf("Case %d:\n",++cas);
       // cout<<"Case "<<++cas<<":"<<endl;
        while(m--)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            //mn=INF;

            printf("%d\n", query(1,1,n, a,b));
        }
    }


    return 0;
}

