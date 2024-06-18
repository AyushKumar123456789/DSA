## Seive of Eratosthenes :

It is used to find that given number is prime or not , (and number in range of 0 to 1e6) it is one time computation method so it is helpful for multiple query :

```cpp

Vector<int>prime(1e6,1);
prime[0]=prime[1]=0;
for(int i=2;i*i<=1e6;i++){
if(prime[i]==1)
{
for (int multiple = i * i; multiple <= 1e6; multiple += i) {
prime[multiple] = 0;
}
}
}

Time Complexity=> O(xlog(log(sqrt(x)))) = xlog(½\*log(x)) = O(xlog(log(x)))

```

## Sum of Two square numbers Theorem :

- ### Fermat's theorem on sums of two squares:

  - A prime number p can be written as sum of two squares if and only if p ≡ 1 (mod 4).
  - A number n can be written as sum of two squares if and only if all prime factors of the form (4k+3) occurs even number of times in prime factorization of n.

  Questions You can try : [Leetcode](https://leetcode.com/problems/sum-of-square-numbers/)

- ### Lagrange's four-square theorem:

  - Every natural number can be represented as sum of four squares of integers.

  - The number of ways a number n can be represented as sum of four squares is 8 times the sum of divisors of n if n is odd and 24 times the sum of odd divisors of n if n is even.

## Wilson's Theorem :

- Wilson's theorem states that a natural number n > 1 is a prime number if and only if the product of all the positive integers less than n is one less than a multiple of n.

- (n-1)! ≡ -1 (mod n) if and only if n is prime.

- Wilson's theorem can be used to test primality of a number n in O(n) time complexity.

## Euler's Totient Function :

- Euler's Totient function φ(n) is the number of positive integers less than n that are coprime to n.
