#pragma once
#include "repository.h"


typedef struct
{
    repository repo;
}controller;


/* returns a repository of expanditures of selected type, from a selected repository */
repository getExpandituresOfType(int type,repository repo)
{
    repository newRepo;
    newRepo.length=0;
    int i;
    for(i=0; i<repo.length; i++)
    {
        if(repo.expanditures[i].type==type)
        {
            newRepo.expanditures[newRepo.length]=repo.expanditures[i];
            newRepo.length++;
        }
    }
    return newRepo;
}


/* returns a repository of expanditures sorted by sum, ascending or descending (1 or 0) */
repository getSortedRepoBySum(repository repo,int ascending)
{
    repository newRepo;
    newRepo.length=0;
    int i,j;
    for(i=0; i<repo.length; i++)
    {
        newRepo.expanditures[newRepo.length]=repo.expanditures[i];
        newRepo.length++;
    }

    for(i=0; i<newRepo.length-1; i++)
    {
        for(j=i+1; j<newRepo.length; j++)
        {
            if(ascending)
            {
                if(newRepo.expanditures[i].money>newRepo.expanditures[j].money)
                {
                    expanditure aux=newRepo.expanditures[i];
                    newRepo.expanditures[i]=newRepo.expanditures[j];
                    newRepo.expanditures[j]=aux;
                }
            }else
            {
                if(newRepo.expanditures[i].money<newRepo.expanditures[j].money)
                {
                    expanditure aux=newRepo.expanditures[i];
                    newRepo.expanditures[i]=newRepo.expanditures[j];
                    newRepo.expanditures[j]=aux;
                }
            }
        }
    }

    return newRepo;
}

/* returns a repository of expanditures sorted by type, ascending or descending (1 or 0) */
repository getSortedRepoByType(repository repo,int ascending)
{
    repository newRepo;
    newRepo.length=0;
    int i,j;
    for(i=0; i<repo.length; i++)
    {
        newRepo.expanditures[newRepo.length]=repo.expanditures[i];
        newRepo.length++;
    }

    for(i=0; i<newRepo.length-1; i++)
    {
        for(j=i+1; j<newRepo.length; j++)
        {
            if(ascending)
            {
                if(newRepo.expanditures[i].type>newRepo.expanditures[j].type)
                {
                    expanditure aux=newRepo.expanditures[i];
                    newRepo.expanditures[i]=newRepo.expanditures[j];
                    newRepo.expanditures[j]=aux;
                }
            }else
            {
                if(newRepo.expanditures[i].type<newRepo.expanditures[j].type)
                {
                    expanditure aux=newRepo.expanditures[i];
                    newRepo.expanditures[i]=newRepo.expanditures[j];
                    newRepo.expanditures[j]=aux;
                }
            }
        }
    }

    return newRepo;
}

