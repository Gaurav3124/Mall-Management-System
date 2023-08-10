#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <math.h>
#define n 15

#define	MAXLINE	 8192  
int clientfd;
int total_bill=0;
char bill_file[5][30]= {"202001115_bill.txt","202001116_bill.txt","202001209_bill.txt","202001456_bill.txt","202001455_bill.txt"};
int fd=0;

int total_amt = 0;
void welcome();
void login();
void menu();
void add();
void select_item();
void list_products();

void welcome(void)

{
	printf("                                                                                                         \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t* * * * * * * * * * * * * * * * * *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\t     WELCOME TO \t  *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\t  CITY CENTRE MALL\t  *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t* * * * * * * * * * * * * * * * * *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t    Asgard, Center of Nine Realms\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t 042069\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\"WE BELIEVE IN CLASS\"\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("-----------------------------------------------------------------------------------------------------------------\n");
	getchar();

}
void login()
{

	int valid=0;
	int a=0, i=0;
	char username[20];
	char password[20];
	char uname1[20]="202001115";
	char uname2[20]="202001116";
	char uname3[20]="202001209";
	char uname4[20]="202001456";
	char uname5[20]="202001455";
	char pword[20]="itpro";
	
	
		system("clear");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LOGIN PAGE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	do
	{
		
	
		printf("\n			Please Enter Your Valid Username & Password.");
		printf("\n\n					Username:");
		scanf("%s",username);
		
		printf("\n			    		Password:");
		scanf("%s",password);
		
		// Checking among 5 CLIENT IDs
		
		if((strcmp(username,uname1)==0||strcmp(username,uname2)==0||strcmp(username,uname3)==0||strcmp(username,uname4)==0||strcmp(username,uname5)==0)&&strcmp(password,pword)==0)
		{
			printf("\n			LOGGED INTO SYSTEM! PRESS ANY KEY TO MAIN MENU!");
			if(strcmp(username,uname1)==0)
			{
				fd=0;
			}
			else if(strcmp(username,uname2)==0)
			{
				fd=1;
			}
			else if(strcmp(username,uname3)==0)
			{
				fd=2;
			}
			else if(strcmp(username,uname4)==0)
			{
				fd=3;
			}
			else
			{
				fd=4;
			}
			getchar();
			getchar();
			break;
		}
		else
		{
			printf("\n		 			Invalid!Try Again");
			a++;
			
		}
	} 
	

	
	while(a<=2);	
	if(a>2){
		printf("\nSorry,You are the wrong User.");

		exit(0);
	}
	
	
}

void list_products()			// Listing products in tabular format
{
	printf("\nITEM ID\tITEM NAME\tQUANTITY\tPRICE\n");
	char buf[256];
	int cnt=0;
	int line=0;
	int i=1;
	while(i<=n)
	{
		FILE *itemfile;
		if ((itemfile = fopen("./items.txt", "r")) == NULL)
		{
			if (errno == ENOENT)
			{
				fprintf(stderr, " path or file does not exist");
				return ;			
			}
			else
			{
				fprintf(stderr, " cannot be opened in read mode");
				return ;
			}

		}
		
			int k;
			for(k=0;k<i;k++)
			{
				fgets(buf,256,itemfile);
			}
			for(int j=0;buf[j]!='\n';j++)
				printf("%c",buf[j]);
			printf("\t");
			for(int j=0;j<n;j++)
			{
				fgets(buf,256,itemfile);
			}
			for(int j=0;buf[j]!='\n';j++)
				printf("%c",buf[j]);
			printf("\t\t");
			for(int j=0;j<n;j++)
			{
				fgets(buf,256,itemfile);
			}
			for(int j=0;buf[j]!='\n';j++)
				printf("%c",buf[j]);
			printf("\t\t");
			for(int j=0;j<n;j++)
			{
				fgets(buf,256,itemfile);
			}
			for(int j=0;buf[j]!='\n';j++)
				printf("%c",buf[j]);
		
		fclose(itemfile);
		printf("\n\n");
		i++;
	}
	
	
}
void select_item()		// Function for customer to add items in their cart
{
	int p_id;
	printf("\n");
	FILE *itemfile;
	if ((itemfile = fopen("./items.txt", "r")) == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, " path or file does not exist");
			return;			
		}
		else
		{
			fprintf(stderr, " cannot be opened in read mode");
			return;
		}

	}
	char buf[1024];
	char name[1024];
	int cnt=0;
	printf("Enter the item id to be selected : ");
	scanf("%d",&p_id);
	int line=0;
	int q;
	char c;
	printf("\nEnter required quantity : ");
	scanf("%d",&q);
	
	line =0;
	while (feof(itemfile) == 0 && line < ((n*2)+p_id))
	{
		
		if(line== n+p_id-1)
		{
			fgets(name,1024,itemfile);
		}
		else fgets(buf, 1024, itemfile);
		line++;
	}
	
	int a_q=0;
	for(int i=0;i<strlen(buf)-1;i++)
	{
		a_q = a_q*10 + buf[i] - '0';
	}
	
	if(a_q<q){
	printf("\nnumber of items insufficient.\n");
	return;
	}
	printf("\nAdded %d items of %s",q,name);
	if (itemfile != NULL)
		{fclose(itemfile);}
	FILE *bill;
	if ((bill = fopen(bill_file[fd], "a")) == NULL)
	{
		fprintf(stderr, "cannot be opened in write mode");
		return;
	}
	if ((itemfile = fopen("./items.txt", "r")) == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, " path or file does not exist");
			return;			
		}
		else
		{
			fprintf(stderr, " cannot be opened in read mode");
			return;
		}

	}
	
	int k;
	char s[1024];
	int p=0;
	s[p] = '\n';
	p++;
	char buf1[256];
	
	
			for(k=0;k<p_id;k++)
			{
				fgets(buf1,256,itemfile);
			}
			
			//For printing ID
			
			for(int j=0;j<strlen(buf1)-1;j++)
			{
				s[p]=buf1[j];
				p++;
			}
			s[p] = '\t';
			p++;
			s[p] = '\t';
			p++;
			for(int j=0;j<n;j++)
			{
				fgets(buf1,256,itemfile);
			}
			
			//For printing NAME
			
			for(int j=0;j<strlen(buf1)-1;j++)
			{
				s[p]=buf1[j];
				p++;
			}
			s[p] = '\t';
			p++;
			s[p] = '\t';
			p++;
			for(int j=0;j<n;j++)
			{
				fgets(buf1,256,itemfile);
			}
			
			//For printing QTY
			
				int len2 = (int)((ceil(log10(q))+1)*sizeof(char));
				char str2[len2];
				printf("\n%d\n",q);
				sprintf(str2, "%d", q);
				for(int j=0;j<len2-1;j++)
				{
					s[p]=str2[j];
					p++;
				}
				s[p] = '\t';
				p++;
				s[p] = '\t';
				p++;
				for(int j=0;j<n;j++)
				{
					fgets(buf1,256,itemfile);
				}
				
			//For printing PRICE
			
			int pp=0;
			
			for(int j=0;j<strlen(buf1)-1;j++)
			{
				s[p]=buf1[j];
				pp = pp *10 + buf1[j] - '0';
				p++;
			}
			s[p] = '\t';
			p++;
			
			//For printing AMOUNT
			
			int amount= pp * q;
			total_amt+=amount;
			int len1 = (int)((ceil(log10(amount))+1)*sizeof(char));
			char str1[len1];
			sprintf(str1, "%d", amount);
			
			for(int j=0;j<len1;j++)
			{
				s[p]=str1[j];
				p++;
			}
			fputs(s,bill);
			
	
	fclose(itemfile);
	fclose(bill);
	
	a_q-=q;
	
	int len = (int)((ceil(log10(a_q))+1)*sizeof(char));
	char newstr[len];
	sprintf(newstr,"%d",a_q);
	
	
	FILE *itemread,*newfile;
	
	if ((itemread = fopen("./items.txt", "r")) == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, " path or file does not exist");
			return;			
		}
		else
		{
			fprintf(stderr, " cannot be opened in read mode");
			return;
		}

	}
	newfile = fopen("./newfile.txt", "w+");
	int i=0;
	char buffer[1024];
	char newline[2]="\n";
	while(i<4*n)
	{
		fgets(buffer, 1024, itemread);
		if(i!=(n*2+p_id-1))
			fputs(buffer, newfile);
		else{
		 fputs(newstr,newfile);
		 fputs(newline,newfile);
		 }
		i++;
	}
	i++;
	fclose(itemread);
	fclose(newfile);
	remove("items.txt");
	rename("./newfile.txt","./items.txt");
	
	getchar();
}

