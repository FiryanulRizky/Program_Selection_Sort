#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct sort{
	int selection;
	struct sort *next;
}node;

node * head = NULL;
void list()
{
	printf ("\n1. Menambahkan Data\n");
	printf ("2. Sort Data\n");
	printf ("3. Keluar");
}
node* aktif() {
	
	node* result = (node *)malloc(sizeof(node));
	result->next = NULL;
	return result;
}
void tambah( int nilai)
{
	node *data1,*data2;
	int a=0,b=0;
	
	data1 = aktif();
	data1->selection = nilai;

	if(head == NULL)
	{
		head = data1;
	}
	else{
		data2 = head;
		while (data2->next!=NULL)
		{
			data2=data2->next;
		}
		data2->next = data1;
	}
}
void tampil()
{
	node *data2;
	if (head == NULL)
	{
		printf ("\nData Kosong");
	}
	else {
		printf ("Daftar Angka : ");
		for ( data2 = head; data2!=NULL ; data2=data2->next)
		{
			printf (" {%d} ",data2->selection);
		}
	}
}

void sorting()
{
	node *h = head, *i, *j;
    for(i = h; i!=NULL && i->next!=NULL; i=i->next)
    {
        node *min;
        min = i;
        for(j = i->next; j!=NULL ; j=j->next)
        {
            if(j->selection < min->selection)
                min=j;
        }
        if(min!=i)
        {
            int temp;
            temp = min->selection;
            min->selection = i->selection;
            i->selection = temp;
        }
    }
    head = h;	
}
int main()
{
	int a=0;	
	int nilai;
	char filename[20] = {"Input Angka.txt"};
	FILE *cek;
	cek=fopen(filename,"r");
	while (fscanf(cek,"%d",&nilai)!=EOF)
	{
		tambah(nilai);
	}
	fclose(cek);
	tampil();
	printf ("\n");
	sorting();
	tampil();
	
	
}

