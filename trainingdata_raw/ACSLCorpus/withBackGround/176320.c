/*@
predicate example_pre(integer a, integer b, integer c, integer d) =
    a == b - c + 1 && b == c + d + 1;

predicate example_post(integer a, integer b, integer c, integer d) =
    a == b - c + 1 && b == c + d + 1;

lemma func_example_1:
    \forall integer a, b, c, d;
    example_pre(a, b, c, d) ==> example_post(a, b, c, d);

lemma func_example_2:
    \forall integer a, b, c, d;
    example_pre(a, b, c, d) ==> example_post(a, b, c, d);

lemma func_example_3:
    \forall integer a, b, c, d;
    example_pre(a, b, c, d) ==> example_post(a, b, c, d);
*/

int main() {
    int a;
    int b;
    int c;
    int d;
    
    //@ assert example_pre(a, b, c, d) ==> example_post(a, b, c, d);
    
    return 0;
}
