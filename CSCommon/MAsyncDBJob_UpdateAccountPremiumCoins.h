#pragma once



#include "MAsyncDBJob.h"



class MAsyncDBJob_UpdateAccountPremiumCoins : public MAsyncJob
{
public :
	MAsyncDBJob_UpdateAccountPremiumCoins(const MUID& uidOwner) : MAsyncJob( MASYNCJOB_UPDATEACCOUNTPREMIUMCOINS, uidOwner )
	{
	}

	~MAsyncDBJob_UpdateAccountPremiumCoins()
	{
	}

	void Input( const DWORD dwAID)
	{
		m_dwAID = dwAID;
	}

	void Run( void* pContext )
	{
		MMatchDBMgr* pDBMgr = (MMatchDBMgr*)pContext;

		pDBMgr->UpdateAccountPremiumCoins( m_dwAID );
	}

private :
	DWORD m_dwAID;
};