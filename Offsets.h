#pragma once

class Offsets
{
public:
	// :APlayerController:PlayerCameraManager:SoT_Engine_classes.hpp
	static constexpr int PlayerCameraManager = 0x0530;
			
	// :AAthenaCharacter:WieldedItemComponent:SoT_Athena_classes.hpp
	static constexpr int WieldedItemComponent = 0x0880;
	// :AAthenaCharacter:HealthComponent:SoT_Athena_classes.hpp
	static constexpr int HealthComponent = 0x08A8;
		
	// :UWieldedItemComponent:CurrentlyWieldedItem:SoT_Athena_classes.hpp
	static constexpr int CurrentlyWieldedItem = 0x02B8;

	// :AWieldableItem:ItemName:SoT_Athena_classes.hpp
	//static constexpr int WieldableItemName = 0xerror; // ItemName property // missing in the latest SDK
		
	// :APlayerCameraManager:CameraCache:SoT_Engine_classes.hpp
	static constexpr int CameraCache = 0x0510;
	// :FCameraCacheEntry:POV:SoT_Engine_structs.hpp
	static constexpr int CameraCachePOV = CameraCache + 0x0010;
	static constexpr int CameraLocation = CameraCachePOV + 0x0;
	static constexpr int CameraRotation = CameraCachePOV + 0xC;
	// :FMinimalViewInfo:FOV:SoT_Engine_structs.hpp
	static constexpr int CameraFOV = CameraCachePOV + 0x0028;
	
	// :UIslandDataAsset:IslandDataEntries:SoT_Athena_classes.hpp
	static constexpr int IslandDataEntries = 0x0040;
	static constexpr int IslandDataEntriesCount  = IslandDataEntries + 0x8;

	// :UIslandDataAssetEntry:IslandName:SoT_Athena_classes.hpp
	static constexpr int IslandName = 0x0028;
	// :UIslandDataAssetEntry:TreasureMaps:SoT_Athena_classes.hpp
	static constexpr int TreasureMaps = 0x0030;

	// :AXMarksTheSpotMap:MapTexturePath:SoT_Athena_classes.hpp
	static constexpr int MapTexturePath = 0x0878;
	// :AXMarksTheSpotMap:Marks:SoT_Athena_classes.hpp
	static constexpr int Marks = 0x08B8;
	static constexpr int MarksCount = Marks + 0x8;

	// :UPlayer:PlayerController:SoT_Engine_classes.hpp
	static constexpr int PlayerController = 0x0030;

	// :AActor:RootComponent:SoT_Engine_classes.hpp
	static constexpr int RootComponent = 0x0170;

	// :APawn:PlayerState:SoT_Engine_classes.hpp
	static constexpr int PlayerState = 0x04C0;

	// :AController:Pawn:SoT_Engine_classes.hpp
	static constexpr int Pawn = 0x04A8; // LocalPlayer

	// :APlayerState:PlayerId:SoT_Engine_classes.hpp
	static constexpr int PlayerId = 0x04C8;
	// :APlayerState:PlayerName:SoT_Engine_classes.hpp
	static constexpr int PlayerName = 0x04A8;

#pragma region Almsonst never changing offsets
	// UObject
	static constexpr int Id = 0x18;

	// :UWorld:PersistentLevel:SoT_Engine_classes.hpp
	static constexpr int PersistentLevel = 0x0030; // ULevel
	static constexpr int ActorsTArray = 0xA0; // Uknown offsets
	static constexpr int ActorsTArrayCount = ActorsTArray + 0x8;
	// :UWorld:OwningGameInstance:SoT_Engine_classes.hpp
	static constexpr int OwningGameInstance = 0x01C0;

	// UGameInstance
	static constexpr int LocalPlayers = 0x38;
	
	// UHealthComponent
	static constexpr int CurrentHealth = 0xDC;
	static constexpr int MaxHealth = 0xD0;

	// :USceneComponent:RelativeLocation:SoT_Engine_classes.hpp
	static constexpr int RelativeLocation = 0x01C0;
	static constexpr int RelativeRotation = RelativeLocation + 0xC;
	static constexpr int RelativeRotationYaw = RelativeRotation + 0x4;

	// :AIslandService:IslandDataAsset:SoT_Athena_classes.hpp
	static constexpr int IslandDataAsset = 0x0500;

	// FTreasureMapData
	static constexpr int TreasureLocations = 0x10;
	static constexpr int TreasureLocationsCount = TreasureLocations + 0x8;
#pragma endregion
};

