void ghost1_direction()
{
int ghost1;
    srand((unsigned) time(NULL));

    ghost1=(rand()%4)+1;


    if(ghost1==1)
        ghost1_dir=UP1;
    else if(ghost1==2)
        ghost1_dir=DOWN1;
    if(ghost1==3)
       ghost1_dir=LEFT1;
    else
        ghost1_dir=RIGHT1;
}
void ghost2_direction()
{
int ghost2;
        //srand((unsigned) time(NULL));
        ghost2=(rand()%4)+1;

        if(ghost2==1)
        ghost2_dir=UP1;
    else if(ghost2==2)
        ghost2_dir=DOWN1;
   if(ghost2==3)
       ghost2_dir=LEFT1;
    else
        ghost2_dir=RIGHT1;

        ghost22=ghost2;
}
int main()
{
    
    return 0;
}