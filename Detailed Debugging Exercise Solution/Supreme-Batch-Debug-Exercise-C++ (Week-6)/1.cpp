// In Sieve of Eratosthenes, we have to consider a prime number and then mark all the multiple of prime as non-prime i.e. false
// prime[p] == false --> prime[p] == true => Considering a prime number which is indicated by true value
// prime[i] == true --> prime[i] == false => Marking multiples of prime as non prime which is indicated by false.
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n) {
	vector<bool> prime(n,true);
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

int main() {
	int n = 50;
	SieveOfEratosthenes(n);
	return 0;
}