#include <stddef.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    ensures 3 <= \result <= 1110;
*/
int func(int a) {
    //@ assert a >= 1 && a <= 10;
    int result;
    result = a + a * a + a * a * a;
    //@ assert result == ((a) + (a) * (a) + (a) * (a) * (a));
    //@ assert result >= 3;
    //@ assert result <= 1110;
    return result;
}

int main() {
    return 0;
}
