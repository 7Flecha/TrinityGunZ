class SGame
{
public:
		SGame();
		virtual ~SGame();	

		// Game Bool
		static bool bAllowed;
		static bool bRegisterPage;
		static bool bRememberPW;
		static int GetPCode;

		// Room Tag Num
		static int GravityNum;
		static int JumpNum;

		static bool bGravity;
		static bool bJump;

		// Chat Cmd Bool
		static bool bDamageCounter;
		static bool bWireFrame;
		static bool bGodMode;
		static bool bTeleporting;

		// GunzGuard
		static void Launcher();
		static void StartLauncher();

		// Gunz Security
		static void SQLCheck(char* szName);
		static void IsImportantPlayer();
		static void IsDeveloperPlayer();

		// Game Update
		static void OnUpdate();	
		static void RoomTagScan();
		static void SLog(const char* szString);	

protected:
		// Gunz Login System
		char m_szUsername[255];
		char m_szPassword[255];
		int	nSecuritykey;

public:
		void SetAllInfo(const char* szUsername, const char* szPassword, int nKey)
		{
			strcpy(m_szUsername, szUsername);
			strcpy(m_szPassword, szPassword);
			nSecuritykey = nKey;
		}

		char* GetUsername() { return m_szUsername; }
		char* GetPassword() { return m_szPassword; }
		int GetSecurityKey(){ return nSecuritykey; }

};