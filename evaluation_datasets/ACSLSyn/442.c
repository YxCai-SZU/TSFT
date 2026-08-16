#include <stdbool.h>
#include <stdint.h>

/* Function 1: Overlap check */
/*@
    predicate valid_range(integer a, integer b, integer c, integer d) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= c <= 100 &&
        1 <= d <= 100;

    logic integer min(integer x, integer y) = (x <= y) ? x : y;
    logic integer max(integer x, integer y) = (x <= y) ? y : x;

    predicate intervals_overlap(integer a, integer b, integer c, integer d) =
        (a <= c && c <= b) ||
        (a <= d && d <= b) ||
        (c <= a && a <= d) ||
        (c <= b && b <= d);

    lemma overlap_symmetric:
        \forall integer a,b,c,d;
        intervals_overlap(a,b,c,d) <==> intervals_overlap(c,d,a,b);
*/

bool overlap_func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int i;

    if (a > c)
    {
        i = a;
    }
    else
    {
        i = c;
    }

    if (b > d)
    {
        i = b;
    }
    else
    {
        i = d;
    }

    if ((a <= c && c <= b) ||
        (a <= d && d <= b) ||
        (c <= a && a <= d) ||
        (c <= b && b <= d))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Function 2: Count odd numbers */

int32_t count_func(uint32_t n)
{
    int32_t result = 0;
    uint32_t count = 0;
    uint32_t i = 1;
    
    while (i <= n) {
        if (i % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    
    result = (int32_t)count;
    return result;
}

/* Function 3: Circle in rectangle check */
/*@
    predicate in_range(integer val, integer low, integer high) =
        low <= val <= high;

    predicate circle_in_rect(integer w, integer h, integer x, integer y, integer r) =
        in_range(w, 0, 10000) &&
        in_range(h, 0, 10000) &&
        in_range(x, 0, w) &&
        in_range(y, 0, h) &&
        in_range(r, 0, 10000) &&
        r <= x <= w - r &&
        r <= y <= h - r;

    lemma circle_center_valid:
        \forall integer w, h, x, y, r;
            circle_in_rect(w, h, x, y, r) ==>
            (x >= r && x <= (w - r) && y >= r && y <= (h - r));
*/

bool circle_func(int w, int h, int x, int y, int r)
{
    bool result;

    result = (x >= r) && (x <= (w - r)) && (y >= r) && (y <= (h - r));
    return result;
}

/* Function 4: Bound check */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
    
    logic integer compute_bound(integer x) = (x / 3) * 3 + (x % 3);
    
    lemma bound_within_range: 
        \forall integer x; is_valid_range(x) ==> compute_bound(x) <= 100;
*/

_Bool bound_func(unsigned int x, unsigned int a) {
    unsigned int quotient;
    unsigned int remainder;
    _Bool can_buy;
    
    quotient = x / 3;
    remainder = x % 3;
    can_buy = 0;
    
    if (quotient * 3 + remainder >= a) {
        can_buy = 1;
    }
    
    return can_buy;
}

/*@
    predicate packet_accepted(integer a, integer b, integer c, integer d,
                              integer n,
                              integer w, integer h, integer x, integer y, integer r,
                              integer x_res, integer a_res) =
        intervals_overlap(a,b,c,d) &&
        (n + 1) / 2 > 0 &&
        circle_in_rect(w, h, x, y, r) &&
        a_res <= compute_bound(x_res);
*/

bool packet_filter(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
                   uint32_t n,
                   int w, int h, int x, int y, int r,
                   unsigned int x_res, unsigned int a_res)
{
    bool accept = false;
    
    bool overlap = overlap_func(a, b, c, d);
    
    if (overlap) {
        int32_t allowed_ports = count_func(n);
        
        bool payload_valid = circle_func(w, h, x, y, r);
        
        bool resource_ok = bound_func(x_res, a_res);
        
        if (allowed_ports > 0 && payload_valid && resource_ok) {
            accept = true;
        }
    }
    
    return accept;
}
