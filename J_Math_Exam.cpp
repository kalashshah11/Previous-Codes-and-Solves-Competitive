#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// Can the vessels fill all the m containers, each has capacity C?
bool FillAllContainers(const vector<ll> &vessels, 
                       ll                m, 
                       ll                C)
{
    ll container = 1;
    ll capacity = C;
    for (int i = 0; i < vessels.size(); ++i)
    {
        // No container can contain so much milk.
        if (vessels[i] > C)
            return false;

        if (vessels[i] > capacity)
        {
            // Already m containers are filled.
            if (container == m)
                return false;
            ++container;
            capacity = C;
        }
        capacity -= vessels[i];
    }
    return true;
}

int main()
{  
    int T;
    cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> vessels(n);
	ll sum = 0;
        for (int i = 0; i < n; ++i){
		cin >> vessels[i];
		sum += vessels[i];
	}
            
        // The capacity 1<=c<=1000000000.
        ll L = 1, U = sum + 1, C = 0;
        while (L <= U)
        {
            ll mid = (L + U) / 2;
            if (FillAllContainers(vessels, m, mid))
            {
                C = mid;
                U = mid - 1;
            }
            else
                L = mid + 1;
        }
        cout << C << endl;
    }
    return 0;
}