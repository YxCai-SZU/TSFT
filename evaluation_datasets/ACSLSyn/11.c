#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;

    predicate condition_a(integer a, integer b, integer c) =
        a < c && c < b || c < b && b < a;

    predicate condition_b(integer a, integer b, integer c) =
        a < b && b < c || b < c && c < a;

    predicate condition_c(integer a, integer b, integer c) =
        a == c || c == b || b == a;

    predicate result_condition(integer a, integer b, integer c) =
        condition_a(a, b, c) || condition_b(a, b, c) || condition_c(a, b, c);
*/

bool func1(int a, int b, int c)
{
    int cnt = 0;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    if (a < c && c < b) {
        cnt += 1;
    } else if (c < b && b < a) {
        cnt += 1;
    }

    if (a < b && b < c) {
        cnt += 1;
    } else if (b < c && c < a) {
        cnt += 1;
    }

    if (a == c || c == b || b == a) {
        cnt += 1;
    }

    //@ assert cnt > 0 <==> result_condition(a, b, c);
    return cnt > 0;
}

/*@
    predicate is_ge_30(integer x) = x >= 30;
*/

bool func2(int x)
{
    bool result;

    //@ assert -40 <= x <= 40;
    result = (x >= 30);
    //@ assert result == (x >= 30);
    return result;
}

/*@
    predicate valid_triangle_sides(integer a, integer b, integer c) =
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    predicate valid_angle(integer angle) = -40 <= angle <= 40;

    predicate triangle_condition(integer a, integer b, integer c, integer angle) =
        (result_condition(a, b, c) && (angle >= 30)) || 
        (!result_condition(a, b, c) && (angle < 30));
*/

bool triangle_analysis(int a, int b, int c, int angle)
{
    bool side_check = func1(a, b, c);
    bool angle_check = func2(angle);
    
    bool result = (side_check && angle_check) || (!side_check && !angle_check);
    
    //@ assert result <==> triangle_condition(a, b, c, angle);
    return result;
}
