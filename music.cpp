#include <iostream>
using namespace std;

struct playlist
 {
 	int id;
 	struct song * song ;
 	playlist * prev , * next ;
 }*head;

struct song 
 {
 	int id;
 	song * prev , * next ;
 }*head1,*tail1;
 
struct stack 
 {
 	char a ;
 	int id ;
 	struct playlist * playlist ;
 	stack * next ;
	}*head2;
	
void reverse(playlist * head)
{
    song * temp = head->song;
    song * temp1 , * temp2 , * temp3 = head->song,* pos ;
    
    while ( temp->next!= temp3 );
     {
     	pos = temp;
     	temp1 = temp ;
     	temp = temp -> next ;
     	//temp2 = temp1 -> next;
     	temp1 -> next = pos -> prev ;
     	temp1 -> prev = temp ;
     	temp1 = temp1 ;
     	pos = temp1;
			
		 }
head->song = temp1->next;
}	

int add_songs ( playlist * temp , int n)
 {
 	
	if(temp->song==NULL)
	{
		song *temp1;
		temp1=new song;
		temp1->id=n;
		temp1->prev=temp1;
		temp1->next=temp1;
		temp->song=temp1;
		//head1=temp1;
	return 1;
	}
	else
	{
		song *temp1,*temp2;;
		temp1=temp->song;
		while(temp1->next!=temp->song)
		{
			temp1=temp1->next;
			
		}
		temp2=new song;
		temp2->id=n;
		temp2->prev=temp1;
		temp1->next=temp2;
		temp2->next=temp->song;
		//head1->prev=temp2;
		//tail1=temp2;
		return 1;
	} 
	return 0;
 }
 
int deleted ( playlist * temp , int n )
 {
 	int flag=0;
	song *temp1,*temp2;
	temp1=temp->song;
	int count=0;
	do
	{
		count++;
		if(temp1->id==n)
		{
			
			flag=1;
			break;
		}
		temp1=temp1->next;
	}while(temp1!=temp->song);
	if(flag==1&&count!=1)
	{
		cout<<temp1->id;
		temp2=temp1->next;
		temp2->prev=temp1->prev;
		temp1->prev->next=temp2;
		delete temp1;
		return 1;
	}
	else if(flag=1&&count==1)
	{
		if(temp1->next==temp->song)	
		{
			temp->song=NULL;
			delete temp1;
			return 1;
		}
		temp2=temp1->next;
		cout<<temp1->id;
		temp2=temp1->next;
		temp2->prev=temp1->prev;
		temp1->prev->next=temp2;
		delete temp1;
		temp->song=temp2;
		
		return 1;
	}
	return 0;
}


void push(char a,int id,playlist *temp)
{
	 stack *temp2,*temp1;
	if(head2==NULL)
	{
		head2=new stack;
		head2->a=a;
		head2->id=id;
		head2->playlist=temp;
		head2->next=NULL;
	}
	else
	{
		temp1=head2;
		while(temp1->next!=NULL)
		temp1=temp1->next;
		temp2=new stack;
		temp2->a=a;
		temp2->id=id;
		temp2->playlist=temp;
		temp2->next=NULL;
		temp1->next=temp2;
	}
}
void pop()
{
	struct stack *temp,*temp1;
	temp=head2;
	temp1=temp->next;
	if(temp->next==NULL)
	{
		if(temp->a=='a')
		deleted(temp->playlist,temp->id);
		else if(temp->a=='b')
		add_songs(temp->playlist,temp->id);
		head2=NULL;
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp=temp->next;
			temp1=temp1->next;
		}
		temp->next=NULL;
		if(temp1->a=='a')
		deleted(temp1->playlist,temp1->id);
		else if(temp1->a=='b')
		add_songs(temp1->playlist,temp1->id);
		else if(temp1->a=='c')
		reverse(temp1->playlist);
		
	}
	
}

playlist * create_playlist ( playlist * head )
 {
 	int n ;
 	playlist * temp = new playlist , * temp1 = head ;
 	cout << "\n Enter Playlist Id ";
 	cin >> n ;
 	if( head == NULL )
 	 {
 		temp -> id =  n ;
 		temp -> song = NULL;
 		temp -> prev = NULL ;
 		temp -> next = NULL ;
 		head = temp ;
 		return head;
		}
	else
	 {
	 	while ( temp1 -> next != NULL )
	 	 temp1 = temp1 -> next ;
	 	 
	 	temp -> id =  n ;
 		temp -> song = NULL;
 		temp -> prev = temp1 ;
 		temp -> next = NULL ;
 		temp1 -> next = temp ;
 		return temp1;
		 }	
 	return 0 ;
 }
 

 
void display ( playlist * tempp )
 {
 song *temp1 = tempp -> song ;
	do
	{
		cout<<temp1->id<<endl;
		temp1=temp1->next;
	}while( temp1!= tempp->song );	
 }
 
void swap (int * a , int * b)
 {
 	int c = *a ;
 	*a = *b ;
 	*b = c ;
 }
 

 
int main()
 {
 playlist * temp ;
 temp = create_playlist( head );

 
 int n;

 while(1)
  {
  	cout<<"\n Enter 1 To Add Songs \n 2 To Play Them \n 3 To Delete Them \n 4 To Break \n 5 To Undo \n 6 To Reverse" ;
  	cin >> n ;
		
		if( n == 1 )
		 {
		 	int m;
			cout<<"\n Enter The ID Of Song"<<endl;
			cin>>m;
		 	add_songs( temp , m); 
		 	push('a',m,temp);
		 }
		  
		if( n == 2 )
		 display ( temp );
		if( n== 3 )
		  {
		  	int p ;
		  	cout<<"Enter Song ID to be deleted \n";
 				cin >> p ;
		  	deleted ( temp , p );
		  	push('d',p,temp);
			}
		 	
		 	
		if( n==4 )
		  break;
		  
		if( n == 5 )
		 pop();
		 
		if( n == 6)
		 {
		 	reverse(temp);
		 	push('c',-1,temp);
		 }
		 
	}
 }

