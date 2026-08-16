// Generated C + ACSL

/*@ logic integer trick(integer n, integer m); */

/*@ 
  requires m >= 0;
  requires n >= 0;
  decreases n;
  ensures \result == n;
*/
int trick(int n, int m)
{
  return (((n < m) || (m == 0))) ? (n) : ((trick((n - m), m) + m));
}

// ```c
// /*@
//   axiomatic lemma_trick_properties {
//     lemma lemma_trick_statement:
//       \forall integer n, m; n >= 0 && m >= 0 ==> trick(n, m) == n;
//   }
// */
// ```

// Lemma: calc_trick
// Property: proves that trick(100, 10) evaluates to 100
// Proof hint: This is an automatic proof by evaluation - the lemma body is empty,
//             indicating Dafny can verify this by directly computing trick(100, 10).
//             In ACSL, this would require the definition of trick() to be visible
//             so the SMT solver can evaluate the concrete call.