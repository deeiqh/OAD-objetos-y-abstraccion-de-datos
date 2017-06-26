#include <iostream>

using namespace std;

struct node
{
	int value;
	node* child[2];
	node(int v)
	{
		value = v;
		child[0] = child[1] = NULL;
	}
};

class bst
{
	private:
		node* root;
	public:
		bst() {root = NULL;}

		bool find(int value)
		{
			node** n;
			return find(n, value);
		}
		bool find(node** &n, int value);
		bool insert(int value);
		void imprimir_niveles();
		int altura();
};

bool bst::find(node** &n, int value)
{
	n = &root;
	while(*n != NULL){
		if ((*n) -> value == value)
			return true;
		n = &(*n) -> child[(*n) -> value < value];
	}
	return false;
}

bool bst::insert(int value)
{
	node** n;
	if (find (n, value))
		return false;
	*n = new node(value);
	return true;
}

struct node2
{
    node* nodo = NULL;
    node2* sig = NULL;
};

void bst::imprimir_niveles()
{
	node2* encadenados1 = new node2;
	if (root !=  NULL){
		
		cout << root->value << '\n';;
		//cout << "root\n";

		if (root->child[0] != NULL){
			//cout << "child[0]\n";
			encadenados1->nodo = root->child[0];
			cout << root->child[0]->value << ' ';
			//cout << "child[0]fin\n";
			
			if (root->child[1] != NULL){
				cout << "child[1]\n";
				encadenados1 -> sig = new node2;
				encadenados1 -> sig->nodo = root->child[1];
				cout << "child[1]fin\n";
				cout << root->child[1]-> value << ' ';				
			    }
		}else{
		    	if (root->child[1] != NULL){
		        	encadenados1->nodo = root->child[1];
			        cout << root->child[1]-> value;
			}
        	}
        	cout << '\n';
	}

	node2* encadenados2 = new node2;
	node2* it2 = encadenados2;
	node2* it1 = encadenados1;
	while(encadenados1->nodo != NULL){
		
		if(it1-> nodo ->child[0] != NULL){
			it2 -> nodo = it1-> nodo ->child[0];
			cout << it2->nodo->value << ' ';
			it2->sig = new node2;
			it2 = it2->sig;
		}
		
		if(it1-> nodo->child[1] != NULL){
			it2->nodo =  it1-> nodo->child[1];
			cout << it2->nodo->value  << ' ';
			it2->sig = new node2;
			it2 = it2->sig;
		}
		
		it1 = it1->sig;
		
		if(it1->nodo == NULL){
			cout << '\n';
			//freeee encadenados1
			encadenados1 = encadenados2;	
			it1 = encadenados1;
			
			node2* encadenados2 = new node2;
			node2* it2 = encadenados2;
		}
	}	
}
int altura()
{
}


int main()
{
	bst bst;

	bst.insert(1);
	bst.insert(2);
	bst.insert(3);
	bst.imprimir_niveles();


	return 0;
}





















