#pragma once

#include <thread>
#include <conio.h>
#include <vector>
#include <locale>
#include <codecvt>

#include "ProcMem.h"
#include "Vector.h"
#include "hDirectX.h"
#include "Offsets.h"
#include "FindPattern/FindPattern.h"


#pragma comment(lib,"winmm.lib")


class CFG;

struct Color
{
	int r, g, b;
};



/*#define WORLD_OFFSET 0x51b5578
#define OBJECTS_OFFSET 0x50f3680
#define NAME_OFFSET 0x50f7e40*/

ULONG_PTR GNames;

ProcMem mem;
DWORD pid;
uintptr_t BASE;
bool FirstRun = true;
uintptr_t WorldAddress;
uintptr_t ObjectsAddress;
uintptr_t NamesAddress;

Vector3 myLocation, myAngles, Cameralocation;
float CameraFov;


void ReadData()
{
	if (FirstRun)
	{
		mem.Process("SoTGame.exe");

		/* Set Module and store it in Client */
		BASE = mem.Module("SoTGame.exe");
		FirstRun = false;

		auto address = IgroWidgets::FindPatternExternal(mem.hProcess, reinterpret_cast<HMODULE>(BASE), 
			reinterpret_cast<const unsigned char*>("\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\x01\xFF\x90\x00\x00\x00\x00\x48\x8B\xF8\x33\xD2\x48\x8D\x4E"),
			"xxx????xxxxx????xxxxxxxx");
		if (address > 0)
		{			
			WorldAddress = IgroWidgets::ReadRIPAddress(mem.hProcess, address, 3, 7);			
		}
		address = IgroWidgets::FindPatternExternal(mem.hProcess, reinterpret_cast<HMODULE>(BASE), 
			reinterpret_cast<const unsigned char*>("\x48\x8B\x3D\x00\x00\x00\x00\x48\x85\xFF\x75\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x89\x44"),
			"xxx????xxxx?x????x????xxxxxx");
		if (address > 0)
		{
			NamesAddress = IgroWidgets::ReadRIPAddress(mem.hProcess, address, 3, 7);
		}
		
		//WaitForMultipleObjects(sizeof(rghThreads) / sizeof(HANDLE), rghThreads, TRU E, INFINITE);
	}
}

class text
{
public:
	char word[64];
};

class textx
{
public:
	wchar_t word[64];
};


enum rareity
{
	Common,
	Rare,
	Legendary,
	Mythical,
	Fort,
	Weeping,
	Drunken
};

enum type
{
	chest,
	skull,
	artifact,
	merchantcrate,
	animalcrate,
	gunpowder,
	player,
	skeleton,
	ship,
	chicken,
	pig,
	snake,
};

struct AActors
{
	int id;
	std::string name, item;
	Vector3 Location;
	Vector3 TopLocation;
	int type, rareity, namesize;
	float health, maxhealth;
	float yaw;
	int distance;
};

std::vector<AActors> ActorArray;
std::vector<AActors> WeildingArray;

#define Assert( _exp ) ((void)0)

struct vMatrix
{
	vMatrix() {}
	vMatrix(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23)
	{
		m_flMatVal[0][0] = m00;	m_flMatVal[0][1] = m01; m_flMatVal[0][2] = m02; m_flMatVal[0][3] = m03;
		m_flMatVal[1][0] = m10;	m_flMatVal[1][1] = m11; m_flMatVal[1][2] = m12; m_flMatVal[1][3] = m13;
		m_flMatVal[2][0] = m20;	m_flMatVal[2][1] = m21; m_flMatVal[2][2] = m22; m_flMatVal[2][3] = m23;
	}

