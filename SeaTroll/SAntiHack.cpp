// ****************************************************************************
//  SAntiHack System/Protection For Applications
//  ---------------------------------------------------------------------------
//  Copyright (C)SeaTroll 2012 - All Rights Reserved
// ****************************************************************************
#include "stdafx.h"
#include "../ZGameInterface.h"
#include "../ZConfiguration.h"
#include "../ZWorldItem.h"
#include "../ZPost.h"
#include "./Module/SItemCheck.h"


//////////////////////////////////////////////////////////////////////
// Bools / Int
bool SAntiHack::IsFirstMassive = 0;
bool SAntiHack::IsFirstFlip = 0;
bool SAntiHack::IsFirstMelee = 0;
bool SAntiHack::IsFirstChat = 0;
int SAntiHack::ItemID = 0;


//////////////////////////////////////////////////////////////////////
// Set Its First
void SAntiHack::SetIsFirst()
{
	SAntiHack::IsFirstFlip = 0;
	SAntiHack::IsFirstMassive = 0;
	SAntiHack::IsFirstMelee = 0;
	SAntiHack::IsFirstChat = 0;
}
//////////////////////////////////////////////////////////////////////
// Massive Add
void SAntiHack::AddMassive(const MUID& attacker) 
{
	SAntiHack::CheckMassive(timeGetTime(), attacker);
}
////////////////////////////////////////////////////////////////////// 
// Massive Check
void SAntiHack::CheckMassive(unsigned long time, const MUID attacker)
{
	ZCharacter* pAttacker = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(attacker);
	if(pAttacker->GetUID() == ZGetMyUID())
	{
		SItemCheck::MassiveCheck(time,SAntiHack::IsFirstMassive);
	}
}
////////////////////////////////////////////////////////////////////// 
// Flip Add
void SAntiHack::AddFlip(const MUID& attacker) 
{
	SAntiHack::CheckFlip(timeGetTime(), attacker);
}
////////////////////////////////////////////////////////////////////// 
// Flip Check
void SAntiHack::CheckFlip(unsigned long time, const MUID attacker)
{
	ZCharacter* pAttacker = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(attacker);
	if(pAttacker->GetUID() == ZGetMyUID())
	{
		SItemCheck::FlipCheck(time,SAntiHack::IsFirstFlip);
	}
}
////////////////////////////////////////////////////////////////////// 
// Melee Add
void SAntiHack::AddMelee(const MUID& attacker, const int ItemID) 
{
	SAntiHack::ItemID = ItemID;
	SAntiHack::CheckMelee(timeGetTime(), attacker);
}
////////////////////////////////////////////////////////////////////// 
// Melee Check
void SAntiHack::CheckMelee(unsigned long Time, MUID attacker)
{
	ZCharacter* pAttacker = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(attacker);
	if(pAttacker->GetUID() == ZGetMyUID())
	{
		SItemCheck::MeleeItem(SAntiHack::ItemID,Time,SAntiHack::IsFirstMelee);
	}
}
////////////////////////////////////////////////////////////////////// 
// Chat Post Function
void SAntiHack::ZPostChat(char *szMsg, int nTeam, int nState, int nKey)
{
	if(nKey != 1337) return;
	switch (nState)
	{
	case 1:
		ZPostPeerChat(szMsg, nTeam);
		break;
	case 2:
		ZPostChannelChat(ZGetGameClient()->GetPlayerUID(), ZGetGameClient()->GetChannelUID(), szMsg);
		break;
	case 3:
		ZPostStageChat(ZGetGameClient()->GetPlayerUID(), ZGetGameClient()->GetStageUID(), szMsg);
		break;
	}
}