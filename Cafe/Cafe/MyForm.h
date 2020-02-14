#pragma once

namespace Cafe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Panel^ main_panel1;

	private: System::Windows::Forms::Panel^ sub_panel1;

	private: System::Windows::Forms::Button^ sub_button1_2;

	private: System::Windows::Forms::Button^ sub_button1_1;
	private: System::Windows::Forms::Button^ main_button2;
	private: System::Windows::Forms::Button^ main_button1;
	private: System::Windows::Forms::Panel^ sub_panel2;

	private: System::Windows::Forms::Button^ sub_button2_1;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->main_panel1 = (gcnew System::Windows::Forms::Panel());
			this->main_button2 = (gcnew System::Windows::Forms::Button());
			this->main_button1 = (gcnew System::Windows::Forms::Button());
			this->sub_panel1 = (gcnew System::Windows::Forms::Panel());
			this->sub_button1_2 = (gcnew System::Windows::Forms::Button());
			this->sub_button1_1 = (gcnew System::Windows::Forms::Button());
			this->sub_panel2 = (gcnew System::Windows::Forms::Panel());
			this->sub_button2_1 = (gcnew System::Windows::Forms::Button());
			this->main_panel1->SuspendLayout();
			this->sub_panel1->SuspendLayout();
			this->sub_panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick_1);
			// 
			// main_panel1
			// 
			this->main_panel1->Controls->Add(this->main_button2);
			this->main_panel1->Controls->Add(this->main_button1);
			this->main_panel1->Location = System::Drawing::Point(12, 12);
			this->main_panel1->Name = L"main_panel1";
			this->main_panel1->Size = System::Drawing::Size(107, 300);
			this->main_panel1->TabIndex = 0;
			// 
			// main_button2
			// 
			this->main_button2->Location = System::Drawing::Point(0, 44);
			this->main_button2->Name = L"main_button2";
			this->main_button2->Size = System::Drawing::Size(107, 48);
			this->main_button2->TabIndex = 3;
			this->main_button2->Text = L"main_button2";
			this->main_button2->UseVisualStyleBackColor = true;
			this->main_button2->Click += gcnew System::EventHandler(this, &MyForm::main_button2_Click);
			// 
			// main_button1
			// 
			this->main_button1->BackColor = System::Drawing::Color::Yellow;
			this->main_button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->main_button1->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->main_button1->FlatAppearance->BorderSize = 0;
			this->main_button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->main_button1->Location = System::Drawing::Point(0, 0);
			this->main_button1->Margin = System::Windows::Forms::Padding(0);
			this->main_button1->Name = L"main_button1";
			this->main_button1->Size = System::Drawing::Size(107, 48);
			this->main_button1->TabIndex = 2;
			this->main_button1->Text = L"main_button1";
			this->main_button1->UseVisualStyleBackColor = false;
			this->main_button1->Click += gcnew System::EventHandler(this, &MyForm::main_button1_Click_1);
			// 
			// sub_panel1
			// 
			this->sub_panel1->Controls->Add(this->sub_button1_2);
			this->sub_panel1->Controls->Add(this->sub_button1_1);
			this->sub_panel1->Location = System::Drawing::Point(125, 12);
			this->sub_panel1->Name = L"sub_panel1";
			this->sub_panel1->Size = System::Drawing::Size(127, 0);
			this->sub_panel1->TabIndex = 1;
			// 
			// sub_button1_2
			// 
			this->sub_button1_2->Location = System::Drawing::Point(0, 44);
			this->sub_button1_2->Name = L"sub_button1_2";
			this->sub_button1_2->Size = System::Drawing::Size(127, 45);
			this->sub_button1_2->TabIndex = 1;
			this->sub_button1_2->Text = L"sub_button1_2";
			this->sub_button1_2->UseVisualStyleBackColor = true;
			// 
			// sub_button1_1
			// 
			this->sub_button1_1->Location = System::Drawing::Point(0, 0);
			this->sub_button1_1->Name = L"sub_button1_1";
			this->sub_button1_1->Size = System::Drawing::Size(127, 48);
			this->sub_button1_1->TabIndex = 0;
			this->sub_button1_1->Text = L"sub_button1_1";
			this->sub_button1_1->UseVisualStyleBackColor = true;
			// 
			// sub_panel2
			// 
			this->sub_panel2->Controls->Add(this->sub_button2_1);
			this->sub_panel2->Location = System::Drawing::Point(125, 12);
			this->sub_panel2->Name = L"sub_panel2";
			this->sub_panel2->Size = System::Drawing::Size(127, 0);
			this->sub_panel2->TabIndex = 2;
			// 
			// sub_button2_1
			// 
			this->sub_button2_1->Location = System::Drawing::Point(0, 0);
			this->sub_button2_1->Name = L"sub_button2_1";
			this->sub_button2_1->Size = System::Drawing::Size(127, 38);
			this->sub_button2_1->TabIndex = 0;
			this->sub_button2_1->Text = L"sub_button2_1";
			this->sub_button2_1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(891, 336);
			this->Controls->Add(this->sub_panel2);
			this->Controls->Add(this->sub_panel1);
			this->Controls->Add(this->main_panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->main_panel1->ResumeLayout(false);
			this->sub_panel1->ResumeLayout(false);
			this->sub_panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void main_button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
		if (sub_panel2->Height == 301) {
			sub_panel2->Height = 0;
		}

		if (sub_panel1->Height == 301) {
			sub_panel1->Height = 0;
			timer1->Enabled = false;
		}
	}

	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		sub_panel1->Height = 301;
		timer1->Stop();
	}

	private: System::Void main_button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer2->Start();
		if (sub_panel1->Height == 301) {
			sub_panel1->Height = 0;
		}

		if (sub_panel2->Height == 301) {
			sub_panel2->Height = 0;
			timer2->Enabled = false;
		}
	}

	private: System::Void timer2_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		sub_panel2->Height = 301;
		timer2->Stop();
	}
};
}
