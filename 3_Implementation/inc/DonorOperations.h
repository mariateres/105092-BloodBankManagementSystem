#ifndef DONOROPERATIONS_H_INCLUDED
#define DONOROPERATIONS_H_INCLUDED
extern int dnum;

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

int prompt(void);
int findnum (int);
void clearInput(void);
int AddDonor(void);
int List(void);
int DeleteDonor(void);
int Update(void);
int Search(void);


#endif // DONOROPERATIONS_H_INCLUDED
