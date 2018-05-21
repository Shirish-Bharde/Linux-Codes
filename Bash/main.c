#include"my_header.h"




void main(int argc, char **argv)
{
	if (argc ==2)
	{
		if(strcmp(argv[1],"-c")!=0)
		{
			printf("use :	./shell -c COMMAND Options\n");
			return;
		}
	}
	if(argc>1)
	{
		char **s;
		int i=argc;
		if(strcmp(argv[1],"-c")==0)
		{
			s=malloc(sizeof(int *)*argc - 2);
			
			for(i=2;i<argc;i++)
			{
				s[i-2]=malloc(strlen(argv[i]));
				strcpy(s[i-2],argv[i]);
			}
			s[i-2]=NULL;
		}
			printf("after for %d \n",i-2);
			execvp(s[0],s);
			return;
	}
	
	scanip();	

}