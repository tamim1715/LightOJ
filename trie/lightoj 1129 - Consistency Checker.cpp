
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

int node[100005][10];
int isword[100005];
bool flag=true;
int root;
int cnt;


bool cmp(string a, string b)
{
    if(a.L==b.L) return a<b;
    return a.L<b.L;
}


void fresh()
{
    for(int i=0; i<100005; i++)
    {
        CLR(node[i]);
    }
}
void insert()
{
    for(int i=0; i<v.size(); i++)
    {
        string s=v[i];
    int now=root;
    for(int i=0; i<s.L; i++)
    {
        if(!node[now][s[i]-'0'])
        {
            node[now][s[i]-'0']=++cnt;
        }
        now=node[now][s[i]-'0'];
        if(isword[now])
        {
            //cout<<"tamim "<<s<<endl;
            flag=false;
        }
    }
    isword[now]=1;
    }

}
int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    cin>>tst;
    while(tst--)
    {
        CLR(isword);
        fresh();
        cnt=0;
        v.clear();
        int n;
        cin>>n;
        flag=true;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            v.pb(s);
        }
        sort(v.begin(), v.end(), cmp);

        insert();
        if(!flag) cout<<"Case "<<++cas<<": NO"<<endl;
        else cout<<"Case "<<++cas<<": YES"<<endl;

    }


    return 0;
}

