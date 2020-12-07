#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
int dnum=0;

typedef struct donor {
    int number;
    char name[20];
    char age[2];
    char phone[15];
    char email[20];
    char bloodgroup[5];
    struct donor *next;
    int count;
    } Donor;

Donor *firstd,*currentd,*newd;
int valid_choice(char choice)
{
    if(choice == '1'|| choice == '2'|| choice == '3'|| choice == '4'|| choice == '5'|| choice == 'Q' || choice == 'q')
        return 1;
    return 0;
}
int findnum (int recordnum)
{
    int record;
    record = recordnum;
    currentd = firstd;
    while(currentd != NULL)
    {
	if(currentd->number == record)
	     {
	   return 1;
	 }
	else
	{
	    currentd = currentd->next;
	}
    }
    return -1;
}
int prompt(void)
{
	char ch;
    fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if(ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}
int AddDonor(void)
{
    newd = (struct donor *)malloc(sizeof(struct donor));
    if(firstd==NULL)
	firstd = currentd = newd;
    else
    {
	currentd = firstd;
	while(currentd->next != NULL)
            currentd = currentd->next;
	currentd->next = newd;
	currentd = newd;
    }

    dnum++;
    printf("%27s: %5i\n","donor number",dnum);
    currentd->number = dnum;    /*dnum is used to give unique numbers*/
    printf("%27s: ","Enter donor name");
    scanf("%s",currentd->name);
    printf("%27s: ","Enter donor age");
    scanf("%s",currentd->age);
    printf("%27s: ","Enter blood group");
    scanf("%s",currentd->bloodgroup);
    printf("%27s: ","Enter contact Phone number");
    scanf("%s",currentd->phone);
    printf("%27s: ","Enter contact email");
    scanf("%s",currentd->email);

    printf("********  donor details added  ******** ");
    currentd->count=0;
    currentd->next = NULL;
	return 0;
}
int List(void)
{
    if(firstd==NULL)
    {
	puts("There are no donor details to display!");
	    return 1;
    }
    else
    {
	    printf("%6s %-20s %-2s %-5s %-15s %-20s\n","Acct#","Name","Age","Blood Group","Phone","Email");
	puts("------ -------------------- ------------- -------------------");
	currentd=firstd;
	do
	{
		printf("%6d: %-20s %-2s %-5s %-15s %-20s\n",\
		currentd->number,\
		currentd->name,\
		currentd->age,\
		currentd->bloodgroup,\
		currentd->phone,\
		currentd->email);

	}
	while((currentd=currentd->next) != NULL);
    }
	return 0;
}
int DeleteDonor(void)
{
    int record;
    if(firstd==NULL)
    {
	puts("There are no donor details to delete!");
	return 1;
    }
    List();
    printf("Enter donor number to delete: ");
    scanf("%d",&record);
    currentd = firstd;
    while(currentd != NULL)
    {
	if(currentd->number == record)
	{
	    if(currentd == firstd)
		firstd=currentd->next;
	free(currentd);
	    printf("donor deatils %d deleted!\n",record);
	    return 0;
	}
	else
	{
	    currentd = currentd->next;
	}
    }
    printf("donor details %d not found!\n",record);
	return 0;
 }
int Update(void)
{
    int record, result;
    if(firstd==NULL)
    {
	puts("There are no donor details to modify!");
	return 1;
    }

    printf("Enter donor number to modify or change: ");
    scanf("%d",&record);
    result = findnum(record);
    if( result >0 ){
	    printf("Contact no %d:\n",currentd->number);
	    printf("Name: %s\n",currentd->name);
	    if(prompt())
		    scanf("%s",currentd->name);
        printf("Age: %s\n",currentd->age);
	    if(prompt())
		    scanf("%s",currentd->age);
        printf("Blood Group: %s\n",currentd->bloodgroup);
	    if(prompt())
		    scanf("%s",currentd->bloodgroup);
	    printf("Phone: %s\n",currentd->phone);
	    if(prompt())
		    scanf("%s",currentd->phone);
	    printf("Email: %s\n",currentd->email);
	    if(prompt())
		    scanf("%s",currentd->email);
	    return 0;
	}
    printf("donor details %d was not found!\n",record);
	return 0;
}

int Search(void)
{
     char buff[20];
     if(firstd==NULL)
	{
	puts("There are no donor details to find!");
	    return 1;
    }
    printf("Enter blood group required: ");
    fflush(stdin);
    gets(buff);
    currentd = firstd;
    while(currentd != NULL)
    {
	if( strcmp(currentd->bloodgroup, buff) == 0 )
	    {
			printf("%6s %-20s %-2s %-15s %-20s\n","Acct#","Name","Age","Phone","Email");

	    printf("%6d: %-20s %-2s %-15s %-20s\n",\
	    currentd->number,\
	    currentd->name,\
	    currentd->age,\
	    currentd->phone,\
	    currentd->email);
			return 0;
	   }
		else
		{         currentd = currentd->next;  
		return 0;}
    }
    printf("donor %s was not found!\n",buff);
	  return 1;
}

