#include <iostream>

using namespace std;

const double EPS = 0.0001;

double sqrt(double number) {
  double start = 0.0, end = max(1.0, number);
  while (start + EPS < end) {
    double mid = start + (end - start) / 2;
    if (mid * mid > number)
      end = mid;
    else
      start = mid;
  }
  return start;
}

int main() {
  double a;
  while (cin >> a) {
    cout << sqrt(a) << endl;
  }
  return 0;
}
