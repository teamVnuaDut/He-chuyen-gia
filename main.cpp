#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "KnowledgeBase.h"
#include "InferenceEngine.h"
#include "ExplanationEngine.h"
#include "Rule.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

//ham giao dien
void adminMode(KnowledgeBase& kb);
void userMode(const KnowledgeBase& globalKB);
void clearScreen();
void showAdminBanner();
void showUserBanner();

int main()
{
	//khai bao doi tuong
	KnowledgeBase kb;
	int mainChoice;

	cout << "Khởi tạo hệ chuyên gia!!!";
	do
	{
		cout << YELLOW << "\n--- MENU CHINH ---\n";
		cout << GREEN << "1. Admin\n";
		cout << GREEN << "2. User\n";
		cout << RED << "3. Exit\n";
		cout << "Chon: ";
		cin >> mainChoice;
		cin.ignore();

		switch (mainChoice)
		{
		case 1:
		{
			adminMode(kb);
			break;
		}
		case 2:
		{
			userMode(kb);
			break;
		}
		case 3:
		{
			cout << "Thoat chuong trinh ... \n";
			break;
		}
		default:
			cout << "Lua chon khong phu hop\n";
			system("pause");
		}
	} while (mainChoice!=3);

	return 0;
}

void adminMode(KnowledgeBase& kb)
{
	int choice;
	do
	{
		showAdminBanner();
		cout << "\n----Che do Admin----\n";
		cout << "1.Them fact\n";
		cout << "2.Them Rule\n";
		cout << "3.Hien thi kien thuc (Facts & Rules)\n";
		cout << "4.Cap nhat Fact\n";
		cout << "5.Cap nhat Rule\n";
		cout << "6.Load du lieu.\n";
		cout << "7.Luu du lieu.\n";
		cout << "8.Quay lai menu\n";
		cout << "Chon: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case 1: {
				cout << "Nhap fact: ";
				string fact;
				getline(cin, fact);
				kb.addFact(fact);
				cout << "Da them fact!\n";
				break;
				}
			case 2: {
				int numPremises;
				cout << "Nhap so luong dieu kien(premises): ";
				cin >> numPremises;
				cin.ignore();
				vector<string> premises;
				for (int i = 0; i < numPremises; ++i)
				{
					cout << "Nhap dieu kien: " << i + 1 << ": ";
					string cond;
					getline(cin, cond);
					premises.push_back(cond);
				}
				cout << "Nhap ket luan: ";
				string conclusion;
				getline(cin, conclusion);
				Rule rule(premises, conclusion);
				kb.addRule(rule);
				cout << "Da them rule\n";
				break;
			}
			case 3:
			{
				kb.displayFacts();
				kb.displayRules();
				break;
			}
			case 4:
			{
				string oldFact, newFact;
				cout << "Nhap Fact can thay doi: ";
				getline(cin, oldFact);
				cout << "Nhap noi dung moi cho fact\n";
				getline(cin, newFact);
				if (kb.updateFact(oldFact, newFact))
				{
					cout << "Cap nhat fact thanh cong\n";
				}
				else
				{
					cout << "Khong tim thay fact can cap nhat\n";
				}
				break;
			}
			case 5:
			{
				string ruleID;
				string newConclusion;
				int numPremises;
				vector<string> premises;

				cout << "Nhap ket luan cua Rule can update: \n";
				getline(cin, ruleID);

				cout << "Nhap so luong dieu kien moi: ";
				cin >> numPremises;
				cin.ignore();
				for (int i = 0; i < numPremises; ++i)
				{
					cout << "Nhap dieu kien: " << i + 1 << ": ";
					string cond;
					getline(cin, cond);
					premises.push_back(cond);
				}
				
				cout << "Nhap ket luan moi: ";
				getline(cin, newConclusion);

				Rule newRule(premises, newConclusion);
				if (kb.updateRule(ruleID, newRule))
				{
					cout << "Cap nhat Rule thanh cong\n";
				}
				else
				{
					cout << "Khong tim thay Rule can cap nhat\n";
				}
				break;
			}
			case 6:
			{
				string filename;
				cout << "File tri thuc\n";
				getline(cin, filename);
				if (kb.loadFromFile(filename))
				{
					cout << "Load tri thuc thanh cong\n";
				}
				break;
			}
			case 7:
			{
				string filename;
				cout << "file luu tru\n";
				getline(cin, filename);
				if (kb.saveToFile(filename))
				{
					cout << "Luu du lieu thanh cong\n";
				}
				break;
			}
			case 8:
			{
				cout << "Thoat che do admin\n";
				break;
			}
			default:
				cout << "Lua chon khong hop le\n";
				break;
		}
	} while (choice!=8);
}

void userMode(const KnowledgeBase& globalKB)
{
	showUserBanner();

	const vector<string>& availableFacts = globalKB.getFacts();
	if (availableFacts.empty())
	{
		cout << "Chua co du lieu tu he thong\n";
		return;
	}

	cout << "\n----Che do nguoi dung----\n";
	cout << "Cac lua chon co san: " << endl;
	for (size_t i = 0; i < availableFacts.size(); i++)
	{
		cout << i + 1 << ". " << availableFacts[i] << endl;
	}
	cout << "Chon toi thieu 4 dap an";
	string line;
	getline(cin, line);
	istringstream iss(line);
	int idx;
	vector<int> selections;
	while (iss >> idx)
	{
		//kiem tra xem chi so co hop le ha khong 
		if (idx >= 1 && idx <= static_cast<int>(availableFacts.size()))
		{
			selections.push_back(idx - 1);	//chuyen ve chio so 0-index
		}
	}
	if (selections.size() < 4)
	{
		cout << "ban phai chon it nhat 4 dap an!\n Vui long thu lai\n";
		return;
	}

	//tao cs tri thuc tam thoi
	KnowledgeBase userKB;
	for (int index : selections)
	{
		userKB.addFact(availableFacts[index]);
	}

	const auto& globalRules = globalKB.getRules();
	for (const auto& rule : globalRules)
	{
		userKB.addRule(rule);
	}

	//hien thi fact nguoi dung da chon 
	cout << "\nCac fact ban da chon:\n";
	userKB.displayFacts();

	//thuc hien duy dien tren du lieu nguoi chon
	InferenceEngine ie;
	ie.infer(userKB);

	//hien thi loi giai thich qua qua trinh suy dien
	ExplanationEngine ee;
	ee.explain();
}

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif // _WIN32

}

void showAdminBanner()
{
	clearScreen();
	cout << CYAN << "===== CHE DO ADMIN =====" << RESET << "\n";
}

void showUserBanner()
{
	clearScreen();
	cout << CYAN << "===== CHE DO USER =====" << RESET << "\n";
}