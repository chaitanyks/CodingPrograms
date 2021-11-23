List:
1. Prime Numbers Sieve of Eratosthenes
2. Union-Find Disjoint Set
3. gcd
4. Fast I/O

-------------------------------------------------

1. Prime Numbers Sieve of Eratosthenes

void isprime(vector<bool> &is_prime,int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

-------------------------------------------------

2. Union-Find Disjoint Set

int root(int x, int parents[]) {
    while (parents[x] != x) {
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void unionGraph(int x, int y, int parents[]) {
    int p1 = root(x, parents);
    int p2 = root(y, parents);
    if (p1 != p2) {
        parents[p1] = p2;
    }
}

-------------------------------------------------

3. gcd

int gcd(int a, int b)
{
  if(a==0)
    return b;
  else
    return gcd(b%a,a);
}

-------------------------------------------------

4. Fast I/O

// Generic
static auto _speedupMagic = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// inside Main()
ios_base::sync_with_stdio(false);
cin.tie(NULL); 

-------------------------------------------------
5.
-------------------------------------------------
6.
-------------------------------------------------
7.  
-------------------------------------------------
8.
