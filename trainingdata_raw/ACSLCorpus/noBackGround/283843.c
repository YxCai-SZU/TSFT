#include <stdbool.h>
#include <stddef.h>

/*@ requires ((len) > 0 && (len) <= 100 &&
      \forall size_t i; 0 <= i < (len) ==> ((((s)[i]) == '0') || (((s)[i]) == '1')));
    assigns \nothing;
    ensures \result <= len;
    ensures \forall size_t i; 0 <= i < len ==> (((s[i]) == '0') || ((s[i]) == '1')); */
size_t min_flips(const char *s, size_t len) {
    //@ assert ((len) > 0 && (len) <= 100 &&       \forall size_t i; 0 <= i < (len) ==> ((((s)[i]) == '0') || (((s)[i]) == '1')));
    
    char s_new[100];
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> s_new[j] == s[j];
        loop invariant \forall size_t j; 0 <= j < i ==> (((s_new[j]) == '0') || ((s_new[j]) == '1'));
        loop assigns i, s_new[0..len-1];
        loop variant len - i; */
    while (i < len) {
        s_new[i] = s[i];
        i++;
    }
    
    //@ assert i == len;
    //@ assert \forall size_t j; 0 <= j < len ==> s_new[j] == s[j];
    //@ assert \forall size_t j; 0 <= j < len ==> (((s_new[j]) == '0') || ((s_new[j]) == '1'));
    
    size_t ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant ans <= index;
        loop invariant \forall size_t k; 0 <= k < len ==> (((s_new[k]) == '0') || ((s_new[k]) == '1'));
        loop assigns ans, index;
        loop variant len - index; */
    while (index < len) {
        if (index == 0) {
            ans++;
        } else {
            char prev_char = s_new[index - 1];
            char current_char = s_new[index];
            if (prev_char != current_char) {
                ans++;
            }
        }
        index++;
    }
    
    //@ assert ans <= len;
    return ans;
}
