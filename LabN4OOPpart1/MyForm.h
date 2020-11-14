#pragma once
#include <cmath>
#include "Repository.h"
#include "CCircle.h"

namespace LabN4OOPpart1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Repository repos(10);	// ’ранилище объектов
	const int D = 100;	// ƒиаметр круга

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
	private: int GetDistance(int x0, int x, int y0, int y) {
		return (pow((x0 - x), 2) + pow((y0 - y), 2));
	}
	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		int check = 0;
		int selected, x, y;
		if ((Control::ModifierKeys == Keys::Control)) {
			for (int i = 0; i < repos.getSize(); ++i) {
				x = this->PointToClient(Cursor->Position).X;
				y = this->PointToClient(Cursor->Position).Y;
				if (!repos.isNull(i)) {
					if (GetDistance(repos.getObject(i).getX(), x, repos.getObject(i).getY(), y) <= pow(D / 2, 2)) {
						if (repos.getObject(i).getSelected() == false)
							check = 1;
						else
							check = 2;
						selected = i;
					}
				}
				if (check > 0) break;
			}
			switch (check) {
			case 1:
				repos.getObject(selected).setSelected(true);
				break;
			case 2:
				repos.getObject(selected).setSelected(false);
				break;
			}
		}
		else {
			for (int i = 0; i < repos.getSize(); ++i) {
				x = this->PointToClient(Cursor->Position).X;
				y = this->PointToClient(Cursor->Position).Y;
				if (!repos.isNull(i)) {
					if (GetDistance(repos.getObject(i).getX(), x, repos.getObject(i).getY(), y) <= pow(D / 2, 2)) {
						check = 1;
						selected = i;
					}
				}
				if (check > 0) break;
			}
			switch (check) {
			case 0:
				for (int i = 0; i < repos.getSize(); ++i) {
					if (!repos.isNull(i))
						repos.getObject(i).setSelected(false);
				}
				repos.addObject(new CCircle(x, y, D / 2));
				break;
			case 1:
				for (int i = 0; i < repos.getSize(); ++i) {
					if (!repos.isNull(i))
						repos.getObject(i).setSelected(false);
				}
				repos.getObject(selected).setSelected(true);
				break;
			}
		}
		MyForm::Refresh();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Black);
		Brush^ brush = gcnew SolidBrush(Color::FromArgb(0, 0, 0));
		for (int i = 0; i < repos.getSize(); ++i) {
			if (!repos.isNull(i)) {
				if (repos.getObject(i).getSelected() == false)
					e->Graphics->DrawEllipse(pen, repos.getObject(i).getX() - repos.getObject(i).getR(), repos.getObject(i).getY() - repos.getObject(i).getR(), repos.getObject(i).getR() * 2, repos.getObject(i).getR() * 2);
				else
					e->Graphics->FillEllipse(brush, repos.getObject(i).getX() - repos.getObject(i).getR(), repos.getObject(i).getY() - repos.getObject(i).getR(), repos.getObject(i).getR() * 2, repos.getObject(i).getR() * 2);
			}
		}
		delete pen;
		delete brush;
	}
	};
}
