#include<iostream>
#include<string>
#include <Windows.h>
using namespace std;
string check(string a);
class node_voter
{
public:
	string name;
	string cnic;
	int age;
	int can;
	string req;
	int get_vote;
	int cast;
	int did;
	node_voter* link;
};

class class_voter
{
private:
	node_voter*head, *tail;
public:
	class_voter()
	{
		head = NULL;
		tail = NULL;	
	}
	void enter(string name, string cnic, int age, class_voter obj)
	{
		if (obj.what(cnic))
		{
			cout << "\t\t\t\t Already exict in our recoed ";
		}
		else
		{
			if (age >= 18)
			{
				node_voter* pt = new node_voter();
				pt->name = name;
				pt->cnic = cnic;
				pt->age = age;
				pt->can = 0;
				pt->req = "no";
				pt->get_vote = 0;
				pt->cast = 0;
				pt->did = 0;
				pt->link = NULL;
				if (head == NULL)
				{
					head = pt;
					tail = pt;
				}
				else
				{
					tail->link = pt;
					tail = pt;
				}
			}
			else
			{
				cout << "\t\t\t\t Voter age is not enough to cast a vote! " << endl;
			}
		}
	}
	void can(string cnic)
	{
		node_voter*pt;
		pt = head;
		while (pt != NULL)
		{
			if (cnic == pt->cnic)
			{
				if (pt->can == 0)
				{
					pt->req = "yes";
					cout << "\t\t\t\t\tYour request has been generated for candidate! ";
					return;
				}
				else
				{
					cout << "\t\t\t\t\tYou are already a candidate! ";
					return;
				}
			}
			pt = pt->link;
		}
	}
	void notcan(string cnic)
	{
		node_voter*pt;
		pt = head;
		while (pt != NULL)
		{
			if (cnic == pt->cnic)
			{
				if (pt->req == "yes")
				{
					pt->can = 0;
					pt->req = "no";
					cout << "\t\t\t\t\tYour request for candidate is deleteed! ";
				}
			}
			pt = pt->link;
		}
	}
	int display_can_req()
	{
		node_voter*pt = head;
		int i = 0;
		while (pt != NULL)
		{
			if (pt->req == "yes")
			{
				i++;
				cout << "\t\t\t\t\t ===================================" << endl;
				cout << "\t\t\t\t\t Candidtae # " << i << " : " << endl;
				cout << "\t\t\t\t\t    Name : " << pt->name << endl;
				cout << "\t\t\t\t\t ===================================" << endl << endl;
			}
			pt = pt->link;
		}
		if (i == 0)
		{
			cout << "\t\t\t\t\tNo candidates request enter! ";
			return 0;
		}
		cout << "\t\t\t\t\t ===================================" << endl;
		cout << "\t\t\t\t\t press 0 to go back  " << endl;
		cout << "\t\t\t\t\t ===================================" << endl;
		cout << "\t\t\t\t\t ";
		return i;
	}
	int display_vote_can(string cnic) // didplay candidates
	{
		node_voter*pt = head;
		int i = 0;
		while (pt != NULL)
		{
			if (pt->can == 1)
			{
				if (pt->cnic[0] == cnic[0])
				{
					i++;
					cout << "\t\t\t\t\t ===================================" << endl;
					cout << "\t\t\t\t\t Candidtae # " << i << " : " << endl;
					cout << "\t\t\t\t\t    Name : " << pt->name << endl;
					cout << "\t\t\t\t\t ===================================" << endl << endl;
				}
			}
			pt = pt->link;
		}
		if (i == 0)
		{
			cout << "\t\t\t\t\t No candidates has been enter in your area! " ;
			return 0;
		}
		cout << "\t\t\t\t\t ";
		return i;
		system("pause");
	}
	int display_can()
	{
		node_voter*pt = head;
		int i = 0;
		while (pt != NULL)
		{
			if (pt->can == 1)
			{
				i++;
				cout << "\t\t\t\t\t ===================================" << endl;
				cout << "\t\t\t\t\t Candidtae # " << i << " : " << endl;
				cout << "\t\t\t\t\t    Name : " << pt->name << endl;
				cout << "\t\t\t\t\t ===================================" << endl << endl;
			}
			pt = pt->link;
		}
		if (i == 0)
		{
			cout << "\t\t\t\t\tNo candidates has been enter! " ;
			return 0;
		}
		cout << "\t\t\t\t\t ===================================" << endl;
		cout << "\t\t\t\t\t press 0 to go back  " << endl;
		cout << "\t\t\t\t\t ===================================" << endl;
		cout << "\t\t\t\t\t ";
		return i;
		system("pause");
	}
	void add_vote_can(int i)
	{
		node_voter*pt;
		pt = head;
		int a = 1;
		while (pt != NULL)
		{
			if (pt->can == 1)
			{
				if (i == a)
				{
					pt->get_vote = 0;
					return;
				}
				a++;
			}
			pt = pt->link;
		}
		cout << "\t\t\t\t\tThis CNIC is not exsit in our record! " << endl;
	}
	void del_can(int i)
	{
		node_voter*pt;
		pt = head;
		int a = 1;
		while (pt != NULL)
		{
			if (pt->can == 1)
			{
				if (i == a)
				{
					pt->can = 0;
					cout << "\t\t\t\t\t Candidate is deleted! ";
					return;
				}
				a++;
			}
			pt = pt->link;
		}
	}
	void cast_vote(int i, string cnic)
	{
		node_voter*pt;
		pt = head;
		int a = 1;
		while (pt != NULL)
		{
			if (pt->can == 1)
			{
				if (pt->cnic[0] == cnic[0])
				{
					if (i == a)
					{
						pt->get_vote = pt->get_vote + 1;
						return;
					}
					a++;
				}
			}
			pt = pt->link;
		}
	}
	void add_can(int i)
	{
		node_voter*pt;
		pt = head;
		int a = 1;
		while (pt != NULL)
		{
			if (pt->req == "yes")
			{
				if (i == a)
				{
					pt->can = 1;
					pt->req = "no";
					cout << "\t\t\t\t\t\tVoter is candidate now! ";
					return;
				}
				a++;
			}
			pt = pt->link;
		}
		cout << "\t\t\t\t\tAll request has been intertained ..... " << endl;
	}
	void display()
	{
		node_voter*pt = head;
		int i = 1;
		while (pt != NULL)
		{
			cout << "\t\t\t\t\t ===================================" << endl;
			cout << "\t\t\t\t\t voter # " << i << " : " << endl;
			cout << "\t\t\t\t\t    CNIC : " << pt->cnic << endl;
			cout << "\t\t\t\t\t    Name : " << pt->name << endl;
			cout << "\t\t\t\t\t    Age  : " << pt->age << endl;
			cout << "\t\t\t\t\t ===================================" << endl << endl;
			pt = pt->link;
			i++;
		}
		if (i == 1)
		{
			cout << "\t\t\t\t\tNo voter has been enterd exist " << endl;
		}
		cout << "\t\t\t\t\t ";
	}
	void Search(string number)
	{
		node_voter*pt;
		pt = head;
		while (pt != NULL)
		{
			if (number == pt->cnic)
			{
				cout << "\t\t\t\t\t ===================================" << endl;
				cout << "\t\t\t\t\t voter has be found  " << endl;
				cout << "\t\t\t\t\t    CNIC : " << pt->cnic << endl;
				cout << "\t\t\t\t\t    Name : " << pt->name << endl;
				cout << "\t\t\t\t\t    Age  : " << pt->age << endl;
				cout << "\t\t\t\t\t ===================================" << endl << endl;
				return;
			}
			pt = pt->link;
		}
		cout << "\t\t\t\t\tNo voter of this CNIC '" << pt->cnic << " exist " << endl;
		cout << "\t\t\t\t\t ";
	}
	bool what(string number)
	{
		node_voter*tmp;
		tmp = head;
		while (tmp != NULL)
		{
			if (number == tmp->cnic)
			{
				return true;
			}
			tmp = tmp->link;
		}
		return false;
	}
	void del(string w)
	{
		node_voter*pt;
		node_voter*per;
		per = NULL;
		pt = head;
		if (pt != NULL && pt->cnic == w)
		{
			head = head->link;
			delete(pt);
			cout << "\t\t\t\t\t This record has been delete ";
			return;
		}
		while (pt != NULL && pt->cnic != w)
		{
			per = pt;
			pt = pt->link;
		}
		if (pt == NULL)
		{
			cout << "\t\t\t\t\t This record does not exict ";
			return;
		}
		per->link = pt->link;
		cout << "\t\t\t\t\t This record has been delete ";
		delete(pt);
	}
	bool what_can(string number)
	{
		node_voter*tmp;
		tmp = head;
		while (tmp != NULL)
		{
			if (number == tmp->cnic && tmp->cast == 0)
			{
				if (tmp->did == 0)
				{
					tmp->cast == 1;
					tmp->did = 1;
					cout << "\t\t\t\t\t------------------------------------------------" << endl;
					cout << "\t\t\t\t\t Candidates of " << check(number) << " are below" << endl;
					cout << "\t\t\t\t\t------------------------------------------------" << endl << endl;
					return true;
				}
				else
				{
					return false;
				}
			}
			tmp = tmp->link;
		}
		return false;
	}
	void display_result()
	{
		node_voter*pt;
		pt = head;
		char cn[7] = { '1', '2', '3', '4', '5', '6', '7' };
		int a[7] = { 0 , 0 , 0 , 0, 0 , 0, 0 };
		string max_cnic[7];
		for (int i = 0; i <7; i++)
		{
			while (pt != NULL)
			{
				if (pt->cnic[0] == cn[i])
				{
					if (a[i] < pt->get_vote)
					{
						a[i] = pt->get_vote;
						max_cnic[i] = pt->cnic;
					}
				}
				pt = pt->link;
			}
		}
		string cn2[7] = { "1", "2", "3", "4", "5", "6", "7" };
		for (int i = 0; i < 7; i++)
		{
			cout << "\t\t\t\t\t ===================================" << endl;
			cout << "\t\t\t\t\t      Winner of " << check(cn2[i])<<endl;
			cout << "\t\t\t\t\t ===================================" << endl;
			node_voter*tmp;
			tmp = head;
			while (tmp != NULL)
			{
				if (max_cnic[i] == tmp->cnic)
				{
					cout << "\t\t\t\t\t    CNIC : " << tmp->cnic << endl;
					cout << "\t\t\t\t\t    Name : " << tmp->name << endl;
					cout << "\t\t\t\t\t ===================================" << endl << endl;
				}
				tmp = tmp->link;
			}
		}
	}
	
