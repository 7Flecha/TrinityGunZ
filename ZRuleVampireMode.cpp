#include "stdafx.h"
#include "ZRuleVampireMode.h"

/////////////////////////////////////////////////////////////////////////////////////////
//////// Vampire Mode
#define KILLER_BONUS_AP				10
#define KILLER_BONUS_HP				10
ZRuleVampire::ZRuleVampire(ZMatch* pMatch) : ZRule(pMatch)
{

}
ZRuleVampire::~ZRuleVampire()
{



}
bool ZRuleVampire::OnCommand(MCommand* pCommand)
{
	if (!ZGetGame()) return false;

	switch (pCommand->GetID())
	{
		case MC_MATCH_GAME_DEAD:
		{
			
			MUID uidAttacker, uidVictim;
			unsigned long int nAttackerArg, nVictimArg;

			pCommand->GetParameter(&uidAttacker, 0, MPT_UID);
			pCommand->GetParameter(&nAttackerArg, 1, MPT_UINT);
			pCommand->GetParameter(&uidVictim, 2, MPT_UID);
			pCommand->GetParameter(&nVictimArg, 3, MPT_UINT);

			bool bSuicide = false;
			if (uidAttacker == uidVictim) bSuicide = true;

			if (uidAttacker != MUID(0,0))
			{
				if (!bSuicide)
				{
					ZCharacter* pAttacker = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidAttacker);
					ExtraHPAP(pAttacker);
				}
			}
		}
		break;
	}

	return false;
}
void ZRuleVampire::ExtraHPAP(ZCharacter* pCharacter)
{

	if (pCharacter)
	{
	
		if (pCharacter->IsDie()) 
		{
			CHECK_RETURN_CALLSTACK(ExtraHPAP);
			return;
		}

		// Get HP/AP
		float fBonusAP = KILLER_BONUS_AP;
		float fBonusHP = KILLER_BONUS_HP;
		pCharacter->SetHP(pCharacter->GetHP() + fBonusHP);
		pCharacter->SetAP(pCharacter->GetAP() + fBonusAP);

		// Said HP/AP
		char szHPAP[123];
		sprintf(szHPAP, "HP: %d / %d AP: %d / %d", (int)ZGetGame()->m_pMyCharacter->GetHP(), (int)ZGetGame()->m_pMyCharacter->GetMaxHP(), (int)ZGetGame()->m_pMyCharacter->GetAP(), (int)ZGetGame()->m_pMyCharacter->GetMaxAP());
		ZChatOutput(MCOLOR(0xFF80FFFF), szHPAP);
	}
}
