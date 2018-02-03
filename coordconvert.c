#include <stdio.h>
#include <stdlib.h>

//note to self: convert this to javascript

int main()
{
	int count,dim,invY,xMax,yMax;
	char invert;

	printf("Enter number of coordinate pairs: ");
	scanf("%d", &count);

	printf("Enter dimensions: ");
	scanf("%d", &dim);

	/*invY = 0;
	printf("Invert Y coordinate? (Y/n)");
	scanf("\n%c", &invert);
	if(invert == 'y' || invert == 'Y')
		invY = 1;*/

	int points[count][dim]; //I know this is shit coding practice but whatever I don't wanna use malloc
	float result[count][dim];
	float half[dim];

	int i,j,temp;
	for(i=0;i<dim;i++)
	{
		printf("Enter maximum for dimension %d: ", i+1);
		scanf("%d",&temp);
		half[i] = temp/2;
	}

	for(i = 0; i< count; i++)
	{
		for(j = 0; j<dim; j++)	
		{
			printf("Enter point %d coordinate %d: ", i+1, j+1);
			scanf("%d", &temp);
			points[i][j] = (float)temp;
		}
	}

	printf("\nOriginal coordinates:\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<dim;j++)
		{
			printf("%d", points[i][j]);
			if(j < dim-1)
				printf(", ");
		}
		printf("\n");
	}

	float temp2;
	for(i=0;i<count;i++)
	{
		for(j=0;j<dim;j++)
		{
			//(point-half)/half
			temp2 = (points[i][j]-half[j])/half[j];
			
			if(j == 1) temp2 = -temp2; //invert y
			result[i][j] = temp2;
		}
	}

	printf("\nNew coordinates:\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<dim;j++)
		{

			printf("%.04f", result[i][j]);
			if(j < dim-1)
				printf(", ");
		}
		printf("\n");
	}


	return (0);
}