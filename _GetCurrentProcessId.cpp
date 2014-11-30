#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<windows.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 0
const int BUF_SIZE= MAX_COMPUTERNAME_LENGTH+1;
char buf[BUF_SIZE];
int main(){
    DWORD _size= BUF_SIZE;
    if (GetComputerNameA(buf, &_size)) {
        string computer_name(buf, _size);
        cout<<"Computer name: ";
        cout<<computer_name<<endl;
        DWORD pid= GetCurrentProcessId();
        cout<<"Current ProcessID: "<<pid<<endl;
    }
    else
    {
        // Handle failure.
    }
    return 0;
}
