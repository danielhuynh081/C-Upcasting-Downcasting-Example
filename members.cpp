#include "class.h"
//hi
//


tree::tree(const tree & other){
	copytree(root, other.root);
}

bool tree::copytree(unique_ptr<Node> &current, const unique_ptr<Node> &copy){
	if(!current)
	{
		return false;
	}
	if(copy == nullptr)
	{
		current = nullptr;
	}
	else{
		current = make_unique<Node>(copy->data.get());

		return copytree(current->left, copy->left);
		return copytree(current->right, copy->right);
	}
	return true;
}

//destructors
tree::~tree(){}


animal::~animal(){

}
dog::~dog(){

}

cat::~cat(){
}

lizard::~lizard(){
}

Node::~Node(){

}
 

//dervied display function
bool dog::displayanimal(){
	cout <<"\nAnimal: Dog" << endl;
	cout <<"Name: "<< getname() << endl;
	cout <<"Breed: "<< getbreed() << endl;
	cout <<"Size: " << getsize() << endl;
	cout <<"Temperament: " << gettemp() << endl;
	cout <<"Shed: " << getshed() << endl;
	cout <<"Fur Type: " << getfur() << endl;
	if(walked){
		cout <<"Walked" << endl;
	}
	else{
		cout <<"Hasn't Walked" << endl;
	}
	if(showered)
	{
		cout <<"Clean" << endl;
	}
	else{
		cout <<"Musty" << endl;
	}
	return true;
}

