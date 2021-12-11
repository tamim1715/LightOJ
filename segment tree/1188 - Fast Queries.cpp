
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
pair<int, int>pii;
map<int, vector<int> >G;
map<int, int>visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};





int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst;
    scanf("%d", &tst);
    while(tst--)
    {
        mp.clear();
        int n,m;
        scanf("%d%d", &n, &m);
        int x;

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &x);
            if(mp[x]==0)
            {
                tree[i]=tree[i-1]+1;
                mp[x]++;
            }
            else tree[i]=tree[i-1];
        }
        while(m--)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            cout<<tree[b]-tree[a]+1<<endl;
        }

    }


    return 0;
}

