#include <iostream>
using namespace std;

struct Node{

	char op;
	Node *right,*left;
};

class stack
{
	private:Node* s[20];int top;

	public:	stack(){

				top=-1;
			}

			void push(Node *n){

				s[++top]=n;
			}

			Node *pop(){

				return s[top--];
			}

			int isempty(){

				if(top == -1)
					return 1;
				else
					return 0;
			}

			char TOP(){

				return s[top]->op;
			}
};

class Tree
{
	Node *root;

	public:
			void create(){

				Node *tr,*tt;
				stack operand,optr;
				char exp[20];
				cout<<"\nEnter the infix expression -> ";
				cin>>exp;


				for(int i = 0;exp[i] != '\0';i++){

					tr = new Node;
					tr->op = exp[i];
					tr->right = tr->left=NULL;
					if(tr->op == '+'||tr->op == '-'||tr->op == '*'||tr->op == '/'){

						if(optr.isempty())
							optr.push(tr);


						else{

							if(precedence(exp[i])<=precedence(optr.TOP())){

										tt = optr.pop();
										tt->right = operand.pop();
										tt->left = operand.pop();
										operand.push(tt);
									}

							optr.push(tr);
								}
					    }

					else
						operand.push(tr);
					
				}

				while(!optr.isempty()){

					tt = optr.pop();
					tt->right = operand.pop();
					tt->left = operand.pop();
					operand.push(tt);
				}

				root = tt;
			}

			int precedence(char x){

				switch(x){

					case '+':	return 1;
								break;

					case '-':	return 1;
								break;

					case '*':	return 2;
								break;

					case '/':	return 2;
								break;
				}
				return 0;
			}

			void postOrder(){

				Node *cn = root;
				stack s1,s2;
				s1.push(cn);
				while(!s1.isempty()){

					cn=s1.pop();
					if(cn->left != NULL)
						s1.push(cn->left);
					if(cn->right != NULL)
						s1.push(cn->right);
					s2.push(cn);
				}

				while(!s2.isempty()){

					cn = s2.pop();
					cout<<cn->op;
				}
			}

			void preOrder(){

				stack s;
				Node *cn = root;
				while(1){

					while(cn != NULL){

						s.push(cn);
						cout<<cn->op;
						cn = cn->left;
					}
					if(!s.isempty()){

						cn = s.pop();
						cn = cn->right;
					}
					else break;
				}

			}

			void inOrder(){

				stack s;
				Node *cn = root;
				while(1){

					while(cn != NULL){

						s.push(cn);
						cn=cn->left;
					}
					if(!s.isempty()){

						cn = s.pop();
						cout<<cn->op;
						cn = cn->right;
					}
					else break;
				}
			}

};

int main(){

	Tree T;
	int choice;
		do{

			cout<<"\n1) ENTER INFIX EXPRESSION ";
			cout<<"\n2) POSTFIX TRAVERSAL";
			cout<<"\n3) PREFIX TRAVERSAL";
			cout<<"\n4) INFIX TRAVERSAL";
			cout<<"\n5) EXIT";
			cout<<"\n\nEnter your choice:";
			cin>>choice;

			switch(choice){

				case 1: T.create();
						break;
				case 2:	cout<<"\nPOSTFIX -> ";
						T.postOrder();
						break;

				case 3:	cout<<"\nPREFIX -> ";
						T.preOrder();
						break;

				case 4:	cout<<"\nINFIX -> ";
						T.inOrder();
						break;

				case 5:	break;

				default: cout<<"\nEnter valid choice!";
			}

		}while(choice != 5);

	return 0;
}

