#pragma once

#include "MWindowFinder.h"


//// °¢Á¾ º¸¾È ¹× ÇØÅ·¹æÁöÄÚµå ////

class MDataChecker;

__forceinline bool ZCheckHackProcess();
unsigned long ZGetMZFileChecksum(const char* pszFileName);
bool ZCheckFileHack();
void ZSetupDataChecker_Global(MDataChecker* pDataChecker);
void ZSetupDataChecker_Game(MDataChecker* pDataChecker);


// ------ inline


__forceinline bool ZCheckHackProcess()
{
	bool bHack = false;

#ifdef _PUBLISH

/*	MHackWindowFinder HackFinder;
	HackFinder.EncodeTest("SpeederXP");
	HackFinder.EncodeTest("ArtMoney");
	HackFinder.EncodeTest("TSearch");
	HackFinder.EncodeTest("GameHack");
	HackFinder.EncodeTest("Memory Doctor");
	HackFinder.AddHackList("‡¤±±°±¦Œ?", true);
	HackFinder.AddHackList("•¦ ™»º±­", true);
	HackFinder.AddHackList("‡±µ¦·¼", true);
	HackFinder.AddHackList("“µ¹±œµ·¿", true);
	HackFinder.AddHackList("™±¹»¦­?»· »?", true);
	HackFinder.EncodeTest("SpeederXP");
	HackFinder.EncodeTest("ArtMoney");
	HackFinder.EncodeTest("TSearch");
	HackFinder.EncodeTest("GameHack");
	HackFinder.EncodeTest("Memory Doctor");
	HackFinder.EncodeTest("xSpeed"); --
	HackFinder.EncodeTest("peed Hack Version Edited By : Windows");
	HackFinder.EncodeTest("UC");
	HackFinder.EncodeTest("Dark Byte's Speedhack");
	HackFinder.EncodeTest("OLLYDBG");
	HackFinder.EncodeTest("Olly Debugger");
	HackFinder.EncodeTest("PROCEXPL");
	HackFinder.EncodeTest("Process Explorer");
	HackFinder.EncodeTest("EasyTune5 Pro Build 2007.12.21");
	HackFinder.EncodeTest("Easy Tune");
	HackFinder.EncodeTest("EasyTune6 Build 2010.07.28");
	HackFinder.EncodeTest("GUI.EXE");
	HackFinder.EncodeTest("gui.exe");
	HackFinder.EncodeTest("Cheat Engine 5.5");
	HackFinder.EncodeTest("Cheat Engine 5.6");
	HackFinder.EncodeTest("Cheat Engine 5.6.1");
	HackFinder.EncodeTest("Cheat Engine 5.7");
	HackFinder.EncodeTest("Cheat Engine 5.8");
	HackFinder.EncodeTest("Cheat Engine 5.9");
	HackFinder.EncodeTest("Cheat Engine 6.0");
	HackFinder.EncodeTest("Cheat Engine 6.1");
	HackFinder.EncodeTest("Cheat Engine 6.2");
	HackFinder.EncodeTest("Cheat Engine 6.3");
	HackFinder.EncodeTest("Cheat Engine 6.4");
	HackFinder.EncodeTest("Cheat Engine 6.5");
	HackFinder.EncodeTest("MoonLight Engine 1099.1");
	HackFinder.EncodeTest("MoonLight Engine");
	HackFinder.EncodeTest("The Wireshark Network Analyzer");
	HackFinder.EncodeTest("WireShark");
	HackFinder.EncodeTest("HideToolz");
	HackFinder.EncodeTest("Conexão de Área de Trabalho Remota");
	HackFinder.EncodeTest("Conexión A Escritorio Remoto");
	HackFinder.EncodeTest("SetFSB");
	HackFinder.EncodeTest("SetFSB 2.2.134.98");
	HackFinder.EncodeTest("SetFSB 2.3.157.122");
	HackFinder.EncodeTest("RivaTuner");
	HackFinder.EncodeTest("TMemoryBrowser");
	HackFinder.EncodeTest("Memory Viewer");
	HackFinder.EncodeTest("Process List");
	HackFinder.EncodeTest("MoonLight Engine 1224.15 by IlvMoney A.K.A FaaF");
	HackFinder.EncodeTest("MoonLight");
	HackFinder.EncodeTest("MoonLight Engine");
	HackFinder.EncodeTest("by IlvMoney A.K.A FaaF");
	HackFinder.EncodeTest("Moon Light Engine settings");
	HackFinder.EncodeTest("Process watcher");
	HackFinder.EncodeTest("SetFSB 2.3.153.118");
	HackFinder.EncodeTest("SetFSB 2.3.153.119");
	HackFinder.EncodeTest("SetFSB 2.3.154.120");
	HackFinder.EncodeTest("SetFSB 2.3.155.121");
	HackFinder.EncodeTest("SetFSB 2.2.134.98");
	HackFinder.EncodeTest("SetFSB ID 1484484651");
	HackFinder.EncodeTest("AMD OverDrive");
	HackFinder.EncodeTest("CPU Burn-in v1.01");
	HackFinder.EncodeTest("CPU Burn-in");
	HackFinder.EncodeTest("CPUCooL");
	HackFinder.EncodeTest("ParetoLogic PC Health Advisor");
	HackFinder.EncodeTest("ParetoLogic");
	HackFinder.EncodeTest("SpeedswitchXP V1.52 - © 2002-2006 Christian Diefer");
	HackFinder.EncodeTest("SpeedswitcherXP");
	HackFinder.EncodeTest("ATITool");
	HackFinder.EncodeTest("A64Info-beta");
	HackFinder.EncodeTest("SetFSB 2.2.134.98");
	HackFinder.EncodeTest("SetFSB ID 1484484651");
	HackFinder.EncodeTest("PowerStrip");
	HackFinder.EncodeTest("EasyTune5 Build 2007.09.21");
	HackFinder.EncodeTest("EasyTune");
	HackFinder.EncodeTest("EasyTune4 Build 2004.10.19");
	HackFinder.EncodeTest("Encrypt Tool 2.0");
	HackFinder.EncodeTest("Written By");
	HackFinder.EncodeTest("ShotBot");
	HackFinder.EncodeTest("Shobot Detect");
	HackFinder.EncodeTest("AutoIt");
	HackFinder.EncodeTest("AutoID");
	HackFinder.EncodeTest("shotbot");
	HackFinder.EncodeTest("cmd.exe");
	HackFinder.EncodeTest("cmd");
	HackFinder.EncodeTest("Prompt de comando");
	HackFinder.EncodeTest("Prompt");
	HackFinder.EncodeTest("WellHide");
	HackFinder.EncodeTest("By Nesk");
	HackFinder.EncodeTest("Inject");
	HackFinder.EncodeTest("Omega Injector");
	HackFinder.EncodeTest("Injector");
	HackFinder.EncodeTest("Injected");
	HackFinder.EncodeTest("Processo");
	HackFinder.EncodeTest("Speed");
	HackFinder.EncodeTest("Ninjex");
	HackFinder.EncodeTest("NameESP");
	HackFinder.EncodeTest("Game Speed Changer");
	HackFinder.EncodeTest("Game Speed");
	HackFinder.EncodeTest("Utorrent 3.0");
	HackFinder.EncodeTest("Torrent");
	HackFinder.EncodeTest("Alladingg's System : Channel Flood 08");
	HackFinder.EncodeTest("Alladingg's System");
	HackFinder.EncodeTest("Omega injector");
	HackFinder.EncodeTest("Autoshot");
	HackFinder.EncodeTest("Workspace Macro 4.6"");
	HackFinder.EncodeTest("Macro Express - Macro Explorer");
	HackFinder.EncodeTest("Teclado Virtual");
	HackFinder.EncodeTest("Injector (Webcheats)");
	HackFinder.EncodeTest("Net Suspender");
	HackFinder.EncodeTest("Kore");
	HackFinder.EncodeTest("NS");
	HackFinder.EncodeTest("Macro");
	HackFinder.EncodeTest("Moslo");
	HackFinder.EncodeTest("actoolinstall_540");
	HackFinder.EncodeTest("X1nject");
	HackFinder.EncodeTest("hack");

	if (HackFinder.Find())
		bHack = true;
*/

	// 0x4b ·Î xor ÈÄ ¿ª¼øÀ¸·Î
	char *cheatProgramNames[] = { 
		// ÇØÅ·Åøµé
			"\x9\x1b\x13\x39\x2e\x2f\x2e\x2e\x3b\x18", // SpeederXP
			"\x8\x32\x2e\x25\x24\x6\x3f\x39\xa", // ArtMoney
			"\x7\x23\x28\x39\x2a\x2e\x18\x1f", // TSearch
			"\x8\x20\x28\x2a\x3\x2e\x26\x2a\xc", // GameHack
			"\xd\x39\x24\x3f\x28\x24\xf\x6b\x32\x39\x24\x26\x2e\x6", // Memory Doctor
			"\x3\xe\x1b\x1c", // WPE
			"\xc\x2e\x25\x22\x2c\x25\xe\x6b\x3f\x2a\x2e\x23\x8", // Cheat Engine
			"\x7\xc\x9\xf\x12\x7\x7\x4", // OLLYDBG
			"\xe\x24\x22\x2f\x3e\x3f\x18\x6b\x39\x2e\x25\x22\x2a\x39\x1f", // Trainer Studio
			"\x10\x25\x24\x22\x3f\x2a\x2e\x39\x8\x6b\x39\x2e\x25\x22\x2a\x39\x1f", // Trainer Creation
			"\xd\x39\x2e\x20\x2a\x6\x6b\x39\x2e\x25\x22\x2a\x39\x1f", // Trainer Maker
		// À¯ÀúµéÀÌ ¸¸µç Åø
			"\xb\x2f\x22\x0\x2e\x23\x1f\x32\x27\x27\x22\x9", // BillyTheKid
			"\x11\x39\x2e\x25\x22\x2a\x39\x1f\x32\x39\x24\x26\x2e\x6\x26\x39\x2d\x1f", // TfrmMemoryTrainer		
	};

#define DECODESTRING(_dest,_source) \
	{ for(int __i=0; __i<_source[0];__i++) { \
	_dest[__i]=((unsigned char)_source[_source[0]-__i]) ^ 0x4b; } \
	_dest[_source[0]]=0; }
	

	MWindowFinder WindowFinder;

	char szTemp[256];

	for(int i=0;i<sizeof(cheatProgramNames)/sizeof(char*);i++) {
		DECODESTRING(szTemp,cheatProgramNames[i]);
		if(WindowFinder.Find(szTemp))
			return true;
	}

	/*
	char *kernelStrings[] = {
	"\xc\x27\x27\x2f\x65\x79\x78\x27\x2e\x25\x39\x2e\x20", // kernel32.dll
	"\x11\x3f\x25\x2e\x38\x2e\x39\x1b\x39\x2e\x2c\x2c\x3e\x29\x2e\xf\x38\x2" // IsDebuggerPresent
	};

	typedef BOOL * (__stdcall *ISDEBUGGERPRESENTTYPE)();
	static ISDEBUGGERPRESENTTYPE isDebuggerPresent = NULL;
	if(	NULL == isDebuggerPresent ) {
		DECODESTRING(szTemp,kernelStrings[0]);
		HMODULE hKernel32 = LoadLibrary( szTemp );
		if (!hKernel32) return true;

		DECODESTRING(szTemp,kernelStrings[1]);
		isDebuggerPresent = (ISDEBUGGERPRESENTTYPE) GetProcAddress(hKernel32, szTemp);
		FreeLibrary(hKernel32);
	}
	if (isDebuggerPresent && isDebuggerPresent())
		bHack = true;
	*/
	if (IsDebuggerPresent())
		bHack = true;

#endif

	return false;
}
