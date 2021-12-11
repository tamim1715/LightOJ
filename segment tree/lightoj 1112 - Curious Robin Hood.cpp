
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

int t[1000001],tree[1000001];

int val=0;

void builttree(int node, int a, int b)
{
    if(a==b)
    {
        tree[node]=t[a];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(a+b)/2;
    builttree(left, a, mid);
    builttree(right, mid+1, b);
    tree[node]=tree[left]+tree[right];

}
void update(int node, int a, int b, int index, int value )
{
    if(index<a||index>b) return;
    if(a==b)
    {
        if(a==index) tree[node]+=value;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(a+b)/2;
    update(left, a, mid, index, value);
    update(right, mid+1, b, index, value);
    tree[node]=tree[left]+tree[right];
}

void query1(int node, int a, int b, int index)
{
    if(index<a||index>b) return;
    if(a==b)
    {
        if(a==index) val=tree[node], tree[node]=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(a+b)/2;
    query1(left, a, mid, index);
    query1(right, mid+1, b, index);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int a, int b, int i, int j)
{
    if(a>=i&&b<=j) { return tree[node]; }
    else if(a>j||b<i) return 0;

    int left=node*2;
    int right=(node*2)+1;
    int mid=(a+b)/2;
    int x=query(left, a, mid, i, j);
    int y=query(right, mid+1, b, i, j);
    return x+y;


}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=1;
    scanf("%d", &tst);
    while(tst--)
    {
        int n,m;
        //cin>>n>>m;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) scanf("%d", &t[i]);//cin>>t[i];
        builttree(1,1,n);
        //for(int i=1; i<=n; i++) cout<<t[i]<<" ";
       // cout<<endl;
       // for(int i=1; i<=9; i++) cout<<tree[i]<<" ";
       // cout<<endl;
        printf("Case %d:\n", cas++);
        while(m--)
        {
            int a,b,c;
            scanf("%d", &a);
            if(a==2)
            {
                scanf("%d %d", &b, &c);
                b++;
                update(1,1,n,b,c);
                //for(int i=1; i<=9; i++) cout<<tree[i]<<" ";
                // cout<<endl;

            }
            else if(a==1)
            {
                scanf("%d", &b);
                b++;
                val=0;
                query1(1, 1, n, b);
                printf("%d\n", val);
                //for(int i=1; i<=9; i++) cout<<tree[i]<<" ";
                // cout<<endl;
            }
            else
            {
                scanf("%d%d", &b, &c);
                b++;
                c++;
                printf("%d\n", query(1,1,n,b,c));
                //for(int i=1; i<=9; i++) cout<<tree[i]<<" ";
                   // cout<<endl;
            }
        }

    }


    return 0;
}

