#pragma once
#include <msclr\marshal_cppstd.h>
#include "../../mp2-lab6-table/TSortTable.h"
#include "../../mp2-lab6-table/TArrayHash.h"
#include "../../mp2-lab6-table/TListHash.h"
#include "../../mp2-lab6-table/TAVLTree.h"

TScanTable scantab;
TSortTable sorttab;
TArrayHash arrhashtab(500);
TListHash listhashtab(500);
TTreeTable treetab;
TAVLTree avltreetab;

namespace Forma1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		int NumRec; // число записей
		int KeyRange; // диапазон ключей

	private: System::Windows::Forms::Button^ buttonCreate;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonFind;
	private: System::Windows::Forms::Button^ buttonDel;
	private: System::Windows::Forms::Label^ labelOpStatus;
	private: System::Windows::Forms::Label^ labelFind;
	private: System::Windows::Forms::TextBox^ textBoxFind;
	private: System::Windows::Forms::Button^ buttonRenew;
	private: System::Windows::Forms::Button^ buttonIns;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gr = CreateGraphics();

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
	private: System::Windows::Forms::RadioButton^ radioButtonScanTab;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButtonSortTab;
	private: System::Windows::Forms::RadioButton^ radioButtonHashArr;
	private: System::Windows::Forms::RadioButton^ radioButtonHashList;
	private: System::Windows::Forms::RadioButton^ radioButtonTreeTab;
	private: System::Windows::Forms::RadioButton^ radioButtonAVLTab;

	private: System::Windows::Forms::Label^ labelNumRec;
	private: System::Windows::Forms::Label^ labelKeyRange;
	private: System::Windows::Forms::Label^ labelRecKey;
	private: System::Windows::Forms::Label^ labelRecVal;
	private: System::Windows::Forms::Label^ labelRec;
	private: System::Windows::Forms::Label^ labelConfig;
	private: System::Windows::Forms::Label^ labelEff;
	private: System::Windows::Forms::Button^ buttonExit;


	private: System::Windows::Forms::TextBox^ textBoxKey;
	private: System::Windows::Forms::TextBox^ textBoxVal;
	private: System::Windows::Forms::TextBox^ textBoxKeyRange;
	private: System::Windows::Forms::TextBox^ textBoxNumRec;
	private: System::Windows::Forms::TextBox^ textBoxEff;
	private: System::Windows::Forms::GroupBox^ groupBoxTabType;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radioButtonScanTab = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonSortTab = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHashArr = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHashList = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTreeTab = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAVLTab = (gcnew System::Windows::Forms::RadioButton());
			this->labelNumRec = (gcnew System::Windows::Forms::Label());
			this->labelKeyRange = (gcnew System::Windows::Forms::Label());
			this->labelRecKey = (gcnew System::Windows::Forms::Label());
			this->labelRecVal = (gcnew System::Windows::Forms::Label());
			this->labelRec = (gcnew System::Windows::Forms::Label());
			this->labelConfig = (gcnew System::Windows::Forms::Label());
			this->labelEff = (gcnew System::Windows::Forms::Label());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxVal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKeyRange = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNumRec = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEff = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxTabType = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCreate = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->buttonDel = (gcnew System::Windows::Forms::Button());
			this->buttonIns = (gcnew System::Windows::Forms::Button());
			this->labelOpStatus = (gcnew System::Windows::Forms::Label());
			this->labelFind = (gcnew System::Windows::Forms::Label());
			this->textBoxFind = (gcnew System::Windows::Forms::TextBox());
			this->buttonRenew = (gcnew System::Windows::Forms::Button());
			this->groupBoxTabType->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButtonScanTab
			// 
			this->radioButtonScanTab->AutoSize = true;
			this->radioButtonScanTab->Location = System::Drawing::Point(20, 33);
			this->radioButtonScanTab->Name = L"radioButtonScanTab";
			this->radioButtonScanTab->Size = System::Drawing::Size(87, 19);
			this->radioButtonScanTab->TabIndex = 0;
			this->radioButtonScanTab->TabStop = true;
			this->radioButtonScanTab->Text = L"Scan Table";
			this->radioButtonScanTab->UseVisualStyleBackColor = true;
			// 
			// radioButtonSortTab
			// 
			this->radioButtonSortTab->AutoSize = true;
			this->radioButtonSortTab->Location = System::Drawing::Point(20, 58);
			this->radioButtonSortTab->Name = L"radioButtonSortTab";
			this->radioButtonSortTab->Size = System::Drawing::Size(81, 19);
			this->radioButtonSortTab->TabIndex = 1;
			this->radioButtonSortTab->TabStop = true;
			this->radioButtonSortTab->Text = L"Sort Table";
			this->radioButtonSortTab->UseVisualStyleBackColor = true;
			// 
			// radioButtonHashArr
			// 
			this->radioButtonHashArr->AutoSize = true;
			this->radioButtonHashArr->Location = System::Drawing::Point(20, 83);
			this->radioButtonHashArr->Name = L"radioButtonHashArr";
			this->radioButtonHashArr->Size = System::Drawing::Size(135, 19);
			this->radioButtonHashArr->TabIndex = 2;
			this->radioButtonHashArr->TabStop = true;
			this->radioButtonHashArr->Text = L"Hash Table on Array";
			this->radioButtonHashArr->UseVisualStyleBackColor = true;
			// 
			// radioButtonHashList
			// 
			this->radioButtonHashList->AutoSize = true;
			this->radioButtonHashList->Location = System::Drawing::Point(20, 108);
			this->radioButtonHashList->Name = L"radioButtonHashList";
			this->radioButtonHashList->Size = System::Drawing::Size(127, 19);
			this->radioButtonHashList->TabIndex = 3;
			this->radioButtonHashList->TabStop = true;
			this->radioButtonHashList->Text = L"Hash Table on List";
			this->radioButtonHashList->UseVisualStyleBackColor = true;
			// 
			// radioButtonTreeTab
			// 
			this->radioButtonTreeTab->AutoSize = true;
			this->radioButtonTreeTab->Location = System::Drawing::Point(20, 133);
			this->radioButtonTreeTab->Name = L"radioButtonTreeTab";
			this->radioButtonTreeTab->Size = System::Drawing::Size(84, 19);
			this->radioButtonTreeTab->TabIndex = 4;
			this->radioButtonTreeTab->TabStop = true;
			this->radioButtonTreeTab->Text = L"Tree Table";
			this->radioButtonTreeTab->UseVisualStyleBackColor = true;
			// 
			// radioButtonAVLTab
			// 
			this->radioButtonAVLTab->AutoSize = true;
			this->radioButtonAVLTab->Location = System::Drawing::Point(20, 158);
			this->radioButtonAVLTab->Name = L"radioButtonAVLTab";
			this->radioButtonAVLTab->Size = System::Drawing::Size(108, 19);
			this->radioButtonAVLTab->TabIndex = 5;
			this->radioButtonAVLTab->TabStop = true;
			this->radioButtonAVLTab->Text = L"AVL Tree Table";
			this->radioButtonAVLTab->UseVisualStyleBackColor = true;
			// 
			// labelNumRec
			// 
			this->labelNumRec->AutoSize = true;
			this->labelNumRec->Location = System::Drawing::Point(310, 79);
			this->labelNumRec->Name = L"labelNumRec";
			this->labelNumRec->Size = System::Drawing::Size(129, 15);
			this->labelNumRec->TabIndex = 7;
			this->labelNumRec->Text = L"Number of the records";
			// 
			// labelKeyRange
			// 
			this->labelKeyRange->AutoSize = true;
			this->labelKeyRange->Location = System::Drawing::Point(310, 116);
			this->labelKeyRange->Name = L"labelKeyRange";
			this->labelKeyRange->Size = System::Drawing::Size(62, 15);
			this->labelKeyRange->TabIndex = 8;
			this->labelKeyRange->Text = L"Key range";
			// 
			// labelRecKey
			// 
			this->labelRecKey->AutoSize = true;
			this->labelRecKey->Location = System::Drawing::Point(310, 276);
			this->labelRecKey->Name = L"labelRecKey";
			this->labelRecKey->Size = System::Drawing::Size(27, 15);
			this->labelRecKey->TabIndex = 9;
			this->labelRecKey->Text = L"Key";
			// 
			// labelRecVal
			// 
			this->labelRecVal->AutoSize = true;
			this->labelRecVal->Location = System::Drawing::Point(310, 317);
			this->labelRecVal->Name = L"labelRecVal";
			this->labelRecVal->Size = System::Drawing::Size(38, 15);
			this->labelRecVal->TabIndex = 10;
			this->labelRecVal->Text = L"Value";
			// 
			// labelRec
			// 
			this->labelRec->AutoSize = true;
			this->labelRec->Location = System::Drawing::Point(284, 234);
			this->labelRec->Name = L"labelRec";
			this->labelRec->Size = System::Drawing::Size(174, 15);
			this->labelRec->TabIndex = 11;
			this->labelRec->Text = L"Insert new record into the table";
			// 
			// labelConfig
			// 
			this->labelConfig->AutoSize = true;
			this->labelConfig->Location = System::Drawing::Point(284, 37);
			this->labelConfig->Name = L"labelConfig";
			this->labelConfig->Size = System::Drawing::Size(80, 15);
			this->labelConfig->TabIndex = 12;
			this->labelConfig->Text = L"Configuration";
			// 
			// labelEff
			// 
			this->labelEff->AutoSize = true;
			this->labelEff->Location = System::Drawing::Point(57, 265);
			this->labelEff->Name = L"labelEff";
			this->labelEff->Size = System::Drawing::Size(58, 15);
			this->labelEff->TabIndex = 13;
			this->labelEff->Text = L"Efficiency";
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(622, 295);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(75, 59);
			this->buttonExit->TabIndex = 14;
			this->buttonExit->Text = L"EXIT";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(460, 270);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 21);
			this->textBoxKey->TabIndex = 15;
			// 
			// textBoxVal
			// 
			this->textBoxVal->Location = System::Drawing::Point(460, 314);
			this->textBoxVal->Name = L"textBoxVal";
			this->textBoxVal->Size = System::Drawing::Size(100, 21);
			this->textBoxVal->TabIndex = 16;
			// 
			// textBoxKeyRange
			// 
			this->textBoxKeyRange->Location = System::Drawing::Point(460, 120);
			this->textBoxKeyRange->Name = L"textBoxKeyRange";
			this->textBoxKeyRange->Size = System::Drawing::Size(100, 21);
			this->textBoxKeyRange->TabIndex = 18;
			// 
			// textBoxNumRec
			// 
			this->textBoxNumRec->Location = System::Drawing::Point(460, 76);
			this->textBoxNumRec->Name = L"textBoxNumRec";
			this->textBoxNumRec->Size = System::Drawing::Size(100, 21);
			this->textBoxNumRec->TabIndex = 17;
			// 
			// textBoxEff
			// 
			this->textBoxEff->Enabled = false;
			this->textBoxEff->Location = System::Drawing::Point(141, 265);
			this->textBoxEff->Name = L"textBoxEff";
			this->textBoxEff->Size = System::Drawing::Size(100, 21);
			this->textBoxEff->TabIndex = 19;
			// 
			// groupBoxTabType
			// 
			this->groupBoxTabType->Controls->Add(this->radioButtonScanTab);
			this->groupBoxTabType->Controls->Add(this->radioButtonSortTab);
			this->groupBoxTabType->Controls->Add(this->radioButtonHashArr);
			this->groupBoxTabType->Controls->Add(this->radioButtonHashList);
			this->groupBoxTabType->Controls->Add(this->radioButtonTreeTab);
			this->groupBoxTabType->Controls->Add(this->radioButtonAVLTab);
			this->groupBoxTabType->Location = System::Drawing::Point(50, 35);
			this->groupBoxTabType->Name = L"groupBoxTabType";
			this->groupBoxTabType->Size = System::Drawing::Size(200, 201);
			this->groupBoxTabType->TabIndex = 20;
			this->groupBoxTabType->TabStop = false;
			this->groupBoxTabType->Text = L"Table type";
			// 
			// buttonCreate
			// 
			this->buttonCreate->Location = System::Drawing::Point(622, 37);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = System::Drawing::Size(75, 23);
			this->buttonCreate->TabIndex = 21;
			this->buttonCreate->Text = L"Create";
			this->buttonCreate->UseVisualStyleBackColor = true;
			this->buttonCreate->Click += gcnew System::EventHandler(this, &MyForm::buttonCreate_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(622, 79);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 22;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// buttonFind
			// 
			this->buttonFind->Location = System::Drawing::Point(622, 164);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(75, 23);
			this->buttonFind->TabIndex = 23;
			this->buttonFind->Text = L"Find";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
			// 
			// buttonDel
			// 
			this->buttonDel->Location = System::Drawing::Point(622, 120);
			this->buttonDel->Name = L"buttonDel";
			this->buttonDel->Size = System::Drawing::Size(75, 23);
			this->buttonDel->TabIndex = 24;
			this->buttonDel->Text = L"Delete";
			this->buttonDel->UseVisualStyleBackColor = true;
			this->buttonDel->Click += gcnew System::EventHandler(this, &MyForm::buttonDel_Click);
			// 
			// buttonIns
			// 
			this->buttonIns->Location = System::Drawing::Point(485, 230);
			this->buttonIns->Name = L"buttonIns";
			this->buttonIns->Size = System::Drawing::Size(75, 23);
			this->buttonIns->TabIndex = 25;
			this->buttonIns->Text = L"Insert";
			this->buttonIns->UseVisualStyleBackColor = true;
			this->buttonIns->Click += gcnew System::EventHandler(this, &MyForm::buttonIns_Click);
			// 
			// labelOpStatus
			// 
			this->labelOpStatus->AutoSize = true;
			this->labelOpStatus->Location = System::Drawing::Point(57, 314);
			this->labelOpStatus->Name = L"labelOpStatus";
			this->labelOpStatus->Size = System::Drawing::Size(98, 15);
			this->labelOpStatus->TabIndex = 26;
			this->labelOpStatus->Text = L"Operation Status";
			this->labelOpStatus->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelFind
			// 
			this->labelFind->AutoSize = true;
			this->labelFind->Location = System::Drawing::Point(284, 181);
			this->labelFind->Name = L"labelFind";
			this->labelFind->Size = System::Drawing::Size(118, 15);
			this->labelFind->TabIndex = 27;
			this->labelFind->Text = L"Find or delete by key";
			// 
			// textBoxFind
			// 
			this->textBoxFind->Location = System::Drawing::Point(460, 178);
			this->textBoxFind->Name = L"textBoxFind";
			this->textBoxFind->Size = System::Drawing::Size(100, 21);
			this->textBoxFind->TabIndex = 28;
			// 
			// buttonRenew
			// 
			this->buttonRenew->Location = System::Drawing::Point(622, 203);
			this->buttonRenew->Name = L"buttonRenew";
			this->buttonRenew->Size = System::Drawing::Size(75, 23);
			this->buttonRenew->TabIndex = 29;
			this->buttonRenew->Text = L"Renew";
			this->buttonRenew->UseVisualStyleBackColor = true;
			this->buttonRenew->Click += gcnew System::EventHandler(this, &MyForm::buttonRenew_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 390);
			this->Controls->Add(this->buttonRenew);
			this->Controls->Add(this->textBoxFind);
			this->Controls->Add(this->labelFind);
			this->Controls->Add(this->labelOpStatus);
			this->Controls->Add(this->buttonIns);
			this->Controls->Add(this->buttonDel);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonCreate);
			this->Controls->Add(this->groupBoxTabType);
			this->Controls->Add(this->textBoxEff);
			this->Controls->Add(this->textBoxKeyRange);
			this->Controls->Add(this->textBoxNumRec);
			this->Controls->Add(this->textBoxVal);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->labelEff);
			this->Controls->Add(this->labelConfig);
			this->Controls->Add(this->labelRec);
			this->Controls->Add(this->labelRecVal);
			this->Controls->Add(this->labelRecKey);
			this->Controls->Add(this->labelKeyRange);
			this->Controls->Add(this->labelNumRec);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Tables";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBoxTabType->ResumeLayout(false);
			this->groupBoxTabType->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

