#include <stdbool.h>
#include <stddef.h>

/*@
    requires len > 0;
    requires \valid_read(s + (0 .. len-1));
    ensures \result <==> (\forall size_t i; 0 <= i < (len) ==> (s)[i] > (threshold));
*/
bool check_greater_than_threshold(const unsigned int *s, size_t len, unsigned int threshold)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> s[j] > threshold;
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (s[i] <= threshold)
        {
            //@ assert !(\forall size_t i; 0 <= i < (len) ==> (s)[i] > (threshold));
            return false;
        }
        i++;
    }
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (s)[i] > (threshold));
    return true;
}

/*@
    requires len > 0;
    requires \valid_read(s + (0 .. len-1));
    ensures \result <==> (\forall size_t i; 0 <= i < (len) ==> (s)[i] >= (threshold));
*/
bool check_greater_than_threshold_or_equal(const unsigned int *s, size_t len, unsigned int threshold)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> s[j] >= threshold;
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (s[i] < threshold)
        {
            //@ assert !(\forall size_t i; 0 <= i < (len) ==> (s)[i] >= (threshold));
            return false;
        }
        i++;
    }
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (s)[i] >= (threshold));
    return true;
}

int main(void)
{
    return 0;
}
