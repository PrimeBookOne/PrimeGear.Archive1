
#undef UNICODE

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#elif _WIN32_WINNT < 0x0600
    #undef _WIN32_WINNT
    #define _WIN32_WINNT 0x0600
#endif
#define MAX_IPV4_ADDRESS_LENGTH 16

/* #include <io.h> */
#include <cstdint>
/* #include <GL/glut.h> */
#include <iomanip>
#include <string>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <sys/types.h>
#include <limits>
#include <fstream>
#include <pthread.h>
/* link with Ws2_32.lib */
#pragma comment (lib, "Ws2_32.lib")
#include <Ws2tcpip.h>
#ifndef __linux__ /*Excludes Anything That Isn't Emscriptem Compatible*/
#ifndef __EMSCRIPTEN__ /*Excludes Anything That Isn't Emscriptem Compatible*/
#include <winsock2.h>  /* UNIX ONLY #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>*/
#include <winsock.h>  /* #include <netdb.h> */
/* #include "../application/vulkan/vulkan-application.hpp" */
/* #include "../application/vulkan/vulkan-common.hpp" */
#include <quadmath.h>
#include <Ws2tcpip.h>
#include <immintrin.h>
#endif
#endif
#include <d3d9.h>
#include <stdio.h>
#include <process.h>
#include <wtypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <bits/stdc++.h>
#include <sched.h>
#include <unistd.h>
#include <winbase.h>
#include <chrono>
#include <dos.h>

#include <filesystem>
#include <algorithm>
#include <conio.h>
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <omp.h>
#include <cuda_runtime_api.h>
#include <Windows.h>
#include <winternl.h>
#include <winsock2.h> 
#include <ws2tcpip.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <TlHelp32.h>
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "ws2_32.lib")
#include <condition_variable>
#include <Iptypes.h>
#include <Mstcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#include <atomic>



#include <wbemidl.h>
#include <comdef.h>
#include <tuple>
#pragma comment(lib, "wbemuuid.lib")

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <curl/curl.h>
#include <base64_default_rfc4648.hpp>
#include <sstream>
#include <cstdio>
#include <memory>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>

#define ID_CLOSE_ALL 9001
#include <windows.h>
#include <cmath>



using namespace std;













































































































int diameter; // current window diameter

int argc;
LPWSTR* argvW = CommandLineToArgvW(GetCommandLineW(), &argc);
const char CLASS_NAME[] = "CircularWindow";
































































class string128Class
{
private:
    __int128 number;
    std::string result;

    void convert() {
        if (number == 0) {
            result = "0";
            return;
        }

        bool isNegative = false;

        if (number < 0) {
            isNegative = true;
            number = -number;
        }

        while (number > 0) {
            int digit = number % 10;
            result.insert(result.begin(), static_cast<char>('0' + digit));
            number /= 10;
        }

        if (isNegative)
            result.insert(result.begin(), '-');
    }

public:
    string128Class(__int128 num) : number(num) {
        convert();
    }


    std::string getString() const {
        return result;
    }
};



class string128ClassComma

{
private:
    __int128 number;
    std::string result;

    void convert() {
        if (number == 0) {
            result = "0";
            return;
        }

        bool isNegative = false;

        if (number < 0) {
            isNegative = true;
            number = -number;
        }

        int digitCount = 0;

        while (number > 0) {
            int digit = number % 10;
            result.insert(result.begin(), static_cast<char>('0' + digit));
            number /= 10;

            digitCount++;

            // Add a comma every three digits (except at the beginning)
            if (digitCount % 3 == 0 && number > 0) {
                result.insert(result.begin(), ',');
            }
        }

        if (isNegative)
            result.insert(result.begin(), '-');
    }

public:
    string128ClassComma(__int128 num) : number(num) {
        convert();
    }

    std::string getString() const {
        return result;
    }
};



