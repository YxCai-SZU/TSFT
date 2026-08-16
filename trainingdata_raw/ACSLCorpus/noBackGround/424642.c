#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(v+(0..1));
    requires ((len) == 2);
    requires ((((len)) == 2) ==> (v)[0] > 0 && (v)[0] < 10);
    requires ((((len)) == 2) ==> (v)[1] > 0 && (v)[1] < 10);
    ensures \result == (v[0] * v[1] % 2 == 0);
*/
bool func(int *v, size_t len) {
    int product;
    bool is_even;
    int temp;
    
    //@ assert ((((len)) == 2) ==> (v)[0] * (v)[1] < 100);
    product = v[0] * v[1];
    is_even = false;
    temp = product;
    
    /*@ loop invariant 0 <= temp <= product;
        loop invariant ((temp) % 2 == (product) % 2);
        loop invariant ((len) == 2);
        loop invariant ((((len)) == 2) ==> (v)[0] > 0 && (v)[0] < 10);
        loop invariant ((((len)) == 2) ==> (v)[1] > 0 && (v)[1] < 10);
        loop assigns temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    
    if (temp == 0) {
        is_even = true;
    }
    return is_even;
}
