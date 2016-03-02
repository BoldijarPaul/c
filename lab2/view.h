#pragma once
#include "controller.h"

typedef struct
{
    controller contr;
} view;

/*
reads an expanditure from keyborad
*/
expanditure readExpanditure()
{
    expanditure exp;
    printf("Expanditure day: ");
    scanf("%d",&exp.day);
    printf("Expanditure money: ");
    scanf("%d",&exp.money);
    printf("Expanditure type:(Food=1,Transport=2,Phone=3,Clothes=4,Others=5) ");
    scanf("%d",&exp.type);
    return exp;
}

/*
 returns the option that the user wants, check the values from the prinf string
*/
int getOption()
{
    printf("1) Add expanditure\n2) List expanditures\n3) Modify expanditures\n4) Remove expanditure\n5) Filter\n6) Sort by sum ascending\n7) Sort by sum descending\n8) Sort by type ascending\n9) Sort by type descending\n0) Exit\n");
    int option=0;
    scanf("%d",&option);
    return option;
}
/*
modifies a expanditure from a repo, the user will next read the position, and new expanditure wanted
*/
void modifiExpanditure(repository *repo){
    int position;
    printf("Please choose the expanditure id: (position) ");
    scanf("%d",&position);
    expanditure exp=readExpanditure();
    int modified=modifyExpanditure(repo,exp,position);
    printf(modified?"Successfully modified!\n":"Not modified, check your input!\n");
}

void showExpandituresOfType(repository repo)
{
    int type;
    printf("Expanditure type:(Food=1,Transport=2,Phone=3,Clothes=4,Others=5) ");
    scanf("%d",&type);
    repository newRepo=getExpandituresOfType(type,repo);
    listExpanditures(newRepo);
}
/*
adds new expanditure to the repo
*/
void addNewExpanditure(repository *repo)
{
    expanditure exp=readExpanditure();
    int added=addExpanditure(repo,exp);
    printf(added?"Added successfully!\n":"Not added, invalid input\n");

}

/*
list all expanditures from selected repo
*/
void listExpanditures(repository repo){
    int i=0;
    for(i=0; i<repo.length; i++)
    {
        printf("ID: %d, DAY: %d, MONEY: %d, TYPE: %s\n",i,repo.expanditures[i].day,repo.expanditures[i].money,TYPES[repo.expanditures[i].type]);
    }
}
/* removes a expanditure from repository */
void removeExpanditure(repository *repo)
{
    int position;
    printf("Position(id): ");
    scanf("%d",&position);
    int removed=removeFromIndex(repo,position);
    printf(removed?"Removed!\n":"Not removed!Check your position maybe!\n");
}
/* starts the app*/
void start(controller *contr)
{

    contr->repo.length=0;
    repository repo=contr->repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    addExpanditure(&repo,createExpanditure(1,50,1));
    addExpanditure(&repo,createExpanditure(1,3,4));
    addExpanditure(&repo,createExpanditure(1,12,5));
    while(1){
        int option;
        option=getOption();
        if(option==1){
           addNewExpanditure(&repo);
        }
        if(option==2)
        {
            listExpanditures(repo);
        }
        if(option==3)
        {
            modifiExpanditure(&repo);
        }
        if(option==4)
        {
            removeExpanditure(&repo);
        }
        if(option==5)
        {
            showExpandituresOfType(repo);
        }
        if(option==6)
        {
            listExpanditures(getSortedRepoBySum(repo,1));
        }
        if(option==7)
        {
            listExpanditures(getSortedRepoBySum(repo,0));
        }
        if(option==8)
        {
            listExpanditures(getSortedRepoByType(repo,1));
        }
        if(option==9)
        {
            listExpanditures(getSortedRepoByType(repo,0));
        }
        if(option==0){
            printf("Bye");
            return;
            break;
        }
    }
}
