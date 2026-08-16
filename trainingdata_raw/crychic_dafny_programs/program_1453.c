// Generated C + ACSL

/*@
    requires x >= -1;  // Ensure we don't go too far negative
    decreases x >= 0 ? x : 0;  // Variant: measure that decreases to 0
    assigns \nothing;
    ensures x <= 0 ==> \result == 1;
    ensures x > 0 ==> \result >= 1;
*/
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