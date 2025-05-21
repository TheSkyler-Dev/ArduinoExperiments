#include <iostream>
#include <string>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

int main() {
    // Method 1: Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    // Method 2: Enable Unicode console mode
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(consoleHandle, &consoleMode);
    SetConsoleMode(consoleHandle, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    
    // Method 3: Set _O_U16TEXT mode for Unicode output
    _setmode(_fileno(stdout), _O_U16TEXT);
    
    std::cout << "Unicode display demonstration program" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    
    // Reset to normal text mode for regular output
    _setmode(_fileno(stdout), _O_TEXT);
    
    std::cout << "\nMethod 1: Using UTF-8 code page (may require console font change)" << std::endl;
    // Print using UTF-8 encoded string
    std::cout << "Full block: \u2588\u2588\u2588" << std::endl;
    std::cout << "Other symbols: \u2591\u2592\u2593\u2588" << std::endl;
    
    std::cout << "\nMethod 2: Using cout with hex escape sequence" << std::endl;
    std::cout << "Full block: \xE2\x96\x88\xE2\x96\x88\xE2\x96\x88" << std::endl;
    
    std::cout << "\nMethod 3: Using wcout with wide character literals" << std::endl;
    // Switch to wide character mode
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Full block: \u2588\u2588\u2588" << std::endl;
    std::wcout << L"Other symbols: \u2591\u2592\u2593\u2588" << std::endl;
    
    // Return to normal text mode
    _setmode(_fileno(stdout), _O_TEXT);
    
    std::cout << "\nNotes for correct display:" << std::endl;
    std::cout << "1. Make sure your console is using a font that supports Unicode (like Consolas)" << std::endl;
    std::cout << "2. In Windows Terminal/PowerShell, right-click title bar > Properties > Font" << std::endl;
    std::cout << "3. You may need to change console settings: chcp 65001 (for UTF-8)" << std::endl;
    
    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();
    return 0;
}