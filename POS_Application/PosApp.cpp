
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "PosApp.h"
#include "Item.h"
#include "Error.h"
#include "Date.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "POS.h"
#include "PosIO.h"

using namespace std;
namespace ict {
	int PosApp::menu()
	{
		int selection;
		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add Perishable item" << endl;
		cout << "3- Add Non-Perishable item" << endl;
		cout << "4- Update item quantity" << endl;
		cout << "5- Show Item" << endl;
		cout << "6- POS" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";
		cin >> selection;
		cout << endl;
		cin.ignore(2000, '\n');
		if (cin.fail())
		{
			selection = -1;
		}
		if (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6 && selection != 0)
		{
			selection = -1;
		}
		
		return selection;
	}
	void PosApp::deallocateItems()
	{
		for (int i = 0; i < m_noOfItems; i++)
		{
			delete m_items[i];
			m_items[i] = nullptr;
		}
		m_noOfItems = 0;
	}
	void PosApp::loadRecs()
	{
		this->deallocateItems();
		std::fstream loadFromFile(this->m_filename, std::ios::in);
		if (!loadFromFile.is_open())
		{
			loadFromFile.clear();
			loadFromFile.close();
			loadFromFile.open(this->m_filename, std::ios::out);
		}
		else
		{
			while (!loadFromFile.eof())
			{
				char c1, c2;
				loadFromFile >> c1 >> c2;
				if (c1 == 'N')
				{
					NonPerishable* P = new NonPerishable;
					P->load(loadFromFile);
					m_items[m_noOfItems] = P;
					m_noOfItems++;
				}
				if (c1 == 'P')
				{
					Perishable* P = new Perishable;
					P->load(loadFromFile);
					m_items[m_noOfItems] = P;
					m_noOfItems++;
				}
				c1 = ' ';
			}
		}
		loadFromFile.close();
	}
	void PosApp::saveRecs()
	{
		std::fstream saveToFile(this->m_filename, std::ios::out);
		for (int i = 0; i < m_noOfItems; i++)
		{
			if (m_items[i]->quantity() > 0)
			{
				m_items[i]->save(saveToFile);
				saveToFile << endl;
			}
		}
		saveToFile.close();
		this->loadRecs();
	}
	int PosApp::searchItems(const char * sku) const
	{
		int index = -1;
		for (int i = 0; i < m_noOfItems; i++)
		{
			if (*m_items[i] == sku)
			{
				index = i;
			}
		}
		return index;
	}
	void PosApp::updateQty()
	{
		char* s;
		std::string str;
		cout << "Please enter the SKU: ";
		std::getline(std::cin, str);
		s = new char[str.length() + 1];
		std::strcpy(s, str.c_str());
		int result = searchItems(s);
		if (result == -1)
		{
			cout << "Not found!" << endl;
		}
		else
		{
			int quantity;
			int stock = m_items[result]->quantity();
			m_items[result]->write(cout, false); 
			cout << endl;
			cout << "Please enter the number of purchased items: ";
			cin >> quantity;
			stock += quantity;
			m_items[result]->quantity(stock);
			saveRecs();
			cout << "Updated!" << endl << endl;
		}
		delete[] s;
	}
	void PosApp::addItem(bool isPerishable)
	{
		if (isPerishable)
		{
			Perishable* P = new Perishable;
			cin >> *P;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << *P;
			}
			else
			{
				m_items[m_noOfItems] = P;
				m_noOfItems++;
				saveRecs();
				cout << "Item added." << endl << endl;
			}
		}
		else
		{
			NonPerishable* P = new NonPerishable;
			cin >> *P;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << *P;
			}
			else
			{
				m_items[m_noOfItems] = P;
				m_noOfItems++;
				saveRecs();
				cout << "Item added." << endl << endl;
			}
		}
	}
	void PosApp::listItems() const
	{
		double total = 0;
		cout << " Row " <<"|";
		cout << " SKU    " << "|";
		cout << " Item Name          " << "|";
		cout << " Price " << "|";
		cout << "TX " << "|";
		cout << "Qty " << "|";
		cout << "   Total " << "|" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++)
		{
			cout.width(4);
			cout.setf(ios::right);
			cout << i + 1 << " | ";
			cout.unsetf(ios::right);
			m_items[i]->write(cout, true);
			cout << endl;
			total += ((m_items[i]->cost()) * (m_items[i]->quantity()));
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout.width(48);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << "Total Asset: $  |";
		cout.width(14);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << total << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl << endl;
		cout.unsetf(ios::right);
	}
	void PosApp::truncateBillFile()
	{
		std::fstream truncate(m_billfname, std::ios::out | std::ios::trunc);
		truncate.close();
	}
	void PosApp::showBill()
	{
		std::fstream bill(m_billfname, std::ios::in);
		if (!bill.is_open())
		{
			bill.clear();
			bill.close();
			bill.open(this->m_billfname, std::ios::out);
		}
		else
		{
			Date date;
			cout << "v--------------------------------------------------------v" << endl;
			cout << "| ";
			cout.fill(' ');
			//cout.width(55);
			cout << date << "                                      |" << endl;
			double total = 0;
			cout << "|";
			cout << " SKU    " << "|";
			cout << " Item Name          " << "|";
			cout << " Price " << "|";
			cout << "TX " << "|";
			cout << "Qty " << "|";
			cout << "   Total " << "|" << endl;
			cout << "|--------|--------------------|-------|---|----|---------|" << endl;
			while (!bill.fail())
			{
				char c1, c2;
				bill >> c1 >> c2;
				if (c1 == 'N')
				{
					NonPerishable* P = new NonPerishable;
					P->load(bill);	
					cout << "| ";
					cout.fill(' ');
					P->write(cout, true);
					cout << endl;
					total += (P->cost() * P->quantity());
					delete P;
				}
				if (c1 == 'P')
				{
					Perishable* P = new Perishable;
					P->load(bill);
					cout << "| ";
					cout.fill(' ');
					P->write(cout, true);
					cout << endl;
					total += (P->cost() * P->quantity());
					delete P;
				}
				c1 = ' ';
			}
			bill.close();
			truncateBillFile();
			cout << "^--------^--------------------^-------^---^----^---------^" << endl;
			cout << "|";
			cout.fill(' ');
			cout.width(42);
			cout.setf(ios::right);
			cout << "Total: $  |";
			cout.width(14);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << total << "|" << endl;
			cout << "^-----------------------------------------^--------------^" << endl << endl;
			cout.unsetf(ios::right);
		}
	}
	void PosApp::addToBill(Item& I)
	{
		fstream add(m_billfname, std::ios::out | std::ios::app);
		int quantity = I.quantity();
		I.quantity(1);
		I.save(add);
		I.quantity(quantity - 1);
		saveRecs();
	}
	void PosApp::POS()
	{
		//std::fstream bill(m_billfname, std::ios::out | std::ios::app);
		char sku[MAX_SKU_LEN + 1];
		int index;
		do
		{
			cout << "Sku: ";
			cin.getline(sku, (MAX_SKU_LEN + 1), '\n');
			index = searchItems(sku);
			if (sku[0] != '\0')
			{
				if (index > -1)
				{

					//m_items[index]->save(bill);
					cout << "v------------------->" << endl;
					cout << "| " << m_items[index]->name() << endl;
					addToBill(*m_items[index]);
					cout << "^------------------->" << endl;
				}
				else
				{
					cout << "Not found!" << endl;
				}
			}
		} while (sku[0] != '\0');

		if (sku[0] == '\0')
		{
			showBill();
		}
	}
	PosApp::PosApp(const char * filename, const char * billfname)
	{
		strcpy(m_filename, filename);
		strcpy(m_billfname, billfname);
		loadRecs();
	}
	void PosApp::run()
	{
		int selection;
		do
		{
			selection = menu();
			if (selection == 1)
			{
				listItems();
			}
			else if (selection == 2)
			{
				addItem(true);
			}
			else if (selection == 3)
			{
				addItem(false);
			}
			else if (selection == 4)
			{
				updateQty();
			}
			else if (selection == 5)
			{
				int index;
				char sku[MAX_SKU_LEN + 1];
				cout << "Please enter the SKU: ";
				cin.getline(sku, (MAX_SKU_LEN + 1), '\n');
				index = searchItems(sku);
				if (index > 0)
				{
					cout << "v-----------------------------------v" << endl;
					m_items[index]->write(cout, false);
					cout << "^-----------------------------------^" << endl << endl;
				}
				else 
				{
					cout << "Not found!" << endl << endl;
				}
			}
			else if (selection == 6)
			{
				POS();
			}
			else if (selection == 0)
			{
				cout << "Goodbye!" << endl;
			}
			else
			{
				cout << "===Invalid Selection, try again===" << endl;
			}
		} while (selection != 0);
	}
}



/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/


