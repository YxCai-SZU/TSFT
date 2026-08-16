/*@
    predicate max_element{L}(int *s, integer len, integer max) =
        \exists integer i; 0 <= i < len && s[i] == max &&
        \forall integer i; 0 <= i < len ==> s[i] <= max;

    predicate min_element{L}(int *s, integer len, integer min) =
        \exists integer i; 0 <= i < len && s[i] == min &&
        \forall integer i; 0 <= i < len ==> s[i] >= min;
*/

/*@
    requires \valid_read(v + (0 .. 3));
    requires v[0] == a && v[1] == b && v[2] == c && v[3] == d;
    ensures \result == 1;
*/
int contains_all(int *v, int a, int b, int c, int d) {
    //@ assert v[0] == a && v[1] == b && v[2] == c && v[3] == d;
    return 1;
}
