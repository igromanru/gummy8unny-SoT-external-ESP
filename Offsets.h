#pragma once

class Offsets
{
public:
	// APlayerController
	static const int PlayerCameraManager = 0x518;
		
	// AAthenaCharacter
	static const int WieldedItemComponent = 0x820;
	static const int HealthComponent = 0x848;
			
	// UWieldedItemComponent
	static const int CurrentlyWieldedItem = 0x2B0;

	// AWieldableItem
	static const int WieldableItemName = 0x580; // ItemName property
		
	// APlayerCameraManager
	static const int CameraCache = 0x500;
	static const int CameraCachePOV = CameraCache + 0x10;
	
	// UIslandDataAsset
	static const int IslandDataEntries = 0x40;
	static const int IslandDataEntriesCount  = IslandDataEntries + 0x8;

	// UIslandDataAssetEntry
	static const int IslandName = 0x28;
	static const int TreasureMaps = 0x30;

	// AXMarksTheSpotMap
	static const int MapTexturePath = 0x888;
	static const int Marks = 0x8C8;
	static const int MarksCount = Marks + 0x8;

#pragma region Almsonst never changing offsets
	// UObject
	static const int Id = 0x18;

	// UWorld
	static const int PersistentLevel = 0x30; // ULevel
	static const int ActorsTArray = 0xA0; // Uknown offsets
	static const int ActorsTArrayCount = ActorsTArray + 0x8;
	static const int OwningGameInstance = 0x1C0;

	// UGameInstance
	static const int LocalPlayers = 0x38;

	// UPlayer
	static const int PlayerController = 0x30;

	// AActor		
	static const int RootComponent = 0x178;

	// APawn
	static const int PlayerState = 0x4A8;

	// AController
	static const int Pawn = 0x490; // LocalPlayer

	// APlayerState
	static const int PlayerId = 0x4B0;	
	static const int PlayerName = 0x490;

	// UHealthComponent
	static const int CurrentHealth = 0xDC;
	static const int MaxHealth = 0xD0;

	// USceneComponent
	static const int RelativeLocation = 0x1B0;
	static const int RelativeRotation = RelativeLocation + 0xC;
	static const int RelativeRotationYaw = RelativeRotation + 0x4;

	// AIslandService
	static const int IslandDataAsset = 0x4E8;

	// FTreasureMapData
	static const int TreasureLocations = 0x10;
	static const int TreasureLocationsCount = TreasureLocations + 0x8;
#pragma endregion
};

