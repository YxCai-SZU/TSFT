#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == true <==> (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool answer = false;
    int i = 0;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
    if (a < b && b < c) {
        answer = true;
    }

    //@ assert answer == true <==> (a < b && b < c);

    /*@
        loop invariant 0 <= i <= 1000000;
        loop invariant (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
        loop invariant answer == true <==> (a < b && b < c);
        loop assigns i;
        loop variant 1000000 - i;
    */
    while (i < 1000000) {
        i = i + 1;
    }

    //@ assert answer == true <==> (a < b && b < c);
    return answer;
}
