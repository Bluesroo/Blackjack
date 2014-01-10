#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Creating card struct
typedef struct
{
    int num;
    char s[15];
    char n[10];
} card;

int main(void)
{
    //Variables
    int i = 51, r, temp, counter = 0, hp, hd, dc = 0, hs = 0, z1, z2, acep = 0, aced = 0, ace;
    char club[] = " of Clubs", heart[] = " of Hearts", diamond[] = " of Diamonds", spade[] = " of Spades";
    char j[] = "Jack", q[] = "Queen", k[] = "King";
    
    //The "Deck"
    card ca; strcpy(ca.s, club); strcpy(ca.n, "Ace"); ca.num = 11;
    card sa; strcpy(sa.s, club); strcpy(sa.n, "Ace"); sa.num = 11;
    card da; strcpy(da.s, club); strcpy(da.n, "Ace"); da.num = 11;
    card ha; strcpy(ha.s, club); strcpy(ha.n, "Ace"); ha.num = 11;
    card c2; strcpy(c2.s, club); strcpy(c2.n, "Two"); c2.num = 2;    
    card c3; strcpy(c3.s, club); strcpy(c3.n, "Three"); c3.num = 3;    
    card c4; strcpy(c4.s, club); strcpy(c4.n, "Four"); c4.num = 4;    
    card c5; strcpy(c5.s, club); strcpy(c5.n, "Five"); c5.num = 5;
    card c6; strcpy(c6.s, club); strcpy(c6.n, "Six"); c6.num = 6;
    card c7; strcpy(c7.s, club); strcpy(c7.n, "Seven"); c7.num = 7;
    card c8; strcpy(c8.s, club); strcpy(c8.n, "Eight"); c8.num = 8;
    card c9; strcpy(c9.s, club); strcpy(c9.n, "Nine"); c9.num = 9;
    card c10; strcpy(c10.s, club); strcpy(c10.n, "Ten"); c10.num = 10;  
    card cj; strcpy(cj.s, club); strcpy(cj.n, j); cj.num = 10;    
    card cq; strcpy(cq.s, club); strcpy(cq.n, q); cq.num = 10;    
    card ck; strcpy(ck.s, club); strcpy(ck.n, k); ck.num = 10;
    card d2; strcpy(d2.s, diamond); strcpy(d2.n, "Two"); d2.num = 2;    
    card d3; strcpy(d3.s, diamond); strcpy(d3.n, "Three"); d3.num = 3;    
    card d4; strcpy(d4.s, diamond); strcpy(d4.n, "Four"); d4.num = 4;    
    card d5; strcpy(d5.s, diamond); strcpy(d5.n, "Five"); d5.num = 5;
    card d6; strcpy(d6.s, diamond); strcpy(d6.n, "Six"); d6.num = 6;
    card d7; strcpy(d7.s, diamond); strcpy(d7.n, "Seven"); d7.num = 7;
    card d8; strcpy(d8.s, diamond); strcpy(d8.n, "Eight"); d8.num = 8;
    card d9; strcpy(d9.s, diamond); strcpy(d9.n, "Nine"); d9.num = 9;
    card d10; strcpy(d10.s, diamond); strcpy(d10.n, "Ten"); d10.num = 10;  
    card dj; strcpy(dj.s, diamond); strcpy(dj.n, j); dj.num = 10;    
    card dq; strcpy(dq.s, diamond); strcpy(dq.n, q); dq.num = 10;    
    card dk; strcpy(dk.s, diamond); strcpy(dk.n, k); dk.num = 10;    
    card s2; strcpy(s2.s, spade); strcpy(s2.n, "Two"); s2.num = 2;    
    card s3; strcpy(s3.s, spade); strcpy(s3.n, "Three"); s3.num = 3;    
    card s4; strcpy(s4.s, spade); strcpy(s4.n, "Four"); s4.num = 4;    
    card s5; strcpy(s5.s, spade); strcpy(s5.n, "Five"); s5.num = 5;
    card s6; strcpy(s6.s, spade); strcpy(s6.n, "Six"); s6.num = 6;
    card s7; strcpy(s7.s, spade); strcpy(s7.n, "Seven"); s7.num = 7;
    card s8; strcpy(s8.s, spade); strcpy(s8.n, "Eight"); s8.num = 8;
    card s9; strcpy(s9.s, spade); strcpy(s9.n, "Nine"); s9.num = 9;
    card s10; strcpy(s10.s, spade); strcpy(s10.n, "Ten"); s10.num = 10;  
    card sj; strcpy(sj.s, spade); strcpy(sj.n, j); sj.num = 10;    
    card sq; strcpy(sq.s, spade); strcpy(sq.n, q); sq.num = 10;    
    card sk; strcpy(sk.s, spade); strcpy(sk.n, k); sk.num = 10; 
    card h2; strcpy(h2.s, heart); strcpy(h2.n, "Two"); h2.num = 2;    
    card h3; strcpy(h3.s, heart); strcpy(h3.n, "Three"); h3.num = 3;    
    card h4; strcpy(h4.s, heart); strcpy(h4.n, "Four"); h4.num = 4;    
    card h5; strcpy(h5.s, heart); strcpy(h5.n, "Five"); h5.num = 5;
    card h6; strcpy(h6.s, heart); strcpy(h6.n, "Six"); h6.num = 6;
    card h7; strcpy(h7.s, heart); strcpy(h7.n, "Seven"); h7.num = 7;
    card h8; strcpy(h8.s, heart); strcpy(h8.n, "Eight"); h8.num = 8;
    card h9; strcpy(h9.s, heart); strcpy(h9.n, "Nine"); h9.num = 9;
    card h10; strcpy(h10.s, heart); strcpy(h10.n, "Ten"); h10.num = 10;  
    card hj; strcpy(hj.s, heart); strcpy(hj.n, j); hj.num = 10;    
    card hq; strcpy(hq.s, heart); strcpy(hq.n, q); hq.num = 10;    
    card hk; strcpy(hk.s, heart); strcpy(hk.n, k); hk.num = 10; 
    
    //Seeding for the random number for shuffling
    srand(time(NULL));
    
    //Putting the cards into a "deck"
    card d[] = {ca, da, sa, ha, c2, c3, c4, c5, c6, c7, c8, c9, c10, cj, cq, ck, d2, d3, d4, d5, d6, d7, d8, d9, d10, dj, dq, dk, s2, s3, s4, s5, s6, s7, s8, s9, s10, sj, sq, sk, h2, h3, h4, h5, h6, h7, h8, h9, h10, hj, hq, hk};  

    //Shuffling the "deck"
    while (i > 1)
    {       
        r = rand() %(i - 1);
        
        card temp = d[r];
        card temp2 = d[i];
        
        d[i] = temp;
        d[r] = temp2;
                
        i--;
    }
    
    //Dealing
    while (hs == 0)
    {
        hp = 0;
        hd = 0;
        printf("Your first card is %s%s.\n", d[dc].n, d[dc].s);
        hp = d[dc].num;
        if (d[dc].num == 11)
        {
            acep++;
        }
        dc++;
        
        printf("The dealer draws its first card.\n");
        hd = d[dc].num;
        z1 = dc;
        if (d[dc].num == 11)
        {
            aced++;
        }
        dc++;
                
        printf ("Your second card is %s%s.\n", d[dc].n, d[dc].s);
        hp = hp + d[dc].num;
        if (d[dc].num == 11)
        {
            acep++;
        }
        dc++;
                
        printf("The dealer draws its second card.\n");
        hd = hd + d[dc].num;
        z2 = dc;
        if (d[dc].num == 11)
        {
            aced++;
        }
        dc++;
        
        //Checking for 21        
        if (hp == 21)
        {
            printf("You have 21! You win this hand!\n");
        }
        // Asking for hit/ stay
        else
        {
            do
            {
                printf("Would you like to hit, or stay? (Yes: 1, No: 2)\n");
                scanf("%i", &hs);
            }
            while (hs < 1 || hs > 2);
        }
        //If staying
        if (hs == 2)
        {
            printf("Your total for this hand was %i.\n", hp);
            printf("The dealer has %s%s and %s%s.\n", d[z1].n, d[z1].s, d[z2].n, d[z2].s);
            
            //The dealer's turn
            while (hd < hp || hd <= 16)
            {
                printf("The dealer decides to hit. It gets %s%s.\n", d[dc].n, d[dc].s);
                hd = hd + d[dc].num;
                if (d[dc].num == 11)
                {
                    aced++;
                }
                
                while (hd > 21 && aced > 0)
                {
                    hd = hd - 10;
                    aced--;
                }
                dc++;
            }
            
            //Outcome
            if (hd > 21)
            {
                printf("The dealer has bust! You win with %i!\n", hp);
            }
            
            if (hd > hp && hd <= 21)
            {
                printf("Oh no! The dealer wins with %i!\n", hd);
            }
            
            if (hp > hd && hp <= 21)
            {
                printf("You win!\n");
            }
            
            if (hp == hd)
            {
                printf("It's a tie!\n");
            }
            
            //Another hand?
            printf("Would you like to play another hand? (Yes: 1, No: 2)\n");
            scanf("%i", &hs);
            if (hs == 2)
            {
                printf("Thank you for playing!");
                return 0;
            }
            else
            {
                hs = 0;
                hp = 0;
                hd = 0;
                acep = 0;
                aced = 0;
            }
        }
        
        //If hitting
        else
        {
            while (hs == 1)
            {
                printf("Your new card is %s%s\n", d[dc].n, d[dc].s);
                hp = hp + d[dc].num;
                if (d[dc].num == 11)
                {
                    acep++;
                }
                
                while (hp > 21 && acep > 0)
                {
                    hp = hp - 10;
                    acep--;
                }
                
                dc++;

                if (hp > 21)
                {
                    printf("Oh no! You've bust!\nWould you like to play another hand?\n");
                    scanf("%i", &hs);
                    if (hs == 2)
                    {
                        printf("Thank you for playing!");
                        return 0;
                    }
                    else
                    {
                        hs = 0;
                        hp = 0;
                        hd = 0;
                        acep = 0;
                        aced = 0;
                    }
                }
                else
                {
                    //Option to draw again
                    do
                    {
                        printf("Would you like to hit, or stay? (1/2)\n");
                        scanf("%i", &hs);
                    }
                        while (hs < 1 || hs > 2);
                }
                
                if (hs == 2)
                {
                    printf("Your total for this hand was %i.\n", hp);
                    printf("The dealer has %s%s and %s%s.\n", d[z1].n, d[z1].s, d[z2].n, d[z2].s);

                    //The dealer's turn
                    while (hd <= 16)
                    {
                        printf("The dealer decides to hit. It gets %s%s.\n", d[dc].n, d[dc].s);
                        hd = hd + d[dc].num;
                        if (d[dc].num == 11)
                        {
                            aced++;
                        }
                        
                        dc++;
                    }

                    //Outcome
                    if (hd > 21)
                    {
                        printf("The dealer has bust! You win!\n");
                    }

                    if (hd > hp && hd <= 21)
                    {
                        printf("Oh no! The dealer wins!\n");
                    }
                    
                    if (hp > hd)
                    {
                        printf("You win!\n");
                    }
                    
                    if (hp == hd)
                    {
                        printf("It's a tie!\n");
                    }

                    //Another hand?
                    do
                    {
                        printf("Would you like to play another hand? (Yes: 1, No: 2)\n");
                        scanf("%i", &hs);
                    }
                        while (hs < 1 || hs > 2);
                    
                    if (hs == 2)
                    {
                        printf("Thank you for playing!");
                        return 0;
                    }
                    else
                    {
                        hs = 0;
                        hp = 0;
                        hd = 0;
                        acep = 0;
                        aced = 0;
                    }
                }
            }
        }
    }
    
    return 0;
}
