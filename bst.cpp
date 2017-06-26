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

struct lista
{
	node* nodo;
	node* sig;
};

void bst::imprimir_niveles()
{ lista* encadenados1;
	if (root !=  NULL){
		cout << root->value;
		
		encadenados1->nodo = root->child[0];
		cout << root->child[0]->value;
		
		encadenados1 -> sig = root->child[1];
		cout << root->child[1]-> value;
	}
	lista* encadenados2;
	while(encadenados1 != NULL || encadenados2 != NULL){		
		encadenados2 -> nodo = encadenados1-> nodo ->child[0];
		cout << encadenados1->nodo->child[0]->value;
		encadenados2 -> sig =  encadenados1-> nodo->child[1];
		cout << encadenados1->nodo->child[1]->value;
		encadenados1 = encadenados1 -> sig;
		if (encadenados1 == NULL)
			encadenados1 = encadenados2;
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
	bst.insert(4);
	bst.insert(5);
	bst.insert(6);
	
	
	
	return 0;
}























