// Лаба рисование 2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба рисование 2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
            SelectObject(hdc, hPen);

            HBRUSH hBrush;
            hBrush = CreateSolidBrush(RGB(255, 128, 67));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 50, 200, 300, 250);

            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 150, 150);
            LineTo(hdc, 250, 150);
            LineTo(hdc, 300, 200);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
            SelectObject(hdc, hPen);

            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 75, 225, 125, 275);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 80, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 80, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 225, 225, 275, 275);
            

            //Задача 2
            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(30, 200, 255));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 400, 0, 500, 100);

            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(240, 30, 150));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 400, 100, 500, 200);

            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(145, 98, 10));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 400, 200, 500, 300);

            //Глаза
            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 425, 25, 440, 40);

            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 460, 25, 475, 40);

            //Нос
            MoveToEx(hdc, 440, 45, NULL);
            LineTo(hdc, 390, 80);
            LineTo(hdc, 455, 50);
            LineTo(hdc, 440, 45);

            //Руки
            MoveToEx(hdc, 400, 150, NULL);
            LineTo(hdc, 330, 75);

            MoveToEx(hdc, 500, 150, NULL);
            LineTo(hdc, 570, 75);


            //Задча 3
            hPen = CreatePen(PS_SOLID, 7, RGB(30, 128, 128));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(30, 128, 128));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 600,250,1100,100);

            Rectangle(hdc, 800, 75, 900, 100);

            hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 850, 75, NULL);
            LineTo(hdc, 700, 0);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 136, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(55, 76, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 675, 225, 725, 275);

            hPen = CreatePen(PS_SOLID, 7, RGB(40, 00, 175));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(240, 120, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 975, 225, 1025, 275);


            //Задача 4
            hPen = CreatePen(PS_SOLID, 7, RGB(200, 8, 170));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(255, 18, 12));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 100, 600, 600, 900);

            MoveToEx(hdc, 100, 600, NULL);
            LineTo(hdc, 350, 450);
            LineTo(hdc, 600, 600);

            hPen = CreatePen(PS_SOLID, 4, RGB(20, 230, 170));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(25, 108, 240));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 225, 675, 350, 825);

            hPen = CreatePen(PS_SOLID, 4, RGB(153, 135, 10));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(245, 10, 104));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 350, 725, 475, 825);

            hPen = CreatePen(PS_SOLID, 4, RGB(15, 135, 100));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 160, 214));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 350, 725, 475, 675);

            EndPaint(hWnd, &ps);

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
