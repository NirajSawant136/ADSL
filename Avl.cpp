#include<iostream>
#include<stdlib.h>
using namespace std;

struct avl {

   int data;
   struct avl *l;
   struct avl *r;
}*r;

class avlTree{

	public:
			int height(avl *tr){

				int h = 0;
				if(tr != NULL){

					int leftHeight = height(tr->l);
					int rightHeight = height(tr->r);
					int maxHeight = max(leftHeight, rightHeight);
					h = maxHeight + 1;
				}
				return h;
			}

			int difference(avl *tr){

				int leftHeight = height(tr->l);
				int rightHeight = height(tr->r);
				int balanceFactor = leftHeight - rightHeight;

				return balanceFactor;
			}

			avl *RRrotate(avl *pr){

				avl *tr;
				tr = pr->r;
				pr->r = tr->l;
				tr->l = pr;

				return tr;
			}

			avl *LLrotate(avl *pr){

				avl *tr;
				tr = pr->l;
				pr->l = tr->r;
				tr->r = pr;

				return tr;
			}

			avl *LRrotate(avl *pr){

				avl *tr;
				tr = pr->l;
				pr->l = RRrotate(tr);

				return LLrotate(pr);
			}

			avl *RLrotate(avl *pr){

				avl *tr;
				tr = pr->r;
				pr->r = LLrotate(tr);

				return RRrotate(pr);
			}

			avl *balance(avl *tr){

				int balanceFactor = difference(tr);
				if(balanceFactor > 1){

					if(difference(tr->l) > 0)
						tr = LLrotate(tr);
					else
						tr = LRrotate(tr);
				}
				else if(balanceFactor < -1){

					if(difference(tr->r) > 0)
						tr = RLrotate(tr);
					else
						tr = RRrotate(tr);
				}
				return tr;
			}
			
			avl *insert(avl *tr, int k){

				if(tr == NULL){
					
					tr = new avl;
					tr->data = k;
					tr->l = tr->r = NULL;
					return tr;
				}
				else if(k < tr->data){

					tr->l = insert(tr->l, k);
					tr = balance(tr);
				}
				else if(k >= tr->data){

					tr->r = insert(tr->r, k);
					tr = balance(tr);
				}
				return tr;
			}

			void Search(avl *tr, int k){

				if(tr == NULL){

					cout<<"\nElement not found!";
					return;
				}
				if(tr->data == k){
					
					cout<<"\nElement found!";
					return;
				}
				else if(tr->data > k){

					Search(tr->l, k);
				}
				else{

					Search(tr->r, k);
				}
			} 

			void Inorder(avl *tr){

				if(tr == NULL)
					return;

				Inorder(tr->l);
				cout<<tr->data<<" ";
				Inorder(tr->r);
			}

			void Postorder(avl *tr){

				if(tr == NULL)
					return;

				cout<<tr->data<<" ";
				Postorder(tr->l);
				Postorder(tr->r);
			}

			void Preorder(avl *tr){

				if(tr == NULL)
					return;

				Preorder(tr->l);
				Preorder(tr->r);
				cout<<tr->data<<" ";
			}

};
int main(){
	
	int c, i;
   	avlTree Avl;
   	while (1) {
   		cout<<"\n-----------------------------------------------------";
      	cout<<"\n1.Insert Element into the tree" << endl;
      	cout<<"2.InOrder traversal" << endl;
      	cout<<"3.PreOrder traversal" << endl;
      	cout<<"4.PostOrder traversal" << endl;
      	cout<<"5.Search Element in tree" << endl;
      	cout<<"6.Exit" << endl;
      	cout<<"\nEnter your Choice: ";
      	cin>>c;
      	
      	cout<<endl;
      	
      	switch (c) {
         	
         	case 1:
            		cout<<"Enter value to be inserted -> ";
            		cin>>i;
            		r = Avl.insert(r, i);
         			break;
         
         	case 2:
            		cout<<"Inorder Traversal -> ";
            		Avl.Inorder(r);
            		cout << endl;
         			break;
         	
         	case 3:
            		cout<<"Preorder Traversal -> ";
            		Avl.Preorder(r);
            		cout << endl;
         			break;
         
         	case 4:
            		cout<<"Postorder Traversal -> ";
            		Avl.Postorder(r);
            		cout << endl;
         			break;
         			
         	case 5:
         			int k;
         			cout<<"Enter element you want to search -> ";
         			cin>>k;
         			Avl.Search(r, k);
         			break;

         	case 6:
            		_Exit(1);
         			break;
         	
         	default:
            		cout<<"Invalid Choice" << endl;
      }
   }

   return 0;
}