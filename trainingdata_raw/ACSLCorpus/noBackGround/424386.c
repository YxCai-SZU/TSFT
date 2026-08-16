#include <stddef.h>
#include <stdint.h>

/*@
  requires ((\valid(((a)) + (0 .. ((n))-1))) && (\valid(((b)) + (0 .. ((m))-1))) && (n) > 0 && (m) > 0);
  ensures 0 <= \result <= m;
*/
size_t func(size_t n, int64_t *a, size_t m, int64_t *b)
{
    size_t ans = 0;
    size_t i = 0;
    size_t j = 0;
    int64_t b_elem = 0;
    int found = 0;

    //@ assert 0 <= i <= m;
    //@ assert 0 <= ans <= i;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= ans <= i;
        loop invariant ((\valid(((a)) + (0 .. ((n))-1))) && (\valid(((b)) + (0 .. ((m))-1))) && (n) > 0 && (m) > 0);
        loop assigns i, ans, j, b_elem, found;
        loop variant m - i;
    */
    while (i < m)
    {
        b_elem = b[i];
        j = 0;
        found = 0;
        
        /*@ loop invariant 0 <= j <= n;
            loop invariant 0 <= ans <= i;
            loop invariant ((\valid(((a)) + (0 .. ((n))-1))) && (\valid(((b)) + (0 .. ((m))-1))) && (n) > 0 && (m) > 0);
            loop invariant i < m;
            loop invariant found == 0;
            loop assigns j, ans, found;
            loop variant n - j;
        */
        while (j < n)
        {
            if (a[j] == b_elem)
            {
                ans += 1;
                found = 1;
                break;
            }
            j += 1;
        }
        
        if (found == 0)
        {
            ans += 1;
        }
        
        i += 1;
        //@ assert 0 <= ans <= i;
    }
    
    //@ assert ans <= m;
    return ans;
}
