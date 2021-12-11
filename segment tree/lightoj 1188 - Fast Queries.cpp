
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

struct tamim
{
    int l,r;
    int id;
};
int t[200009];
tamim q[200009];
int ans,result[200009],cnt[200009];
int block;

bool cmp(tamim a, tamim b)
{
    if((a.l/block)==(b.l/block))
    {
        return a.r<b.r;
    }
    else return (a.l/block)<(b.l/block);

}
void update(int pos)
{
    cnt[t[pos]]++;
    if(cnt[t[pos]]==1) ans++;
}

void qremove(int pos)
{
    cnt[t[pos]]--;
    if(cnt[t[pos]]==0) ans--;
}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    scanf("%d", &tst);
    while(tst--)
    {
        printf("Case %d:\n",++cas);

        int n,m;
        memset(t, 0, sizeof(t));
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) scanf("%d", &t[i]);
        for(int i=1; i<=m; i++)
        {
            //int a,b;
            scanf("%d%d", &q[i].l, &q[i].r);

            q[i].id=i;
        }
        block=sqrt(n);

        sort(q+1, q+m+1, cmp);
        int curl,curr,x,y;
        int l=1,r=0;
        ans=0;
        memset(cnt, 0, sizeof(cnt));
        for(int i=1; i<=m; i++)
        {
            x=q[i].l;
            y=q[i].r;
            while(l>x) qremove(--l);
            while(r<y)  update(++r);
            while(l<x)  update(l++);
            while(r>y) qremove(r--);
            result[q[i].id]=ans;



        }
        for(int i=1; i<=m; i++)
        {
            cout<<result[i]<<endl;
        }




    }


    return 0;
}

