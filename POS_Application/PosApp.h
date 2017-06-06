//OOP244 Final Project
// File PosApp.h
// Version 1.0
// Date 13th April, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// PosApp uses the previously created classes to manage the items in store and also works as a Point Of Sale system to
// sell the items to customers

#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__
#include "Item.h"
#include "Error.h"
#include "Date.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "POS.h"
#include "PosIO.h"

namespace ict {
	class PosApp {

		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;
		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isPerishable);
		void listItems()const;
		void truncateBillFile();
		void showBill();
		void addToBill(Item& I);
		void POS();

	public:
		PosApp(const char* filename, const char* billfname);
		PosApp(const PosApp& P) = delete;
		PosApp& operator=(const PosApp& P) = delete;
		void run();
	};
}

#endif
