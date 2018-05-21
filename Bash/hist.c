#include"my_header.h"

void hist_stack(char *cmd)
{
	HIST *temp;
	temp=malloc(sizeof(HIST));
	strcpy(temp->cmd,cmd);
	if(start == 0)
	{
		start=temp;
	}
	else
	{
		int count=0;
		HIST *dummy,*pre;
		dummy=start;

		while(dummy->next)
		{
			pre=dummy;
			dummy=dummy->next;
			count++;
		}
		if(count>=10)
		{
			free(dummy);
			pre->next=0;
		}
			temp->next=start;
			start=temp;
	}
}

void hist_cmd()
{
	HIST *dummy;
	dummy=start;
	int i=0;
	while(dummy)
	{
		printf("%d 	 %s\n",++i,dummy->cmd);
		dummy=dummy->next;
	}
}






void scanip()
{
	char cmd[30];
	char c;
	int cmd_count=0;
	while(1)
	{		
		printf("<%d Shirish's System> ",++cmd_count);
//		scanf("%[^\n]",cmd);
		gets(cmd);	
		hist_stack(cmd);
		if(strcmp(cmd,"hist") == 0)
			hist_cmd();
		else if(strcmp(cmd,"curPid") == 0)
			printf("Current Process ID : 	%u \n",getpid());
		else if(strcmp(cmd,"pPid") == 0)
			printf("Current Parent Process ID : 	%u \n",getppid());
/*		else if(cmd[0]=='c' && cmd[1]=='d' && cmd[2]==' ')
			execute(cmd);
*/		else
		{
			int pid,*col,colan=0,i;
			char s[128];
				strcpy(s,cmd);

			for(i=0;s[i]=='\0' || s[i]==';';i++)
			{
				if(s[i]==';')
					colan++;
			}


			if(s[i]=='\0')
				goto END;



			END :
			if((pid = fork()) == 0)
			{
				char s[128];
				strcpy(s,cmd);
			
				int len= strlen(s),i,k,wc=0;
				char **cmd;
				for(i=0;s[i];i++)
				{
					if(s[0]==' ')
						continue;
					if(s[i]!=' ' && ( s[i+1]==' ' || s[i+1]=='\0' ) )
						wc++;
					if(s[i]==' ')	
						s[i]='\0';
				}
				cmd = malloc((sizeof (char*) * wc) +1);
				for(i=0,k=0;i<=len;i++)
				{
					if(s[i]!=' ' && s[i-1]=='\0')
					cmd[k++] = &s[i];
				}
				cmd[k]=NULL;
				execvp(cmd[0],cmd);
				exit(1);
			}
			else
				wait(&pid);

		}
	}
	
}
