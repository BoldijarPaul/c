#pragma once
#include "repository.h"


typedef struct
{
    repository repo;
}controller;


/* returns a repository of expanditures of selected type, from a selected repository */
vect getExpandituresOfType(int type,repository repo)
{
    vect v = createVect();
    v.length=0;
    int i;
    for(i=0; i<repo.v.length; i++)
    {
        if(repo.v.expanditures[i].type==type)
        {
            v.expanditures[v.length]=repo.v.expanditures[i];
            v.length++;
        }
    }
    return v;
}


/* returns a repository of expanditures sorted by sum, ascending or descending (1 or 0) */
vect getSortedRepoBySum(repository repo,int ascending)
{
    vect v=createVect();
    v.length=0;
    int i,j;
    for(i=0; i<repo.v.length; i++)
    {
        v.expanditures[v.length]=repo.v.expanditures[i];
        v.length++;
    }

    for(i=0; i<v.length-1; i++)
    {
        for(j=i+1; j<v.length; j++)
        {
            if(ascending)
            {
                if(v.expanditures[i].money>v.expanditures[j].money)
                {
                    expanditure aux=v.expanditures[i];
                    v.expanditures[i]=v.expanditures[j];
                    v.expanditures[j]=aux;
                }
            }else
            {
                if(v.expanditures[i].money<v.expanditures[j].money)
                {
                    expanditure aux=v.expanditures[i];
                    v.expanditures[i]=v.expanditures[j];
                    v.expanditures[j]=aux;
                }
            }
        }
    }

    return v;
}

/* returns a repository of expanditures sorted by type, ascending or descending (1 or 0) */
vect getSortedRepoByType(repository repo,int ascending)
{
    vect v=createVect();
    v.length=0;
    int i,j;
    for(i=0; i<v.length; i++)
    {
        v.expanditures[v.length]=v.expanditures[i];
        v.length++;
    }

    for(i=0; i<v.length-1; i++)
    {
        for(j=i+1; j<v.length; j++)
        {
            if(ascending)
            {
                if(v.expanditures[i].type>v.expanditures[j].type)
                {
                    expanditure aux=v.expanditures[i];
                    v.expanditures[i]=v.expanditures[j];
                    v.expanditures[j]=aux;
                }
            }else
            {
                if(v.expanditures[i].type<v.expanditures[j].type)
                {
                    expanditure aux=v.expanditures[i];
                    v.expanditures[i]=v.expanditures[j];
                    v.expanditures[j]=aux;
                }
            }
        }
    }

    return v;
}

