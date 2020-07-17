#include <Windows.h>

#include "GameSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow) {

	GameSystem gSystem;

	if (gSystem.Init()) {
		gSystem.Main();
	}

	gSystem.Final();

	return 0;
}