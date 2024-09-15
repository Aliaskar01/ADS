def sieve_of_eratosthenes(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False  
    for i in range(2, int(limit**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False
    
    primes = [i for i in range(2, limit + 1) if sieve[i]]
    return primes

limit = 10000
primes = sieve_of_eratosthenes(limit)

n = int(input())

print(primes[n - 1])