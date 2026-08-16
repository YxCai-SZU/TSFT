/*@
    predicate first_greater_than_last{L}(int *s, integer len) =
        len > 0 ==> s[0] > s[len-1];
*/

/*@
    requires \valid_read(v + (0..len-1));
    requires len > 0;
    ensures \result <==> first_greater_than_last(v, len);
*/
int func(int *v, int len) {
    int last_element;
    int result;
    
    //@ assert len > 0;
    
    last_element = v[len - 1];
    result = v[0] > last_element;
    
    return result;
}
