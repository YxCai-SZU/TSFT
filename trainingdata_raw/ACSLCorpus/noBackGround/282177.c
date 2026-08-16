#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000 && (a) % 3 == 0);
    ensures \result == a + 100;
    assigns \nothing;
*/
int func(int a) {
    int result;
    int count;
    int temp;
    
    result = a;
    count = 0;
    temp = a;
    
    /*@
        loop invariant 1 <= a && a <= 10000;
        loop invariant a % 3 == 0;
        loop invariant temp >= 0;
        loop invariant temp == a - 3 * count;
        loop invariant count >= 0;
        loop invariant count <= a / 3;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3) {
        temp -= 3;
        count += 1;
    }
    
    result += 100;
    
    //@ assert a + 100 <= 10100;
    
    //@ assert a + 100 == result;
    
    return result;
}

int main() {
    return 0;
}
