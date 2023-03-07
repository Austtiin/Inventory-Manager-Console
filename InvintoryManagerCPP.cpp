/*

Austin Stephens

Simple inventory account manager for C++ course project in c++. Showcasing a few different loop structures
and data handeling.

The program must accomplish the task you have chosen, either:
a statistics program for sports or another domain,
an inventory accounting program,
a contact manager program,
a two player chess or checkers program, or
a cash accounting program.
The program must use at least one menu at the beginning with multiple options including an option to exit the program.
The program must run continuously, in a cyclic manner until the user chooses to exit.
Sublevel menus are allowed.
The program must use:
multiple data types,
multiple mathematical operators,
decision structures,
iterative structures, and
functions.
The program must run and be free from errors.
The program should be thoroughly documented with introductory comments at the top and other comments in areas that could be confusing.
The program should be easily readable and use proper indention.


Input:
User input based on menus, what they would like to do with a product.
Moving around menus and editing products beased on what they would like to do

Output:
Menus based on user input, edits based on users prodcuts and what they would like to do.
*/

//including librarys
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


//defining class, determining some private / public

class Product
{
private:
    char *Manufacture,*title;
	float *price;
	int *stock;
public:
    Product()	{
	Manufacture= new char[20];
	title=new char[20];
	price= new float;
	stock=new int;
	}
	//starting our functions
	void datafeed();
	void editproduct();
	void showproduct();
	int search(char[],char[]);
	void buyProduct();
};


//defining public object functions, figuring out what one does what is determined by the name 
//to make it easy to read

void Product::datafeed()
{
    cin.ignore();
    cout << "\nEnter Manufacture Name: " << endl;
    cin.getline(Manufacture,20);
	cout << "Enter Title Name: ";
    cin.getline(title,20);
	cout << "Enter Price: ";
    cin >> *price;
	cout << "Enter Stock/Material Ammount: ";
    cin >> *stock;
}

void Product::editproduct()
{
    cout<<"\nEnter Manufacture Name: ";      cin.getline(Manufacture,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock/Material Ammount: ";   cin>>*stock;
}

void Product::showproduct()
{
    cout<<"\nManufacture Name: "<<Manufacture;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Held Ammount: "<<*stock;
}

int Product::search(char tbuy[20],char mbuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(mbuy,Manufacture)==0)
		return 1;
	else return 0;
}

void Product::buyProduct()
{
	int count;
	cout << "\nEnter Number Of Products to buy: ";
	cin >> count;
	if(count <=* stock)	{
		*stock=*stock-count;
		cout << "Products Bought Confirmed" << endl;
		cout << "Amount:  $"<<(*price)*count << endl;
	}
	else
		cout<<"\nRequired material is not in Stock";
}


//int main
//showing our while loop and switch statemnt determining our decision(s)

int main()	{
	Product *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],manufacturebuy[20];

	//menu that will pop up every time we call/return to our while loop
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Product"
		<<"\n2. Buy Product"
		<<"\n3. Search For Product"
		<<"\n4. Edit Details Of Product"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;


//determining the input / menu screen

		switch(choice)	{
			case 1:	
				B[i] = new Product;
				B[i] -> datafeed();
				i++;	break;

			case 2: cin.ignore();
				cout<<"\nEnter Title Of Product: "; cin.getline(titlebuy,20);
				cout<<"Enter Manufacturer Of Product: ";  cin.getline(manufacturebuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,manufacturebuy))	{
						B[t]->buyProduct();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Product is Not in Stock";
				break;


			case 3:
				cin.ignore();
				cout<<"\nEnter Title Of Product: "; cin.getline(titlebuy,20);
				cout<<"Enter Manufacturer Of Product: ";  cin.getline(manufacturebuy,20);

				for(t=0;t<i;t++)	{
					if(B[t] -> search(titlebuy,manufacturebuy))	{
						cout<<"\nProduct Found Successfully";
						B[t]->showproduct();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Product is Not in Stock";
				break;


			case 4:

				cin.ignore();
				cout<<"\nEnter Title Of Product: "; cin.getline(titlebuy,20);
				cout<<"Enter Manufacturer Of Product: ";  cin.getline(manufacturebuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,manufacturebuy))	{
						cout<<"\nProduct Found Successfully";
						B[t]->editproduct();
						break;
					}
				}


				if(t==i)
				cout<<"\nThis Product is Not in Stock";
				break;


			case 5:
			exit(0);

			default: cout<<"\nInvalid Choice Entered";

		}
	}




	return 0;
}