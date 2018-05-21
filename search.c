#include"my_header.h" 

int s_count,dir_count;

void search(char *dir_name,char *f_name,int from)
{
	char path[2000];
	strcpy(path,dir_name);
	char file_name[500];
//	printf("%s  %s \n",dir_name,f_name);
	DIR *dptr;
	struct dirent *dir_struct;
	int file_id,is_dir1,is_dir2;
	struct stat file_struct;

	dptr=opendir(path);
//	perror("recurssion");
//	printf("path is %s\n",path);



	while(dir_struct = readdir(dptr))
	{
		strcpy(path,dir_name);
		strcpy(file_name,path);
		strcat(file_name,"/");
		strcat(file_name,dir_struct->d_name);
//		printf("file :%s\n",file_name);	
//		printf("\nreading : %s		dptr : %d    dir_struct : %u	",dir_struct->d_name,dptr,dir_struct);
//		sleep(1);
		is_dir1 = strcmp(dir_struct->d_name,".");
		is_dir2 = strcmp(dir_struct->d_name,"..");
		int ss;
//		printf("before stat :%s \n",dir_struct->d_name);
		ss  = lstat(file_name,&file_struct);
//		perror("stat");
		//			printf("%d %d %d \n",is_dir1,is_dir2,ss);
		//		if( (stat(dir_struct->d_name,&file_struct)==0)  && is_dir1 && is_dir2 )
		if( ~ss && is_dir1 && is_dir2 )
		{
			//			printf("condition : %s ",dir_struct->d_name);
//			printf(" %s  %s",dir_struct->d_name,f_name);
			if( S_ISDIR(file_struct.st_mode) )
			{
//				printf("Main Path = %s\n",path);
				strcat(path,"/");
				strcat(path,dir_struct->d_name);
//				printf("\n			going to folder	 %s \n",path);
				search(path,f_name,1);
			}
			if( strstr( dir_struct->d_name,f_name ) )
			{
				getcwd(path,sizeof(path));
				printf("\033[32;1m %s \033[34;1m %s \n\n",dir_struct->d_name,path);
				s_count++;
			}
		}
	}
//	printf("i****************************return ************************************.............\n");
}



void main(int argc, char **argv)
{
	int i;
	char f_name[20];
	if(argc != 2)
	{
		printf("use : ./search FILENAME\n");
		return;
	}
	char path[222];
	getcwd(path,sizeof(path));
//	printf("%s.....\n",path);
	search(path,argv[1],0);
}
