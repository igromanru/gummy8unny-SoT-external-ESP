#pragma once
#include "Functions.h"
#include <ShlObj.h>

struct Types {
	Color cCommon;
	Color cRare;
	Color cLegendary;
	Color cMythical;
	Color cHigher;

	bool bCommon, bRare, bLegendary, bMythical, bHigher;

};

struct Animals {
	bool chicken, snake, pig;
};
struct AnimalCrates {
	bool chicken, snake, pig;
};
struct Items {

	Color cAnimalCrates, cMerchant, cResources, cGunpowder, cPlayers, cShips, cSkeletons;
	bool bChests, bSkulls, bMerchant, bResources, bGunpowder, bAnimals, bAnimalCrates, bPlayers, bShips, bSkeletons;
	Animals Animals;
	AnimalCrates AnimalCrates;
};

class CFG
{
public:
	CFG();
	~CFG();

	void LoadCfg();
	void SaveCfg();
public:

	Types tRadar;
	Types tESP;



};

static CFG cfg;

//std::shared_ptr<CFG> cfg = nullptr;
