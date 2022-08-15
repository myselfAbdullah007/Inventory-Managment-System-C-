//Created by Abdullah Chaudhary
// insta || @oye_abdullahhh
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Header.h"
using namespace std;

//Display SHopkeeper Data
	void Shopkeeper::DisplayShopkeeper(Shopkeeper shopObj[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\n\t\t\t\tShopKeeper : " << i + 1 << endl << endl;
			cout << "\t\t\t\t\t\tFirst Name        : " << shopObj[i].firstName << endl;
			cout << "\t\t\t\t\t\tLast Name         : " << shopObj[i].LastName << endl;
			cout << "\t\t\t\t\t\tShopkeeper ID     : " << shopObj[i].sId << endl;
			cout << "\t\t\t\t\t\tUserName          : " << shopObj[i].Username << endl;
			cout << "\t\t\t\t\t\tEmail             : " << shopObj[i].Email << endl;
			cout << "\t\t\t\t\t\tPassword          : " << shopObj[i].Password << endl;
			cout << "\t\t\t\t\t\tRegistration Date : " << shopObj[i].RegDate << endl;
			cout << "\t\t\t\t\t\tGender            : " << shopObj[i].Gender << endl;
			cout << "\t\t\t\t\t\tBlood Group " << shopObj[i].BG << endl;
			cout << "\t\t\t\t\t\tContact Number    : " << shopObj[i].ContactNo << endl;
			cout << "\t\t\t\t\t\tAddress           : " << shopObj[i].Address << endl;
		}
	}

	//Serch Shopkeeper and return that particular index

	int Shopkeeper::SearchShopkeeper(Shopkeeper arr[], int size)
	{
		string id;
		cout << "\t\t\t\t\t\tEnter Shopkeeper ID : ";
		cin >> id;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].sId == id)
				return i;
		}
		cout << "\t\t\t\t\t\tNo Such Profile Exixst\n\n\t\t\t\t\t\tReTry\n";
		return -1;
	}
