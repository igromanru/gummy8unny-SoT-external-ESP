#include "cfg.h"

float GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName)
{
	char szData[32];

	GetPrivateProfileStringA(lpAppName, lpKeyName, std::to_string(flDefault).c_str(), szData, 32, lpFileName);

	return (float)atof(szData);
}

void WritePrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flValue, LPCSTR lpFileName)
{
	WritePrivateProfileStringA(lpAppName, lpKeyName, std::to_string((int)flValue).c_str(), lpFileName);
}


void SaveColor(Color color, std::string AppName, std::string keyname, std::string file)
{
	std::string r = keyname + ".r";
	std::string g = keyname + ".g";
	std::string b = keyname + ".b";

	WritePrivateProfileFloat(AppName.c_str(), r.c_str(), color.r, file.c_str());
	WritePrivateProfileFloat(AppName.c_str(), g.c_str(), color.g, file.c_str());
	WritePrivateProfileFloat(AppName.c_str(), b.c_str(), color.b, file.c_str());
}

Color ReadColor(std::string AppName, std::string keyname, std::string file)
{
	std::string r = keyname + ".r";
	std::string g = keyname + ".g";
	std::string b = keyname + ".b";

	int ir = GetPrivateProfileFloat(AppName.c_str(), r.c_str(), 0, file.c_str());
	int ig = GetPrivateProfileFloat(AppName.c_str(), g.c_str(), 0, file.c_str());
	int ib = GetPrivateProfileFloat(AppName.c_str(), b.c_str(), 0, file.c_str());

	return Color{ ir,ig,ib };

}


CFG::CFG()
{

}

CFG::~CFG()
{

}


void CFG::LoadCfg()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Arghware\\";
		file = std::string(path) + "\\Arghware\\Autosave.cfg";
	}

	CreateDirectory(folder.c_str(), NULL);

	
	tRadar.cCommon = ReadColor("Radar","Color.Common", file);
	tRadar.cRare = ReadColor("Radar", "Color.Rare", file);
	tRadar.cLegendary = ReadColor("Radar", "Color.Legendary", file);
	tRadar.cMythical = ReadColor("Radar", "Color.Mythical", file);
	tRadar.cHigher = ReadColor("Radar", "Color.Higher", file);
	tRadar.bCommon = GetPrivateProfileFloat("Radar", "Show.Common", 0, file.c_str());
	tRadar.bRare = GetPrivateProfileFloat("Radar", "Show.Rare", 0, file.c_str());
	tRadar.bLegendary = GetPrivateProfileFloat("Radar", "Show.Legendary", 0, file.c_str());
	tRadar.bMythical = GetPrivateProfileFloat("Radar", "Show.Mythical", 0, file.c_str());
	tRadar.bHigher = GetPrivateProfileFloat("Radar", "Show.Higher", 0, file.c_str());
}

void CFG::SaveCfg()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Arghware\\";
		file = std::string(path) + "\\Arghware\\Autosave.cfg";
	}

	CreateDirectory(folder.c_str(), NULL);


	SaveColor(tRadar.cCommon, "Radar", "Color.Common", file);
	SaveColor(tRadar.cRare, "Radar", "Color.Rare", file);
	SaveColor(tRadar.cLegendary, "Radar", "Color.Legendary", file);
	SaveColor(tRadar.cMythical, "Radar", "Color.Mythical", file);
	SaveColor(tRadar.cHigher, "Radar", "Color.Higher", file);
	WritePrivateProfileFloat("Radar", "Show.Common", tRadar.bCommon, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Rare", tRadar.bRare, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Legendary", tRadar.bLegendary, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Mythical", tRadar.bMythical, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Higher", tRadar.bHigher, file.c_str());
}