#include<stdio.h>
#include<stdlib.h>

struct node
{
 	int date;
 	struct node *left;
 	struct node *right;
};

struct node* root = NULL;//kok varsayilan olarak NULL 

struct node* newNode(int key)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));//dugum olusturma
	temp->date = key;
	temp->left = NULL;
	temp ->right = NULL;
		
	if (root == NULL)
		root = temp;
	return temp;
};

void inorder(struct node *root)// cikti almak icin finksiyon
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->date);
		inorder(root->right);
	}
}

struct node* add (struct node* node, int key)// BTC' ye sayi ekleme fonksiyonu
{
	if(node == NULL)
		return newNode(key);
	
	if(key < node->date)
	node ->left = add(node->left, key);
	
	else if (key > node->date)
		node ->right = add(node->right, key);
	return node;
};

int main ()
{
	int sec;
	
	while(1 == 1)//kullanicinin secim yaapacigi menu
	{
		printf("1)Sayi Ekleme:");
		printf("\n2)Kok Dondur");
		printf("\nLutfen Secim Yapiniz: ");
		scanf("%d",&sec);
		
		switch(sec)
		{
			case 1:
				printf("\nEklemek istediginiz sayiyi girniz: ");
				scanf("%d",&sec);
				add(root,sec);
				break;
			
			case 2:
			inorder(root);
			break;	
		}
		
	}
	return 0;
}
