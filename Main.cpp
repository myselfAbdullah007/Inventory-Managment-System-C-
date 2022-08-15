//Created by Abdullah Chaudhary
// insta || @oye_abdullahhh
#include<iostream>
#include<fstream>
#include<string>
#include"Header.h"
using namespace std;
int main()
{
	system("Color F3");
	AdministratorModule* AdminObj;
	ShopkeeperModule* ShopKeeperObj;
	CustomerModule* CustomerObj;
	Base* ptr;
	int index = -1, ch;

	AdminObj = new AdministratorModule[TotalAdmin];
	AdminArray(AdminObj, TotalAdmin);

	ShopKeeperObj = new ShopkeeperModule[TotalShopkeeper];
	ShopkeeperArray(ShopKeeperObj, TotalShopkeeper);

	CustomerObj = new CustomerModule[TotalCustomer];
	CustomerArray(CustomerObj, TotalCustomer);


	bool flag;

	int choice;
	cout << "\t\t\t\t\t\tINVENTORY MANAGMENT SYSTEM\n\n";
	while (true)
	{
		cout << "\t\t\t\t\t\t\t1.) Admin\n\t\t\t\t\t\t\t2.) ShopKeeper\n\t\t\t\t\t\t\t3.) Customer\n\t\t\t\t\t\t\t4.) Exit\n\nEnter : ";
		while (true)
		{
			cin >> choice;
			if (!cin)
			{
				cout << "Enter Integer\nEnter again " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else
				break;
		}
		switch (choice)
		{
		case 1:
			system("cls");
			//DisplayAdmin(AdminObj, TotalAdmin);
			system("Color 9F");
			cout << "\t\t\t\t\t\tWELCOME TO ADMIN MODULE\n\n";
			while (true)
			{
				cout << "\t\t\t\t\t\t\t1.) SignUp \n\t\t\t\t\t\t\t2.) SignIn\n\t\t\t\t\t\t\t3.) Exit\n\nEnter : ";
				cin >> choice;
				if (choice == 1)
				{
					system("cls");
					ptr = new AdministratorModule;
					ptr->SignUp();
					cout << "\n\t\t\t\t\t\tAccount Registered Successfully\n";

					TotalAdmin = AdminCount();
					AdminObj = new AdministratorModule[TotalAdmin];
					AdminArray(AdminObj, TotalAdmin);
				}
				else if (choice == 2)
				{
					system("cls");
					TotalAdmin = AdminCount();
					AdminObj = new AdministratorModule[TotalAdmin];
					AdminArray(AdminObj, TotalAdmin);
					index = AdminObj->SignIn(AdminObj, TotalAdmin);
					if (index == -1)
						continue;
					else
					{
						system("cls");
						flag = true;
						while (flag)
						{
							cout << "\n\t\t\t\t\t\t1.) Add Shopkeeper \n\t\t\t\t\t\t2.) Add Customer \n\t\t\t\t\t\t3.) Add Product \n\t\t\t\t\t\t4.) Edit Shopkeeper";
							cout << "\n\t\t\t\t\t\t5.) Edit Customer\n\t\t\t\t\t\t6.) Edit Product\n\t\t\t\t\t\t7.) Delete Shopkeeper ";
							cout << "\n\t\t\t\t\t\t8.) Delete Customer\n\t\t\t\t\t\t9.) Delete Product \n\t\t\t\t\t\t10.) Exit\n";
							cin >> ch;
							switch (ch)
							{
							case 1:
								system("cls");
								AdminObj[index].AddShopkeeper();
								break;
							case 2:
								system("cls");
								AdminObj[index].AddCustomer();
								break;
							case 3:
								system("cls");
								AdminObj[index].AddProduct();
								break;
							case 4:
								system("cls");
								AdminObj[index].EditShopkeeper();
								break;
							case 5:
								system("cls");
								AdminObj[index].EditCustomer();
								break;
							case 6:
								system("cls");
								AdminObj[index].EditProduct();
								break;
							case 7:
								system("cls");
								AdminObj[index].DeleteShopkeeper();
								break;
							case 8:
								system("cls");
								AdminObj[index].DeleteCustomer();
								break;
							case 9:
								system("cls");
								AdminObj[index].DeleteProduct();
								break;
							case 10:
								flag = false;
								break;
							default:
								cout << "InCorrect Input\n\n";
								break;
							}
						}
					}
				}
				else if (choice == 3)
				{
					break;
				}
				else
					cout << "Enter Correct Input\n";
			}
			break;
		case 2:
			system("cls");
			system("Color B4");
			//displayShopkeeper(ShopKeeperObj, TotalShopkeeper);
			while (true)
			{
				cout << "\t\t\t\t\t\tWELCOME TO SHOPKEEPER MODULE\n\n";
				cout << "\t\t\t\t\t\t1.) Register to system\n\t\t\t\t\t\t2.) Log in to system\n\t\t\t\t\t\t3.) Exit \n\n\t\t\t\t\t\tEnter : ";
				cin >> choice;
				if (choice == 1)
				{
					system("cls");
					ptr = new ShopkeeperModule;
					ptr->SignUp();
					cout << "\t\t\t\t\t\tShopKeeper Registered Successfully\n";
					TotalShopkeeper = ShopKeeperCount();
					ShopKeeperObj = new ShopkeeperModule[TotalShopkeeper];
					ShopkeeperArray(ShopKeeperObj, TotalShopkeeper);
				}
				else if (choice == 2)
				{
					system("cls");
					index = ShopKeeperObj->SignIn(ShopKeeperObj, TotalShopkeeper);
					if (index == -1)
						continue;
					else
					{
						system("cls");
						flag = true;
						while (flag)
						{
							cout << "\n\t\t\t\t\t\t1.) Add Product \n\t\t\t\t\t\t2.) Edit Product \n\t\t\t\t\t\t3.) View Product \n\t\t\t\t\t\t4.) Exit \n\n\t\t\t\t\t\tEnter : ";
							cin >> ch;
							switch (ch)
							{
							case 1:
								system("cls");
								ShopKeeperObj[index].AddProduct();
								break;
							case 2:
								system("cls");
								ShopKeeperObj[index].EditProduct();
								ShopkeeperArray(ShopKeeperObj, TotalShopkeeper);
								break;
							case 3:
								system("cls");
								ShopKeeperObj[index].ViewProduct();
								break;
							case 4:
								flag = false;
								break;
							default:
								cout << "\t\t\t\t\t\tEnter Valid Input\n";
								break;
							}
						}

					}
				}
				else if (choice == 3)
				{
					break;
				}
				else
				{
					cout << "\n\t\t\t\t\t\tEnter correct Input\n";
				}
			}
			break;
		case 3:
			
			//displayCustomer(CustomerObj, TotalCustomer);
			while (true)
			{
				system("cls");
				cout << "\t\t\t\t\t\tWELCOME TO CUSTOMER MODULE\n\n";
				cout << "\t\t\t\t\t\t1.) Register to System \n\t\t\t\t\t\t2.) Log in to System \n\t\t\t\t\t\t3.) Exit \n\n\t\t\t\t\t\tEnter : ";
				cin >> choice;
				if (choice == 1)
				{
					system("cls");
					ptr = new CustomerModule();
					ptr->SignUp();
					cout << "\t\t\t\t\t\tCustomer Registered Successfully\n";
					TotalCustomer = CustomerCount();
					CustomerObj = new CustomerModule[TotalCustomer];
					CustomerArray(CustomerObj, TotalCustomer);
				}
				else if (choice == 2)
				{
					system("cls");
					index = CustomerObj->SignIn(CustomerObj, TotalCustomer);
					if (index == -1)
						continue;
					else
					{
						system("cls");
						flag = true;
						while (flag)
						{
							cout << "\t\t\t\t\t\t1.) Purchase a Product \n\t\t\t\t\t\t2.) Add to cart \n\t\t\t\t\t\t3.) Check Out \n\t\t\t\t\t\t4.) Exit \n\n\t\t\t\t\t\tEnter : ";
							cin >> ch;
							switch (ch)
							{
							case 1:
								system("cls");
								CustomerObj[index].Purchase_a_Product(CustomerObj[index].cID);
								break;
							case 2:
								system("cls");
								CustomerObj[index].AddtoCart(CustomerObj[index].cID);
								break;
							case 3:
								system("cls");
								CustomerObj[index].CheckOut(CustomerObj[index].cID);
								break;
							case 4:
								flag = false;
								break;
							default:
								cout << "\t\t\t\t\t\tEnter Correct Input\n\n";
								break;
							}
						}
					}
				}
				else if (choice == 3)
				{
					break;
				}
				else
				{
					cout << "\t\t\t\t\t\tEnter correct Input\n";
					break;
				}
			}

			break;
		case 4:
			system("cls");
			cout << "\t\t\t\t\t\tGood Bye! Thanks for Choosing Us!~\n";
			return 0;
		default:
			cout << "\t\t\t\t\t\tEnter Correct Input\n";
			break;
		}
	}
}
