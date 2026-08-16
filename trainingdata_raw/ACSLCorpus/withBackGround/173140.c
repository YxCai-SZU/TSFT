/*@
    predicate is_u32(integer x) = 0 <= x <= 4294967295;
    
    lemma add_lemma: \forall integer a, b; is_u32(a) && is_u32(b) && a + b <= 4294967295 ==> is_u32(a + b);
    lemma sub_lemma: \forall integer a, b; is_u32(a) && is_u32(b) && a >= b ==> is_u32(a - b);
    lemma mul_lemma: \forall integer a, b; is_u32(a) && is_u32(b) && a * b <= 4294967295 ==> is_u32(a * b);
*/

int main() {
    return 0;
}
