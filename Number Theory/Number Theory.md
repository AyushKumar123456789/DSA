# Seive of Eratosthenes :

It is used to find that given number is prime or not , (and number in range of 0 to 1e6) it is one time computation method so it is helpful for multiple query :

```

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
