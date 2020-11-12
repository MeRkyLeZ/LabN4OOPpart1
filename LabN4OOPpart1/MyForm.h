#pragma once
#include "Repository.h"
#include "CCircle.h"
#include <list>

namespace LabN4OOPpart1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Repository repos(10);	// ’ранилище объектов
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		bool check = false;
		int R = 100;
		for (int i = 0; i < repos.getCount(); ++i) {
			int x = this->PointToClient(Cursor->Position).X - R / 2;
			int y = this->PointToClient(Cursor->Position).Y - R / 2;
			if (!repos.isNull(i))
				if (abs(repos.getObject(i).getX() - x) <= R && abs(repos.getObject(i).getY() - y) <= R) {
					check = true;
					break;
				}
		}
		if (!check) {
			repos.addObject(new CCircle(this->PointToClient(Cursor->Position).X - R / 2, this->PointToClient(Cursor->Position).Y - R / 2, R));
		}
		MyForm::Refresh();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Black);
		for (int i = 0; i < repos.getCount(); ++i) {
			e->Graphics->DrawEllipse(pen, repos.getObject(i).getX(), repos.getObject(i).getY(), repos.getObject(i).getR(), repos.getObject(i).getR());
		}
		delete pen;
	}
	};
}
