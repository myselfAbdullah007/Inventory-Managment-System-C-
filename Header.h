//Code Created By Abdullah Chaudhary
//instagram / @oye_abdullahhh
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
////////////////////////////Classes Prototype
class AdministratorModule;
class ShopkeeperModule;
class CustomerModule;
///////////////////////////Function Prototype
int CustomerCount();
int ShopKeeperCount();
int ProductCount();
int AdminCount();
void AdminArray(AdministratorModule AdminObj[], int count);
void ShopkeeperArray(ShopkeeperModule ShopObj[], int count);
void CustomerArray(CustomerModule CusObj[], int count);

static int TotalAdmin = AdminCount();
static int TotalShopkeeper = ShopKeeperCount();
static int TotalCustomer = CustomerCount();
static int TotalProduct = ProductCount();


//////////////////////Classes 
class Base
{
public:
	virtual void SignUp() = 0;
};

class Admin
{
public:
	string username, email, password;
};


class Shopkeeper
{
public:
	string firstName, LastName, sId;
	string Username, Email, Password, RegDate, Gender, BG, ContactNo, Address;


	//Print All Registered Shopkeepers

	void DisplayShopkeeper(Shopkeeper shopObj[], int size);

	//Serch Shopkeeper and return that particular index

	int SearchShopkeeper(Shopkeeper arr[], int size);
};

class Customer
{
public:
	//Attributes
	string cfirstName, cLastName, cID, cregDate, cgender, ccontactNo, cBG, caddress, noOfProducts, Category;
	string cUserName, cEmail, cPass, billStatus;
	//Print all registered Customers
	void DisplayCustomer(Customer cusObj[], int size);
	//Serach any customer by its id and return that index
	int SearchCustomer(Customer arr[], int size);
};
class Product
{
public:
	string name, categoryName, category, description, quantity, size, color, pID;
	string cN[5] = { "Sports", "Garments","Eatables", "Medicines", "Fashion" };
	//Print all added Products
	void DisplayProduct(Product ProObj[], int size);
	//Function to add product details to filee
	void AddProduct();
	//Set Product ID by its category and product Number
	void setProductID();
	//Serach Product by Id and return that particular index
	int SearchProduct(Product arr[], int size);
	//Function to Get data from file then Edit it and then store back data to file
	void EditProduct();
};

class AdministratorModule :public Base, public Admin, public Shopkeeper, public Customer, public Product
{
public:
	AdministratorModule();
	//Operator Overloading
	AdministratorModule operator =(AdministratorModule& ob)
	{
		return ob;
	}
	//Function to register new Admin
	virtual void SignUp();
	//Function for SignIn check weather particular email and pass is present in admin file or not
	int SignIn(AdministratorModule obj[], int ind);
	//Add shopkeeper Informatio to file
	void AddShopkeeper();
	//Adding Customer Informatrion into the file
	void AddCustomer();
	//Get data from file,edit and store back to file
	void EditShopkeeper();
	//Take data from file,edit and store back
	void EditCustomer();
	//Function to get data from File and delete particular shopkeeper
	void DeleteShopkeeper();
	//Function to get data from File and delete particular Customer
	void DeleteCustomer();
	void DeleteProduct();

};
class ShopkeeperModule :public Base, public Shopkeeper, public Product
{
public:
	ShopkeeperModule();
	//Adding data into file
	virtual void SignUp();
	//Check weather email and pass are present in file and return index
	int SignIn(ShopkeeperModule arr[], int size);

	void ViewProduct();
};

class CustomerModule : public Base, public Customer, public Product
{
public:
	virtual void SignUp();
	//signIn fucntions
	int SignIn(CustomerModule arr[], int size);
	int searchforPurchasing(Product obj[], int size);
	//purchase product functions
	void Purchase_a_Product(string id);
	//add to cart functions
	void AddtoCart(string id);
	void CheckOut(string id);
};

///////////////////////////// info Display Functions
void DisplayAdmin(AdministratorModule AdminObj[], int TotalAdmin);
void displayShopkeeper(ShopkeeperModule shopObj[], int size);
void displayCustomer(CustomerModule cusObj[], int size);
