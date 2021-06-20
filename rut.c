#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define HOR (__TIME__)

int main()
{
	int ss=0, mm=0, hh=0;
	char file_name[25];
	FILE *fp;

	printf("Project-Name: ");
	scanf("%s", file_name);

	while(ss < 60)
	{
		system("clear");
		printf("\nProject: %s", file_name);
		printf("\nrut:         %02d:%02d:%02d", hh, mm, ss);

		fp = fopen(file_name, "w+");
		fprintf(fp, "\nProject: %s;\nInit_time: %s - %s;", file_name, __DATE__, HOR);
		fprintf(fp, "\nTime: %02d:%02d:%02d;\n\n", hh, mm, ss);
		fclose(fp);
		printf("\nPress Ctrl+C to stop: ");
		sleep(1);
		ss++;

		if(mm == 59 && ss == 59)
		{
			ss=0;
	        mm=0;
	        hh++;
	    }

		else if(ss == 59)
		{
			ss=0;
			mm++;
		}

	}
return 0;
}
