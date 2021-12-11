
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

//#define L length()


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

//string s;

int n;

int tree[500005],lazy[500005];

void built(int node, int l, int r)
{
    //if(b<l||a>r) return;
    if(l==r)
    {
        lazy[node]=0;
        //cout<<node<<endl;
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    built(left, l, mid);
    built(right, mid+1, r);
    lazy[node]=0;

}

void update(int node, int l, int r, int a, int b)
{
    if(b<l||a>r) return;
    if(a<=l&&b>=r)
    {
        lazy[node]++;
        //cout<<node<<endl;
        return;
    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    update(left, l, mid, a,b);
    update(right, mid+1, r, a,b);

}

int query(int node, int l, int r, int a)
{
    if(a<l||a>r) return 0;
    if(l==a&&r==a)
    {
        return lazy[node];

    }
    int left=(node<<1);
    int right=(node<<1)+1;
    int mid=((l+r)>>1);
    if(a<=mid)
       return lazy[node]+query(left, l, mid, a);
    else
       return lazy[node]+query(right, mid+1, r, a);

}

int main()
{
    //freopen("tamim.txt", "w", stdout);
    fast();
    int tst,cas=0;
    scanf("%d", &tst);
    getchar();
    while(tst--)
    {
        char s[100000];
        cout<<"Case "<<++cas<<":"<<endl;
        memset(lazy, 0, sizeof(lazy));
        scanf("%s", &s);
        n = strlen(s);

        //built(1,0,n-1);
        built(1,1,n);
        int q;
        scanf("%d", &q);


         getchar();

        while(q--)
        {
            char c;
            int a,b;
            scanf("%c", &c);
            getchar();
            if(c=='I')
            {
                scanf("%d%d",&a,&b);
                getchar();

                update(1,1,n,a,b);
                //cout<<endl;
                //for(int i=0; i<=30; i++) cout<<lazy[i]<<" ";
               // cout<<endl;
                //cout<<endl;
            }
            else
            {
               scanf("%d", &a);
                getchar();
                int x=query(1,1,n,a);
                //cout<<" x "<<x<<endl;
                if(x%2)
                {
                    if(s[a-1]=='0') printf("1\n");
                    else printf("0\n");
                }
                else printf("%c\n", s[a-1]);
            }
        }


    }


    return 0;
}