void add()		// Function for supplier to add items in the store
{
	int p_id;
	printf("\n");
	FILE *itemfile;
	if ((itemfile = fopen("./items.txt", "r")) == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, " path or file does not exist");
			return;			
		}
		else
		{
			fprintf(stderr, " cannot be opened in read mode");
			return;
		}

	}
	char buf[256];
	
	int cnt=0;
	printf("\n Enter the item id to be added : ");
	scanf("%d",&p_id);
	int line=0;
	int q;
	char c;
	printf("\nEnter the quantity to be added : ");
	scanf("%d",&q);
	
	line =0;
	printf("Finished restocking of %d items of ",q);
	while (feof(itemfile) == 0 && line < ((n*2)+p_id))
	{
		fgets(buf, 256, itemfile);
		if(line == n+p_id-1){fputs(buf,stdout);}
		line++;
	}
	
	int a_q=0;
	for(int i=0;i<strlen(buf)-1;i++)
	{
		a_q = a_q*10 + buf[i] - '0';
	}
	a_q+=q;
	
	int len = (int)((ceil(log10(a_q))+1)*sizeof(char));
	char newstr[len];
	sprintf(newstr,"%d",a_q);
	
	if (itemfile != NULL)
		fclose(itemfile);
	FILE *itemread,*newfile;
	
	if ((itemread = fopen("./items.txt", "r")) == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, " path or file does not exist");
			return;			
		}
		else
		{
			fprintf(stderr, " cannot be opened in read mode");
			return;
		}

	}
	newfile = fopen("./newfile.txt", "w+");
	int i=0;
	char buffer[1024];
	char newline[2]="\n";

	while(i<4*n)
	{
		fgets(buffer, 1024, itemread);
		if(i!=(n*2+p_id-1))
			fputs(buffer, newfile);
		else{
		 fputs(newstr,newfile);
		 fputs(newline,newfile);
		 }
		i++;
	}
	i++;
	fclose(itemread);
	fclose(newfile);
	remove("items.txt");
	rename("./newfile.txt","./items.txt");
	
	getchar();
}


