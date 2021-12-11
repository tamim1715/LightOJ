
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
int cnt=0;
int t[200009],ans[200005],check[200005],k;

struct tamim
{
    int index,l,r;

}query[200005];

bool cmp(tamim a, tamim b)
{
    int own_index=a.l/k;
    int other_index=b.l/k;
    if(own_index==other_index) return a.r<b.r;
    return own_index<other_index;
}
void add(int cur)
{
    check[t[cur]]++;
    if(check[t[cur]]==1) cnt++;
}
void remove(int cur)
{
    check[t[cur]]--;
    if(check[t[cur]]==0) cnt--;
}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    scanf("%d", &tst);
    while(tst--)
    {
        CLR(check);
        //mp.clear();
        cnt=0;
        int n,q;
        scanf("%d %d", &n, &q);
        k=n/sqrt(q*2/3);
        for(int i=1; i<=n; i++) scanf("%d", &t[i]);
        for(int i=1; i<=q; i++)
        {
            scanf("%d %d", &query[i].l, &query[i].r);
            query[i].index=i;

        }
        sort(query+1, query+q+1, cmp);
        int l=1,r=0;
        for(int i=1; i<=q; i++)
        {
            while(r<query[i].r) add(++r);
            while(l<query[i].l) remove(l++);
            while(r>query[i].r) remove(r--);
            while(l>query[i].l) add(--l);
            ans[query[i].index]=cnt;
        }
        printf("Case %d:\n", ++cas);
        //cout<<"Case "<<++cas<<":"<<endl;
        for(int i=1; i<=q; i++)
        {
            printf("%d\n", ans[i]);
        }
    }


    return 0;
}

