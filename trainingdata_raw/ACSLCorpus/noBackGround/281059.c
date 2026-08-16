#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) >= 3 &&
        1 <= (v)[0] && (v)[0] <= 13 &&
        1 <= (v)[1] && (v)[1] <= 13 &&
        1 <= (v)[2] && (v)[2] <= 13);
    ensures \result == 1 <==> (((v[2]) == (v[0]) + (v[1])) ? 1 : (((v[1]) == (v[0]) + (v[2])) ? 1 : (((v[0]) == (v[1]) + (v[2])) ? 1 : 0))) == 1;
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert 1 <= a && a <= 13;
    //@ assert 1 <= b && b <= 13;
    //@ assert 1 <= c && c <= 13;

    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == 1 <==> (((c) == (a) + (b)) ? 1 : (((b) == (a) + (c)) ? 1 : (((a) == (b) + (c)) ? 1 : 0))) == 1;
    return result;
}

#ifdef TEST
#include <assert.h>

int main() {
    int test1[3] = {1, 2, 3};
    int test2[3] = {1, 2, 5};
    
    bool r1 = func(test1);
    bool r2 = func(test2);
    
    assert(r1 == true);
    assert(r2 == false);
    
    return 0;
}
#endif
