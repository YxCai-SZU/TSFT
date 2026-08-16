// Generated C + ACSL

// ```c
// /*@
//   axiomatic peasantMultLemma_properties {
//     lemma peasantMultLemma_even:
//       \forall integer a, b;
//         b >= 0 && b % 2 == 0 ==>
//         a * b == 2 * a * (b / 2);
    
//     lemma peasantMultLemma_odd:
//       \forall integer a, b;
//         b >= 0 && b % 2 == 1 ==>
//         a * b == a + 2 * a * ((b - 1) / 2);
//   }
// */
// ```

/*@
    requires b > 0;
    assigns \nothing;
    ensures \result == a * b;
*/
int peasantMult(int a, int b)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  int aa = a;
  int bb = b;
/*@
  loop invariant 0 <= bb <= \at(b, LoopEntry);
  loop invariant r + aa * bb == \at(a, LoopEntry) * \at(b, LoopEntry);
  loop assigns r, aa, bb;
  loop variant bb;
*/
  while ((bb > 0))
    {
      if (((bb % 2) == 0))
      {
        aa = (2 * aa);
        bb = (bb / 2);
      }
      else
      if (((bb % 2) == 1))
      {
        r = (r + aa);
        aa = (2 * aa);
        bb = ((bb - 1) / 2);
      }
    }
  return r;  // Dafny implicit return
}

/*@
    requires a >= 0;
    requires b > 0;
    assigns \nothing;
*/
void euclidianDiv(int a, int b)
{
  int r = a;
  /*@ assert r >= 0 && r <= 2147483647; */
  int q = 0;
  /*@ assert q >= 0 && q <= 2147483647; */
/*@
  loop invariant 0 <= r <= a;
  loop invariant r == a - b * q;
  loop invariant q >= \at(q, LoopEntry);
  loop invariant r == \at(r, LoopEntry) - b * (q - \at(q, LoopEntry));
  loop assigns r, q;
  loop variant r - b;
*/
  while (((r - b) >= 0))
    {
      r = (r - b);
      q = (q + 1);
    }
}
