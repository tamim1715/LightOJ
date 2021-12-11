
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

#define pii pair<int, int>
#define F  first
#define S  second

#define f(a,b) for(int i=a; i<b; i++)
#define fl(a,b) for(long long i=a; i<b; i++)

#define sf scanf
#define pf printf

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

ll t[200000],tree[200000];


ll query(ll indx)
{
    ll sum=0LL;
    while(indx>0)
    {
        sum+=tree[indx];
        //cout<<tree[indx]<<"  check  "<<indx<<" "<<sum<<endl;
        indx-=(indx&(-indx));
    }
    return sum;
}

ll update1(ll x, ll n)
{
    ll p=query(x);
    ll q=query(x-1);
    ll val=p-q;
    while(x<=n)
    {
        tree[x]-=val;
        x+=(x&(-x));
    }
    return val;
}
void update2(ll indx, ll val, ll n)
{
    while(indx<=n)
    {
        tree[indx]+=val;
        //cout<<tree[indx]<<" check "<<indx<<endl;
        indx+=(indx&(-indx));
    }
}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    ll tst,cas=0;
    scanf("%lld", &tst);
    while(tst--)
    {
        printf("Case %lld:\n",++cas);
        ll n,q;
        scanf("%lld%lld", &n, &q);
        CLR(tree);
        CLR(t);
        for(ll i=1; i<=n; i++) scanf("%lld",&t[i]);
        for(ll i=1; i<=n; i++)
        {
            update2(i, t[i], n);
        }


        while(q--)
        {
            ll x,y,z;
            sf("%lld",&x);
            if(x==1)
            {
                sf("%lld", &y);
                y++;
               ll p=update1(y, n);
               printf("%lld\n", p);
            }
            if(x==2)
            {
                sf("%lld %lld", &y, &z);
                y++;
                update2(y,z,n);

            }
            if(x==3)
            {
                sf("%lld %lld", &y, &z);
                y++;
                z++;
                ll p=query(y-1);
                ll q=query(z);
                //cout<<p<<" "<<q<<endl;
                printf("%lld\n", q-p);
            }
        }



    }


    return 0;
}

