// Generated C + ACSL

#define MAX_MODELS 10

// Global variables that the contracts reference
int registeredModels[MAX_MODELS];
int registeredModelsCount;

/*@
    requires \valid(registeredModels + (0 .. registeredModelsCount - 1));
    requires registeredModelsCount >= 0;
    requires registeredModelsCount < MAX_MODELS;
    requires \forall integer i; 0 <= i < registeredModelsCount ==>
             registeredModels[i] != modelType;
    assigns registeredModels[0 .. registeredModelsCount], registeredModelsCount;
    ensures registeredModelsCount == \old(registeredModelsCount) + 1;
    ensures registeredModels[\old(registeredModelsCount)] == modelType;
    ensures \forall integer i; 0 <= i < \old(registeredModelsCount) ==>
            registeredModels[i] == \old(registeredModels[i]);
    ensures \exists integer i; 0 <= i < registeredModelsCount &&
            registeredModels[i] == modelType;
*/
void registerModel(int modelType)
{
  registeredModels[registeredModelsCount] = modelType;
  registeredModelsCount++;
}

/*@
    assigns registeredModelsCount;
*/
void registerAll(void)
{
  registeredModelsCount = 0;
}

/*@
  predicate isRegistered(integer modelType) =
    \exists integer i; 0 <= i < registeredModelsCount && registeredModels[i] == modelType;
*/