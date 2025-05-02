#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace MyMath;

TEST_CASE("SquareMat basic arithmetic operators") {
    SquareMat a(2);
    SquareMat b(2);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat sum = a + b;
    CHECK(sum[0][0] == 6);
    CHECK(sum[1][1] == 12);

    SquareMat diff = a - b;
    CHECK(diff[0][0] == -4);
    CHECK(diff[1][1] == -4);

    SquareMat neg = -a;
    CHECK(neg[0][0] == -1);
    CHECK(neg[1][1] == -4);

    SquareMat prod = a * b;
    CHECK(prod[0][0] == 19);
    CHECK(prod[1][1] == 50);

    SquareMat scaled = a * 2.0;
    CHECK(scaled[0][0] == 2);
    CHECK(scaled[1][1] == 8);

    SquareMat modmat = a % b;
    CHECK(modmat[0][0] == 1);  

    SquareMat modint = a % 2;
    CHECK(modint[0][0] == 1);  

    SquareMat div = a / 2.0;
    CHECK(div[0][0] == doctest::Approx(0.5));
    CHECK(div[1][1] == doctest::Approx(2.0));

    SquareMat pow = a ^ 2;
    CHECK(pow[0][0] == 7);  

    SquareMat prefix = ++a;
    CHECK(prefix[0][0] == 2);

    SquareMat postfix = b++;
    CHECK(postfix[0][0] == 5);
    CHECK(b[0][0] == 6);

    SquareMat predec = --a;
    CHECK(predec[0][0] == 1);

    SquareMat postdec = b--;
    CHECK(postdec[0][0] == 6);
    CHECK(b[0][0] == 5);

    SquareMat trans = ~a;
    CHECK(trans[0][1] == a[1][0]);

    a += b;
    CHECK(a[0][0] == 6);

    a -= b;
    CHECK(a[0][0] == 1);

    a *= b;
    CHECK(a[0][0] == 19);

    a *= 0.5;
    CHECK(a[0][0] == doctest::Approx(9.5));

    a %= b;
    CHECK(a[0][0] == doctest::Approx(fmod(9.5, 5.0)));

    a %= 3;
    CHECK(a[0][0] == doctest::Approx(fmod(fmod(9.5, 5.0), 3.0)));

    a /= 2.0;
    CHECK(a[0][0] == doctest::Approx(fmod(fmod(9.5, 5.0), 3.0) / 2.0));

    SquareMat equal(2);
    equal[0][0] = a[0][0]; equal[0][1] = a[0][1];
    equal[1][0] = a[1][0]; equal[1][1] = a[1][1];

    CHECK(a == equal);
    CHECK_FALSE(a != equal);
    CHECK_FALSE(a < equal);
    CHECK(a <= equal);
    CHECK_FALSE(a > equal);
    CHECK(a >= equal);

    double norm = !a;
    CHECK(norm >= 0);

    std::ostringstream oss;
    oss << a;
    CHECK(!oss.str().empty());
}
