#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 5000;

    predicate triangle_inequality_fails(integer a, integer b, integer c) =
        a + b < c || b + c < a || c + a < b;

    predicate valid_triangle(integer a, integer b, integer c) =
        a + b > c && b + c > a && c + a > b;

    predicate two_sides_greater(integer a, integer b, integer c) =
        (a + b > c && b + c > a && c + a <= b) ||
        (a + b > c && b + c <= a && c + a > b) ||
        (a + b <= c && b + c > a && c + a > b);

    predicate one_side_greater(integer a, integer b, integer c) =
        (a + b > c && b + c <= a && c + a <= b) ||
        (a + b <= c && b + c > a && c + a <= b) ||
        (a + b <= c && b + c <= a && c + a > b);

    predicate no_side_greater(integer a, integer b, integer c) =
        a + b <= c && b + c <= a && c + a <= b;
*/

/*@
    requires valid_input(a,b,c);
    ensures \result >= -1 && \result <= 3;
    ensures \result == -1 ==> triangle_inequality_fails(a,b,c);
    ensures \result == 3 ==> valid_triangle(a,b,c);
    ensures \result == 2 ==> two_sides_greater(a,b,c);
    ensures \result == 1 ==> one_side_greater(a,b,c);
    ensures \result == 0 ==> no_side_greater(a,b,c);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t result;
    //@ assert valid_input(a,b,c);
    
    if (a + b < c || b + c < a || c + a < b) {
        result = -1;
        //@ assert triangle_inequality_fails(a,b,c);
        return result;
    } else if (a + b > c && b + c > a && c + a > b) {
        result = 3;
        //@ assert valid_triangle(a,b,c);
        return result;
    } else {
        if (a + b > c && b + c > a && c + a <= b) {
            result = 2;
            //@ assert two_sides_greater(a,b,c);
            return result;
        } else if (a + b > c && b + c <= a && c + a > b) {
            result = 2;
            //@ assert two_sides_greater(a,b,c);
            return result;
        } else if (a + b <= c && b + c > a && c + a > b) {
            result = 2;
            //@ assert two_sides_greater(a,b,c);
            return result;
        } else if (a + b > c && b + c <= a && c + a <= b) {
            result = 1;
            //@ assert one_side_greater(a,b,c);
            return result;
        } else if (a + b <= c && b + c > a && c + a <= b) {
            result = 1;
            //@ assert one_side_greater(a,b,c);
            return result;
        } else if (a + b <= c && b + c <= a && c + a > b) {
            result = 1;
            //@ assert one_side_greater(a,b,c);
            return result;
        } else {
            result = 0;
            //@ assert no_side_greater(a,b,c);
            return result;
        }
    }
}
