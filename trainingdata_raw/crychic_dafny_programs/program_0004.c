// Generated C + ACSL

/*@
    requires e >= 0;
    decreases e;
    assigns \nothing;
    ensures x > 0 ==> \result > 0;
*/
int exp(int x, int e)
{
  return ((e == 0)) ? (1) : ((x * exp(x, (e - 1))));
}

// ```acsl
// /*@
//   axiomatic exp3_Lemma_properties {
//     lemma exp3_Lemma_statement:
//       \forall integer n;
//         n >= 1 ==> (exp(3, n) - 1) % 2 == 0;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic mult8_Lemma_properties {
//     logic integer exp(integer base, integer power);

//     lemma mult8_Lemma_statement:
//       \forall integer n;
//         n >= 1 ==>
//         (exp(3, 2 * n) - 1) % 8 == 0;

//     lemma mult8_Lemma_base_case:
//       (exp(3, 2 * 1) - 1) % 8 == 0;

//     lemma mult8_Lemma_inductive_step:
//       \forall integer n;
//         n >= 2 && (exp(3, 2 * (n - 1)) - 1) % 8 == 0 ==>
//         (exp(3, 2 * n) - 1) % 8 == 0;

//     lemma mult8_Lemma_calc_helper:
//       \forall integer n;
//         n >= 2 ==>
//         exp(3, 2 * n) == exp(3, 2 * (n - 1)) * 9;
//   }
// */
// ```