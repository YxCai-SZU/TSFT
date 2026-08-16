// Generated C + ACSL

// ```c
// /*@
//   axiomatic EcCuadDiv2_Lemma_properties {
//     lemma EcCuadDiv2_Lemma_statement:
//       \forall integer x; x >= 1 ==> (x * x + x) % 2 == 0;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic EcCubicaDiv6_Lemma_properties {
    // Lemma: For any integer x >= 1, the expression x³ + 3x² + 2x is divisible by 6
    // This is equivalent to x(x+1)(x+2) being divisible by 6 (product of 3 consecutive integers)
//     lemma EcCubicaDiv6_Lemma:
//       \forall integer x;
//         x >= 1 ==>
//         (x * x * x + 3 * x * x + 2 * x) % 6 == 0;
//   }
// */

// Proof hint: The lemma uses recursive reasoning on x.
// Base case: x = 1 gives (1 + 3 + 2) = 6, which is divisible by 6.
// Inductive step: Assumes property holds for (x-1), then shows it holds for x by:
//   1. Expanding (x-1)³ + 3(x-1)² + 2(x-1) using binomial expansion
//   2. Showing x³ - x is divisible by 6 (difference of consecutive terms)
//   3. Using EcCuadDiv2_Lemma to show x² + x is divisible by 2
//   4. Combining these facts to prove x³ + 3x² + 2x ≡ 0 (mod 6)
// Mathematical insight: x³ + 3x² + 2x = x(x²+3x+2) = x(x+1)(x+2), 
// which is always divisible by 6 as it's the product of 3 consecutive integers.
// ```

// ```c
// /*@
//   axiomatic cubEven_Lemma_properties {
//     lemma cubEven_Lemma_statement:
//       \forall integer x;
//         (x * x * x + 5) % 2 == 1 ==> x % 2 == 0;

//     lemma cubEven_Lemma_proof_hint:
//       \forall integer x;
//         x % 2 == 1 ==>
//           \exists integer k;
//             k == (x - 1) / 2 &&
//             x * x * x + 5 == 2 * (4 * k * k * k + 6 * k * k + 3 * k + 3);
//   }
// */

// Lemma: cubEven_Lemma
// Property: If x³ + 5 is odd, then x must be even
// Proof hint: Proof by contradiction. Assume x is odd (x = 2k+1).
//             Then x³ + 5 = (2k+1)³ + 5 = 8k³ + 12k² + 6k + 6 = 2(4k³ + 6k² + 3k + 3),
//             which is even, contradicting the requirement that (x³ + 5) % 2 == 1.
//             Therefore x must be even.
// ```

// ```c
// /*@
//   axiomatic PerfectCube_Lemma_properties {
//     lemma perfectCube_Lemma_statement:
//       \forall integer x;
//         \exists integer z;
//           x * x * x == 3 * z ||
//           x * x * x == 3 * z + 1 ||
//           x * x * x == 3 * z - 1;

//     lemma perfectCube_Lemma_case0:
//       \forall integer x, integer k;
//         x % 3 == 0 && k == x / 3 ==>
//           x * x * x == 3 * (9 * k * k * k);

//     lemma perfectCube_Lemma_case1:
//       \forall integer x, integer k;
//         x % 3 == 1 && k == (x - 1) / 3 ==>
//           x * x * x == 3 * (9 * k * k * k + 9 * k * k + 3 * k) + 1;

//     lemma perfectCube_Lemma_case2:
//       \forall integer x, integer k;
//         x % 3 == 2 && k == (x - 2) / 3 ==>
//           x * x * x == 3 * (9 * k * k * k + 18 * k * k + 12 * k + 3) - 1;
//   }
// */
// ```

/*@ logic integer exp_logic(integer x, integer e); */

/*@
  requires e >= 0;
  decreases e;
*/
int exp(int x, int e)
{
  /*@ assert e >= 0; */
  return ((e == 0)) ? (1) : ((x * exp(x, (e - 1))));
}

// ```c
// /*@
//   axiomatic expGET1_Lemma_properties {
//     lemma expGET1_Lemma_statement:
//       \forall integer x, integer e;
//         x >= 1 && e >= 0 ==> exp(x, e) >= 1;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic prodMon_Lemma_properties {
//     lemma prodMon_Lemma_statement:
//       \forall integer z, a, b;
//         (z >= 1 && a >= b && b >= 1) ==>
//         (z * a >= z * b);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic expMon_Lemma_properties {
//     lemma expMon_Lemma_statement:
//       \forall integer x, integer n;
//         (x >= 1 && n >= 1) ==>
//         exp(x + 1, n) >= exp(x, n) + 1;
//   }
// */
// ```