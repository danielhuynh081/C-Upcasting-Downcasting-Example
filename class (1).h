#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;
string setsize();
string settemperament();
string setfur();
string setshed();
class animal // abstract base class
{
	public:
		animal(){}
		animal(string nameinput, string animalinput, string breedinput, string sizeinput, string tempinput): name(nameinput), animaltype(animalinput), breed(breedinput), size(sizeinput), temperament(tempinput){}
		animal(const animal& copy): name(copy.name), animaltype(copy.animaltype), breed(copy.breed), size(copy.size), temperament(copy.temperament), history(copy.history){}
		virtual	~animal();
		virtual bool displayanimal() =0;
		bool sizecheck(){ //pet interaction function
			if(size == "Small")
			{
				cout << getname() << " meet the size limit!" << endl;
			}
			if(size == "Medium")
			{
				cout << getname() << " might be able to meet the size limit." << endl;
			}
			if(size == "Large")
			{
				cout << getname() << " does not meet the size limit!" << endl;
			}
			return true;
		}
		bool parkcheck(){//pet interaction function
			if(temperament == "Friendly")
			{
				cout << getname() << " is allowed at the pet park! " << endl;
			}
			if(temperament == "Shy")
			{
				cout << getname() << " is allowed at the pet park! " << endl;

			}
			if(temperament == "Agressive")
			{
				cout << getname() << " is not allowed at the pet park. " << endl;
			}
			return true;
		}
		string getname(){
			return name;
		}
		string getbreed(){
			return breed;
		}
		string getsize(){
			return size;
		}
		string gettemp(){
			return temperament;
		}

	protected:
		string name;
		string animaltype;
		string breed;
		string size;
		string temperament;
		string history;
};

class dog : public animal //first derived class
{
	public:
		dog(){}
		dog(const dog & copy): animal(copy), shed(copy.shed), furlength(copy.furlength), showered(copy.showered), walked(copy.walked){}
		dog(string nameinput, string breedinput, string sizeinput, string tempinput, string shedinput, string furlengthinput): animal(nameinput, "Dog", breedinput, sizeinput, tempinput),  shed(shedinput), furlength(furlengthinput), showered(false), walked(false) {}
		 ~dog();
		bool displayanimal();
		bool setshed();
		bool sethairlength;
		bool showerdog(){
			showered = true;
			return showered;
		}
		bool walkdog(){
			walked = true;
			return walked;
		}
		bool walkcheck(){
			return walked;
		}
		bool showercheck(){
			return showered;
		}
		string getshed(){
			return shed;
		}
		string getfur(){
			return furlength;
		}
	
	private:
		string shed;
		string furlength;
		bool showered;
		bool walked;


};

class cat : public animal//second derived class
{
	public:
		cat();
		cat(const cat & copy): animal(copy), clawsclipped(copy.clawsclipped), groomed(copy.groomed), color(copy.color), hairlength(copy.hairlength){}
		cat(string nameinput, string breedinput, string sizeinput, string tempinput, string colorinput, string hairlengthinput): animal(nameinput, "Cat", breedinput, sizeinput, tempinput), clawsclipped(false), groomed(false), color(colorinput), hairlength(hairlengthinput){}
		~cat();
		bool displayanimal();
		bool setcolor();
		bool sethairlength();	
		bool playwithcat();
		bool clipclaws(){
			clawsclipped = true;
			return clawsclipped;
		}
		bool groomcat(){
			groomed = true;
			return groomed;
		}
		bool getclipped(){
			return clawsclipped;
		}
		bool groomcheck(){
			return groomed;
		}
		string getcolor(){
			return color;
		}
		string hairget(){
			return hairlength;
		}


	private:
		bool clawsclipped;
		bool groomed;
		string color;
		string hairlength;

};

class lizard : public animal //third derived class
{
	public:
		lizard();
		lizard(const lizard & copy): animal(copy), soilchange(copy.soilchange), plantadd(copy.plantadd), color(copy.color), temp(copy.temp){}
		lizard(string nameinput, string breedinput, string sizeinput, string tempinput, string colorinput, int temperatureinput): animal(nameinput, "lizard", breedinput, sizeinput, tempinput), soilchange(false), plantadd(false), color(colorinput),temp(temperatureinput){}
       		~lizard();
		bool displayanimal();
		bool addplants(){ //setter
			plantadd = true;
			return true;
		}
		bool changesoil(){ //setter
			soilchange = true;
			return true;
		}
		bool changetemp(int newtemp){ //setter
			temp = newtemp;
			return true;
		}
		int tempcheck(){//getter
			return temp;
		}
		string getcolor(){//getter
			return color;
		}


	private:
		bool soilchange;
		bool plantadd;
		string color;
		int temp;

};
class Node//holds our data
{
	public:
	
		
	Node(animal * insert): data(insert), left(nullptr), right(nullptr){
	}
	~Node();

	unique_ptr<animal> data;
	bool black;
	unique_ptr<Node> left;
	unique_ptr<Node> right;
};

class tree//data structure
{
	public:
		tree(): root(nullptr){}
		tree(const tree & other);
		~tree();
		bool copytree(unique_ptr<Node> &current, const unique_ptr<Node> &copy);
		bool addnode(animal* insert);
		bool addnode(unique_ptr<Node> & current,  animal * insert);
		bool displaytree(bool detail);
		bool displaytree(Node* current, bool detail);

		bool displaytype(char petpick);
		bool displaytype(Node * current, char animaltype);
		bool checktype(Node* current, char typeinput);

		bool removeall();
		bool removeall(Node * current);

		bool removepet();
		bool removepet(char type,Node*parent, Node*current, string petname);

		bool walkdog();
		bool walkdog(Node* current);
		
		bool searchinteract(char type, string nameinput);
		bool searchinteract(char type, string nameinput, Node*  current);
		bool interactpet();
		bool interactpet(Node* current);
	private:
		unique_ptr<Node> root;
};