	float *operator[](int i) { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	const float *operator[](int i) const { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	float *Base() { return &m_flMatVal[0][0]; }
	const float *Base() const { return &m_flMatVal[0][0]; }

	float m_flMatVal[3][4];
};

vMatrix Matrix(Vector3 rot, Vector3 origin)
{
	origin = Vector3(0, 0, 0);
	float radPitch = (rot.x * float(PI) / 180.f);
	float radYaw = (rot.y * float(PI) / 180.f);
	float radRoll = (rot.z * float(PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	vMatrix matrix;
	matrix[0][0] = CP * CY;
	matrix[0][1] = CP * SY;
	matrix[0][2] = SP;
	matrix[0][3] = 0.f;

	matrix[1][0] = SR * SP * CY - CR * SY;
	matrix[1][1] = SR * SP * SY + CR * CY;
	matrix[1][2] = -SR * CP;
	matrix[1][3] = 0.f;

	matrix[2][0] = -(CR * SP * CY + SR * SY);
	matrix[2][1] = CY * SR - CR * SP * SY;
	matrix[2][2] = CR * CP;
	matrix[2][3] = 0.f;

	matrix[3][0] = origin.x;
	matrix[3][1] = origin.y;
	matrix[3][2] = origin.z;
	matrix[3][3] = 1.f;

	return matrix;
}
bool WorldToScreen(Vector3 origin, Vector2 * out) {
	Vector3 Screenlocation = Vector3(0, 0, 0);
	Vector3 Rotation = myAngles;	// FRotator

	vMatrix tempMatrix = Matrix(Rotation, Vector3(0, 0, 0)); // Matrix

	Vector3 vAxisX, vAxisY, vAxisZ;

	vAxisX = Vector3(tempMatrix[0][0], tempMatrix[0][1], tempMatrix[0][2]);
	vAxisY = Vector3(tempMatrix[1][0], tempMatrix[1][1], tempMatrix[1][2]);
	vAxisZ = Vector3(tempMatrix[2][0], tempMatrix[2][1], tempMatrix[2][2]);

	Vector3 vDelta = origin - Cameralocation;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	float FovAngle = CameraFov; // + 22; for widescreen?
	float ScreenCenterX = Width / 2.0f;
	float ScreenCenterY = Height / 2.0f;

	out->x = ScreenCenterX + vTransformed.x * (ScreenCenterX / tanf(FovAngle * static_cast<float>(PI) / 360.f)) / vTransformed.z;
	out->y = ScreenCenterY - vTransformed.y * (ScreenCenterX / tanf(FovAngle * static_cast<float>(PI) / 360.f)) / vTransformed.z;


	return true;
}

Vector3 CalcAngle(Vector3 src, Vector3 dst)
{
	Vector3 angles;
	Vector3 delta = src - dst;
	angles.x = (asinf(delta.z / delta.Length()) * RADPI);
	angles.y = (atanf(delta.y / delta.x) * RADPI);
	angles.z = 0.0f;
	if (delta.x >= 0.0) { angles.y += 180.0f; }

	return angles;
}

Vector2 RotatePoint(Vector2 pointToRotate, Vector2 centerPoint, float angle, bool angleInRadians = false)
{
	if (!angleInRadians)
		angle = static_cast<float>(angle * (PI / 180.f));
	float cosTheta = static_cast<float>(cos(angle));
	float sinTheta = static_cast<float>(sin(angle));
	Vector2 returnVec = Vector2(cosTheta * (pointToRotate.x - centerPoint.x) - sinTheta * (pointToRotate.y - centerPoint.y), sinTheta * (pointToRotate.x - centerPoint.x) + cosTheta * (pointToRotate.y - centerPoint.y)
	);
	returnVec += centerPoint;
	return returnVec;
}

float getAngle(Vector2 initial, Vector2 final)
{
	return atan2(initial.y - final.y, initial.x - final.x) * 180 / PI;
}

int GetTextWidth(const char *szText, ID3DXFont* pFont)
{
	RECT rcRect = { 0,0,0,0 };
	if (pFont)
	{
		// calculate required rect
		pFont->DrawText(nullptr, szText, strlen(szText), &rcRect, DT_CALCRECT, D3DCOLOR_XRGB(0, 0, 0));
	}

	// return width
	return rcRect.right - rcRect.left;
}

template< class T > struct TArray
{
public:
	T* Data;
	int Count;
	int Max;

public:
	TArray()
	{
		Data = NULL;
		Count = Max = 0;
	};

public:
	int Num()
	{
		return this->Count;
	};

	T& operator() (int i)
	{
		return this->Data[i];
	};

	const T& operator() (int i) const
	{
		return this->Data[i];
	};

	void Add(T InputData)
	{
		Data = (T*)realloc(Data, sizeof(T) * (Count + 1));
		Data[Count++] = InputData;
		Max = Count;
	};

	void Clear()
	{
		free(Data);
		Count = Max = 0;
	};
};

std::string getNameFromID(int ID) {
	try {
		DWORD_PTR fNamePtr = mem.Read<DWORD_PTR>(GNames + int(ID / 0x4000) * 0x8);
		DWORD_PTR fName = mem.Read<DWORD_PTR>(fNamePtr + 0x8 * int(ID % 0x4000));
		return mem.Read<text>(fName + 0x10).word;
	}
	catch (int e) { return std::string(""); }

}

class AActor
{
public:
	char pad_0000[2120]; //0x0000
}; //Size: 0x0848

DWORD_PTR IslandDataAsset_PTR;

struct FTreasureLocationData {
	Vector3	WorldSpaceLocation;
	Vector3	IslandSpaceLocation;
	Vector2	MapSpaceLocation;
};


bool get_IslandDataEntries_list(DWORD_PTR IslandDataAsset_PTR, DWORD_PTR * list, __int32 * count) {
	try {
		*list = mem.Read<DWORD_PTR>(IslandDataAsset_PTR + Offsets::IslandDataEntries);
		*count = mem.Read<__int32>(IslandDataAsset_PTR + Offsets::IslandDataEntriesCount);
		return true;
	}
	catch (int e) {
		*list = NULL;
		*count = 0;
		return false;
	}
}

bool find_Island_In_IslandDataEntries(std::string MapTexturePath, DWORD_PTR * TreasureLocations_PTR, __int32 * TreasureLocations_Count) {
	DWORD_PTR list = NULL;
	__int32 count = 0;
	if (get_IslandDataEntries_list(IslandDataAsset_PTR, &list, &count)) {
		for (auto nIndex = 0; nIndex <= count; nIndex++) {
			try {
				const auto cIsland = mem.Read<DWORD_PTR>(list + (nIndex * 0x8));
				const auto IslandName_ID = mem.Read<__int32>(cIsland + Offsets::IslandName);
				const std::string IslandName = getNameFromID(IslandName_ID);
				if (MapTexturePath.find(IslandName) != std::string::npos) {
					const auto FTreasureMapData_PTR = mem.Read<DWORD_PTR>(cIsland + Offsets::TreasureMaps);					// FTreasureMapData
					*TreasureLocations_PTR = mem.Read<DWORD_PTR>(FTreasureMapData_PTR + Offsets::TreasureLocations);		// FTreasureLocationData
					*TreasureLocations_Count = mem.Read<__int32>(FTreasureMapData_PTR + Offsets::TreasureLocationsCount);	// FTreasureLocationData_Size
					return true;
				}
			}
			catch (int e) { continue; }
		}
		return false;

	}
	else {
		return false;
	}
}





std::vector<Vector3> XMarksTheSpot;



bool get_TreasureMap(DWORD_PTR _PTR, std::string * MapTexturePath, std::vector<Vector2> * Marks) {
	try {
		DWORD_PTR Name_PTR = mem.Read<DWORD_PTR>(_PTR + Offsets::MapTexturePath);
		DWORD_PTR Marks_PTR = mem.Read<DWORD_PTR>(_PTR + Offsets::Marks);
		__int32 Marks_Cout = mem.Read<__int32>(_PTR + Offsets::MarksCount);

		std::wstring test = mem.Read<textx>(Name_PTR).word;

		using convert_type = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_type, wchar_t> converter;

		//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
		std::string converted_str = converter.to_bytes(test);

		*MapTexturePath = converted_str;

		for (int nIndex = 0; nIndex < Marks_Cout; nIndex++) {
			Vector2 Position = mem.Read<Vector2>(Marks_PTR + (nIndex * (sizeof(Vector2) + sizeof(float))));
			Marks->push_back(Position);
		}

		return true;
	}
	catch (int e) {
		*MapTexturePath = "";
		Marks->clear();
		return false;
	}
}
