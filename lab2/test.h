#include <stdio.h>
#include "controller.h"
#include <assert.h>

typedef struct
{
    controller contr;
}test;

void runTest(test t)
{
     t.contr.repo=createRepo();
   testAddExpanditure(t.contr);
  testModifyExpanditure(t.contr);
   testRemoveExpanditure(t.contr);
   testFilterExpanditure(t.contr);
  testSorting(t.contr);
}

void testAddExpanditure(controller c)
{
    repository repo=c.repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    addExpanditure(&repo,createExpanditure(1,50,1));
    addExpanditure(&repo,createExpanditure(1,3,4));
    addExpanditure(&repo,createExpanditure(1,12,5));
    assert(repo.v.length==5);
}

void testRemoveExpanditure(controller c)
{
    repository repo=c.repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    addExpanditure(&repo,createExpanditure(1,50,1));
    addExpanditure(&repo,createExpanditure(1,3,4));
    addExpanditure(&repo,createExpanditure(1,12,5));
    removeFromIndex(&repo,1);
    removeFromIndex(&repo,1);
    assert(repo.v.length==3);
}

void testModifyExpanditure(controller c)
{
    repository repo=c.repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    expanditure newExpanditure=createExpanditure(1,10,2);
    modifyExpanditure(&repo,newExpanditure,1);
    assert(repo.v.expanditures[1].money==10);

}

void testFilterExpanditure(controller c)
{
  repository repo=c.repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    addExpanditure(&repo,createExpanditure(1,50,1));
    addExpanditure(&repo,createExpanditure(1,3,4));
    addExpanditure(&repo,createExpanditure(1,12,5));
    vect filteredRepo=getExpandituresOfType(FOOD,repo);
    assert(filteredRepo.length==2);
}

void testSorting(controller c)
{
  repository repo=c.repo;
    addExpanditure(&repo,createExpanditure(1,5,1));
    addExpanditure(&repo,createExpanditure(1,0,2));
    addExpanditure(&repo,createExpanditure(1,50,1));
    addExpanditure(&repo,createExpanditure(1,3,4));
    addExpanditure(&repo,createExpanditure(1,12,5));
    vect sortedRepo=getSortedRepoBySum(repo,1);
    assert(sortedRepo.expanditures[0].money==0);
}

