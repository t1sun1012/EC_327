
double abs(double number) {
    if (number < 0) {
        number *= -1;
    }
    return number;
}


double sqrt(double N, double tol) {
    double guess = N;
    while (abs(guess - N/guess) > tol) {
        guess = (guess + N/guess) / 2;
    }
    return guess;
}

double positiveX(int a, int b, int c, double tol) {
    double x;
    double delta;
    delta = b*b - 4*a*c;
    x = (-b + sqrt(delta, tol)) / (2 * a);
    return x;
}

double negativeX(int a, int b, int c, double tol) {
    double x;
    double delta;
    delta = b*b - 4*a*c;
    x = (-b - sqrt(delta, tol)) / (2 * a);
    return x;
}