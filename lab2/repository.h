#pragma once
#include "domain.h"

typedef struct
{
    expanditure *expanditures;
    int length;
}vect;

typedef struct
{
    vect v;
}repository;

vect createVect()
{
    vect v;
    v.length=0;
    v.expanditures=malloc(sizeof(expanditure) * 10);
    return v;
}
repository createRepo()
{
    repository repository;
    repository.v=createVect();
    return repository;
}


/* removes the item at the position wanted
    returns 1 if sucessfull, 0 if not
*/
int removeFromIndex(repository *repo,int position)
{
    if(repo->v.length==0)
    {
        return 0;
    }
    if(position<0 || position>=repo->v.length){
        return 0;
    }
    if(position==0 && repo->v.length==1)
    {
        printf("removed primu boss");
        repo->v.length--;
        return 1;
    }
    int i;
    for (i=position; i<repo->v.length-1; i++)
    {
        repo->v.expanditures[i]=repo->v.expanditures[i+1];
    }
    repo->v.length--;
    return 1;
}

void fixSize(repository *repo,int newLength)
{

    expanditure *newExpanditures=malloc(sizeof(repository)*newLength);
    int i;
    for(i=0;i<repo->v.length; i++)
    {
        newExpanditures[i]=repo->v.expanditures[i];
    }
    free(repo->v.expanditures);
    repo->v.expanditures=newExpanditures;
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
    fixSize(repo,repo->v.length+1);
    repo->v.expanditures[repo->v.length++]=exp;
    return 1;
}

/*
modifies the expanditure at the desired position.
returns 0 or 1 (fail/success)
*/
int modifyExpanditure(repository *repo,expanditure newExpanditure,int position)
{
    if(position<0 || position>=repo->v.length){
        return 0;
    }
    if(!validateExpanditure(newExpanditure))
    {
        return 0;
    }
    else{
        repo->v.expanditures[position]=newExpanditure;
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




