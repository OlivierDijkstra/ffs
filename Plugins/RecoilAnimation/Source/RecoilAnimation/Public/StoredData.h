// Designed by Hitman's Store, 2022

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StoredData.generated.h"

USTRUCT(BlueprintType)
struct FProgression
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Accel = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Damping = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Amount = 0.f;
};

UCLASS(BlueprintType)
class RECOILANIMATION_API UStoredData : public UDataAsset
{
	GENERATED_BODY()

public:
	/** Tries to load data asset */
	static UStoredData* FindDataAsset(const FString& SlotName, const UWorld* const World);
	
	/** Saves recoil animation data by creating a data asset */
	void SaveData(UPackage* Package, const FString& SlotName);
	
	/** How fast to Lerp to the Target value */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Legacy | Velocity")
	FVector AccelRot = FVector::ZeroVector;

	/** How fast to Lerp to the Target value */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Legacy | Velocity")
	FVector AccelLoc = FVector::ZeroVector;

	/** How fast to Lerp to 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Legacy | Velocity")
	FVector DampRot = FVector::ZeroVector;

	/** How fast to Lerp to 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Legacy | Velocity")
	FVector DampLoc = FVector::ZeroVector;

	/** Damping factor for Pitch spring */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"), Category = "Legacy | Pitch")
	float PitchDamping = 0.f;

	/** How much should oscillate around the target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"), Category = "Legacy | Pitch")
	float PitchStiffness = 0.f;

	/** Damping factor for Roll spring */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"), Category = "Legacy | Roll")
	float RollDamping = 0.f;

	/** How much should oscillate around the target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"), Category = "Legacy | Roll")
	float RollStiffness = 0.f;

	/** Damping factor for Kickback spring */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"),
		Category = "Legacy | Kickback")
	float KickDamping = 0.f;

	/** How much should oscillate around the target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0"),
		Category = "Legacy | Kickback")
	float KickStiffness = 0.f;

	/** Target values for Pitch when aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D PitchAim = FVector2D::ZeroVector;

	/** Target values for Yaw when aiming
	 * X - min min
	 * Y - min max
	 * Z - max min
	 * W - max max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector4 YawAim = FVector4(0, 0, 0, 0);

	/** Target values for Roll when aiming
	 * X - min min
	 * Y - min max
	 * Z - max min
	 * W - max max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector4 RollAim = FVector4(0, 0, 0, 0);

	/** Target values for Pitch when not aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D PitchHip = FVector2D::ZeroVector;

	/** Target values for Yaw when not aiming
	 * X - min min
	 * Y - min max
	 * Z - max min
	 * W - max max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector4 YawHip = FVector4(0, 0, 0, 0);

	/** Target values for Roll when not aiming
	 * X - min min
	 * Y - min max
	 * Z - max min
	 * W - max max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector4 RollHip = FVector4(0, 0, 0, 0);

	/** Target values for Kickback when aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickAim = FVector2D::ZeroVector;

	/** Target values for Kickback Right when aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickAimR = FVector2D::ZeroVector;

	/** Target values for Kickback Up when aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickAimUp = FVector2D::ZeroVector;

	/** Target values for Kickback when not aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickHip = FVector2D::ZeroVector;

	/** Target values for Kickback Right when not aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickHipR = FVector2D::ZeroVector;

	/** Target values for Kickback Up when not aiming
	 * X - min
	 * Y - max
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	FVector2D KickHipUp = FVector2D::ZeroVector;

	/** Smooth amount in Auto mode. 0 means no smoothing */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Smoothing")
	FRotator SmoothRot = FRotator::ZeroRotator;

	/** Smooth amount in Auto mode. 0 means no smoothing */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Smoothing")
	FVector SmoothLoc = FVector::ZeroVector;

	/** Multiplier for each rotation axis while in Semi/Auto state */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Smoothing")
	FRotator MultiRot = FRotator(1.f, 1.f, 1.f);

	/** Multiplier for each translation axis while in Semi/Auto state */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Smoothing")
	FVector MultiLoc = FVector(1.f, 1.f, 1.f);

	/** Enables smoothing for Roll target values */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Smoothing")
	bool bSmoothRoll = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Noise 2D Layer")
	FVector2D Noise2DTarget = FVector2D::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Noise 2D Layer")
	FVector2D Noise2DAccel = FVector2D::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Noise 2D Layer")
	FVector2D Noise2DZero = FVector2D::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Noise 2D Layer")
	float NoiseAimScalar = 1.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pushback")
	float Pushback = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pushback")
	float PushbackZero = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pushback")
	float PushbackAccel = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Progression")
	FProgression PitchProgress;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Progression")
	FProgression ZProgress;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Progression")
	float ProgressAimAlpha = 0.f;

	/** Playback position used for getting start value during Semi-Auto transition */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Timeline")
	float PlaybackOffset = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Timeline")
	float PlayRate = 1.f;

private:
	FString GetPackagePath(const FString& SlotName) const;
};