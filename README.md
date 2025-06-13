# In the Sleeve of Eratosthenes
this is an implementation of the prime finding algorithm, but packed into a sort of one-liner in C ...
```C
// Sieve of Eratosthenes in "one line" of C, packed into one for loop with no body
// by nullp0tr
void primes(unsigned long long int n)
{
   for (struct {unsigned long long int p, i, k, limit, done; bool *prime;}s
       = {2, 2*2, 2, sqrt(n), 0, (bool *)calloc(n+1, sizeof(bool))}; 
     s.done == 0; s.p<=s.limit ? (!s.prime[s.p] ? ((s.i<=n ? (s.prime[s.i] = 1, s.i+=s.p)
     : (s.i=(s.p+1)*2, ++s.p))) : (s.i=(s.p+1)*2, ++s.p)) : (s.k<=n ? (!s.prime[s.k]
     ? (printf("%llu ", s.k), ++s.k) : (++s.k)) : (free(s.prime), s.done = 1))
    );
}
```

the current C file has `primes(200)` hardcoded, and will print all prime numbers up to 200.

to compile it use `gcc sleeve.c -o sleeve -lm`