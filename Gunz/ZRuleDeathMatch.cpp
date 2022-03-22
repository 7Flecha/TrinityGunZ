#include "stdafx.h"
#include "ZRuleDeathMatch.h"
#include "ZScreenEffectManager.h"
#include "MMatchUtil.h"


/////////////////////////////////////////////////////////////////////////////////////////
//////// SoloDeathMatch
ZRuleSoloDeathMatch::ZRuleSoloDeathMatch(ZMatch* pMatch) : ZRule(pMatch)
{

}
ZRuleSoloDeathMatch::~ZRuleSoloDeathMatch()
{

}
/////////////////////////////////////////////////////////////////////////////////////////
//////// TeamDeathMatch
ZRuleTeamDeathMatch::ZRuleTeamDeathMatch(ZMatch* pMatch) : ZRule(pMatch)
{

}
ZRuleTeamDeathMatch::~ZRuleTeamDeathMatch()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//////// TeamDeathMatch Extrame
ZRuleTeamDeathMatch2::ZRuleTeamDeathMatch2(ZMatch* pMatch) : ZRule(pMatch)
{

}
ZRuleTeamDeathMatch2::~ZRuleTeamDeathMatch2()
{

}
bool ZRuleTeamDeathMatch2::OnCommand(MCommand* pCommand)
{
	if (!ZGetGame()) return false;

	switch (pCommand->GetID())
	{

	case MC_MATCH_GAME_DEAD:
		{
			MUID uidAttacker, uidVictim;

			pCommand->GetParameter(&uidAttacker, 0, MPT_UID);
			pCommand->GetParameter(&uidVictim, 2, MPT_UID);

			ZCharacter* pAttacker = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidAttacker);
			ZCharacter* pVictim = (ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidVictim);
			
			m_pMatch->AddTeamKills(pVictim->GetTeamID() == MMT_BLUE ? MMT_RED : MMT_BLUE);
		}
		break;
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////////////////
//////// Capture the flag
ZRuleTeamCTF::ZRuleTeamCTF(ZMatch* pMatch) : ZRule(pMatch)
{
	ZeroMemory(m_BlueFlagPos, sizeof(m_BlueFlagPos));
	ZeroMemory(m_RedFlagPos, sizeof(m_RedFlagPos));
}
ZRuleTeamCTF::~ZRuleTeamCTF()
{

}
bool ZRuleTeamCTF::OnCommand(MCommand* pCommand)
{
	if (!ZGetGame()) return false;

	switch (pCommand->GetID())
	{
		case MC_MATCH_FLAG_STATE:
		{
			int nItemID;
			MShortVector s_pos;
			int IsGone;
			MUID Carrier;
			pCommand->GetParameter(&nItemID, 0, MPT_INT);
			pCommand->GetParameter(&s_pos, 1, MPT_SVECTOR);
			pCommand->GetParameter(&IsGone, 2, MPT_INT);
			pCommand->GetParameter(&Carrier, 3, MPT_UID);
			switch(nItemID)
			{
			case CTF_RED_ITEM_ID:
				{
				SetRedCarrier(Carrier);
				SetRedFlagState(IsGone);
				SetRedFlagPos(rvector(s_pos.x, s_pos.y, s_pos.z));
				}
				break;
			case CTF_BLUE_ITEM_ID:
				{
				SetBlueCarrier(Carrier);
				SetBlueFlagState(IsGone);
				SetBlueFlagPos(rvector(s_pos.x, s_pos.y, s_pos.z));
				}
				break;
			}
		}
		break;

	case MC_MATCH_FLAG_CAP:
		{
			MMatchTeam nTeam;
			pCommand->GetParameter(&nTeam, 0, MPT_INT);
			m_pMatch->AddTeamKills(nTeam == MMT_BLUE ? MMT_BLUE : MMT_RED);

			if(nTeam == MMT_RED)
			{
				ZGetGameInterface()->PlayVoiceSound( VOICE_RED_TEAM_SCORE, 1600);
				ZGetScreenEffectManager()->AddScreenEffect("ctf_score_r");
				SetBlueFlagState(false);
				SetRedCarrier(MUID(0,0));
			}
			else if(nTeam == MMT_BLUE)
			{
				ZGetGameInterface()->PlayVoiceSound( VOICE_BLUE_TEAM_SCORE, 1600);
				ZGetScreenEffectManager()->AddScreenEffect("ctf_score_b");
				SetBlueCarrier(MUID(0,0));
				SetRedFlagState(true);
			}

			for (ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin();
			itor != ZGetGame()->m_CharacterManager.end(); ++itor)
			{
				ZCharacter* pCharacter =(ZCharacter*)(*itor).second;

				if(pCharacter)
				{
					if(pCharacter->GetTeamID() == nTeam)
					{
						pCharacter->SetTagger(false);
					}
				}
			}
		}
		break;
	case MC_MATCH_FLAG_EFFECT:
		{
			MUID uidOwner;
			int nTeam;
			pCommand->GetParameter(&uidOwner,		0, MPT_UID);
			pCommand->GetParameter(&nTeam,			1, MPT_INT);

			ZCharacter* pCapper =(ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidOwner);
			if(pCapper)
			{
				if(!pCapper->IsDie())
				{
					AssignFlagEffect(uidOwner, nTeam);
				}
				else
				{
					for (ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin();
					itor != ZGetGame()->m_CharacterManager.end(); ++itor)
					{
						ZCharacter* pCharacter =(ZCharacter*) (*itor).second;

						if(pCharacter)
						{
							if(pCharacter->GetTeamID() == nTeam)
							{
								pCharacter->SetTagger(false);
							}
						}
					}
					if(nTeam == MMT_RED)
					{
						SetRedCarrier(MUID(0,0));
						SetBlueFlagState(false);
						ZGetScreenEffectManager()->AddScreenEffect("ctf_flagdrop_b");
						ZGetGameInterface()->PlayVoiceSound( VOICE_BLUE_FLAG_RETURN, 1600);
					}
					else if(nTeam == MMT_BLUE)
					{
						SetBlueCarrier(MUID(0,0));
						SetRedFlagState(false);
						ZGetScreenEffectManager()->AddScreenEffect("ctf_flagdrop_r");
						ZGetGameInterface()->PlayVoiceSound( VOICE_RED_FLAG_RETURN, 1600);
					}
				}
			}
			else
			{
					for (ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin();
					itor != ZGetGame()->m_CharacterManager.end(); ++itor)
					{
						ZCharacter* pCharacter =(ZCharacter*) (*itor).second;

						if(pCharacter)
						{
							if(pCharacter->GetTeamID() == nTeam)
							{
								pCharacter->SetTagger(false);
							}
						}
					}
					if(nTeam == MMT_RED)
					{
					SetRedCarrier(MUID(0,0));
					SetBlueFlagState(false);
					ZGetScreenEffectManager()->AddScreenEffect("ctf_flagdrop_b");
					ZGetGameInterface()->PlayVoiceSound( VOICE_BLUE_FLAG_RETURN, 1600);
					}
					else if(nTeam == MMT_BLUE)
					{
					SetBlueCarrier(MUID(0,0));
					SetRedFlagState(false);
					ZGetScreenEffectManager()->AddScreenEffect("ctf_flagdrop_r");
					ZGetGameInterface()->PlayVoiceSound( VOICE_RED_FLAG_RETURN, 1600);
					}
			}
		}
		break;
	}

	return false;
}
void ZRuleTeamCTF::AssignFlagEffect(MUID& uidOwner, int nTeam)
{
	if (!ZGetGame()) return;

	for (ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin();
	itor != ZGetGame()->m_CharacterManager.end(); ++itor)
	{
		ZCharacter* pCharacter =(ZCharacter*) (*itor).second;
		if(pCharacter)
		{
			if(pCharacter->GetTeamID() == nTeam)
			{
				pCharacter->SetTagger(false);
			}
		}
	}

	ZCharacter* pFlagChar =(ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidOwner);


	if (pFlagChar)
	{		
			if(nTeam == MMT_BLUE)
			{
				ZGetEffectManager()->AddBerserkerIcon(pFlagChar);
				ZGetEffectManager()->AddRedFlagIcon(pFlagChar);
				pFlagChar->SetTagger(true);
			}		
			else if(nTeam == MMT_RED)
			{
				ZGetEffectManager()->AddBerserkerIcon(pFlagChar);
				ZGetEffectManager()->AddBlueFlagIcon(pFlagChar);
				pFlagChar->SetTagger(true);
			}

			if(nTeam == MMT_BLUE)
			{
				SetBlueCarrier(uidOwner);
				SetRedFlagState(true);
				ZGetScreenEffectManager()->AddScreenEffect("ctf_taken_r");
				ZGetGameInterface()->PlayVoiceSound( VOICE_BLUE_HAS_FLAG, 1600);
			}
			else if (nTeam == MMT_RED)
			{
				SetRedCarrier(uidOwner);
				SetBlueFlagState(true);
				ZGetScreenEffectManager()->AddScreenEffect("ctf_taken_b");
				ZGetGameInterface()->PlayVoiceSound( VOICE_RED_HAS_FLAG, 1600);
			}
		}
}
/////////////////////////////////////////////////////////////////////////////////////////
//////// Team Escape Mode
bool ZRuleTeamEscape::OnCommand(MCommand* pCommand)
{
	if (!ZGetGame()) return false;

	switch (pCommand->GetID())
	{
	//	HANDLE_COMMAND(MC_MATCH_PORTAL_TEAM					,OnEscapePortalTeam);
		HANDLE_COMMAND(MC_MATCH_PORTAL_STATE				,OnEscapePortalState);
		HANDLE_COMMAND(MC_MATCH_PORTAL_HIT					,OnEscapePortalHit);
		HANDLE_COMMAND(MC_MATCH_PORTAL_EFFECT				,OnEscapePortalEffect);
	}
	return false;
}
bool ZRuleTeamEscape::OnEscapePortalTeam(MCommand* pCommand)
{
	return false;
}
bool ZRuleTeamEscape::OnEscapePortalState(MCommand* pCommand)
{
	int nItemID;
	MShortVector s_pos;
	int IsClose;

	pCommand->GetParameter(&nItemID, 0, MPT_INT);
	pCommand->GetParameter(&s_pos, 1, MPT_SVECTOR);
	pCommand->GetParameter(&IsClose, 2, MPT_INT);

	switch(nItemID)
	{
	case ESCAPE_PORTAL_RED_ITEM_ID:
		{
			//SetRedFlagState(IsClose);
			//SetRedFlagPos(rvector(s_pos.x, s_pos.y, s_pos.z));
		}
		break;
	case ESCAPE_PORTAL_BLUE_ITEM_ID:
		{
			//SetBlueFlagState(IsGone);
			//SetBlueFlagPos(rvector(s_pos.x, s_pos.y, s_pos.z));
		}
		break;
	}
	return false;
}
bool ZRuleTeamEscape::OnEscapePortalHit(MCommand* pCommand)
{
return false;
}
bool ZRuleTeamEscape::OnEscapePortalEffect(MCommand* pCommand)
{
	MUID uidOwner;
	int nTeam;
	pCommand->GetParameter(&uidOwner,		0, MPT_UID);
	pCommand->GetParameter(&nTeam,			1, MPT_INT);

	ZCharacter* pEscapeChar =(ZCharacter*) ZGetGame()->m_CharacterManager.Find(uidOwner);

	if (pEscapeChar)
	{		
		if(nTeam == MMT_BLUE)
		{
			ZChatOutput(MCOLOR(ZCOLOR_CHAT_SYSTEM), "You Escaped in the red portal!");
			pEscapeChar->SetTagger(true);
		}		
		else if(nTeam == MMT_RED)
		{
			ZChatOutput(MCOLOR(ZCOLOR_CHAT_SYSTEM), "You Escaped in the blue portal!");
			pEscapeChar->SetTagger(true);
		}
	}
	else
	{
		if(nTeam == MMT_BLUE)
		{
				char msg[255];
				sprintf(msg, "%s has escaped in the red portal!", GetBlueEscapeChar());
				ZChatOutput(MCOLOR(ZCOLOR_CHAT_SYSTEM), msg);
				pEscapeChar->SetTagger(true);
		}
		else if(nTeam == MMT_RED)
		{
				char msg[255];
				sprintf(msg, "%s has escaped in the blue portal!", GetRedEscapeChar());
				ZChatOutput(MCOLOR(ZCOLOR_CHAT_SYSTEM), msg);
				pEscapeChar->SetTagger(true);
		}
	}
return false;
}

