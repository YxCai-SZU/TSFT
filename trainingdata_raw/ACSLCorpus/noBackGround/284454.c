#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 123 &&
        0 <= (b) && (b) <= 123 &&
        0 <= (c) && (c) <= 123 &&
        0 <= (d) && (d) <= 123 &&
        0 <= (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long is_freed = 0;
    long counter = a;

    //@ assert (0 <= (a) && (a) <= 123 &&         0 <= (b) && (b) <= 123 &&         0 <= (c) && (c) <= 123 &&         0 <= (d) && (d) <= 123 &&         0 <= (e) && (e) <= 123 &&         0 <= (k) && (k) <= 123 &&         (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert a <= counter && counter <= b;
    //@ assert 0 <= is_freed && is_freed <= counter - a;
    //@ assert is_freed == counter - a;

    /*@
        loop invariant a <= counter && counter <= b;
        loop invariant 0 <= is_freed && is_freed <= counter - a;
        loop invariant is_freed == counter - a;
        loop invariant (0 <= (a) && (a) <= 123 &&
        0 <= (b) && (b) <= 123 &&
        0 <= (c) && (c) <= 123 &&
        0 <= (d) && (d) <= 123 &&
        0 <= (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop assigns counter, is_freed;
        loop variant b - counter;
    */
    while (counter < b)
    {
        //@ assert counter < b;
        is_freed += 1;
        counter += 1;
        //@ assert is_freed == counter - a;
    }

    counter = b;
    //@ assert b <= counter && counter <= c;
    //@ assert 0 <= is_freed && is_freed <= counter - a;
    //@ assert is_freed == counter - a;

    /*@
        loop invariant b <= counter && counter <= c;
        loop invariant 0 <= is_freed && is_freed <= counter - a;
        loop invariant is_freed == counter - a;
        loop invariant (0 <= (a) && (a) <= 123 &&
        0 <= (b) && (b) <= 123 &&
        0 <= (c) && (c) <= 123 &&
        0 <= (d) && (d) <= 123 &&
        0 <= (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop assigns counter, is_freed;
        loop variant c - counter;
    */
    while (counter < c)
    {
        //@ assert counter < c;
        is_freed += 1;
        counter += 1;
        //@ assert is_freed == counter - a;
    }

    counter = c;
    //@ assert c <= counter && counter <= d;
    //@ assert 0 <= is_freed && is_freed <= counter - a;
    //@ assert is_freed == counter - a;

    /*@
        loop invariant c <= counter && counter <= d;
        loop invariant 0 <= is_freed && is_freed <= counter - a;
        loop invariant is_freed == counter - a;
        loop invariant (0 <= (a) && (a) <= 123 &&
        0 <= (b) && (b) <= 123 &&
        0 <= (c) && (c) <= 123 &&
        0 <= (d) && (d) <= 123 &&
        0 <= (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop assigns counter, is_freed;
        loop variant d - counter;
    */
    while (counter < d)
    {
        //@ assert counter < d;
        is_freed += 1;
        counter += 1;
        //@ assert is_freed == counter - a;
    }

    counter = d;
    //@ assert d <= counter && counter <= e;
    //@ assert 0 <= is_freed && is_freed <= counter - a;
    //@ assert is_freed == counter - a;

    /*@
        loop invariant d <= counter && counter <= e;
        loop invariant 0 <= is_freed && is_freed <= counter - a;
        loop invariant is_freed == counter - a;
        loop invariant (0 <= (a) && (a) <= 123 &&
        0 <= (b) && (b) <= 123 &&
        0 <= (c) && (c) <= 123 &&
        0 <= (d) && (d) <= 123 &&
        0 <= (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop assigns counter, is_freed;
        loop variant e - counter;
    */
    while (counter < e)
    {
        //@ assert counter < e;
        is_freed += 1;
        counter += 1;
        //@ assert is_freed == counter - a;
    }

    //@ assert is_freed == e - a;
    return e - a <= k;
}
