// Generated C + ACSL

/*@ logic integer More(integer x); */

/*@ decreases (x > 0) ? x : 0;
  @*/
int More(int x)
{
  return ((x <= 0)) ? (1) : ((More((x - 2)) + 3));
}

// ```c
// /*@
//   axiomatic Increasing_properties {
//     lemma Increasing_statement:
//       \forall integer x; x < More(x);
//   }
// */
// ```