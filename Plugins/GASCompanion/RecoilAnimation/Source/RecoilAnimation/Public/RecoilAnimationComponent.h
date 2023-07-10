// Designed by Hitman's Store, 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/TimelineComponent.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/KismetMathLibrary.h"
#include "RecoilAnimationComponent.generated.h"

class UStoredData;
class UUserWidget;

DECLARE_LOG_CATEGORY_EXTERN(LogRecoilAnimation, Log, All);

DECLARE_DELEGATE(FDoTransition);
DECLARE_DELEGATE_RetVal(bool, FCheckCondition);

UENUM(BlueprintType)
enum ESolverType_PRAS
{
	Legacy UMETA(DisplayName="Legacy", ToolTip="Based on Lerp and SpringInterp"),
	Advanced UMETA(DisplayName="Advanced", ToolTip="Based on curves")
};

UENUM(BlueprintType)
enum EFireMode_PRAS
{
	Semi UMETA(DisplayName = "Semi"),
	Auto UMETA(DisplayName = "Auto"),
	Burst UMETA(DisplayName = "Burst"),
};

/** Essentials for procedural animation solver */
USTRUCT(BlueprintType)
struct FRecoilAnimData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* SingleRot = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* SingleLoc = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* AutoRot = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* AutoLoc = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* RestRot = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Advanced | Curve")
	UCurveVector* RestLoc = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Common")
	FString SlotName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Common")
	TEnumAsByte<ESolverType_PRAS> SolverType = Advanced;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Values")
	UStoredData* StoredData = nullptr;
};

/** Disables axis */
USTRUCT(BlueprintType)
struct FMuteAxis
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	bool X = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	bool Y = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	bool Z = false;
};

USTRUCT()
struct FStartRest
{
	GENERATED_BODY()

	FStartRest() = default;

	FStartRest(bool X, bool Y, bool Z) : X(X), Y(Y), Z(Z)
	{
	}
	
	bool X = false;
	bool Y = false;
	bool Z = false;
};

USTRUCT()
struct FAnimState_PRAS
{
	GENERATED_BODY()

	/** Defines whether it's possible to start transition */
	FCheckCondition TransitionCondition;

	/** This will be executed in Play() */
	FDoTransition OnPlay;

	/** This will be executed in Stop() */
	FDoTransition OnStop;
};

USTRUCT(BlueprintType)
struct FInputScale_PRAS
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D Pitch = FVector2D::UnitVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D Kick = FVector2D::UnitVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D KickR = FVector2D::UnitVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D KickUp = FVector2D::UnitVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector4 Yaw = FVector4(1, 1, 1, 1);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector4 Roll = FVector4(1, 1, 1, 1);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D Noise = FVector2D::UnitVector;

	// X - Pitch, Y - Z offset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FVector2D Progression = FVector2D::UnitVector;
	
	FInputScale_PRAS operator* (const FInputScale_PRAS& A) const
	{
		FInputScale_PRAS NewScale;

		NewScale.Pitch *= A.Pitch;
		NewScale.Kick *= A.Kick;
		NewScale.KickR *= A.KickR;
		NewScale.KickUp *= A.KickUp;
		NewScale.Yaw *= A.Yaw;
		NewScale.Roll *= A.Roll;
		NewScale.Noise *= A.Noise;
		NewScale.Progression *= A.Progression;

		return NewScale;
	}

	void operator*= (const FInputScale_PRAS& A)
	{
		Pitch *= A.Pitch;
		Kick *= A.Kick;
		KickR *= A.KickR;
		KickUp *= A.KickUp;
		Yaw *= A.Yaw;
		Roll *= A.Roll;
		Noise *= A.Noise;
		Progression *= A.Progression;
	}

	FInputScale_PRAS operator/ (const FInputScale_PRAS& A) const
	{
		FInputScale_PRAS NewScale;

		NewScale.Pitch /= A.Pitch;
		NewScale.Kick /= A.Kick;
		NewScale.KickR /= A.KickR;
		NewScale.KickUp /= A.KickUp;
		NewScale.Yaw /= A.Yaw;
		NewScale.Roll /= A.Roll;
		NewScale.Noise /= A.Noise;
		NewScale.Progression /= A.Progression;
		
		return NewScale;
	}

	void operator/= (const FInputScale_PRAS& A)
	{
		Pitch /= A.Pitch;
		Kick /= A.Kick;
		KickR /= A.KickR;
		KickUp /= A.KickUp;
		Yaw /= A.Yaw;
		Roll /= A.Roll;
		Noise /= A.Noise;
		Progression /= A.Progression;
	}
	
	void Reset()
	{
		Pitch = Kick = KickR = KickUp = Noise = Progression = FVector2D::UnitVector;
		Yaw = Roll = FVector4(1, 1, 1, 1);
	}
};

