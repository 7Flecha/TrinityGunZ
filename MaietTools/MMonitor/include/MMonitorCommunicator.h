#ifndef _MMonitorCOMMUNICATOR
#define _MMonitorCOMMUNICATOR


#include <string>

using std::string;


namespace MMonitor {

class MMonitorCommunicator
{
public :
	MMonitorCommunicator() {}
	virtual ~MMonitorCommunicator() {}
	
	virtual bool	Init()		{ return true; }
	virtual void	Release()	{}

	virtual bool	Send( const DWORD dwIP, const USHORT nPort, const string& strMonitorCommand ) = 0;
};

}

#endif