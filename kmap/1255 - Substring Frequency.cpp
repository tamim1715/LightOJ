
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

int p[3000009],cnt=0,m;
void prefixfunction(string a)
{
    int now;
    p[0]=now=-1;
    int len=a.L;
    for(int i=1; i<len; i++)
    {
        while(now!=-1&&a[now+1]!=a[i])  now=p[now]; //cout<<now<<endl;
        if(a[now+1]==a[i]) p[i]=++now;
        else p[i]=now=-1;
        if(p[i]==m-1) cnt++;
        //cout<<now<<endl;
    }
}
/*int kmap(string a, string b)
{
    //p[0]=-1;
    int now=-1;
    int n=a.L;
    int m=b.L;
    for(int i=0; i<n; i++)
    {
        while(now!=-1&&b[now+1]!=a[i]) {now=p[now];}

        if(b[now+1]==a[i]) ++now;
        else now=-1;
        if(now==m-1) cnt++,now=p[now];
        //cout<<now<<endl;
    }
    //cout<<n<<" "<<m<<" "<<a<<" "<<b<<endl;
    return cnt;
}*/

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();

    int tst,cas=0;
    cin>>tst;
    while(tst--)
    {
        cnt=0;
        memset(p, -1, sizeof(p));

        string a,b;
        cin>>a>>b;
        m=b.L;
        string c=b+"#"+a;
        prefixfunction(c);
        //for(int i=0; i<6; i++) cout<<p[i]<<" ";
        //cout<<endl;
        //int x=kmap(a, b);
        cout<<"Case "<<++cas<<": "<<cnt<<endl;
    }


    return 0;
}

