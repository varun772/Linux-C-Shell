#include"header.h"
  
void ls(char* sou)
{ 
    //printf("%s\n",sou);
    int count=0;
    char *temp[10000];
    //printf("%lu\n",strlen(sou));
    char *token;
    token = strtok(sou," ");
    int exclu[100000];
    int exclucount=0;
    struct dirent *de;
    int acount=0,lcount=0,doublecount=0;
    while(token!=NULL)
    {
        temp[count]=token;
        //printf("%s\n",temp[count]);
        if(temp[count][0]== '-')
        {   if(temp[count][1]=='a' && strlen(temp[count])==2)
            {
                acount++;
                exclu[exclucount]=count;
                exclucount++;
            }
            if(temp[count][1]== 'l' && strlen(temp[count])==2)
            {
                lcount++;
                exclu[exclucount]=count;
                exclucount++;
            }
            if((temp[count][1]=='a' && temp[count][2]=='l') || (temp[count][1]=='l' && temp[count][2]=='a'))
            {
                doublecount++;
                acount++;
                lcount++;
            }
        }
        count++;
        token = strtok(NULL," ");

    }
    //printf("%d\n",count);
    //printf("%d\n",acount);
    //printf("%d\n",lcount);
        if(count==1)
        {
                DIR *dr = opendir("."); 
                    if (dr == NULL) 
                    { 
                        printf("Could not open current directory\n");
                        return;
                    } 
                    while ((de = readdir(dr)) != NULL) 
                    {
                            char *a[1];
                            a[0] = de->d_name;
                            //printf("%c\n",a[0][0]);
                            if(a[0][0]!='.')
                            printf("%s\n", de->d_name); 
                            //printf("%lu\n",de->d_ino);
                    }
                    closedir(dr);
        }
        else
        {
            int printcount=0;
            for(int i=1;i<count;i++)
            {
                if(((acount+lcount)==(count-1))|| (doublecount>0) || ((acount==0) && (lcount==0)))
                {
                    if(acount!=0 && lcount==0)
                    {
                        DIR *dr = opendir("."); 
                        if (dr == NULL) 
                        { 
                            printf("Could not open current directory\n" );
                            return;
                        } 
                        while ((de = readdir(dr)) != NULL) 
                        {
                                printf("%s\n", de->d_name); 
                        }
                        closedir(dr);
                    }
                    else if(acount==0 && lcount!=0)
                    {
                         DIR *dr = opendir("."); 
                        if (dr == NULL) 
                        { 
                            printf("Could not open current directory\n" ); 
                            return;
                        } 
                        int siz=0;
                        while ((de = readdir(dr)) != NULL)
                        {
                            struct stat file;
                            /*char *string[10000];
                            getcwd(string,10000);
                            strcat(string,"/");*/
                            struct passwd *pw;
                            struct group *gp;
                            char *a[1];
                            a[0] = de->d_name;
                            if(a[0][0]!='.')
                            {
                                stat(de->d_name,&file);  
                                printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
                                printf( (file.st_mode & S_IRUSR) ? "r" : "-");
                                printf( (file.st_mode & S_IWUSR) ? "w" : "-");
                                printf( (file.st_mode & S_IXUSR) ? "x" : "-");
                                printf( (file.st_mode & S_IRGRP) ? "r" : "-");
                                printf( (file.st_mode & S_IWGRP) ? "w" : "-");
                                printf( (file.st_mode & S_IXGRP) ? "x" : "-");
                                printf( (file.st_mode & S_IROTH) ? "r" : "-");
                                printf( (file.st_mode & S_IWOTH) ? "w" : "-");
                                printf( (file.st_mode & S_IXOTH) ? "x" : "-");
                                printf(" %ld ",file.st_nlink);
                                pw=getpwuid(file.st_uid);
                                gp=getgrgid(file.st_gid);
                                printf("%s ",pw->pw_name);
                                printf("%s ",gp->gr_name);
                                printf("%4ld ",file.st_size);
                                char* c=ctime(&file.st_mtime);
                                for(int i=4;i<=15;i++)
                                    printf("%c",c[i]);
                                printf(" %s\n",de->d_name);
                                siz+=file.st_blocks;
                            }	
                        }
                        printf("Total siz = %d\n",siz/2);
                    }
                    else if(acount !=0 && lcount!=0)
                    {
                        if(printcount<1)
                        {
                            //printf("%d\n",printcount);
                            DIR *dr = opendir("."); 
                            if (dr == NULL) 
                            { 
                                printf("Could not open current directory\n" );
                                return; 
                            } 
                            int siz=0;
                            while ((de = readdir(dr)) != NULL)
                            {
                            struct stat file;
                                /*char *string[10000];
                                getcwd(string,10000);
                                strcat(string,"/");*/
                                struct passwd *pw;
                                struct group *gp;
                                char *a[1];
                                a[0] = de->d_name;

                                    stat(de->d_name,&file);  
                                    printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
                                    printf( (file.st_mode & S_IRUSR) ? "r" : "-");
                                    printf( (file.st_mode & S_IWUSR) ? "w" : "-");
                                    printf( (file.st_mode & S_IXUSR) ? "x" : "-");
                                    printf( (file.st_mode & S_IRGRP) ? "r" : "-");
                                    printf( (file.st_mode & S_IWGRP) ? "w" : "-");
                                    printf( (file.st_mode & S_IXGRP) ? "x" : "-");
                                    printf( (file.st_mode & S_IROTH) ? "r" : "-");
                                    printf( (file.st_mode & S_IWOTH) ? "w" : "-");
                                    printf( (file.st_mode & S_IXOTH) ? "x" : "-");
                                    printf(" %ld ",file.st_nlink);
                                    pw=getpwuid(file.st_uid);
                                    gp=getgrgid(file.st_gid);
                                    printf("%s ",pw->pw_name);
                                    printf("%s ",gp->gr_name);
                                    printf("%4ld ",file.st_size);
                                    char* c=ctime(&file.st_mtime);
                                    for(int i=4;i<=15;i++)
                                        printf("%c",c[i]);
                                    printf(" %s\n",de->d_name);
                                    siz+=file.st_blocks;
                            }
                            printf("Total siz = %d\n",siz/2);
                            printcount++;
                        }
                    }
                    else
                    {
                        char *anna;
                        DIR *dr = opendir(temp[i]); 
                        if(dr!=NULL)
                        {
                            printf("%s\n",temp[i]);
                            printf(":");
                            printf("\n");
                        }
                        if (dr == NULL) 
                        { 
                            printf("Could not open current directory\n");
                            return;
                        } 
                        while ((de = readdir(dr)) != NULL) 
                        {
                            char *a[1];
                            a[0] = de->d_name;
                            //printf("%c\n",a[0][0]);
                            if(a[0][0]!='.')
                            printf("%s\n", de->d_name); 
                            //printf("%lu\n",de->d_ino);
                        }
                        closedir(dr);
                    }    
                }
                else 
                {
                    if(temp[i][0]!='-')
                    {
                        if(acount!=0 && lcount==0 )
                        {
                            DIR *dr = opendir(temp[i]); 
                            if (dr == NULL) 
                            { 
                                printf("Could not open current directory\n" ); 
                                return;
                            } 
                            while ((de = readdir(dr)) != NULL) 
                            {
                                    printf("%s\n", de->d_name); 
                            }
                            closedir(dr);
                        }
                        if(lcount!=0 && acount==0)
                        {
                            DIR *dr = opendir(temp[i]); 
                            if (dr == NULL) 
                            { 
                                printf("Could not open current directory\n" ); 
                                return;
                            } 
                            int siz=0;
                            while ((de = readdir(dr)) != NULL)
                            {
                                struct stat file;
                                /*char *string[10000];
                                getcwd(string,10000);
                                strcat(string,"/");*/
                                struct passwd *pw;
                                struct group *gp;
                                char *a[1];
                                a[0] = de->d_name;
                                if(a[0][0]!='.')
                                {
                                    stat(de->d_name,&file);  
                                    printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
                                    printf( (file.st_mode & S_IRUSR) ? "r" : "-");
                                    printf( (file.st_mode & S_IWUSR) ? "w" : "-");
                                    printf( (file.st_mode & S_IXUSR) ? "x" : "-");
                                    printf( (file.st_mode & S_IRGRP) ? "r" : "-");
                                    printf( (file.st_mode & S_IWGRP) ? "w" : "-");
                                    printf( (file.st_mode & S_IXGRP) ? "x" : "-");
                                    printf( (file.st_mode & S_IROTH) ? "r" : "-");
                                    printf( (file.st_mode & S_IWOTH) ? "w" : "-");
                                    printf( (file.st_mode & S_IXOTH) ? "x" : "-");
                                    printf(" %ld ",file.st_nlink);
                                    pw=getpwuid(file.st_uid);
                                    gp=getgrgid(file.st_gid);
                                    printf("%s ",pw->pw_name);
                                    printf("%s ",gp->gr_name);
                                    printf("%4ld ",file.st_size);
                                    char* c=ctime(&file.st_mtime);
                                    for(int i=4;i<=15;i++)
                                        printf("%c",c[i]);
                                    printf(" %s\n",de->d_name);
                                    siz+=file.st_blocks;
                                }	
                            }
                            printf("Total siz = %d\n",siz/2);
                        }
                        if(acount==0 && lcount ==0 )
                        {
                            DIR *dr = opendir(temp[i]); 
                            if (dr == NULL) 
                            { 
                                printf("Could not open current directory\n" );
                                return; 
                            } 
                            while ((de = readdir(dr)) != NULL) 
                            {
                                    char *a[1];
                                    a[0] = de->d_name;
                                    //printf("%c\n",a[0][0]);
                                    if(a[0][0]!='.')
                                    printf("%s\n", de->d_name); 
                                    //printf("%lu\n",de->d_ino);
                            }
                            closedir(dr);
                        }
                        if(acount!=0 && lcount!=0)
                        {
                            DIR *dr = opendir(temp[i]); 
                            if (dr == NULL) 
                            { 
                                printf("Could not open current directory\n" );
                                return; 
                            } 
                            int siz=0;
                            while ((de = readdir(dr)) != NULL)
                            {
                                struct stat file;
                                /*char *string[10000];
                                getcwd(string,10000);
                                strcat(string,"/");*/
                                struct passwd *pw;
                                struct group *gp;
                                char *a[1];
                                a[0] = de->d_name;

                                    stat(de->d_name,&file);  
                                    printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
                                    printf( (file.st_mode & S_IRUSR) ? "r" : "-");
                                    printf( (file.st_mode & S_IWUSR) ? "w" : "-");
                                    printf( (file.st_mode & S_IXUSR) ? "x" : "-");
                                    printf( (file.st_mode & S_IRGRP) ? "r" : "-");
                                    printf( (file.st_mode & S_IWGRP) ? "w" : "-");
                                    printf( (file.st_mode & S_IXGRP) ? "x" : "-");
                                    printf( (file.st_mode & S_IROTH) ? "r" : "-");
                                    printf( (file.st_mode & S_IWOTH) ? "w" : "-");
                                    printf( (file.st_mode & S_IXOTH) ? "x" : "-");
                                    printf(" %ld ",file.st_nlink);
                                    pw=getpwuid(file.st_uid);
                                    gp=getgrgid(file.st_gid);
                                    printf("%s ",pw->pw_name);
                                    printf("%s ",gp->gr_name);
                                    printf("%4ld ",file.st_size);
                                    char* c=ctime(&file.st_mtime);
                                    for(int i=4;i<=15;i++)
                                        printf("%c",c[i]);
                                    printf(" %s\n",de->d_name);
                                    siz+=file.st_blocks;
                            }
                            printf("Total siz = %d\n",siz/2);
                        }
                    }
                }
            }
        } 
}

