#include "ffsAnimInstance.h"
// #include "ffsCharacter.h"

void UffsAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // auto PlayerCharacter = Cast<AffsCharacter>(TryGetPawnOwner());
    // if (!PlayerCharacter)
    // {
    //     UE_LOG(LogTemp, Error, TEXT("gamersAnimInstance::NativeInitializeAnimation() - Invalid Character!"));
    //     return;
    // }
    
    // RecoilAnimation = PlayerCharacter->GetRecoilAnimation();
    // if (!RecoilAnimation)
    // {
    //     UE_LOG(LogTemp, Error, TEXT("gamersAnimInstance::NativeInitializeAnimation() - Null RecoilAnimation!"));
    // }
}

void UffsAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
}