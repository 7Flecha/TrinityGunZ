#include "stdafx.h"
#include "ZRule.h"
#include "ZMatch.h"
#include "ZRuleDeathMatch.h"
#include "ZRuleGladiator.h"
#include "ZRuleAssassinate.h"
#include "ZRuleTraining.h"
#include "ZRuleQuest.h"
#include "ZRuleSurvival.h"
#include "ZRuleQuestChallenge.h"
#include "ZRuleBountyHunter.h"
#include "ZRuleVampireMode.h"
#include "ZRuleInfected.h"
#include "ZRuleBerserker.h"
#include "ZRuleDuel.h"
#include "ZRuleDuelTournament.h"

ZRule::ZRule(ZMatch* pMatch)
{
	m_pMatch = pMatch;				// 초기화 =_=
}

ZRule::~ZRule()
{

}

void ZRule::Update(float fDelta)
{
	OnUpdate(fDelta);
}

ZRule* ZRule::CreateRule(ZMatch* pMatch, MMATCH_GAMETYPE nGameType)
{
	switch(nGameType)
	{
	case MMATCH_GAMETYPE_DEATHMATCH_SOLO:
		{
			return (new ZRuleSoloDeathMatch(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_DEATHMATCH_TEAM:
		{
			return (new ZRuleTeamDeathMatch(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_GLADIATOR_SOLO:
		{
			return (new ZRuleSoloGladiator(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_GLADIATOR_TEAM:
		{
			return (new ZRuleTeamGladiator(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_ASSASSINATE:
		{
			return (new ZRuleAssassinate(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_TRAINING:
		{
			return (new ZRuleTraining(pMatch));
		}
		break;
#ifdef _QUEST
	case MMATCH_GAMETYPE_SURVIVAL:
		{
			return (new ZRuleSurvival(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_QUEST:
		{
			return (new ZRuleQuest(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_QUEST_CHALLENGE:
		{
			return (new ZRuleQuestChallenge(pMatch));
		}
		break;
#endif
	case MMATCH_GAMETYPE_BERSERKER:
		{
			return (new ZRuleBerserker(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_DEATHMATCH_TEAM2:
		{
			return (new ZRuleTeamDeathMatch2(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_DUEL:
		{
			return (new ZRuleDuel(pMatch));
		}
		break;

	case MMATCH_GAMETYPE_DUELTOURNAMENT:
		{
			return (new ZRuleDuelTournament(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_VAMPIRE:
		{
			return (new ZRuleVampire(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_CTF:
		{
			return (new ZRuleTeamCTF(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_TRAINING_TEAM:
		{
			return (new ZRuleTeamTraining(pMatch));
		}
		break;
	case MMATCH_GAMETYPE_BOUNTY:
		{
			return (new ZRuleBounty(pMatch));
		}
		break;


	default:
		{
			// 게임 타입이 없습니다.
			//_ASSERT(0);
		}
	}
	return NULL;

}

float ZRule::FilterDelayedCommand( MCommand* pCommand )
{
	return 0;
}

bool ZRule::OnCommand(MCommand* pCommand)
{
	return false;
}

void ZRule::AfterCommandProcessed( MCommand* pCommand )
{

}

void ZRule::OnResponseRuleInfo(MTD_RuleInfo* pInfo)
{

}