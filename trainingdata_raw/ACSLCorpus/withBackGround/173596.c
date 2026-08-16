/*@
    logic integer func(integer a, integer b, integer c) =
        a > b ?
            (b > c ? c : b)
        :
            (a > c ? c : a);

    lemma func_properties:
        \forall integer a, b, c;
            0 <= a <= 10000 &&
            0 <= b <= 10000 &&
            0 <= c <= 10000
        ==>
            func(a, b, c) <= a &&
            func(a, b, c) <= b &&
            func(a, b, c) <= c &&
            (func(a, b, c) == a ||
             func(a, b, c) == b ||
             func(a, b, c) == c);
*/

int main()
{
    return 0;
}
