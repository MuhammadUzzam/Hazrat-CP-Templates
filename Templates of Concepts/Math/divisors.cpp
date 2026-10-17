// Divisors

// Number of divisors
int cntDiv(int n){
    int cnt=0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            cnt++;
            if(i!=n/i) cnt++;
        }
    }
    return cnt;
}

// Sum of divisors
int sumDiv(int n){
    int sum=0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            sum+=i;
            if(i!=n/i) sum+=n/i;
        }
    }
    return sum;
}

// Product of divisors
// product = n^(d(n)/2)
// handle perfect square separately if using modulo

// Get all divisors
vector<int> getDiv(int n){
    vector<int>v;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);
        }
    }
    return v;
}

// Get sorted divisors
vector<int> getDivSorted(int n){
    vector<int>v=getDiv(n);
    sort(v.begin(),v.end());
    return v;
}

// Precompute divisors for 1...N
vector<int>divs[N+1];

for(int i=1;i<=N;++i)
    for(int j=i;j<=N;j+=i)
        divs[j].push_back(i);

// Precompute number of divisors
vector<int>cnt(N+1);

for(int i=1;i<=N;++i)
    for(int j=i;j<=N;j+=i)
        cnt[j]++;

        
Important Formulas
n = p1^a1 * p2^a2 * ...

Number of divisors:
d(n) = (a1+1)(a2+1)...

Sum of divisors:
σ(n) = Π (1+p+p²+...+p^a)

Product of divisors:
Π divisors = n^(d(n)/2)