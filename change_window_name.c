#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief Function to retrieve and change the name of file in a subdirectory. It does that only if the window is visible.
 * @param ChildHandle
 * @param lPar
 * @return Boolean value.
 */
BOOL CALLBACK EnumChild(HWND ChildHandle, LPARAM lPar)
{
    int WinLen;
    char *WinText;

    // Get the length of a window's title.
    if (!(WinLen = GetWindowTextLengthA(ChildHandle)))
        return 1;

    // Checking to see the windos is visible.
    if (!(IsWindowVisible(ChildHandle)))
        return 1;

    // Printing the length of the window.
    printf("\t| winlen: %d\n", WinLen++);

    // Allocating memory for the window.
    WinText = malloc(WinLen);

    //  Getting the title of the window.
    GetWindowText(ChildHandle, WinText, WinLen);

    // Printing the title of the window.
    printf("\t| text: %s\n\n", WinText);

    // Changing every child window's name:
    SetWindowText(ChildHandle, "So crazy cool :)");

    // Releasing the memory ressources.
    free(WinText);
}

/**
 * @brief Function to retrieve and change the title of a window, checking for visibility before changing the name.
 * @param WinHandle
 * @param lPar
 * @return
 */
BOOL CALLBACK EnWinProc(HWND WinHandle, LPARAM lPar)
{
    int WinLen;
    char *WinText;

    // Obtaining the length the windows title.
    if (!(WinLen = GetWindowTextLengthA(WinHandle)))
        return 1;

    // Checking to see if the windows is visible or not.
    if (!(IsWindowVisible(WinHandle)))
        return 1;

    // Printing the length of the windows title.
    printf("winlen: %d\n", WinLen++);

    // Allocating memory for the windows title.
    WinText = malloc(WinLen);

    // Get the windows title.
    GetWindowText(WinHandle, WinText, WinLen);

    // Printing the title of the windows.
    printf("text: %s\n\n", WinText);

    // Changing the title of every window with [So Cool Dud :) ]
    SetWindowText(WinHandle, "So Cool Dud :)");

    // Finding every child window.
    EnumChildWindows(WinHandle, &EnumChild, 0);

    // Freeing memory.
    free(WinText);
}

int main()
{
    // // Get a list of all window open currently in the system.
    // EnumWindows(&EnWinProc, 0);

    // // Pause the system before returning.
    // system("pause");

    while (1)
    {
        EnumWindows(&EnWinProc, 0);
        Sleep(500);
    }

    return 0;
}