//pet physical characteristics
bool dog::setshed(){
	string sizeinput;
	char button2;
	do
	{
		cout <<"\nWhats your pets shed ? : (a) Low (b) Medium (c) Heavy  ";
		cin>> button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A'){
			sizeinput="Small";
		}
		if(toupper(button2)=='B'){
			sizeinput = "Medium";
		}
		if(toupper(button2)=='C'){
			sizeinput = "Large";
		}	
		else if(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' )
		{
			cout <<"pick valid answer";
		}
	}
	while(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' );
	return true;
}

//dervied display function
bool cat::displayanimal(){
	cout <<"\nAnimal : Cat" << endl;
	cout <<"Name: " << getname() << endl;
	cout <<"Breed: " << getbreed() << endl;
	cout <<"Size: " << getsize() << endl;
	cout <<"Fur length: " << hairget() << endl;
	cout <<"Color : " << getcolor() << endl;
	if(clawsclipped)
	{
		cout <<"Clipped claws" << endl;
	}
	else{
		cout <<"Claws haven't been clipped" << endl;
	}
	if(groomed)
	{
		cout <<"Groomed" << endl;
	}
	else{
		cout <<"Hasn't been groomed" << endl;
	}
	
	return true;
}

//dervied display function
bool lizard::displayanimal(){
	cout <<"\nLizard" << endl;
	cout <<"Name: " << getname() << endl;
	cout <<"Breed: " << getbreed() << endl;
	cout <<"Size: " << getsize() << endl;
	cout <<"Color: " << getcolor() << endl;
	cout <<"Temp : " << tempcheck() << "F"<<endl;
	if(soilchange)
	{
		cout <<"Soil changed" << endl;
	}
	else{
		cout <<"Soil hasnt been changed" << endl;
	}
	if(plantadd)
	{
		cout <<"New plants have been added" << endl;
	}
	else{
		cout <<"No new plants have been added" << endl;
	}
	return true;
}

//wrapper add function 
bool tree::addnode( animal * insert){

	if(!root)//empty tree
	{
	//	animal * temp = insert.release();
		
		unique_ptr<Node> temp(new Node(insert));
		root = move(temp);
		return true;
	}
	else{
	try{
		addnode(root, insert);
		return true;
	}catch(const bad_alloc& e)
	{
		cerr<<"error adding nodes:" << e.what() << endl;
		return false;
	}catch(...){
		cerr<<"unknown error occured" << endl;
	}
	}

	return false;
}

//recursive add function
bool tree::addnode(unique_ptr<Node> & current ,  animal * insert)
{
	if(!current)
	{
		unique_ptr<Node> temp(new Node(insert));//create a new node of insert data
		current = move(temp); //passes ownership and moves that data into the node current is pointing
		return true;
	}
	if(current->data->getname() <= insert->getname())//new data is higher than parent
	{
		addnode(current->right, insert);

	}
	else if(current->data->getname() > insert->getname())//new data is less than 
	{
		addnode(current->left, insert);
	}
	return true;
}

//wrapper to display all
bool tree::displaytree(bool detail){
	if(root)
	{
		displaytree(root.get(), detail);
	}
	else{
		cout <<"\nempty tree" <<endl;
	}
	return true;
}

//recursive display all
bool tree::displaytree(Node * current, bool detail){
	/*if(current)
	{
		current->data->displayanimal();
	}
	*/
	if(current)
	{
		if(current->left.get())
		{
			displaytree(current->left.get(), detail);
		}
		if(detail)
		{
			current->data->displayanimal();
		}
		else{
			cout <<"Name: " << current->data->getname() << endl;
		}
		if(current->right.get())
		{
			displaytree(current->right.get(), detail);
		}
	}

	return true;
}


//wrapper for removing the whole tree
bool tree::removeall(){
	try{

		removeall(root.get());
		root = nullptr;
		return true;
	}catch(const exception & e){
		cerr<<"exception error occured:" << e.what() << endl;
	}
	catch(...)
	{
		cerr<< "error removing" << endl;
		return false;
	}
return false;	
}

//recursive function to delete the tree
bool tree::removeall(Node * current)
{
	if(current)
	{
		if(current->left.get())
		{
			removeall(current->left.get());
		}
		current->data.reset();
		if(current->right.get())
		{
			removeall(current->right.get());
		}
	}
	return true;
}

//user inputted removal
bool tree::removepet()
{
	char petpick;
	string petremove;
	cout <<"\n(a) remove dog\n(b) remove cat\n(c) remove lizard" << endl;
	cin>> petpick;
	cin.ignore(100, '\n');
	displaytype(petpick);
	cout <<"which pet would you like to remove?";
	cin >>petremove;
	cin.ignore(100, '\n');
	if(root->left.get() == nullptr && root->right.get() == nullptr)
	{
		if(root->data->getname() == petremove)
		{
			root.reset();
			return true;
		}
		cerr<<"pet not found " << endl;
		return false;
	}

	try//exception handling
	{
	removepet(petpick, root.get(), root.get(), petremove);
	return true;
	}catch(const exception & e){
		cerr<<"exception error" << e.what() << endl;
		return false;
	}
	catch(...)
	{
		cerr <<"error removing" << endl;
		return false;
	}
	return true;
}

bool tree::removepet(char type, Node * parent, Node * current, string petname)
{
	if(!current)//stopping statement, also prevents from accessing unaccesible memory
	{
		return false;
	}
	if(current)
	{
		if(petname < current->data->getname() && current->left.get())
		{
			return removepet(type, current, current->left.get(), petname);
		}	
		else if(petname > current->data->getname() && current->right.get())
		{
			return removepet(type, current, current->right.get(), petname);
		}
		else{
			if(current->data->getname() == petname && checktype(current, type))//node to be removed found
			{
				if(current->left == nullptr && current->right == nullptr) //leaf case
				{
					if(parent){
						if(parent->left.get() == current){//check if its either in the left or right tree of the parent
							parent->left = nullptr;
						}
						else{
							parent->right = nullptr;
						}
					}
					else{ //case of removing a single data tree
						root = nullptr;
					}
					return true;
				}
				else if(current->left == nullptr && current->right != nullptr)//one right node
				{
					Node* temp = current->right.release(); //set a hold for the right node of current
					if(parent)
					{
						if(parent->left.get() == current) //replace current with our hold 
						{
							parent->left = unique_ptr<Node>(temp);
						}
						else{
							parent->right = unique_ptr<Node>(temp);
						}
					}else{//removing root case
						root = unique_ptr<Node>(temp);
					}
					return true;
				}
				else if( current->left != nullptr && current->right == nullptr)//one left node
				{
					Node* temp = current->left.release(); //set hold for current in left node case
					if(parent)
					{
						if(parent->left.get() == current)//replace parent left node with temp hold
						{
							parent->left = unique_ptr<Node>(temp);
						}
						else{
							parent->right = unique_ptr<Node>(temp);
						}
					}else{//root case
						root = unique_ptr<Node>(temp);
					}
					return true;
				}
				else{
					//middle of list
					Node*successor = current->right.get(); //move one to the right for sucessor loop
					while(successor->left != nullptr)
					{
						successor = successor->left.get(); //move to successor
					}
					current->data = move(successor->data); //replace current wth sucessor
					if(current->right.get())
					{
						return removepet(type, current, current->right.get(), successor->data->getname());
					}
				}

			}

		}
	}
	return false;

}
bool tree::displaytype(char petpick){
	if(toupper(petpick) =='A')
	{
		cout <<"Current dogs" << endl <<endl;
		displaytype(root.get(), 'A');
	}
	if(toupper(petpick) =='B')
	{
		cout <<"Current cats" << endl << endl;
		displaytype(root.get(), 'B');
	}
	if(toupper(petpick) =='C')
	{
		cout <<"Current lizards" << endl << endl;
		displaytype(root.get(), 'C');

	}
	return true;
}

bool tree::displaytype(Node* current, char animaltype) 
{
	if(current)
	{
		if(current->left.get())
		{
			displaytype(current->left.get(), animaltype);
		}
		if(checktype(current, animaltype))
		{
			cout<<"Name: " << current->data->getname() << endl;
		}
		if(current->right.get())
		{
			displaytype(current->right.get(), animaltype);
		}
	}
	return false;
}

bool tree::checktype(Node* current, char typeinput)
{
	if(toupper(typeinput) =='A')
	{

		dog* dogcheck = dynamic_cast<dog*>(current->data.get());
		if(dogcheck)
		{
			return true;
		}
		else{
			return false;
		}
	}
	else if(toupper(typeinput) =='B')
	{
		cat *catcheck = dynamic_cast<cat*>(current->data.get());
		if(catcheck)
		{
			return true;
		}
		else{
			return false;
		}
	}
	else
	{
		lizard * lizardcheck = dynamic_cast<lizard*>(current->data.get());
		if(lizardcheck)
		{
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
bool tree::walkdog()
{
	return walkdog(root.get());
}
bool tree::walkdog(Node * current)
{
	if(current)
	{
		dog * dogcheck = dynamic_cast<dog*>(current->data.get());
		if(dogcheck && dogcheck->walkcheck() == false)
		{
			cout <<"Walking dog";
			dogcheck->walkdog();
		}
	}
	return true;
}

bool tree::interactpet(){
	interactpet(root.get());
	return true;
}

bool tree::interactpet(Node* current){
	char button2;
	dog * dogcheck = dynamic_cast<dog*>(current->data.get());
	cat * catcheck = dynamic_cast<cat*>(current->data.get());
	lizard * lizardcheck = dynamic_cast<lizard*>(current->data.get());
	if(dogcheck)
	{
		cout <<"\n\n(a) Walk dog\n(b) Shower dog\n(c) check size test\n(d) check park test";
		cin>>button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A')
		{
			dogcheck->walkdog();
		}
		if(toupper(button2) =='B')
		{
			dogcheck->showerdog();
		}
		if(toupper(button2) =='C')
		{
			dogcheck->sizecheck();
		}	
		if(toupper(button2) =='D')
		{
			dogcheck->parkcheck();
		}
		return true;
	}
	if(catcheck)
	{
		cout <<"\n\n(a) Clip claws\n(b) Groom cat\n(c) check size test\n(d) check park test";
		cin>>button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A')
		{
			catcheck->clipclaws();
		}
		else if(toupper(button2) =='B')
		{
			catcheck->groomcat();
		}
		if(toupper(button2) =='C')
		{
			catcheck->sizecheck();
		}	
		if(toupper(button2) =='D')
		{
			catcheck->parkcheck();
		}
		return true;	
	}
	else if(lizardcheck)
	{
		int tempset;
		cout <<"\n\n(a) Change soil\n(b) change temp\n(c) add plants\n(d) check size test\n(e) check park test";
		cin>>button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A')
		{
			lizardcheck->changesoil();
		}
		if(toupper(button2) =='B')
		{
			do
			{
				cout <<"\n\npick a safe temperature\nbetween 75 F and 90 F:";
				cin >> tempset;
				cin.ignore(100, '\n');
				if(tempset < 70 || tempset > 90)
				{
					cout <<"please pick a safe temperature within range" << endl;
				}
			}
			while(tempset < 70 || tempset > 90);
			lizardcheck->changetemp(tempset);
		}
		if(toupper(button2) =='C')
		{
			lizardcheck->addplants();
		}
		if(toupper(button2) =='D')
		{
			lizardcheck->sizecheck();
		}	
		if(toupper(button2) =='E')
		{
			lizardcheck->parkcheck();
		}
		return true;
	}
	return false;

}

bool tree::searchinteract(char type, string nameinput)
{
	if(root)
	{
		searchinteract(type, nameinput, root.get());
	}
	return false;

}
bool tree::searchinteract(char type, string nameinput, Node * current)
{
	if(current)
	{
		if(current->left.get())
		{
			searchinteract(type, nameinput, current->left.get());
		}
		if(nameinput == current->data->getname() && checktype(current, type))
		{
			interactpet(current);
			cout <<"\n\nPRESS ENTER TO CONTINUE" << endl;
			cin.get();
			current->data->displayanimal();
			return true;
		}
		if(current->right.get())
		{
			searchinteract(type, nameinput, current->right.get());
		}

	}


	return false;
}
string setshed(){
	string shedinput;
	char button2;
	do
	{
		cout <<"\nWhats your pets shed type ? : (a) low (b) medium (c) heavy  ";
		cin>> button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A'){
			shedinput="low";
		}
		if(toupper(button2)=='B'){
			shedinput = "medium";
		}
		if(toupper(button2)=='C'){
			shedinput = "heavy";
		}	
		else if(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' )
		{
			cout <<"pick valid answer";
		}
	}
	while(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' );
	return shedinput;
}

string setfur(){
	string furinput;
	char button2;
	do
	{
		cout <<"\nWhats your pets fur type ? : (a) short (b) medium (c) long  ";
		cin>> button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A'){
			furinput="short";
		}
		if(toupper(button2)=='B'){
			furinput = "medium";
		}
		if(toupper(button2)=='C'){
			furinput = "long";
		}	
		else if(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' )
		{
			cout <<"pick valid answer";
		}
	}while(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' );
	return furinput;
}
string setsize(){
	string sizeinput;
	char button2;
	do
	{
		cout <<"\nWhats your pets size ? : (a) small (b) medium (c) large  ";
		cin>> button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A'){
			sizeinput="Small";
		}
		if(toupper(button2)=='B'){
			sizeinput = "Medium";
		}
		if(toupper(button2)=='C'){
			sizeinput = "Large";
		}	
		else if(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' )
		{
			cout <<"pick valid answer";
		}
	}
	while(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' );
	return sizeinput;
}

string settemperament(){
	string tempinput;
	char button2;
	do
	{
		cout <<"\nWhats your pets temperament ? : (a) friendly (b) shy (c) aggressive  ";
		cin>> button2;
		cin.ignore(100, '\n');
		if(toupper(button2) =='A'){
			tempinput="Friendly";
		}
		if(toupper(button2)=='B'){
			tempinput = "Shy";
		}
		if(toupper(button2)=='C'){
			tempinput = "Agressive";
		}	
		else if(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' )
		{
			cout <<"pick valid answer";
		}
	}
	while(toupper(button2) != 'A' && toupper(button2)!= 'B' && toupper(button2) != 'C' );
	return tempinput;

}

