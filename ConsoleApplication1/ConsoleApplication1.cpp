#include "atlimage.h"
#include <iostream>
#include <Windows.h>
#define sizen 50
using namespace std;
void out(int n) {
	cout.width(2);
	switch (n)
	{
	case 0: {cout << " "; break; }
	case 1: {cout << "."; break; }
	case 2: {cout << ","; break; }
	case 3: {cout << ":"; break; }
	case 4: {cout << ";"; break; }
	case 5: {cout << "+"; break; }
	case 6: {cout << "*"; break; }
	case 7: {cout << "?"; break; }
	case 8: {cout << "%"; break; }
	case 9: {cout << "S"; break; }
	case 10: {cout << "#"; break; }
	case 11: {cout << "@"; break; }
	default: {cout << " "; break; }
	}
}

int main(void) {
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	CImage im;
		const wchar_t* adress = L"C:\\abc\\visual studio\\символьные арты\\p1.png";
		im.Load((LPCTSTR)(adress));
		COLORREF PIXEL;
		for (int x = 0; x < im.GetHeight(); x += im.GetHeight() / sizen) {
			for (int y = 0; y < im.GetWidth(); y += im.GetWidth() / (im.GetWidth() / (im.GetHeight() / sizen))) {
				PIXEL = im.GetPixel(y, x);
				int y1 = 0.299 * GetRValue(PIXEL) + 0.587 * GetGValue(PIXEL) + 0.114 * GetBValue(PIXEL);
				out(y1 / 23);
			}
			cout << endl;
		}

	return 0;
}