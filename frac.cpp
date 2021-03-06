#include <bits/stdc++.h>

// frac.cpp
// author: Seong Yong-ju ( @sei40kr )
// Copyright 2017 Seong Yong-ju

int gcd(int n, int m) {
  if (n % m == 0) {
    return m;
  }

  return gcd(m, n % m);
}

class Frac {
 private:
  int a, b;

 public:
  Frac(int num) {
    a = num;
    b = 1;
  }
  Frac(int num, int den) {
    a = num;
    b = den;
  }
  Frac(const Frac &f) { *this = f; }

  Frac &operator=(const Frac &f) {
    a = f.a;
    b = f.b;
    return *this;
  }

  Frac &operator+=(const Frac &f) {
    a += f.a;
    b += f.b;
    return *this;
  }

  Frac &operator*=(const Frac &f) {
    a *= f.a;
    b *= f.b;
    return *this;
  }

  Frac reduce() const {
    Frac ret = *this;
    int d = gcd(a, b);
    ret.a /= d;
    ret.b /= d;
    return ret;
  }

  std::string str() const {
    char buf[32];

    if (b == 1) {
      snprintf(buf, sizeof(buf), "%d", a);
    } else {
      snprintf(buf, sizeof(buf), "%d/%d", a, b);
    }

    return buf;
  }
};

Frac operator+(const Frac &f1, const Frac &f2) {
  Frac ret = f1;
  ret += f1;
  return ret;
}

Frac operator*(const Frac &f1, const Frac &f2) {
  Frac ret = f1;
  ret *= f1;
  return ret;
}

int main() {
  Frac a(1, 2);
  Frac b(1, 3);
  Frac c = a + b;
  Frac d = a * b;
  Frac e = d * Frac(15);
  Frac f = e.reduce();
  Frac g = f * 2;
  Frac h = g.reduce();
  printf("a = %s\n", a.str().c_str());
  printf("b = %s\n", b.str().c_str());
  printf("c = %s\n", c.str().c_str());
  printf("d = %s\n", d.str().c_str());
  printf("e = %s\n", e.str().c_str());
  printf("f = %s\n", f.str().c_str());
  printf("g = %s\n", g.str().c_str());
  printf("h = %s\n", h.str().c_str());
}
