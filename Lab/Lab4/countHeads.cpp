double factorial(int n) {
    if (n==0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

double choose(int N, int r) {
    double result = factorial(N) / (factorial(r) * factorial(N-r));
    return result;
}