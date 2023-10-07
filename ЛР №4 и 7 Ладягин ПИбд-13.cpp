// Лаба рисование.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба рисование.h"

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
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY);
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
            
            //Земля
            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 0, 900,NULL);
            LineTo(hdc, 1920, 900);

            //Дом
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 128, 255));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 100, 900, NULL);
            LineTo(hdc, 100, 600);
            LineTo(hdc, 600, 600);
            LineTo(hdc, 600, 900);
            //Крыша
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 128, 255));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 100, 600, NULL);
            LineTo(hdc, 350, 450);
            LineTo(hdc, 600, 600);
            //Окно
            hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 225, 675, NULL);
            LineTo(hdc, 475, 675);
            LineTo(hdc, 475, 825);
            LineTo(hdc, 225, 825);
            LineTo(hdc, 225, 675);
            hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 350, 675, NULL);
            LineTo(hdc, 350, 825);
            hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 350, 725, NULL);
            LineTo(hdc, 475, 725);

            //Ёлка
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 650, 900, NULL);
            LineTo(hdc, 800, 900);
            LineTo(hdc, 725, 850);
            LineTo(hdc, 650, 900);
            MoveToEx(hdc, 675, 850, NULL);
            LineTo(hdc, 775, 850);
            LineTo(hdc, 725, 800);
            LineTo(hdc, 675, 850);
            MoveToEx(hdc, 700, 800, NULL);
            LineTo(hdc, 750, 800);
            LineTo(hdc, 725, 750);
            LineTo(hdc, 700, 800);

            //Дерево
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 900, 900, NULL);
            LineTo(hdc, 900, 750);
            MoveToEx(hdc, 900, 850, NULL);
            LineTo(hdc, 850, 825);
            MoveToEx(hdc, 900, 825, NULL);
            LineTo(hdc, 950, 800);
            MoveToEx(hdc, 900, 800, NULL);
            LineTo(hdc, 850, 780);
            MoveToEx(hdc, 900, 775, NULL);
            LineTo(hdc, 925, 760);

            //Сарай
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 1100, 900, NULL);
            LineTo(hdc, 1100, 400);
            LineTo(hdc, 1900, 400);
            LineTo(hdc, 1900, 900);
            LineTo(hdc, 1100, 900);
            //Крыша сарая
            MoveToEx(hdc, 1100, 400, NULL);
            LineTo(hdc, 1300, 150);
            LineTo(hdc, 1500, 100);
            LineTo(hdc, 1700, 150);
            LineTo(hdc, 1900, 400);
            //Первый этаж
            //Дверь
            MoveToEx(hdc, 1400, 900, NULL);
            LineTo(hdc, 1600, 900);
            LineTo(hdc, 1600, 550);
            LineTo(hdc, 1400, 550);
            LineTo(hdc, 1400, 900);
            MoveToEx(hdc, 1500, 900, NULL);
            LineTo(hdc, 1500, 550);
            //Пр. окно
            MoveToEx(hdc, 1650, 650, NULL);
            LineTo(hdc, 1750, 650);
            LineTo(hdc, 1750, 750);
            LineTo(hdc, 1650, 750);
            LineTo(hdc, 1650, 650);
            MoveToEx(hdc, 1700, 650, NULL);
            LineTo(hdc, 1700, 750);
            MoveToEx(hdc, 1650, 700, NULL);
            LineTo(hdc, 1750, 700);
            //Л. окно
            MoveToEx(hdc, 1250, 650, NULL);
            LineTo(hdc, 1350, 650);
            LineTo(hdc, 1350, 750);
            LineTo(hdc, 1250, 750);
            LineTo(hdc, 1250, 650);
            MoveToEx(hdc, 1300, 650, NULL);
            LineTo(hdc, 1300, 750);
            MoveToEx(hdc, 1250, 700, NULL);
            LineTo(hdc, 1350, 700);
            //Второй этаж
            //Дверь
            MoveToEx(hdc, 1450, 250, NULL);
            LineTo(hdc, 1550, 250);
            LineTo(hdc, 1550, 400);
            LineTo(hdc, 1450, 400);
            LineTo(hdc, 1450, 250);
            //Пр. окно
            MoveToEx(hdc, 1600, 275, NULL);
            LineTo(hdc, 1600, 325);
            LineTo(hdc, 1650, 325);
            LineTo(hdc, 1650, 275);
            LineTo(hdc, 1600, 275);
            MoveToEx(hdc, 1625, 275, NULL);
            LineTo(hdc, 1625, 325);
            MoveToEx(hdc, 1600, 300, NULL);
            LineTo(hdc, 1650, 300);
            //Л. окно
            MoveToEx(hdc, 1350, 275, NULL);
            LineTo(hdc, 1400, 275);
            LineTo(hdc, 1400, 325);
            LineTo(hdc, 1350, 325);
            LineTo(hdc, 1350, 275);
            MoveToEx(hdc, 1375, 275, NULL);
            LineTo(hdc, 1375, 325);
            MoveToEx(hdc, 1350, 300, NULL);
            LineTo(hdc, 1400, 300);
            //Верхнее окно
            MoveToEx(hdc, 1475, 175, NULL);
            LineTo(hdc, 1525, 175);
            LineTo(hdc, 1525, 225);
            LineTo(hdc, 1475, 225);
            LineTo(hdc, 1475, 175);
            MoveToEx(hdc, 1500, 175, NULL);
            LineTo(hdc, 1500, 225);
            MoveToEx(hdc, 1475, 200, NULL);
            LineTo(hdc, 1525, 200);



            //ЛАБОРАТОРНАЯ РАБОТА №7
            //Задача 1
            int x1 = 800, y1 = 600;
            int x2 = 900, y2 = 700;
            hPen = CreatePen(PS_SOLID, 2, RGB(139, 0, 255));
            SelectObject(hdc, hPen);
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 5;
            } while (x1 <= 1000);

            //Задача 2 и сразу 3
            x1 = 0, y1 = 250;
            x2 = 100, y2 = 250;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 5;
                y1 -= 10;
            } while (x1 <= 100);

            x1 = 100;
            y1 = 50;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 5;
                y1 += 10;
            } while (x1 <= 200);

            //Задача 4,1
            hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            SelectObject(hdc, hPen);
            x1 = 150, y1 = 0;
            x2 = 150, y2 = 100;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 5;
                x2 += 5;
            } while (x1 <= 450);

            //Задача 5
            hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
            SelectObject(hdc, hPen);
            x1 = 0, y1 = 900;
            x2 = 5, y2 = 890;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 3;
                x2 += 3;
            } while (x1 <= 1920);
            //Солнце
            HBRUSH hBrush;
            hBrush = CreateSolidBrush(RGB(255, 255, 0));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 1820, -100, 2020, 100);
            
            //Лучи
            x1 = 1670, y1 = 0, x2 = 1920, y2 = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 10;
                y1 += 10;
            } while (x1 <= 1920);

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
