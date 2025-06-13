#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void primes(unsigned long long int n)
{
   for (struct {unsigned long long int p, i, k, limit, done; bool *prime;}s
       = {2, 2*2, 2, sqrt(n), 0, (bool *)calloc(n+1, sizeof(bool))}; 
     s.done == 0; s.p<=s.limit ? (!s.prime[s.p] ? ((s.i<=n ? (s.prime[s.i] = 1, s.i+=s.p)
     : (s.i=(s.p+1)*2, ++s.p))) : (s.i=(s.p+1)*2, ++s.p)) : (s.k<=n ? (!s.prime[s.k]
     ? (printf("%llu\n", s.k), ++s.k) : (++s.k)) : (free(s.prime), s.done = 1))
    );
}


int main() {
  primes(200);
  return 0;
}

