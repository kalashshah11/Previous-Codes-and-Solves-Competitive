#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
 
using namespace std;

const int MAX = 300005;
const int MAGIC = 548;

struct query{
    int l;
    int r;
    int id;
    query() {
        
    }
    query(int l, int r, int id):
    l(l), r(r), id(id) {
        
    }
    bool operator < (const query other) const{
        if(l / MAGIC != other.l / MAGIC) {
            return l / MAGIC < other.l / MAGIC;
        }
        return r < other.r;
    }
};

int N, Q;
int a[MAX], output[MAX], counts[MAX], frequencies[MAX],sizes[MAX];
vector<query> queries;

void fix(int &answer) {
    while (frequencies[answer + 1] > 0) {
        answer ++;
    }
    while (answer > 0 && frequencies[answer] == 0) {
        answer --;
    }
}
void add(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] ++;
    frequencies[counts[a[position]]] ++;
    fix(answer);
}
void remove(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] --;
    if (counts[a[position]] > 0) {
        frequencies[counts[a[position]]] ++;
    }
    fix(answer);
}


int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &Q);
    // fastInput(N);
    // fastInput(Q);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
        // fastInput(a[i]);
    }
    for (int i = 0; i < Q; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        // fastInput(l);
        // fastInput(r);
        queries.push_back(query(l-1, r-1, i));
		sizes[i] = r - l + 1;
    }
    sort(queries.begin(), queries.end());
    int L = N - 1, R = N - 1;
    int answer = 0;
    for(int i = 0; i < Q; i ++) {
        for(int j = L; j >= queries[i].l; j --) {
            add(j, answer);
        }
        for(int j = R + 1; j <= queries[i].r; j ++) {
            add(j, answer);
        }
        for(int j = L + 1; j < queries[i].l; j ++) {
            remove(j, answer);
        }
        for(int j = R; j > queries[i].r; j --) {
            remove(j, answer);
        }
        L = queries[i].l - 1;
        R = queries[i].r;
        output[queries[i].id] = answer;
		
    }
    for(int i = 0; i < Q; i ++) {
		int left = sizes[i] - output[i];
		if(left >= output[i] - 1){
			printf("1\n");
		}
		else if(left <= 2*output[i]){
			printf("%d\n",output[i] - left);
		}
		else{
			printf("%d\n",2*left - output[i] + 2);
		}
    }
    
    return 0;
}