UCLASS(ClassGroup=(RecoilAnimation), meta=(BlueprintSpawnableComponent))
class RECOILANIMATION_API URecoilAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URecoilAnimationComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void Init(const FRecoilAnimData Data, const float Rate = 0.0f, const int Bursts = 0);
	
	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void Play();
	
	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void Stop();
	
	FORCEINLINE FTransform GetOutput() const { return FTransform(OutRot, OutLoc); };
	
	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void SetFireMode(EFireMode_PRAS NewMode);

	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void SetAimingStatus(bool bStatus);

	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void SaveData();

	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void ScaleInput(FInputScale_PRAS NewScale);

	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void UnscaleInput(FInputScale_PRAS NewScale);

	UFUNCTION(BlueprintCallable, Category = "Essentials")
	void ResetInputScale();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Debug", meta=(DevelopmentOnly))
	FORCEINLINE EFireMode_PRAS GetFireMode() const { return FireMode; };
	
	/** Returns time since the last shot */
	UFUNCTION(BlueprintCallable, Category = "Debug")
	float GetDelta() const;
	
	UFUNCTION(BlueprintCallable, Category = "Debug", meta=(DevelopmentOnly))
	void Simulate(bool bStartSim);
	
	UFUNCTION(BlueprintCallable, Category = "Debug", meta=(DevelopmentOnly))
	void ShowUI();
	
	UFUNCTION(BlueprintCallable, Category = "Debug", meta=(DevelopmentOnly))
	void HideUI();
	
	void AddEvent(float Time, FOnTimelineEvent Event);

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	FMuteAxis MuteRot;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	FMuteAxis MuteLoc;
	
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Recoil Animation")
	FRecoilAnimData AnimData;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Recoil Animation")
	FInputScale_PRAS InputScale;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void AnimationUpdate(FVector VectorAlpha);

	UFUNCTION()
	void CalculateTargetData();

	/**
	 * Interpolation between values using curve as an alpha
	 * @param Last is the last alpha value
	 * @param Current is the current alpha value
	 * @param bStartRest determines whether to start rest curve or not
	 * @param StartVal is the A parameter of Lerp
	 */
	double CorrectStart(double& Last, const double Current, bool& bStartRest, double& StartVal);

	/** Frame rate independent Lerp */
	FORCEINLINE double GLerp(double A, double B, double Alpha, double DeltaTime)
	{
		return FMath::Lerp(A, B, 1 - FMath::Exp(-Alpha * DeltaTime));
	};

	FVector GLerp(FVector A, FVector B, FVector Alpha, float DeltaTime);

	FRotator GLerp(FRotator A, FRotator B, FVector Alpha, float DeltaTime);
	
	void SetupStateMachine();

	void SetSimulationTimer(float SemiDelay);
	
	/**
     * Returns a normalized random float *
     * @param RecoilProfile defines minimum (rand between X and Y) and maximum (rand between Z and W) values
     */
	double GetAngularRecoil(const FVector4 RecoilProfile);

	/** Sets current playback to the absolute position to compensate timer error */
	void CorrectAlpha(const UCurveVector* Rotation, const UCurveVector* Location, const float TimeCorrection);

	/** Sets up curves and timeline for another state */
	void SetupTransition(FRotator StartRot, FVector StartLoc, UCurveVector* Rot, UCurveVector* Loc);
	
	void SetupComponent();

	void TickAdvancedSolver(float DeltaTime);

	/** Performs a spring interpolation to zero */
	float DampSpring(float Current, FFloatSpringState& SpringState, float Stiffness, float Damping, float DeltaTime);

	void ApplySmoothing(float DeltaTime);
	void ApplyNoise(FTransform& Finalized, float DeltaTime);
	void ApplyPushback(FTransform& Finalized, float DeltaTime);
	void ApplyProgression(FTransform& Finalized, float DeltaTime);

	double GetNonZero(double OldValue, double NewValue) const
	{
		if(FMath::IsNearlyZero(NewValue))
		{
			return OldValue;
		}

		return NewValue;
	}
	
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Recoil Animation Output", meta=(AllowPrivateAccess=true))
	FRotator OutRot;
	
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Recoil Animation Output", meta=(AllowPrivateAccess=true))
	FVector OutLoc;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> WidgetClass;

	/** Temporary container for rotation curve */
	UPROPERTY()
	UCurveVector* TempRot;

	/** Temporary container for location curve */
	UPROPERTY()
	UCurveVector* TempLoc;
	
	UPROPERTY()
	class UHelperWidget* Widget;
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category = "Essentials")
	bool bIsAiming = false;

	/** Time of the last shot */
	float LastShotTime = 0.f;

	FTimerHandle TimerHandle;
	FTimeline AnimTimeline;

	/* Important
	 * 0 = X
	 * 1 = Y
	 * 2 = Z
	 */
	FStartRest CanRestRot;
	FStartRest CanRestLoc;

	FRotator StartValRot;
	FVector StartValLoc;

	FRotator TargetRot;
	FVector TargetLoc;

	/** These are current spring states used by FloatSpingInterp */
	FFloatSpringState PitchState;
	FFloatSpringState RollState;
	FFloatSpringState KickState;

	/** Binds a member function to the Timeline Tick() */
	FOnTimelineVector ProgressFunction;

	/** If simulation enabled or not */
	bool bSim;

	/** Must be updated whenever current fire mode is changed */
	TEnumAsByte<EFireMode_PRAS> FireMode;

	/** Weapon's fire rate in shots per minute */
	float FireRate;

	/** How long the burst queue should be */
	int BurstAmount;

	/** Current burst counter */
	int BurstCounter;

	/** Simplified state machine for animation states */
	TArray<FAnimState_PRAS> StateMachine;
	uint8 CurrentStateIndex = 0;

	/** Raw non-interp data */
	FRotator RawOutRot;
	FVector RawOutLoc;

	/** True when in Burst or FullAuto state */
	bool bEnableSmoothing = false;

	/** 1 - Animation is active and playing. 0 - Animation is either ended or blending out */
	bool bAnimActive = true;

	FVector2D Noise2DTarget = FVector2D::ZeroVector;
	FVector2D Noise2DCurrent = FVector2D::ZeroVector;
	FVector2D NoiseSpeed = FVector2D::ZeroVector;

	double PushbackTarget = 0;
	double PushbackCurrent = 0;
	double PushbackOut = 0;
	double PushbackSpeed = 0;

	FRotator LerpedRot;
	FVector LerpedLoc;
	
	FVector2D PitchProgress = FVector2D::ZeroVector;
	FVector2D ZProgress = FVector2D::ZeroVector;
	double PitchProgressSpeed = 0;
	double ZProgressSpeed = 0;
};