#pragma once

class Offsets
{
public:
	// APlayerController
	static constexpr int PlayerCameraManager = 0x518;

		
	// AAthenaCharacter
	static constexpr int WieldedItemComponent = 0x820;
	static constexpr int HealthComponent = 0x848;
			
	// UWieldedItemComponent
	static constexpr int CurrentlyWieldedItem = 0x2B0;

	// AWieldableItem
	static constexpr int WieldableItemName = 0x580; // ItemName property
		
	// APlayerCameraManager
	static constexpr int CameraCache = 0x500;
	static constexpr int CameraCachePOV = CameraCache + 0x10;
	static constexpr int CameraLocation = CameraCachePOV + 0x0;
	static constexpr int CameraRotation = CameraCachePOV + 0xC;
	static constexpr int CameraFOV = CameraCachePOV + 0x18;
	
	// UIslandDataAsset
	static constexpr int IslandDataEntries = 0x40;
	static constexpr int IslandDataEntriesCount  = IslandDataEntries + 0x8;

	// UIslandDataAssetEntry
	static constexpr int IslandName = 0x28;
	static constexpr int TreasureMaps = 0x30;

	// AXMarksTheSpotMap
	static constexpr int MapTexturePath = 0x888;
	static constexpr int Marks = 0x8C8;
	static constexpr int MarksCount = Marks + 0x8;

#pragma region Almsonst never changing offsets
	// UObject
	static constexpr int Id = 0x18;

	// UWorld
	static constexpr int PersistentLevel = 0x30; // ULevel
	static constexpr int ActorsTArray = 0xA0; // Uknown offsets
	static constexpr int ActorsTArrayCount = ActorsTArray + 0x8;
	static constexpr int OwningGameInstance = 0x1C0;

	// UGameInstance
	static constexpr int LocalPlayers = 0x38;

	// UPlayer
	static constexpr int PlayerController = 0x30;

	// AActor		
	static constexpr int RootComponent = 0x178;

	// APawn
	static constexpr int PlayerState = 0x4A8;

	// AController
	static constexpr int Pawn = 0x490; // LocalPlayer

	// APlayerState
	static constexpr int PlayerId = 0x4B0;	
	static constexpr int PlayerName = 0x490;

	// UHealthComponent
	static constexpr int CurrentHealth = 0xDC;
	static constexpr int MaxHealth = 0xD0;

	// USceneComponent
	static constexpr int RelativeLocation = 0x1B0;
	static constexpr int RelativeRotation = RelativeLocation + 0xC;
	static constexpr int RelativeRotationYaw = RelativeRotation + 0x4;

	// AIslandService
	static constexpr int IslandDataAsset = 0x4E8;

	// FTreasureMapData
	static constexpr int TreasureLocations = 0x10;
	static constexpr int TreasureLocationsCount = TreasureLocations + 0x8;
#pragma endregion
};

