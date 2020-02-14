#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Cafe::MyForm form;
    Application::Run(% form);
    return 0;
}

