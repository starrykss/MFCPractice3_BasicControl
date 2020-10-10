
// MFCPractice3_BasicControlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCPractice3_BasicControl.h"
#include "MFCPractice3_BasicControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCPractice3BasicControlDlg 대화 상자



CMFCPractice3BasicControlDlg::CMFCPractice3BasicControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPRACTICE3_BASICCONTROL_DIALOG, pParent)
	, m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// 체크 박스 설정
	m_bChecked[0] = FALSE;
	m_bChecked[1] = FALSE;
}

void CMFCPractice3BasicControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strEdit);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_listBox);
	DDX_Control(pDX, IDC_COMBO_AUTO, m_cbListItem);
}

BEGIN_MESSAGE_MAP(CMFCPractice3BasicControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &CMFCPractice3BasicControlDlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CMFCPractice3BasicControlDlg::OnRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCPractice3BasicControlDlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCPractice3BasicControlDlg::OnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCPractice3BasicControlDlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CMFCPractice3BasicControlDlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMFCPractice3BasicControlDlg::OnClickedButtonDelete)
END_MESSAGE_MAP()


// CMFCPractice3BasicControlDlg 메시지 처리기

BOOL CMFCPractice3BasicControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCPractice3BasicControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCPractice3BasicControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCPractice3BasicControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPractice3BasicControlDlg::UpdateComboBox()
{
	// TODO: 여기에 구현 코드 추가.
	int nCnt = m_listBox.GetCount();
	m_cbListItem.ResetContent();

	for (int i = 0; i < nCnt; i++) 
	{
		CString strItem;
		strItem.Format(_T("리스트 항목: %d"), i + 1);
		m_cbListItem.AddString(strItem);
	}
}


void CMFCPractice3BasicControlDlg::OnRadio1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_listBox.AddString(_T("라디오1 선택"));
	UpdateComboBox();
}


void CMFCPractice3BasicControlDlg::OnRadio2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_listBox.AddString(_T("라디오2 선택"));
	UpdateComboBox();
}


void CMFCPractice3BasicControlDlg::OnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[0] == FALSE)
	{
		m_bChecked[0] = TRUE;
		m_listBox.AddString(_T("체크박스 1 체크"));
	}
	else {
		m_bChecked[0] = FALSE;
		m_listBox.AddString(_T("체크박스 1 해제"));
	}
	UpdateComboBox();
}


void CMFCPractice3BasicControlDlg::OnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[1] == FALSE)
	{
		m_bChecked[1] = TRUE;
		m_listBox.AddString(_T("체크박스 2 체크"));
	}
	else {
		m_bChecked[1] = FALSE;
		m_listBox.AddString(_T("체크박스 2 해제"));
	}
	UpdateComboBox();
}


void CMFCPractice3BasicControlDlg::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);		// 사용자가 입력한 내용을 가져오는 함수 (m_strEdit 함수에 내용 저장)

	if (m_strEdit.IsEmpty() == FALSE)
	{
		m_listBox.AddString(m_strEdit);
		m_strEdit.Empty();
	}
	else 
	{
		AfxMessageBox(_T("문자를 입력하세요."));
	}
	UpdateData(FALSE);
	UpdateComboBox();
}


void CMFCPractice3BasicControlDlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strSelText;
	int index = m_cbListItem.GetCurSel();   // Get Current Select : 현재 콤보 박스에 있는 아이템의 인덱스를 가져옴.
	if (index != CB_ERR)
	{
		m_listBox.GetText(index, strSelText);
		m_listBox.AddString(strSelText);
		UpdateComboBox();
	}
	else {
		AfxMessageBox(_T("콤보 박스에서 추가할 아이템을 선택하세요."));
	}
}


void CMFCPractice3BasicControlDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR)
	{
		m_listBox.DeleteString(index);
		UpdateComboBox();
	}
	else
	{
		AfxMessageBox(_T("콤보 박스에서 삭제할 아이템을 선택하세요."));
	}
}
