#include <stdio.h>
#include <stdlib.h>

void fcfs() 
{
    int track[200], n, h, i, j, hm[200], tot_hm=0;

    printf("Enter the no of tracks : ");
    scanf("%d",&n);
    printf("Enter the track positions : ");
    
    for(i=0;i<n;i++)
        scanf("%d",&track[i]);
    
    printf("Enter the current position of the header : ");
    scanf("%d",&h);
    
    hm[0] = abs(h - track[0]);
    tot_hm += hm[0];
    
    printf("\nTracks traversed\tDifference between tracks\n");
    printf("%d\t\t\t%d\n",track[0],hm[0]);
    
    for(i=1;i<n;i++) 
    {
        hm[i] = abs(track[i] - track[i-1]);
        tot_hm += hm[i];
        printf("%d\t\t\t%d\n",track[i],hm[i]);
    }
    printf("\nTotal head movements : %d",tot_hm);
    printf("\nAverage head movements : %.2f",(float)tot_hm/n);
}

void scan() 
{
    int track[200], n, h, i, j, temp, hm[200], tot_hm=0;
    
    printf(" Enter the no of tracks : ");
    scanf("%d",&n);
    printf(" Enter the track positions : ");
    
    for(i=0;i<n;i++)
        scanf("%d",&track[i]);
    
    track[i] = 199;
    n++;
    
    for(j=0;j<n;j++)
        for(i=j+1;i<=n;i++)
            if(track[i] < track[j]) 
            {
                temp = track[i];
                track[i] = track[j];
                track[j] = temp;
            }
    printf(" Enter the current position of the header : ");
    scanf("%d",&h);
    
    for(i=0;i<n;i++)
        if(track[i] >= h)
        {
            hm[i] = track[i] - h;
            tot_hm += hm[i];
            j = i;
            break;
        }
    printf("\n Tracks traversed\tDifference between tracks\n");
    printf(" %d\t\t\t%d\n",track[i],hm[i]);
    
    while(track[i] < 199) 
    {
        i++;
        hm[i] = abs(track[i] - track[i-1]);
        tot_hm += hm[i];
        printf(" %d\t\t\t%d\n",track[i],hm[i]);
    }
    
    while(j > 0) 
    {
        j--;
        hm[j] = abs(track[j] - track[i]);
        tot_hm += hm[j];
        printf(" %d \t\t\t %d\n",track[j],hm[j]);
        i = j;
    }
    printf("\n Total head movements : %d",tot_hm);
    printf("\n Average head movements : %.2f",(float)tot_hm/n);
}

void cscan() 
{
    int track[200], n, h, i, j, temp, hm[200], tot_hm=0;
    
    printf(" Enter the no of tracks : ");
    scanf("%d",&n);
    printf(" Enter the track positions : ");
    
    for(i=1;i<=n;i++)
        scanf("%d",&track[i]);
    
    track[0] = 0;
    track[i] = 199;
    n++;
    for(j=0;j<n;j++)
        for(i=j+1;i<=n;i++)
            if(track[i] < track[j]) 
            {
                temp = track[i];track[i] = track[j];
                track[j] = temp;
            }
    
    printf(" Enter the current position of the header : ");
    scanf("%d",&h);
    for(i=0;i<n;i++)
        if(track[i] >= h)
        {
            hm[i] = track[i] - h;
            tot_hm += hm[i];
            j = i;
            break;
        }    
    printf("\n Tracks traversed\tDifference between tracks\n");
    printf(" %d\t\t\t%d\n",track[i],hm[i]);
    while(track[i] < 199) 
    {
        i++;
        hm[i] = abs(track[i] - track[i-1]);
        tot_hm += hm[i];
        printf(" %d\t\t\t%d\n",track[i],hm[i]);
    }
    i = 0;
    hm[i] = 199 - track[i];
    tot_hm += hm[i];
    printf(" %d\t\t\t%d\n",track[i],hm[i]);
    i++;
    
    while(i < j) 
    {
        hm[i] = abs(track[i] - track[i-1]);
        tot_hm += hm[i];
        printf(" %d\t\t\t%d\n",track[i],hm[i]);
        i++;
    }
    printf("\n Total head movements : %d",tot_hm);
    printf("\n Average head movements : %.2f",(float)tot_hm/n);
}

void main()
{
    int ch;
    char choice;
    do{
        printf("--------------------MENU--------------------\n\t1. FCFS\n\t2. SCAN\n\t3. C-SCAN\n\t4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        
        switch(ch) 
        {
            case 1 : fcfs();
                    break;
            case 2 : scan();
                    break;
            case 3 : cscan();
                    break;
            case 4 : exit(0);
                    break;
            default : printf("Invalid Choice !!!");
        }
        printf("\nDo you want to continue?(y/n): ");
        scanf(" %c", &choice);
    }while(choice=='y' || choice=='Y');
}
