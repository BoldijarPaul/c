#pragma once
typedef struct
{
    int day,money,type;
}expanditure;

const int FOOD = 1;
const int TRANSPORT=2;
const int PHONE =3;
const int CLOTHES =4;
const int OTHERS = 5;

const char *TYPES[] = {"","Food","Transport","Phone","Clothes","Others"};

expanditure createExpanditure(int day,int money,int type)
{
    expanditure exp;
    exp.day=day;
    exp.money=money;
    exp.type=type;
    return exp;
}