	void start()
	{
		node_voter*pt = head;
		while (pt != NULL)
		{
			pt->can = 0;
			pt->req = "no";
			pt->get_vote = 0;
			pt->cast = 0;
			pt->did = 0;
			pt = pt->link;
			
		}
	}

};

class node_admin
{
public:
	string cnic;
	node_admin* link;
};

class class_admin
{
private:
	node_admin *head, *tail;
public:
	class_admin()
	{
		head = NULL;
		tail = NULL;
	}
	void enter(string cnic, class_admin obj)
	{
		if (obj.what(cnic))
		{
			cout << "\t\t\t\t\t Already exict in our recoed " << endl;
		}
		else
		{
			node_admin* pt = new node_admin;
			pt->cnic = cnic;
			pt->link = NULL;
			if (head == NULL)
			{
				head = pt;
				tail = pt;
			}
			else
			{
				tail->link = pt;
				tail = pt;
			}
			cout << "\t\t\t\t\t New recoed has been added " << endl;
		}
	}
	void display()
	{
		node_admin *pt = head;
		int i = 1;
		while (pt != NULL)
		{
			cout << "\t\t\t\t\t-------------------------------------------" << endl;
			cout << "\t\t\t\t\t Admin # " << i << " is : " << pt->cnic << endl;
			cout << "\t\t\t\t\t-------------------------------------------" << endl;
			pt = pt->link;
			i++;
		}
	}
	void Search(string number)
	{
		node_admin *tmp;
		tmp = head;
		while (tmp != NULL)
		{
			if (number == tmp->cnic)
			{
				cout << "\t\t\t\tAdmin of this CNIC '" << tmp->cnic << "' is exsit " << endl;
				return;
			}
			tmp = tmp->link;
		}
		cout << "\t\t\t\tAdmin of this CNIC '" << tmp->cnic << "' doesn't exsit " << endl;
	}

