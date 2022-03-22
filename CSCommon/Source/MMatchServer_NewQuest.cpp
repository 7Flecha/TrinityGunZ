#include "stdafx.h"
#include "MMatchServer.h"
#include "MMatchStage.h"
#include "MMatchRule.h"
#include "MMatchRuleQuestChallenge.h"
#include "MMatchGameType.h"
#include "MMatchConfig.h"
#include "MBlobArray.h"
#include "MMatchShop.h"

void MMatchServer::OnNewQuestRequestDead(const MUID& uidVictim)
{
	MMatchObject* pVictim = GetObject(uidVictim);
	if (pVictim == NULL) return;

	MMatchStage* pStage = FindStage(pVictim->GetStageUID());
	if (pStage == NULL) return;

	if ( !MGetGameTypeMgr()->IsCQuestDerived(pStage->GetStageSetting()->GetGameType())) return;

	// Check if live so not response dead
	if (pVictim->CheckAlive() == false) {	
		MCommand* pNew = CreateCommand(MC_MATCH_RESPONSE_SUICIDE, MUID(0,0));
		int nResult = MOK;
		pNew->AddParameter(new MCommandParameterInt(nResult));
		pNew->AddParameter(new MCommandParameterUID(pVictim->GetUID()));
		RouteToBattle(pStage->GetUID(), pNew);
		return;
	}

	pVictim->OnDead();

	// Send Player Dead to Quest 
	MCommand* pCmd = CreateCommand(MC_NEWQUEST_PLAYER_DEAD, MUID(0,0));
	pCmd->AddParameter(new MCommandParameterUID(uidVictim));	
}
