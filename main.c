#include "graph_sims_header.h"

int main()
{
    int ordre;
    initAllegro();
    BITMAP *page,*rect,*it;
    page = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    rect = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(rect);
    /*unsigned long currentMillis=0, previousMillis=0;
    unsigned long sec = 0;
    srand(time(NULL));
    currentMillis = clock();
    sec = clock();
    if ((currentMillis - previousMillis) >= 15000) {
        previousMillis = currentMillis;
    }
    sec -= previousMillis;
    sec = sec / 10000;
    textprintf_ex(page, font, 0, 0, makecol(255, 0, 255), -1, "%d", sec);*/




    cases tabcases[23][35];
    Bitmaps *bitmaps=initialisation_bitmaps();

    for(int i=0;i<23;i++)
    {
        for(int j=0;j<35;j++)
        {
            tabcases[i][j].type=0;
            tabcases[i][j].intersection=0;
            tabcases[i][j].passage=0;
            tabcases[i][j].x=j*21;
            tabcases[i][j].y=i*11;
            printf("tab[%d][%d]=x=%d y=%d  ",j,i,tabcases[i][j].x,tabcases[i][j].y);
        }printf("\n\n\n");
    }





    BITMAP* route;
    route= load_bitmap("routelosange.bmp",NULL);

    maps(bitmaps->maps,page);







    for(int i=0;i<64;i++)
    {
        line(page,0,10+21*i,20+41*i,0,makecol(86,122,65));
        line(page ,1024-41*i,0,1024,2+21*i,makecol(86,122,65));

    }


    while (!key[KEY_ESC])
    {

        clear_bitmap(rect);

        blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);

        rectfill(page, 0, 0, 1024, 70, makecol(0,0,0));
        rectfill(page, 920, 0, 1024, 768, makecol(0,0,0));
        outils(bitmaps,rect,page);
        pause(bitmaps->pause,page);
        sauvegarde(bitmaps->sauvegarde,page);
        quitter(bitmaps->quitter,page);
        temps(bitmaps->temps,page);
        niveaux(bitmaps->niveau0,bitmaps->niveau_1,bitmaps->niveau_2,page);



       /*
            //printf("%d\n",sec);
        }*/


       // if(mouse_b&1)MAJ_graph(ordre);

            show_mouse(rect);

        blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }


    destroy_bitmap(rect);
    destroy_bitmap(page);


    return 0;
}
END_OF_MAIN();
