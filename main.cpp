#include "class.h"

//Daniel Huynh, November 17th, Karla Fant CS302 Program 3.
//the purpose of this program is to create a binary search tree of animals with unique pointers and experiencing expcetion handlging, upcasting, and downcasting.

int main()
{
	//initialize data structure and varaibles used to navigate the program
	tree datatree;
	char start, button, petpick;
	string nameinput, breedinput, sizeinput, temperamentinput, petremove, hairlength, colorinput, shedinput;

	cout <<"Welcome to the pet program, press x to start: " ;
	cin>>start;
	cin.ignore(100, '\n');
	while(toupper(start) =='X')
	{
		cout <<"\n\n(a) add pet\n(b) interact with pets\n(c) display pets\n(d) remove pet \n(e) remove all pets \n(f) end program:";
		cin>>button;
		cin.ignore(100, '\n');
		if(toupper(button) =='A')
		{
			cout <<"\n(a) add dog\n(b) add cat\n(c) add reptile ";
			cin >> petpick;
			cin.ignore(100, '\n');
			if(toupper(petpick) =='A') //add dog
			{
				cout <<"\n\nWhats your pets name? : ";
				cin>>nameinput;
				cin.ignore(100, '\n');
				cout <<"\nWhats your pets breed? : ";
				cin>>breedinput;
				cin.ignore(100, '\n');
				sizeinput=setsize();
				hairlength = setfur();
				shedinput = setshed();
				temperamentinput = settemperament();
				animal * newdog = new dog(nameinput, breedinput, sizeinput, temperamentinput, shedinput, hairlength); 
				datatree.addnode(newdog);
				//datatree.walkdog();
				//datatree.interactpet();

			}
			if(toupper(petpick) =='B')//add cat
			{
				string color;
				cout <<"\n\nWhats your pets name? : ";
				cin>>nameinput;
				cin.ignore(100, '\n');
				cout <<"\nWhats your pets breed? : ";
				cin>>breedinput;
				cin.ignore(100, '\n');
				cout <<"\nWhats the color of your pet? : ";
				cin >> color;
				cin.ignore(100, '\n');
				sizeinput=setsize();
				temperamentinput = settemperament();
				hairlength = setfur();
				animal * newcat = new cat(nameinput, breedinput, sizeinput, temperamentinput, color, hairlength); 
				datatree.addnode(newcat);

			}
			if(toupper(petpick) =='C')//add lizard
			{
				string color;
				cout <<"\n\nWhats your pets name? : ";
				cin>>nameinput;
				cin.ignore(100, '\n');
				cout <<"\nWhats your pets breed? : ";
				cin>>breedinput;
				cin.ignore(100, '\n');
				cout <<"\nWhats the color of your pet? : ";
				cin >> color;
				cin.ignore(100, '\n');
				sizeinput=setsize();
				temperamentinput = settemperament();
				animal * newlizard = new lizard(nameinput, breedinput, sizeinput, temperamentinput, color, 70); 
				datatree.addnode(newlizard);

			}

		}
		if(toupper(button) =='B')//change personal pet values
		{
			cout <<"what type of pet would you like to interact with ?" << endl;
			cout <<"(a) Dog\n(b) Cat\n(c) Lizard";
			cin >> petpick;
			cin.ignore(100, '\n');
			datatree.displaytype(petpick);
			cout <<"enter pet name to interact:";
			cin>>petremove;
			cin.ignore(100, '\n');
			datatree.searchinteract(petpick, petremove);

		}
		if(toupper(button) =='C') //display pets
		{
			bool detail;
			do
			{
			cout <<"would you like to display pets with detail ? y/n : ";
			cin >>petpick;
			cin.ignore(100, '\n');
			if(toupper(petpick) =='Y'){//this will display each pets physical characteristics and detail
				detail = true;
			}
			if(toupper(petpick) =='N'){
				detail = false;
			}
			else{
				cout <<"press Y or N " << endl;
			}
			
			}while(toupper(petpick) != 'Y' && toupper(petpick) != 'N');
			datatree.displaytree(detail);
		}
		if(toupper(button) =='D')//remove pet
		{
			datatree.removepet();


		}
		if(toupper(button) =='E') //remove all
		{
			datatree.removeall();
		}
		if(toupper(button) =='F')
		{
			start = 'v';

		}

	}
	return 0;
}
