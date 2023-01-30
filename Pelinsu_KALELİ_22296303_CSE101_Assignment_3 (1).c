#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void loto6_49(int,char);

int main()
{
    char tercih;
    int adet;

    printf("6/49 SAYISAL LOTO (O.G)\n");
    printf("-----------------------\n");
    printf("K - Kolon Oyna\nB - Bilet Oyna");

    printf("\nKolon mu, Bilet mi (K/B)? ");
    scanf(" %c",&tercih);



    printf("Kac adet %c oynanacak?\n",tercih);
    scanf(" %d",&adet);

    loto6_49(adet,tercih);

    return 0;
}


void loto6_49(int amount,char choice)
{
    int random,coupon[5],coupon2[5],check;

    srand(time(NULL));

    switch(choice)
    {
        case 'k':
        case 'K':
            {
                for(int i = 1; i<=amount; i++)
                {
                    printf("\n %d. kolon\n",i);
                    printf("--------------------\n");

                        for(int j = 0; j < 6; j++)
                    {
                            random = rand()%49+1;
                            check = 0;

                        for(int a=0; a<6; a++)
                            if(coupon2[a]==random)
                                {
                                    //For spotting the equal random values we tick check, then leave the loop.
                                    check = 1;
                                    break;
                                }

                        if(check==0)
                        {
                            //If there are no equal values, we assign.
                            coupon2[j]=random;

                        }
                        else
                        {
                            //if there are two equal values, we decrease the j integer to turn back and retake a new value.
                            j--;
                        }
                    }

                        for (int pass = 0;pass<5;pass++)
                            {
                                for(int w=0;w<5;w++)
                                {
                                    if(coupon2[w]>coupon2[w+1])
                                    {
                                        //For ascending order.
                                        int tmp;
                                        tmp = coupon2[w];
                                        coupon2[w]=coupon2[w+1];
                                        coupon2[w+1]=tmp;
                                    }

                                }
                            }

                            for(int g =0;g<5;g++)
                            {
                                printf(" %d\t",coupon2[g]);
                            }

                }

                printf("\n");
                break;
            }
        case 'b':
        case 'B':
            {
                for(int i = 0;i<amount;i++)
                {
                    for(int a = 0;a<8;a++)
                    {
                        printf("\n %d.Bilet %d. kolon\n",i+1,a+1);
                        printf("--------------------\n");

                        for(int j = 0; j < 6; j++)
                    {
                            random = rand()%49+1;
                            check = 0;

                        for(int a=0; a<6; a++)
                            if(coupon[a]==random)
                                {
                                    //For spotting the equal random values we tick check, then leave the loop.
                                    check = 1;
                                    break;
                                }
                        if(check==0)
                        {
                            //If there are no equal values, we assign.
                            coupon[j]=random;
                        }
                        else
                        {
                            //if there are two equal values, we decrease the j integer to turn back and retake a new value.
                            j--;
                        }

                    }

                        for(int pass=0;pass<5;pass++)
                        {
                            for(int w=0;w<5;w++)
                            {
                                if(coupon[w]>coupon[w+1])
                                {
                                    //For ascending order.
                                    int tmp;
                                    tmp = coupon[w];
                                    coupon[w]=coupon[w+1];
                                    coupon[w+1]=tmp;
                                }
                            }
                        }
                        for(int g=0;g<5;g++)
                        {
                            printf(" %d\t",coupon[g]);
                        }
                    }
                }
                    printf("\n");
                    break;
            }

        default:
            {
                printf("Gecersiz girdi, %c diye bir secenek yok.",choice);
                break;
            }
    }

}
