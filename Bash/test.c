#include"my_header.h"

void main(int argc, char **argv)
{

char s[200],**cmd;
int i,wc=0,k;
scanf("%[^\n]",s);
printf("%s \n",s);
int len= strlen(s);
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
}