	bool what(string number)
	{
		node_admin *tmp;
		tmp = head;
		while (tmp != NULL)
		{
			if (number == tmp->cnic)
			{
				return true;
			}
			tmp = tmp->link;
		}
		return false;
	}
	void del(string w)
	{
		node_admin *pt;
		node_admin *per;
		per = NULL;
		pt = head;
		if (w == "12345-1234567-1")
		{
			cout << endl << "\t\t\t\t\t=============================================" << endl;
			cout << "\t\t\t\t\t|| Don't you dare try to delete this admin ||" << endl;
			cout << "\t\t\t\t\t|| you are way out of your League          ||  " << endl;
			cout << "\t\t\t\t\t=============================================" << endl;
			return;
		}
		if (pt != NULL && pt->cnic == w)
		{
			head = head->link;
			delete(pt);
			cout << "\t\t\t\t\t This record has be delete " << endl;
			return;
		}
		while (pt != NULL && pt->cnic != w)
		{
			per = pt;
			pt = pt->link;
		}
		if (pt == NULL)
		{
			cout << "\t\t\t\t\t This record does not exict " << endl;
			return;
		}
		per->link = pt->link;
		cout << "\t\t\t\t\t This record has be delete " << endl;
		delete(pt);
	}
};

string input_cnic()
{
go:
	string cnic;
	cout << "\t\t\t\t\t Enter your CNIC please (xxxxx-xxxxxxx-x) : ";
	cin >> cnic;
	int a = 0, b = 0;
	if (cnic.length() == 15) 
	{
		for (int i = 0; i < cnic.length(); i++) 
		{
			if (isdigit(cnic[i]) == false) 
			{
				a = a + i;
			}
			if (cnic[i] == '-') 
			{
				b = b + i;
			}
		}
		if (a == 18 && b == 18) 
		{
			return cnic;
		}
		else 
		{
			cout << "\t\t\t\t\t invalid entry! " << endl;
			goto go;
		}
	}
	else if (cnic == "14206")
	{
		return cnic;
	}
	else
	{
		cout << "\t\t\t\t\t invalid entry! " << endl;
		goto go;
	}
	return cnic;

}