//Print all registered Customers
	void Customer::DisplayCustomer(Customer cusObj[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\t\t\t\t\t\tFirst Name        : " << cusObj[i].cfirstName << endl;
			cout << "\t\t\t\t\t\tLast Name         : " << cusObj[i].cLastName << endl;
			cout << "\t\t\t\t\t\tCustomer ID       : " << cusObj[i].cID << endl;
			cout << "\t\t\t\t\t\tUserName          : " << cusObj[i].cUserName << endl;
			cout << "\t\t\t\t\t\tEmail             : " << cusObj[i].cEmail << endl;
			cout << "\t\t\t\t\t\tPassword          : " << cusObj[i].cPass << endl;
			cout << "\t\t\t\t\t\tRegistration Date : " << cusObj[i].cregDate << endl;
			cout << "\t\t\t\t\t\tGender            : " << cusObj[i].cgender << endl;
			cout << "\t\t\t\t\t\tBlood Group       : " << cusObj[i].cBG << endl;
			cout << "\t\t\t\t\t\tContact No.       : " << cusObj[i].ccontactNo << endl;
			cout << "\t\t\t\t\t\tAddress           : " << cusObj[i].caddress << endl;
		}
	}

		//Serach any customer by its id and return that index

	int Customer::SearchCustomer(Customer arr[], int size)
	{
		string id;
		cout << "\t\t\t\t\t\tEnter Customer ID : ";
		cin >> id;
		for (int i = 0; i < size; i++)
		{
			if (id == arr[i].cID)
			{
				return i;
			}
		}
		cout << "\t\t\t\t\t\tNo Such Profile Exist\n\n";
		return -1;
	}
		//Print all added Products
	void Product::DisplayProduct(Product ProObj[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\t\t\t\tProduct : " << i + 1 << " :\n";
			cout << "\t\t\t\t\t\tProduct ID        : " << ProObj[i].pID << endl;
			cout << "\t\t\t\t\t\tProduct Name      : " << ProObj[i].name << endl;
			cout << "\t\t\t\t\t\tCategory          : " << ProObj[i].categoryName << endl;
			cout << "\t\t\t\t\t\tProduct Size      : " << ProObj[i].size << endl;
			cout << "\t\t\t\t\t\tProduct Color     : " << ProObj[i].color << endl;
			cout << "\t\t\t\t\t\tProduct Quantity  : " << ProObj[i].quantity << endl;
			cout << "\t\t\t\t\t\tDescription       : " << ProObj[i].description << endl;

		}
	}


		//Function to add product details to filee
	void Product::AddProduct()
	{
		cout << "\t\t\t\t\t\tEnter Product Name : ";
		getline(cin,name);
		getline(cin, name);
		cout << "\t\t\t\t\t\tEnter Category Name : \n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\t\t\t\t\t\t" << i + 1 << " )\t" << cN[i] << endl;
		}
		cin >> categoryName;
		cout << "\n\n";
		cout << "\n\t\t\t\t\t\tEnter Description : ";
		getline(cin,description);
		getline(cin, description);
		pID = to_string(++TotalProduct);
		setProductID();
		cout << "\t\t\t\t\t\tEnter Size : ";
		cin >> size;
		cout << "\t\t\t\t\t\tEnter color : ";
		cin >> color;
		cout << "\t\t\t\t\t\tEnter Quantity : ";
		cin >> quantity;

		//Storing in file
		fstream file;
		file.open("product.txt", ios::app);

		file << name << endl << categoryName << endl << description << endl;
		file << pID << endl << size << endl << color << endl << quantity << endl;

		file.close();
		cout << "\t\t\t\t\t\tPRODUCT ADDED SUCCESFULLY!\n";
	}

		//Set Product ID by its category and product Number
	void Product::setProductID()
	{
		int n = pID.length();
		if (n == 1)
			pID = "0" + category + "000" + pID;
		else if (n == 2)
			pID = "0" + category + "00" + pID;
		else if (n == 3)
			pID = "0" + category + "0" + pID;
		else
			pID = "0" + category + pID;
	}


		//Serach Product by Id and return that particular index

	int Product::SearchProduct(Product arr[], int size)
	{
		string id;
		cout << "Enter Product ID : ";
		cin >> id;
		for (int i = 0; i < size; i++)
		{
			if (id == arr[i].pID)
			{
				cout << "Index returned * " << i << endl;
				return i;
			}
		}
		cout << "No Such Product Exist\n\n";
		return -1;
	}

		//Function to Get data from file then Edit it and then store back data to file
	void Product::EditProduct()
	{
		int index = -1;
		Product* arr;
		arr = new Product[TotalProduct];
		string line;
		fstream file;
		//Getting data from file
		file.open("product.txt", ios::in);
		for (int i = 0; i < TotalProduct; i++)
		{
			getline(file, arr[i].name);
			getline(file, arr[i].categoryName);
			getline(file, arr[i].description);
			getline(file, arr[i].pID);
			getline(file, arr[i].size);
			getline(file, arr[i].color);
			getline(file, arr[i].quantity);
		}
		file.close();
		DisplayProduct(arr, TotalProduct);
		//Editing Data
		while (index == -1)
		{
			index = SearchProduct(arr, TotalProduct);
			if (index != -1)
			{
				cout << "\t\t\t\t\t\tEnter Name : ";
				getline(cin,arr[index].name);
				getline(cin, arr[index].name);
				cout << "\t\t\t\t\t\tEnter description : ";
				getline(cin,arr[index].description);
				getline(cin, arr[index].description);
				cout << "\t\t\t\t\t\tEnter Quantity : ";
				cin >> arr[index].quantity;
				cout << "\t\t\t\t\t\tEnter Size : ";
				cin >> arr[index].size;
				cout << "\t\t\t\t\t\tEnter color : ";
				cin >> arr[index].color;
				cout << "\n\t\t\t\t\t\tProduct Information Updated\n";
				break;
			}
			else
			{
				int ch;
				cout << "1.) Exit\n2.) ReSearch \nEnter : ";
				cin >> ch;
				if (ch == 1)
					break;
			}
		}

		//Storing back to file
		file.open("product.txt", ios::out);
		for (int i = 0; i < TotalProduct; i++)
		{
			file << arr[i].name << endl;
			file << arr[i].categoryName << endl;
			file << arr[i].description << endl;
			file << arr[i].pID << endl;
			file << arr[i].size << endl;
			file << arr[i].color << endl;
			file << arr[i].quantity << endl;
		}
		file.close();
	}

	//////////////////////////   Admin class Functions  /////////////////////////////////////////////////////////////////////////////////////////////

	
	AdministratorModule::AdministratorModule() {}
		//Function to register new Admin
		void AdministratorModule::SignUp()
		{
			string Email, Passcode, Username;
			fstream file;

			cout << "\t\t\tEnter Email : ";
			cin >> Email;
			cout << "\t\t\tEnter Password : ";
			cin >> Passcode;
			cout << "\t\t\tEnter User Name : ";
			cin >> Username;

			file.open("Admin.txt", ios::app);
			file << Email << endl;
			file << Passcode << endl;
			file << Username << endl;
			file.close();
		}

		//Function for SignIn check weather particular email and pass is present in admin file or not
		int AdministratorModule::SignIn(AdministratorModule obj[], int ind)
		{
			string u, p;
			bool found = false;
			cout << "\t\t\tEnter UserName : ";
			cin >> u;
			cout << "\t\t\tEnter Password : ";
			cin >> p;
			for (int i = 0; i < ind - 1; i++)
			{
				if (u == obj[i].username && p == obj[i].password)
				{
					cout << "\t\t\t\t\t\tSignIn Successfull\n";
					return i;
					found = true;
				}
			}
			cout << "\t\t\t\t\tNo Such Profile for Admin Exist\n\n";
			return -1;
		}

		//Add shopkeeper Information to file

		void AdministratorModule::AddShopkeeper()
		{
			cout << "\t\t\t\t\t\tEnter First Name : ";
			cin >> firstName;
			cout << "\t\t\t\t\t\tEnter Last Name : ";
			cin >> LastName;
			sId = to_string(++TotalShopkeeper);
			cout << "\t\t\t\t\t\tId : " << sId << endl;
			cout << "\t\t\t\t\t\tEnter User Name : ";
			cin >> Username;
			cout << "\t\t\t\t\t\tEnter Email : ";
			cin >> Email;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> Password;
			cout << "\t\t\t\t\t\tEnter Date of Registration : ";
			cin >> RegDate;
			cout << "\t\t\t\t\t\tEnter Gender : ";
			cin >> Gender;
			cout << "\t\t\t\t\t\tEnter Blood Group : ";
			cin >> BG;
			cout << "\t\t\t\t\t\tEnter Contact Number : ";
			cin >> ContactNo;
			cout << "\t\t\t\t\t\tEnter Address : ";
			cin >> Address;

			//storing to File
			fstream file;
			file.open("shopkeeper.txt", ios::app);

			file << firstName << endl << LastName << endl << sId << endl << Username << endl;
			file << Email << endl << Password << endl << RegDate << endl;
			file << Gender << endl << BG << endl << ContactNo << endl << Address << endl;
			file.close();
			cout << "\t\t\t\t\t\tSHOPKEEPER ADDED SUCCESFULLY!\n";
		}

		//Adding Customer Informatrion into the file
		void AdministratorModule::AddCustomer()
		{

			cout << "\t\t\t\t\t\tEnter First Name : ";
			cin >> cfirstName;
			cout << "\t\t\t\t\t\tEnter Last Name : ";
			cin >> cLastName;
			cID = to_string(++TotalCustomer);
			cout << "\t\t\t\t\t\tEnter User Name : ";
			cin >> cUserName;
			cout << "\t\t\t\t\t\tEnter Email : ";
			cin >> cEmail;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> cPass;
			cout << "\t\t\t\t\t\tEnter Registration D : ";
			cin >> cregDate;
			cout << "\t\t\t\t\t\tEnter Gender : ";
			cin >> cgender;
			cout << "\t\t\t\t\t\tEnter Blood Group : ";
			cin >> cBG;
			cout << "\t\t\t\t\t\tEnter Contact Number : ";
			cin >> ccontactNo;
			cout << "\t\t\t\t\t\tEnter Address : ";
			cin >> caddress;
			cout << "\t\t\t\t\t\tEnter Category of Products : ";
			cin >> Category;
			cout << "\t\t\t\t\t\tEnetr Number of Products : ";
			cin >> noOfProducts;
			cout << "\t\t\t\t\t\tBill Paid Status (Yes / No) : ";
			cin >> billStatus;

			//storing to File

			fstream file;
			file.open("customer.txt", ios::app);

			file << cfirstName << endl << cLastName << endl << cID << endl << cUserName << endl;
			file << cEmail << endl << cPass << endl << cregDate << endl;
			file << cgender << endl << cBG << endl << ccontactNo << endl << caddress << endl;

			file.close();
			cout << "Customer Added\n";
		}


		//Get data from file,edit and store back to file
		void AdministratorModule::EditShopkeeper()
		{
			int index = -1;
			Shopkeeper* arr;

			arr = new Shopkeeper[TotalShopkeeper];
			string line;
			fstream file;

			file.open("shopkeeper.txt", ios::in);


			////  Getting Data from file

			for (int i = 0; i < TotalShopkeeper; i++)
			{
				getline(file, arr[i].firstName);
				getline(file, arr[i].LastName);
				getline(file, arr[i].sId);
				getline(file, arr[i].Username);
				getline(file, arr[i].Email);
				getline(file, arr[i].Password);
				getline(file, arr[i].RegDate);
				getline(file, arr[i].Gender);
				getline(file, arr[i].BG);
				getline(file, arr[i].ContactNo);
				getline(file, arr[i].Address);
			}
			file.close();

			//Editing 
			DisplayShopkeeper(arr, TotalShopkeeper);
			while (index == -1)
			{
				index = SearchShopkeeper(arr, TotalShopkeeper);
				if (index != -1)
				{
					cout << "\t\t\t\t\t\tEnter First Name : ";
					cin >> arr[index].firstName;
					cout << "\t\t\t\t\t\tEnter Last Name : ";
					cin >> arr[index].LastName;
					cout << "\t\t\t\t\t\tEnter Address : ";
					cin >> arr[index].Address;
					cout << "\t\t\t\t\t\tEnter Contact No. : ";
					cin >> arr[index].ContactNo;
					cout << "\t\t\t\t\t\tEnter UserName : ";
					cin >> arr[index].Username;
					cout << "\t\t\t\t\t\tEnter Email : ";
					cin >> arr[index].Email;
					cout << "\t\t\t\t\t\tEnter Password : ";
					cin >> arr[index].Password;
				}
				else
				{
					int ch;
					cout << "\t\t\t\t\t\t1.) Exit\n\t\t\t\t\t\t2.) ReSearch \n\n\t\t\t\t\t\tEnter : ";
					cin >> ch;
					if (ch == 1)
						break;
				}
			}

			//Storing back to file
			file.open("shopkeeper.txt", ios::out);

			for (int i = 0; i < TotalShopkeeper; i++)
			{
				file << arr[i].firstName << endl;
				file << arr[i].LastName << endl;
				file << arr[i].sId << endl;
				file << arr[i].Username << endl;
				file << arr[i].Email << endl;
				file << arr[i].Password << endl;
				file << arr[i].RegDate << endl;
				file << arr[i].Gender << endl;
				file << arr[i].BG << endl;
				file << arr[i].ContactNo << endl;
				file << arr[i].Address << endl;
			}
			file.close();
		}


		//Take data from file,edit and store back
		void AdministratorModule::EditCustomer()
		{
			int index = -1;
			Customer* arr;
			arr = new Customer[TotalCustomer];
			string line;
			fstream file;

			////  Getting Data from file
			file.open("customer.txt", ios::in);
			for (int i = 0; i < TotalCustomer; i++)
			{
				getline(file, arr[i].cfirstName);
				getline(file, arr[i].cLastName);
				getline(file, arr[i].cID);
				getline(file, arr[i].cUserName);
				getline(file, arr[i].cEmail);
				getline(file, arr[i].cPass);
				getline(file, arr[i].cregDate);
				getline(file, arr[i].cgender);
				getline(file, arr[i].cBG);
				getline(file, arr[i].ccontactNo);
				getline(file, arr[i].caddress);
			}
			file.close();
			DisplayCustomer(arr, TotalCustomer);

			while (index == -1)
			{
				index = SearchCustomer(arr, TotalCustomer);
				if (index != -1)
				{
					cout << "\t\t\t\t\t\tEnter First Name : ";
					cin >> arr[index].cfirstName;
					cout << "\t\t\t\t\t\tEnter Last Name : ";
					cin >> arr[index].cLastName;
					cout << "\t\t\t\t\t\tEnter Address : ";
					cin >> arr[index].caddress;
					cout << "\t\t\t\t\t\tEnter Contact No. : ";
					cin >> arr[index].ccontactNo;
					cout << "\t\t\t\t\t\tEnter UserName : ";
					cin >> arr[index].cUserName;
					cout << "\t\t\t\t\t\tEnter Email : ";
					cin >> arr[index].cEmail;
					cout << "\t\t\t\t\t\tEnter Password : ";
					cin >> arr[index].cPass;
					cout << "\n\t\t\t\t\t\tCustomer Information Updated\n";
					break;
				}
				else
				{
					int ch;
					cout << "\t\t\t\t\t\t1.) Exit\n\t\t\t\t\t\t2.) ReSearch \n\n\t\t\t\t\t\tEnter : ";
					cin >> ch;
					if (ch == 1)
						break;
				}
			}
			//Storing back
			file.open("customer.txt", ios::out);

			for (int i = 0; i < TotalCustomer; i++)
			{
				file << arr[i].cfirstName << endl;
				file << arr[i].cLastName << endl;
				file << arr[i].cID << endl;
				file << arr[i].cUserName << endl;
				file << arr[i].cEmail << endl;
				file << arr[i].cPass << endl;
				file << arr[i].cregDate << endl;
				file << arr[i].cgender << endl;
				file << arr[i].cBG << endl;
				file << arr[i].ccontactNo << endl;
				file << arr[i].caddress << endl;
			}

			file.close();

		}

		//Function to get data from File and delete particular shopkeeper
		void AdministratorModule::DeleteShopkeeper()
		{
			int index = -1, cont = -1;
			Shopkeeper* arr;

			arr = new Shopkeeper[TotalShopkeeper];
			string line;
			fstream file;
			cout << "ShopK : " << TotalShopkeeper << endl;
			file.open("shopkeeper.txt", ios::in);


			////  Getting Data from file

			for (int i = 0; i < TotalShopkeeper; i++)
			{
				getline(file, arr[i].firstName);
				getline(file, arr[i].LastName);
				getline(file, arr[i].sId);
				getline(file, arr[i].Username);
				getline(file, arr[i].Email);
				getline(file, arr[i].Password);
				getline(file, arr[i].RegDate);
				getline(file, arr[i].Gender);
				getline(file, arr[i].BG);
				getline(file, arr[i].ContactNo);
				getline(file, arr[i].Address);
			}
			file.close();


			DisplayShopkeeper(arr, TotalShopkeeper);

			while (index == -1)
			{
				cont = index = SearchShopkeeper(arr, TotalShopkeeper);
				if (index != -1)
				{
					cout << "\t\t\t\t\t\tShopkeeper Deleted\n";
					TotalShopkeeper--;
					break;
				}
				else
				{
					int ch;
					cout << "\t\t\t\t\t\t1.) Exit\n\t\t\t\t\t\t2.) ReSearch \n\t\t\t\t\t\tEnter : ";
					cin >> ch;
					if (ch == 1)
						break;
				}
			}

			//Storing back

			file.open("shopkeeper.txt", ios::out);

			for (int i = 0; i < TotalShopkeeper; i++)
			{
				if (cont != -1 && cont == i)
					continue;
				file << arr[i].firstName << endl;
				file << arr[i].LastName << endl;
				file << arr[i].sId << endl;
				file << arr[i].Username << endl;
				file << arr[i].Email << endl;
				file << arr[i].Password << endl;
				file << arr[i].RegDate << endl;
				file << arr[i].Gender << endl;
				file << arr[i].BG << endl;
				file << arr[i].ContactNo << endl;
				file << arr[i].Address << endl;
			}
			file.close();
		}

		//Function to get data from File and delete particular Customer
		void AdministratorModule::DeleteCustomer()
		{
			int index = -1, cont = -1;
			Customer* arr;
			arr = new Customer[TotalCustomer];
			string line;
			fstream file;
			file.open("customer.txt", ios::in);
			for (int i = 0; i < TotalCustomer; i++)
			{
				getline(file, arr[i].cfirstName);
				getline(file, arr[i].cLastName);
				getline(file, arr[i].cID);
				getline(file, arr[i].cUserName);
				getline(file, arr[i].cEmail);
				getline(file, arr[i].cPass);
				getline(file, arr[i].cregDate);
				getline(file, arr[i].cgender);
				getline(file, arr[i].cBG);
				getline(file, arr[i].ccontactNo);
				getline(file, arr[i].caddress);
			}
			file.close();
			DisplayCustomer(arr, TotalCustomer);

			while (index == -1)
			{
				cont = index = SearchCustomer(arr, TotalCustomer);
				if (index != -1)
				{
					TotalCustomer--;
					cout << "\nCustomer Deleted\n";
					break;
				}
				else
				{
					int ch;
					cout << "1.) Exit\n2.) ReSearch \nEnter : ";
					cin >> ch;
					if (ch == 1)
						break;
				}
			}

			file.open("customer.txt", ios::out);

			for (int i = 0; i < TotalCustomer; i++)
			{
				if (cont != -1 && cont == i)
					continue;
				file << arr[i].cfirstName << endl;
				file << arr[i].cLastName << endl;
				file << arr[i].cID << endl;
				file << arr[i].cUserName << endl;
				file << arr[i].cEmail << endl;
				file << arr[i].cPass << endl;
				file << arr[i].cregDate << endl;
				file << arr[i].cgender << endl;
				file << arr[i].cBG << endl;
				file << arr[i].ccontactNo << endl;
				file << arr[i].caddress << endl;
			}

			file.close();
		}


		void AdministratorModule::DeleteProduct()
		{
			int index = -1, cont = -1;
			Product* arr;
			arr = new Product[TotalProduct];
			string line;
			fstream file;

			file.open("product.txt", ios::in);
			for (int i = 0; i < TotalProduct; i++)
			{
				getline(file, arr[i].name);
				getline(file, arr[i].categoryName);
				getline(file, arr[i].description);
				getline(file, arr[i].pID);
				getline(file, arr[i].size);
				getline(file, arr[i].color);
				getline(file, arr[i].quantity);
			}
			file.close();
			DisplayProduct(arr, TotalProduct);
			while (index == -1)
			{
				cont = index = SearchProduct(arr, TotalProduct);
				if (index != -1)
				{
					TotalProduct--;
					cout << "\n\t\t\t\t\t\tProduct Deleted\n";
					break;
				}
				else
				{
					int ch;
					cout << "\t\t\t\t\t\t1.) Exit\n\t\t\t\t\t\t2.) ReSearch \n\t\t\t\t\t\tEnter : ";
					cin >> ch;
					if (ch == 1)
						break;
				}
			}

			file.open("product.txt", ios::out);
			for (int i = 0; i < TotalCustomer; i++)
			{
				if (cont != -1 && cont == i)
				{
					continue;
				}
				file << arr[i].name << endl;
				file << arr[i].categoryName << endl;
				file << arr[i].description << endl;
				file << arr[i].pID << endl;
				file << arr[i].size << endl;
				file << arr[i].color << endl;
				file << arr[i].quantity << endl;
			}
			file.close();
		}

		ShopkeeperModule::ShopkeeperModule() {}
			//Adding data into file
		void ShopkeeperModule::SignUp()
		{
			string firstName, LastName, sId;
			string Username, Email, Password, RegDate, Gender, BG, ContactNo, Address;
			cout << "\t\t\t\t\t\tEnter First Name : ";
			cin >> firstName;
			cout << "\t\t\t\t\t\tEnter Last Name : ";
			cin >> LastName;
			sId = to_string(++TotalShopkeeper);
			cout << "\t\t\t\t\t\tId : " << sId << endl;
			cout << "\t\t\t\t\t\tEnter User Name : ";
			cin >> Username;
			cout << "\t\t\t\t\t\tEnter Email : ";
			cin >> Email;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> Password;
			cout << "\t\t\t\t\t\tEnter Date of Registration : ";
			getline(cin,RegDate);
			cout << "\t\t\t\t\t\tEnter Gender : ";
			cin >> Gender;
			cout << "\t\t\t\t\t\tEnter Blood Group : ";
			cin >> BG;
			cout << "\t\t\t\t\t\tEnter Contact Number : ";
			cin >> ContactNo;
			cout << "\t\t\t\t\t\tEnter Address : ";
			getline(cin,Address);
			getline(cin, Address);

			fstream file;
			file.open("shopkeeper.txt", ios::app);

			file << firstName << endl << LastName << endl << sId << endl << Username << endl;
			file << Email << endl << Password << endl << RegDate << endl;
			file << Gender << endl << BG << endl << ContactNo << endl << Address << endl;
			file.close();
			cout << "\t\t\t\t\t\tShopKeeper Added\n";
		}

			//Check weather email and pass are present in file and return index
		int ShopkeeperModule::SignIn(ShopkeeperModule arr[], int size)
		{
			string u, p;
			bool found = false;
			cout << "\t\t\t\t\t\tEnter UserName : ";
			cin >> u;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> p;
			for (int i = 0; i < size; i++)
			{
				if (u == arr[i].Username && p == arr[i].Password)
				{
					cout << "\t\t\t\t\t\tCondition SuccessFul\n";
					return i;
					found = true;
				}
			}
			if (!found)
				cout << "\t\t\t\t\t\tNo Such Profile for ShopKeeper Exist\n\n";
			return -1;
		}

		void ShopkeeperModule::ViewProduct()
		{
			Product* arr;
			arr = new Product[TotalProduct];
			string line;
			fstream file;

			file.open("product.txt", ios::in);
			for (int i = 0; i < TotalProduct; i++)
			{
				getline(file, arr[i].name);
				getline(file, arr[i].categoryName);
				getline(file, arr[i].description);
				getline(file, arr[i].pID);
				getline(file, arr[i].size);
				getline(file, arr[i].color);
				getline(file, arr[i].quantity);
			}
			file.close();
			DisplayProduct(arr, TotalProduct);
		}
		void CustomerModule::SignUp()
		{
			string firstName, LastName, ID, RegistrationDate, gender, ContactNo, bloodGroup, address, noOfProducts, Category, UserName, Email, Password;

			cout << "\t\t\t\t******Enter Credentials******";
			cout << "\n\t\t\t\t\t\tEnter First Name : ";
			cin >> firstName;
			cout << "\t\t\t\t\t\tEnter Last Name : ";
			cin >> LastName;
			cID = to_string(++TotalCustomer);
			cout << "ID : " << cID;
			cout << "\n\t\t\t\t\t\tEnter User Name : ";
			cin >> UserName;
			cout << "\t\t\t\t\t\tEnter Email : ";
			cin >> Email;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> Password;
			cout << "\t\t\t\t\t\tEnter Registration D : ";
			getline(cin,RegistrationDate);
			getline(cin, RegistrationDate);
			cout << "\t\t\t\t\t\tEnter Gender : ";
			cin >> gender;
			cout << "\t\t\t\t\t\tEnter Blood Group : ";
			cin >> bloodGroup;
			cout << "\t\t\t\t\t\tEnter Contact Number : ";
			cin >> ContactNo;
			cout << "\t\t\t\t\t\tEnter Address : ";
			getline(cin,address);
			getline(cin, address);
			fstream file;
			file.open("customer.txt", ios::app);

			file << firstName << endl << LastName << endl << cID << endl << UserName << endl;
			file << Email << endl << Password << endl << RegistrationDate << endl;
			file << gender << endl << bloodGroup << endl << ContactNo << endl << address << endl;

			file.close();
			cout << "Customer is Successfully  Added\n";
		}



			//signIn fucntions
		int CustomerModule::SignIn(CustomerModule arr[], int size)
		{
			string UserName, password;
			bool found = false;
			cout << "\n\t\t\t\t\t\tEnter UserName : ";
			cin >> UserName;
			cout << "\t\t\t\t\t\tEnter Password : ";
			cin >> password;
			for (int i = 0; i < size; i++)
			{
				if (UserName == arr[i].cUserName && password == arr[i].cPass)
				{
					cout << "\t\t\t\t\t\tSignIn SuccessFull" << endl;
					found = true;
					return i;
				}
				else
				{
					cout << "\t\t\t\t\t\tIncorrect username or password" << endl;
					return -1;
				}
			}
		}

		int CustomerModule::searchforPurchasing(Product obj[], int size)
		{
			string id;
			cout << "\t\t\t\t\t\tEnter Product ID to purchase : ";
			cin >> id;
			for (int i = 0; i < size; i++)
			{
				if (id == obj[i].pID)
				{
					return i;
				}
			}
			cout << "\t\t\t\t\t\tNo Such Product Exist";
			cout << endl;
			return -1;
		}

			//purchase product functions

		void CustomerModule::Purchase_a_Product(string id)
		{
			int n = -1, totalquantity = 0, choice;
			fstream file;
			Product* ptr;
			ptr = new Product[TotalProduct];


			file.open("product.txt", ios::in);
			for (int i = 0; i < TotalProduct; i++)
			{
				getline(file, ptr[i].name);
				getline(file, ptr[i].categoryName);
				getline(file, ptr[i].description);
				getline(file, ptr[i].pID);
				getline(file, ptr[i].size);
				getline(file, ptr[i].color);
				getline(file, ptr[i].quantity);
			}
			file.close();

			while (n == -1)
			{
				DisplayProduct(ptr, TotalProduct);
				n = searchforPurchasing(ptr, TotalProduct);
				if (n != -1)
				{
					while (true)
					{

						cout << "\t\t\t\t\t\tEnter Quantity : ";
						cin >> totalquantity;
						if (totalquantity > stoi(ptr[n].quantity))
						{
							cout << "\t\t\t\t\t\tThe stock is unavailable" << endl;
							cout << "\t\t\t\t\t\tsorry for an inconveneince" << endl;
							cout << "\t\t\t\t\t\t1.) ReEnter Quantity \n\t\t\t\t\t\t2.) Skip\n\t\t\t\t\t\t3.) Enter : ";
							cin >> choice;
							if (choice == 2)
								break;
						}
						else
						{

							//using stoi function that takes string and changes into int
							int q = stoi(ptr[n].quantity);
							q -= totalquantity;
							ptr[n].quantity = to_string(q);


							fstream filecart;
							filecart.open("addToCart.txt", ios::app);
							if (filecart.is_open())
							{
								cout << "\t\t\t\t\t\tProduct Added to Cart\n";
								filecart << id << endl;
								filecart << ptr[n].name << endl << ptr[n].categoryName << endl << ptr[n].description << endl;
								filecart << ptr[n].pID << endl << ptr[n].size << endl << ptr[n].color << endl << totalquantity << endl;
							}
							else
								cout << "\t\t\t\t\t\tFile not open\n";
							filecart.close();
							break;
						}
					}
					cout << "\n\t\t\t\t\t\t1.) Continue Shopping \n\t\t\t\t\t\t2.) Exit\n\n\t\t\t\t\t\tEnter : ";
					cin >> choice;
					if (choice == 1)
						n = -1;
					else
						n = 0;
					break;
				}
				else
				{
					int choice;
					cout << "\t\t\t\t\t\t1.) Exit\n\t\t\t\t\t\t2.) ReSearch \n\t\t\t\t\t\tEnter : ";
					cin >> choice;
					if (choice == 1)
						break;
				}
			}

			//filing

			file.open("product.txt", ios::out);

			for (int i = 0; i < TotalCustomer; i++)
			{
				file << ptr[i].name << endl;
				file << ptr[i].categoryName << endl;
				file << ptr[i].description << endl;
				file << ptr[i].pID << endl;
				file << ptr[i].size << endl;
				file << ptr[i].color << endl;
				file << ptr[i].quantity << endl;
			}
			file.close();
		}


			//add to cart functions
		void CustomerModule::AddtoCart(string id)
		{
			int del = 0;
			string line;
			fstream filecart;
			struct cart
			{
				string cid, nam, cN, des, pid, siz, clr, quant;
			};
			int n = -1, count = 0;
			cart* arr;
			fstream file;
			file.open("addToCart.txt", ios::in);
			while (getline(file, line))
			{
				count++;
			}
			count = count / 8;
			arr = new cart[count];
			file.close();
			file.open("addToCart.txt", ios::in);

			for (int i = 0; i < count; i++)
			{
				getline(file, arr[i].cid);
				getline(file, arr[i].nam);
				getline(file, arr[i].cN);
				getline(file, arr[i].des);
				getline(file, arr[i].pid);
				getline(file, arr[i].siz);
				getline(file, arr[i].clr);
				getline(file, arr[i].quant);
			}
			file.close();
			int choice;
			if (count > 0)
			{
				for (int i = 0; i < count; i++)
				{
					if (id == arr[i].cid)
					{
						//this will display all product added in cart
						cout << "\t\t\t\tProduct.no." << i + 1 << endl;
						cout << "\t\t\t\t\t\tProduct ID     : " << arr[i].cid << endl;
						cout << "\t\t\t\t\t\tProduct Name   : " << arr[i].nam << endl;
						cout << "\t\t\t\t\t\tCategory Name  : " << arr[i].cN << endl;
						cout << "\t\t\t\t\t\tDescription    : " << arr[i].des << endl;
						cout << "\t\t\t\t\t\tProduct ID     : " << arr[i].pid << endl;
						cout << "\t\t\t\t\t\tSize           : " << arr[i].siz << endl;
						cout << "\t\t\t\t\t\tColor          : " << arr[i].clr << endl;
						cout << "\t\t\t\t\t\tQuantity : " << arr[i].quant << endl;

						cout << "\n\t\t\t\t\t\t1.) Make change in Quantity \n\t\t\t\t\t\t2.) Delete\n\t\t\t\t\t\t3.) No Changes\n\t\t\t\t\t\tEnter : ";
						cin >> choice;

						//reading product
						if (choice == 1)
						{
							int q;
							cout << "\t\t\t\t\t\tEnter new Quantity : ";
							cin >> q;
							arr[i].quant = to_string(q);

						}

						//product removation
						else if (choice == 2)
						{
							del++;
							for (int j = i; j < count - 1; j++)
							{
								swap(arr[i], arr[i + 1]);
							}
							count--;
							cout << "\t\t\t\t\t\tProduct Removed from Cart\n";
						}
						if (choice == 3)
							continue;
					}
				}
				count = count - del;

				filecart.open("addToCart.txt", ios::out);
				for (int i = 0; i < count; i++)
				{
					filecart << arr[i].cid << endl;
					filecart << arr[i].nam << endl << arr[i].cN << endl << arr[i].des << endl;
					filecart << arr[i].pid << endl << arr[i].siz << endl << arr[i].clr << endl << arr[i].quant << endl;
				}
				filecart.close();
			}
			else
			{
				cout << "\t\t\t\t\t\tNo Product found in cart\n";
			}
		}


		void CustomerModule::CheckOut(string id)
		{
			int payment;
			float pCount = 0;
			string line;
			struct cart
			{
				string id, nam, cN, des, productId, size, clr, quant;
			};
			int index = -1, count = 0;
			cart* arr;
			fstream file;
			file.open("addToCart.txt", ios::in);
			while (getline(file, line))
			{
				count++;
			}
			count = count / 8;
			arr = new cart[count];
			file.close();
			file.open("addToCart.txt", ios::in);
			for (int i = 0; i < count; i++)
			{
				getline(file, arr[i].id);
				getline(file, arr[i].nam);
				getline(file, arr[i].cN);
				getline(file, arr[i].des);
				getline(file, arr[i].productId);
				getline(file, arr[i].size);
				getline(file, arr[i].clr);
				getline(file, arr[i].quant);
			}
			file.close();


			for (int i = 0; i < count; i++)
			{
				if (id == arr[i].id)
					pCount++;
			}
			//adding tax
			pCount = pCount * 200;
			pCount = pCount + (0.02 * pCount);

			while (true)
			{
				if (pCount > 0)
				{
					cout << "\t\t\t\t\t\tTotal Price  : " << pCount << endl << endl;
					cout << "\t\t\t\t\t\tEnter Amount : ";
					cin >> payment;
					if (payment >= pCount)
					{
						cout << "\t\t\t\t\t\tChange Returned : " << payment - pCount << endl;
						fstream filecart;
						filecart.open("addToCart.txt", ios::out);
						for (int i = 0; i < count; i++)
						{
							if (arr[i].id == id)
								continue;
							filecart << arr[i].id << endl;
							filecart << arr[i].nam << endl << arr[i].cN << endl << arr[i].des << endl;
							filecart << arr[i].productId << endl << arr[i].size << endl << arr[i].clr << endl << arr[i].quant << endl;
						}
						filecart.close();
						break;
					}
					else
						cout << "\t\t\t\t\t\tNot Enough Amount\n\t\t\t\t\t\tReEnter \n";
				}
				else
				{
					cout << "\t\t\t\t\t\tNothing to pay\n";
					break;
				}
			}
		}
		
		void DisplayAdmin(AdministratorModule AdminObj[], int TotalAdmin)
		{
			for (int i = 0; i < TotalAdmin - 1; i++)
			{
				cout << "Email    : " << AdminObj[i].email << endl;
				cout << "Passward : " << AdminObj[i].password << endl;
				cout << "Username : " << AdminObj[i].username << endl;

			}
		}
		void displayShopkeeper(ShopkeeperModule shopObj[], int size)
		{
			for (int i = 0; i < size; i++)
			{
				cout << "\nShopKeeper : " << i + 1 << endl << endl;
				cout << "First Name : " << shopObj[i].firstName << endl;
				cout << "Last Name : " << shopObj[i].LastName << endl;
				cout << "Shopkeeper ID : " << shopObj[i].sId << endl;
				cout << "UserName : " << shopObj[i].Username << endl;
				cout << "Email : " << shopObj[i].Email << endl;
				cout << "Password : " << shopObj[i].Password << endl;
				cout << "Registration Date : " << shopObj[i].RegDate << endl;
				cout << "Gender : " << shopObj[i].Gender << endl;
				cout << "Blood Group " << shopObj[i].BG << endl;
				cout << "Contact Number : " << shopObj[i].ContactNo << endl;
				cout << "Address : " << shopObj[i].Address << endl;
			}
		}
		void displayCustomer(CustomerModule cusObj[], int size)
		{
			for (int i = 0; i < size; i++)
			{
				cout << "First Name : " << cusObj[i].cfirstName << endl;
				cout << "Last Name : " << cusObj[i].cLastName << endl;
				cout << "Customer ID : " << cusObj[i].cID << endl;
				cout << "UserName : " << cusObj[i].cUserName << endl;
				cout << "Email : " << cusObj[i].cEmail << endl;
				cout << "Password : " << cusObj[i].cPass << endl;
				cout << "Registration Date : " << cusObj[i].cregDate << endl;
				cout << "Gender : " << cusObj[i].cgender << endl;
				cout << "Blood Group : " << cusObj[i].cBG << endl;
				cout << "Contact No. : " << cusObj[i].ccontactNo << endl;
				cout << "Address : " << cusObj[i].caddress << endl;
			}
		}

		int ProductCount()
		{

			fstream file;
			int count = 0;
			string line;
			file.open("product.txt", ios::in);
			if (file.is_open())
				while (file)
				{
					getline(file, line);
					count++;
				}
			else
				cout << "File Not Open\n";
			count /= 7;
			return count;
		}


		int CustomerCount()
		{
			int count = 0;
			fstream file;

			string line;
			file.open("customer.txt", ios::in);
			if (file.is_open())
				while (file.good())
				{
					getline(file, line);
					count++;
				}
			else
				cout << "File Not Open\n";
			count /= 11;
			return count;
		}

		int ShopKeeperCount()
		{
			int count = 0;
			fstream file;

			string line;
			file.open("shopkeeper.txt", ios::in);
			if (file.is_open())
				while (file.good())
				{
					getline(file, line);
					count++;
				}
			else
				cout << "File Not Open\n";
			count /= 11;
			return count;
		}


		int AdminCount()
		{
			int count = 0;
			fstream file;

			string line;
			file.open("Admin.txt", ios::in);
			if (file.is_open())
				while (file.good())
				{
					getline(file, line);
					count++;
				}
			else
				cout << "File Not Open\n";
			count /= 3;
			count += 1;
			return count;
		}


		void CustomerArray(CustomerModule CusObj[], int count)
		{
			fstream file;
			string line;

			file.open("customer.txt", ios::in);
			for (int i = 0; i < TotalCustomer; i++)
			{
				getline(file, CusObj[i].cfirstName);
				getline(file, CusObj[i].cLastName);
				getline(file, CusObj[i].cID);
				getline(file, CusObj[i].cUserName);
				getline(file, CusObj[i].cEmail);
				getline(file, CusObj[i].cPass);
				getline(file, CusObj[i].cregDate);
				getline(file, CusObj[i].cgender);
				getline(file, CusObj[i].cBG);
				getline(file, CusObj[i].ccontactNo);
				getline(file, CusObj[i].caddress);
			}
			file.close();

		}


		void ShopkeeperArray(ShopkeeperModule ShopObj[], int count)
		{
			fstream file;

			file.open("shopkeeper.txt", ios::in);

			////  Getting Data from file

			for (int i = 0; i < TotalShopkeeper; i++)
			{
				getline(file, ShopObj[i].firstName);
				getline(file, ShopObj[i].LastName);
				getline(file, ShopObj[i].sId);
				getline(file, ShopObj[i].Username);
				getline(file, ShopObj[i].Email);
				getline(file, ShopObj[i].Password);
				getline(file, ShopObj[i].RegDate);
				getline(file, ShopObj[i].Gender);
				getline(file, ShopObj[i].BG);
				getline(file, ShopObj[i].ContactNo);
				getline(file, ShopObj[i].Address);
			}
			file.close();
			return;
		}

		void AdminArray(AdministratorModule AdminObj[], int count)
		{
			fstream file;
			int j = 0;

			file.open("Admin.txt", ios::in);

			for (int i = 0; i < count - 1;)
			{
				if (j == 0)
				{
					getline(file, AdminObj[i].email);
					j++;
				}
				else if (j == 1)
				{
					getline(file, AdminObj[i].password);
					j++;
				}
				else if (j == 2)
				{
					getline(file, AdminObj[i].username);
					j++;
				}
				if (j == 3)
				{
					j = 0;
					i++;
				}
			}
			file.close();
		}
