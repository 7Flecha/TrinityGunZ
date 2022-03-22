#ifndef _ZRULE_BOUNTY_H
#define _ZRULE_BOUNTY_H

#include "ZRule.h"

class ZRuleBounty : public ZRule
{
private:
	MUID	m_uidBounty;
	float	m_fElapsedHealthUpdateTime;
	void AssignBounty(MUID& uidBounty);

public:
	ZRuleBounty(ZMatch* pMatch);
	virtual ~ZRuleBounty();
	virtual bool OnCommand(MCommand* pCommand);
	virtual void OnResponseRuleInfo(MTD_RuleInfo* pInfo);
	virtual void onDraw(MDrawContext* pDC);
	MUID GetBountyUID() const { return m_uidBounty; }
};

#define Bounty_DAMAGE_RATIO			2.0f		// 버서커가 되면 파워가 2배로 된다.

#endif