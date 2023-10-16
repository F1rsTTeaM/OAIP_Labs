// ЛР №9 Ладягин ПИбд-13.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "ЛР №9 Ладягин ПИбд-13.h"

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
    LoadStringW(hInstance, IDC_MY913, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY913));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY913));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY913);
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

void StClauseAuto(HDC hdc,int x, int y){
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    //Верхний треугольник
    MoveToEx(hdc, x + 20, y, NULL);
    LineTo(hdc, x + 30, y + 20);
    LineTo(hdc, x + 10, y + 20);
    LineTo(hdc, x + 20, y);

    //Средний треугольник
    MoveToEx(hdc, x + 20, y + 10, NULL);
    LineTo(hdc, x + 30, y + 40);
    LineTo(hdc, x + 10, y + 40);
    LineTo(hdc, x + 20, y + 10);

    //Нижний треугольник
    MoveToEx(hdc, x + 20, y + 30, NULL);
    LineTo(hdc, x + 40, y + 80);
    LineTo(hdc, x, y + 80);
    LineTo(hdc, x + 20, y + 30);
}

void drawTruck(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, x + 0, y + 30, x + 40, y + 50);
    Rectangle(hdc, x + 10, y + 10, x + 40, y + 30);
    Rectangle(hdc, x + 40, y + 0, x + 100, y + 50);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, x + 10, y + 40, x + 30, y + 60);
    Ellipse(hdc, x + 70, y + 40, x + 90, y + 60);
}

void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 1010, 10);
    drawTruck(hdc, 1010, 310);
    drawTruck(hdc, 1310, 10);
    drawTruck(hdc, 1310, 310);
    drawTruck(hdc, 1160, 160);
}

void drawTrucks2(HDC hdc) {
    int x = 1510;
    do {
        drawTruck(hdc,x,10);
        x += 150;
    } while (x < 1920);
}

void drawTrucks3(HDC hdc) {
    int y = 450;
    do {
        drawTruck(hdc, 1010, y);
        y += 100;
    } while (y < 1080);
}

void drawTrucks4(HDC hdc) {
    int x = 1510, y = 450;
    do {
        drawTruck(hdc, x, y);
        x += 100;
        y += 100;
    } while (x < 1920 && y < 1080);
}

void Logo(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 6, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, x, y, x + 270, y + 270);
    hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x + 135, y, NULL);
    LineTo(hdc, x + 135, y + 135);
    LineTo(hdc, x + 20, y + 200);
    MoveToEx(hdc, x + 135, y + 135, NULL);
    LineTo(hdc, x + 250, y + 200);
}

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
            
            //Задача 1.1
            StClauseAuto(hdc,0,0);
            StClauseAuto(hdc, 200, 200);
            StClauseAuto(hdc, 100, 100);
            StClauseAuto(hdc, 0, 200);
            StClauseAuto(hdc, 200, 0);

            //Задача 1.2
            int x = 500;
            do {
                StClauseAuto(hdc, x, 0);
                x += 50;
            } while (x < 900);

            //Задача 1.3
            int y = 500;
            do {
                StClauseAuto(hdc, 0, y);
                y += 90;
            } while (y < 800);

            //Задача 1.4
            x = 500, y = 500;
            do {
                StClauseAuto(hdc, x, y);
                x += 50;
                y += 100;
            } while (x < 1000 && y < 900);


            drawTrucks1(hdc);
            drawTrucks2(hdc);
            drawTrucks3(hdc);
            drawTrucks4(hdc);
            Logo(hdc,500,150);

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
