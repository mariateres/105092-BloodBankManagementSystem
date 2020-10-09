

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "DonorOperations.h"


Donor *firstd,*currentd,*newd;

int main()
{
    dnum=0;
    FILE *datafile;
    char *filename = "details.dat";
    char ch;
    firstd = NULL;
    datafile = fopen(filename,"r");

    if(datafile)
    {
	    firstd = (struct donor *)malloc(sizeof(struct donor));

	    currentd = firstd;
	    while(1)
	    {
		    newd = (struct donor *)malloc(sizeof(struct donor));
		    fread(currentd,sizeof(struct donor),1,datafile);
		    if(currentd->next == NULL)
			    break;
		    currentd->next = newd;
	    currentd->count=0;
		    currentd = newd;
	    }
	    fclose(datafile);

	    dnum = currentd->number;

    }

    do
    {
	fflush(stdin);
	puts("\n******BLOOD BANK MANAGEMENT SYSTEM*****");
	puts("-- -----------------------------");
	puts("1 - Add a new donor details");
	puts("2 - Delete history of donor details");
	puts("3 - List all donor details");
	puts("4 - Modify donor details");
	puts("5 - Find a donor detail by blood group");
	puts("-- -----------------------------");
	puts("Q - Save and quit\n");
	printf("\tYour choice:");
	ch = getchar();
	    valid_choice(ch);
	    ch = toupper(ch);
	switch(ch)
	{
	    case '1':
		puts("Add a new donor details \n");
		fflush(stdin);
		AddDonor();
		break;
	    case '2':
		puts("Delete a donor details \n");
		DeleteDonor();
		break;
	    case '3':
		puts("List all donor details \n");
		List();
		break;
	    case '4':
		puts("Modify a donor details \n");
		Update();
		break;
	    case '5':
		puts("Find a donor by blood group\n");
		Search();
		break;
	    case 'Q':
		puts("Save and quit\n");

		default:
		break;
	}
    }
    while(ch != 'Q');
    currentd = firstd;
    if(currentd == NULL)
	    return(0);
    datafile = fopen(filename,"w");
    if(datafile == NULL)
    {
	    printf("Error writing to %s\n",filename);
	    return(1);
    }
    while(currentd != NULL)
    {
	    fwrite(currentd,sizeof(struct donor),1,datafile);
	    currentd = currentd->next;
    }
    fclose(datafile);
    return(0);
}
