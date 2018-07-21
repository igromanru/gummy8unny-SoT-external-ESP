#pragma once

class Offsets
{
public:
	// :APlayerController:PlayerCameraManager:SoT_Engine_classes.hpp
	static constexpr int PlayerCameraManager = 0x0518;
			
	// :AAthenaCharacter:WieldedItemComponent:SoT_Athena_classes.hpp
	static constexpr int WieldedItemComponent = 0x820;
	// :AAthenaCharacter:HealthComponent:SoT_Athena_classes.hpp
	static constexpr int HealthComponent = 0x848;
		
	// :UWieldedItemComponent:CurrentlyWieldedItem:SoT_Athena_classes.hpp
	static constexpr int CurrentlyWieldedItem = 0x02A8;

	// :AWieldableItem:ItemName:SoT_Athena_classes.hpp
	static constexpr int WieldableItemName = 0x580; // ItemName property
		
	// :APlayerCameraManager:CameraCache:SoT_Engine_classes.hpp
	static constexpr int CameraCache = 0x0500;
	// :FCameraCacheEntry:POV:SoT_Engine_structs.hpp
	static constexpr int CameraCachePOV = CameraCache + 0x10;
	static constexpr int CameraLocation = CameraCachePOV + 0x0;
	static constexpr int CameraRotation = CameraCachePOV + 0xC;
	static constexpr int CameraFOV = CameraCachePOV + 0x18;
	
	// :UIslandDataAsset:IslandDataEntries:SoT_Athena_classes.hpp
	static constexpr int IslandDataEntries = 0x40;
	static constexpr int IslandDataEntriesCount  = IslandDataEntries + 0x8;

	// :UIslandDataAssetEntry:IslandName:SoT_Athena_classes.hpp
	static constexpr int IslandName = 0x0028;
	// :UIslandDataAssetEntry:TreasureMaps:SoT_Athena_classes.hpp
	static constexpr int TreasureMaps = 0x30;

	// :AXMarksTheSpotMap:MapTexturePath:SoT_Athena_classes.hpp
	static constexpr int MapTexturePath = 0x888;
	// :AXMarksTheSpotMap:Marks:SoT_Athena_classes.hpp
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

	// :USceneComponent:RelativeLocation:SoT_Engine_classes.hpp
	static constexpr int RelativeLocation = 0x01B0;
	static constexpr int RelativeRotation = RelativeLocation + 0xC;
	static constexpr int RelativeRotationYaw = RelativeRotation + 0x4;

	// :AIslandService:Marks:SoT_Athena_classes.hpp
	static constexpr int IslandDataAsset = 0x4E8;

	// FTreasureMapData
	static constexpr int TreasureLocations = 0x10;
	static constexpr int TreasureLocationsCount = TreasureLocations + 0x8;
#pragma endregion
};