// CREATE
private: System::Void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input;
	input = msclr::interop::marshal_as<std::string>(textBoxNumRec->Text);
	NumRec = atoi(input.c_str());
	input = msclr::interop::marshal_as<std::string>(textBoxKeyRange->Text);
	KeyRange = atoi(input.c_str());

	if (radioButtonScanTab->Checked)
	{
		scantab.fillTab(NumRec, KeyRange);
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.fillTab(NumRec, KeyRange);
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.fillTab(NumRec, KeyRange);
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.fillTab(NumRec, KeyRange);
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.fillTab(NumRec, KeyRange);
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.fillTab(NumRec, KeyRange);
	}

	std::string str = "Table was successfully created";
	labelOpStatus->Text = gcnew String(str.c_str());
}

// SAVE
private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {

	if (radioButtonScanTab->Checked)
	{
		scantab.printTab("scantab");
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.printTab("sorttab");
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.printTab("arrhashtab");
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.printTab("listhashtab");
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.printTab("treetab");
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.printTab("avltreetab");
	}

	std::string str = "Table was successfully saved";
	labelOpStatus->Text = gcnew String(str.c_str());
}

// FIND
private: System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input, effstr;
	input = msclr::interop::marshal_as<std::string>(textBoxFind->Text);
	int findkey = atoi(input.c_str());
	bool findres;
	int eff;

	if (radioButtonScanTab->Checked)
	{
		scantab.clrEff();
		findres = scantab.findRec(findkey);
		eff = scantab.getEff();
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.clrEff();
		findres = sorttab.findRec(findkey);
		eff = sorttab.getEff();
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.clrEff();
		findres = arrhashtab.findRec(findkey);
		eff = arrhashtab.getEff();
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.clrEff();
		findres = listhashtab.findRec(findkey);
		eff = listhashtab.getEff();
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.clrEff();
		findres = treetab.findRec(findkey);
		eff = treetab.getEff();
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.clrEff();
		findres = avltreetab.findRec(findkey);
		eff = avltreetab.getEff();
	}

	effstr = std::to_string(eff);
	std::string str;
	if (findres)
	{
		str = "The record was successfully found";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	else
	{
		str = "The record was not found";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	textBoxEff->Text = gcnew String(effstr.c_str());
}

// DELETE
private: System::Void buttonDel_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input, effstr;
	input = msclr::interop::marshal_as<std::string>(textBoxFind->Text);
	int findkey = atoi(input.c_str());
	int delres;
	int eff;

	if (radioButtonScanTab->Checked)
	{
		scantab.clrEff();
		delres = scantab.delRec(findkey);
		eff = scantab.getEff();
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.clrEff();
		delres = sorttab.delRec(findkey);
		eff = sorttab.getEff();
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.clrEff();
		delres = arrhashtab.delRec(findkey);
		eff = arrhashtab.getEff();
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.clrEff();
		delres = listhashtab.delRec(findkey);
		eff = listhashtab.getEff();
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.clrEff();
		delres = treetab.delRec(findkey);
		eff = treetab.getEff();
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.clrEff();
		delres = avltreetab.delRec(findkey);
		eff = avltreetab.getEff();
	}

	effstr = std::to_string(eff);
	std::string str;
	if (delres == TabOK)
	{
		str = "The record was successfully deleted";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	else {
		str = "The record was not deleted";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	textBoxEff->Text = gcnew String(effstr.c_str());
}

// INSERT
private: System::Void buttonIns_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input, effstr;
	input = msclr::interop::marshal_as<std::string>(textBoxKey->Text);
	int newkey = atoi(input.c_str());
	input = msclr::interop::marshal_as<std::string>(textBoxVal->Text);
	int newval = atoi(input.c_str());
	TRecord newrec(newkey, newval);
	int insres;
	int eff;

	if (radioButtonScanTab->Checked) {
		scantab.clrEff();
		insres = scantab.insRec(newrec);
		eff = scantab.getEff();
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.clrEff();
		insres = sorttab.insRec(newrec);
		eff = sorttab.getEff();
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.clrEff();
		insres = arrhashtab.insRec(newrec);
		eff = arrhashtab.getEff();
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.clrEff();
		insres = listhashtab.insRec(newrec);
		eff = listhashtab.getEff();
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.clrEff();
		insres = treetab.insRec(newrec);
		eff = treetab.getEff();
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.clrEff();
		insres = avltreetab.insRec(newrec);
		eff = avltreetab.getEff();
	}

	effstr = std::to_string(eff);
	std::string str;
	if (insres == TabOK)
	{
		str = "The record was successfully inserted";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	else {
		str = "The record was not inserted";
		labelOpStatus->Text = gcnew String(str.c_str());
	}
	textBoxEff->Text = gcnew String(effstr.c_str());
}

// RENEW
private: System::Void buttonRenew_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButtonScanTab->Checked)
	{
		scantab.clrTab();
		scantab.clrEff();
	}
	if (radioButtonSortTab->Checked)
	{
		sorttab.clrTab();
		sorttab.clrEff();
	}
	if (radioButtonHashArr->Checked)
	{
		arrhashtab.clrTab();
		arrhashtab.clrEff();
	}
	if (radioButtonHashList->Checked)
	{
		listhashtab.clrTab();
		listhashtab.clrEff();
	}
	if (radioButtonTreeTab->Checked)
	{
		treetab.clrTab();
		treetab.clrEff();
	}
	if (radioButtonAVLTab->Checked)
	{
		avltreetab.clrTab();
		avltreetab.clrEff();
	}
	std::string str = "Table was successfully renewed";
	labelOpStatus->Text = gcnew String(str.c_str());
}

// EXIT
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

