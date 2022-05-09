#include "frame.h"
#include "Button.h"

// �ϴ��� ���� ���� 1���� ����Ѵ�.
extern Frame* mainWindow;

// �����Լ��δ� ���� �޽��� ó�� �Լ��� �ִ�.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_RBUTTONUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	case WM_SIZE:
		if (mainWindow != nullptr)
			mainWindow->eventHandler(MyEvent(Msg, wParam, lParam));
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);

		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
		if (ps.fErase) {
			OutputDebugString(L"����� �׷�����\n");  // �� ���� �׽�Ʈ���̴� ���߿� ���ش�.
		}

		// MainWindow  ��ü�� repaint �� ȣ���Ѵ�.		
		if (mainWindow != nullptr)
			mainWindow->repaint();

		EndPaint(Hw, &ps);  // BeginPaint�� ¦�� �ȴ�
	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame() :Frame(L"", 800, 600) {	
	//	
}

Frame::Frame(std::wstring title, int width, int height)
{
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWIn", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // ���� �ּ�ȭ �ִ�ȭ ������
		WS_THICKFRAME,  // resize�� �����ϰ�
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	invalidate();
}

void Frame::run()
{
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));

	MSG msg;

	initialize();

	// �⺻ �޽��� �����Դϴ�:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		//if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)
		if (!TranslateAccelerator(msg.hwnd, NULL, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

Component* Frame::eventHandler(MyEvent e)
{
	if (e.isLButtonDown() || e.isRButtonDown()) {
		start_ = e.getPos();
		Component* b = findComponent(e.getPos());
		if (b)
			b->onClick(e);
		return b;
	}
	return nullptr;
}

Component* Frame::findComponent(MyPoint p)
{
	for (auto b : componentList) {
		if (b->inside(p))
			return b;
	}
	return nullptr;
}

void Frame::add(Component* b)
{	
	//container�� �� component�� add�� �ԾƳ��� ����� componentList�� �ȳֵ���
	if (b->getCompoParent() == nullptr) {
		b->setFrameParent(this);
	}
	else {
		componentList.push_back(b);
		b->setFrameParent(this);
	}	
}

void Frame::remove(Component* b)
{		
	componentList.remove(b);	
}

void Frame::repaint()
{	
	 //�׷����� ��� ���� ���⿡.		
	for (auto i = componentList.begin(); i != componentList.end(); i++) {
		(*i)->draw(hDC_);
	}
	//OutputDebugString(L"repaint()\n");
}

void Frame::invalidate() { InvalidateRect(hWnd_, nullptr, true); }

void Frame::changeLabel(Component* c) {}