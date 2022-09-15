#include <stdio.h>
#include <stdlib.h>

int main()
{
    char TabNb1[80] = {0}, TabNb2[80] = {0}, sign1, sign2, calcul, TabRes[81] = {0};
    int ic1, ic2, ires, iNb1, iNb2, PlusGrand, i, retenue, fin, res;
    printf("entrer le 1er nombre d'au plus 80 chiffres (valeur absolue)\n");
    scanf("%c",&TabNb1[0]);
    iNb1=0;
    while (TabNb1[iNb1]!='\n')/*On utilise une boucle indetermin�e qui se termine lorsque le caract�re lu est '/n', afin de remplir les tableaux TabNb1 et TabNb2*/
    {
        iNb1=iNb1+1;
        scanf("%c",&TabNb1[iNb1]);
    }
    printf("entrer le second nombre d'au plus 80 chiffres (valeur absolue)\n");
    scanf("%c",&TabNb2[0]);
    iNb2=0;
    while (TabNb2[iNb2]!='\n')
    {
        iNb2=iNb2+1;
        scanf("%c",&TabNb2[iNb2]);
    }
    printf("Entrer le signe du premier entier '+' ou '-'\n");
    scanf(" %c", &sign1);
    printf("Entrer le signe du deuxieme entier\n");
    scanf(" %c", &sign2);
    /*Apr�s avoir demand� le signe des entiers, on regarde lequel des deux, en valeur absolue, est le plus grand*/

    if (iNb1 > iNb2)
    {
        fin=iNb1;
        PlusGrand=1;
    }
    else
    {
        fin=iNb2;
        if (iNb1 < iNb2)
        {
            PlusGrand=2;
        }
        else /* Si les deux entiers font la m�me taille, on compare caract�re par caract�re pour d�terminer le plus grand*/
        {
            i=0;
            while(TabNb1[i]==TabNb2[i] && i<=fin)
            {
                i=i+1;
            }
            if (TabNb1[i]>TabNb2[i])
            {
                PlusGrand=1;
            }
            else
            {
                PlusGrand=2;
            }
        }

    }
    printf("Quelle operation voulez-vous faire ? '+' pour addition et '-' pour soustraction\n");
    scanf(" %c", &calcul);
    retenue=0;
    i=fin;
    ic1=iNb1-1;
    ic2=iNb2-1;
    /*On initialise les variables necessaires au calcul puis on entre dans la premi�re condition, le cas o� l'op�ration nous amen�e a effectu�e une addition*/
    if ((calcul=='+' && sign1=='+' && sign2=='+') || (calcul=='+' && sign1=='-' && sign2=='-') || (calcul=='-' && sign1=='+' && sign2=='-') || (calcul=='-' && sign1=='-' && sign2=='+') ) /* BON*/
    {
        ires=fin;/*On initialise ires de mani�re � laisser de la place au d�but de tableau en cas de retenue*/
        for (i=fin; i>0; i=i-1)/*Cette boucle POUR va de la fin du plus grand nombre jusqu'� 1, permet d'englober tout le calcul*/
        {
            if (ic2>=0 && ic1>=0)/*Si aucun des deux nombres n'est encore fini alors on effectue on addition normale*/
            {
                res=(TabNb1[ic1]-'0')+(TabNb2[ic2]-'0')+retenue;

                if (res>=10)/*Si le calcul effectu� est >=10 cel� signifie qu'il faut enregistrer dans le tableau des r�sultat le modulo de la valeur calcul�e et ajout� une retenue pour le prochain calcul*/
                {
                    retenue=1;
                    TabRes[ires]=((res%10)+'0');
                }
                else/*Sinon il n'y a pas de retenue et on affecte a tabRes le r�sultat du calcul (0<=res<10)*/
                {
                    retenue=0;
                    TabRes[ires]=(res+'0');
                }
            }
            if (ic2<0)/*Si l'un des deux entiers est fini avant l'autre alors on rempli le tableau de r�sultat par les valeurs restantes du tableau non vide*/
            {
                res=(TabNb1[ic1]-'0')+retenue;/*On calcule le r�sultat et on regarde s'il est >=10 ou pas*/
                if (res>=10)
                {
                    TabRes[ic1+1]=(res%10)+'0';/*Si c'est le cas, on enregistre le modulo du r�sultat et on ajoute une retenue pour le calcul suivant*/
                    retenue=1;
                }
                else/*Sinon on utilise une boucle POUR qui permet dans le cas o� le calcul est <10, de remplir le tableau de r�sultat par les valeurs du tableau restant*/
                {
                    for (i=ic1+1; i>=0; i=i-1)
                    {
                        TabRes[i]=((TabNb1[i-1]-'0')+retenue)+'0';
                        retenue=0;
                    }
                }
            }
            else if (ic1<0)/*M�me m�thode que pour ic2<0*/
            {
                res=(TabNb2[ic2]-'0')+retenue;
                if (res>=10)
                {
                    TabRes[ic2+1]=(res%10)+'0';
                    retenue=1;
                }
                else
                {
                    for (i=ic2+1; i>=0; i=i-1)
                    {
                        TabRes[i]=((TabNb2[i-1]-'0')+retenue)+'0';
                        retenue=0;
                    }
                }
            }
            /*On passe aux valeurs suivantes dans les trois tableaux gr�ce aux indices*/
            ires=ires-1;
            ic1=ic1-1;
            ic2=ic2-1;
        }
        if(retenue==1)/*Si � la fin du calcul il reste une retenue alors il faut rajouter un 1 devant l'entier r�sultat*/
        {
            TabRes[0]='1';
        }
        if((calcul=='+' && sign1=='+' && sign2=='+') || (calcul=='-' && sign1=='+' && sign2=='-'))
        {
            printf("Le r�sultat est:");
        }
        else
        {
            printf("Le r�sultat est: -");
        }

        if(retenue==1)/*S'il y avait une derni�re retenue (on a donc ajout� un 1 en position 0) on affiche le tableau depuis la position 0*/
        {
            for (ires=0; ires<=fin; ires++)
            {
                printf(" %c", TabRes[ires]);
            }
        }
        else /*Sinon on affiche le tableau depuis la position 1*/
        {
            for (ires=1; ires<=fin; ires++)
            {
                printf(" %c", TabRes[ires]);
            }
        }
    }
/*on rentre dans la deuxi�me condition calculatoire, le cas de la soustraction. Lors d'une soustaction, il y a une retenue si la diff�rence entre les deux chiffres est <0*/
    if ((calcul=='+' && sign1=='+' && sign2=='-') || (calcul=='-' && sign1=='+' && sign2=='+') || (calcul=='+' && sign1=='-' && sign2=='+') || (calcul=='-' && sign1=='-' && sign2=='-'))
    {
        ires=fin-1;
        if(PlusGrand==1)/*Dans le cas de la soustraction on a deux cas qui change l'op�ration effectu�e et le signe du r�sultat: soit l'entier 1 est plus grand soit l'entier 2 est plus grand (ou �gal)*/
        {
            for (i=fin-1; i>=0; i=i-1)/*Si le premier est le plus grand alors on fait le premier moins le deuxi�me. Cette boucle permet de faire le calcul en se d�pla�ant de la fin du plus grand entier jusqu'� 1*/
            {
                if ((TabNb1[ic1]>TabNb2[ic2]) && ic2>=0)/*On compare la valeur des chiffres en cours de calcul. Si celui du premier entier est plus grand alors on effectue une soustraction*/
                {
                    res=(TabNb1[ic1]-'0')-(TabNb2[ic2]-'0')-retenue;
                    retenue=0;
                }
                else if ((TabNb1[ic1]==TabNb2[ic2]) && ic2>=0)/*Si les deux chiffres compar�s sont �gaux alors le r�sultat d�pend de s'il y a une retenue ou pas*/
                {
                    if (retenue==1)/*Si il y a une retenue alors il faut ajout� 10 � la soustraction. Et il y aura une retenue au calcul suivant*/
                    {
                        res=((TabNb1[ic1]-'0')+10)-(TabNb2[ic2]-'0')-retenue;
                        retenue=1;
                    }
                    else /*Sinon(il n'y a pas de retenue), alors le r�sultat est 0 car les chiffres sont �gaux.*/
                    {
                        res=0;
                        retenue=0;
                    }
                }
                else if ((TabNb1[ic1]<TabNb2[ic2]) && ic2>=0)/*On traite maintenant le cas o� le second chiffre est sup�rieur. Il faut alors ajout� 10 au calcul et pr�ciser qu'il y aura une retenue au prochaine calcul.*/
                {
                    res=((TabNb1[ic1]-'0')+10)-(TabNb2[ic2]-'0')-retenue;
                    retenue=1;
                }
                else if (ic2<0) /*Le cas o� le deuxi�me entier (qui est le plus petit dans le cas trait�) n'a plus de chiffre sans que le premier soit fini*/
                {
                    res=(TabNb1[ic1]-'0')-retenue;/*On v�rifie alors si le calcul est <0 ou pas*/
                    if (res<0)/*Si c'est le cas on ajoute 10 au r�sultat et on ajoute une retenue pour le calcul suivant*/
                    {
                        TabRes[ic1]=(res+10)+'0';
                        retenue=1;
                    }
                    else/*Si ce n'est pas le cas on rempli le tableau de r�sultat par les chiffres restant dans l'entier le plus grand � l'aide d'une boucle pour*/
                    {
                        for (i=ic1; i>=0; i=i-1)
                        {
                            TabRes[i]=((TabNb1[i]-'0')-retenue)+'0';
                            retenue=0;
                        }
                    }
                }
                if (ic2>=0)/*On entre les valeurs calcul�es (si le deuxi�me chiffre est fini les valeurs sont entr�es juste au dessus c'est pour cela qu'on entre les valeurs QUE si le deuxi�me nombre n'est pas encore fini)*/
                {
                    TabRes[ires]=(res+'0');
                }
                /*On passe aux valeurs suivantes*/
                ires=ires-1;
                ic1=ic1-1;
                ic2=ic2-1;
            }
            if ((calcul=='+' && sign1=='+' && sign2=='-') || (calcul=='-' && sign1=='+' && sign2=='+'))
                printf ("Le resultat est:");
            else
            {
                printf ("Le resultat est: -");
            }
            for(ires=0; ires<fin; ires++)
            {
                printf(" %c", TabRes[ires]);
            }
        }
        else /*Si le plus grand nombre est le deuxi�me entier alors on effectue la m�me chose qu'au dessus en faisant une soustraction du deuxi�me par le premier entier cette fois.*/
        {
            for (i=fin-1; i>=0; i=i-1)
            {
                if (TabNb2[ic2]>TabNb1[ic1] && ic1>=0)
                {
                    res=(TabNb2[ic2]-'0')-(TabNb1[ic1]-'0')-retenue;
                    retenue=0;
                }

                else if ((TabNb1[ic1]==TabNb2[ic2]) && ic1>=0)
                {
                    if (retenue==1)
                    {
                        res=((TabNb2[ic2]-'0')+10)-(TabNb1[ic1]-'0')-retenue;
                        retenue=1;
                    }
                    else
                    {
                        res=0;
                        retenue=0;
                    }
                }
                else if ((TabNb2[ic2]<TabNb1[ic1]) && ic1>=0)
                {
                    res=((TabNb2[ic2]-'0')+10)-(TabNb1[ic1]-'0')-retenue;
                    retenue=1;
                }
                else if (ic1<0)
                {
                    res=(TabNb2[ic2]-'0')-retenue;
                    if (res<0)
                    {
                        TabRes[ic2]=(res+10)+'0';
                        retenue=1;
                    }
                    else
                    {
                        for (i=ic2; i>=0; i=i-1)
                        {
                            TabRes[i]=((TabNb2[i]-'0')-retenue)+'0';
                            retenue=0;
                        }
                    }
                }
                if (ic1>=0)
                {
                    TabRes[ires]=(res+'0');
                }
                ires=ires-1;
                ic1=ic1-1;
                ic2=ic2-1;
            }
            if ((calcul=='+' && sign1=='+' && sign2=='-') || (calcul=='-' && sign1=='+' && sign2=='+'))
                printf ("Le resultat est: -");
            else
            {
                printf ("Le resultat est:");
            }
            for(ires=0; ires<fin; ires++)
            {
                printf(" %c", TabRes[ires]);
            }
        }
    }

    return 0;
}
