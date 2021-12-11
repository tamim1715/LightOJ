
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
vector<string>v;
map<int, vector<int> >G;
map<int, int>visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


ll nnode=0LL,mx=0LL;

struct node
{
    int next[4];
    ll cnt;
}t[2500109];
void new_node(int cur)
{
    t[cur].next[0]=-1;
    t[cur].next[1]=-1;
    t[cur].next[2]=-1;
    t[cur].next[3]=-1;
    t[cur].cnt=1;

}
void iinsert()
{
    string s;
    cin>>s;
    ll now=0LL;
    for(int i=0; i<s.L; i++)
    {
        int x;
        if(s[i]=='A') x=0;
        else if(s[i]=='C') x=1;
        else if(s[i]=='G') x=2;
        else if(s[i]=='T') x=3;
        if(t[now].next[x]==-1)
        {
            t[now].next[x]=nnode;
            new_node(nnode++);
            now=t[now].next[x];
        }
        else
        {
            now=t[now].next[x];
            t[now].cnt++;

            mx=max(mx, (i+1)*t[now].cnt);
        }
    }
    mx=max(mx, (ll)s.L);
}

int main()
{
    int tst,cas=0;
    cin>>tst;

    while(tst--)
    {
        int n;
        mx=0LL;
        nnode=1LL;

        cin>>n;
        new_node(0);
        for(int i=0; i<n; i++)
        {
            iinsert();
        }
        cout<<"Case "<<++cas<<": "<<mx<<endl;
    }
}

