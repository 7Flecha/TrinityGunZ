// ****************************************************************************
//  SGame System/Protection For Applications
//  ---------------------------------------------------------------------------
//  Copyright (C)SeaTroll 2012 - All Rights Reserved
// ****************************************************************************
#include "stdafx.h"
#include "../ZGameInterface.h"
#include "../ZConfiguration.h"
#include "../ZWorldItem.h"
#include "../ZPost.h"
#include "../ZMyInfo.h"
#include "./Module/SEncryption.h"

// ****************************************************************************
//								   Game System
// ****************************************************************************
bool SGame::bAllowed		= 0;		// Allowed Gunz Start
bool SGame::bRegisterPage	= 0;		// Register page (dont edit)

bool SGame::bDamageCounter = false;
bool SGame::bWireFrame = false;
bool SGame::bGodMode = false;
bool SGame::bTeleporting = false;

// Room Tag Key
int SGame::GravityNum = 0;
int SGame::JumpNum = 0;

bool SGame::bGravity = false;
bool SGame::bJump = false;


// ****************************************************************************
//								   SeaTroll Game
// ****************************************************************************
void SGame::SLog(const char* szString)
{
  FILE* pFile = fopen("Logs/Anithack.txt", "a");
  fprintf(pFile, "%s\n",szString);
  fclose(pFile);
}

void SGame::OnUpdate()
{
	GunzState state = ZApplication::GetGameInterface()->GetState();
	//SGame::InjectionCheck();
	if(state == GUNZ_GAME)
	{
		if(ZGetSGame()->bTeleporting == true)
		{
			if(GetAsyncKeyState(VK_NUMPAD4)) // Num Lock 4
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				rvector vDirection = ZGetGame()->m_pMyCharacter->GetDirection();

				vPosition.x = vPosition.x + (vDirection.y * 50.0f);
				vPosition.y = vPosition.y - (vDirection.x * 50.0f);

				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
			if(GetAsyncKeyState(VK_NUMPAD5)) // Num Lock 5
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				rvector vDirection = ZGetGame()->m_pMyCharacter->GetDirection();

				vPosition.x = vPosition.x - (vDirection.x * 50.0f);
				vPosition.y = vPosition.y - (vDirection.y * 50.0f);

				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
			if(GetAsyncKeyState(VK_NUMPAD6)) // Num Lock 6
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				rvector vDirection = ZGetGame()->m_pMyCharacter->GetDirection();

				vPosition.x = vPosition.x - (vDirection.y * 50.0f);
				vPosition.y = vPosition.y + (vDirection.x * 50.0f);

				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
			if(GetAsyncKeyState(VK_NUMPAD7)) // Num Lock 7
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				vPosition.z-=500;
				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
			if(GetAsyncKeyState(VK_NUMPAD8)) // Num Lock 8
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				rvector vDirection = ZGetGame()->m_pMyCharacter->GetDirection();

				vPosition.x = vPosition.x + (vDirection.x * 50.0f);
				vPosition.y = vPosition.y + (vDirection.y * 50.0f);

				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
			if(GetAsyncKeyState(VK_NUMPAD9)) // Num Lock 9
			{
				//Variable:
				ZCharacter* pCharacter = ZGetGame()->m_pMyCharacter;

				// Set Possition:
				rvector vPosition = ZGetGame()->m_pMyCharacter->GetPosition();
				vPosition.z+=500;
				ZGetGame()->m_pMyCharacter->SetPosition(vPosition);
			}
		}
	}
}

void SGame::RoomTagScan()
{
	int Gravity = 0;
	int Jump = 0;

	if(sscanf(ZGetGameClient()->GetStageName(), "!g%i", &Gravity))
	{
		
		if (Gravity < 0 || Gravity > 9)
		{
			SGame::bGravity = true;
			SGame::GravityNum = Gravity;
		}
		else
		{
			SGame::bGravity = false;
			SGame::GravityNum = 0;
		}

	}
	if(sscanf(ZGetGameClient()->GetStageName(), "!j%i", &Jump))
	{
		if (Jump < 0 || Jump > 9)
		{
			SGame::bJump = true;
			SGame::JumpNum = Jump;
		}
		else
		{
			SGame::bJump = false;
			SGame::JumpNum = 0;
		}
	}

}
// ****************************************************************************
//								   Gunz Guard
// ****************************************************************************
void SGame::StartLauncher()
{
	CFileFind Finder;
	BOOL bFound1 = Finder.FindFile("GunzLauncher.exe");
	if(bFound1 == 0)
	{	
		char *msg;
		msg = "Game Startup Unsuccessful, Please Reinstall DevilGunz";
		MessageBox(NULL, msg, "Msg", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	else
	{
		WinExec("GunzLauncher.exe",SW_SHOW);
		ExitProcess(0);
	}
}

void SGame::Launcher()
{
	SEncryption cEncription;
	int nMode = cEncription.Decription();

	// Launcher Check
	if ( nMode == S_LAUNCH_INTERNATIONAL)
	{
		mlog( "ERROR\n");
		SGame::StartLauncher();
	}
	else if ( nMode == S_LAUNCH_DEVELOP)
	{
		mlog( "ERROR\n");
		SGame::StartLauncher();
	}
	else if ( nMode == S_LAUNCH_TEST)
	{
		mlog( "ERROR\n");
		SGame::StartLauncher();
	}
	else if ( nMode == S_LAUNCH_DEVILGUNZ)
	{
		SGame::bAllowed = 1; 
	}
	else
	{
		mlog( "ERROR\n");
		SGame::StartLauncher();
	}
}
// ****************************************************************************
//								   Gunz Security
// ****************************************************************************
void SGame::SQLCheck(char* szName)
{
	if(strstr(szName, "-") || strstr(szName, "'") || strstr(szName, "-") || strstr(szName, ";") || strstr(szName, "}") || strstr(szName, "%") || strstr(szName, "\") || strstr(szName, """) || strstr(szName, "*") || strstr(szName, "DROP") || strstr(szName, "SELECT") || strstr(szName, "DELETE")|| strstr(szName, "INSERT") || strstr(szName, "SET") || strstr(szName, "FROM") || strstr(szName, "$") || strstr(szName, "+") || strstr(szName, "=")|| strstr(szName, "_") || strstr(szName, "[") || strstr(szName, "]") || strstr(szName, "^"))
	{
		char szError[256];
		sprintf(szError, "You fill a symbol in that's forbidden!");
		ZGetGameInterface()->ShowMessage(szError);
		return;
	}
}
void SGame::IsImportantPlayer()
{
	if((ZGetMyInfo()->GetUGradeID() != MMUG_DEVELOPER) || (ZGetMyInfo()->GetUGradeID() != MMUG_ADMINISTRATOR) || (ZGetMyInfo()->GetUGradeID() != MMUG_GAMEMASTER) || (ZGetMyInfo()->GetUGradeID() != MMUG_OWNER)) return;
}

void SGame::IsDeveloperPlayer()
{
	if(ZGetMyInfo()->GetUGradeID() != MMUG_DEVELOPER) return;
}


