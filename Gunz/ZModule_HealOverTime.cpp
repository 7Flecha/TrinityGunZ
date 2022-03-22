
#include "stdafx.h"
#include "ZModule_HealOverTime.h"
#include "ZGame.h"
#include "ZApplication.h"
#include "ZModule_HPAP.h"

int GetEffectLevel();

ZModule_HealOverTime::ZModule_HealOverTime()
{
	ClearHeal();
}

ZModule_HealOverTime::~ZModule_HealOverTime()
{
	ClearHeal();
}

void ZModule_HealOverTime::InitStatus()
{
	Active(false);
}

bool ZModule_HealOverTime::Update(float fElapsed)
{
	ZCharacter* pChar = MDynamicCast(ZCharacter, m_pContainer);
	if (!pChar)
		_ASSERT(0);
	else
	{
		for(list<ZHealInfo *>::iterator i = m_Heals.begin(); 
			i != m_Heals.end(); i++)
		{
			ZHealInfo *pInfo = (*i);

			if(ZGetGame()->GetTime() > pInfo->fNextHealTime) {
				pInfo->fNextHealTime += 1.f;
				pInfo->numHealDone += 1;

				if(pChar->IsDie())
				{
					pInfo->bOnHeal = false;
				}
				else
				{
					switch (pInfo->type)
					{
					case MMDT_HEAL:
						pChar->SetHP( min( pChar->GetHP() + pInfo->fHeal, pChar->GetMaxHP() ) );
						break;
					case MMDT_REPAIR:
						pChar->SetAP( min( pChar->GetAP() + pInfo->fHeal, pChar->GetMaxAP() ) );
						break;
					default:
						_ASSERT(0);
					}
					ZGetEffectManager()->AddPotionEffect( pChar->GetPosition(), pChar, pInfo->nEffectId );
				}
			}
			if(pInfo->numHealDone == pInfo->numHealDesire) {
				pInfo->bOnHeal = false;
			}
		}
	}

	RemoveEndedHeal();
	return true;
}

void ZModule_HealOverTime::BeginHeal(MMatchDamageType type, int nHealAmount, int numHeal, MMatchItemEffectId effectId, int nItemId)
{
	if (type != MMDT_HEAL && type != MMDT_REPAIR) { _ASSERT(0); return; }

	ZHealInfo *pNew = new ZHealInfo;

	pNew->type = type;
	pNew->nEffectId = effectId;

	float fCurrTime = ZGetGame()->GetTime();

	pNew->fBeginTime = fCurrTime;

	pNew->fHeal = (float)nHealAmount;
	pNew->numHealDesire = numHeal;
	pNew->numHealDone = 0;

	pNew->fNextHealTime = fCurrTime;

	pNew->bOnHeal = true;
	pNew->nItemId = nItemId;

	m_Heals.push_back(pNew);


	Active();
}

bool ZModule_HealOverTime::GetHealOverTimeBuffInfo(vector<MTD_BuffInfo> &vecOut)
{
	for(list<ZHealInfo *>::iterator i = m_Heals.begin(); 
		i != m_Heals.end(); i++)
	{
		ZHealInfo *pInfo = (*i);

		MTD_BuffInfo temp;
		temp.nItemId = pInfo->nItemId;
		temp.nRemainedTime = pInfo->numHealDesire - pInfo->numHealDone;
		vecOut.push_back(temp);
	}

	return true;
}

void ZModule_HealOverTime::ShiftFugitiveValues()
{
	// Nothing.
}


void ZModule_HealOverTime::RemoveEndedHeal()
{
	list<ZHealInfo *>::iterator i = m_Heals.begin();

	while(i != m_Heals.end())
	{
		if((*i)->bOnHeal == false)
		{
			delete (*i);
			i = m_Heals.erase(i);
		}
		else
			i++;
	}
}

void ZModule_HealOverTime::ClearHeal()
{
	for(list<ZHealInfo *>::iterator i = m_Heals.begin(); 
		i != m_Heals.end(); i++)
			delete (*i);

	m_Heals.clear();
}