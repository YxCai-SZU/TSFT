#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid_read(s + (0 .. s_len-1));
    requires \valid_read(t + (0 .. t_len-1));
    requires ((s_len) == (t_len));
    requires ((s_len) <= 0x80000000);
    assigns \nothing;
    ensures \result <= s_len;
    ensures \forall size_t i; 0 <= i < s_len ==> (s[i] != t[i] ==> \result > 0);
*/
size_t min_operations(const int32_t *s, size_t s_len, const int32_t *t, size_t t_len)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= s_len;
        loop invariant count <= i;
        loop invariant ((s_len) == (t_len));
        loop invariant ((s_len) <= 0x80000000);
        loop invariant \forall size_t j; 0 <= j < i ==> (s[j] != t[j] ==> count > 0);
        loop invariant count <= s_len;
        loop assigns i, count;
        loop variant s_len - i;
    */
    while (i < s_len && i < t_len)
    {
        //@ assert i < s_len && i < t_len;
        if (s[i] != t[i])
        {
            //@ assert s[i] != t[i];
            count++;
        }
        i++;
    }
    //@ assert count <= s_len;
    return count;
}
