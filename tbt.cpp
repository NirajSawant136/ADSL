#include<iostream>
using namespace std;

struct Node{

	int data;
	Node *left , *right;
	int lth , rth;

};

class tbt{

	private:Node *root , *d;

	public:	tbt(){

				root = d = NULL;

			}
			void create(){

				char n;
				int data;
				do{

					cout<<"\nENTER DATA-> ";
					cin>>data;
					append(data);
					cout<<"WANT TO ADD MORE?(Y/N)";
					cin>>n;

				}while(n == 'y'||n == 'Y');

			}
			void append(int data){

				Node *tr = root;
				Node *par = NULL;

				while(tr != NULL){

					if(data == tr->data){

						return;
					}

					par = tr;
					if(data < tr->data){

						if(tr->lth == 0)
							tr = tr->left;
						else
							break;
					}

					else{

						if(tr->rth == 0)
							tr = tr->right;
						else
							break;
					}
				}
				Node *tmp = new Node;
				tmp->data = data;
				tmp->lth = 1;
				tmp->rth = 1;

				if(par == NULL){

					root = tmp;
					tmp->left = tmp->right = d;
				}
				else if(data < par->data){

					tmp->left = par->left;
					tmp->right = par;
					par->lth = 0;
					par->left = tmp;
				}
				else{

					tmp->left = par;
					tmp->right = par->right;
					par->rth = 0;
					par->right = tmp;
				}
			}
			Node *inorderSuccessor(Node *tr){

				if(tr->rth == 1)
					return(tr->right);

				tr = tr->right;
				while(tr->lth == 0)
					tr = tr->left;

				return(tr);

			}
			void Inorder(){

				cout<<"Inorder Traversal ->\n";
				if(root == d){
					cout<<"Empty Tree";
					return;
				}
				Node *tr = root;
				while(tr->lth == 0)
					tr = tr->left;

				while(tr != NULL){

					cout<<tr->data<<" ";
					tr = inorderSuccessor(tr);
				}
				cout<<endl;

			}
			void Preorder(){

				Node *tr = root;
				while(tr != NULL){

					while(tr->lth == 0){

						cout<<tr->data;
						tr = tr->left;

					}
					while(tr->rth == 1){

						tr = tr->right;
						if(tr != NULL){

							cout<<tr->data;

						}
						else
							return;
						tr = tr->right;
					}

				}

			}

};

int main()
{
	/* code */
	tbt t;
	t.create();
	t.Inorder();
//	t.Preorder();
	return 0;

}