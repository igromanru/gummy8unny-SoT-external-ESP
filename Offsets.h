#pragma once

class Offsets
{
public:
	// UWorld
	static const int OwningGameInstance = 0x1C0;

	// UGameInstance
	static const int LocalPlayers = 0x38;

	// ULocalPlayer -> UPlayer
	static const int PlayerController = 0x38;

	// APlayerController
	static const int PlayerCameraManager = 0x518;

	// AController
	static const int Pawn = 0x490; // LocalPlayer

	// AActor	
	static const int RootComponent = 0x178;

	// APawn
	static const int PlayerState = 0x4A8;

	// AAthenaCharacter
	static const int WieldedItemComponent = 0x820;
	static const int HealthComponent = 0x848;
	
	// UWieldedItemComponent
	static const int CurrentlyWieldedItem = 0x2B0;

	// AWieldableItem
	static const int WieldableItemName = 0x580; // ItemName property
	
	
};

