#pragma once
#include "domain.h"

typedef struct
{
    expanditure expanditures[1000];
    int length;
}repository;


/* removes the item at the position wanted
    returns 1 if sucessfull, 0 if not
*/
int removeFromIndex(repository *repo,int position)
{
    if(repo->length==0)
    {
        return 0;
    }
    if(position<0 || position>=repo->length){
        return 0;
    }
    if(position==0 && repo->length==1)
    {
        printf("removed primu boss");
        repo->length--;
        return 1;
    }
    int i;
    for (i=position; i<repo->length-1; i++)
    {
        repo->expanditures[i]=repo->expanditures[i+1];
    }
    repo->length--;
    return 1;
}

/*adds a new expanditure to repo
exp.day should be > 0
exp.money should be > 0
exp.type should be in [1,5]
returns 1 if added successfully,else 0
*/
int addExpanditure(repository *repo,expanditure exp)
{
    if(!validateExpanditure(exp))
        return 0;
    repo->expanditures[repo->length++]=exp;
    return 1;
}
/*
modifies the expanditure at the desired position.
returns 0 or 1 (fail/success)
*/
int modifyExpanditure(repository *repo,expanditure newExpanditure,int position)
{
    if(position<0 || position>=repo->length){
        return 0;
    }
    if(!validateExpanditure(newExpanditure))
    {
        return 0;
    }
    else{
        repo->expanditures[position]=newExpanditure;
    }
}
/*
validates an expanditure, the day and money should be > 0
and the type should be one if the existing one
*/
int validateExpanditure(expanditure exp)
{
    if(exp.day<0 || exp.money<0) {return 0;}
    if(exp.type<1 || exp.type>5) {return 0;}
    return 1;

}




