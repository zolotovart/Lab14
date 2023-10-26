// Lab14.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab14.h"
#include "Images.h"

#define MAX_LOADSTRING 100


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int image1_x = 50;
int image1_y = 50;
int type = 0;
int tt = 0;
int image1_n = 1;
int image1_m = 1;
unsigned char r, g;

void Pict6(HDC hdc) {
    if (type == 0) Image2(hdc, image1_x, image1_y, RGB(r, g, 0));
    if (type == 1) Image3(hdc, image1_x, image1_y, RGB(r, g, 0));
    if (type == 2) Image6(hdc, image1_x, image1_y, RGB(r, g, 0));
    if (type == 3) drawTruck(hdc, image1_x, image1_y, RGB(r, g, 0));
    if (type == 4) gg(hdc, image1_x, image1_y, RGB(r, g, 0));
}
void PictureVH(HDC hdc) {
    int x, y, i, j;
    y = image1_y;
    i = 0;
    do {
        x = image1_x;
        j = 0;
        do {
            if (type == 0) Image2(hdc, x, y, RGB(r, g, 0));
            if (type == 1) Image3(hdc, x, y, RGB(r, g, 0));
            if (type == 2) Image6(hdc, x, y, RGB(r, g, 0));
            x += 50;
            j++;
        } while (j < image1_m);
        y += 70;
        i++;
    } while (i < image1_n);
}
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
    LoadStringW(hInstance, IDC_LAB14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB14));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB14);
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
    case WM_LBUTTONDOWN:
    {
        WORD xPos, yPos;

        // Сохраняем координаты курсора мыши
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);


        image1_x = xPos;
        image1_y = yPos;
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //Rectangle(hdc, image1_x - 10, image1_y - 10, image1_x + 10, image1_y + 10);
            //Image2(hdc, image1_x, image1_y, RGB(0,255,0));
            if (type == 0) Image2(hdc, image1_x, image1_y, RGB(0, 255, 0));
            if (type == 1) Image3(hdc, image1_x, image1_y, RGB(0, 255, 0));
            if (type == 2) Image6(hdc, image1_x, image1_y, RGB(0, 255, 0));
            if (type == 3) drawTruck(hdc, image1_x, image1_y, RGB(0, 255, 0));
            if (type == 4) gg(hdc, image1_x, image1_y, RGB(245, 245, 220));

            PictureVH(hdc);
            Pict6(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT: // стрелка ВЛЕВО
            image1_x -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT: // стрелка ВПРАВО
            image1_x += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN: // стрелка ВНИЗ
            image1_y += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP: // стрелка ВВЕРХ
            image1_y -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_SPACE:
            type++;
            if (type > 2) type = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case   0x49: // I
            image1_m -= 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case   0x4f: // O
            image1_m += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case    0x55: // U
            image1_n -= 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case    0x4e: // N
            image1_n += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_SHIFT:
            r += 36;
            g += 51;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case    0x41: // A картинки налево
            if (type<4) type++;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case    0x44: // D картинки направо
            if (type>0) type--;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
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