void menu(void)
{
	system("clear");
	printf("\n------------------------------- MENU -------------------------------\n");
    	int ch1,ch2,ch3;
    	printf("\n\n");
        printf("1. Supplier\n");
        printf("2. Customer\n");
        printf("Enter your choice: ");
        scanf("%d", &ch1);
        getchar();
        if(ch1==1)
        {
            system("clear");
            int h=0;
            while(h==0)
            {
		    printf("\n----------------\n");
		    printf("1. Items list\n");
		    printf("2. Add stock\n");
		    printf("3. Exit\n");
		    printf("Enter your choice: ");
		    scanf("%d", &ch2);
		    switch(ch2)
		    {
		        case 1: 
		        	list_products();
		               break;
		        case 2: 
		        	add();
		                break;
		        case 3: 
		        	h=1;
		        	break;
		        default: 
		        	printf("invalid input");
		               break;
                   }
            }
        }
        else if(ch1==2)
        {
        
		  FILE *customer_bill;
		  if ((customer_bill = fopen(bill_file[fd], "w")) == NULL)
		  {
			fprintf(stderr, "cannot be opened in write mode");
			return;
		  }
		  fprintf(customer_bill,"\nITEM ID\t\tITEM NAME\tQUANTITY\tPRICE\tAMOUNT\n" );
		  fclose(customer_bill);
		
//		  system("clear");
		  int h=0;
		  while(h==0)
		  {
			    printf("\n----------------------------");
			    printf("\n1. Items List\n");
			    printf("2. Select items to purchase\n");
			    printf("3. Print bill and exit\n");
			    printf("\nEnter your choice: ");  
			    scanf("%d",&ch3);
			    switch(ch3)
			    {
			    case 1: 
				list_products();
				break;
			    case 2: 
				select_item();
				break;
			    case 3: 
				h=1;
		        	FILE *c_bill;
		        	if ((c_bill = fopen(bill_file[fd], "r")) == NULL)
				{
					if (errno == ENOENT)
					{
						fprintf(stderr, " path or file does not exist");
						return;			
					}
					else
					{
						fprintf(stderr, " cannot be opened in read mode");
						return;
					}

				}
				
				
				
				char buffer[1024];
				while(feof(c_bill)==0)
				{
					fgets(buffer,1024,c_bill);
					fputs(buffer,stdout);
				}
				printf("\n\n\t\t\t\t\tTOTAL AMOUNT : %d ",total_amt);
				printf("\n\nThank You. Visit Again\n");
		        	fclose(c_bill);
		        	
		                break;
		                char msg[2]="0";
		                write(clientfd, msg, strlen(msg));
		        default: printf("invalid input");
		                break;
		    }
            }
        }
                
            
    }  
    
int open_clientfd(char *hostname, char *port) 		// To setup connection between Server and Client
{
    int clientfd;
    struct addrinfo hints, *listp, *p;
	char host[MAXLINE],service[MAXLINE];
    int flags;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;  
    hints.ai_flags = AI_NUMERICSERV;  
    hints.ai_flags |= AI_ADDRCONFIG;  
    getaddrinfo(hostname, port, &hints, &listp);
    for (p = listp; p; p = p->ai_next) {
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) 
            continue; 

		flags = NI_NUMERICHOST | NI_NUMERICSERV;		
		getnameinfo(p->ai_addr, p->ai_addrlen, host, MAXLINE, service, MAXLINE, flags);
        printf("host:%s, service:%s\n", host, service);
		
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1) 
		{
			printf("Connected to server %s at port %s\n", host, service);
            break; 
		}
        close(clientfd); 
    } 
    freeaddrinfo(listp);
    if (!p) 
        return -1;
    else    
        return clientfd;
}


int main(int argc, char **argv)
{
    
    char *host, *port, buf[MAXLINE];
    host = argv[1];
    port = argv[2];
    clientfd = open_clientfd(host, port);
    
    welcome();
    login();
    menu();
    
    close(clientfd);
    exit(0);
}