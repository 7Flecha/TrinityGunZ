#include "stdafx.h"
#include "NewAppLoginBox.h"
#include "NewAppDlg.h"



/************************************************************************************
  Dialog
*************************************************************************************/
// Å¬·¡½º »ý¼ºÀÚ
CNewAppLoginBox::CNewAppLoginBox( CWnd* pParent) : CDDBDialog( IDD_LOGINBOX, pParent)
{
	CDDBDLGINFO DlgInfo;
	DlgInfo.nWidth  = 366; //432
	DlgInfo.nHeight = 207; //320
	DlgInfo.IDSkinResource = IDR_BMP_POPUPDLG;
	DlgInfo.nTextColor = RGB( 150, 150, 150);
	DlgInfo.nTextBkColor = RGB( 46, 47, 48);
	SetDialogInfo( DlgInfo);
	m_pParentDialog = NULL;

}


// DoDataExchange
void CNewAppLoginBox::DoDataExchange( CDataExchange* pDX)
{
	CDDBDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK,				m_cOK);
	DDX_Control(pDX, IDCANCEL,			m_cCancel);
	DDX_Control(pDX, IDC_ID,			m_cID);
	DDX_Control(pDX, IDC_PASSWORD,		m_cPassword);
}

// Message map
BEGIN_MESSAGE_MAP( CNewAppLoginBox, CDDBDialog)
	ON_BN_CLICKED(IDOK, OnBnLoginRequest)
END_MESSAGE_MAP()



/************************************************************************************
  Å¬·¡½º ¸Þ¼¼Áö ÇÚµé·¯
*************************************************************************************/
// OnInitDialog : ´ÙÀÌ¾ó·Î±×¸¦ ÃÊ±âÈ­´Â ÇÔ¼ö
BOOL CNewAppLoginBox::OnInitDialog() 
{
	CDDBDialog::OnInitDialog();

	// À©µµ¿ì ÀÌµ¿
	if ( m_pParentDialog != NULL)
	{
		CRect rect;
		m_pParentDialog->GetWindowRect( &rect);
		int x = rect.left + rect.Width() / 2 - GetWidth() / 2;
		int y = rect.top + rect.Height() / 2 - GetHeight() / 2;
		MoveWindow( x, y, GetWidth(), GetHeight());
	}
	

	// Box
	DrawPanel( 6, 25, GetWidth()-12, GetHeight()-31);

	// Button Sound
	m_cOK.InitDDBButton( IDR_BMP_BUTTON, IDR_WAV_PUSHBUTTON);
	m_cCancel.InitDDBButton( IDR_BMP_BUTTON, IDR_WAV_PUSHBUTTON);

	// Login Box
	GetScreen()->PutText( 45, 77, 15, "Arial", "Username", RGB( 180, 180, 180), TS_BOLD);
	GetScreen()->PutText( 45, 103, 15, "Arial", "Password", RGB( 180, 180, 180), TS_BOLD);
	GetScreen()->PutBox( 110, 75, 196, 22, RGB( 180, 180, 180));
	GetScreen()->PutBox( 110, 101, 196, 22, RGB( 180, 180, 180));
	m_cID.MoveWindow( 111, 76, 194, 20);
	m_cPassword.MoveWindow( 111, 102, 194, 20);

	// Login Title
	GetScreen()->PutText(  9, 5, 17, "Arial", "Login", RGB( 0, 0, 0), TS_BOLD);
	GetScreen()->PutText( 10, 6, 17, "Arial", "Login", RGB( 180, 180, 180), TS_BOLD);

	// Buttons
	m_cOK.SetWindowText( "OK");
	m_cOK.ShowWindow( SW_SHOW);
	m_cOK.EnableWindow( TRUE);		// Disable wanneer login en password are empty
	m_cOK.MoveWindow( GetWidth() / 2 - m_cOK.GetWidth() - 5, GetHeight() - 35);

	m_cCancel.SetWindowText( "Cancel");
	m_cCancel.ShowWindow( SW_SHOW);
	m_cCancel.EnableWindow( TRUE);
	m_cCancel.MoveWindow( GetWidth() / 2 + 5, GetHeight() - 35);

	return true;
}


char* GetResponseFromURL( unsigned long* dwRecvCount, char* szURL, ... )
{
	// variaveis locais 
	HINTERNET hUrl, hSession;
	unsigned long dwRecv;
	char szFinalURL[512];

	// buffer alocado para retorno
	char* szBuffer = new char[512];

	// limpa o buffer de retorno
	memset( szBuffer, 0, 512 );

	// monta a URL com os parametros adicionais
	va_list va_alist;
	va_start( va_alist, szURL );
	vsprintf_s( szFinalURL, 512, szURL, va_alist );
	va_end( va_alist );

	// obtem handle da sessao da internet
	hSession = InternetOpenA( "Microsoft Internet Explorer", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0 );

	// se falhou ao obter sessao finaliza a funcao
	if( !hSession )
		return szBuffer;

	// obtem handle da url
	hUrl = InternetOpenUrlA( hSession, szFinalURL, 0, 0, 0, 0 );

	// se falhou ao obter handle da url finaliza a funcao
	if( !hUrl )
		return szBuffer;

	// le a url e armazena oq foi lido no buffer de retorno
	InternetReadFile( hUrl,	szBuffer, 512, &dwRecv );

	// fecha todas as handles, de url e da sessao
	InternetCloseHandle( hSession );
	InternetCloseHandle( hUrl );

	// se o valor de bytes lidos for 0 encerra a funcao
	if( !dwRecv )
		return szBuffer;

	// se a variavel dwRecvCount for válida armazena a quantidade de bytes recebidos
	if( dwRecvCount )
		*dwRecvCount = dwRecv;

	// retorna o buffer
	return szBuffer;
}



// Login Request
void CNewAppLoginBox::OnBnLoginRequest()
{
	// Check
	CString strPassword, strUsername;
	m_cPassword.GetWindowText( strPassword);
	m_cID.GetWindowText( strUsername);


	if( strPassword.IsEmpty() && strUsername.IsEmpty())
	{
		MessageBox( "Please Fill an Username and Password", "Error", MB_OK); 
		return;
	}
	else if ( strPassword.IsEmpty())
	{
		MessageBox( "Please Fill an Password", "Error", MB_OK); 
		return;
	}
	else if ( strUsername.IsEmpty())
	{
		MessageBox( "Please Fill an Username", "Error", MB_OK); 
		return;
	}
	

	char* pBuffer = GetResponseFromURL(NULL, "http://patch.devilgunz.com/test/test.php?User=%s&Pass=%s", strUsername, strPassword); 

	if(stricmp(pBuffer, "ERROR"))
	{

		CNewAppDlg dlg;
		// Set Info
		dlg.SetInfo(strUsername, strPassword);
		// Exit Form
		CDialog::OnOK();
		// Open Form
		dlg.DoModal();
	}
	else if(stricmp(pBuffer, "OK"))
	{
		MessageBox( "Your Login information is not correct!", "Error", MB_OK);
	}
	else
	{
		MessageBox( "Login Network is offline!", "Error", MB_OK);
	}
}