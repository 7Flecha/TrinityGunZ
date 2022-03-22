#ifndef _MMATCHMAP_H
#define _MMATCHMAP_H

#include "MMatchGlobal.h"


enum MMATCH_MAP 
{
	MMATCH_MAP_MANSION			= 0,
	MMATCH_MAP_PRISON			= 1,
	MMATCH_MAP_STATION			= 2,
	MMATCH_MAP_PRISON_II		= 3,
	MMATCH_MAP_BATTLE_ARENA		= 4,
	MMATCH_MAP_TOWN				= 5,
	MMATCH_MAP_DUNGEON			= 6,
	MMATCH_MAP_RUIN				= 7,
	MMATCH_MAP_ISLAND			= 8,
	MMATCH_MAP_GARDEN			= 9,
	MMATCH_MAP_CASTLE			= 10,
	MMATCH_MAP_FACTORY			= 11,
	MMATCH_MAP_PORT				= 12,
	MMATCH_MAP_LOST_SHRINE		= 13,
	MMATCH_MAP_STAIRWAY			= 14,
	MMATCH_MAP_SNOWTOWN			= 15,
	MMATCH_MAP_HALL				= 16,
	MMATCH_MAP_CATACOMB			= 17,
	MMATCH_MAP_JAIL				= 18,
	MMATCH_MAP_SHOWERROOM		= 19,
	MMATCH_MAP_HIGH_HAVEN		= 20,
	MMATCH_MAP_CITADEL			= 21,
	MMATCH_MAP_RELAYMAP			= 22,
	MMATCH_MAP_HALLOWEEN_TOWN	= 23,
	MMATCH_MAP_WEAPON_SHOP		= 24,
	MMATCH_MAP_FAG1				= 25,
	MMATCH_MAP_FAG2				= 26,
	MMATCH_MAP_FAG3				= 27,
	MMATCH_MAP_FAG4				= 28,
	MMATCH_MAP_FAG5				= 29,
	MMATCH_MAP_FAG6				= 30,
	MMATCH_MAP_FAG7				= 31,
	MMATCH_MAP_FAG8				= 32,
	MMATCH_MAP_FAG9				= 33,
	MMATCH_MAP_FAG10			= 34,
	MMATCH_MAP_FAG11			= 35,
	MMATCH_MAP_FAG12			= 36,
	MMATCH_MAP_FAG13			= 37,
	MMATCH_MAP_FAG14			= 38,
	MMATCH_MAP_FAG15			= 39,
	MMATCH_MAP_FAG16			= 40,
	MMATCH_MAP_FAG17			= 41,
	MMATCH_MAP_FAG18			= 42,
	MMATCH_MAP_FAG19			= 43,
	MMATCH_MAP_FAG20			= 44,
	MMATCH_MAP_FAG21			= 45,
	MMATCH_MAP_FAG22			= 46,
	MMATCH_MAP_FAG23			= 47,
	MMATCH_MAP_FAG24			= 48,
	MMATCH_MAP_FAG25			= 49,
	MMATCH_MAP_FAG26			= 50,
	MMATCH_MAP_FAG27			= 51,
	MMATCH_MAP_FAG28			= 52,
	MMATCH_MAP_FAG29			= 53,
	MMATCH_MAP_FAG30			= 54,
	MMATCH_MAP_FAG31			= 55,
	MMATCH_MAP_FAG32			= 56,
	MMATCH_MAP_FAG33			= 57,
	MMATCH_MAP_FAG34			= 58,
	MMATCH_MAP_FAG35			= 59,
	MMATCH_MAP_FAG36			= 60,
	MMATCH_MAP_FAG37			= 61,
	MMATCH_MAP_FAG38			= 62,
	MMATCH_MAP_FAG39			= 63,
	MMATCH_MAP_FAG40			= 64,
	MMATCH_MAP_FAG41			= 65,
	MMATCH_MAP_FAG42			= 66,
	MMATCH_MAP_FAG43			= 67,
	MMATCH_MAP_FAG44			= 68,
	MMATCH_MAP_FAG45			= 69,
	MMATCH_MAP_FAG46			= 70,
	MMATCH_MAP_FAG47			= 71,
	MMATCH_MAP_FAG48			= 72,
	MMATCH_MAP_FAG49			= 73,
	MMATCH_MAP_FAG50			= 74,
	MMATCH_MAP_FAG51			= 75,
	MMATCH_MAP_FAG52			= 76,
	MMATCH_MAP_FAG53			= 77,
	MMATCH_MAP_FAG54			= 78,
	MMATCH_MAP_FAG55			= 79,
	MMATCH_MAP_FAG56			= 80,
	MMATCH_MAP_FAG57			= 81,
	MMATCH_MAP_FAG58			= 82,
	MMATCH_MAP_FAG59			= 83,
	MMATCH_MAP_FAG60			= 84,
	MMATCH_MAP_FAG61			= 85,
	MMATCH_MAP_FAG62			= 86,
	MMATCH_MAP_FAG63			= 87,
	MMATCH_MAP_FAG64			= 88,
	MMATCH_MAP_FAG65			= 89,
	MMATCH_MAP_FAG66			= 90,
	MMATCH_MAP_FAG67			= 91,
	MMATCH_MAP_FAG68			= 92,
	MMATCH_MAP_FAG69			= 93,
	MMATCH_MAP_FAG70			= 94,
	MMATCH_MAP_FAG71			= 95,
	MMATCH_MAP_FAG72			= 96,
	MMATCH_MAP_FAG73			= 97,
	MMATCH_MAP_FAG74			= 98,
	MMATCH_MAP_FAG75			= 99,
	MMATCH_MAP_MAX
};

#define MMATCH_MAP_COUNT	MMATCH_MAP_MAX			// ÀüÃ¼ ¸Ê °¹¼ö

#define MMATCH_MAPNAME_RELAYMAP				"RelayMap"


class MMapDesc
{
private:
	const struct MapInfo
	{
		int			nMapID;							// map id
		char		szMapName[MAPNAME_LENGTH];		// ¸Ê ÀÌ¸§
		char		szMapImageName[MAPNAME_LENGTH];	// ¸Ê ÀÌ¹ÌÁö ÀÌ¸§
		char		szBannerName[MAPNAME_LENGTH];	// º£³Ê ÀÌ¸§
		float		fExpRatio;						// °æÇèÄ¡ ½Àµæ·ü
		int			nMaxPlayers;					// ÃÖ´ë ÀÎ¿ø
		bool		bOnlyDuelMap;					// µà¾ó¸Ê Àü¿ë
		bool		bIsCTFMap;
	};


	// data
	MapInfo	m_MapVectors[MMATCH_MAP_COUNT];
	MMapDesc();
public:
	~MMapDesc() { }
	
	static MMapDesc* GetInstance();

	bool Initialize(const char* szFileName);
	bool Initialize(MZFileSystem* pfs, const char* szFileName);
	bool MIsCorrectMap(const int nMapID);
	

 
	bool IsMapOnlyDuel( const int nMapID);
	bool IsCTFMap( const int nMapID);
	int GetMapID( const int nMapID);
	const char* GetMapName(const int nMapID);
	const char* GetMapImageName(const char* szMapName);
	const char* GetBannerName(const char* szMapName);
	float GetExpRatio( const int nMapID); 
	int GetMaxPlayers( const int nMapID);

	int GetMapCount(){ return MMATCH_MAP_COUNT; }
};


inline MMapDesc* MGetMapDescMgr() 
{ 
	return MMapDesc::GetInstance();
}



#endif