string check(string a)
{
	int i = a.length();
	if (a[0] == '1')
	{
		return "Khyber Pakhtunkhwa";
	}
	else if (a[0] == '2')
	{
		return "FATA";
	}
	else if (a[0] == '3')
	{
		return "Punjab";
	}
	else if (a[0] == '4')
	{
		return "Sindh";
	}
	else if (a[0] == '5')
	{
		return "Balochistan";
	}
	else if (a[0] == '6')
	{
		return "Islamabad";
	}
	else if (a[0] == '7')
	{
		return "Gilgit-Baltistan";
	}
}
void loadingBar()
{
	system("color 0A");
	char a = 177, b = 219;
	cout << "\n\n\n\n";
	cout << "\n\n\n\n\t\t\t\t\t Loading...\n\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 26; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 26; i++)
	{
		cout << b;
		Sleep(300);
	}
	return;
}
void about()
{
	system("color 07");
	char b = 219;
	cout << endl << endl << endl << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 80; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                                        ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << " Sometime Words isn't perfect for intro but if there is, it's right here";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                                        ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 80; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                                        ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << " #           # ####### #         # #      ##    # #       ## #######    ";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << " #           # #       #       #        #    #  #   #   #  # #          ";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << " #     #     # ####### #      #        #      # #     #    # #######    ";
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << " #   #   #   # #       #       #        #    #  #          # #          ";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << " # #       # # ####### ######    # #      ##    #          # #######    ";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 80; i++)   // midel bar
	{
		cout << b;
	}
	cout << endl << "\t    ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                                        ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t     Riphah International University                \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t Project name :       Polling system                \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t Developer    :       Athar Ateeq                  \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t SAP id       :         14206                      \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t Semester     :         3rd (section B)             \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "\t Instructor   :    Sir Rana Marwat Hussain          \t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                                        ";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t    ";
	Sleep(300);
	for (int i = 0; i < 80; i++)   // uper bar
	{
		cout << b;
	}
	return;
}
void users()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "  Welcome to Voting system (-.-)..  ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << "  1.  Administrators                ";
	for (int i = 0; i < 4; i++)   // right side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2.  Voter                         ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << "  3.  Help                          ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "  4.  About                         ";
	for (int i = 0; i < 4; i++)   // right side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0.  Exit                          ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void admin()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "  Welcome to Admin panal (=.=)..    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << "  1.  Manage Administrators         ";
	for (int i = 0; i < 4; i++)   // right side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2.  Manage Candidates             ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "  3.  Start voting                  ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "  4.  Check vote Results            ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "  5.  Manage voters                 ";
	for (int i = 0; i < 4; i++)   // right side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0.  Logout                        ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void voter()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "  Welcome to voter panal (=.=)..    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  1.  Register as candidate         ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2.  Don't want to be candidate    ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0.  Logout                        ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void help()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t";
	for (int i = 0; i < 56; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "      Tension not, Help has arrive (=.=)..      ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 56; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "If you wanna cast a vote but don't have voter id";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << "please contact Administrators and if you are a  ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 7th line
	{
		cout << b;
	}
	cout << "voter and want to make yourself a candidate then";
	for (int i = 0; i < 4; i++)   // right side bar on 7th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "open your portal and generate request to be a   ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 9th line
	{
		cout << b;
	}
	cout << "candidate. After that it is up to Administrator ";
	for (int i = 0; i < 4; i++)   // right side bar on 9th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "to accept that request. If you want to cast a   ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "vote open voter portal and you'll get candidiate";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "of your area feel, free to cast we will keep it ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "secret.                                         ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "                                                ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "    Admin Phone # : 0347-8448101                ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 10th line
	{
		cout << b;
	}
	cout << "    Admin E-mail : atharateeq01@gmail.com       ";
	for (int i = 0; i < 4; i++)   // right side bar on 10th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                                ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t";
	for (int i = 0; i < 56; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void manage_administrators()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "    Manage Administrators (-.-)..   ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << "  1. Add Administrator              ";
	for (int i = 0; i < 4; i++)   // right side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2. Display Administrator          ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  3. Delelet Administrator          ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0. Exit                           ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void manage_candidates()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}

	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "    Manage Candidates (-.-)..       ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}

	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << "  1. Check request for Candidates   ";
	for (int i = 0; i < 4; i++)   // right side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2. Delelet Candidates             ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0. Exit                           ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void manage_voter()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}

	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "      Manage voter  (-.-)..         ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}

	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 4th line
	{
		cout << b;
	}
	cout << "  1. Add voter                      ";
	for (int i = 0; i < 4; i++)   // right side bar on 4th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  2. Delete voter                   ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << "  3. View all voters                ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 6th line
	{
		cout << b;
	}
	cout << "  4. Search voter                   ";
	for (int i = 0; i < 4; i++)   // right side bar on 6th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "  0. Exit                           ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
void votting()
{
	system("color 07");
	char b = 219;
	cout << "\r";
	cout << endl << endl << endl << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // uper bar
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}

	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 2nd line
	{
		cout << b;
	}
	cout << "  Welcome to voter panal (=.=)..    ";
	for (int i = 0; i < 4; i++)   // right side bar on 2nd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // bar on 3rd line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 5th line
	{
		cout << b;
	}
	cout << "  Enter your CNIC you cast vote     ";
	for (int i = 0; i < 4; i++)   // right side bar on 5th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 4; i++)   // left side bar on 8th line
	{
		cout << b;
	}
	cout << "                                    ";
	for (int i = 0; i < 4; i++)   // right side bar on 8th line
	{
		cout << b;
	}
	cout << endl << "\t\t\t\t\t";
	for (int i = 0; i < 44; i++)   // lower bar
	{
		cout << b;
	}
	return;
}
int main()
{
	loadingBar();
	system("CLS");
	about();
	cout << "\t\t\t\t\t ";
	system("pause");
	system("CLS");
	class_admin ad;
	ad.enter("12345-1234567-1", ad);
	class_voter vo;
	//kpk 6 voters 
	vo.enter("kpk_1st", "12345-1234567-1", 23, vo);
	vo.enter("kpk_2nd", "12345-1234567-2", 23, vo);
	vo.enter("kpk_3rd", "12345-1234567-3", 23, vo);
	vo.enter("kpk_4th", "12345-1234567-4", 23, vo);
	vo.enter("kpk_5th", "12345-1234567-5", 23, vo);
	vo.enter("kpk_6th", "12345-1234567-6", 23, vo);
	//FATA 6 voter
	vo.enter("fata_1st", "22345-1234567-1", 23, vo);
	vo.enter("fata_2nd", "22345-1234567-2", 23, vo);
	vo.enter("fata_3rd", "22345-1234567-3", 23, vo);
	vo.enter("fata_4th", "22345-1234567-4", 23, vo);
	vo.enter("fata_5th", "22345-1234567-5", 23, vo);
	vo.enter("fata_6th", "22345-1234567-6", 23, vo);
	//punjab 6 voters
	vo.enter("pun_1st", "32345-1234567-1", 23, vo);
	vo.enter("pun_2nd", "32345-1234567-2", 23, vo);
	vo.enter("pun_3rd", "32345-1234567-3", 23, vo);
	vo.enter("pun_4th", "32345-1234567-4", 23, vo);
	vo.enter("pun_5th", "32345-1234567-5", 23, vo);
	vo.enter("pun_6th", "32345-1234567-6", 23, vo);
	//Sindh 6 voters
	vo.enter("sin_1st", "42345-1234567-1", 23, vo);
	vo.enter("sin_2nd", "42345-1234567-2", 23, vo);
	vo.enter("sin_3rd", "42345-1234567-3", 23, vo);
	vo.enter("sin_4th", "42345-1234567-4", 23, vo);
	vo.enter("sin_5th", "42345-1234567-5", 23, vo);
	vo.enter("sin_6th", "42345-1234567-6", 23, vo);
	//Balochistan 6 voters
	vo.enter("bal_1st", "52345-1234567-1", 23, vo);
	vo.enter("bal_2nd", "52345-1234567-2", 23, vo);
	vo.enter("bal_3rd", "52345-1234567-3", 23, vo);
	vo.enter("bal_4th", "52345-1234567-4", 23, vo);
	vo.enter("bal_5th", "52345-1234567-5", 23, vo);
	vo.enter("bal_6th", "52345-1234567-6", 23, vo);
	//Islamabad 6 voters
	vo.enter("isl_1st", "62345-1234567-1", 23, vo);
	vo.enter("isl_2nd", "62345-1234567-2", 23, vo);
	vo.enter("isl_3rd", "62345-1234567-3", 23, vo);
	vo.enter("isl_4th", "62345-1234567-4", 23, vo);
	vo.enter("isl_5th", "62345-1234567-5", 23, vo);
	vo.enter("isl_6th", "62345-1234567-6", 23, vo);
	//Gilgit-Baltistan 6 voters
	vo.enter("gil_1st", "72345-1234567-1", 23, vo);
	vo.enter("gil_2nd", "72345-1234567-2", 23, vo);
	vo.enter("gil_3rd", "72345-1234567-3", 23, vo);
	vo.enter("gil_4th", "72345-1234567-4", 23, vo);
	vo.enter("gil_5th", "72345-1234567-5", 23, vo);
	vo.enter("gil_6th", "72345-1234567-6", 23, vo);
go_user:
	system("CLS");
	users();
	cout << endl << "\t\t\t\t\t Press crosspanding no : ";
	int sel;
	cin >> sel;
	if (sel == 1) // admin
	{
		string cnic = input_cnic();
		bool check = ad.what(cnic);
		if (check)
		{
		go_admin:
			system("CLS");
			admin();
			cout << endl << "\t\t\t\t\t Press crosspanding no : ";
			int sel;
			cin >> sel;
			if (sel == 1)
			{
			go_m_admin:
				system("CLS");
				manage_administrators();
				cout << endl << "\t\t\t\t\t Press crosspanding no : ";
				int sel;
				cin >> sel;
				if (sel == 1)
				{
					ad.enter(input_cnic(), ad);
					cout << "\t\t\t\t\t";
					system("pause");
					goto go_m_admin;
				}
				else if (sel == 2)
				{
					ad.display();
					cout << "\t\t\t\t\t";
					system("pause");
					goto go_m_admin;
				}
				else if (sel == 3)
				{
					ad.del(input_cnic());
					cout << "\t\t\t\t\t";
					system("pause");
					goto go_m_admin;
				}
				else if (sel == 0)
				{
					goto go_admin;
				}
				else
				{
					cout << "\t\t\t\t\t Invalide choise! ";
					system("pause");
					goto go_m_admin;
				}

			}
			else if (sel == 2)
			{
			go_m_can:
				system("CLS");
				manage_candidates();
				cout << endl << "\t\t\t\t\t Press crosspanding no : ";
				int sel;
				cin >> sel;
				if (sel == 1)
				{
					int a = vo.display_can_req();
					if (a == 0)
					{
						system("pause");
						goto go_m_can;
					}
					cout << endl << "\t\t\t\t\tEnter candidate number you make him/her candidate : ";
					int i;
					cin >> i;
					if (i > a || i == 0)
					{
						goto go_m_can;
					}
					vo.add_can(i);
					system("pause");
					goto go_m_can;
				}
				else if (sel == 2)
				{
					int a = vo.display_can();
					if (a == 0)
					{
						system("pause");
						goto go_m_can;
					}
					cout << endl << "\t\t\t\t\tEnter candidate number to delete candidate : ";
					int i;
					cin >> i;
					if (i == 0)
					{
						goto go_m_can;
					}
					vo.del_can(i);
					system("pause");
					goto go_m_can;
				}
				else if (sel == 0)
				{
					goto go_admin;
				}
				else
				{
					cout << "\t\t\t\t\t Invalide choise! ";
					system("pause");
					goto go_m_can;
				}
			}
			else if (sel == 3)
			{
			go_s_votting:
				system("CLS");
				votting();
				string no = input_cnic();
				if (no == "14206")
				{
					cout << "\t\t\t\t\t Votting is ended now!";
					system("pause");
					goto result;
				}
				if (vo.what_can(no))
				{
					int a = vo.display_vote_can(no);
					if (a == 0)
					{
						system("pause");
						goto go_s_votting;
					}
					go_again:
					cout << endl << "\t\t\t\t\tEnter candidate number you want to vote : ";
					int i;
					cin >> i;
					if (i <= 0 || i > a)
					{
						cout << "\t\t\t\t\t Invalid Entry! ";
						system("pause");
						goto go_again;
					}
					vo.cast_vote(i , no);
					system("pause");
					goto go_s_votting;
				}
				else
				{
					cout << "\t\t\t\t\t For some reason you can not cast a vote! ";
					system("pause");
					goto go_s_votting;
				}
			}
			else if (sel == 5)
			{
			go_m_voter:
				system("CLS");
				manage_voter();
				cout << endl << "\t\t\t\t\t Press crosspanding no : ";
				int sel;
				cin >> sel;
				if (sel == 1)
				{
					string cnic = input_cnic();
					cout << "\t\t\t\t\t Enter your name please : ";
					string name;
					cin >> name;
					cout << "\t\t\t\t\t Enter your age please : ";
					int age;
					cin >> age;
					vo.enter(name, cnic, age, vo);
					system("pause");
					goto go_m_voter;
				}
				else if (sel == 2)
				{
					vo.del(input_cnic());
					system("pause");
					goto go_m_voter;
				}
				else if (sel == 4)
				{
					vo.Search(input_cnic());
					system("pause");
					goto go_m_voter;
				}
				else if (sel == 3)
				{
					vo.display();
					system("pause");
					goto go_m_voter;
				}
				else if (sel == 0)
				{
					goto go_admin;
				}
				else
				{
					cout << "\t\t\t\t\t Invalide choise! ";
					system("pause");
					goto go_m_voter;
				}

			}
			else if (sel == 4)
			{
				result:
				vo.display_result();
				vo.start();
				system("pause");
				goto go_admin;
			}
			else if (sel == 0)
			{
				goto go_user;
			}
			else
			{
				cout << "\t\t\t\t\t Invalide choise! ";
				system("pause");
				goto go_admin;
			}
		}
		else
		{
			cout << "\t\t\t\t\t This CNIC is not exist! ";
			system("pause");
			goto go_user;
		}
	}
	else if (sel == 2)
	{
		string cnic = input_cnic();
		bool check = vo.what(cnic);
		if (check)
		{
		go_voter:
			system("CLS");
			voter();
			cout << endl << "\t\t\t\t\t Press crosspanding no : ";
			int sel;
			cin >> sel;
			if (sel == 1)
			{
				cout << "\t\t\t\t\t Do want to be a candidate? (Y/N) : ";
				string ans;
				cin >> ans;
				if (ans == "Y" || ans == "y")
				{
					vo.can(cnic);
					system("pause");
					goto go_voter;
				}
				else if (ans == "N" || ans == "n")
				{
					goto go_voter;
				}
				else
				{
					cout << "\t\t\t\t\t Invalide choise! ";
					system("pause");
					goto go_voter;
				}
			}
			else if (sel == 2)
			{
				cout << "\t\t\t\t\t Do want to withdraw form candidate? (Y/N) : ";
				string ans;
				cin >> ans;
				if (ans == "Y" || ans == "y")
				{
					vo.notcan(cnic);
					system("pause");
					goto go_voter;
				}
				else if (ans == "N" || ans == "n")
				{
					goto go_voter;
				}
			}
			else if (sel == 0)
			{
				goto go_user;
			}
			else
			{
				cout << "\t\t\t\t\t Invalide choise! ";
				system("pause");
				goto go_voter;
			}
		}
		else
		{
			cout << "\t\t\t\t\t This CNIC is not exist! ";
			system("pause");
			goto go_user;
		}
	}
	else if (sel == 3)
	{
		system("CLS");
		help();
		cout << endl;
		system("pause");
		goto go_user;
	}
	else if (sel == 4)
	{
		system("CLS");
		about();
		cout << endl;
		system("pause");
		goto go_user;
	}
	else if (sel == 0)
	{
		go_end:
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\tThank you!";
		system("pause");
		return 0;
	}
	else
	{
		cout << "\t\t\t\t\t Invalide choise! ";
		system("pause");
		goto go_user;
	}
	return 0;
}
