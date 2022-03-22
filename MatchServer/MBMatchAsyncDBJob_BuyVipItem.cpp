#include "stdafx.h"
#include "MBMatchAsyncDBJob_BuyVipItem.h"

void MBMatchAsyncDBJob_BuyVipItem::Run( void* pContext )
{
	MMatchDBMgr* pDBMgr = (MMatchDBMgr*)pContext;

	if( !pDBMgr->BuyVipItem(m_nCID, m_nItemID, m_nItemCount, m_dwPrice, m_wRentHourPeriod, m_bIsSpendableItem, &m_dwCIID) )
	{
		SetResult( MASYNC_RESULT_FAILED );
		return;
	}

	SetResult( MASYNC_RESULT_SUCCEED );
}