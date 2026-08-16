/*@
predicate positive(integer v) = v > 0;

lemma distributivity_lemma:
  \forall integer x, a, b;
    positive(x) && positive(a) && positive(b) ==>
      x * (a + b) == x * a + x * b;

lemma distributivity_lemma2:
  \forall integer x, a, b;
    positive(x) && positive(a) && positive(b) ==>
      x * (a + b) == x * a + x * b;
*/

/*@
  requires 1 <= r <= 100;
  ensures \result == r * r;
  assigns \nothing;
*/
unsigned long func(unsigned long r)
{
    // Variable declarations at top
    unsigned long result;

    //@ assert r * r <= 100 * 100;
    //@ assert r * r >= 1 * 1;
    
    result = r * r;
    return result;
}

int main()
{
    return 0;
}
