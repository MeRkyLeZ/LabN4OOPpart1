#include "MyForm.h"
#include <Windows.h>
#include <iostream>

using namespace LabN4OOPpart1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}