class StringTo128Class {
public:
    // Function to convert a string to __int128
    static __int128 stringToInt128(const std::string& str) {
        if (str.empty())
            throw std::invalid_argument("Empty string");

        int i = 0;
        int sign = 1;

        if (str[i] == '-') {
            sign = -1;
            i++;
        }

        __int128 result = 0;
        for (; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (str[i] - '0');
            } else {
                throw std::invalid_argument("Invalid character in the input string");
            }
        }

        return result * sign;
    }
};

























std::vector<std::string> splitCommandLine(const std::string& cmdLine) {
    std::vector<std::string> args;
    std::istringstream stream(cmdLine);
    std::string token;
    while (stream >> std::quoted(token)) {  // supports quoted strings like "value with spaces"
        args.push_back(token);
    }
    return args;
}


void runGuiThread(HINSTANCE hInstance, int nCmdShow, std::string hostIp, std::string label) {
    const char* className = "ZetaWindowClass";
    WNDCLASSA wc = {};
    wc.lpfnWndProc = [](HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT {
        switch (msg) {
            case WM_APP + 1: {
                std::string* str = reinterpret_cast<std::string*>(lParam);
                MessageBoxA(hwnd, str->c_str(), "IPC Message", MB_OK);
                delete str;
                return 0;
            }
        }
        return DefWindowProcA(hwnd, msg, wParam, lParam);
    };
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    RegisterClassA(&wc);
    HWND hwnd = CreateWindowExA(0, className, label.c_str(), WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
                                nullptr, nullptr, hInstance, nullptr);
    if (!hwnd) return;
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // store globally or accessible location for PostMessage
    g_hwnd = hwnd;
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int screenWidth;
    static HFONT hFont = nullptr;
    switch (uMsg) {
    case WM_CREATE: {
        screenWidth = GetSystemMetrics(SM_CXSCREEN);
        diameter = screenWidth / 4;
        HRGN hRgn = CreateEllipticRgn(0, 0, diameter, diameter);
        SetWindowRgn(hwnd, hRgn, TRUE);
        return 0;
    }
    case WM_MOUSEWHEEL: {
        int delta = GET_WHEEL_DELTA_WPARAM(wParam);
        diameter += (delta > 0 ? 20 : -20);
        if (diameter < 100) diameter = 100;
        if (diameter > screenWidth) diameter = screenWidth;
        SetWindowPos(hwnd, nullptr, 0, 0, diameter, diameter,
                     SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        HRGN hRgn = CreateEllipticRgn(0, 0, diameter, diameter);
        SetWindowRgn(hwnd, hRgn, TRUE);
        InvalidateRect(hwnd, nullptr, TRUE);
        return 0;
    }
    case WM_LBUTTONDOWN:
        ReleaseCapture();
        SendMessage(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
        return 0;
    case WM_SETCURSOR:
        SetCursor(LoadCursor(nullptr, IDC_ARROW));
        return TRUE;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(0, 0, 0));
        const int rows = 11, cols = 11;
        int cellWidth = clientRect.right / cols;
        int cellHeight = clientRect.bottom / rows;
        int number = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                RECT cellRect = {
                    col * cellWidth,
                    row * cellHeight,
                    (col + 1) * cellWidth,
                    (row + 1) * cellHeight
                };
                int fontSize = (diameter / ((number % 2 == 0) ? 14 : 20));
                HFONT cellFont = CreateFontA(
                    fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                    DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                    CLEARTYPE_QUALITY, VARIABLE_PITCH, "Segoe UI");
                HFONT oldFont = (HFONT)SelectObject(hdc, cellFont);
                std::string text = std::to_string(number);
                DrawTextA(hdc, text.c_str(), -1, &cellRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                SelectObject(hdc, oldFont);
                DeleteObject(cellFont);
                if (++number > 120) break;
            }
            if (number > 120) break;
        }
        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_RBUTTONUP: {
        HMENU hPopup = CreatePopupMenu();
        AppendMenu(hPopup, MF_STRING, ID_CLOSE_ALL, "Close All");
        POINT pt;
        GetCursorPos(&pt);
        TrackPopupMenu(hPopup, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hwnd, nullptr);
        DestroyMenu(hPopup);
        return 0;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == ID_CLOSE_ALL) {
            DestroyWindow(hwnd);
            return 0;
        }
        break;
    case WM_DESTROY:
        if (hFont) DeleteObject(hFont);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    HANDLE mutexHandle = CreateMutexA(NULL, TRUE, "ZetaConduitSingleInstance");
    if (GetLastError() == ERROR_ALREADY_EXISTS) return 0;
    std::string fullCmdLine = GetCommandLineA();
    std::vector<std::string> argsVec = splitCommandLine(fullCmdLine);
    std::vector<char*> argv;
    for (auto& s : argsVec) argv.push_back(&s[0]);
    int argc = static_cast<int>(argv.size());
    std::string hostIp = "null", optionMenueInput = "null", optionFlagInput = "null";
    std::string networkAssignment = "default", optionComputeInput = "default";
    std::string computeMethod = "null";
    bool createHost = true, singleCore = false, optionO = false;
    int optionCores = 0, hostPort = 0;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o") optionO = true;
        else if (arg == "-c" && i + 1 < argc) {
            std::istringstream(argv[++i]) >> optionCores;
        } else if (arg == "-m" && i + 1 < argc) optionMenueInput = argv[++i];
        else if (arg == "-ip" && i + 1 < argc) hostIp = argv[++i];
        else if (arg == "-p" && i + 1 < argc) {
            std::istringstream(argv[++i]) >> hostPort;
        } else if (arg == "-f" && i + 1 < argc) optionFlagInput = argv[++i];
        else if (arg == "-x" && i + 1 < argc) optionComputeInput = argv[++i];
        else if (arg == "-w" && i + 1 < argc) networkAssignment = argv[++i];
        else std::cerr << "Invalid argument: " << arg << std::endl;
    }
    createHost = (networkAssignment != "g");
//    system("cls");
    std::cout << "Run Commands: " << std::endl;
    if (hostIp == "null" && hostPort && networkAssignment == "g")
        std::cout << "Guest connect to Host Port: " << hostPort << std::endl;
    if (hostIp != "null" && hostPort && networkAssignment == "g")
        std::cout << "Guest connect to Host IP & Port: " << hostIp << ":" << hostPort << std::endl;
    if (hostPort && hostIp != "null" && networkAssignment == "h")
        std::cout << "Host Assigned IP & Port: " << hostIp << ":" << hostPort << std::endl;
    if (hostPort && hostIp == "null" && networkAssignment == "h")
        std::cout << "Host Assigned Port: " << hostPort << std::endl;
    if (optionCores == 1) singleCore = true;
    if (optionCores)
        std::cout << "CPU Core Assignment: " << optionCores
                  << (singleCore ? "  SINGLE Core " : "") << std::endl;
    if (optionMenueInput != "null")
        std::cout << "Menue Assignment: " << optionMenueInput << std::endl;
    if (optionFlagInput != "null")
        std::cout << "Flag Assignment: " << optionFlagInput << std::endl;
    optionComputeInput = "Gear";
    if (optionComputeInput != "default")
        std::cout << "Compute Assignment: " << optionComputeInput << std::endl;
    else
        computeMethod = optionComputeInput;
//  if (createHost) AttachConsoleWindow();
    const char* className = "ZetaWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClassA(&wc);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    diameter = screenWidth / 4;
    HWND hwnd = CreateWindowExA(
        WS_EX_LAYERED, className, "Circular Window", WS_POPUP,
        (screenWidth - diameter) / 2, (GetSystemMetrics(SM_CYSCREEN) - diameter) / 2,
        diameter, diameter, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd) return 0;
    SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
   
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}


void AttachConsoleWindow() {
    AllocConsole(); // Allocate a new console for this process
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout); // Redirect stdout
    freopen_s(&fp, "CONOUT$", "w", stderr); // Redirect stderr
    freopen_s(&fp, "CONIN$",  "r", stdin);  // Redirect stdin
    SetConsoleTitle("Debug Console");
}

