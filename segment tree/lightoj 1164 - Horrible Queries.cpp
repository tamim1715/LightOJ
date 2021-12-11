
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

ll tree[500009],lazy[500009];

void built(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=0LL;
        lazy[node]=0LL;
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    built(left, l, mid);
    built(right, mid+1, r);
    tree[node]=0LL;
    lazy[node]=0LL;
}
void update(int node, int l, int r, int i, int j, ll x)
{
    if(i>r || j<l) return;
    if(l>=i and r<=j)
    {
        tree[node]+=(r-l+1)*x;
        //cout<<lazy[node]<<" prothome "<<x<<endl;
        lazy[node]+=x;
        //cout<<lazy[node]<<" sesh "<<x<<endl;
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    update(left, l, mid,i ,j, x);
    update(right, mid+1, r, i , j, x);

    tree[node]=tree[left]+tree[right]+((r-l+1)*lazy[node]);

}

ll query(int node, int l, int r, int i, int j, ll carry)
{
    if(i>r||j<l) return 0LL;
    if(l>=i and r<=j)
    {
        //cout<<tree[node]<<" "<<l<<" "<<r<<" "<<carry<<endl;
        return tree[node]+((r-l+1)*carry);
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    //cout<<lazy[node]<<" lazy "<<carry<<endl;
    ll p=query(left, l, mid,i ,j, carry+lazy[node]);
    ll q=query(right, mid+1, r, i , j, carry+lazy[node]);

    return p+q;
}

int main()
{
    freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=1;
    scanf("%d", &tst);
    while(tst--)
    {
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
        //for(int i=0; i<5; i++) cout<<lazy[i]<<endl;
        printf("Case %d:\n", cas++);
        int n,m;
        scanf("%d%d", &n, &m);
        built(1,1,n);



        while(m--)
        {
            int x,a,b;
             ll c;
            scanf("%d", &x);
            if(x==0)
            {
                //int a,b;


                scanf("%d%d %lld", &a, &b, &c);
                a++;
                b++;
                update(1,1,n, a, b, c);
                //for(int i=1; i<=30; i++) cout<<tree[i]<<" ";
                //cout<<endl;

            }
            else
            {
                //int a,b;
                scanf("%d %d", &a, &b);
                a++;
                b++;
                ll p=query(1,1,n,a,b, 0);
                printf("%lld\n", p);
            }
        }

    }


    return 0;
}

