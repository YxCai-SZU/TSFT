#include <stddef.h>

/*@ requires \valid_read(s+(0..4));
    requires \valid_read(t+(0..6));
    requires ((5) == 5);
    requires ((7) == 7);
    ensures ((5) + (7)) == 12;
*/
void func(char *s, char *t) {
    // Variable declarations at scope top
    size_t s_len = 5;
    size_t t_len = 7;
    size_t sum = 0;

    //@ assert s_len == 5;
    //@ assert t_len == 7;
    //@ assert (((integer)s_len) + ((integer)t_len)) == 12;
    sum = s_len + t_len;
    //@ assert sum == 12;
}
