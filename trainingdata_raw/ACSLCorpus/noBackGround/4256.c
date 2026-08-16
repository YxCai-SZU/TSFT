#include <stdbool.h>

/*@ requires a <= b;
    requires a >= -0x7fffffffffffffff;
    requires b <= 0x7fffffffffffffff;
    requires c >= -0x7fffffffffffffff;
    ensures \result <==> (a <= c && c <= b);
    ensures \result <==> ((a) <= (c) && (c) <= (b));
*/
bool func(long long a, long long b, long long c) {
    //@ assert a <= b;
    //@ assert a <= c && c <= b <==> ((a) <= (c) && (c) <= (b));
    return a <= c && c <= b;
}

int main() {
    long long a = 0;
    long long b = 0;
    long long c = 0;
    bool result = func(a, b, c);
    return 0;
}
